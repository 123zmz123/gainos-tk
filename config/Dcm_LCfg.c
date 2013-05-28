/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 * Generated by GaInOS-TK Studio at 2013-05-28:23-08-10.
 * Don't Modify it by hand.
 * Email: parai@foxmail.com
 * URL: https://github.com/parai/gainos-tk  && http://hi.baidu.com/parai
 */

#include "Std_Types.h"
#include "Dcm.h"
#include "Dcm_Internal.h"
#if defined(USE_PDUR)
#include "PduR.h"
#endif

#define DCM_SECURITY_EOL_INDEX 2
#define DCM_SESSION_EOL_INDEX 2
#define DCM_DID_LIST_EOL_INDEX 2

extern Std_ReturnType vSecurityLevel_0_GetSeed (uint8 *securityAccessDataRecord, uint8 *seed, Dcm_NegativeResponseCodeType *errorCode);
extern Std_ReturnType vSecurityLevel_0_CompKey (uint8 *key);
extern Std_ReturnType vSecurityLevel_1_GetSeed (uint8 *securityAccessDataRecord, uint8 *seed, Dcm_NegativeResponseCodeType *errorCode);
extern Std_ReturnType vSecurityLevel_1_CompKey (uint8 *key);
extern Std_ReturnType vRequestService_0_Start (Dcm_ProtocolType protocolID);
extern Std_ReturnType vRequestService_0_Stop (Dcm_ProtocolType protocolID);

extern Std_ReturnType vRequestService_1_Start (Dcm_ProtocolType protocolID);
extern Std_ReturnType vRequestService_1_Stop (Dcm_ProtocolType protocolID);

extern Std_ReturnType vSessionControl_0_GetSesChgPer(Dcm_SesCtrlType sesCtrlTypeActive, Dcm_SesCtrlType sesCtrlTypeNew);
extern Std_ReturnType vSessionControl_1_GetSesChgPer(Dcm_SesCtrlType sesCtrlTypeActive, Dcm_SesCtrlType sesCtrlTypeNew);
const Dcm_DspSecurityRowType DspSecurityList[] = {
	{ // vSecurityLevel_0
		/* DspSecurityLevel = */ 0,
		/* DspSecurityDelayTimeOnBoot = */ 0,/* Value is not configurable */
		/* DspSecurityNumAttDelay = */ 0, 	/* Value is not configurable */
		/* DspSecurityDelayTime = */ 0, 	/* Value is not configurable */
		/* DspSecurityNumAttLock = */ 0, 	/* Value is not configurable */
		/* DspSecurityADRSize = */ 1,
		/* DspSecuritySeedSize = */ 1,
		/* DspSecurityKeySize = */ 1,
		/* GetSeed = */ vSecurityLevel_0_GetSeed,
		/* CompareKey = */ vSecurityLevel_0_CompKey,
		/* Arc_EOL = */ FALSE
	},
	{ // vSecurityLevel_1
		/* DspSecurityLevel = */ 1,
		/* DspSecurityDelayTimeOnBoot = */ 0,/* Value is not configurable */
		/* DspSecurityNumAttDelay = */ 0, 	/* Value is not configurable */
		/* DspSecurityDelayTime = */ 0, 	/* Value is not configurable */
		/* DspSecurityNumAttLock = */ 0, 	/* Value is not configurable */
		/* DspSecurityADRSize = */ 1,
		/* DspSecuritySeedSize = */ 1,
		/* DspSecurityKeySize = */ 1,
		/* GetSeed = */ vSecurityLevel_1_GetSeed,
		/* CompareKey = */ vSecurityLevel_1_CompKey,
		/* Arc_EOL = */ FALSE
	},
	{ // Dummy For EOL
		/* DspSecurityLevel = */ 0xBD,
		/* DspSecurityDelayTimeOnBoot = */ 0,/* Value is not configurable */
		/* DspSecurityNumAttDelay = */ 0, 	/* Value is not configurable */
		/* DspSecurityDelayTime = */ 0, 	/* Value is not configurable */
		/* DspSecurityNumAttLock = */ 0, 	/* Value is not configurable */
		/* DspSecurityADRSize = */ 0xBD,
		/* DspSecuritySeedSize = */ 0xBD,
		/* DspSecurityKeySize = */ 0xBD,
		/* GetSeed = */ NULL,
		/* CompareKey = */ NULL,
		/* Arc_EOL = */ TRUE
	}
};

