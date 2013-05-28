#include "Os.h"
#include "Dcm.h"
#include "Can.h"
#include "CanIf.h"
#include "CanTp.h"
#include "PduR.h"
#include <stdio.h>
/* ֪ͨ�ص����� */
Std_ReturnType vSecurityLevel_0_GetSeed (uint8 *securityAccessDataRecord, uint8 *seed, 
                        Dcm_NegativeResponseCodeType *errorCode)
{
}
Std_ReturnType vSecurityLevel_0_CompKey (uint8 *key)
{
}
Std_ReturnType vSecurityLevel_1_GetSeed (uint8 *securityAccessDataRecord, uint8 *seed, 
                        Dcm_NegativeResponseCodeType *errorCode)
{
}
Std_ReturnType vSecurityLevel_1_CompKey (uint8 *key)
{
}
Std_ReturnType vRequestService_0_Start (Dcm_ProtocolType protocolID)
{
}
Std_ReturnType vRequestService_0_Stop (Dcm_ProtocolType protocolID)
{
}

Std_ReturnType vRequestService_1_Start (Dcm_ProtocolType protocolID)
{
}
Std_ReturnType vRequestService_1_Stop (Dcm_ProtocolType protocolID)
{
}

Std_ReturnType vSessionControl_0_GetSesChgPer(Dcm_SesCtrlType sesCtrlTypeActive,
                                             Dcm_SesCtrlType sesCtrlTypeNew)
{
}
Std_ReturnType vSessionControl_1_GetSesChgPer(Dcm_SesCtrlType sesCtrlTypeActive, 
                                            Dcm_SesCtrlType sesCtrlTypeNew)
{
}
/* Dcm Example Initialise Routine.
 * ��ʼ��Can��CanIf��PduR��DCM ��
 * ��Ҫʹ�á�dcm_ex1.arxml����������Ӧ�����ļ���*/
void DcmEx1Init(void)
{
    Can_Init(&Can_ConfigData); 
    CanIf_Init(&CanIf_Config);
    CanTp_Init();
    PduR_Init(&PduR_Config);
    Dcm_Init();
    //�������õ�����CANͨ�� CAN_CTRL_0 �� CAN_CTRL_1
    CanIf_SetControllerMode(vCanIf_Channel_0,CANIF_CS_STARTED);
    CanIf_SetControllerMode(vCanIf_Channel_1,CANIF_CS_STARTED);
}

/* Dcm Example Main Function Routine.
 * ���API���뱻�����Եĵ��ã�����ÿ 5ms һ��*/
void DcmEx1MainFunction(void)
{
    CanTp_MainFunction();
    Dcm_MainFunction();
}

void DcmEx1Sender(void)
{
    PduInfoType pduInfo = 
    {
        NULL,
        128 
    };
    PduR_DcmTransmit(PDUR_TX_vEcuC_Pdu_0,&pduInfo);
}