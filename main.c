#include "stm8s.h"
#include "main.h"
#include "milis.h"
#include "daughterboard.h"

//#include "delay.h"
//#include <stdio.h>
//#include "uart1.h"

void setup(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
#if defined (BTN_PORT) || defined (BTN_PIN)
    GPIO_Init(BTN_PORT, BTN_PIN, GPIO_MODE_IN_FL_NO_IT);
    GPIO_Init(LED1_PORT, LED1_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED2_PORT, LED2_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED3_PORT, LED3_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED4_PORT, LED4_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED5_PORT, LED5_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED6_PORT, LED6_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED7_PORT, LED7_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED8_PORT, LED8_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);


    GPIO_Init(PWMR_PORT, PWMR_PIN, GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_Init(PWMG_PORT, PWMG_PIN, GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_Init(PWMB_PORT, PWMB_PIN, GPIO_MODE_OUT_PP_LOW_FAST);

    GPIO_Init(S1_PORT, S1_PIN, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(S2_PORT, S2_PIN, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(S3_PORT, S3_PIN, GPIO_MODE_IN_PU_NO_IT);

#endif

    init_milis();
    //init_uart1();
}


int main(void)
{
    uint32_t time1 = 0;
    uint32_t time2 = 1000;
    uint32_t time3 = 2000;
    uint32_t time4 = 4000;
    uint32_t time5 = 0;
    uint32_t time6 = 0;
    uint32_t time7 = 0;
    uint32_t time8 = 0;
    uint8_t btn_push = 0;    //pamatuje si stisk tlacitka
    uint32_t time_btn = 0;
    
    setup();
    while(1){
        
        if (milis() - time_btn > 20){
            time_btn = milis();             
            if (PUSH(S1))
            {
                btn_push = 1;    
            }
            else{
                if (btn_push == 1)
                {
                    REVERSE(PWMR);
                }
                btn_push = 0;
            }
            if (PUSH(S2))
            {
                btn_push = 1;    
            }
            else{
                if (btn_push == 1)
                {
                    REVERSE(PWMB);
                }
                    btn_push = 0;
                }       
            if (PUSH(S3))
            {
                btn_push = 1;    
            }
            else{
                if (btn_push == 1)
                {
                    REVERSE(PWMG);
                }
                btn_push = 0;
            }
        }
    
        


        
        /*
        if(GPIO_ReadInputPin(S1_PORT, S1_PIN) == 0){
            HIGH(PWMR);}
        else{
            LOW(PWMR);
        }
        if(PUSH(S2)){
            HIGH(PWMG);
        }
        else{
            LOW(PWMG);
        }
        
        if (PUSH(S3))
        {
            HIGH(PWMB);
        }
        else{
        LOW(PWMB);
        }
        */
        /*
        if (milis() - time1 > 10000 ) {
            GPIO_WriteReverse(GPIOG, LED1_PIN);
            time1 = milis();
        }        
        if (milis() - time2 > 10000){
            GPIO_WriteReverse(GPIOG, LED2_PIN);
            time2 = milis();
        }
        if (milis() - time3 > 10000){
            GPIO_WriteReverse(GPIOG, LED3_PIN);
            time3 = milis();
        }
        if (milis() - time4 > 10000){
            GPIO_WriteReverse(GPIOG, LED4_PIN);
            time4 = milis();
        }     
        */
        }
        
    }


/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