const Dcm_DspSecurityType DspSecurity = {
    /* DspSecurityRow = */ DspSecurityList
};
const Dcm_DspSessionRowType DspSessionList[] = {
	{ //vSession_0
		/* DspSessionLevel = */ 0,
		/* DspSessionP2ServerMax = */ 10,
		/* DspSessionP2StarServerMax = */ 10,
		/* Arc_EOL = */ FALSE
	},
	{ //vSession_1
		/* DspSessionLevel = */ 1,
		/* DspSessionP2ServerMax = */ 10,
		/* DspSessionP2StarServerMax = */ 10,
		/* Arc_EOL = */ FALSE
	},
	{ //Dummy Session For EOL
		/* DspSessionLevel = */ 0xBD,
		/* DspSessionP2ServerMax = */ 0xBD,
		/* DspSessionP2StarServerMax = */ 0xBD,
		/* Arc_EOL = */ TRUE
	},
};

const Dcm_DspSessionType DspSession = {
    /* DspSessionRow = */ DspSessionList,
};

const Dcm_DspSecurityRowType *vServiceTable_0_vService0_SecurityList[] = {
	&DspSecurityList[0],//vSecurityLevel_0
	&DspSecurityList[DCM_SECURITY_EOL_INDEX]
};
const Dcm_DspSecurityRowType *vServiceTable_0_vService1_SecurityList[] = {
	&DspSecurityList[0],//vSecurityLevel_0
	&DspSecurityList[DCM_SECURITY_EOL_INDEX]
};
const Dcm_DspSecurityRowType *vServiceTable_1_vService0_SecurityList[] = {
	&DspSecurityList[1],//vSecurityLevel_1
	&DspSecurityList[DCM_SECURITY_EOL_INDEX]
};
const Dcm_DspSessionRowType *vServiceTable_0_vService0_SessionList[] = {
	&DspSessionList[0],//vSession_0
	&DspSessionList[DCM_SESSION_EOL_INDEX]
};
const Dcm_DspSessionRowType *vServiceTable_0_vService1_SessionList[] = {
	&DspSessionList[0],//vSession_0
	&DspSessionList[DCM_SESSION_EOL_INDEX]
};
const Dcm_DspSessionRowType *vServiceTable_1_vService0_SessionList[] = {
	&DspSessionList[1],//vSession_1
	&DspSessionList[DCM_SESSION_EOL_INDEX]
};

const Dcm_DspSessionRowType *vDcmDidInfo_0_read_sessionRefList[] = {
	&DspSessionList[0],//vSession_0
	&DspSessionList[DCM_SESSION_EOL_INDEX]
};
const Dcm_DspSecurityRowType *vDcmDidInfo_0_read_securityRefList[] = {
	&DspSecurityList[0],//vSecurityLevel_0
	&DspSecurityList[DCM_SECURITY_EOL_INDEX]
};
const Dcm_DspDidReadType vDcmDidInfo_0_didRead = {
    /* DspDidReadSessionRef = */ vDcmDidInfo_0_read_sessionRefList,
    /* DspDidReadSecurityLevelRef = */ vDcmDidInfo_0_read_securityRefList
};

const Dcm_DspSessionRowType *vDcmDidInfo_0_write_sessionRefList[] = {
	&DspSessionList[0],//vSession_0
	&DspSessionList[DCM_SESSION_EOL_INDEX]
};
const Dcm_DspSecurityRowType *vDcmDidInfo_0_write_securityRefList[] = {
	&DspSecurityList[0],//vSecurityLevel_0
	&DspSecurityList[DCM_SECURITY_EOL_INDEX]
};
const Dcm_DspDidWriteType vDcmDidInfo_0_didWrite = {
    /* DspDidReadSessionRef = */ vDcmDidInfo_0_write_sessionRefList,
    /* DspDidReadSecurityLevelRef = */ vDcmDidInfo_0_write_securityRefList
};

