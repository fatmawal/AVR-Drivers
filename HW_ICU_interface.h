/**************************************************************/
/******************** Layer : MCAL*************************/
/********************Ver :01 *************************/
/********************Component :ICU *************************/
/********************Author : FATMA WALEED*************************/
/******************** *************************/

#ifndef HW_ICU_INTERFACE_H_
#define HW_ICU_INTERFACE_H_

void HWICU_voidInit(void);
void HWICU_voidSetTriggrEdge(u8 Copy_u8Edge);
void HWICU_voidEnableInterrupt(void);
void HWICU_voidDisableInterrupt(void);
void HWICU_voidSetCallBack(void (*ptr)(void));
u16 HWICU_u16GetReading(void);
#define RISING    1
#define FALLING   0



#endif
