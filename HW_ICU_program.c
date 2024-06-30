#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "HW_ICU_interface.h"
#include "HW_ICU_private.h"
#include "HW_ICU_config.h"


static void (*GlobalPtr)(void)=NULL;
void HWICU_voidInit(void)
{
	//ENABLE INTERUPT:
	SET_BIT(TIMSK,TIMSK_TICIE1);
	//SET TO RISING EDGE:
	SET_BIT(TCCR1B,TCCR1B_ICES1);
}

void HWICU_voidSetTriggrEdge(u8 Copy_u8Edge)
{
	if(Copy_u8Edge==RISING)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(Copy_u8Edge==FALLING)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
}
void HWICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void HWICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}
void HWICU_voidSetCallBack(void (*ptr)(void))
{
if(ptr!=NULL)
{
	GlobalPtr=ptr;
}
else
	{
		asm("NOP");
	}
}
u16 HWICU_u16GetReading(void)
{
	return ICR1;
}
void __vector_6(void)     __attribute((signal));
void __vector_6(void)
{
	if(GlobalPtr!=NULL)
	{
		GlobalPtr();
	}
	else
	{
		asm("NOP");
	}
}

