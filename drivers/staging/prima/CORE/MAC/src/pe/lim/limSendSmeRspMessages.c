/*
<<<<<<< HEAD
=======
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
/*
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Airgo Networks, Inc proprietary. All rights reserved.
 * This file limSendSmeRspMessages.cc contains the functions
 * for sending SME response/notification messages to applications
 * above MAC software.
 * Author:        Chandra Modumudi
 * Date:          02/13/02
 * History:-
 * Date           Modified by    Modification Information
 * --------------------------------------------------------------------
 */

#include "vos_types.h"
#include "wniApi.h"
#include "sirCommon.h"
#include "aniGlobal.h"

<<<<<<< HEAD
#if (WNI_POLARIS_FW_PRODUCT == AP)
#include "wniCfgAp.h"
#else
#include "wniCfgSta.h"
#endif
#include "sysDef.h"
#include "cfgApi.h"

#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
#include "halDataStruct.h"
#include "halCommonApi.h"
#endif
=======
#include "wniCfgSta.h"
#include "sysDef.h"
#include "cfgApi.h"

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

#include "schApi.h"
#include "utilsApi.h"
#include "limUtils.h"
#include "limSecurityUtils.h"
#include "limSerDesUtils.h"
#include "limSendSmeRspMessages.h"
#include "limIbssPeerMgmt.h"
#include "limSessionUtils.h"


/**
 * limSendSmeRsp()
 *
 *FUNCTION:
 * This function is called by limProcessSmeReqMessages() to send
 * eWNI_SME_START_RSP, eWNI_SME_MEASUREMENT_RSP, eWNI_SME_STOP_BSS_RSP
 * or eWNI_SME_SWITCH_CHL_RSP messages to applications above MAC
 * Software.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac         Pointer to Global MAC structure
 * @param msgType      Indicates message type
 * @param resultCode   Indicates the result of previously issued
 *                     eWNI_SME_msgType_REQ message
 *
 * @return None
 */

void
limSendSmeRsp(tpAniSirGlobal pMac, tANI_U16 msgType,
              tSirResultCodes resultCode,tANI_U8 smesessionId, tANI_U16 smetransactionId)
{
    tSirMsgQ    mmhMsg;
    tSirSmeRsp  *pSirSmeRsp;

    PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
           FL("Sending message %s with reasonCode %s\n"),
=======
           FL("Sending message %s with reasonCode %s"),
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           limMsgStr(msgType), limResultCodeStr(resultCode));)

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeRsp, sizeof(tSirSmeRsp)))
    {
        /// Buffer not available. Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("call to palAllocateMemory failed for eWNI_SME_*_RSP\n"));
=======
               FL("call to palAllocateMemory failed for eWNI_SME_*_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        return;
    }
  
<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
    sirStoreU16N((tANI_U8*)&pSirSmeRsp->messageType, msgType);
    sirStoreU16N((tANI_U8*)&pSirSmeRsp->length, sizeof(tSirSmeRsp));
#else
    pSirSmeRsp->messageType = msgType;
    pSirSmeRsp->length      = sizeof(tSirSmeRsp);
#endif
=======
    pSirSmeRsp->messageType = msgType;
    pSirSmeRsp->length      = sizeof(tSirSmeRsp);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    pSirSmeRsp->statusCode  = resultCode;

    /* Update SME session Id and Transaction Id */
    pSirSmeRsp->sessionId = smesessionId;
    pSirSmeRsp->transactionId = smetransactionId;


    mmhMsg.type = msgType;
    mmhMsg.bodyptr = pSirSmeRsp;
    mmhMsg.bodyval = 0;
<<<<<<< HEAD
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
=======
    MTRACE(macTraceMsgTx(pMac, smesessionId , mmhMsg.type));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
   {
    tpPESession psessionEntry = peGetValidPowerSaveSession(pMac);
    switch(msgType)
    {
        case eWNI_PMC_ENTER_BMPS_RSP:
            limDiagEventReport(pMac, WLAN_PE_DIAG_ENTER_BMPS_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
            break;
        case eWNI_PMC_EXIT_BMPS_RSP:
            limDiagEventReport(pMac, WLAN_PE_DIAG_EXIT_BMPS_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
            break;
        case eWNI_PMC_ENTER_IMPS_RSP:
            limDiagEventReport(pMac, WLAN_PE_DIAG_ENTER_IMPS_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
            break;        
        case eWNI_PMC_EXIT_IMPS_RSP:
            limDiagEventReport(pMac, WLAN_PE_DIAG_EXIT_IMPS_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
            break;
        case eWNI_PMC_ENTER_UAPSD_RSP:
            limDiagEventReport(pMac, WLAN_PE_DIAG_ENTER_UAPSD_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
            break;
        case eWNI_PMC_EXIT_UAPSD_RSP:
            limDiagEventReport(pMac, WLAN_PE_DIAG_EXIT_UAPSD_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
            break;
        case eWNI_SME_SWITCH_CHL_RSP:
            limDiagEventReport(pMac, WLAN_PE_DIAG_SWITCH_CHL_RSP_EVENT, NULL, (tANI_U16)resultCode, 0);
            break;
        case eWNI_SME_STOP_BSS_RSP:
            limDiagEventReport(pMac, WLAN_PE_DIAG_STOP_BSS_RSP_EVENT, NULL, (tANI_U16)resultCode, 0);
            break;      
        case eWNI_PMC_ENTER_WOWL_RSP:
            limDiagEventReport(pMac, WLAN_PE_DIAG_ENTER_WOWL_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
            break;
        case eWNI_PMC_EXIT_WOWL_RSP:
            limDiagEventReport(pMac, WLAN_PE_DIAG_EXIT_WOWL_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
            break;          
    } 
   }  
#endif //FEATURE_WLAN_DIAG_SUPPORT
    
    limSysProcessMmhMsgApi(pMac, &mmhMsg,  ePROT);
} /*** end limSendSmeRsp() ***/


/**
 * limSendSmeJoinReassocRspAfterResume()
 *
 *FUNCTION:
 * This function is called to send Join/Reassoc rsp
 * message to SME after the resume link.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac         Pointer to Global MAC structure
 * @param status       Resume link status 
 * @param ctx          context passed while calling resmune link.
 *                     (join response to be sent)
 *
 * @return None
 */
static void limSendSmeJoinReassocRspAfterResume( tpAniSirGlobal pMac, 
                                       eHalStatus status, tANI_U32 *ctx)
{
    tSirMsgQ         mmhMsg;
    tpSirSmeJoinRsp  pSirSmeJoinRsp = (tpSirSmeJoinRsp) ctx;

    mmhMsg.type = pSirSmeJoinRsp->messageType;
    mmhMsg.bodyptr = pSirSmeJoinRsp;
    mmhMsg.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    limSysProcessMmhMsgApi(pMac, &mmhMsg,  ePROT);
}


/**
 * limSendSmeJoinReassocRsp()
 *
 *FUNCTION:
 * This function is called by limProcessSmeReqMessages() to send
 * eWNI_SME_JOIN_RSP or eWNI_SME_REASSOC_RSP messages to applications
 * above MAC Software.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac         Pointer to Global MAC structure
 * @param msgType      Indicates message type
 * @param resultCode   Indicates the result of previously issued
 *                     eWNI_SME_msgType_REQ message
 *
 * @return None
 */

void
limSendSmeJoinReassocRsp(tpAniSirGlobal pMac, tANI_U16 msgType,
                         tSirResultCodes resultCode, tANI_U16 protStatusCode,
                         tpPESession psessionEntry,tANI_U8 smesessionId,tANI_U16 smetransactionId)
{
    tpSirSmeJoinRsp  pSirSmeJoinRsp;
    tANI_U32 rspLen;
    tpDphHashNode pStaDs    = NULL;

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    if (msgType == eWNI_SME_REASSOC_RSP)
        limDiagEventReport(pMac, WLAN_PE_DIAG_REASSOC_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
    else
        limDiagEventReport(pMac, WLAN_PE_DIAG_JOIN_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
           FL("Sending message %s with reasonCode %s\n"),
=======
           FL("Sending message %s with reasonCode %s"),
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           limMsgStr(msgType), limResultCodeStr(resultCode));)

    if(psessionEntry == NULL)
    {

        rspLen = sizeof(tSirSmeJoinRsp);   

        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeJoinRsp, rspLen))
        {
            /// Buffer not available. Log error
<<<<<<< HEAD
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for JOIN/REASSOC_RSP\n"));
=======
            limLog(pMac, LOGP, FL("call to palAllocateMemory failed for JOIN/REASSOC_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            return;
        }
         
        palZeroMemory(pMac, (tANI_U8*)pSirSmeJoinRsp, rspLen);
         
         
        pSirSmeJoinRsp->beaconLength = 0;
        pSirSmeJoinRsp->assocReqLength = 0;
        pSirSmeJoinRsp->assocRspLength = 0;
    }

    else
    {
        rspLen = psessionEntry->assocReqLen + psessionEntry->assocRspLen + 
            psessionEntry->bcnLen + 
#ifdef WLAN_FEATURE_VOWIFI_11R
            psessionEntry->RICDataLen +
#endif
#ifdef FEATURE_WLAN_CCX            
            psessionEntry->tspecLen + 
#endif            
            sizeof(tSirSmeJoinRsp) - sizeof(tANI_U8) ;
    
        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeJoinRsp, rspLen))
        {
            /// Buffer not available. Log error
            limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("call to palAllocateMemory failed for JOIN/REASSOC_RSP\n"));
=======
               FL("call to palAllocateMemory failed for JOIN/REASSOC_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

            return;
        }

        palZeroMemory(pMac, (tANI_U8*)pSirSmeJoinRsp, rspLen);

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
        sirStoreU16N((tANI_U8*)&pSirSmeJoinRsp->messageType, msgType);
        sirStoreU16N((tANI_U8*)&pSirSmeJoinRsp->length, rspLen);
#endif    
        
#if (WNI_POLARIS_FW_PRODUCT == WLAN_STA)
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        if (resultCode == eSIR_SME_SUCCESS)
        {
            pStaDs = dphGetHashEntry(pMac, DPH_STA_HASH_INDEX_PEER, &psessionEntry->dph.dphHashTable);
            if (pStaDs == NULL)
            {
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not Get Self Entry for the station\n"));)
            }
            else
            {
                    //Pass the peer's staId
                pSirSmeJoinRsp->staId = pStaDs->staIndex;
            pSirSmeJoinRsp->ucastSig   = pStaDs->ucUcastSig;
            pSirSmeJoinRsp->bcastSig   = pStaDs->ucBcastSig;
            }
        }
#endif

#if (WNI_POLARIS_FW_PACKAGE == ADVANCED)
        if (resultCode == eSIR_SME_TRANSFER_STA)
        {
            palCopyMemory( pMac->hHdd, pSirSmeJoinRsp->alternateBssId,
                      pMac->lim.gLimAlternateRadio.bssId,
                      sizeof(tSirMacAddr));
            pSirSmeJoinRsp->alternateChannelId =
                               pMac->lim.gLimAlternateRadio.channelId;
        }
#endif
=======
                PELOGE(limLog(pMac, LOGE, FL("could not Get Self Entry for the station"));)
            }
            else
            {
                //Pass the peer's staId
                pSirSmeJoinRsp->staId = pStaDs->staIndex;
                pSirSmeJoinRsp->ucastSig   = pStaDs->ucUcastSig;
                pSirSmeJoinRsp->bcastSig   = pStaDs->ucBcastSig;
            }
        }
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        pSirSmeJoinRsp->beaconLength = 0;
        pSirSmeJoinRsp->assocReqLength = 0;
        pSirSmeJoinRsp->assocRspLength = 0;
#ifdef WLAN_FEATURE_VOWIFI_11R
        pSirSmeJoinRsp->parsedRicRspLen = 0;
#endif
#ifdef FEATURE_WLAN_CCX            
        pSirSmeJoinRsp->tspecIeLen = 0;
#endif
        
        if(resultCode == eSIR_SME_SUCCESS)
        {

            if(psessionEntry->beacon != NULL)
            {
                pSirSmeJoinRsp->beaconLength = psessionEntry->bcnLen;
                palCopyMemory(pMac->hHdd, pSirSmeJoinRsp->frames, psessionEntry->beacon, pSirSmeJoinRsp->beaconLength);
                palFreeMemory(pMac->hHdd, psessionEntry->beacon);
                psessionEntry->beacon = NULL;
#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
<<<<<<< HEAD
                PELOG1(limLog(pMac, LOG1, FL("Beacon=%d\n"), psessionEntry->bcnLen);)
=======
                PELOG1(limLog(pMac, LOG1, FL("Beacon=%d"), psessionEntry->bcnLen);)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#endif
            }
        
            if(psessionEntry->assocReq != NULL)
            {
                pSirSmeJoinRsp->assocReqLength = psessionEntry->assocReqLen;
                palCopyMemory(pMac->hHdd, pSirSmeJoinRsp->frames + psessionEntry->bcnLen, psessionEntry->assocReq, pSirSmeJoinRsp->assocReqLength);
                palFreeMemory(pMac->hHdd, psessionEntry->assocReq);
                psessionEntry->assocReq = NULL;
#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
<<<<<<< HEAD
                PELOG1(limLog(pMac, LOG1, FL("AssocReq=%d\n"), psessionEntry->assocReqLen);)
=======
                PELOG1(limLog(pMac, LOG1, FL("AssocReq=%d"), psessionEntry->assocReqLen);)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#endif
            }
            if(psessionEntry->assocRsp != NULL)
            {
                pSirSmeJoinRsp->assocRspLength = psessionEntry->assocRspLen;
                palCopyMemory(pMac->hHdd, pSirSmeJoinRsp->frames + psessionEntry->bcnLen + psessionEntry->assocReqLen, psessionEntry->assocRsp, pSirSmeJoinRsp->assocRspLength);
                palFreeMemory(pMac->hHdd, psessionEntry->assocRsp);
                psessionEntry->assocRsp = NULL;
            }           
#ifdef WLAN_FEATURE_VOWIFI_11R
            if(psessionEntry->ricData != NULL)
            {
                pSirSmeJoinRsp->parsedRicRspLen = psessionEntry->RICDataLen;
                palCopyMemory(pMac->hHdd, pSirSmeJoinRsp->frames + psessionEntry->bcnLen + psessionEntry->assocReqLen + psessionEntry->assocRspLen, psessionEntry->ricData, pSirSmeJoinRsp->parsedRicRspLen);
                palFreeMemory(pMac->hHdd, psessionEntry->ricData);
                psessionEntry->ricData = NULL;
<<<<<<< HEAD
                PELOG1(limLog(pMac, LOG1, FL("RicLength=%d\n"), pSirSmeJoinRsp->parsedRicRspLen);)
=======
                PELOG1(limLog(pMac, LOG1, FL("RicLength=%d"), pSirSmeJoinRsp->parsedRicRspLen);)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            }
#endif
#ifdef FEATURE_WLAN_CCX            
            if(psessionEntry->tspecIes != NULL)
            {
                pSirSmeJoinRsp->tspecIeLen = psessionEntry->tspecLen;
                palCopyMemory(pMac->hHdd, pSirSmeJoinRsp->frames + psessionEntry->bcnLen + psessionEntry->assocReqLen + psessionEntry->assocRspLen + psessionEntry->RICDataLen, psessionEntry->tspecIes, pSirSmeJoinRsp->tspecIeLen);
                palFreeMemory(pMac->hHdd, psessionEntry->tspecIes);
                psessionEntry->tspecIes = NULL;
<<<<<<< HEAD
                PELOG1(limLog(pMac, LOG1, FL("CCX-TspecLen=%d\n"), psessionEntry->tspecLen);)
=======
                PELOG1(limLog(pMac, LOG1, FL("CCX-TspecLen=%d"), psessionEntry->tspecLen);)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            }
#endif            
            pSirSmeJoinRsp->aid = psessionEntry->limAID;
#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
<<<<<<< HEAD
            PELOG1(limLog(pMac, LOG1, FL("AssocRsp=%d\n"), psessionEntry->assocRspLen);)
#endif
        }
=======
            PELOG1(limLog(pMac, LOG1, FL("AssocRsp=%d"), psessionEntry->assocRspLen);)
#endif
        }
        else
        {

            if(psessionEntry->beacon != NULL)
            {
                palFreeMemory(pMac->hHdd, psessionEntry->beacon);
                psessionEntry->beacon = NULL;
            }

            if(psessionEntry->assocReq != NULL)
            {
                palFreeMemory(pMac->hHdd, psessionEntry->assocReq);
                psessionEntry->assocReq = NULL;
            }

            if(psessionEntry->assocRsp != NULL)
            {
                palFreeMemory(pMac->hHdd, psessionEntry->assocRsp);
                psessionEntry->assocRsp = NULL;
            }

        }
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }


    pSirSmeJoinRsp->messageType = msgType;
    pSirSmeJoinRsp->length = (tANI_U16) rspLen;
    pSirSmeJoinRsp->statusCode = resultCode;
    pSirSmeJoinRsp->protStatusCode = protStatusCode;
    
    /* Update SME session ID and transaction Id */
    pSirSmeJoinRsp->sessionId = smesessionId;
    pSirSmeJoinRsp->transactionId = smetransactionId;
    
    if(IS_MCC_SUPPORTED && limIsLinkSuspended( pMac ) )
    {
        if( psessionEntry && psessionEntry->limSmeState == eLIM_SME_LINK_EST_STATE )
        {
            
#ifdef WLAN_FEATURE_11AC
            if (psessionEntry->vhtCapability)
            {
                ePhyChanBondState htSecondaryChannelOffset;
               /*Get 11ac cbState from 11n cbState*/
                 htSecondaryChannelOffset = limGet11ACPhyCBState(pMac, 
                                    psessionEntry->currentOperChannel,
<<<<<<< HEAD
                                    psessionEntry->htSecondaryChannelOffset);
=======
                                    psessionEntry->htSecondaryChannelOffset,
                                    psessionEntry->apCenterChan,
                                    psessionEntry);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                peSetResumeChannel( pMac, psessionEntry->currentOperChannel, htSecondaryChannelOffset);
            }
            else 
#endif
               peSetResumeChannel( pMac, psessionEntry->currentOperChannel, psessionEntry->htSecondaryChannelOffset);
        }
        else
        {
            peSetResumeChannel( pMac, 0, 0);
        }
        limResumeLink( pMac, limSendSmeJoinReassocRspAfterResume, 
                                              (tANI_U32*) pSirSmeJoinRsp );
    }
    else
    {
        limSendSmeJoinReassocRspAfterResume( pMac, eHAL_STATUS_SUCCESS,
                                              (tANI_U32*) pSirSmeJoinRsp );
    }
} /*** end limSendSmeJoinReassocRsp() ***/



/**
 * limSendSmeStartBssRsp()
 *
 *FUNCTION:
 * This function is called to send eWNI_SME_START_BSS_RSP
 * message to applications above MAC Software.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac         Pointer to Global MAC structure
 * @param msgType      Indicates message type
 * @param resultCode   Indicates the result of previously issued
 *                     eWNI_SME_msgType_REQ message
 *
 * @return None
 */

void
limSendSmeStartBssRsp(tpAniSirGlobal pMac,
                      tANI_U16 msgType, tSirResultCodes resultCode,tpPESession psessionEntry,
                      tANI_U8 smesessionId,tANI_U16 smetransactionId)
{


    tANI_U16            size = 0;
    tSirMsgQ            mmhMsg;
    tSirSmeStartBssRsp  *pSirSmeRsp;
    tANI_U16            ieLen;
    tANI_U16            ieOffset, curLen;

<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("Sending message %s with reasonCode %s\n"),
=======
    PELOG1(limLog(pMac, LOG1, FL("Sending message %s with reasonCode %s"),
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           limMsgStr(msgType), limResultCodeStr(resultCode));)

    size = sizeof(tSirSmeStartBssRsp);

    if(psessionEntry == NULL)
    {
       
         if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeRsp, size))
         {
            /// Buffer not available. Log error
<<<<<<< HEAD
            limLog(pMac, LOGP,FL("call to palAllocateMemory failed for eWNI_SME_START_BSS_RSP\n"));
=======
            limLog(pMac, LOGP,FL("call to palAllocateMemory failed for eWNI_SME_START_BSS_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            return;
         }
         palZeroMemory(pMac, (tANI_U8*)pSirSmeRsp, size);
                      
    }
    else
    {
        //subtract size of beaconLength + Mac Hdr + Fixed Fields before SSID
        ieOffset = sizeof(tAniBeaconStruct) + SIR_MAC_B_PR_SSID_OFFSET;
        ieLen = pMac->sch.schObject.gSchBeaconOffsetBegin + pMac->sch.schObject.gSchBeaconOffsetEnd - ieOffset;
        //calculate the memory size to allocate
        size += ieLen;

        if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeRsp, size))
        {
            /// Buffer not available. Log error
            limLog(pMac, LOGP,
<<<<<<< HEAD
            FL("call to palAllocateMemory failed for eWNI_SME_START_BSS_RSP\n"));
=======
            FL("call to palAllocateMemory failed for eWNI_SME_START_BSS_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

            return;
        }
        palZeroMemory(pMac, (tANI_U8*)pSirSmeRsp, size);
        size = sizeof(tSirSmeStartBssRsp);
        if (resultCode == eSIR_SME_SUCCESS)
        {

                sirCopyMacAddr(pSirSmeRsp->bssDescription.bssId, psessionEntry->bssId);
        
                /* Read beacon interval from session */
                pSirSmeRsp->bssDescription.beaconInterval = (tANI_U16) psessionEntry->beaconParams.beaconInterval;
                pSirSmeRsp->bssType         = psessionEntry->bssType;

                if (cfgGetCapabilityInfo( pMac, &pSirSmeRsp->bssDescription.capabilityInfo,psessionEntry)
                != eSIR_SUCCESS)
<<<<<<< HEAD
                limLog(pMac, LOGP, FL("could not retrieve Capabilities value\n"));
=======
                limLog(pMac, LOGP, FL("could not retrieve Capabilities value"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

                limGetPhyMode(pMac, (tANI_U32 *)&pSirSmeRsp->bssDescription.nwType, psessionEntry);

#if 0
            if (wlan_cfgGetInt(pMac, WNI_CFG_CURRENT_CHANNEL, &len) != eSIR_SUCCESS)
<<<<<<< HEAD
                limLog(pMac, LOGP, FL("could not retrieve CURRENT_CHANNEL from CFG\n"));
=======
                limLog(pMac, LOGP, FL("could not retrieve CURRENT_CHANNEL from CFG"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           
#endif// TO SUPPORT BT-AMP 
            
                pSirSmeRsp->bssDescription.channelId = psessionEntry->currentOperChannel;

                pSirSmeRsp->bssDescription.aniIndicator = 1;

                curLen = pMac->sch.schObject.gSchBeaconOffsetBegin - ieOffset;
                palCopyMemory( pMac->hHdd, (tANI_U8 *) &pSirSmeRsp->bssDescription.ieFields,
                           pMac->sch.schObject.gSchBeaconFrameBegin + ieOffset,
                          (tANI_U32)curLen);

                palCopyMemory( pMac->hHdd, ((tANI_U8 *) &pSirSmeRsp->bssDescription.ieFields) + curLen,
                           pMac->sch.schObject.gSchBeaconFrameEnd,
                          (tANI_U32)pMac->sch.schObject.gSchBeaconOffsetEnd);


                //subtracting size of length indicator itself and size of pointer to ieFields
                pSirSmeRsp->bssDescription.length = sizeof(tSirBssDescription) -
                                                sizeof(tANI_U16) - sizeof(tANI_U32) +
                                                ieLen;
                //This is the size of the message, subtracting the size of the pointer to ieFields
                size += ieLen - sizeof(tANI_U32);
        }

            

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
        sirStoreU16N((tANI_U8*)&pSirSmeRsp->messageType, msgType);
        sirStoreU16N((tANI_U8*)&pSirSmeRsp->length, size);
       
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        
    }

    pSirSmeRsp->messageType     = msgType;
    pSirSmeRsp->length          = size;

    /* Update SME session Id and transaction Id */
    pSirSmeRsp->sessionId       = smesessionId;
    pSirSmeRsp->transactionId   = smetransactionId;
    pSirSmeRsp->statusCode      = resultCode;
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
    if(psessionEntry != NULL )
    pSirSmeRsp->staId           = psessionEntry->staId; //else it will be always zero smeRsp StaID = 0 
      
#endif
=======
    if(psessionEntry != NULL )
    pSirSmeRsp->staId           = psessionEntry->staId; //else it will be always zero smeRsp StaID = 0 
      
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    mmhMsg.type = msgType;
    mmhMsg.bodyptr = pSirSmeRsp;
    mmhMsg.bodyval = 0;
<<<<<<< HEAD
    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));

=======
    if(psessionEntry == NULL)
    {
        MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    }
    else
    {
        MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
    }
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_START_BSS_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    limSysProcessMmhMsgApi(pMac, &mmhMsg,  ePROT);
} /*** end limSendSmeStartBssRsp() ***/





#define LIM_MAX_NUM_OF_SCAN_RESULTS_REPORTED  20
#define LIM_SIZE_OF_EACH_BSS  400 // this is a rough estimate


/**
 * limSendSmeScanRsp()
 *
 *FUNCTION:
 * This function is called by limProcessSmeReqMessages() to send
 * eWNI_SME_SCAN_RSP message to applications above MAC
 * Software.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac         Pointer to Global MAC structure
 * @param length       Indicates length of message
 * @param resultCode   Indicates the result of previously issued
 *                     eWNI_SME_SCAN_REQ message
 *
 * @return None
 */

void
limSendSmeScanRsp(tpAniSirGlobal pMac, tANI_U16 length,
                  tSirResultCodes resultCode,tANI_U8  smesessionId,tANI_U16 smetranscationId)
{
    tSirMsgQ              mmhMsg;
    tpSirSmeScanRsp       pSirSmeScanRsp=NULL;
    tLimScanResultNode    *ptemp = NULL;
    tANI_U16              msgLen, allocLength, curMsgLen = 0;
    tANI_U16              i, bssCount;
    tANI_U8               *pbBuf;
    tSirBssDescription    *pDesc;

    PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
       FL("Sending message SME_SCAN_RSP with length=%d reasonCode %s\n"),
=======
       FL("Sending message SME_SCAN_RSP with length=%d reasonCode %s"),
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       length, limResultCodeStr(resultCode));)

    if (resultCode != eSIR_SME_SUCCESS)
    {
        limPostSmeScanRspMessage(pMac, length, resultCode,smesessionId,smetranscationId);
        return;
    }

    mmhMsg.type = eWNI_SME_SCAN_RSP;
    i = 0;
    bssCount = 0;
    msgLen = 0;
    allocLength = LIM_MAX_NUM_OF_SCAN_RESULTS_REPORTED * LIM_SIZE_OF_EACH_BSS;
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeScanRsp, allocLength))
    {
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
                   FL("call to palAllocateMemory failed for eWNI_SME_SCAN_RSP\n"));
