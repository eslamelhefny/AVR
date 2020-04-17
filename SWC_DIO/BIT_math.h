/*
 * BIT_math.h
 *
 *  Created on: Jan 23, 2020
 *      Author: IOT scientist
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define CLEAR_BIT(var,bit_num) (var&=~(1<<bit_num))
#define SET_BIT(var,bit_num) (var|=(1<<bit_num))
#define TOGGLE_BIT(var,bit_num) (var^=(1<<bit_num))
#define GET_BIT(var,bit_num) ((var>>bit_num)&1)

#endif /* BIT_MATH_H_ */
