/* BitOperation.h
This header provides the Macros for convenient bit operations (set/clr) of GPIO pins on AVR MCUs. 

                                                              hyzhang7
                                                              2010
*/
#ifndef __BIT_OPT_GENERAL__
#define __BIT_OPT_GENERAL__
#define SETB_P(port,pin)  SETB_P ## port(pin)
#define CLR_P(port,pin)  CLR_P ## port(pin)
#define OUT_P(port,pin)   DDR ## port |=(1<<pin)
#define IN_P(port,pin)    DDR ## port &=~(1<<pin)
#endif

#ifndef __BIT_OPT_PD__
#define __BIT_OPT_PD__ 
#define  SETB_PD(x)  PORTD|=(1<<(x))
#define  CLR_PD(x)   PORTD&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PB__
#define __BIT_OPT_PB__
#define  SETB_PB(x)  PORTB|=(1<<(x))
#define  CLR_PB(x)   PORTB&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PC__
#define __BIT_OPT_PC__
#define  SETB_PC(x)  PORTC|=(1<<(x))
#define  CLR_PC(x)   PORTC&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PA__
#define __BIT_OPT_PA__
#define  SETB_PA(x)  PORTA|=(1<<(x))
#define  CLR_PA(x)   PORTA&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PE__
#define __BIT_OPT_PE__
#define  SETB_PE(x)  PORTE|=(1<<(x))
#define  CLR_PE(x)   PORTE&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PF__
#define __BIT_OPT_PF__
#define  SETB_PF(x)  PORTF|=(1<<(x))
#define  CLR_PF(x)   PORTF&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PG__
#define __BIT_OPT_PG__
#define  SETB_PG(x)  PORTG|=(1<<(x))
#define  CLR_PG(x)   PORTG&=~(1<<(x))
#endif
