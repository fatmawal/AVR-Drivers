#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"


static void (*Glopalptrtofunc)(void)= NULL ;

void TIMER0_voidInit(void)
{
	//FAST PWM
	SET_BIT(TCCR0,TCCR0_WGM00) ;
	SET_BIT(TCCR0,TCCR0_WGM01);
	//OCR VALUE
	OCR0=64;
	//NON INVERTED MODE
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
	//PIE  ENABLE
	//SET_BIT(TIMSK,TIMSK_OCIEO);
	//PRESCALER=8
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
}

void TIMER0_voidSetOcrValue(u8 Copy_u8Value)
{
	OCR0= Copy_u8Value;
}
u8 TIMER0_u8SetCallBack(void (*ptrtofunc)(void))
{
	u8 Local_Errorstate=OK ;
	if(ptrtofunc!= NULL)
	{
		Glopalptrtofunc=ptrtofunc;
	}
	else
	{
		Local_Errorstate=NOT_OK ;
	}
	return Local_Errorstate;
}

void __vector_10 (void)    __attribute__((signal));
void __vector_10 (void)
{
	if(Glopalptrtofunc!= NULL)
	{
		Glopalptrtofunc();
	}
}


/***************************************************/
void TIMER1_voidInit(void)
{
	//NORMAL MODE:

	 /*CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);  */
	//PRESCALER:
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
	//NON INVERTER :
	//CLR_BIT(TCCR1A,TCCR1A_COM1A0);
//	SET_BIT(TCCR1A,TCCR1A_COM1A1);


}
void TIMER1_voidSetOcrValue(u16 Copy_u16value)
{
	OCR1A=Copy_u16value;
}
void TIMER1_voidSetIcrValue(u16 Copy_u16value)
{
	ICR1=Copy_u16value;
}

u16 TIMER1_u16ReadTimer(void)
{
	return TCNT1A;
}

void TIMER1_voidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1A=Copy_u16Value;
}
