#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"



void TIM3_Int_Init(u16 arr,u16 psc);
void TIM3_PWM_Init(u16 arr,u16 psc);
void TIM1_PWM_Init(u16 arr,u16 psc);
void slow_move( u32 d1,u32 d2);
void quick_move(u32 c1,u32 c2);
#endif