=======
                   FL("call to palAllocateMemory failed for eWNI_SME_SCAN_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        return;
    }
    for (i = 0; i < LIM_MAX_NUM_OF_SCAN_RESULTS; i++)
    {
        //when ptemp is not NULL it is a left over
        ptemp = pMac->lim.gLimCachedScanHashTable[i];
        while(ptemp)
        {
            pbBuf = ((tANI_U8 *)pSirSmeScanRsp) + msgLen;
            if(0 == bssCount)
            {
                msgLen = sizeof(tSirSmeScanRsp) -
                           sizeof(tSirBssDescription) +
                           ptemp->bssDescription.length +
                           sizeof(ptemp->bssDescription.length);
                pDesc = pSirSmeScanRsp->bssDescription;
            }
            else
            {
                msgLen += ptemp->bssDescription.length +
                          sizeof(ptemp->bssDescription.length);
                pDesc = (tSirBssDescription *)pbBuf;
            }
            if( (allocLength < msgLen) ||
                 (LIM_MAX_NUM_OF_SCAN_RESULTS_REPORTED <= bssCount++) )
            {
                pSirSmeScanRsp->statusCode  =
                    eSIR_SME_MORE_SCAN_RESULTS_FOLLOW;
<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
                sirStoreU16N((tANI_U8*)&pSirSmeScanRsp->messageType,
                             eWNI_SME_SCAN_RSP);
                sirStoreU16N((tANI_U8*)&pSirSmeScanRsp->length, curMsgLen);
#else
                pSirSmeScanRsp->messageType = eWNI_SME_SCAN_RSP;
                pSirSmeScanRsp->length      = curMsgLen;
#endif
=======
                pSirSmeScanRsp->messageType = eWNI_SME_SCAN_RSP;
                pSirSmeScanRsp->length      = curMsgLen;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                mmhMsg.bodyptr = pSirSmeScanRsp;
                mmhMsg.bodyval = 0;
                MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
                limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
                if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeScanRsp, allocLength))
                {
                    // Log error
                    limLog(pMac, LOGP,
<<<<<<< HEAD
                                 FL("call to palAllocateMemory failed for eWNI_SME_SCAN_RSP\n"));
=======
                                 FL("call to palAllocateMemory failed for eWNI_SME_SCAN_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                    return;
                }
                msgLen = sizeof(tSirSmeScanRsp) -
                           sizeof(tSirBssDescription) +
                           ptemp->bssDescription.length +
                           sizeof(ptemp->bssDescription.length);
                pDesc = pSirSmeScanRsp->bssDescription;
                bssCount = 1;
            }
            curMsgLen = msgLen;

<<<<<<< HEAD
            PELOG2(limLog(pMac, LOG2, FL("ScanRsp : msgLen %d, bssDescr Len=%d\n"),
                          msgLen, ptemp->bssDescription.length);)
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
            sirStoreU16N((tANI_U8*)&pDesc->length,
                         ptemp->bssDescription.length);
#else
            pDesc->length
                    = ptemp->bssDescription.length;
#endif
=======
            PELOG2(limLog(pMac, LOG2, FL("ScanRsp : msgLen %d, bssDescr Len=%d"),
                          msgLen, ptemp->bssDescription.length);)
            pDesc->length
                    = ptemp->bssDescription.length;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            palCopyMemory( pMac->hHdd, (tANI_U8 *) &pDesc->bssId,
                              (tANI_U8 *) &ptemp->bssDescription.bssId,
                              ptemp->bssDescription.length);

            PELOG2(limLog(pMac, LOG2, FL("BssId "));
            limPrintMacAddr(pMac, ptemp->bssDescription.bssId, LOG2);)

            pSirSmeScanRsp->sessionId   = smesessionId;
            pSirSmeScanRsp->transcationId = smetranscationId;

            ptemp = ptemp->next;
        } //while(ptemp)
    } //for (i = 0; i < LIM_MAX_NUM_OF_SCAN_RESULTS; i++)

    if(0 == bssCount)
    {
       limPostSmeScanRspMessage(pMac, length, resultCode, smesessionId, smetranscationId);
       if (NULL != pSirSmeScanRsp)
       {
           palFreeMemory( pMac->hHdd, pSirSmeScanRsp);
           pSirSmeScanRsp = NULL;
       }
    }
    else
    {
        // send last message
        pSirSmeScanRsp->statusCode  = eSIR_SME_SUCCESS;
<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
        sirStoreU16N((tANI_U8*)&pSirSmeScanRsp->messageType,
                             eWNI_SME_SCAN_RSP);
        sirStoreU16N((tANI_U8*)&pSirSmeScanRsp->length, curMsgLen);
#else
        pSirSmeScanRsp->messageType = eWNI_SME_SCAN_RSP;
        pSirSmeScanRsp->length = curMsgLen;
#endif
=======
        pSirSmeScanRsp->messageType = eWNI_SME_SCAN_RSP;
        pSirSmeScanRsp->length = curMsgLen;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        /* Update SME session Id and SME transcation Id */
        pSirSmeScanRsp->sessionId   = smesessionId;
        pSirSmeScanRsp->transcationId = smetranscationId;

        mmhMsg.type = eWNI_SME_SCAN_RSP;
        mmhMsg.bodyptr = pSirSmeScanRsp;
        mmhMsg.bodyval = 0;
        MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
        limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
<<<<<<< HEAD
        PELOG2(limLog(pMac, LOG2, FL("statusCode : eSIR_SME_SUCCESS\n"));)
=======
        PELOG2(limLog(pMac, LOG2, FL("statusCode : eSIR_SME_SUCCESS"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }

    return;

} /*** end limSendSmeScanRsp() ***/

<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
/**
 * limSendSmeLfrScanRsp()
 *
 *FUNCTION:
 * This function is called by limProcessSmeReqMessages() to send
 * eWNI_SME_SCAN_RSP message to applications above MAC Software
 * only for sending up the roam candidates.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac         Pointer to Global MAC structure
 * @param length       Indicates length of message
 * @param resultCode   Indicates the result of previously issued
 *                     eWNI_SME_SCAN_REQ message
 *
 * @return None
 */

void
limSendSmeLfrScanRsp(tpAniSirGlobal pMac, tANI_U16 length,
                     tSirResultCodes resultCode,tANI_U8  smesessionId,tANI_U16 smetranscationId)
{
    tSirMsgQ              mmhMsg;
    tpSirSmeScanRsp       pSirSmeScanRsp=NULL;
    tLimScanResultNode    *ptemp = NULL;
    tANI_U16              msgLen, allocLength, curMsgLen = 0;
    tANI_U16              i, bssCount;
    tANI_U8               *pbBuf;
    tSirBssDescription    *pDesc;

    PELOG1(limLog(pMac, LOG1,
       FL("Sending message SME_SCAN_RSP with length=%d reasonCode %s\n"),
       length, limResultCodeStr(resultCode));)

    if (resultCode != eSIR_SME_SUCCESS)
    {
        limPostSmeScanRspMessage(pMac, length, resultCode,smesessionId,smetranscationId);
        return;
    }

    mmhMsg.type = eWNI_SME_SCAN_RSP;
    i = 0;
    bssCount = 0;
    msgLen = 0;
    allocLength = LIM_MAX_NUM_OF_SCAN_RESULTS_REPORTED * LIM_SIZE_OF_EACH_BSS;
    if ( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd,
                                (void **)&pSirSmeScanRsp, allocLength))
    {
        // Log error
        limLog(pMac, LOGP,
                   FL("call to palAllocateMemory failed for eWNI_SME_SCAN_RSP\n"));

        return;
    }
    for (i = 0; i < LIM_MAX_NUM_OF_SCAN_RESULTS; i++)
    {
        //when ptemp is not NULL it is a left over
        ptemp = pMac->lim.gLimCachedLfrScanHashTable[i];
        while(ptemp)
        {
            pbBuf = ((tANI_U8 *)pSirSmeScanRsp) + msgLen;
            if(0 == bssCount)
            {
                msgLen = sizeof(tSirSmeScanRsp) -
                           sizeof(tSirBssDescription) +
                           ptemp->bssDescription.length +
                           sizeof(ptemp->bssDescription.length);
                pDesc = pSirSmeScanRsp->bssDescription;
            }
            else
            {
                msgLen += ptemp->bssDescription.length +
                          sizeof(ptemp->bssDescription.length);
                pDesc = (tSirBssDescription *)pbBuf;
            }
            if ( (allocLength < msgLen) ||
                 (LIM_MAX_NUM_OF_SCAN_RESULTS_REPORTED <= bssCount++) )
            {
                pSirSmeScanRsp->statusCode  =
                    eSIR_SME_MORE_SCAN_RESULTS_FOLLOW;
                pSirSmeScanRsp->messageType = eWNI_SME_SCAN_RSP;
                pSirSmeScanRsp->length      = curMsgLen;
                mmhMsg.bodyptr = pSirSmeScanRsp;
                mmhMsg.bodyval = 0;
                MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
                limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
                if (eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd,
                                                   (void **)&pSirSmeScanRsp,
                                                   allocLength))
                {
                    // Log error
                    limLog(pMac, LOGP,
                                 FL("call to palAllocateMemory failed for eWNI_SME_SCAN_RSP\n"));
                    return;
                }
                msgLen = sizeof(tSirSmeScanRsp) -
                           sizeof(tSirBssDescription) +
                           ptemp->bssDescription.length +
                           sizeof(ptemp->bssDescription.length);
                pDesc = pSirSmeScanRsp->bssDescription;
                bssCount = 1;
            }
            curMsgLen = msgLen;

            PELOG2(limLog(pMac, LOG2, FL("ScanRsp : msgLen %d, bssDescr Len=%d\n"),
                          msgLen, ptemp->bssDescription.length);)
            pDesc->length
                    = ptemp->bssDescription.length;
            palCopyMemory( pMac->hHdd, (tANI_U8 *) &pDesc->bssId,
                              (tANI_U8 *) &ptemp->bssDescription.bssId,
                              ptemp->bssDescription.length);

            PELOG2(limLog(pMac, LOG2, FL("BssId "));
            limPrintMacAddr(pMac, ptemp->bssDescription.bssId, LOG2);)

            pSirSmeScanRsp->sessionId   = smesessionId;
            pSirSmeScanRsp->transcationId = smetranscationId;

            ptemp = ptemp->next;
        } //while(ptemp)
    } //for (i = 0; i < LIM_MAX_NUM_OF_SCAN_RESULTS; i++)

    if (0 == bssCount)
    {
       limPostSmeScanRspMessage(pMac, length, resultCode, smesessionId, smetranscationId);
       if (NULL != pSirSmeScanRsp)
       {
           palFreeMemory( pMac->hHdd, pSirSmeScanRsp);
           pSirSmeScanRsp = NULL;
       }
    }
    else
    {
        // send last message
        pSirSmeScanRsp->statusCode  = eSIR_SME_SUCCESS;
        pSirSmeScanRsp->messageType = eWNI_SME_SCAN_RSP;
        pSirSmeScanRsp->length = curMsgLen;

        /* Update SME session Id and SME transcation Id */
        pSirSmeScanRsp->sessionId   = smesessionId;
        pSirSmeScanRsp->transcationId = smetranscationId;

        mmhMsg.type = eWNI_SME_SCAN_RSP;
        mmhMsg.bodyptr = pSirSmeScanRsp;
        mmhMsg.bodyval = 0;
        MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
        limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
        PELOG2(limLog(pMac, LOG2, FL("statusCode : eSIR_SME_SUCCESS\n"));)
    }

    return;

} /*** end limSendSmeLfrScanRsp() ***/
#endif //WLAN_FEATURE_ROAM_SCAN_OFFLOAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