const Dcm_DspSessionRowType *vDcmDidInfo_0_control_sessionRefList[] = {
	&DspSessionList[0],//vSession_0
	&DspSessionList[DCM_SESSION_EOL_INDEX]
};
const Dcm_DspSecurityRowType *vDcmDidInfo_0_control_securityRefList[] = {
	&DspSecurityList[0],//vSecurityLevel_0
	&DspSecurityList[DCM_SECURITY_EOL_INDEX]
};
const Dcm_DspDidControlType vDcmDidInfo_0_didControl = {
    /* DspDidReadSessionRef = */ vDcmDidInfo_0_control_sessionRefList,
    /* DspDidReadSecurityLevelRef = */ vDcmDidInfo_0_control_securityRefList,
    /* DspDidFreezeCurrentState = */ NULL,
    /* DspDidResetToDefault = */ NULL,
    /* DspDidReturnControlToEcu = */ NULL,
    /* DspDidShortTermAdjustment = */ NULL
};

const Dcm_DspSessionRowType *vDcmDidInfo_1_read_sessionRefList[] = {
	&DspSessionList[1],//vSession_1
	&DspSessionList[DCM_SESSION_EOL_INDEX]
};
const Dcm_DspSecurityRowType *vDcmDidInfo_1_read_securityRefList[] = {
	&DspSecurityList[1],//vSecurityLevel_1
	&DspSecurityList[DCM_SECURITY_EOL_INDEX]
};
const Dcm_DspDidReadType vDcmDidInfo_1_didRead = {
    /* DspDidReadSessionRef = */ vDcmDidInfo_1_read_sessionRefList,
    /* DspDidReadSecurityLevelRef = */ vDcmDidInfo_1_read_securityRefList
};

const Dcm_DspSessionRowType *vDcmDidInfo_1_write_sessionRefList[] = {
	&DspSessionList[1],//vSession_1
	&DspSessionList[DCM_SESSION_EOL_INDEX]
};
const Dcm_DspSecurityRowType *vDcmDidInfo_1_write_securityRefList[] = {
	&DspSecurityList[1],//vSecurityLevel_1
	&DspSecurityList[DCM_SECURITY_EOL_INDEX]
};
const Dcm_DspDidWriteType vDcmDidInfo_1_didWrite = {
    /* DspDidReadSessionRef = */ vDcmDidInfo_1_write_sessionRefList,
    /* DspDidReadSecurityLevelRef = */ vDcmDidInfo_1_write_securityRefList
};

const Dcm_DspSessionRowType *vDcmDidInfo_1_control_sessionRefList[] = {
	&DspSessionList[1],//vSession_1
	&DspSessionList[DCM_SESSION_EOL_INDEX]
};
const Dcm_DspSecurityRowType *vDcmDidInfo_1_control_securityRefList[] = {
	&DspSecurityList[1],//vSecurityLevel_1
	&DspSecurityList[DCM_SECURITY_EOL_INDEX]
};
const Dcm_DspDidControlType vDcmDidInfo_1_didControl = {
    /* DspDidReadSessionRef = */ vDcmDidInfo_1_control_sessionRefList,
    /* DspDidReadSecurityLevelRef = */ vDcmDidInfo_1_control_securityRefList,
    /* DspDidFreezeCurrentState = */ NULL,
    /* DspDidResetToDefault = */ NULL,
    /* DspDidReturnControlToEcu = */ NULL,
    /* DspDidShortTermAdjustment = */ NULL
};

const Dcm_DspDidInfoType DspDidInfoList[] = {
	{ // vDcmDidInfo_0
		 /* DspDidDynamicllyDefined = */ FALSE,
		 /* DspDidFixedLength = */ TRUE,
		 /* DspDidScalingInfoSize = */ 8,
		{ // DspDidAccess
			 /* DspDidRead */ &vDcmDidInfo_0_didRead,
			 /* DspDidWrite */ &vDcmDidInfo_0_didWrite,
			 /* DspDidControl */ &vDcmDidInfo_0_didControl,
		}
	}, 
	{ // vDcmDidInfo_1
		 /* DspDidDynamicllyDefined = */ FALSE,
		 /* DspDidFixedLength = */ TRUE,
		 /* DspDidScalingInfoSize = */ 8,
		{ // DspDidAccess
			 /* DspDidRead */ &vDcmDidInfo_1_didRead,
			 /* DspDidWrite */ &vDcmDidInfo_1_didWrite,
			 /* DspDidControl */ &vDcmDidInfo_1_didControl,
		}
	}, 
};

