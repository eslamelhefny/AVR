/*
 * INTERRUPT_priv.h
 *
 *  Created on: Mar 25, 2020
 *      Author: IOT scientist
 */

#ifndef INTERRUPT_PRIV_H_
#define INTERRUPT_PRIV_H_
/*
 * define control register
 */

#define GICR_REG   *((volatile u8*) 0x5B)
#define GIFR_REG   *((volatile u8*) 0x5A)
#define MCUCSR_REG *((volatile u8*) 0x54)
#define MCUCR_REG  *((volatile u8*) 0x55)
#define SREG_REG   *((volatile u8*) 0x5F)




#endif /* INTERRUPT_PRIV_H_ */