/**
 * limPostSmeScanRspMessage()
 *
 *FUNCTION:
 * This function is called by limSendSmeScanRsp() to send
 * eWNI_SME_SCAN_RSP message with failed result code
 *
 *NOTE:
 * NA
 *
 * @param pMac         Pointer to Global MAC structure
 * @param length       Indicates length of message
 * @param resultCode   failed result code
 *
 * @return None
 */

void
limPostSmeScanRspMessage(tpAniSirGlobal    pMac,     
                      tANI_U16               length,
                      tSirResultCodes   resultCode,tANI_U8 smesessionId, tANI_U16 smetransactionId)
{
    tpSirSmeScanRsp   pSirSmeScanRsp;
    tSirMsgQ          mmhMsg;

    PELOG1(limLog(pMac, LOG1,
<<<<<<< HEAD
       FL("limPostSmeScanRspMessage: send SME_SCAN_RSP (len %d, reasonCode %s). \n"),
=======
       FL("limPostSmeScanRspMessage: send SME_SCAN_RSP (len %d, reasonCode %s). "),
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       length, limResultCodeStr(resultCode));)

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeScanRsp, length))
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("palAllocateMemory failed for eWNI_SME_SCAN_RSP\n"));
=======
        limLog(pMac, LOGP, FL("palAllocateMemory failed for eWNI_SME_SCAN_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return;
    }
    palZeroMemory(pMac->hHdd, (void*)pSirSmeScanRsp, length);

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
    sirStoreU16N((tANI_U8*)&pSirSmeScanRsp->messageType, eWNI_SME_SCAN_RSP);
    sirStoreU16N((tANI_U8*)&pSirSmeScanRsp->length, length);
#else
    pSirSmeScanRsp->messageType = eWNI_SME_SCAN_RSP;
    pSirSmeScanRsp->length      = length;
#endif
=======
    pSirSmeScanRsp->messageType = eWNI_SME_SCAN_RSP;
    pSirSmeScanRsp->length      = length;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    if(sizeof(tSirSmeScanRsp) <= length)
    {
        pSirSmeScanRsp->bssDescription->length = sizeof(tSirBssDescription);
    }

    pSirSmeScanRsp->statusCode  = resultCode;

    /*Update SME session Id and transaction Id */
    pSirSmeScanRsp->sessionId = smesessionId;
    pSirSmeScanRsp->transcationId = smetransactionId;
    
    mmhMsg.type = eWNI_SME_SCAN_RSP;
    mmhMsg.bodyptr = pSirSmeScanRsp;
    mmhMsg.bodyval = 0;

    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_SCAN_RSP_EVENT, NULL, (tANI_U16)resultCode, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
    return;

}  /*** limPostSmeScanRspMessage ***/

#ifdef FEATURE_OEM_DATA_SUPPORT

/**
 * limSendSmeOemDataRsp()
 *
 *FUNCTION:
 * This function is called by limProcessSmeReqMessages() to send
 * eWNI_SME_OEM_DATA_RSP message to applications above MAC
 * Software.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac         Pointer to Global MAC structure
 * @param pMsgBuf      Indicates the mlm message
 * @param resultCode   Indicates the result of previously issued
 *                     eWNI_SME_OEM_DATA_RSP message
 *
 * @return None
 */

void limSendSmeOemDataRsp(tpAniSirGlobal pMac, tANI_U32* pMsgBuf, tSirResultCodes resultCode)
{
    tSirMsgQ                      mmhMsg;
    tSirOemDataRsp*               pSirSmeOemDataRsp=NULL;
    tLimMlmOemDataRsp*            pMlmOemDataRsp=NULL;
    tANI_U16                      msgLength;

    
    //get the pointer to the mlm message
    pMlmOemDataRsp = (tLimMlmOemDataRsp*)(pMsgBuf);

    msgLength = sizeof(tSirOemDataRsp);

    //now allocate memory for the char buffer
    if(eHAL_STATUS_SUCCESS != palAllocateMemory(pMac->hHdd, (void**)&pSirSmeOemDataRsp, msgLength))
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pSirSmeOemDataRsp\n"));
=======
        limLog(pMac, LOGP, FL("call to palAllocateMemory failed for pSirSmeOemDataRsp"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return;
    }

#if defined (ANI_LITTLE_BYTE_ENDIAN)
    sirStoreU16N((tANI_U8*)&pSirSmeOemDataRsp->length, msgLength);
    sirStoreU16N((tANI_U8*)&pSirSmeOemDataRsp->messageType, eWNI_SME_OEM_DATA_RSP);
#else
    pSirSmeOemDataRsp->length = msgLength;
    pSirSmeOemDataRsp->messageType = eWNI_SME_OEM_DATA_RSP;
#endif

    palCopyMemory(pMac->hHdd, pSirSmeOemDataRsp->oemDataRsp, pMlmOemDataRsp->oemDataRsp, OEM_DATA_RSP_SIZE);

    //Now free the memory from MLM Rsp Message
    palFreeMemory(pMac->hHdd, pMlmOemDataRsp);

    mmhMsg.type = eWNI_SME_OEM_DATA_RSP;
    mmhMsg.bodyptr = pSirSmeOemDataRsp;
    mmhMsg.bodyval = 0;

    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);

    return;
}  /*** limSendSmeOemDataRsp ***/

#endif


/**
 * limSendSmeAuthRsp()
 *
 *FUNCTION:
 * This function is called by limProcessSmeMessages() to send
 * eWNI_SME_AUTH_RSP message to host
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param  pMac        Pointer to Global MAC structure
 * @param statusCode   Indicates the result of previously issued
 *                     eWNI_SME_AUTH_REQ message
 *
 * @return None
 */
