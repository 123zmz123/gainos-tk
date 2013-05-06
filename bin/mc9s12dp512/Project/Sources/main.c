#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Std_Types.h"
#include <stdio.h>
#include "Os.h"
#include "osek_os.h"


void TERMIO_PutChar(char c)
{
    while(!SCI0SR1_TDRE);       /* �ȴ��������ݼĴ�������������Ϊ�� */
	SCI0DRL = c;
}
static void Sci_Init()
{
	SCI0BD = CPU_FREQUENCY/16/115200;   /* ����SCI0������Ϊ115200 */
	SCI0CR1 = 0x00;       /* ����SCI0Ϊ����ģʽ����λ����λ������żУ��*/
	SCI0CR2 = 0x08;       /* ���������ݣ���ֹ�жϹ��� */
}

#define BOOT_MESSAGE    \
"GaInOS-TK is really a copy of uTenux.\r\n"  \
"Author: parai\r\n"   \
"Email:parai@foxmail.com"

void main(void) {
    Sci_Init();
    printf("\r\nStart OS.%s\r\n",BOOT_MESSAGE);
    StartOS(OSDEFAULTAPPMODE);
}
