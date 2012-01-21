/* This file has been generated from /home/woz/lisa-m-team4938/paparazzi/conf/airframes/lisa_m.xml */
/* Please DO NOT EDIT */

#ifndef AIRFRAME_H
#define AIRFRAME_H 

#define AIRFRAME_NAME "ECE_2012"
#define AC_ID 1
#define MD5SUM ((uint8_t*)"\105\124\333\312\307\175\323\016\115\302\331\365\171\305\226\171")

#define SERVOS_NB 5

#define SERVO_THROTTLE 1
#define SERVO_THROTTLE_NEUTRAL 1200
#define SERVO_THROTTLE_TRAVEL_UP 0.0833333333333
#define SERVO_THROTTLE_TRAVEL_DOWN 0
#define SERVO_THROTTLE_MAX 2000
#define SERVO_THROTTLE_MIN 1200

#define SERVO_AILERON 4
#define SERVO_AILERON_NEUTRAL 1500
#define SERVO_AILERON_TRAVEL_UP -0.0520833333333
#define SERVO_AILERON_TRAVEL_DOWN -0.0520833333333
#define SERVO_AILERON_MAX 2000
#define SERVO_AILERON_MIN 1000

#define SERVO_ELEVATOR 3
#define SERVO_ELEVATOR_NEUTRAL 1500
#define SERVO_ELEVATOR_TRAVEL_UP 0.0520833333333
#define SERVO_ELEVATOR_TRAVEL_DOWN 0.0520833333333
#define SERVO_ELEVATOR_MAX 2000
#define SERVO_ELEVATOR_MIN 1000


#define COMMAND_THROTTLE 0
#define COMMAND_ROLL 1
#define COMMAND_PITCH 2
#define COMMANDS_NB 3
#define COMMANDS_FAILSAFE {0,0,0}


#define SetCommandsFromRC(_commands_array, _rc_array) { \
  _commands_array[COMMAND_THROTTLE] = _rc_array[RADIO_THROTTLE];\
  _commands_array[COMMAND_ROLL] = _rc_array[RADIO_ROLL];\
  _commands_array[COMMAND_PITCH] = _rc_array[RADIO_PITCH];\
}

#define SetActuatorsFromCommands(values) { \
  uint32_t servo_value;\
  float command_value;\
  command_value = values[COMMAND_THROTTLE];\
  command_value *= command_value>0 ? SERVO_THROTTLE_TRAVEL_UP : SERVO_THROTTLE_TRAVEL_DOWN;\
  servo_value = SERVO_THROTTLE_NEUTRAL + (int32_t)(command_value);\
  actuators[SERVO_THROTTLE] = ChopServo(servo_value, SERVO_THROTTLE_MIN, SERVO_THROTTLE_MAX);\
\
  Actuator(SERVO_THROTTLE) = SERVOS_TICS_OF_USEC(actuators[SERVO_THROTTLE]);\
\
  command_value = values[COMMAND_ROLL];\
  command_value *= command_value>0 ? SERVO_AILERON_TRAVEL_UP : SERVO_AILERON_TRAVEL_DOWN;\
  servo_value = SERVO_AILERON_NEUTRAL + (int32_t)(command_value);\
  actuators[SERVO_AILERON] = ChopServo(servo_value, SERVO_AILERON_MIN, SERVO_AILERON_MAX);\
\
  Actuator(SERVO_AILERON) = SERVOS_TICS_OF_USEC(actuators[SERVO_AILERON]);\
\
  command_value = values[COMMAND_PITCH];\
  command_value *= command_value>0 ? SERVO_ELEVATOR_TRAVEL_UP : SERVO_ELEVATOR_TRAVEL_DOWN;\
  servo_value = SERVO_ELEVATOR_NEUTRAL + (int32_t)(command_value);\
  actuators[SERVO_ELEVATOR] = ChopServo(servo_value, SERVO_ELEVATOR_MIN, SERVO_ELEVATOR_MAX);\
\
  Actuator(SERVO_ELEVATOR) = SERVOS_TICS_OF_USEC(actuators[SERVO_ELEVATOR]);\
\
  ActuatorsCommit();\
}

#define AllActuatorsInit() { \
  ActuatorsInit();\
}