void
limSendSmeAuthRsp(tpAniSirGlobal pMac,
                  tSirResultCodes statusCode,
                  tSirMacAddr peerMacAddr,
                  tAniAuthType authType,
                  tANI_U16   protStatusCode,
                  tpPESession psessionEntry,tANI_U8 smesessionId,
                  tANI_U16 smetransactionId)
{
#if 0
    tSirMsgQ       mmhMsg;
    tSirSmeAuthRsp *pSirSmeAuthRsp;


    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeAuthRsp, sizeof(tSirSmeAuthRsp)))
    {
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("call to palAllocateMemory failed for eWNI_SME_AUTH_RSP\n"));
=======
               FL("call to palAllocateMemory failed for eWNI_SME_AUTH_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        return;
    }

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
    sirStoreU16N((tANI_U8*)&pSirSmeAuthRsp->messageType, eWNI_SME_AUTH_RSP);
    sirStoreU16N((tANI_U8*)&pSirSmeAuthRsp->length, sizeof(tSirSmeAuthRsp));
 
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   

    if(psessionEntry != NULL)
    {
        palCopyMemory( pMac->hHdd, (tANI_U8 *) pSirSmeAuthRsp->peerMacAddr,
                  (tANI_U8 *) peerMacAddr, sizeof(tSirMacAddr));
        pSirSmeAuthRsp->authType    = authType;
          
    }

    pSirSmeAuthRsp->messageType = eWNI_SME_AUTH_RSP;
    pSirSmeAuthRsp->length      = sizeof(tSirSmeAuthRsp);
    pSirSmeAuthRsp->statusCode  = statusCode;
    pSirSmeAuthRsp->protStatusCode = protStatusCode;
    
    /* Update SME session and transaction Id*/
    pSirSmeAuthRsp->sessionId = smesessionId;
    pSirSmeAuthRsp->transactionId = smetransactionId;  

    mmhMsg.type = eWNI_SME_AUTH_RSP;
    mmhMsg.bodyptr = pSirSmeAuthRsp;
    mmhMsg.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, 0, mmhMsg.type));
    limSysProcessMmhMsgApi(pMac, &mmhMsg,  ePROT);
#endif
} /*** end limSendSmeAuthRsp() ***/


<<<<<<< HEAD
void limSendSmeDisassocDeauthNtfPostResume( tpAniSirGlobal pMac,
=======
void limSendSmeDisassocDeauthNtf( tpAniSirGlobal pMac,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                                eHalStatus status, tANI_U32 *pCtx )
{
    tSirMsgQ                mmhMsg;
    tSirMsgQ                *pMsg = (tSirMsgQ*) pCtx;

    mmhMsg.type = pMsg->type;
    mmhMsg.bodyptr = pMsg;
    mmhMsg.bodyval = 0;

    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));

    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
}
/**
 * limSendSmeDisassocNtf()
 *
 *FUNCTION:
 * This function is called by limProcessSmeMessages() to send
 * eWNI_SME_DISASSOC_RSP/IND message to host
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * This function is used for sending eWNI_SME_DISASSOC_CNF,
 * or eWNI_SME_DISASSOC_IND to host depending on
 * disassociation trigger.
 *
 * @param peerMacAddr       Indicates the peer MAC addr to which
 *                          disassociate was initiated
 * @param reasonCode        Indicates the reason for Disassociation
 * @param disassocTrigger   Indicates the trigger for Disassociation
 * @param aid               Indicates the STAID. This parameter is
 *                          present only on AP.
 *
 * @return None
 */
void
limSendSmeDisassocNtf(tpAniSirGlobal pMac,
                      tSirMacAddr peerMacAddr,
                      tSirResultCodes reasonCode,
                      tANI_U16 disassocTrigger,
                      tANI_U16 aid,
                      tANI_U8 smesessionId,
                      tANI_U16 smetransactionId,
                      tpPESession psessionEntry)
{

    tANI_U8                     *pBuf;
    tSirSmeDisassocRsp      *pSirSmeDisassocRsp;
    tSirSmeDisassocInd      *pSirSmeDisassocInd;
    tANI_U32 *pMsg;
    
    switch (disassocTrigger)
    {
        case eLIM_PEER_ENTITY_DISASSOC:
            return;

        case eLIM_HOST_DISASSOC:
            /**
             * Disassociation response due to
             * host triggered disassociation
             */

            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeDisassocRsp, sizeof(tSirSmeDisassocRsp)))
            {
                // Log error
                limLog(pMac, LOGP,
<<<<<<< HEAD
                   FL("call to palAllocateMemory failed for eWNI_SME_DISASSOC_RSP\n"));
=======
                   FL("call to palAllocateMemory failed for eWNI_SME_DISASSOC_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

                return;
            }

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
            sirStoreU16N((tANI_U8*)&pSirSmeDisassocRsp->messageType,
                         eWNI_SME_DISASSOC_RSP);
            sirStoreU16N((tANI_U8*)&pSirSmeDisassocRsp->length,
                         sizeof(tSirSmeDisassocRsp));
#else
            pSirSmeDisassocRsp->messageType = eWNI_SME_DISASSOC_RSP;
            pSirSmeDisassocRsp->length      = sizeof(tSirSmeDisassocRsp);
#endif
=======
            pSirSmeDisassocRsp->messageType = eWNI_SME_DISASSOC_RSP;
            pSirSmeDisassocRsp->length      = sizeof(tSirSmeDisassocRsp);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            //sessionId
            pBuf = (tANI_U8 *) &pSirSmeDisassocRsp->sessionId;
            *pBuf = smesessionId;
            pBuf++;

            //transactionId
            limCopyU16(pBuf, smetransactionId);
            pBuf += sizeof(tANI_U16);

            //statusCode            
            limCopyU32(pBuf, reasonCode);
            pBuf += sizeof(tSirResultCodes);

            //peerMacAddr
            palCopyMemory( pMac->hHdd, pBuf, peerMacAddr, sizeof(tSirMacAddr));
            pBuf += sizeof(tSirMacAddr);

<<<<<<< HEAD
#if (WNI_POLARIS_FW_PRODUCT == AP)
            limCopyU16(pBuf, aid);
            pBuf += sizeof(tANI_U16);

            // perStaStats
            limStatSerDes(pMac, &pMac->hal.halMac.macStats.pPerStaStats[aid].staStat, pBuf);
#else
            // Clear Station Stats
            //for sta, it is always 1, IBSS is handled at halInitSta

#endif//#if (WNI_POLARIS_FW_PRODUCT == AP)
=======
            // Clear Station Stats
            //for sta, it is always 1, IBSS is handled at halInitSta

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

          
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
            limDiagEventReport(pMac, WLAN_PE_DIAG_DISASSOC_RSP_EVENT,
                                      psessionEntry, (tANI_U16)reasonCode, 0);
#endif
            pMsg = (tANI_U32*) pSirSmeDisassocRsp;
            break;

        default:
            /**
             * Disassociation indication due to Disassociation
             * frame reception from peer entity or due to
             * loss of link with peer entity.
             */
            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeDisassocInd, sizeof(tSirSmeDisassocInd)))
            {
                // Log error
                limLog(pMac, LOGP,
<<<<<<< HEAD
                   FL("call to palAllocateMemory failed for eWNI_SME_DISASSOC_IND\n"));
=======
                   FL("call to palAllocateMemory failed for eWNI_SME_DISASSOC_IND"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

                return;
            }

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
            sirStoreU16N((tANI_U8*)&pSirSmeDisassocInd->messageType,
                         eWNI_SME_DISASSOC_IND);
            sirStoreU16N((tANI_U8*)&pSirSmeDisassocInd->length,
                         sizeof(tSirSmeDisassocInd));
#else
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            pSirSmeDisassocInd->messageType = eWNI_SME_DISASSOC_IND;
            pSirSmeDisassocInd->length      = sizeof(tSirSmeDisassocInd);
            
            /* Update SME session Id and Transaction Id */
            pSirSmeDisassocInd->sessionId = smesessionId;
            pSirSmeDisassocInd->transactionId = smetransactionId;
            pSirSmeDisassocInd->reasonCode = reasonCode;
<<<<<<< HEAD
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            pBuf = (tANI_U8 *) &pSirSmeDisassocInd->statusCode;

            limCopyU32(pBuf, reasonCode);
            pBuf += sizeof(tSirResultCodes);

            palCopyMemory( pMac->hHdd, pBuf, psessionEntry->bssId, sizeof(tSirMacAddr));
            pBuf += sizeof(tSirMacAddr);

            palCopyMemory( pMac->hHdd, pBuf, peerMacAddr, sizeof(tSirMacAddr));
<<<<<<< HEAD
#if (WNI_POLARIS_FW_PRODUCT == AP)
            pBuf += sizeof(tSirMacAddr);
            limCopyU16(pBuf, aid);
            pBuf += sizeof(tANI_U16);

            limStatSerDes(pMac, &pMac->hal.halMac.macStats.pPerStaStats[aid].staStat, pBuf);

#endif//#if (WNI_POLARIS_FW_PRODUCT == AP)
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release


#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
            limDiagEventReport(pMac, WLAN_PE_DIAG_DISASSOC_IND_EVENT,
                                              psessionEntry, (tANI_U16)reasonCode, 0);
#endif
            pMsg = (tANI_U32*) pSirSmeDisassocInd;
<<<<<<< HEAD
#if (WNI_POLARIS_FW_PRODUCT == AP)
            PELOG1(limLog(pMac, LOG1,
               FL("*** Sending DisAssocInd staId=%d, reasonCode=%d ***\n"),
               aid, reasonCode);)
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

            break;
    }

    /* Delete the PE session Created */
    if((psessionEntry != NULL) && ((psessionEntry ->limSystemRole ==  eLIM_STA_ROLE) ||
                                  (psessionEntry ->limSystemRole ==  eLIM_BT_AMP_STA_ROLE)) )
    {
        peDeleteSession(pMac,psessionEntry);
    }
        
<<<<<<< HEAD
    if( IS_MCC_SUPPORTED && limIsLinkSuspended( pMac ) )
    {
        //Resume on the first active session channel.
        tANI_U8 resumeChannel;
        ePhyChanBondState resumePhyCbState;
        peGetActiveSessionChannel( pMac, &resumeChannel, &resumePhyCbState );
        peSetResumeChannel( pMac, resumeChannel, resumePhyCbState );

        limResumeLink( pMac, limSendSmeDisassocDeauthNtfPostResume, 
                                              (tANI_U32*) pMsg );
    }
    else
    {
        limSendSmeDisassocDeauthNtfPostResume( pMac, eHAL_STATUS_SUCCESS,
                                              (tANI_U32*) pMsg );
    }
=======
    limSendSmeDisassocDeauthNtf( pMac, eHAL_STATUS_SUCCESS,
                                              (tANI_U32*) pMsg );
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
} /*** end limSendSmeDisassocNtf() ***/


/** -----------------------------------------------------------------
  \brief limSendSmeDisassocInd() - sends SME_DISASSOC_IND
   
  After receiving disassociation frame from peer entity, this 
  function sends a eWNI_SME_DISASSOC_IND to SME with a specific
  reason code.  
    
  \param pMac - global mac structure
  \param pStaDs - station dph hash node 
  \return none 
  \sa
  ----------------------------------------------------------------- */
void
limSendSmeDisassocInd(tpAniSirGlobal pMac, tpDphHashNode pStaDs,tpPESession psessionEntry)
{
    tSirMsgQ  mmhMsg;
    tSirSmeDisassocInd *pSirSmeDisassocInd;

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeDisassocInd, sizeof(tSirSmeDisassocInd)))
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("palAllocateMemory failed for eWNI_SME_DISASSOC_IND\n"));
        return;
    }

    //psessionEntry = peFindSessionByBssid(pMac,pStaDs->staAddr,&sessionId); 
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
    sirStoreU16N((tANI_U8*)&pSirSmeDisassocInd->messageType, eWNI_SME_DISASSOC_IND);
    sirStoreU16N((tANI_U8*)&pSirSmeDisassocInd->length, sizeof(tSirSmeDisassocInd));
#else
    pSirSmeDisassocInd->messageType = eWNI_SME_DISASSOC_IND;
    pSirSmeDisassocInd->length = sizeof(tSirSmeDisassocInd);
#endif

#if 0 //Commenting out all the serialization     
    //statusCode
    pBuf = (tANI_U8 *) &pSirSmeDisassocInd->statusCode;
    limCopyU32(pBuf, pStaDs->mlmStaContext.disassocReason);
    pBuf += sizeof(tSirResultCodes);

    //peerMacAddr
    palCopyMemory( pMac->hHdd, pBuf, pStaDs->staAddr, sizeof(tSirMacAddr));

#ifdef ANI_PRODUCT_TYPE_AP
    pBuf += sizeof(tSirMacAddr);
    //aid
    limCopyU16(pBuf, pStaDs->assocId);
    pBuf += sizeof(tANI_U16);

    //perStaStats
    limStatSerDes(pMac, &pMac->hal.halMac.macStats.pPerStaStats[pStaDs->assocId].staStat, pBuf);
#endif
#endif
=======
        limLog(pMac, LOGP, FL("palAllocateMemory failed for eWNI_SME_DISASSOC_IND"));
        return;
    }

    pSirSmeDisassocInd->messageType = eWNI_SME_DISASSOC_IND;
    pSirSmeDisassocInd->length = sizeof(tSirSmeDisassocInd);

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    pSirSmeDisassocInd->sessionId     =  psessionEntry->smeSessionId;
    pSirSmeDisassocInd->transactionId =  psessionEntry->transactionId;
    pSirSmeDisassocInd->statusCode    =  pStaDs->mlmStaContext.disassocReason;
    pSirSmeDisassocInd->reasonCode    =  pStaDs->mlmStaContext.disassocReason;
    
    palCopyMemory( pMac->hHdd, pSirSmeDisassocInd->bssId , psessionEntry->bssId , sizeof(tSirMacAddr));
 
    palCopyMemory( pMac->hHdd, pSirSmeDisassocInd->peerMacAddr , pStaDs->staAddr, sizeof(tSirMacAddr));

<<<<<<< HEAD
#ifdef ANI_PRODUCT_TYPE_AP
    pSirSmeDisassocInd->aid =  pStaDs->assocId;
    limStatSerDes(pMac, &pMac->hal.halMac.macStats.pPerStaStats[pStaDs->assocId].staStat,(tANI_U8*)&pSirSmeDisassocInd-> perStaStats ); 
#endif   
#ifdef WLAN_SOFTAP_FEATURE
    pSirSmeDisassocInd->staId = pStaDs->staIndex;
#endif  
=======
    pSirSmeDisassocInd->staId = pStaDs->staIndex;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
 
    mmhMsg.type = eWNI_SME_DISASSOC_IND;
    mmhMsg.bodyptr = pSirSmeDisassocInd;
    mmhMsg.bodyval = 0;

    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_DISASSOC_IND_EVENT, psessionEntry, 0, (tANI_U16)pStaDs->mlmStaContext.disassocReason); 
#endif //FEATURE_WLAN_DIAG_SUPPORT

    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
 
} /*** end limSendSmeDisassocInd() ***/


/** -----------------------------------------------------------------
  \brief limSendSmeDeauthInd() - sends SME_DEAUTH_IND
   
  After receiving deauthentication frame from peer entity, this 
  function sends a eWNI_SME_DEAUTH_IND to SME with a specific
  reason code.  
    
  \param pMac - global mac structure
  \param pStaDs - station dph hash node 
  \return none 
  \sa
  ----------------------------------------------------------------- */
