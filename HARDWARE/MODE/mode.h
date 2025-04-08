#ifndef __MODE_H
#define __MODE_H	 
#include "sys.h"
#include "delay.h"
#include "infrared.h"
#include "tianwen.h"
#include <stdlib.h>
extern u16 count;
extern u8 bug;

// 以下是一些预定义的函数声明，用于执行特定的动作或模式

// 执行站立动作
void Stand(void);

// 执行前进动作
void Advance(void);

// 执行女王动作
void Queen(void);

// 执行向左移动动作
void Left(void);

// 执行向右移动动作
void Right(void);

// 执行摇摆模式，可能是指保持静止或特定姿势
void Rock(void);

// 执行睡眠模式，可能是模拟睡眠状态
void Sleep(void);

// 执行坐下动作
void Sit(void);

// 执行握手动作
void Handshake(void);

// 执行小便动作，用于模拟人类行为
void pee(void);

// 执行跳舞动作
void dance(void);

// 执行模式切换，可能是更改当前的行为模式
void mode(void);

// 执行前进动作，带有参数以指定更详细的行动信息
// x 和 y 可能是坐标，num 可能是行动次数或其他数值参数
void For(int x, int y, int num);

// 执行的动作
void SwingLegs(void);
void Sit_half(void);
void dunqi(void);
void Dig(void);
void kaiji(void);
void welcome(void);
		 				    
#endif
