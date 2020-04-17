/*
 * INTERRUPT_int.h
 *
 *  Created on: Mar 25, 2020
 *      Author: IOT scientist
 */

#ifndef XINT_INT_H_
#define XINT_INT_H_

volatile void X (void);
void EXINT_vdSetExternalInterrupt(u8 int_id,u8 int_mod);
void EXINT_vdEnableInterrupt(u8 int_id);
void EXINT_vdDisableInterrupt(u8 int_id);
void EXINT_vdSetCallBack( void (*fn_name)(void));
void EXINT_vdEnableGlobalInt();


/*
 * SET Sence mode
 */
#define RISING_EDGE       0
#define FALLING_EDGE      1
#define ANY_CHANGE        2
#define LOW_EDGE          3


#define INT0 6
#define INT1 7
#define INT2 5


#define INTF0 6
#define INTF1 7
#define INTF2 5

/*
 * ISC11 ISC10 ISC01 ISC00
 */

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3


#define ISC2 6
#endif /* XINT_INT_H_ */