#define SECTION_IMU 1
#define IMU_GYRO_P_NEUTRAL -44
#define IMU_GYRO_Q_NEUTRAL 11
#define IMU_GYRO_R_NEUTRAL -17
#define IMU_GYRO_P_SENS 4.412
#define IMU_GYRO_P_SENS_NUM 1103
#define IMU_GYRO_P_SENS_DEN 250
#define IMU_GYRO_Q_SENS 4.412
#define IMU_GYRO_Q_SENS_NUM 1103
#define IMU_GYRO_Q_SENS_DEN 250
#define IMU_GYRO_R_SENS 4.412
#define IMU_GYRO_R_SENS_NUM 1103
#define IMU_GYRO_R_SENS_DEN 250
#define IMU_GYRO_PQ_SENS 0.0
#define IMU_GYRO_PQ_SENS_NUM 0
#define IMU_GYRO_PQ_SENS_DEN 1
#define IMU_GYRO_PR_SENS 0.0
#define IMU_GYRO_PR_SENS_NUM 0
#define IMU_GYRO_PR_SENS_DEN 1
#define IMU_GYRO_QR_SENS 0.0
#define IMU_GYRO_QR_SENS_NUM 0
#define IMU_GYRO_QR_SENS_DEN 1
#define IMU_ACCEL_X_NEUTRAL 5
#define IMU_ACCEL_Y_NEUTRAL 7
#define IMU_ACCEL_Z_NEUTRAL 1
#define IMU_ACCEL_X_SENS 38.2950544968
#define IMU_ACCEL_X_SENS_NUM 45686
#define IMU_ACCEL_X_SENS_DEN 1193
#define IMU_ACCEL_Y_SENS 37.2659314684
#define IMU_ACCEL_Y_SENS_NUM 30409
#define IMU_ACCEL_Y_SENS_DEN 816
#define IMU_ACCEL_Z_SENS 39.1599014171
#define IMU_ACCEL_Z_SENS_NUM 31837
#define IMU_ACCEL_Z_SENS_DEN 813
#define IMU_ACCEL_XY_SENS 0.0
#define IMU_ACCEL_XY_SENS_NUM 0
#define IMU_ACCEL_XY_SENS_DEN 1
#define IMU_ACCEL_XZ_SENS 0.0
#define IMU_ACCEL_XZ_SENS_NUM 0
#define IMU_ACCEL_XZ_SENS_DEN 1
#define IMU_ACCEL_YZ_SENS 0.0
#define IMU_ACCEL_YZ_SENS_NUM 0
#define IMU_ACCEL_YZ_SENS_DEN 1
#define IMU_MAG_X_NEUTRAL -99
#define IMU_MAG_Y_NEUTRAL 41
#define IMU_MAG_Z_NEUTRAL -111
#define IMU_MAG_X_SENS 3.81341423535
#define IMU_MAG_X_SENS_NUM 35194
#define IMU_MAG_X_SENS_DEN 9229
#define IMU_MAG_Y_SENS 4.46099985003
#define IMU_MAG_Y_SENS_NUM 59251
#define IMU_MAG_Y_SENS_DEN 13282
#define IMU_MAG_Z_SENS 3.9637570825
#define IMU_MAG_Z_SENS_NUM 65073
#define IMU_MAG_Z_SENS_DEN 16417
#define IMU_MAG_XY_SENS 0.0
#define IMU_MAG_XY_SENS_NUM 0
#define IMU_MAG_XY_SENS_DEN 1
#define IMU_MAG_XZ_SENS 0.0
#define IMU_MAG_XZ_SENS_NUM 0
#define IMU_MAG_XZ_SENS_DEN 1
#define IMU_MAG_YZ_SENS 0.0
#define IMU_MAG_YZ_SENS_NUM 0
#define IMU_MAG_YZ_SENS_DEN 1
#define IMU_BODY_TO_IMU_PHI RadOfDeg(0.)
#define IMU_BODY_TO_IMU_THETA RadOfDeg(0.)
#define IMU_BODY_TO_IMU_PSI RadOfDeg(0.)

#define SECTION_AUTO1 1
#define AUTO1_MAX_ROLL 1.0
#define AUTO1_MAX_PITCH 1.0

#define SECTION_adc 1
#define ADC_CHANNEL_GYRO_NB_SAMPLES 16
#define ADC_CHANNEL_ACCEL_NB_SAMPLES 32