const Dcm_DspDidType DspDidList[] = { 
	{ // vDid_0,
		/* DspDidUsePort = */ FALSE,/* Value is not configurable */
		/* DspDidIdentifier = */ 0x0,
		/* DspDidInfoRef = */ &DspDidInfoList[0], //vDcmDidInfo_0
		/* DspDidRef = */ NULL, //I cann't understand
		/* DspDidSize = */ 64,
		/* DspDidReadDataLengthFnc = */ NULL,
        /* DspDidConditionCheckReadFnc = */ NULL,
        /* DspDidReadDataFnc = */ NULL,
        /* DspDidConditionCheckWriteFnc = */ NULL,
        /* DspDidWriteDataFnc = */ NULL,
        /* DspDidGetScalingInfoFnc = */ NULL,
        /* DspDidFreezeCurrentStateFnc = */ NULL,	
        /* DspDidResetToDefaultFnc = */ NULL,
        /* DspDidReturnControlToEcuFnc = */ NULL,
        /* DspDidShortTermAdjustmentFnc = */ NULL,
        /* DspDidControlRecordSize = */ NULL,
		/* Arc_EOL = */ FALSE
	},
	{ // vDid_1,
		/* DspDidUsePort = */ FALSE,/* Value is not configurable */
		/* DspDidIdentifier = */ 0x1,
		/* DspDidInfoRef = */ &DspDidInfoList[1], //vDcmDidInfo_1
		/* DspDidRef = */ NULL, //I cann't understand
		/* DspDidSize = */ 64,
		/* DspDidReadDataLengthFnc = */ NULL,
        /* DspDidConditionCheckReadFnc = */ NULL,
        /* DspDidReadDataFnc = */ NULL,
        /* DspDidConditionCheckWriteFnc = */ NULL,
        /* DspDidWriteDataFnc = */ NULL,
        /* DspDidGetScalingInfoFnc = */ NULL,
        /* DspDidFreezeCurrentStateFnc = */ NULL,	
        /* DspDidResetToDefaultFnc = */ NULL,
        /* DspDidReturnControlToEcuFnc = */ NULL,
        /* DspDidShortTermAdjustmentFnc = */ NULL,
        /* DspDidControlRecordSize = */ NULL,
		/* Arc_EOL = */ FALSE
	},
	{ // Dummy for EOL,
		/* DspDidUsePort = */ FALSE,/* Value is not configurable */
		/* DspDidIdentifier = */ 0xDB,
		/* DspDidInfoRef = */ NULL,
		/* DspDidRef = */ NULL, //I cann't understand
		/* DspDidSize = */ 0xDB,
		/* DspDidReadDataLengthFnc = */ NULL,
        /* DspDidConditionCheckReadFnc = */ NULL,
        /* DspDidReadDataFnc = */ NULL,
        /* DspDidConditionCheckWriteFnc = */ NULL,
        /* DspDidWriteDataFnc = */ NULL,
        /* DspDidGetScalingInfoFnc = */ NULL,
        /* DspDidFreezeCurrentStateFnc = */ NULL,	
        /* DspDidResetToDefaultFnc = */ NULL,
        /* DspDidReturnControlToEcuFnc = */ NULL,
        /* DspDidShortTermAdjustmentFnc = */ NULL,
        /* DspDidControlRecordSize = */ NULL,
		/* Arc_EOL = */ TRUE
	}
};

/************************************************************************
 *							Routine control								*
 ************************************************************************/

/************************************************************************
 *							Memory Info             					*
 ************************************************************************/

const Dcm_DspType Dsp = {
    /* DspMaxDidToRead = */ 0x99,//????
    /* DspDid = */ DspDidList,
    /* DspDidInfo = */ DspDidInfoList,
    /* DspEcuReset = */ NULL,
    /* DspPid = */ NULL,
    /* DspReadDTC = */ NULL,
    /* DspRequestControl = */ NULL,
    /* DspRoutine = */ NULL,//DspRoutineList,???
    /* DspRoutineInfo = */ NULL,//DspRoutineInfoList,???
    /* DspSecurity = */ &DspSecurity,
    /* DspSession = */ &DspSession,
    /* DspTestResultByObdmid = */ NULL,
    /* DspVehInfo = */ NULL
};

/************************************************************************
 *									DSD									*
 ************************************************************************/

