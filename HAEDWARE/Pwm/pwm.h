#ifndef __PWM_H__
#define __PWM_H__
#include "HC89F303.h"

void pwm_init(u16 hz);
void set_pwm(u8 duty);
#endif

