/* This file has been generated from /home/woz/lisa-m-team4938/paparazzi/var/ECE_2012/settings_modules.xml /home/woz/lisa-m-team4938/paparazzi/conf/settings/basic.xml */
/* Please DO NOT EDIT */

#ifndef SETTINGS_H
#define SETTINGS_H 

#define RCSettings(mode_changed) { \
}

#include "autopilot.h"
#include "downlink.h"
#include "estimator.h"
#include "subsystems/gps.h"
#include "subsystems/nav.h"
#include "generated/modules.h"

#define DlSetting(_idx, _value) { \
  switch (_idx) { \
    case 0: flight_altitude = _value; break;\
    case 1: nav_course = _value; break;\
    case 2: nav_IncreaseShift( _value ); _value = nav_shift; break;\
    case 3: estimator_flight_time = _value; break;\
    case 4: nav_SetNavRadius( _value ); _value = nav_radius; break;\
    case 5: pprz_mode = _value; break;\
    case 6: launch = _value; break;\
    case 7: kill_throttle = _value; break;\
    case 8: telemetry_mode_Ap_DefaultChannel = _value; break;\
    case 9: telemetry_mode_Fbw_DefaultChannel = _value; break;\
    case 10: gps_Reset( _value ); _value = gps.reset; break;\
    default: break;\
  }\
}
#define PeriodicSendDlValue(_chan) { \
  static uint8_t i;\
  float var;\
  if (i >= 11) i = 0;\
  switch (i) { \
    case 0: var = flight_altitude; break;\
    case 1: var = nav_course; break;\
    case 2: var = nav_shift; break;\
    case 3: var = estimator_flight_time; break;\
    case 4: var = nav_radius; break;\
    case 5: var = pprz_mode; break;\
    case 6: var = launch; break;\
    case 7: var = kill_throttle; break;\
    case 8: var = telemetry_mode_Ap_DefaultChannel; break;\
    case 9: var = telemetry_mode_Fbw_DefaultChannel; break;\
    case 10: var = gps.reset; break;\
    default: var = 0.; break;\
  }\
  DOWNLINK_SEND_DL_VALUE(_chan, &i, &var);\
  i++;\
}
static inline float settings_get_value(uint8_t i) {
  switch (i) { \
    case 0: return flight_altitude;
    case 1: return nav_course;
    case 2: return nav_shift;
    case 3: return estimator_flight_time;
    case 4: return nav_radius;
    case 5: return pprz_mode;
    case 6: return launch;
    case 7: return kill_throttle;
    case 8: return telemetry_mode_Ap_DefaultChannel;
    case 9: return telemetry_mode_Fbw_DefaultChannel;
    case 10: return gps.reset;
    default: return 0.;
    }
  }

/* Persistent Settings */
struct PersistentSettings {
};

extern struct PersistentSettings pers_settings;

static inline void persistent_settings_store( void ) {
}

static inline void persistent_settings_load( void ) {
};

#endif // SETTINGS_H