void
limSendSmeDeauthInd(tpAniSirGlobal pMac, tpDphHashNode pStaDs, tpPESession psessionEntry)                   
{
<<<<<<< HEAD
#ifndef WLAN_SOFTAP_FEATURE
    tANI_U8  *pBuf;
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    tSirMsgQ  mmhMsg;
    tSirSmeDeauthInd  *pSirSmeDeauthInd;

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeDeauthInd, sizeof(tSirSmeDeauthInd)))
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("palAllocateMemory failed for eWNI_SME_DEAUTH_IND \n"));
        return;
    }

#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
    sirStoreU16N((tANI_U8*)&pSirSmeDeauthInd->messageType, eWNI_SME_DEAUTH_IND);
    sirStoreU16N((tANI_U8*)&pSirSmeDeauthInd->length, sizeof(tSirSmeDeauthInd));
#else
    pSirSmeDeauthInd->messageType = eWNI_SME_DEAUTH_IND;
    pSirSmeDeauthInd->length = sizeof(tSirSmeDeauthInd);
#endif

#ifdef WLAN_SOFTAP_FEATURE
=======
        limLog(pMac, LOGP, FL("palAllocateMemory failed for eWNI_SME_DEAUTH_IND "));
        return;
    }

    pSirSmeDeauthInd->messageType = eWNI_SME_DEAUTH_IND;
    pSirSmeDeauthInd->length = sizeof(tSirSmeDeauthInd);

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    pSirSmeDeauthInd->sessionId = psessionEntry->smeSessionId;
    pSirSmeDeauthInd->transactionId = psessionEntry->transactionId;
    if(eSIR_INFRA_AP_MODE == psessionEntry->bssType)
    {
        pSirSmeDeauthInd->statusCode = (tSirResultCodes)pStaDs->mlmStaContext.cleanupTrigger;
    }
    else
    {
        //Need to indicatet he reascon code over the air
        pSirSmeDeauthInd->statusCode = (tSirResultCodes)pStaDs->mlmStaContext.disassocReason;
    }
    //BSSID
    palCopyMemory( pMac->hHdd, pSirSmeDeauthInd->bssId, psessionEntry->bssId, sizeof(tSirMacAddr));
    //peerMacAddr
    palCopyMemory( pMac->hHdd, pSirSmeDeauthInd->peerMacAddr, pStaDs->staAddr, sizeof(tSirMacAddr));
    pSirSmeDeauthInd->reasonCode = pStaDs->mlmStaContext.disassocReason;
<<<<<<< HEAD
#else

    //sessionId
    pBuf = (tANI_U8 *) &pSirSmeDeauthInd->sessionId;
    *pBuf++ = psessionEntry->smeSessionId;

    //transactionId
    limCopyU16(pBuf, 0);
    pBuf += sizeof(tANI_U16);

    // status code
    limCopyU32(pBuf, pStaDs->mlmStaContext.cleanupTrigger);
    pBuf += sizeof(tSirResultCodes);
    
    //bssid
    palCopyMemory( pMac->hHdd, pBuf, psessionEntry->bssId, sizeof(tSirMacAddr));
    pBuf += sizeof(tSirMacAddr);

    //peerMacAddr
    palCopyMemory( pMac->hHdd, pBuf, pStaDs->staAddr, sizeof(tSirMacAddr));
#endif  

#if (WNI_POLARIS_FW_PRODUCT == AP)
    pBuf += sizeof(tSirMacAddr);
    limCopyU16(pBuf, pStaDs->staAddr);
#endif

#ifdef WLAN_SOFTAP_FEATURE
    pSirSmeDeauthInd->staId = pStaDs->staIndex;
#endif
=======


    pSirSmeDeauthInd->staId = pStaDs->staIndex;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    mmhMsg.type = eWNI_SME_DEAUTH_IND;
    mmhMsg.bodyptr = pSirSmeDeauthInd;
    mmhMsg.bodyval = 0;

    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_DEAUTH_IND_EVENT, psessionEntry, 0, pStaDs->mlmStaContext.cleanupTrigger);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
    return;
} /*** end limSendSmeDeauthInd() ***/

<<<<<<< HEAD
=======
#ifdef FEATURE_WLAN_TDLS
/**
 * limSendSmeTDLSDelStaInd()
 *
 *FUNCTION:
 * This function is called to send the TDLS STA context deletion to SME.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 * NA
 *
 * @param  pMac   - Pointer to global MAC structure
 * @param  pStaDs - Pointer to internal STA Datastructure
 * @param  psessionEntry - Pointer to the session entry
 * @param  reasonCode - Reason for TDLS sta deletion
 * @return None
 */
void
limSendSmeTDLSDelStaInd(tpAniSirGlobal pMac, tpDphHashNode pStaDs, tpPESession psessionEntry, tANI_U16 reasonCode)
{
    tSirMsgQ  mmhMsg;
    tSirTdlsDelStaInd  *pSirTdlsDelStaInd;

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirTdlsDelStaInd, sizeof(tSirTdlsDelStaInd)))
    {
        limLog(pMac, LOGP, FL("palAllocateMemory failed for eWNI_SME_TDLS_DEL_STA_IND "));
        return;
    }

    //messageType
    pSirTdlsDelStaInd->messageType = eWNI_SME_TDLS_DEL_STA_IND;
    pSirTdlsDelStaInd->length = sizeof(tSirTdlsDelStaInd);

    //sessionId
    pSirTdlsDelStaInd->sessionId = psessionEntry->smeSessionId;

    //peerMacAddr
    palCopyMemory( pMac->hHdd, pSirTdlsDelStaInd->peerMac, pStaDs->staAddr, sizeof(tSirMacAddr));

    //staId
    limCopyU16((tANI_U8*)(&pSirTdlsDelStaInd->staId), (tANI_U16)pStaDs->staIndex);

    //reasonCode
    limCopyU16((tANI_U8*)(&pSirTdlsDelStaInd->reasonCode), reasonCode);

    mmhMsg.type = eWNI_SME_TDLS_DEL_STA_IND;
    mmhMsg.bodyptr = pSirTdlsDelStaInd;
    mmhMsg.bodyval = 0;


    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
    return;
}/*** end limSendSmeTDLSDelStaInd() ***/

/**
 * limSendSmeTDLSDeleteAllPeerInd()
 *
 *FUNCTION:
 * This function is called to send the eWNI_SME_TDLS_DEL_ALL_PEER_IND
 * message to SME.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 * NA
 *
 * @param  pMac   - Pointer to global MAC structure
 * @param  psessionEntry - Pointer to the session entry
 * @return None
 */
void
limSendSmeTDLSDeleteAllPeerInd(tpAniSirGlobal pMac, tpPESession psessionEntry)
{
    tSirMsgQ  mmhMsg;
    tSirTdlsDelAllPeerInd  *pSirTdlsDelAllPeerInd;

    if ( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirTdlsDelAllPeerInd, sizeof(tSirTdlsDelAllPeerInd)))
    {
        limLog(pMac, LOGP, FL("palAllocateMemory failed for eWNI_SME_TDLS_DEL_ALL_PEER_IND"));
        return;
    }

    //messageType
    pSirTdlsDelAllPeerInd->messageType = eWNI_SME_TDLS_DEL_ALL_PEER_IND;
    pSirTdlsDelAllPeerInd->length = sizeof(tSirTdlsDelAllPeerInd);

    //sessionId
    pSirTdlsDelAllPeerInd->sessionId = psessionEntry->smeSessionId;

    mmhMsg.type = eWNI_SME_TDLS_DEL_ALL_PEER_IND;
    mmhMsg.bodyptr = pSirTdlsDelAllPeerInd;
    mmhMsg.bodyval = 0;


    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
    return;
}/*** end limSendSmeTDLSDeleteAllPeerInd() ***/

/**
 * limSendSmeMgmtTXCompletion()
 *
 *FUNCTION:
 * This function is called to send the eWNI_SME_MGMT_FRM_TX_COMPLETION_IND
 * message to SME.
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 *
 *NOTE:
 * NA
 *
 * @param  pMac   - Pointer to global MAC structure
 * @param  psessionEntry - Pointer to the session entry
 * @param  txCompleteStatus - TX Complete Status of Mgmt Frames
 * @return None
 */
void
limSendSmeMgmtTXCompletion(tpAniSirGlobal pMac,
                           tpPESession psessionEntry,
                           tANI_U32 txCompleteStatus)
{
    tSirMsgQ  mmhMsg;
    tSirMgmtTxCompletionInd  *pSirMgmtTxCompletionInd;

    if ( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirMgmtTxCompletionInd, sizeof(tSirMgmtTxCompletionInd)))
    {
        limLog(pMac, LOGP, FL("palAllocateMemory failed for eWNI_SME_MGMT_FRM_TX_COMPLETION_IND"));
        return;
    }

    //messageType
    pSirMgmtTxCompletionInd->messageType = eWNI_SME_MGMT_FRM_TX_COMPLETION_IND;
    pSirMgmtTxCompletionInd->length = sizeof(tSirMgmtTxCompletionInd);

    //sessionId
    pSirMgmtTxCompletionInd->sessionId = psessionEntry->smeSessionId;

    pSirMgmtTxCompletionInd->txCompleteStatus = txCompleteStatus;

    mmhMsg.type = eWNI_SME_MGMT_FRM_TX_COMPLETION_IND;
    mmhMsg.bodyptr = pSirMgmtTxCompletionInd;
    mmhMsg.bodyval = 0;


    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
    return;
}/*** end limSendSmeTDLSDeleteAllPeerInd() ***/
#endif

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

/**
 * limSendSmeDeauthNtf()
 *
 *FUNCTION:
 * This function is called by limProcessSmeMessages() to send
 * eWNI_SME_DISASSOC_RSP/IND message to host
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * This function is used for sending eWNI_SME_DEAUTH_CNF or
 * eWNI_SME_DEAUTH_IND to host depending on deauthentication trigger.
 *
 * @param peerMacAddr       Indicates the peer MAC addr to which
 *                          deauthentication was initiated
 * @param reasonCode        Indicates the reason for Deauthetication
 * @param deauthTrigger     Indicates the trigger for Deauthetication
 * @param aid               Indicates the STAID. This parameter is present
 *                          only on AP.
 *
 * @return None
 */
void
limSendSmeDeauthNtf(tpAniSirGlobal pMac, tSirMacAddr peerMacAddr, tSirResultCodes reasonCode,
                    tANI_U16 deauthTrigger, tANI_U16 aid,tANI_U8 smesessionId, tANI_U16 smetransactionId)
{
    tANI_U8             *pBuf;
    tSirSmeDeauthRsp    *pSirSmeDeauthRsp;
    tSirSmeDeauthInd    *pSirSmeDeauthInd;
    tpPESession         psessionEntry;
    tANI_U8             sessionId;
    tANI_U32            *pMsg;

    psessionEntry = peFindSessionByBssid(pMac,peerMacAddr,&sessionId);  
    switch (deauthTrigger)
    {
        case eLIM_PEER_ENTITY_DEAUTH:
            return;
            
        case eLIM_HOST_DEAUTH:
            /**
             * Deauthentication response to host triggered
             * deauthentication.
             */
            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeDeauthRsp, sizeof(tSirSmeDeauthRsp)))
            {
                // Log error
                limLog(pMac, LOGP,
<<<<<<< HEAD
                   FL("call to palAllocateMemory failed for eWNI_SME_DEAUTH_RSP\n"));
=======
                   FL("call to palAllocateMemory failed for eWNI_SME_DEAUTH_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

                return;
            }

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
            sirStoreU16N((tANI_U8*) &(pSirSmeDeauthRsp->messageType),
                         eWNI_SME_DEAUTH_RSP);
                sirStoreU16N((tANI_U8*) &(pSirSmeDeauthRsp->length),
                             sizeof(tSirSmeDeauthRsp));
#else
            pSirSmeDeauthRsp->messageType = eWNI_SME_DEAUTH_RSP;
            pSirSmeDeauthRsp->length      = sizeof(tSirSmeDeauthRsp);
#endif
=======
            pSirSmeDeauthRsp->messageType = eWNI_SME_DEAUTH_RSP;
            pSirSmeDeauthRsp->length      = sizeof(tSirSmeDeauthRsp);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            pSirSmeDeauthRsp->statusCode = reasonCode;
            pSirSmeDeauthRsp->sessionId = smesessionId;
            pSirSmeDeauthRsp->transactionId = smetransactionId;  

            pBuf  = (tANI_U8 *) pSirSmeDeauthRsp->peerMacAddr;
            palCopyMemory( pMac->hHdd, pBuf, peerMacAddr, sizeof(tSirMacAddr));

<<<<<<< HEAD
#if (WNI_POLARIS_FW_PRODUCT == AP)
            pBuf += sizeof(tSirMacAddr);
            limCopyU16(pBuf, aid);
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
            limDiagEventReport(pMac, WLAN_PE_DIAG_DEAUTH_RSP_EVENT,
                                      psessionEntry, 0, (tANI_U16)reasonCode);
#endif
            pMsg = (tANI_U32*)pSirSmeDeauthRsp;

            break;

        default:
            /**
             * Deauthentication indication due to Deauthentication
             * frame reception from peer entity or due to
             * loss of link with peer entity.
             */
            if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeDeauthInd, sizeof(tSirSmeDeauthInd)))
            {
                // Log error
                limLog(pMac, LOGP,
<<<<<<< HEAD
                   FL("call to palAllocateMemory failed for eWNI_SME_DEAUTH_Ind\n"));
=======
                   FL("call to palAllocateMemory failed for eWNI_SME_DEAUTH_Ind"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

                return;
            }

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
            sirStoreU16N((tANI_U8*)&pSirSmeDeauthInd->messageType,
                         eWNI_SME_DEAUTH_IND);
            sirStoreU16N((tANI_U8*)&pSirSmeDeauthInd->length,
                         sizeof(tSirSmeDeauthInd));
#else
            pSirSmeDeauthInd->messageType = eWNI_SME_DEAUTH_IND;
            pSirSmeDeauthInd->length      = sizeof(tSirSmeDeauthInd);
            pSirSmeDeauthInd->reasonCode = eSIR_MAC_UNSPEC_FAILURE_REASON;
#endif
=======
            pSirSmeDeauthInd->messageType = eWNI_SME_DEAUTH_IND;
            pSirSmeDeauthInd->length      = sizeof(tSirSmeDeauthInd);
            pSirSmeDeauthInd->reasonCode = eSIR_MAC_UNSPEC_FAILURE_REASON;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

            // sessionId
            pBuf = (tANI_U8*) &pSirSmeDeauthInd->sessionId;
            *pBuf++ = smesessionId;

            //transaction ID
            limCopyU16(pBuf, smetransactionId);
            pBuf += sizeof(tANI_U16);

            // status code
            limCopyU32(pBuf, reasonCode);
            pBuf += sizeof(tSirResultCodes);

            //bssId
            palCopyMemory( pMac->hHdd, pBuf, psessionEntry->bssId, sizeof(tSirMacAddr));
            pBuf += sizeof(tSirMacAddr);

            //peerMacAddr
            palCopyMemory( pMac->hHdd, pSirSmeDeauthInd->peerMacAddr, peerMacAddr, sizeof(tSirMacAddr));

<<<<<<< HEAD
#if (WNI_POLARIS_FW_PRODUCT == AP)
            pBuf += sizeof(tSirMacAddr);
            limCopyU16(pBuf, aid);
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
            limDiagEventReport(pMac, WLAN_PE_DIAG_DEAUTH_IND_EVENT,
                                        psessionEntry, 0, (tANI_U16)reasonCode);
#endif //FEATURE_WLAN_DIAG_SUPPORT
            pMsg = (tANI_U32*)pSirSmeDeauthInd;

            break;
    }
    
    /*Delete the PE session  created */
    if(psessionEntry != NULL)
    {
        peDeleteSession(pMac,psessionEntry);
    }   

