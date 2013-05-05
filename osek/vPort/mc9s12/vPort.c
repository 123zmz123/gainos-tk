#include "vPort.h"
#include "derivative.h"      /* derivative-specific definitions */

LOCAL 	UB	knl_tmp_stack[cfgTMP_STACK_SZ];
/*
 *    Function Name : disint
 *    Description   : Disable external interrupt,CPSR interrupt flag is in  disabled status.
 */
EXPORT UB disint()
{
    asm psha;
    asm tpa;
    asm tab; 
    asm sei;
    asm pula;
}

/*
 *    Function Name : enaint
 *    Description   : Enable external interrupt (restore to original state),
 *                    Updates CPSR interrupt disabled flag with the intsts interrupt flag.
 */
EXPORT void enaint(UB mask)
{
    (void)mask;
    asm psha;  
    asm tba;
    asm tap;
    asm pula;
}

EXPORT UB knl_getPRIMASK ( void )
{
    asm psha; /* sava A */
	asm tpa;
    asm tab;
    asm pula;
}
EXPORT void knl_system_clock_init(void)
{
    CRGINT = 0;                  //���ж�
    CLKSEL_PLLSEL = 0;           //��δ��ʼ��PLLǰ��ʹ��PLL�������ΪCPUʱ��
    
  #if(CPU_FREQUENCY == 40000000) 
    SYNR = 4;
  #elif(CPU_FREQUENCY == 32000000)
    SYNR = 3;     
  #elif(CPU_FREQUENCY == 24000000)
    SYNR = 2;
  #endif 

    REFDV = 1;                   //PLLCLK=2��OSCCLK��(SYNR+1)/(REFDV+1)��64MHz ,fbus=32M
    PLLCTL_PLLON = 1;            //��PLL
    PLLCTL_AUTO = 1;             //ѡȡ�Զ�ģʽ
    while (CRGFLG_LOCK == 0);    //�ȴ�PLL����Ƶ��
    CLKSEL_PLLSEL = 1;           //ѡ��ϵͳʱ����PLL����
}

EXPORT void knl_start_hw_timer( void )
{
    CRGINT_RTIE=1;       //ʹ��ʵʱ�ж�
    RTICTL = 0x70;       //����ʵʱ�жϵ�ʱ����Ϊ4.096ms
    //�ж�����=1/16 x 10E-6 x ��0+1��x 2E��7+9��=0.004096s=4.096ms 
}
EXPORT void knl_setup_context( TCB *tcb )
{
    SStackFrame     *ssp;
    UW pc;
    ID tskid = tcb - knl_tcb_table;
    ssp = knl_gtsk_table[tskid].isstack;
    ssp--;
    pc = (UW)knl_gtsk_table[tskid].task;

    /* CPU context initialization */
    ssp->ppage =(VB)pc;
    ssp->taskmode  = 0;             /* Initial taskmode */
    ssp->ccr = (0xC0);              /* CCR Register (Disable STOP instruction and XIRQ)       */
    ssp->pc = (VH)(pc>>8);          /* Task startup address */
    tcb->tskctxb.ssp = ssp;         /* System stack */
}
LOCAL void knl_low_pow(void)
{
}
#pragma CODE_SEG __NEAR_SEG NON_BANKED
static void l_dispatch0(void)
{
    l_dispatch1:
    asm sei;   //disable interrupt
    if(knl_schedtsk==(void *)0)
    {
        knl_low_pow();
        asm cli;  //enable interrupt
        goto l_dispatch1;
    }
    l_dispatch2:
    knl_ctxtsk=knl_schedtsk;
	knl_dispatch_disabled=0;    /* Dispatch enable */
	/* Context restore */
	asm   ldx  knl_ctxtsk;
	asm   lds  SP_OFFSET,x;       /* Restore 'ssp' from TCB */
	asm   pula
    asm   staa	$30	      /* restore PPAGE */
    asm   puld;
    asm   std   knl_taskmode  /* restore knl_taskmode */
    asm   rti;   
}
void knl_force_dispatch(void)
{
    asm  lds #knl_tmp_stack:(cfgTMP_STACK_SZ-1)   /* Set temporal stack */
    knl_dispatch_disabled=1;    /* Dispatch disable */ 
    knl_ctxtsk=(void *)0;
    asm sei; 
    asm jmp l_dispatch0;
}

interrupt 4 void knl_dispatch_entry(void)
{
_ret_int_dispatch:
    knl_dispatch_disabled=1;    /* Dispatch disable */ 
    asm   ldd   knl_taskmode  
    asm   pshd;                 /* save knl_taskmode */
    asm   ldaa	$30		        
	asm   psha                  /* save ppage */
	asm   ldx  knl_ctxtsk;
	asm   sts  SP_OFFSET,x;            /* save 'ssp' to TCB */
	knl_ctxtsk=(void*)0;
	asm jmp l_dispatch0;  	    	
}
interrupt 7 void knl_systick_handler(void)
{  
    CRGFLG &=0xEF;			// clear the interrupt flag  
	asm cli;     /* enable interrupt */ 
	(void)IncrementCounter(0);		
}
#pragma CODE_SEG DEFAULT