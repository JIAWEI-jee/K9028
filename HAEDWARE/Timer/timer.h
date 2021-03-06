#ifndef __TIMER_H__
#define __TIMER_H__
#include "HC89F303.h"

#define overrang_time   (60*60*2)
#define Heat_Value      (60*4)
#define cali_time        (60*2*100)
#define Length          4.88
#define Temperature_Value         91.0624
#define H_0_5           (60*30)
#define H_1_0           (60*60)
#define H_2_0           (60*60*2)
#define H_3_0           (60*60*3)
#define H_4_0           (60*60*4)
#define H_5_0           (60*60*5)
#define H_6_0           (60*60*6)
#define H_7_0           (60*60*7)
#define H_8_0           (60*60*8)


extern u8 over_rang_time_std;
extern u8 Gap_protect_std;
extern u8 On_stay;
extern u8 Heat_start_std;
extern u8  Open_Heat_Value;
extern u8 one_heat;
extern u16 led_time_cnt;
extern u8   LED_std;

void time0_init(void);
void set_time_sec_val(u16 sec);
void set_time_sec(void);
void set_correct_time(u8 gap);
void led_set_on(void);
void led_set_off(void);
#endif