<<<<<<< HEAD
    if( IS_MCC_SUPPORTED && limIsLinkSuspended( pMac ) )
    {
        //Resume on the first active session channel.
        tANI_U8 resumeChannel;
        ePhyChanBondState resumePhyCbState;
        peGetActiveSessionChannel( pMac, &resumeChannel, &resumePhyCbState );
        peSetResumeChannel( pMac, resumeChannel, resumePhyCbState );

        limResumeLink( pMac, limSendSmeDisassocDeauthNtfPostResume, 
                                              (tANI_U32*) pMsg );
    }
    else
    {
        limSendSmeDisassocDeauthNtfPostResume( pMac, eHAL_STATUS_SUCCESS,
                                              (tANI_U32*) pMsg );
    }
=======
    limSendSmeDisassocDeauthNtf( pMac, eHAL_STATUS_SUCCESS,
                                              (tANI_U32*) pMsg );

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
} /*** end limSendSmeDeauthNtf() ***/


/**
 * limSendSmeWmStatusChangeNtf()
 *
 *FUNCTION:
 * This function is called by limProcessSmeMessages() to send
 * eWNI_SME_WM_STATUS_CHANGE_NTF message to host.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 *
 * @param statusChangeCode   Indicates the change in the wireless medium.
 * @param statusChangeInfo   Indicates the information associated with
 *                           change in the wireless medium.
 * @param infoLen            Indicates the length of status change information
 *                           being sent.
 *
 * @return None
 */
void
limSendSmeWmStatusChangeNtf(tpAniSirGlobal pMac, tSirSmeStatusChangeCode statusChangeCode,
                                 tANI_U32 *pStatusChangeInfo, tANI_U16 infoLen, tANI_U8 sessionId)
{
    tSirMsgQ                  mmhMsg;
    tSirSmeWmStatusChangeNtf  *pSirSmeWmStatusChangeNtf;
    eHalStatus                status;
<<<<<<< HEAD
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && (WNI_POLARIS_FW_PRODUCT == AP)
    tANI_U32                  bufLen;
    tANI_U16                  length=0;
    tANI_U8                   *pBuf;
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release



    status = palAllocateMemory( pMac->hHdd, (void **)&pSirSmeWmStatusChangeNtf,
                                                    sizeof(tSirSmeWmStatusChangeNtf));
    if (status != eHAL_STATUS_SUCCESS)
    {
        limLog(pMac, LOGE,
<<<<<<< HEAD
          FL("call to palAllocateMemory failed for eWNI_SME_WM_STATUS_CHANGE_NTF, status = %d\n"),
=======
          FL("call to palAllocateMemory failed for eWNI_SME_WM_STATUS_CHANGE_NTF, status = %d"),
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
          status);
          return;
    }

<<<<<<< HEAD
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && (WNI_POLARIS_FW_PRODUCT == AP)
    pBuf = (tANI_U8 *)pSirSmeWmStatusChangeNtf;
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    mmhMsg.type = eWNI_SME_WM_STATUS_CHANGE_NTF;
    mmhMsg.bodyval = 0;
    mmhMsg.bodyptr = pSirSmeWmStatusChangeNtf;

    switch(statusChangeCode)
    {
        case eSIR_SME_RADAR_DETECTED:

<<<<<<< HEAD
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && (WNI_POLARIS_FW_PRODUCT == AP)
            bufLen = sizeof(tSirSmeWmStatusChangeNtf);
            if ((limSmeWmStatusChangeHeaderSerDes(pMac,
                                                  statusChangeCode,
                                          pBuf,
                                          &length,
                                          bufLen,
                                          sessionId) != eSIR_SUCCESS))
            {
                palFreeMemory(pMac->hHdd, (void *) pSirSmeWmStatusChangeNtf);
                limLog(pMac, LOGP, FL("Header SerDes failed \n"));
                return;
            }
            pBuf += length;
            bufLen -= length;
            if ((limRadioInfoSerDes(pMac,
                                  (tpSirRadarInfo)pStatusChangeInfo,
                                  pBuf,
                                  &length,
                                  bufLen) != eSIR_SUCCESS))
            {
                palFreeMemory(pMac->hHdd, (void *) pSirSmeWmStatusChangeNtf);
                limLog(pMac, LOGP, FL("Radio Info SerDes failed \n"));
                return;
            }

            pBuf = (tANI_U8 *) pSirSmeWmStatusChangeNtf;
            pBuf += sizeof(tANI_U16);
            limCopyU16(pBuf, length);
#endif
            break;

        case eSIR_SME_CB_LEGACY_BSS_FOUND_BY_AP:
#if (WNI_POLARIS_FW_PACKAGE == ADVANCED) && (WNI_POLARIS_FW_PRODUCT == AP)

            if( eSIR_SUCCESS != nonTitanBssFoundSerDes( pMac,
                                (tpSirNeighborBssWdsInfo) pStatusChangeInfo,
                                pBuf,
                                &length,
                                sessionId))
            {
                palFreeMemory(pMac->hHdd, (void *) pSirSmeWmStatusChangeNtf);
                limLog( pMac, LOGP,
                    FL("Unable to serialize nonTitanBssFoundSerDes!\n"));
                return;
            }
#endif
=======
            break;

        case eSIR_SME_CB_LEGACY_BSS_FOUND_BY_AP:
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;

        case eSIR_SME_BACKGROUND_SCAN_FAIL:
            limPackBkgndScanFailNotify(pMac,
                                       statusChangeCode,
                                       (tpSirBackgroundScanInfo)pStatusChangeInfo,
                                       pSirSmeWmStatusChangeNtf, sessionId);
            break;

        default:
<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
        sirStoreU16N((tANI_U8*)&pSirSmeWmStatusChangeNtf->messageType,
                    eWNI_SME_WM_STATUS_CHANGE_NTF );
        sirStoreU16N((tANI_U8*)&pSirSmeWmStatusChangeNtf->length,
                    (sizeof(tSirSmeWmStatusChangeNtf)));
        pSirSmeWmStatusChangeNtf->sessionId = sessionId;
        sirStoreU32N((tANI_U8*)&pSirSmeWmStatusChangeNtf->statusChangeCode,
                    statusChangeCode);
#else
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        pSirSmeWmStatusChangeNtf->messageType = eWNI_SME_WM_STATUS_CHANGE_NTF;
        pSirSmeWmStatusChangeNtf->statusChangeCode = statusChangeCode;
        pSirSmeWmStatusChangeNtf->length = sizeof(tSirSmeWmStatusChangeNtf);
        pSirSmeWmStatusChangeNtf->sessionId = sessionId;
<<<<<<< HEAD
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        if(sizeof(pSirSmeWmStatusChangeNtf->statusChangeInfo) >= infoLen)
        {
            palCopyMemory( pMac->hHdd, (tANI_U8 *)&pSirSmeWmStatusChangeNtf->statusChangeInfo, (tANI_U8 *)pStatusChangeInfo, infoLen);
        }
<<<<<<< HEAD
        limLog(pMac, LOGE, FL("***---*** StatusChg: code 0x%x, length %d ***---***\n"),
=======
        limLog(pMac, LOGE, FL("***---*** StatusChg: code 0x%x, length %d ***---***"),
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
               statusChangeCode, infoLen);
        break;
    }


<<<<<<< HEAD
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    if (eSIR_SUCCESS != limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT))
    {
        palFreeMemory(pMac->hHdd, (void *) pSirSmeWmStatusChangeNtf);
        limLog( pMac, LOGP, FL("limSysProcessMmhMsgApi failed\n"));
=======
    MTRACE(macTraceMsgTx(pMac, sessionId, mmhMsg.type));
    if (eSIR_SUCCESS != limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT))
    {
        palFreeMemory(pMac->hHdd, (void *) pSirSmeWmStatusChangeNtf);
        limLog( pMac, LOGP, FL("limSysProcessMmhMsgApi failed"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }

} /*** end limSendSmeWmStatusChangeNtf() ***/


/**
 * limSendSmeSetContextRsp()
 *
 *FUNCTION:
 * This function is called by limProcessSmeMessages() to send
 * eWNI_SME_SETCONTEXT_RSP message to host
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 *
 * @param pMac         Pointer to Global MAC structure
 * @param peerMacAddr  Indicates the peer MAC addr to which
 *                     setContext was performed
 * @param aid          Indicates the aid corresponding to the peer MAC
 *                     address
 * @param resultCode   Indicates the result of previously issued
 *                     eWNI_SME_SETCONTEXT_RSP message
 *
 * @return None
 */
void
limSendSmeSetContextRsp(tpAniSirGlobal pMac,
                        tSirMacAddr peerMacAddr, tANI_U16 aid,
                        tSirResultCodes resultCode,
                        tpPESession psessionEntry,tANI_U8 smesessionId,tANI_U16 smetransactionId)
{

    tANI_U8                   *pBuf;
    tSirMsgQ             mmhMsg;
    tSirSmeSetContextRsp *pSirSmeSetContextRsp;

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeSetContextRsp, sizeof(tSirSmeSetContextRsp)))
    {
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("call to palAllocateMemory failed for SmeSetContextRsp\n"));
=======
               FL("call to palAllocateMemory failed for SmeSetContextRsp"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        return;
    }

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
    sirStoreU16N((tANI_U8*)&pSirSmeSetContextRsp->messageType,
                 eWNI_SME_SETCONTEXT_RSP);
    sirStoreU16N((tANI_U8*)&pSirSmeSetContextRsp->length,
                 sizeof(tSirSmeSetContextRsp));
#else
    pSirSmeSetContextRsp->messageType = eWNI_SME_SETCONTEXT_RSP;
    pSirSmeSetContextRsp->length      = sizeof(tSirSmeSetContextRsp);
#endif
=======
    pSirSmeSetContextRsp->messageType = eWNI_SME_SETCONTEXT_RSP;
    pSirSmeSetContextRsp->length      = sizeof(tSirSmeSetContextRsp);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    pSirSmeSetContextRsp->statusCode  = resultCode;

    pBuf = pSirSmeSetContextRsp->peerMacAddr;

    palCopyMemory( pMac->hHdd, pBuf, (tANI_U8 *) peerMacAddr, sizeof(tSirMacAddr));
    pBuf += sizeof(tSirMacAddr);

<<<<<<< HEAD
#if (WNI_POLARIS_FW_PRODUCT == AP)
    limCopyU16(pBuf, aid);
    pBuf += sizeof(tANI_U16);
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    /* Update SME session and transaction Id*/
    pSirSmeSetContextRsp->sessionId = smesessionId;
    pSirSmeSetContextRsp->transactionId = smetransactionId;

    mmhMsg.type = eWNI_SME_SETCONTEXT_RSP;
    mmhMsg.bodyptr = pSirSmeSetContextRsp;
    mmhMsg.bodyval = 0;
<<<<<<< HEAD
    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
=======
    if(NULL == psessionEntry)
    {
        MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    }
    else
    {
        MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
    }
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_SETCONTEXT_RSP_EVENT, psessionEntry, (tANI_U16)resultCode, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
} /*** end limSendSmeSetContextRsp() ***/

/**
 * limSendSmeRemoveKeyRsp()
 *
 *FUNCTION:
 * This function is called by limProcessSmeMessages() to send
 * eWNI_SME_REMOVEKEY_RSP message to host
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 *
 * @param pMac         Pointer to Global MAC structure
 * @param peerMacAddr  Indicates the peer MAC addr to which
 *                     Removekey was performed
 * @param aid          Indicates the aid corresponding to the peer MAC
 *                     address
 * @param resultCode   Indicates the result of previously issued
 *                     eWNI_SME_REMOVEKEY_RSP message
 *
 * @return None
 */
void
limSendSmeRemoveKeyRsp(tpAniSirGlobal pMac,
                        tSirMacAddr peerMacAddr,
                        tSirResultCodes resultCode,
                        tpPESession psessionEntry,tANI_U8 smesessionId,
                        tANI_U16 smetransactionId)
{
    tANI_U8                 *pBuf;
    tSirMsgQ                mmhMsg;
    tSirSmeRemoveKeyRsp     *pSirSmeRemoveKeyRsp;

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pSirSmeRemoveKeyRsp, sizeof(tSirSmeRemoveKeyRsp)))
    {
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
               FL("call to palAllocateMemory failed for SmeRemoveKeyRsp\n"));
=======
               FL("call to palAllocateMemory failed for SmeRemoveKeyRsp"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        return;
    }

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined(ANI_LITTLE_BYTE_ENDIAN)
    sirStoreU16N((tANI_U8*)&pSirSmeRemoveKeyRsp->messageType,
                 eWNI_SME_REMOVEKEY_RSP);
    sirStoreU16N((tANI_U8*)&pSirSmeRemoveKeyRsp->length,
                 sizeof(tSirSmeRemoveKeyRsp));
  
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    

    if(psessionEntry != NULL)
    {
        pBuf = pSirSmeRemoveKeyRsp->peerMacAddr;
        palCopyMemory( pMac->hHdd, pBuf, (tANI_U8 *) peerMacAddr, sizeof(tSirMacAddr));
        pBuf += sizeof(tSirMacAddr);
        limCopyU32(pBuf, resultCode);
    }
    
    pSirSmeRemoveKeyRsp->messageType = eWNI_SME_REMOVEKEY_RSP;
    pSirSmeRemoveKeyRsp->length      = sizeof(tSirSmeRemoveKeyRsp);
    pSirSmeRemoveKeyRsp->statusCode  = resultCode;
        
    /* Update SME session and transaction Id*/
    pSirSmeRemoveKeyRsp->sessionId = smesessionId;
    pSirSmeRemoveKeyRsp->transactionId = smetransactionId;   
    
    mmhMsg.type = eWNI_SME_REMOVEKEY_RSP;
    mmhMsg.bodyptr = pSirSmeRemoveKeyRsp;
    mmhMsg.bodyval = 0;
<<<<<<< HEAD
    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
=======
    if(NULL == psessionEntry)
    {
        MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    }
    else
    {
        MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
    }
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
} /*** end limSendSmeSetContextRsp() ***/


