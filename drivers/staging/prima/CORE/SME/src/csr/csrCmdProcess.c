/*
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
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
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
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

/** ------------------------------------------------------------------------- * 
    ------------------------------------------------------------------------- *  
<<<<<<< HEAD
<<<<<<< HEAD
    \file csrCmdProcess.c
  
    Implementation for processing various commands.
  
   Copyright (C) 2006 Airgo Networks, Incorporated
 
   ========================================================================== */


#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
#include "halInternal.h" //Check if the below include of aniGobal.h is sufficient for Volans too.
#endif

#ifdef FEATURE_WLAN_INTEGRATED_SOC
#include "aniGlobal.h"
#endif
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
 
    Copyright (C) 2006 Airgo Networks, Incorporated

   ---------------------------------------------------------------------------*
*/

#include "aniGlobal.h"
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

#include "palApi.h"
#include "csrInsideApi.h"
#include "smeInside.h"
#include "smsDebug.h"




eHalStatus csrMsgProcessor( tpAniSirGlobal pMac,  void *pMsgBuf )
{
    eHalStatus status = eHAL_STATUS_SUCCESS;
    tSirSmeRsp *pSmeRsp = (tSirSmeRsp *)pMsgBuf;

<<<<<<< HEAD
<<<<<<< HEAD
    smsLog( pMac, LOG2, "  Message %d[0x%04X] received in curState %d and substate %d\n",
=======
    smsLog( pMac, LOG2, "  Message %d[0x%04X] received in curState %d and substate %d",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    smsLog( pMac, LOG2, "  Message %d[0x%04X] received in curState %d and substate %d",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                pSmeRsp->messageType, pSmeRsp->messageType, 
                pMac->roam.curState[pSmeRsp->sessionId],
                pMac->roam.curSubState[pSmeRsp->sessionId] );

    // Process the message based on the state of the roaming states...
    
#if defined( ANI_RTT_DEBUG )
    if(!pAdapter->fRttModeEnabled)
    {
#endif//RTT    
        switch (pMac->roam.curState[pSmeRsp->sessionId])
        {
        case eCSR_ROAMING_STATE_SCANNING: 
        {
            //Are we in scan state
#if defined( ANI_EMUL_ASSOC )
            emulScanningStateMsgProcessor( pAdapter, pMBBufHdr );
#else
            status = csrScanningStateMsgProcessor(pMac, pMsgBuf);
#endif    
            break;
        }
        
        case eCSR_ROAMING_STATE_JOINED: 
        {
            //are we in joined state
            csrRoamJoinedStateMsgProcessor( pMac, pMsgBuf );
            break;
        }
        
        case eCSR_ROAMING_STATE_JOINING:
        {
            //are we in roaming states
#if defined( ANI_EMUL_ASSOC )
            emulRoamingStateMsgProcessor( pAdapter, pMBBufHdr );
#endif
            csrRoamingStateMsgProcessor( pMac, pMsgBuf );
            break;
        }

        //For all other messages, we ignore it        
        default:
        {
            /*To work-around an issue where checking for set/remove key base on connection state is no longer 
            * workable due to failure or finding the condition meets both SAP and infra/IBSS requirement.
            */
            if( (eWNI_SME_SETCONTEXT_RSP == pSmeRsp->messageType) ||
                (eWNI_SME_REMOVEKEY_RSP == pSmeRsp->messageType) )
            {
<<<<<<< HEAD
<<<<<<< HEAD
                smsLog(pMac, LOGW, FL(" handling msg 0x%X CSR state is %d\n"), pSmeRsp->messageType, pMac->roam.curState[pSmeRsp->sessionId]);
=======
                smsLog(pMac, LOGW, FL(" handling msg 0x%X CSR state is %d"), pSmeRsp->messageType, pMac->roam.curState[pSmeRsp->sessionId]);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                smsLog(pMac, LOGW, FL(" handling msg 0x%X CSR state is %d"), pSmeRsp->messageType, pMac->roam.curState[pSmeRsp->sessionId]);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                csrRoamCheckForLinkStatusChange(pMac, pSmeRsp);
            }
            else
            {
<<<<<<< HEAD
<<<<<<< HEAD
                smsLog(pMac, LOGW, "  Message 0x%04X is not handled by CSR. CSR state is %d \n", pSmeRsp->messageType, pMac->roam.curState[pSmeRsp->sessionId]);
=======
                smsLog(pMac, LOGW, "  Message 0x%04X is not handled by CSR. CSR state is %d ", pSmeRsp->messageType, pMac->roam.curState[pSmeRsp->sessionId]);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                smsLog(pMac, LOGW, "  Message 0x%04X is not handled by CSR. CSR state is %d ", pSmeRsp->messageType, pMac->roam.curState[pSmeRsp->sessionId]);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            }
            break;
        }
        
        }//switch
        
#if defined( ANI_RTT_DEBUG )
    }
#endif//RTT

    return (status);
}



tANI_BOOLEAN csrCheckPSReady(void *pv)
{
    tpAniSirGlobal pMac = PMAC_STRUCT( pv );

    VOS_ASSERT( pMac->roam.sPendingCommands >= 0 );
    return (pMac->roam.sPendingCommands == 0);
}


void csrFullPowerCallback(void *pv, eHalStatus status)
{
    tpAniSirGlobal pMac = PMAC_STRUCT( pv );
    tListElem *pEntry;
    tSmeCmd *pCommand;

    (void)status;
    
    while( NULL != ( pEntry = csrLLRemoveHead( &pMac->roam.roamCmdPendingList, eANI_BOOLEAN_TRUE ) ) )
    {
        pCommand = GET_BASE_ADDR( pEntry, tSmeCmd, Link );
        smePushCommand( pMac, pCommand, eANI_BOOLEAN_FALSE );
    }

}


