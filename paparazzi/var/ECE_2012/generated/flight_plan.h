/* This file has been generated from /home/woz/lisa-m-team4938/paparazzi/conf/flight_plans/himmel.xml */
/* Please DO NOT EDIT */

#ifndef FLIGHT_PLAN_H
#define FLIGHT_PLAN_H 

#include "std.h"
#include "generated/modules.h"
#define FLIGHT_PLAN_NAME "Basic"
#define NAV_UTM_EAST0 506274
#define NAV_UTM_NORTH0 3566329
#define NAV_UTM_ZONE0 12
#define NAV_LAT0 322335810 /* 1e7deg */
#define NAV_LON0 1038149598 /* 1e7deg */
#define NAV_ALT0 0 /* mm above msl */
#define NAV_MSL0 -28150 /* mm, EGM96 geoid-height (msl) over ellipsoid */
#define QFU 0.0
#define WP_dummy 0
#define WP_HOME 1
#define WP_NE 2
#define WP_NW 3
#define WP_SW 4
#define WP_SE 5
#define WAYPOINTS { \
 {42.0, 42.0, 20},\
 {21.1, -25.7, 20},\
 {65.0, 22.4, 20},\
 {-19.5, 22.3, 20},\
 {-25.3, -72.7, 20},\
 {67.6, -78.5, 20},\
};
#define WAYPOINTS_LLA { \
 {322339596, 1038154059, 2000}, /* 1e7deg, 1e7deg, cm (hmsl=-28.15m) */ \
 {322333490, 1038151836, 2000}, /* 1e7deg, 1e7deg, cm (hmsl=-28.15m) */ \
 {322337827, 1038156499, 2000}, /* 1e7deg, 1e7deg, cm (hmsl=-28.15m) */ \
 {322337822, 1038147530, 2000}, /* 1e7deg, 1e7deg, cm (hmsl=-28.15m) */ \
 {322329252, 1038146908, 2000}, /* 1e7deg, 1e7deg, cm (hmsl=-28.15m) */ \
 {322328724, 1038156768, 2000}, /* 1e7deg, 1e7deg, cm (hmsl=-28.15m) */ \
};
#define NB_WAYPOINT 6
#define NB_BLOCK 2
#define GROUND_ALT 0.
#define GROUND_ALT_CM 0
#define SECURITY_HEIGHT 10.
#define SECURITY_ALT 10.
#define MAX_DIST_FROM_HOME 100.
#ifdef NAV_C

static inline void auto_nav(void) {
  switch (nav_block) {
    Block(0) // corners
    ; // pre_call
    switch(nav_stage) {
      Label(while_1)
      Stage(0)
        if (! (TRUE)) Goto(endwhile_2) else NextStageAndBreak();
        Stage(1)
          if (NavApproaching(2,CARROT)) NextStageAndBreakFrom(2) else {
            NavGotoWaypoint(2);
            NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
            NavVerticalAltitudeMode(WaypointAlt(2), 0.);
          }
          break;
        Stage(2)
          if (NavApproaching(3,CARROT)) NextStageAndBreakFrom(3) else {
            NavGotoWaypoint(3);
            NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
            NavVerticalAltitudeMode(WaypointAlt(3), 0.);
          }
          break;
        Stage(3)
          if (NavApproaching(4,CARROT)) NextStageAndBreakFrom(4) else {
            NavGotoWaypoint(4);
            NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
            NavVerticalAltitudeMode(WaypointAlt(4), 0.);
          }
          break;
        Stage(4)
          if (NavApproaching(5,CARROT)) NextStageAndBreakFrom(5) else {
            NavGotoWaypoint(5);
            NavVerticalAutoThrottleMode(RadOfDeg(0.000000));
            NavVerticalAltitudeMode(WaypointAlt(5), 0.);
          }
          break;
        Stage(5)
          Goto(while_1)
        Label(endwhile_2)
      default:
      Stage(6)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    Block(1) // HOME
    ; // pre_call
    switch(nav_stage) {
      Stage(0)
        nav_home();
        break;
      default:
      Stage(1)
        NextBlock();
        break;
    }
    ; // post_call
    break;

    default: break;
  }
}
#endif // NAV_C

#endif // FLIGHT_PLAN_H