/**
 * limSendSmePromiscuousModeRsp()
 *
 *FUNCTION:
 * This function is called by limProcessSmeMessages() to send
 * eWNI_PROMISCUOUS_MODE_RSP message to host
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * This function is used for sending eWNI_SME_PROMISCUOUS_MODE_RSP to
 * host as a reply to eWNI_SME_PROMISCUOUS_MODE_REQ directive from it.
 *
 * @param None
 * @return None
 */
void
limSendSmePromiscuousModeRsp(tpAniSirGlobal pMac)
{
#if 0
    tSirMsgQ   mmhMsg;
    tSirMbMsg  *pMbMsg;

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pMbMsg, sizeof(tSirMbMsg)))
    {
        // Log error
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("call to palAllocateMemory failed\n"));
=======
        limLog(pMac, LOGP, FL("call to palAllocateMemory failed"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        return;
    }

    pMbMsg->type   = eWNI_SME_PROMISCUOUS_MODE_RSP;
    pMbMsg->msgLen = 4;

    mmhMsg.type = eWNI_SME_PROMISCUOUS_MODE_RSP;
    mmhMsg.bodyptr = pMbMsg;
    mmhMsg.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, 0, mmhMsg.type));
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
#endif
} /*** end limSendSmePromiscuousModeRsp() ***/



/**
 * limSendSmeNeighborBssInd()
 *
 *FUNCTION:
 * This function is called by limLookupNaddHashEntry() to send
 * eWNI_SME_NEIGHBOR_BSS_IND message to host
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * This function is used for sending eWNI_SME_NEIGHBOR_BSS_IND to
 * host upon detecting new BSS during background scanning if CFG
 * option is enabled for sending such indication
 *
 * @param  pMac - Pointer to Global MAC structure
 * @return None
 */

void
limSendSmeNeighborBssInd(tpAniSirGlobal pMac,
                         tLimScanResultNode *pBssDescr)
{
    tSirMsgQ                 msgQ;
    tANI_U32                      val;
    tSirSmeNeighborBssInd    *pNewBssInd;

    if ((pMac->lim.gLimSmeState != eLIM_SME_LINK_EST_WT_SCAN_STATE) ||
        ((pMac->lim.gLimSmeState == eLIM_SME_LINK_EST_WT_SCAN_STATE) &&
         pMac->lim.gLimRspReqd))
    {
        // LIM is not in background scan state OR
        // current scan is initiated by HDD.
        // No need to send new BSS indication to HDD
        return;
    }

    if (wlan_cfgGetInt(pMac, WNI_CFG_NEW_BSS_FOUND_IND, &val) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("could not get NEIGHBOR_BSS_IND from CFG\n"));
=======
        limLog(pMac, LOGP, FL("could not get NEIGHBOR_BSS_IND from CFG"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        return;
    }

    if (val == 0)
        return;

    /**
     * Need to indicate new BSSs found during
     * background scanning to host.
     * Allocate buffer for sending indication.
     * Length of buffer is length of BSS description
     * and length of header itself
     */
    val = pBssDescr->bssDescription.length + sizeof(tANI_U16) + sizeof(tANI_U32) + sizeof(tANI_U8);
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pNewBssInd, val))
    {
        // Log error
        limLog(pMac, LOGP,
<<<<<<< HEAD
           FL("call to palAllocateMemory failed for eWNI_SME_NEIGHBOR_BSS_IND\n"));
=======
           FL("call to palAllocateMemory failed for eWNI_SME_NEIGHBOR_BSS_IND"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        return;
    }

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
    sirStoreU16N((tANI_U8*) &pNewBssInd->messageType,
                 eWNI_SME_NEIGHBOR_BSS_IND);
    sirStoreU16N((tANI_U8*)&pNewBssInd->length, (tANI_U16)val );
#else
    pNewBssInd->messageType = eWNI_SME_NEIGHBOR_BSS_IND;
    pNewBssInd->length      = (tANI_U16) val;
#endif
    pNewBssInd->sessionId = 0;

#if (WNI_POLARIS_FW_PRODUCT == WLAN_STA)
    palCopyMemory( pMac->hHdd, (tANI_U8 *) pNewBssInd->bssDescription,
                  (tANI_U8 *) &pBssDescr->bssDescription,
                  pBssDescr->bssDescription.length + sizeof(tANI_U16));
#endif
=======
    pNewBssInd->messageType = eWNI_SME_NEIGHBOR_BSS_IND;
    pNewBssInd->length      = (tANI_U16) val;
    pNewBssInd->sessionId = 0;

    palCopyMemory( pMac->hHdd, (tANI_U8 *) pNewBssInd->bssDescription,
                  (tANI_U8 *) &pBssDescr->bssDescription,
                  pBssDescr->bssDescription.length + sizeof(tANI_U16));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    msgQ.type = eWNI_SME_NEIGHBOR_BSS_IND;
    msgQ.bodyptr = pNewBssInd;
    msgQ.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, msgQ.type));
    limSysProcessMmhMsgApi(pMac, &msgQ, ePROT);
} /*** end limSendSmeNeighborBssInd() ***/

/** -----------------------------------------------------------------
  \brief limSendSmeAddtsRsp() - sends SME ADDTS RSP    
  \      This function sends a eWNI_SME_ADDTS_RSP to SME.   
  \      SME only looks at rc and tspec field. 
  \param pMac - global mac structure
  \param rspReqd - is SmeAddTsRsp required
  \param status - status code of SME_ADD_TS_RSP
  \return tspec
  \sa
  ----------------------------------------------------------------- */
void
limSendSmeAddtsRsp(tpAniSirGlobal pMac, tANI_U8 rspReqd, tANI_U32 status, tpPESession psessionEntry, 
        tSirMacTspecIE tspec, tANI_U8 smesessionId, tANI_U16 smetransactionId)  
{
    tpSirAddtsRsp     rsp;
    tSirMsgQ          mmhMsg;

    if (! rspReqd)
        return;

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&rsp, sizeof(tSirAddtsRsp)))
    {
        limLog(pMac, LOGP, FL("palAllocateMemory failed for ADDTS_RSP"));
        return;
    }

    palZeroMemory( pMac->hHdd, (tANI_U8 *) rsp, sizeof(*rsp));
    rsp->messageType = eWNI_SME_ADDTS_RSP;
    rsp->rc = status;
    rsp->rsp.status = (enum eSirMacStatusCodes) status;
    //palCopyMemory( pMac->hHdd, (tANI_U8 *) &rsp->rsp.tspec, (tANI_U8 *) &addts->tspec, sizeof(addts->tspec));  
    rsp->rsp.tspec = tspec;
   
    /* Update SME session Id and transcation Id */
    rsp->sessionId = smesessionId;
    rsp->transactionId = smetransactionId;
    
    mmhMsg.type = eWNI_SME_ADDTS_RSP;
    mmhMsg.bodyptr = rsp;
    mmhMsg.bodyval = 0;
<<<<<<< HEAD
    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
=======
    if(NULL == psessionEntry)
    {
        MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    }
    else
    {
        MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
    }
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_ADDTS_RSP_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
    return;
}

void
limSendSmeAddtsInd(tpAniSirGlobal pMac, tpSirAddtsReqInfo addts)
{
    tpSirAddtsRsp rsp;
    tSirMsgQ      mmhMsg;

<<<<<<< HEAD
    limLog(pMac, LOGW, "SendSmeAddtsInd (token %d, tsid %d, up %d)\n",
=======
    limLog(pMac, LOGW, "SendSmeAddtsInd (token %d, tsid %d, up %d)",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           addts->dialogToken,
           addts->tspec.tsinfo.traffic.tsid,
           addts->tspec.tsinfo.traffic.userPrio);

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&rsp, sizeof(tSirAddtsRsp)))
    {
        // Log error
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("palAllocateMemory failed for ADDTS_IND\n"));
=======
        limLog(pMac, LOGP, FL("palAllocateMemory failed for ADDTS_IND"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return;
    }
    palZeroMemory( pMac->hHdd, (tANI_U8 *) rsp, sizeof(*rsp));

    rsp->messageType     = eWNI_SME_ADDTS_IND;

    palCopyMemory( pMac->hHdd, (tANI_U8 *) &rsp->rsp, (tANI_U8 *) addts, sizeof(*addts));

    mmhMsg.type = eWNI_SME_ADDTS_IND;
    mmhMsg.bodyptr = rsp;
    mmhMsg.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
}

void
limSendSmeDeltsRsp(tpAniSirGlobal pMac, tpSirDeltsReq delts, tANI_U32 status,tpPESession psessionEntry,tANI_U8 smesessionId,tANI_U16 smetransactionId)
{
    tpSirDeltsRsp rsp;
    tSirMsgQ      mmhMsg;

<<<<<<< HEAD
    limLog(pMac, LOGW, "SendSmeDeltsRsp (aid %d, tsid %d, up %d) status %d\n",
=======
    limLog(pMac, LOGW, "SendSmeDeltsRsp (aid %d, tsid %d, up %d) status %d",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           delts->aid,
           delts->req.tsinfo.traffic.tsid,
           delts->req.tsinfo.traffic.userPrio,
           status);
    if (! delts->rspReqd)
        return;

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&rsp, sizeof(tSirDeltsRsp)))
    {
        // Log error
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("palAllocateMemory failed for DELTS_RSP\n"));
=======
        limLog(pMac, LOGP, FL("palAllocateMemory failed for DELTS_RSP"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return;
    }
    palZeroMemory( pMac->hHdd, (tANI_U8 *) rsp, sizeof(*rsp));
  
    if(psessionEntry != NULL)
    {
        
        rsp->aid             = delts->aid;
        palCopyMemory( pMac->hHdd, (tANI_U8 *) &rsp->macAddr[0], (tANI_U8 *) &delts->macAddr[0], 6);
        palCopyMemory( pMac->hHdd, (tANI_U8 *) &rsp->rsp, (tANI_U8 *) &delts->req, sizeof(tSirDeltsReqInfo));
    } 

    
    rsp->messageType     = eWNI_SME_DELTS_RSP;
    rsp->rc              = status;

    /* Update SME session Id and transcation Id */
    rsp->sessionId = smesessionId;
    rsp->transactionId = smetransactionId;

    mmhMsg.type = eWNI_SME_DELTS_RSP;
    mmhMsg.bodyptr = rsp;
    mmhMsg.bodyval = 0;
<<<<<<< HEAD
    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
=======
    if(NULL == psessionEntry)
    {
        MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    }
    else
    {
        MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
    }
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_DELTS_RSP_EVENT, psessionEntry, (tANI_U16)status, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
}

void
limSendSmeDeltsInd(tpAniSirGlobal pMac, tpSirDeltsReqInfo delts, tANI_U16 aid,tpPESession psessionEntry)
{
    tpSirDeltsRsp rsp;
    tSirMsgQ      mmhMsg;

<<<<<<< HEAD
    limLog(pMac, LOGW, "SendSmeDeltsInd (aid %d, tsid %d, up %d)\n",
=======
    limLog(pMac, LOGW, "SendSmeDeltsInd (aid %d, tsid %d, up %d)",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           aid,
           delts->tsinfo.traffic.tsid,
           delts->tsinfo.traffic.userPrio);

    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&rsp, sizeof(tSirDeltsRsp)))
    {
        // Log error
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("palAllocateMemory failed for DELTS_IND\n"));
=======
        limLog(pMac, LOGP, FL("palAllocateMemory failed for DELTS_IND"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return;
    }
    palZeroMemory( pMac->hHdd, (tANI_U8 *) rsp, sizeof(*rsp));

    rsp->messageType     = eWNI_SME_DELTS_IND;
    rsp->rc              = eSIR_SUCCESS;
    rsp->aid             = aid;
    palCopyMemory( pMac->hHdd, (tANI_U8 *) &rsp->rsp, (tANI_U8 *) delts, sizeof(*delts));

    /* Update SME  session Id and SME transaction Id */

    rsp->sessionId = psessionEntry->smeSessionId;
    rsp->transactionId = psessionEntry->transactionId;

    mmhMsg.type = eWNI_SME_DELTS_IND;
    mmhMsg.bodyptr = rsp;
    mmhMsg.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, psessionEntry->peSessionId, mmhMsg.type));
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_DELTS_IND_EVENT, psessionEntry, 0, 0);
#endif //FEATURE_WLAN_DIAG_SUPPORT

    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
}

/**
 * limSendSmeStatsRsp()
 *
 *FUNCTION:
 * This function is called to send 802.11 statistics response to HDD.
 * This function posts the result back to HDD. This is a response to
 * HDD's request for statistics.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac         Pointer to Global MAC structure
 * @param p80211Stats  Statistics sent in response 
 * @param resultCode   TODO:
 * 
 *
 * @return none
 */

void
limSendSmeStatsRsp(tpAniSirGlobal pMac, tANI_U16 msgType, void* stats)
{
    tSirMsgQ              mmhMsg;
    tSirSmeRsp           *pMsgHdr = (tSirSmeRsp*) stats;

    switch(msgType)
    {
        case WDA_STA_STAT_RSP:
            mmhMsg.type = eWNI_SME_STA_STAT_RSP;
            break;
        case WDA_AGGR_STAT_RSP:
            mmhMsg.type = eWNI_SME_AGGR_STAT_RSP;
            break;
        case WDA_GLOBAL_STAT_RSP:
            mmhMsg.type = eWNI_SME_GLOBAL_STAT_RSP;
            break;
        case WDA_STAT_SUMM_RSP:
            mmhMsg.type = eWNI_SME_STAT_SUMM_RSP;
            break;      
        default:
            mmhMsg.type = msgType; //Response from within PE
            break;
    }

    pMsgHdr->messageType = mmhMsg.type; 

    mmhMsg.bodyptr = stats;
    mmhMsg.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);                                                  

    return;

} /*** end limSendSmeStatsRsp() ***/

/**
 * limSendSmePEStatisticsRsp()
 *
 *FUNCTION:
 * This function is called to send 802.11 statistics response to HDD.
 * This function posts the result back to HDD. This is a response to
 * HDD's request for statistics.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac         Pointer to Global MAC structure
 * @param p80211Stats  Statistics sent in response 
 * @param resultCode   TODO:
 * 
 *
 * @return none
 */

void
limSendSmePEStatisticsRsp(tpAniSirGlobal pMac, tANI_U16 msgType, void* stats)
{
    tSirMsgQ              mmhMsg;
    tANI_U8 sessionId;
    tAniGetPEStatsRsp *pPeStats = (tAniGetPEStatsRsp *) stats;
    tpPESession pPeSessionEntry;

    //Get the Session Id based on Sta Id
    pPeSessionEntry = peFindSessionByStaId(pMac, pPeStats->staId, &sessionId);

    //Fill the Session Id
    if(NULL != pPeSessionEntry)
    {
      //Fill the Session Id
      pPeStats->sessionId = pPeSessionEntry->smeSessionId;
    }
 
    pPeStats->msgType = eWNI_SME_GET_STATISTICS_RSP;
    

    //msgType should be WDA_GET_STATISTICS_RSP
    mmhMsg.type = eWNI_SME_GET_STATISTICS_RSP;

    mmhMsg.bodyptr = stats;
    mmhMsg.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);                                                  

    return;

} /*** end limSendSmePEStatisticsRsp() ***/