const Dcm_DsdServiceType vServiceTable_0_serviceList[] = {
	{ // vService0
		 /* DsdSidTabServiceId =*/ SID_DIAGNOSTIC_SESSION_CONTROL,
		 /* DsdSidTabSubfuncAvail =*/ FALSE,
		 /* DsdSidTabSecurityLevelRef =*/ vServiceTable_0_vService0_SecurityList,
		 /* DsdSidTabSessionLevelRef =*/ vServiceTable_0_vService0_SessionList,
		 /* Arc_EOL = */ FALSE
	},
	{ // vService1
		 /* DsdSidTabServiceId =*/ SID_ECU_RESET,
		 /* DsdSidTabSubfuncAvail =*/ FALSE,
		 /* DsdSidTabSecurityLevelRef =*/ vServiceTable_0_vService1_SecurityList,
		 /* DsdSidTabSessionLevelRef =*/ vServiceTable_0_vService1_SessionList,
		 /* Arc_EOL = */ FALSE
	},
	{ // Dummy For EOL
		 /* DsdSidTabServiceId =*/ 0xDB,
		 /* DsdSidTabSubfuncAvail =*/ FALSE,
		 /* DsdSidTabSecurityLevelRef =*/ NULL,
		 /* DsdSidTabSessionLevelRef =*/ NULL,
		 /* Arc_EOL = */ TRUE
	}
};

const Dcm_DsdServiceType vServiceTable_1_serviceList[] = {
	{ // vService0
		 /* DsdSidTabServiceId =*/ SID_READ_DTC_INFORMATION,
		 /* DsdSidTabSubfuncAvail =*/ FALSE,
		 /* DsdSidTabSecurityLevelRef =*/ vServiceTable_1_vService0_SecurityList,
		 /* DsdSidTabSessionLevelRef =*/ vServiceTable_1_vService0_SessionList,
		 /* Arc_EOL = */ FALSE
	},
	{ // Dummy For EOL
		 /* DsdSidTabServiceId =*/ 0xDB,
		 /* DsdSidTabSubfuncAvail =*/ FALSE,
		 /* DsdSidTabSecurityLevelRef =*/ NULL,
		 /* DsdSidTabSessionLevelRef =*/ NULL,
		 /* Arc_EOL = */ TRUE
	}
};

const Dcm_DsdServiceTableType DsdServiceTable[] = {	
	{ // vServiceTable_0
		 /* DsdSidTabId = */ 0,
		 /* DsdService = */ vServiceTable_0_serviceList,
		 /* Arc_EOL = */ FALSE
	},
	{ // vServiceTable_1
		 /* DsdSidTabId = */ 1,
		 /* DsdService = */ vServiceTable_1_serviceList,
		 /* Arc_EOL = */ FALSE
	},
	{ // Dummy For EOL 
		 /* DsdSidTabId = */ 0xDB,
		 /* DsdService = */ NULL,
		 /* Arc_EOL = */ TRUE
	}
};

const Dcm_DsdType Dsd = {
    /* DsdServiceTable = */ DsdServiceTable
};

/************************************************************************
 *									DSL									*
 ************************************************************************/

uint8 vDcmBuffer_0_RX[8];
Dcm_DslBufferRuntimeType rxBufferParams_vDcmBuffer_0_RX =
{
	/* status = */ NOT_IN_USE
};
uint8 vDcmBuffer_0_TX[8];
Dcm_DslBufferRuntimeType rxBufferParams_vDcmBuffer_0_TX =
{
	/* status = */ NOT_IN_USE
};
uint8 vDcmBuffer_1_RX[8];
Dcm_DslBufferRuntimeType rxBufferParams_vDcmBuffer_1_RX =
{
	/* status = */ NOT_IN_USE
};
uint8 vDcmBuffer_1_TX[8];
Dcm_DslBufferRuntimeType rxBufferParams_vDcmBuffer_1_TX =
{
	/* status = */ NOT_IN_USE
};
const Dcm_DslBufferType DcmDslBufferList[DCM_DSL_BUFFER_LIST_LENGTH] = {
	{ // vDcmBuffer_0_RX
		/* DslBufferID = */ 0,//? I am not that clear.
		/* DslBufferSize = */ 8,/* ?Value is not configurable */
		{ /* pduInfo */
			/* SduDataPtr = */ vDcmBuffer_0_RX,
			/* SduLength = */ 8,
		},
		/* externalBufferRuntimeData = */ &rxBufferParams_vDcmBuffer_0_RX
	},
	{ // vDcmBuffer_0_TX
		/* DslBufferID = */ 0,//? I am not that clear.
		/* DslBufferSize = */ 8,/* ?Value is not configurable */
		{ /* pduInfo */
			/* SduDataPtr = */ vDcmBuffer_0_TX,
			/* SduLength = */ 8,
		},
		/* externalBufferRuntimeData = */ &rxBufferParams_vDcmBuffer_0_TX
	},
	{ // vDcmBuffer_1_RX
		/* DslBufferID = */ 0,//? I am not that clear.
		/* DslBufferSize = */ 8,/* ?Value is not configurable */
		{ /* pduInfo */
			/* SduDataPtr = */ vDcmBuffer_1_RX,
			/* SduLength = */ 8,
		},
		/* externalBufferRuntimeData = */ &rxBufferParams_vDcmBuffer_1_RX
	},
	{ // vDcmBuffer_1_TX
		/* DslBufferID = */ 0,//? I am not that clear.
		/* DslBufferSize = */ 8,/* ?Value is not configurable */
		{ /* pduInfo */
			/* SduDataPtr = */ vDcmBuffer_1_TX,
			/* SduLength = */ 8,
		},
		/* externalBufferRuntimeData = */ &rxBufferParams_vDcmBuffer_1_TX
	},
};