#define SECTION_INS 1
#define INS_ROLL_NEUTRAL_DEFAULT RadOfDeg(0)
#define INS_PITCH_NEUTRAL_DEFAULT RadOfDeg(0)

#define SECTION_BAT 1
#define MILLIAMP_AT_FULL_THROTTLE 20000
#define VOLTAGE_ADC_A 0.02456533604651162791
#define VOLTAGE_ADC_B 0.24024993023255813953
#define VoltageOfAdc(adc) (VOLTAGE_ADC_A * adc + VOLTAGE_ADC_B)
#define CATASTROPHIC_BAT_LEVEL 0.1
#define CRITIC_BAT_LEVEL 0.2
#define LOW_BAT_LEVEL 0.3
#define MAX_BAT_LEVEL 0.4

#define SECTION_SIMU 1
#define YAW_RESPONSE_FACTOR 0.7

#define SECTION_MISC 1
#define TELEMETRY_MODE_FBW 1
#define NOMINAL_AIRSPEED 12.5
#define CARROT 5.
#define KILL_MODE_DISTANCE (1.5*MAX_DIST_FROM_HOME)
#define CONTROL_RATE 60
#define ALT_KALMAN_ENABLED TRUE
#define TRIGGER_DELAY 1.
#define DEFAULT_CIRCLE_RADIUS 50.

#define SECTION_VERTICAL CONTROL 1
#define V_CTL_POWER_CTL_BAT_NOMINAL 11.1
#define V_CTL_ALTITUDE_PGAIN -0.07
#define V_CTL_ALTITUDE_MAX_CLIMB 2.
#define V_CTL_AUTO_THROTTLE_NOMINAL_CRUISE_THROTTLE 0.55
#define V_CTL_AUTO_THROTTLE_MIN_CRUISE_THROTTLE 0.30
#define V_CTL_AUTO_THROTTLE_MAX_CRUISE_THROTTLE 0.80
#define V_CTL_AUTO_THROTTLE_LOITER_TRIM 1500
#define V_CTL_AUTO_THROTTLE_DASH_TRIM -500
#define V_CTL_AUTO_THROTTLE_CLIMB_THROTTLE_INCREMENT 0.15
#define V_CTL_AUTO_THROTTLE_PGAIN -0.025
#define V_CTL_AUTO_THROTTLE_IGAIN 0.1
#define V_CTL_AUTO_THROTTLE_PITCH_OF_VZ_PGAIN 0.05
#define V_CTL_AUTO_PITCH_PGAIN -0.05
#define V_CTL_AUTO_PITCH_IGAIN 0.075
#define V_CTL_AUTO_PITCH_MAX_PITCH 0.35
#define V_CTL_AUTO_PITCH_MIN_PITCH -0.35
#define V_CTL_THROTTLE_SLEW 0.05

#define SECTION_HORIZONTAL CONTROL 1
#define H_CTL_COURSE_PGAIN -0.85
#define H_CTL_ROLL_MAX_SETPOINT 0.6
#define H_CTL_PITCH_MAX_SETPOINT 0.5
#define H_CTL_PITCH_MIN_SETPOINT -0.5
#define H_CTL_ROLL_PGAIN 12000.
#define H_CTL_AILERON_OF_THROTTLE 0.0
#define H_CTL_PITCH_PGAIN -9000.
#define H_CTL_PITCH_DGAIN 1.5
#define H_CTL_ELEVATOR_OF_ROLL 1250

#define SECTION_NAV 1
#define NAV_PITCH 0.
#define NAV_GLIDE_PITCH_TRIM 0

#define SECTION_AGGRESSIVE 1
#define AGR_BLEND_START 20
#define AGR_BLEND_END 10
#define AGR_CLIMB_THROTTLE 0.8
#define AGR_CLIMB_PITCH 0.3
#define AGR_DESCENT_THROTTLE 0.1
#define AGR_DESCENT_PITCH -0.25
#define AGR_CLIMB_NAV_RATIO 0.8
#define AGR_DESCENT_NAV_RATIO 1.0

#define SECTION_FAILSAFE 1
#define FAILSAFE_DELAY_WITHOUT_GPS 1
#define FAILSAFE_DEFAULT_THROTTLE 0.3
#define FAILSAFE_DEFAULT_ROLL 0.3
#define FAILSAFE_DEFAULT_PITCH 0.5
#define FAILSAFE_HOME_RADIUS 100


#endif // AIRFRAME_H