<<<<<<< HEAD
=======
#if defined WLAN_FEATURE_VOWIFI_11R || defined FEATURE_WLAN_CCX || defined(FEATURE_WLAN_LFR)
/**
 * limSendSmePEGetRoamRssiRsp()
 *
 *FUNCTION:
 * This function is called to send roam rssi response to HDD.
 * This function posts the result back to HDD. This is a response to
 * HDD's request to get roam rssi.
 *
 *PARAMS:
 *
 *LOGIC:
 *
 *ASSUMPTIONS:
 * NA
 *
 *NOTE:
 * NA
 *
 * @param pMac         Pointer to Global MAC structure
 * @param p80211Stats  Statistics sent in response
 * @param resultCode   TODO:
 *
 *
 * @return none
 */

void
limSendSmePEGetRoamRssiRsp(tpAniSirGlobal pMac, tANI_U16 msgType, void* stats)
{
    tSirMsgQ              mmhMsg;
    tANI_U8 sessionId;
    tAniGetRoamRssiRsp *pPeStats = (tAniGetRoamRssiRsp *) stats;
    tpPESession pPeSessionEntry = NULL;

    //Get the Session Id based on Sta Id
    pPeSessionEntry = peFindSessionByStaId(pMac, pPeStats->staId, &sessionId);

    //Fill the Session Id
    if(NULL != pPeSessionEntry)
    {
      //Fill the Session Id
      pPeStats->sessionId = pPeSessionEntry->smeSessionId;
    }

    pPeStats->msgType = eWNI_SME_GET_ROAM_RSSI_RSP;

    //msgType should be WDA_GET_STATISTICS_RSP
    mmhMsg.type = eWNI_SME_GET_ROAM_RSSI_RSP;

    mmhMsg.bodyptr = stats;
    mmhMsg.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, sessionId, mmhMsg.type));
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);

    return;

} /*** end limSendSmePEGetRoamRssiRsp() ***/

#endif

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

void
limSendSmeIBSSPeerInd(
    tpAniSirGlobal      pMac,
    tSirMacAddr peerMacAddr,
    tANI_U16    staIndex, 
    tANI_U8     ucastIdx,
    tANI_U8     bcastIdx,
    tANI_U8  *beacon, 
    tANI_U16 beaconLen, 
    tANI_U16 msgType,
    tANI_U8 sessionId)
{
    tSirMsgQ                  mmhMsg;
    tSmeIbssPeerInd *pNewPeerInd;
    
    if(eHAL_STATUS_SUCCESS !=
        palAllocateMemory(pMac->hHdd,(void * *) &pNewPeerInd,(sizeof(tSmeIbssPeerInd) + beaconLen)))
    {
        PELOGE(limLog(pMac, LOGE, FL("Failed to allocate memory"));)
        return;
    }
    
    palZeroMemory(pMac->hHdd, (void *) pNewPeerInd, (sizeof(tSmeIbssPeerInd) + beaconLen));

    palCopyMemory( pMac->hHdd, (tANI_U8 *) pNewPeerInd->peerAddr,
                   peerMacAddr, sizeof(tSirMacAddr));
    pNewPeerInd->staId= staIndex;
    pNewPeerInd->ucastSig = ucastIdx;
    pNewPeerInd->bcastSig = bcastIdx;
    pNewPeerInd->mesgLen = sizeof(tSmeIbssPeerInd) + beaconLen;
    pNewPeerInd->mesgType = msgType;
    pNewPeerInd->sessionId = sessionId;

    if ( beacon != NULL )
    {
        palCopyMemory(pMac->hHdd, (void*) ((tANI_U8*)pNewPeerInd+sizeof(tSmeIbssPeerInd)), (void*)beacon, beaconLen);
    }

    mmhMsg.type    = msgType;
//    mmhMsg.bodyval = (tANI_U32) pNewPeerInd;
    mmhMsg.bodyptr = pNewPeerInd;
<<<<<<< HEAD
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
=======
    MTRACE(macTraceMsgTx(pMac, sessionId, mmhMsg.type));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);
    
}


/** -----------------------------------------------------------------
  \brief limSendExitBmpsInd() - sends exit bmps indication
   
  This function sends a eWNI_PMC_EXIT_BMPS_IND with a specific reason
  code to SME. This will trigger SME to get out of BMPS mode. 
    
  \param pMac - global mac structure
  \param reasonCode - reason for which PE wish to exit BMPS
  \return none 
  \sa
  ----------------------------------------------------------------- */
void limSendExitBmpsInd(tpAniSirGlobal pMac, tExitBmpsReason reasonCode)
{
    tSirMsgQ  mmhMsg;
    tANI_U16  msgLen = 0;
    tpSirSmeExitBmpsInd  pExitBmpsInd;
 
    msgLen = sizeof(tSirSmeExitBmpsInd);
    if( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd, (void **)&pExitBmpsInd, msgLen ))
    {
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("palAllocateMemory failed for PMC_EXIT_BMPS_IND \n"));
=======
        limLog(pMac, LOGP, FL("palAllocateMemory failed for PMC_EXIT_BMPS_IND "));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return;
    }
    palZeroMemory(pMac->hHdd, pExitBmpsInd, msgLen);

<<<<<<< HEAD
#if defined (ANI_PRODUCT_TYPE_AP) && defined (ANI_LITTLE_BYTE_ENDIAN)
    sirStoreU16N((tANI_U8*)&pExitBmpsInd->mesgType, eWNI_PMC_EXIT_BMPS_IND);
    sirStoreU16N((tANI_U8*)&pExitBmpsInd->mesgLen, msgLen);
#else
    pExitBmpsInd->mesgType = eWNI_PMC_EXIT_BMPS_IND;
    pExitBmpsInd->mesgLen = msgLen;
#endif
=======
    pExitBmpsInd->mesgType = eWNI_PMC_EXIT_BMPS_IND;
    pExitBmpsInd->mesgLen = msgLen;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    pExitBmpsInd->exitBmpsReason = reasonCode;
    pExitBmpsInd->statusCode = eSIR_SME_SUCCESS;

    mmhMsg.type = eWNI_PMC_EXIT_BMPS_IND;
    mmhMsg.bodyptr = pExitBmpsInd;
    mmhMsg.bodyval = 0;
  
<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("Sending eWNI_PMC_EXIT_BMPS_IND to SME. \n"));)        
=======
    PELOG1(limLog(pMac, LOG1, FL("Sending eWNI_PMC_EXIT_BMPS_IND to SME. "));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
#ifdef FEATURE_WLAN_DIAG_SUPPORT_LIM //FEATURE_WLAN_DIAG_SUPPORT 
    limDiagEventReport(pMac, WLAN_PE_DIAG_EXIT_BMPS_IND_EVENT, peGetValidPowerSaveSession(pMac), 0, (tANI_U16)reasonCode);
#endif //FEATURE_WLAN_DIAG_SUPPORT
    
    limSysProcessMmhMsgApi(pMac, &mmhMsg,  ePROT);
    return;

} /*** end limSendExitBmpsInd() ***/




/*--------------------------------------------------------------------------
  \brief peDeleteSession() - Handle the Delete BSS Response from HAL.

    
  \param pMac                   - pointer to global adapter context
  \param sessionId             - Message pointer.
    
  \sa
  --------------------------------------------------------------------------*/

void limHandleDeleteBssRsp(tpAniSirGlobal pMac,tpSirMsgQ MsgQ)
{
    tpPESession psessionEntry;
    tpDeleteBssParams pDelBss = (tpDeleteBssParams)(MsgQ->bodyptr);
    if((psessionEntry = peFindSessionBySessionId(pMac,pDelBss->sessionId))==NULL)
    {
<<<<<<< HEAD
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID\n"));
=======
        limLog(pMac, LOGP,FL("Session Does not exist for given sessionID"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return;
    }
    if (psessionEntry->limSystemRole == eLIM_STA_IN_IBSS_ROLE)
    {
        limIbssDelBssRsp(pMac, MsgQ->bodyptr,psessionEntry);
    }    
    else if(psessionEntry->limSystemRole == eLIM_UNKNOWN_ROLE)
    {
         limProcessSmeDelBssRsp(pMac, MsgQ->bodyval,psessionEntry);
    }
           
    else
         limProcessMlmDelBssRsp(pMac,MsgQ,psessionEntry);
    
}

#ifdef WLAN_FEATURE_VOWIFI_11R
/** -----------------------------------------------------------------
  \brief limSendSmeAggrQosRsp() - sends SME FT AGGR QOS RSP    
  \      This function sends a eWNI_SME_FT_AGGR_QOS_RSP to SME.   
  \      SME only looks at rc and tspec field. 
  \param pMac - global mac structure
  \param rspReqd - is SmeAddTsRsp required
  \param status - status code of eWNI_SME_FT_AGGR_QOS_RSP
  \return tspec
  \sa
  ----------------------------------------------------------------- */
void
limSendSmeAggrQosRsp(tpAniSirGlobal pMac, tpSirAggrQosRsp aggrQosRsp, 
                     tANI_U8 smesessionId)
{
    tSirMsgQ         mmhMsg;

    mmhMsg.type = eWNI_SME_FT_AGGR_QOS_RSP;
    mmhMsg.bodyptr = aggrQosRsp;
    mmhMsg.bodyval = 0;
<<<<<<< HEAD
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
=======
    MTRACE(macTraceMsgTx(pMac, smesessionId , mmhMsg.type));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);

    return;
}
#endif

/** -----------------------------------------------------------------
  \brief limSendSmePreChannelSwitchInd() - sends an indication to SME 
  before switching channels for spectrum manangement.
   
  This function sends a eWNI_SME_PRE_SWITCH_CHL_IND to SME.
    
  \param pMac - global mac structure
  \return none 
  \sa
  ----------------------------------------------------------------- */
void
limSendSmePreChannelSwitchInd(tpAniSirGlobal pMac)
{
    tSirMsgQ         mmhMsg;

    mmhMsg.type = eWNI_SME_PRE_SWITCH_CHL_IND;
    mmhMsg.bodyptr = NULL;
    mmhMsg.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);

    return;
}

/** -----------------------------------------------------------------
  \brief limSendSmePostChannelSwitchInd() - sends an indication to SME 
  after channel switch for spectrum manangement is complete.
   
  This function sends a eWNI_SME_POST_SWITCH_CHL_IND to SME.
    
  \param pMac - global mac structure
  \return none 
  \sa
  ----------------------------------------------------------------- */
void
limSendSmePostChannelSwitchInd(tpAniSirGlobal pMac)
{
    tSirMsgQ         mmhMsg;

    mmhMsg.type = eWNI_SME_POST_SWITCH_CHL_IND;
    mmhMsg.bodyptr = NULL;
    mmhMsg.bodyval = 0;
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);

    return;
}

void limSendSmeMaxAssocExceededNtf(tpAniSirGlobal pMac, tSirMacAddr peerMacAddr,
                    tANI_U8 smesessionId)
{
    tSirMsgQ         mmhMsg;
    tSmeMaxAssocInd *pSmeMaxAssocInd;

    if(eHAL_STATUS_SUCCESS !=
            palAllocateMemory(pMac->hHdd,(void **)&pSmeMaxAssocInd, sizeof(tSmeMaxAssocInd)))
    {
        PELOGE(limLog(pMac, LOGE, FL("Failed to allocate memory"));)
        return;
    }    
    palZeroMemory(pMac->hHdd, (void *) pSmeMaxAssocInd, sizeof(tSmeMaxAssocInd));
    palCopyMemory( pMac->hHdd, (tANI_U8 *)pSmeMaxAssocInd->peerMac,
            (tANI_U8 *)peerMacAddr, sizeof(tSirMacAddr));
    pSmeMaxAssocInd->mesgType  = eWNI_SME_MAX_ASSOC_EXCEEDED;
    pSmeMaxAssocInd->mesgLen    = sizeof(tSmeMaxAssocInd); 
    pSmeMaxAssocInd->sessionId = smesessionId;
    mmhMsg.type = pSmeMaxAssocInd->mesgType;
    mmhMsg.bodyptr = pSmeMaxAssocInd;
    PELOG1(limLog(pMac, LOG1, FL("msgType %s peerMacAddr %02x-%02x-%02x-%02x-%02x-%02x"
<<<<<<< HEAD
                "sme session id %d\n"),"eWNI_SME_MAX_ASSOC_EXCEEDED", peerMacAddr[0], peerMacAddr[1],
                peerMacAddr[2], peerMacAddr[3], peerMacAddr[4], peerMacAddr[5], smesessionId);)
    MTRACE(macTraceMsgTx(pMac, NO_SESSION, mmhMsg.type));
=======
                "sme session id %d"),"eWNI_SME_MAX_ASSOC_EXCEEDED", peerMacAddr[0], peerMacAddr[1],
                peerMacAddr[2], peerMacAddr[3], peerMacAddr[4], peerMacAddr[5], smesessionId);)
    MTRACE(macTraceMsgTx(pMac, smesessionId, mmhMsg.type));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);

    return;
}
<<<<<<< HEAD
=======
#ifdef WLAN_FEATURE_ROAM_SCAN_OFFLOAD
/** -----------------------------------------------------------------
  \brief limSendSmeCandidateFoundInd() - sends
         eWNI_SME_CANDIDATE_FOUND_IND

  After receiving candidate found indication frame from FW, this
  function sends a eWNI_SME_CANDIDATE_FOUND_IND to SME to notify
  roam candidate(s) are available.

  \param pMac - global mac structure
  \param psessionEntry - session info
  \return none
  \sa
  ----------------------------------------------------------------- */
void
limSendSmeCandidateFoundInd(tpAniSirGlobal pMac, tANI_U8  sessionId)
{
    tSirMsgQ  mmhMsg;
    tSirSmeCandidateFoundInd *pSirSmeCandidateFoundInd;

    if ( eHAL_STATUS_SUCCESS != palAllocateMemory( pMac->hHdd,
                                             (void **)&pSirSmeCandidateFoundInd,
                                             sizeof(tSirSmeCandidateFoundInd)))
    {
        limLog(pMac, LOGP, FL("palAllocateMemory failed for eWNI_SME_CANDIDATE_FOUND_IND\n"));
        return;
    }

    pSirSmeCandidateFoundInd->messageType = eWNI_SME_CANDIDATE_FOUND_IND;
    pSirSmeCandidateFoundInd->length = sizeof(tSirSmeDisassocInd);

    pSirSmeCandidateFoundInd->sessionId     =  sessionId;


    limLog( pMac, LOGE, FL("posting candidate ind to SME"));
    mmhMsg.type = eWNI_SME_CANDIDATE_FOUND_IND;
    mmhMsg.bodyptr = pSirSmeCandidateFoundInd;
    mmhMsg.bodyval = 0;

    limSysProcessMmhMsgApi(pMac, &mmhMsg, ePROT);

} /*** end limSendSmeCandidateFoundInd() ***/
#endif //WLAN_FEATURE_ROAM_SCAN_OFFLOAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
