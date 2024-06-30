#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"

void ADC_voidInit(void)
{

	//SET VCC AS REF VALUE
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	// SET LEFT ADJUSTMENT RES
	SET_BIT(ADMUX,ADMUX_ADLAR);

	// SET PRE SCALER TO 128
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	// ADC ENABLE
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
	ADMUX &=0b11100000;
	ADMUX |=Copy_u8Channel;
	SET_BIT(ADCSRA,ADCSRA_ADSC);   // TO START CONVERSION
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0)
	{

	}
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	return ADCH ;
}