const Dcm_DslCallbackDCMRequestServiceType DCMRequestServiceList[] = {
	{ // vRequestService_0
		/* StartProtocol = */ vRequestService_0_Start,
		/* StopProtocol = */ vRequestService_0_Stop,
		/* Arc_EOL = */ FALSE	},
	{ // vRequestService_1
		/* StartProtocol = */ vRequestService_1_Start,
		/* StopProtocol = */ vRequestService_1_Stop,
		/* Arc_EOL = */ FALSE	},
	{ // Dummy For EOL
		/* StartProtocol = */ NULL,
		/* StopProtocol = */ NULL,
		/* Arc_EOL = */ TRUE	}
};

extern const Dcm_DslMainConnectionType DslMainConnectionList[];

const Dcm_DslProtocolRxType DcmDslProtocolRxList[] = {
	{// vProtocol_0->vConnection0->vRxChannel0
		/* DslMainConnectionParent = */ &DslMainConnectionList[0],
		/* DslProtocolAddrType = */ DCM_PROTOCOL_PHYSICAL_ADDR_TYPE,
		/* DcmDslProtocolRxPduId = */ PDUR_RX_vEcuC_Pdu_0,
		/* DcmDslProtocolRxTesterSourceAddr_v4 = */ 0,		/* Value is not configurable */
		/* DcmDslProtocolRxChannelId_v4 = */ 0,				/* Value is not configurable */
		/* Arc_EOL = */ FALSE
	},
	{// vProtocol_1->vConnection0->vRxChannel0
		/* DslMainConnectionParent = */ &DslMainConnectionList[0],
		/* DslProtocolAddrType = */ DCM_PROTOCOL_PHYSICAL_ADDR_TYPE,
		/* DcmDslProtocolRxPduId = */ PDUR_RX_vEcuC_Pdu_1,
		/* DcmDslProtocolRxTesterSourceAddr_v4 = */ 0,		/* Value is not configurable */
		/* DcmDslProtocolRxChannelId_v4 = */ 0,				/* Value is not configurable */
		/* Arc_EOL = */ FALSE
	},
	{// Dummy for EOL
		/* DslMainConnectionParent = */ NULL,
		/* DslProtocolAddrType = */ 0xDB,
		/* DcmDslProtocolRxPduId = */ 0xDB,
		/* DcmDslProtocolRxTesterSourceAddr_v4 = */ 0,		/* Value is not configurable */
		/* DcmDslProtocolRxChannelId_v4 = */ 0,				/* Value is not configurable */
		/* Arc_EOL = */ TRUE
	}
};

const Dcm_DslProtocolTxType DcmDslProtocolTxList[] = {
	{// vProtocol_0->vConnection0->vTxChannel0
		/* DslMainConnectionParent = */ &DslMainConnectionList[0],
		/* DcmDslProtocolTxPduId = */ PDUR_TX_vEcuC_Pdu_0,
		/* Arc_EOL = */ FALSE
	},
	{// vProtocol_1->vConnection0->vTxChannel0
		/* DslMainConnectionParent = */ &DslMainConnectionList[0],
		/* DcmDslProtocolTxPduId = */ PDUR_TX_vEcuC_Pdu_1,
		/* Arc_EOL = */ FALSE
	},
	{// Dummy for EOL
		/* DslMainConnectionParent = */ NULL,
		/* DcmDslProtocolTxPduId = */ 0xDB,
		/* Arc_EOL = */ TRUE
	}
};

