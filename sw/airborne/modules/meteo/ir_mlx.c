/*
 * $Id: ir_mlx.c $
 *
 * Copyright (C) 2010 Martin Mueller
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

/** \file ir_mlx.c
 *  \brief Melexis 90614 I2C
 *
 *   This reads the values for temperatures from the Melexis 90614 IR sensor through I2C.
 */


#include "ir_mlx.h"

#include "sys_time.h"
#include "i2c.h"
#include "led.h"
#include "mcu_periph/uart.h"
#include "messages.h"
#include "downlink.h"

#ifndef MLX_I2C_DEV
#define MLX_I2C_DEV i2c0
#endif

struct i2c_transaction mlx_trans;

uint8_t  ir_mlx_status;
uint16_t ir_mlx_itemp_case;
float    ir_mlx_temp_case;
uint16_t ir_mlx_itemp_obj;
float    ir_mlx_temp_obj;

/* I2C address is set to 3 */
#ifndef MLX90614_ADDR
#define MLX90614_ADDR 0x06
#endif

//    printf("Ta    = %2.2f°C (0x%04X)\n", (tp*0.02)-273.15, tp);


void ir_mlx_init( void ) {
  ir_mlx_status = IR_MLX_UNINIT;
}

void ir_mlx_periodic( void ) {
  if (cpu_time_sec > 1) {
    /* start two byte case temperature */
    mlx_trans.buf[0] = MLX90614_TA;
    I2CTransceive(MLX_I2C_DEV, mlx_trans, MLX90614_ADDR, 1, 2);
    ir_mlx_status = IR_MLX_RD_CASE_TEMP;
  }
}

void ir_mlx_event( void ) {
  if ((mlx_trans.status == I2CTransSuccess)) {
    if (ir_mlx_status == IR_MLX_RD_CASE_TEMP) {
      /* read two byte case temperature */
      ir_mlx_itemp_case  = mlx_trans.buf[1] << 8;
      ir_mlx_itemp_case |= mlx_trans.buf[0];
      ir_mlx_temp_case = ir_mlx_itemp_case*0.02 - 273.15;

      /* start two byte obj temperature */
      mlx_trans.buf[0] = MLX90614_TOBJ;
      ir_mlx_status = IR_MLX_RD_CASE_TEMP;
      I2CTransceive(MLX_I2C_DEV, mlx_trans, MLX90614_ADDR, 1, 2);
      ir_mlx_status = IR_MLX_RD_OBJ_TEMP;
    }
    else if (ir_mlx_status == IR_MLX_RD_OBJ_TEMP) {
      /* read two byte obj temperature */
      ir_mlx_itemp_obj  = mlx_trans.buf[1] << 8;
      ir_mlx_itemp_obj |= mlx_trans.buf[0];
      ir_mlx_temp_obj = ir_mlx_itemp_obj*0.02 - 273.15;
      mlx_trans.status = I2CTransDone;

      DOWNLINK_SEND_MLX_STATUS(DefaultChannel,
                              &ir_mlx_itemp_case,
                              &ir_mlx_temp_case,
                              &ir_mlx_itemp_obj,
                              &ir_mlx_temp_obj);
    }
  }
}
