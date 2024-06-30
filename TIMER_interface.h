/**************************************************************/
/******************** Layer : MCAL*************************/
/********************Ver :01 *************************/
/********************Component :TIMER *************************/
/********************Author : FATMA WALEED*************************/
/******************** *************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTRFACE_H_

void TIMER0_voidInit(void);

void TIMER0_voidSetCallBack(void (*ptrtofunc)(void));

void TIMER0_voidSetOcrValue(u8 Copy_u8Value);



void TIMER1_voidInit(void);
void TIMER1_voidSetOcrValue(u16 Copy_u16value);
void TIMER1_voidSetIcrValue(u16 Copy_u16value);

#endif