extern const Dcm_DslConnectionType DslConnectionList[];

const Dcm_DslMainConnectionType DslMainConnectionList[] = {
	{//vProtocol_0->vConnection0
		/* DslConnectionParent = */ &DslConnectionList[0],
		/* DslPeriodicTransmissionConRef = */ NULL,		/* Value is not configurable */
		/* DslROEConnectionRef = */ NULL,				/* Value is not configurable */
		/* DslProtocolRx = */ NULL,						/* Value is not configurable */
		/* DslProtocolTx = */ &DcmDslProtocolTxList[0],
	},
	{//vProtocol_1->vConnection0
		/* DslConnectionParent = */ &DslConnectionList[1],
		/* DslPeriodicTransmissionConRef = */ NULL,		/* Value is not configurable */
		/* DslROEConnectionRef = */ NULL,				/* Value is not configurable */
		/* DslProtocolRx = */ NULL,						/* Value is not configurable */
		/* DslProtocolTx = */ &DcmDslProtocolTxList[1],
	},
};

extern const Dcm_DslProtocolRowType DslProtocolRowList[];

const Dcm_DslConnectionType DslConnectionList[] = {
	{//vProtocol_0->vConnection0
		/* DslProtocolRow = */ &DslProtocolRowList[0],
		/* DslMainConnection = */ &DslMainConnectionList[0],
		/* DslPeriodicTransmission = */ NULL,	/* Value is not configurable */
		/* DslResponseOnEvent = */ NULL,	/* Value is not configurable */
		/* Arc_EOL = */ FALSE
	},
	{//vProtocol_1->vConnection0
		/* DslProtocolRow = */ &DslProtocolRowList[1],
		/* DslMainConnection = */ &DslMainConnectionList[1],
		/* DslPeriodicTransmission = */ NULL,	/* Value is not configurable */
		/* DslResponseOnEvent = */ NULL,	/* Value is not configurable */
		/* Arc_EOL = */ FALSE
	},
	{//Dummy For EOL
		/* DslProtocolRow = */ NULL,
		/* DslMainConnection = */ NULL,
		/* DslPeriodicTransmission = */ NULL,
		/* DslResponseOnEvent = */ NULL,
		/* Arc_EOL = */ TRUE
	}
};

extern const Dcm_DslProtocolTimingRowType ProtocolTimingList[];

Dcm_DslRunTimeProtocolParametersType dcmDslRuntimeVariables[2];
const Dcm_DslProtocolRowType DslProtocolRowList[]= {
	{//vProtocol_0
		/* DslProtocolID = */ DCM_UDS_ON_CAN,
		/* DslProtocolIsParallelExecutab = */ FALSE, // not supported
		/* DslProtocolPreemptTimeout = */ 0,	// not supported
		/* DslProtocolPriority = */ 0,	// not supported
		/* DslProtocolTransType = */ DCM_PROTOCOL_TRANS_TYPE_1,
		/* DslProtocolRxBufferID = */ &DcmDslBufferList[0],//vDcmBuffer_0_RX
		/* DslProtocolTxBufferID = */ &DcmDslBufferList[1],//vDcmBuffer_0_TX
		/* DslProtocolSIDTable = */ &DsdServiceTable[0],//vServiceTable_0
		/* DslProtocolTimeLimit = */ &ProtocolTimingList[0],//vTiming_0
		/* DslConnection = */ DslConnectionList,
		/* DslRunTimeProtocolParameters = */ &dcmDslRuntimeVariables[0],
		/* Arc_EOL = */ FALSE
	},
	{//vProtocol_1
		/* DslProtocolID = */ DCM_UDS_ON_CAN,
		/* DslProtocolIsParallelExecutab = */ FALSE, // not supported
		/* DslProtocolPreemptTimeout = */ 0,	// not supported
		/* DslProtocolPriority = */ 0,	// not supported
		/* DslProtocolTransType = */ DCM_PROTOCOL_TRANS_TYPE_1,
		/* DslProtocolRxBufferID = */ &DcmDslBufferList[2],//vDcmBuffer_1_RX
		/* DslProtocolTxBufferID = */ &DcmDslBufferList[3],//vDcmBuffer_1_TX
		/* DslProtocolSIDTable = */ &DsdServiceTable[1],//vServiceTable_1
		/* DslProtocolTimeLimit = */ &ProtocolTimingList[1],//vTiming_1
		/* DslConnection = */ DslConnectionList,
		/* DslRunTimeProtocolParameters = */ &dcmDslRuntimeVariables[1],
		/* Arc_EOL = */ FALSE
	},
	{//Dummy for EOL
		/* DslProtocolID = */ 0xDB,
		/* DslProtocolIsParallelExecutab = */ FALSE, // not supported
		/* DslProtocolPreemptTimeout = */ 0,	// not supported
		/* DslProtocolPriority = */ 0,	// not supported
		/* DslProtocolTransType = */ 0xDB,
		/* DslProtocolRxBufferID = */ NULL,
		/* DslProtocolTxBufferID = */ NULL,
		/* DslProtocolSIDTable = */ NULL,
		/* DslProtocolTimeLimit = */ NULL,
		/* DslConnection = */ NULL,
		/* DslRunTimeProtocolParameters = */ NULL,
		/* Arc_EOL = */ TRUE
	}
};

