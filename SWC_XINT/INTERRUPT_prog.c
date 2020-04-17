/*
 * INTERRUPT_prog.c
 *
 *  Created on: Mar 25, 2020
 *      Author: IOT scientist
 */
#include"../BIT_math.h"
#include"../STD_TYPES.h"
#include "INTERRUPT_priv.h"
#include "INTERRUPT_int.h"
/*********************************************************************************************************
 * function name : Pinter to function or call back function
 * input         : void
 * return type   : void
 * Discription    : this function take interrupt id and
 * 				   enable this interrupt .
 *********************************************************************************************************
 */
void (*CallBack)(void);
/*********************************************************************************************************
 * function name : EXINT_vdSetExternalInterrupt
 * input         : interrupt id , mode id
 * return type   : void
 * Discription    : this function set interrupt mode and there are four modes :
 * 						1-RISING_EDGE
 * 						2-FALLING_EDGE
 * 						3-LOW_EDGE
 * 						4-ANY_CHANGE
 * 					for INT0 and INT1 but for interrupt2 there are two options only :
 * 						1-RISING_EDGE
 * 						2-FALLING_EDGE
 * 					then enable External Interrupt
 *********************************************************************************************************
 */
void EXINT_vdSetExternalInterrupt(u8 int_id,u8 int_mod)
{
	switch(int_id)
	{
	case INT0 :
	{
		switch(int_mod)
		{
		case RISING_EDGE :
		{
			SET_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
			break;

		}
		case FALLING_EDGE :
		{
			CLEAR_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
			break;
		}
		case LOW_EDGE:
		{
			CLEAR_BIT(MCUCR_REG,ISC00);
			CLEAR_BIT(MCUCR_REG,ISC01);
			break;

		}
		case ANY_CHANGE:
		{
			SET_BIT(MCUCR_REG,ISC00);
			CLEAR_BIT(MCUCR_REG,ISC01);
			break;

		}
		}
		break;

	}
	case INT1 :
	{
		switch(int_mod)
		{
		case RISING_EDGE :
		{
			SET_BIT(MCUCR_REG,ISC10);
			SET_BIT(MCUCR_REG,ISC11);
			break;

		}
		case FALLING_EDGE :
		{
			CLEAR_BIT(MCUCR_REG,ISC10);
			SET_BIT(MCUCR_REG,ISC11);
			break;
		}
		case LOW_EDGE:
		{
			CLEAR_BIT(MCUCR_REG,ISC10);
			CLEAR_BIT(MCUCR_REG,ISC11);
			break;

		}
		case ANY_CHANGE:
		{
			SET_BIT(MCUCR_REG,ISC10);
			CLEAR_BIT(MCUCR_REG,ISC11);
			break;

		}
		}
		break;

	}
	case INT2:
	{
		switch(int_mod)
		{
		case RISING_EDGE :
		{
			SET_BIT(MCUCSR_REG,ISC2);
			break;

		}
		case FALLING_EDGE :
		{
			CLEAR_BIT(MCUCSR_REG,ISC2);
			break;
		}
		case LOW_EDGE:
		{
			/*
			 * avr doesn't have this feature in external interrupt 2
			 */
			 //					#error "you can't set sensing mode to low becouse avr doesn't have this feature rising or falling only"
			break;

		}
		case ANY_CHANGE:
		{
			//					#error "you can't set sensing mode to anychange becouse avr doesn't have this feature rising or falling only"
			break;

		}
		}
		break;


	}
	default:
	{
//#warning "wrong input parameters"
	}

	}

	EXINT_vdEnableInterrupt( int_id);

}
/*********************************************************************************************************
 * function name : EXINT_vd enable Interrupt
 * input         : interrupt id
 * return type   : void
 * Discription    : this function take interrupt id and
 * 				   enable this interrupt .
 *********************************************************************************************************
 */
void EXINT_vdEnableInterrupt(u8 int_id)
{
	switch(int_id)
	{
	case INT0 :
	{
		SET_BIT(GICR_REG,INT0);
		break;

	}
	case INT1 :
	{
		SET_BIT(GICR_REG,INT1);
		break;

	}
	case INT2 :
	{
		SET_BIT(GICR_REG,INT2);
		break;

	}

	}

}



/*********************************************************************************************************
 * function name : EXINT_vd enable Interrupt
 * input         : interrupt id
 * return type   : void
 * Discription    : this function take interrupt id and
 * 				   enable this interrupt .
 *********************************************************************************************************
 */
void EXINT_vdDisableInterrupt(u8 int_id)
{

	switch(int_id)
	{
	case INT0 :
	{
		CLEAR_BIT(GICR_REG,INT0);
		break;

	}
	case INT1 :
	{
		CLEAR_BIT(GICR_REG,INT1);
		break;

	}
	case INT2 :
	{
		CLEAR_BIT(GICR_REG,INT2);
		break;

	}

	}


}
/*********************************************************************************************************
 * function name : EXINT_vdSetCallBack
 * input         : pointer to function you want to set
 * return type   : void
 * Discription    : this function set the ISR to do the function in application layer
 * 				   .
 *********************************************************************************************************
 */
void EXINT_vdSetCallBack( void (*fn_name)(void))
{
	CallBack = fn_name;


}
/*********************************************************************************************************
 * function name : EXINT_vdEnableGlobalInt
 * input         : pointer to function you want to set
 * return type   : void
 * Discription    : this function set the ISR to do the function in application layer
 *
 *********************************************************************************************************
 */
void EXINT_vdEnableGlobalInt()
{
	SET_BIT(SREG_REG,7);
}
void __vector_1(void) __attribute__(( signal , used ));
void __vector_2(void) __attribute__(( signal , used ));
void __vector_3(void) __attribute__(( signal , used ));
void __vector_1(void)
{
	CallBack();
}
void __vector_2(void)
{
	CallBack();
}
void __vector_3(void)
{
	CallBack();
}