const Dcm_DslProtocolType DslProtocol = {
    /* DslProtocolRxGlobalList = */ DcmDslProtocolRxList,
    /* DslProtocolTxGlobalList = */ DcmDslProtocolTxList,
    /* DslProtocolRowList = */ DslProtocolRowList
};

const Dcm_DslProtocolTimingRowType ProtocolTimingList[] = {
	{//vTiming_0
		/* TimStrP2ServerMax = */ 10,
		/* TimStrP2ServerMin = */ 5,
		/* TimStrP2StarServerMax = */ 0,		/* Value is not configurable */
		/* TimStrP2StarServerMin = */ 0,		/* Value is not configurable */
		/* TimStrS3Server = */ 10,
		/* Arc_EOL = */ FALSE
	},
	{//vTiming_1
		/* TimStrP2ServerMax = */ 10,
		/* TimStrP2ServerMin = */ 5,
		/* TimStrP2StarServerMax = */ 0,		/* Value is not configurable */
		/* TimStrP2StarServerMin = */ 0,		/* Value is not configurable */
		/* TimStrS3Server = */ 10,
		/* Arc_EOL = */ FALSE
	},
	{//Dummy For EOL
		/* TimStrP2ServerMax = */ 0,
		/* TimStrP2ServerMin = */ 0,
		/* TimStrP2StarServerMax = */ 0,		/* Value is not configurable */
		/* TimStrP2StarServerMin = */ 0,		/* Value is not configurable */
		/* TimStrS3Server = */ 0,
		/* Arc_EOL = */ TRUE
	},
};

const Dcm_DslProtocolTimingType ProtocolTiming = {
    /* DslProtocolTimingRow = */ ProtocolTimingList
};

const Dcm_DslSessionControlType SessionControlList[] = {
	{//vSessionControl_0
		 /* GetSesChgPermission = */ vSessionControl_0_GetSesChgPer,
		 /* ChangeIndication = */ NULL,
		 /* ConfirmationRespPend = */ NULL,
		 /* Arc_EOL = */ FALSE
	},
	{//vSessionControl_1
		 /* GetSesChgPermission = */ vSessionControl_1_GetSesChgPer,
		 /* ChangeIndication = */ NULL,
		 /* ConfirmationRespPend = */ NULL,
		 /* Arc_EOL = */ FALSE
	},
	{//Dummy For EOL
		 /* GetSesChgPermission = */ NULL,
		 /* ChangeIndication = */ NULL,
		 /* ConfirmationRespPend = */ NULL,
		 /* Arc_EOL = */ TRUE
	}
};

const Dcm_DslDiagRespType DiagResp = {
    /* DslDiagRespForceRespPendEn = */ TRUE,
    /* DslDiagRespMaxNumRespPend = */ 10
};

const Dcm_DslType Dsl = {
    /* DslBuffer = */ DcmDslBufferList,
    /* DslCallbackDCMRequestService = */ DCMRequestServiceList,
    /* DslDiagResp = */ &DiagResp,
    /* DslProtocol = */ &DslProtocol,
    /* DslProtocolTiming = */ &ProtocolTiming,
    /* DslServiceRequestIndication = */ NULL,
    /* DslSessionControl = */ SessionControlList
};

const Dcm_ConfigType DCM_Config = {
    /* Dsp = */ &Dsp,
    /* Dsd = */ &Dsd,
    /* Dsl = */ &Dsl
};
