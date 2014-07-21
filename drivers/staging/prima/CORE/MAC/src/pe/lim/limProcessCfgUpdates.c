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

/*
 * Airgo Networks, Inc proprietary. All rights reserved.
 * This file limProcessCfgUpdates.cc contains the utility functions
 * to handle various CFG parameter update events
 * Author:        Chandra Modumudi
 * Date:          01/20/03
 * History:-
 * Date           Modified by    Modification Information
 * --------------------------------------------------------------------
 */

#include "aniGlobal.h"

<<<<<<< HEAD
<<<<<<< HEAD
#if (WNI_POLARIS_FW_PRODUCT == AP)
#include "wniCfgAp.h"
#else
#include "wniCfgSta.h"
#endif
=======
#include "wniCfgSta.h"
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#include "wniCfgSta.h"
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#include "sirMacProtDef.h"
#include "cfgApi.h"
#include "limTypes.h"
#include "limUtils.h"
#include "limPropExtsUtils.h"
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
#include "halCommonApi.h"
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#include "schApi.h"
#include "pmmApi.h"
#if defined WLAN_FEATURE_VOWIFI
#include "rrmApi.h"
#endif

static void limUpdateConfig(tpAniSirGlobal pMac,tpPESession psessionEntry);

#if 0
/**
 * limGetCfgIdOfDefaultKeyid()
 *
 *FUNCTION:
 * This function is called to get CFG ID of default key id
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
 * @param  dkid     - Value of default key id
 * @return dkCfgId  - CFG ID of key corresponding to default key Id
 */

static tANI_U32
limGetCfgIdOfDefaultKeyid(tANI_U32 dkid)
{
    if (dkid == WNI_CFG_WEP_DEFAULT_KEYID_0)
        return WNI_CFG_WEP_DEFAULT_KEY_1;
    else if (dkid == WNI_CFG_WEP_DEFAULT_KEYID_1)
        return WNI_CFG_WEP_DEFAULT_KEY_2;
    else if (dkid == WNI_CFG_WEP_DEFAULT_KEYID_2)
        return WNI_CFG_WEP_DEFAULT_KEY_3;
    else // dkid == WNI_CFG_WEP_DEFAULT_KEYID_3
        return WNI_CFG_WEP_DEFAULT_KEY_4;
} /*** end limGetCfgIdOfDefaultKeyid() ***/
#endif


/**
 * limSetDefaultKeyIdAndKeys()
 *
 *FUNCTION:
 * This function is called while applying configuration
 * during JOIN/REASSOC/START_BSS.
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
 * @param  pMac  - Pointer to Global MAC structure
 * @return None
 */

static void
limSetDefaultKeyIdAndKeys(tpAniSirGlobal pMac)
{
#ifdef FIXME_GEN6
    tANI_U32 val;
    tANI_U32 dkCfgId;

<<<<<<< HEAD
<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("Setting default keys at SP\n"));)
=======
    PELOG1(limLog(pMac, LOG1, FL("Setting default keys at SP"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    PELOG1(limLog(pMac, LOG1, FL("Setting default keys at SP"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    if (wlan_cfgGetInt(pMac, WNI_CFG_WEP_DEFAULT_KEYID,
                  &val) != eSIR_SUCCESS)
    {
        limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("Unable to retrieve defaultKeyId from CFG\n"));
=======
               FL("Unable to retrieve defaultKeyId from CFG"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
               FL("Unable to retrieve defaultKeyId from CFG"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
    dkCfgId = limGetCfgIdOfDefaultKeyid(val);
#endif

} /*** end limSetDefaultKeyIdAndKeys() ***/

/** -------------------------------------------------------------
\fn limSetCfgProtection
\brief sets lim global cfg cache from the config.
\param      tpAniSirGlobal    pMac
\return      None
  -------------------------------------------------------------*/
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
void limSetCfgProtection(tpAniSirGlobal pMac, tpPESession pesessionEntry)
#else
void limSetCfgProtection(tpAniSirGlobal pMac)
#endif
{
    tANI_U32 val = 0;

#ifdef WLAN_SOFTAP_FEATURE
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
void limSetCfgProtection(tpAniSirGlobal pMac, tpPESession pesessionEntry)
{
    tANI_U32 val = 0;

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if(( pesessionEntry != NULL ) && (pesessionEntry->limSystemRole == eLIM_AP_ROLE )){
        if (pesessionEntry->gLimProtectionControl == WNI_CFG_FORCE_POLICY_PROTECTION_DISABLE )
            palZeroMemory( pMac->hHdd, (void *)&pesessionEntry->cfgProtection , sizeof(tCfgProtection));
        else{
            limLog(pMac, LOG1, FL(" frm11a = %d, from11b = %d, frm11g = %d, "
                                    "ht20 = %d, nongf = %d, lsigTxop = %d, "
<<<<<<< HEAD
<<<<<<< HEAD
                                    "rifs = %d, obss = %d\n"),    
=======
                                    "rifs = %d, obss = %d"),
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                                    "rifs = %d, obss = %d"),
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                                    pesessionEntry->cfgProtection.fromlla,
                                    pesessionEntry->cfgProtection.fromllb,
                                    pesessionEntry->cfgProtection.fromllg,
                                    pesessionEntry->cfgProtection.ht20,
                                    pesessionEntry->cfgProtection.nonGf,
                                    pesessionEntry->cfgProtection.lsigTxop,
                                    pesessionEntry->cfgProtection.rifs,
                                    pesessionEntry->cfgProtection.obss);
        }
    }
    else{
<<<<<<< HEAD
<<<<<<< HEAD
#endif
    if (wlan_cfgGetInt(pMac, WNI_CFG_FORCE_POLICY_PROTECTION, &val) != eSIR_SUCCESS)
    {
        limLog(pMac, LOGP, FL("reading WNI_CFG_FORCE_POLICY_PROTECTION cfg failed\n"));
=======
    if (wlan_cfgGetInt(pMac, WNI_CFG_FORCE_POLICY_PROTECTION, &val) != eSIR_SUCCESS)
    {
        limLog(pMac, LOGP, FL("reading WNI_CFG_FORCE_POLICY_PROTECTION cfg failed"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    if (wlan_cfgGetInt(pMac, WNI_CFG_FORCE_POLICY_PROTECTION, &val) != eSIR_SUCCESS)
    {
        limLog(pMac, LOGP, FL("reading WNI_CFG_FORCE_POLICY_PROTECTION cfg failed"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return;
    }
    else
        pMac->lim.gLimProtectionControl = (tANI_U8)val;

    if (wlan_cfgGetInt(pMac, WNI_CFG_PROTECTION_ENABLED, &val) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("reading protection cfg failed\n"));
=======
        limLog(pMac, LOGP, FL("reading protection cfg failed"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        limLog(pMac, LOGP, FL("reading protection cfg failed"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return;
    }

    if(pMac->lim.gLimProtectionControl == WNI_CFG_FORCE_POLICY_PROTECTION_DISABLE)
        palZeroMemory( pMac->hHdd, (void *)&pMac->lim.cfgProtection , sizeof(tCfgProtection));
    else
        {
<<<<<<< HEAD
<<<<<<< HEAD
#if (defined(ANI_PRODUCT_TYPE_AP) || defined(ANI_PRODUCT_TYPE_AP_SDK))
            {
                pMac->lim.cfgProtection.overlapFromlla = (val >> WNI_CFG_PROTECTION_ENABLED_OLBC_FROM_llA) & 1;
                pMac->lim.cfgProtection.overlapFromllb = (val >> WNI_CFG_PROTECTION_ENABLED_OLBC_FROM_llB) & 1;
                pMac->lim.cfgProtection.overlapFromllg = (val >> WNI_CFG_PROTECTION_ENABLED_OLBC_FROM_llG) & 1;
                pMac->lim.cfgProtection.overlapHt20 = (val >> WNI_CFG_PROTECTION_ENABLED_OLBC_HT20) & 1;
                pMac->lim.cfgProtection.overlapNonGf = (val >> WNI_CFG_PROTECTION_ENABLED_OLBC_NON_GF) & 1;
                pMac->lim.cfgProtection.overlapLsigTxop = (val >> WNI_CFG_PROTECTION_ENABLED_OLBC_LSIG_TXOP) & 1;
                pMac->lim.cfgProtection.overlapRifs = (val >> WNI_CFG_PROTECTION_ENABLED_OLBC_RIFS) & 1;
                pMac->lim.cfgProtection.overlapOBSS = (val>> WNI_CFG_PROTECTION_ENABLED_OLBC_OBSS )&1;

            }
            #endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            pMac->lim.cfgProtection.fromlla = (val >> WNI_CFG_PROTECTION_ENABLED_FROM_llA) & 1;
            pMac->lim.cfgProtection.fromllb = (val >> WNI_CFG_PROTECTION_ENABLED_FROM_llB) & 1;
            pMac->lim.cfgProtection.fromllg = (val >> WNI_CFG_PROTECTION_ENABLED_FROM_llG) & 1;
            pMac->lim.cfgProtection.ht20 = (val >> WNI_CFG_PROTECTION_ENABLED_HT_20) & 1;
            pMac->lim.cfgProtection.nonGf = (val >> WNI_CFG_PROTECTION_ENABLED_NON_GF) & 1;
            pMac->lim.cfgProtection.lsigTxop = (val >> WNI_CFG_PROTECTION_ENABLED_LSIG_TXOP) & 1;
            pMac->lim.cfgProtection.rifs = (val >> WNI_CFG_PROTECTION_ENABLED_RIFS) & 1;
            pMac->lim.cfgProtection.obss= (val >> WNI_CFG_PROTECTION_ENABLED_OBSS) & 1;

        }
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
}
#endif
=======
    }
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    }
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
}



/**
 * limUpdateTriggerStaBkScanFlag
 *
 * FUNCTION:
 * This function updates the lim global gLimTriggerBackgroundScanDuringQuietBss
 * based on cfg configuration.  Usually triggered after a cfgSetInt call.
 *
 * PARAMS:
 * pMac       - Pointer to Global MAC structure
 *
 */
static tSirRetStatus limUpdateTriggerStaBkScanFlag(tpAniSirGlobal pMac)
{
    tANI_U32 val;
    tANI_U8 flag;

    if(wlan_cfgGetInt(pMac, WNI_CFG_TRIG_STA_BK_SCAN, &val) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN from cfg\n"));)
=======
    PELOG1(limLog(pMac, LOG1, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN from cfg"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    PELOG1(limLog(pMac, LOG1, FL("Failed to get WNI_CFG_TRIG_STA_BK_SCAN from cfg"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    return eSIR_FAILURE;
    }

    flag = (val) ? 1 : 0;
    if(flag != pMac->lim.gLimTriggerBackgroundScanDuringQuietBss)
    {
        /* Update global flag */
        pMac->lim.gLimTriggerBackgroundScanDuringQuietBss = flag;
        /*Update beacon prop IE also if we're an AP */

        //call a wrapper and if the session role is other than the sta call this function schsetfixedbeacon fields function
        limUpdateBeacon(pMac);

    }

    return eSIR_FAILURE;
}


/**
 * limHandleCFGparamUpdate()
 *
 *FUNCTION:
 * This function is called by limProcessMessages() to
 * whenever SIR_CFG_PARAM_UPDATE_IND message is posted
 * to LIM (due to a set operation on a CFG parameter).
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
 * @param  pMac  - Pointer to Global MAC structure
 * @param  cfgId - ID of CFG parameter that got updated
 * @return None
 */

void
limHandleCFGparamUpdate(tpAniSirGlobal pMac, tANI_U32 cfgId)
{
    tANI_U32 val1, val2;
    tANI_U16 val16;
    tSirMacHTCapabilityInfo   *pHTCapabilityInfo;
    tSirMacHTParametersInfo *pAmpduParamInfo;

<<<<<<< HEAD
<<<<<<< HEAD
    PELOG3(limLog(pMac, LOG3, FL("Handling CFG parameter id %X update\n"), cfgId);)
=======
    PELOG3(limLog(pMac, LOG3, FL("Handling CFG parameter id %X update"), cfgId);)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    PELOG3(limLog(pMac, LOG3, FL("Handling CFG parameter id %X update"), cfgId);)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    switch (cfgId)
    {
        case WNI_CFG_WEP_DEFAULT_KEYID:

            // !!LAC - when the default KeyID is changed, force all of the
            // keys and the keyID to be reprogrammed.  this allows the
            // keys to change after the initial setting of the keys when the CFG was
            // applied at association time through CFG changes of the keys.
            limSetDefaultKeyIdAndKeys( pMac );

            break;

        case WNI_CFG_EXCLUDE_UNENCRYPTED:
            if (wlan_cfgGetInt(pMac, WNI_CFG_EXCLUDE_UNENCRYPTED,
                          &val1) != eSIR_SUCCESS)
            {
                limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("Unable to retrieve excludeUnencr from CFG\n"));
=======
                   FL("Unable to retrieve excludeUnencr from CFG"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                   FL("Unable to retrieve excludeUnencr from CFG"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            }
#if 0
            halSetSpExclUndecrypted(pMac, (tHalBitVal) val);
#else
            limLog(pMac, LOGE,
<<<<<<< HEAD
<<<<<<< HEAD
                   FL("Unsupported CFG: WNI_CFG_EXCLUDE_UNENCRYPTED\n"));
=======
                   FL("Unsupported CFG: WNI_CFG_EXCLUDE_UNENCRYPTED"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                   FL("Unsupported CFG: WNI_CFG_EXCLUDE_UNENCRYPTED"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#endif

            break;

        case WNI_CFG_ASSOCIATION_FAILURE_TIMEOUT:
            if (pMac->lim.gLimMlmState != eLIM_MLM_WT_ASSOC_RSP_STATE)
            {
                // 'Change' timer for future activations
                limDeactivateAndChangeTimer(pMac,
                                            eLIM_ASSOC_FAIL_TIMER);
            }

            break;

<<<<<<< HEAD
<<<<<<< HEAD
#if (WNI_POLARIS_FW_PRODUCT == WLAN_STA) || defined(ANI_AP_CLIENT_SDK)
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        case WNI_CFG_BACKGROUND_SCAN_PERIOD:


            limDeactivateAndChangeTimer(pMac, eLIM_BACKGROUND_SCAN_TIMER);

            if (wlan_cfgGetInt(pMac, WNI_CFG_BACKGROUND_SCAN_PERIOD, &val1) != eSIR_SUCCESS)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                limLog(pMac, LOGP,  FL("could not retrieve Background scan period value\n"));
=======
                limLog(pMac, LOGP,  FL("could not retrieve Background scan period value"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                limLog(pMac, LOGP,  FL("could not retrieve Background scan period value"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }
            if (val1 == 0)
                break;



            if ( (pMac->lim.gLimSystemRole == eLIM_STA_ROLE) ||
                 ( (pMac->lim.gLimSystemRole == eLIM_STA_IN_IBSS_ROLE) &&
                   (pMac->lim.gLimSmeState == eLIM_SME_NORMAL_STATE)))
            {
                // Reactivate Background scan timer
                MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, NO_SESSION, eLIM_BACKGROUND_SCAN_TIMER));
                if (tx_timer_activate(
                      &pMac->lim.limTimers.gLimBackgroundScanTimer) != TX_SUCCESS)
                {
                    /// Could not activate background scan timer.
                    // Log error
                    limLog(pMac, LOGP,
<<<<<<< HEAD
<<<<<<< HEAD
                      FL("could not activate background scan timer\n"));
=======
                      FL("could not activate background scan timer"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                      FL("could not activate background scan timer"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                    pMac->lim.gLimBackgroundScanStarted = FALSE;
                    pMac->lim.gLimBackgroundScanTerminate = TRUE;
                }
                else
                {
                    pMac->lim.gLimBackgroundScanStarted = TRUE;
                    pMac->lim.gLimBackgroundScanTerminate = FALSE;
                }
               
               PELOG3(limLog(pMac, LOG3,
<<<<<<< HEAD
<<<<<<< HEAD
                       FL("Updated Background scan period\n"));)
            }
            
            break;
#endif
#if (WNI_POLARIS_FW_PRODUCT == AP)
        case WNI_CFG_PREAUTH_CLNUP_TIMEOUT:
            if (pMac->lim.gLimSystemRole == eLIM_AP_ROLE)
            {
                limDeactivateAndChangeTimer(pMac,
                                           eLIM_PRE_AUTH_CLEANUP_TIMER);

#ifdef GEN6_TODO
                /* revisit this piece of code to assign the appropriate sessionId below
                 * priority - MEDIUM
                 */
                pMac->lim.limTimers.gLimPreAuthClnupTimer.sessionId = sessionId;
#endif
                // Reactivate pre-auth cleanup timer
                MTRACE(macTrace(pMac, TRACE_CODE_TIMER_ACTIVATE, NO_SESSION, eLIM_PRE_AUTH_CLEANUP_TIMER));
                if (tx_timer_activate(&pMac->lim.limTimers.gLimPreAuthClnupTimer)
                                                       != TX_SUCCESS)
                {
                    /// Could not activate pre-auth cleanup timer.
                    // Log error
                    limLog(pMac, LOGP,
                      FL("could not activate preauth cleanup timer\n"));
                }
               PELOG3(limLog(pMac, LOG3,
                       FL("Updated pre-auth cleanup timeout\n"));)
            }

            break;

#endif

        case WNI_CFG_BG_SCAN_CHANNEL_LIST:
#if (WNI_POLARIS_FW_PRODUCT == WLAN_STA) || defined(ANI_AP_CLIENT_SDK)
            PELOG1(limLog(pMac, LOG1,
               FL("VALID_CHANNEL_LIST has changed, reset next bg scan channel\n"));)
            pMac->lim.gLimBackgroundScanChannelId = 0;
#endif
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                       FL("Updated Background scan period"));)
            }
            
            break;

        case WNI_CFG_BG_SCAN_CHANNEL_LIST:
            PELOG1(limLog(pMac, LOG1,
               FL("VALID_CHANNEL_LIST has changed, reset next bg scan channel"));)
            pMac->lim.gLimBackgroundScanChannelId = 0;
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

            break;

    case WNI_CFG_TRIG_STA_BK_SCAN:
        if(limUpdateTriggerStaBkScanFlag(pMac) != eSIR_SUCCESS)
        {
       PELOG2(limLog(pMac, LOG2,
<<<<<<< HEAD
<<<<<<< HEAD
               FL("Updating lim trigger sta bk scan global flag failed!\n"));)
=======
               FL("Updating lim trigger sta bk scan global flag failed!"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
               FL("Updating lim trigger sta bk scan global flag failed!"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        }
        break;

    case WNI_CFG_PROTECTION_ENABLED:
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
        limSetCfgProtection(pMac, NULL);
#else
        limSetCfgProtection(pMac);
#endif
=======
        limSetCfgProtection(pMac, NULL);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        limSetCfgProtection(pMac, NULL);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        break;
    case WNI_CFG_PROBE_RSP_BCN_ADDNIE_FLAG:
    {
        tSirMsgQ msg = {0};
        tANI_U32 status;

        msg.type = SIR_LIM_UPDATE_BEACON;

        status = limPostMsgApi(pMac, &msg);

        if (status != TX_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("Failed limPostMsgApi\n"), status);)
=======
            PELOGE(limLog(pMac, LOGE, FL("Failed limPostMsgApi"), status);)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("Failed limPostMsgApi"), status);)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        break;
    }
    case WNI_CFG_GREENFIELD_CAPABILITY:
        if (wlan_cfgGetInt(pMac, WNI_CFG_HT_CAP_INFO, &val1) != eSIR_SUCCESS) 
        {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap Info CFG\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;
        }
        if (wlan_cfgGetInt(pMac, WNI_CFG_GREENFIELD_CAPABILITY, &val2) != eSIR_SUCCESS) 
        {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve GreenField CFG\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve GreenField CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve GreenField CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;
        }
        val16 = ( tANI_U16 ) val1;
        pHTCapabilityInfo = ( tSirMacHTCapabilityInfo* ) &val16;
        pHTCapabilityInfo->greenField = (tANI_U16)val2;
        if(cfgSetInt(pMac, WNI_CFG_HT_CAP_INFO, *(tANI_U16*)pHTCapabilityInfo) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        break;

    case WNI_CFG_HT_RX_STBC:
        if (wlan_cfgGetInt(pMac, WNI_CFG_HT_CAP_INFO, &val1) != eSIR_SUCCESS) 
        {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve WNI_CFG_HT_CAP_INFO \n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve WNI_CFG_HT_CAP_INFO "));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve WNI_CFG_HT_CAP_INFO "));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;
        }
        if (wlan_cfgGetInt(pMac, WNI_CFG_HT_RX_STBC, &val2) != eSIR_SUCCESS) 
        {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve WNI_CFG_HT_RX_STBC\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve WNI_CFG_HT_RX_STBC"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve WNI_CFG_HT_RX_STBC"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;
        }
        val16 = ( tANI_U16 ) val1;
        pHTCapabilityInfo = ( tSirMacHTCapabilityInfo* ) &val16;
        pHTCapabilityInfo->rxSTBC = (tANI_U16)val2;
        if(cfgSetInt(pMac, WNI_CFG_HT_CAP_INFO, *(tANI_U16*)pHTCapabilityInfo) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        break;

    case WNI_CFG_MAX_AMSDU_LENGTH:
        if (wlan_cfgGetInt(pMac, WNI_CFG_HT_CAP_INFO, &val1) != eSIR_SUCCESS)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap Info CFG\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }
        if (wlan_cfgGetInt(pMac, WNI_CFG_MAX_AMSDU_LENGTH, &val2) != eSIR_SUCCESS)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve Max AMSDU Length CFG\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve Max AMSDU Length CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve Max AMSDU Length CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }
        val16 = ( tANI_U16 ) val1;
        pHTCapabilityInfo = ( tSirMacHTCapabilityInfo* ) &val16;
        pHTCapabilityInfo->maximalAMSDUsize = (tANI_U16)val2;
        if(cfgSetInt(pMac, WNI_CFG_HT_CAP_INFO, *(tANI_U16*)pHTCapabilityInfo) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        break;

    case WNI_CFG_SHORT_GI_20MHZ:
        if (wlan_cfgGetInt(pMac, WNI_CFG_HT_CAP_INFO, &val1) != eSIR_SUCCESS) 
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap CFG\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }
        if (wlan_cfgGetInt(pMac, WNI_CFG_SHORT_GI_20MHZ, &val2) != eSIR_SUCCESS) 
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve shortGI 20Mhz CFG\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve shortGI 20Mhz CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve shortGI 20Mhz CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }
        val16 = ( tANI_U16 ) val1;
        pHTCapabilityInfo = ( tSirMacHTCapabilityInfo* ) &val16;
        pHTCapabilityInfo->shortGI20MHz = (tANI_U16)val2;
        if(cfgSetInt(pMac,  WNI_CFG_HT_CAP_INFO, *(tANI_U16*)pHTCapabilityInfo) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        break;
    case WNI_CFG_SHORT_GI_40MHZ:
        if (wlan_cfgGetInt(pMac, WNI_CFG_HT_CAP_INFO, &val1) != eSIR_SUCCESS) 
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap CFG\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT Cap CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }
        if (wlan_cfgGetInt(pMac, WNI_CFG_SHORT_GI_40MHZ, &val2) != eSIR_SUCCESS) 
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve shortGI 40Mhz CFG\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve shortGI 40Mhz CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve shortGI 40Mhz CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }
        val16 = ( tANI_U16 ) val1;
        pHTCapabilityInfo = ( tSirMacHTCapabilityInfo* ) &val16;
        pHTCapabilityInfo->shortGI40MHz = (tANI_U16)val2;
        if(cfgSetInt(pMac,  WNI_CFG_HT_CAP_INFO, *(tANI_U16*)pHTCapabilityInfo) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT Cap Info CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        break;
    case WNI_CFG_MPDU_DENSITY:
        if (wlan_cfgGetInt(pMac, WNI_CFG_HT_AMPDU_PARAMS, &val1) != eSIR_SUCCESS) 
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT AMPDU Param CFG\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT AMPDU Param CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT AMPDU Param CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }
        if (wlan_cfgGetInt(pMac, WNI_CFG_MPDU_DENSITY, &val2) != eSIR_SUCCESS) 
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve MPDU Density CFG\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve MPDU Density CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve MPDU Density CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }
        val16 = ( tANI_U16 ) val1;
        pAmpduParamInfo = ( tSirMacHTParametersInfo* ) &val16;
        pAmpduParamInfo->mpduDensity = (tANI_U8)val2;
        if(cfgSetInt(pMac,  WNI_CFG_HT_AMPDU_PARAMS, *(tANI_U8*)pAmpduParamInfo) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not update HT AMPDU Param CFG\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT AMPDU Param CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT AMPDU Param CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        break;
    case WNI_CFG_MAX_RX_AMPDU_FACTOR:
        if (wlan_cfgGetInt(pMac, WNI_CFG_HT_AMPDU_PARAMS, &val1) != eSIR_SUCCESS) 
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT AMPDU Param CFG\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT AMPDU Param CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve HT AMPDU Param CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }
        if (wlan_cfgGetInt(pMac, WNI_CFG_MAX_RX_AMPDU_FACTOR, &val2) != eSIR_SUCCESS) 
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve AMPDU Factor CFG\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve AMPDU Factor CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("could not retrieve AMPDU Factor CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }
        val16 = ( tANI_U16 ) val1;
        pAmpduParamInfo = ( tSirMacHTParametersInfo* ) &val16;
        pAmpduParamInfo->maxRxAMPDUFactor = (tANI_U8)val2;
        if(cfgSetInt(pMac,  WNI_CFG_HT_AMPDU_PARAMS, *(tANI_U8*)pAmpduParamInfo) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not update HT AMPDU Param CFG\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT AMPDU Param CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not update HT AMPDU Param CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        break;
  
    case WNI_CFG_HEART_BEAT_THRESHOLD:
        if (wlan_cfgGetInt(pMac, WNI_CFG_HEART_BEAT_THRESHOLD, &val1) != eSIR_SUCCESS)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve WNI_CFG_HEART_BEAT_THRESHOLD CFG\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve WNI_CFG_HEART_BEAT_THRESHOLD CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve WNI_CFG_HEART_BEAT_THRESHOLD CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
        }
        if(!val1) 
        {
            limDeactivateAndChangeTimer(pMac, eLIM_HEART_BEAT_TIMER);
            pMac->sys.gSysEnableLinkMonitorMode = 0;
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, "Deactivating heartbeat link monitoring\n");)
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        } 
        else 
        {
            tANI_U16 sessionId;
            pMac->sys.gSysEnableLinkMonitorMode = 1;
            for(sessionId = 0; sessionId < pMac->lim.maxBssId; sessionId++)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                if( (pMac->lim.gpSession[sessionId].valid )&& 
                    (eLIM_MLM_LINK_ESTABLISHED_STATE == pMac->lim.gpSession[sessionId].limMlmState) &&
                    ( pMac->pmm.gPmmState != ePMM_STATE_BMPS_SLEEP))
                {
                    limReactivateHeartBeatTimer(pMac, &pMac->lim.gpSession[sessionId]);
                }
            }
            PELOGE(limLog(pMac, LOGE, "Reactivating heartbeat link monitoring\n");)
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                if( (pMac->lim.gpSession[sessionId].valid )&&
                    (eLIM_MLM_LINK_ESTABLISHED_STATE == pMac->lim.gpSession[sessionId].limMlmState) &&
                    ( pMac->pmm.gPmmState != ePMM_STATE_BMPS_SLEEP) &&
                    (!IS_ACTIVEMODE_OFFLOAD_FEATURE_ENABLE))
                {
                    PELOG2(limLog(pMac, LOG2, "HB link monitoring reactivated"
                           " for session=%d", sessionId);)
                    PELOGW(limLog(pMac, LOGW, "Before reactivating HB timer; parameters are"
                           " session=%d limMlmState=%d pmmState=%d", sessionId,
                             pMac->lim.gpSession[sessionId].limMlmState,
                             pMac->pmm.gPmmState);)
                    limReactivateHeartBeatTimer(pMac, &pMac->lim.gpSession[sessionId]);
                }
                else if ( pMac->lim.gpSession[sessionId].valid )
                {
                    PELOGW(limLog(pMac, LOGW, "HB link monitoring not reactivated-"
                           "session=%d, limMlmState=%d, gPmmState=%d", 
                           sessionId, pMac->lim.gpSession[sessionId].limMlmState,
                           pMac->pmm.gPmmState);)
                }
            }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        }        
    case WNI_CFG_MAX_PS_POLL:
    case WNI_CFG_NUM_BEACON_PER_RSSI_AVERAGE:
    case WNI_CFG_MIN_RSSI_THRESHOLD:
    case WNI_CFG_NTH_BEACON_FILTER:
    case WNI_CFG_BROADCAST_FRAME_FILTER_ENABLE:
        {
            tpSirPowerSaveCfg pPowerSaveConfig;

            /* Allocate and fill in power save configuration. */
            if (palAllocateMemory(pMac->hHdd, (void **)&pPowerSaveConfig,
                                  sizeof(tSirPowerSaveCfg)) != eHAL_STATUS_SUCCESS)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("LIM: Cannot allocate memory for power save configuration\n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("LIM: Cannot allocate memory for power save configuration"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("LIM: Cannot allocate memory for power save configuration"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                break;
            }

            /* This context should be valid if power-save configuration message has been already dispathed 
             * during initialization process. Re-using the present configuration mask
             */
            palCopyMemory(pMac->hHdd, pPowerSaveConfig, (tANI_U8 *)&pMac->pmm.gPmmCfg, sizeof(tSirPowerSaveCfg));

            if ( (pmmSendPowerSaveCfg(pMac, pPowerSaveConfig)) != eSIR_SUCCESS)
            {
<<<<<<< HEAD
<<<<<<< HEAD
                PELOGE(limLog(pMac, LOGE, FL("LIM: pmmSendPowerSaveCfg() failed \n"));)
=======
                PELOGE(limLog(pMac, LOGE, FL("LIM: pmmSendPowerSaveCfg() failed "));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                PELOGE(limLog(pMac, LOGE, FL("LIM: pmmSendPowerSaveCfg() failed "));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            }
        }
        break;


     case WNI_CFG_DOT11_MODE:
        if (wlan_cfgGetInt(pMac, WNI_CFG_DOT11_MODE, &val1) != eSIR_SUCCESS) 
        {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve Dot11 Mode  CFG\n"));)
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve Dot11 Mode  CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOGE(limLog(pMac, LOGE, FL("could not retrieve Dot11 Mode  CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;
        }
        /* TODO */
        //psessionEntry->dot11mode = val1;    //// un comment this line ...FORBUILD -TEMPFIX.. HOW TO GET sessionEntry?????
        break;
    case WNI_CFG_ADDBA_REQ_DECLINE:
        if(wlan_cfgGetInt(pMac, WNI_CFG_ADDBA_REQ_DECLINE, &val1) != eSIR_SUCCESS) {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog( pMac, LOGE, FL( "Unable to get ADDBA_REQ_DECLINE cfg\n" ));
=======
            limLog( pMac, LOGE, FL( "Unable to get ADDBA_REQ_DECLINE cfg" ));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            limLog( pMac, LOGE, FL( "Unable to get ADDBA_REQ_DECLINE cfg" ));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;
        }
        pMac->lim.gAddBA_Declined = (tANI_U8)val1;
        break;
        
    case WNI_CFG_SCAN_IN_POWERSAVE:
        if(wlan_cfgGetInt(pMac, WNI_CFG_SCAN_IN_POWERSAVE, &val1) != eSIR_SUCCESS) {
<<<<<<< HEAD
<<<<<<< HEAD
            limLog( pMac, LOGE, FL( "Unable to get WNI_CFG_SCAN_IN_POWERSAVE \n" ));
=======
            limLog( pMac, LOGE, FL( "Unable to get WNI_CFG_SCAN_IN_POWERSAVE " ));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            limLog( pMac, LOGE, FL( "Unable to get WNI_CFG_SCAN_IN_POWERSAVE " ));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;
        }
        pMac->lim.gScanInPowersave = (tANI_U8)val1;
        break;


    case WNI_CFG_ASSOC_STA_LIMIT:
        if(wlan_cfgGetInt(pMac, WNI_CFG_ASSOC_STA_LIMIT, &val1) != eSIR_SUCCESS) {
            limLog( pMac, LOGE, FL( "Unable to get WNI_CFG_ASSOC_STA_LIMIT" ));
            break;
        }
        pMac->lim.gLimAssocStaLimit = (tANI_U16)val1;
        break;

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    case WNI_CFG_DEL_ALL_RX_BA_SESSIONS_2_4_G_BTC:
        if (wlan_cfgGetInt
           (pMac, WNI_CFG_DEL_ALL_RX_BA_SESSIONS_2_4_G_BTC, &val1) !=
                 eSIR_SUCCESS)
        {
            limLog(pMac, LOGE,
                 FL( "Unable to get WNI_CFG_DEL_ALL_RX_BA_SESSIONS_2_4_G_BTC"));
            break;
        }
        if (val1)
        {
            limLog(pMac, LOGW,
                FL("BTC requested to disable all RX BA sessions"));
            limDelAllBASessionsBtc(pMac);
        }
        else
        {
            limLog(pMac, LOGW,
                FL("Resetting the WNI_CFG_DEL_ALL_RX_BA_SESSIONS_2_4_G_BTC"));
        }
        break;

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    default:
            break;
    }
} /*** end limHandleCFGparamUpdate() ***/



/**
 * limApplyConfiguration()
 *
 *FUNCTION:
 * This function is called to apply the configured parameters
 * before joining or reassociating with a BSS or starting a BSS.
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
 * @param  pMac  - Pointer to Global MAC structure
 * @return None
 */

void
limApplyConfiguration(tpAniSirGlobal pMac,tpPESession psessionEntry)
{
    tANI_U32          val=0, phyMode;

<<<<<<< HEAD
<<<<<<< HEAD
    PELOG2(limLog(pMac, LOG2, FL("Applying config\n"));)

#if (defined(ANI_PRODUCT_TYPE_AP) || defined(ANI_PRODUCT_TYPE_AP_SDK))
    limCleanupMeasResources(pMac);
#endif
=======
    PELOG2(limLog(pMac, LOG2, FL("Applying config"));)

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    PELOG2(limLog(pMac, LOG2, FL("Applying config"));)

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    limInitWdsInfoParams(pMac);

    psessionEntry->limSentCapsChangeNtf = false;

    limGetPhyMode(pMac, &phyMode, psessionEntry);
        
    // Set default keyId and keys
    limSetDefaultKeyIdAndKeys(pMac);

    limUpdateConfig(pMac,psessionEntry);

<<<<<<< HEAD
<<<<<<< HEAD
    if (phyMode == WNI_CFG_PHY_MODE_11A)
    {
        // 11a mode always uses short slot
        // Check this since some APs in 11a mode broadcast long slot in their beacons. As per standard, always use what PHY mandates.
        psessionEntry->shortSlotTimeSupported = true;
    }
    else if (phyMode == WNI_CFG_PHY_MODE_11G)
    {
        if ((psessionEntry->pePersona == VOS_STA_SAP_MODE) ||
           (psessionEntry->pePersona == VOS_P2P_GO_MODE))
        {
            val = 1;
        }

        // Program Polaris based on AP capability

        if (psessionEntry->limMlmState == eLIM_MLM_WT_JOIN_BEACON_STATE)
            // Joining BSS.
            val = SIR_MAC_GET_SHORT_SLOT_TIME( psessionEntry->limCurrentBssCaps);
        else if (psessionEntry->limMlmState == eLIM_MLM_WT_REASSOC_RSP_STATE)
            // Reassociating with AP.
            val = SIR_MAC_GET_SHORT_SLOT_TIME( psessionEntry->limReassocBssCaps);
        psessionEntry->shortSlotTimeSupported = val;
    }
    else // if (phyMode == WNI_CFG_PHY_MODE_11B) - use this if another phymode is added later ON
    {
        // Will reach here in 11b case
        psessionEntry->shortSlotTimeSupported = false;
    }
    //apply protection related config.

#ifdef WLAN_SOFTAP_FEATURE
    limSetCfgProtection(pMac, psessionEntry);    
#else
    limSetCfgProtection(pMac);    
#endif
=======
    psessionEntry->shortSlotTimeSupported = limGetShortSlotFromPhyMode(pMac, psessionEntry, phyMode);

    limSetCfgProtection(pMac, psessionEntry);    
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    psessionEntry->shortSlotTimeSupported = limGetShortSlotFromPhyMode(pMac, psessionEntry, phyMode);

    limSetCfgProtection(pMac, psessionEntry);    
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release


    /* Added for BT - AMP Support */
    if ( (psessionEntry->limSystemRole == eLIM_AP_ROLE) ||
         (psessionEntry->limSystemRole == eLIM_BT_AMP_AP_ROLE)||
         (psessionEntry->limSystemRole == eLIM_STA_IN_IBSS_ROLE)||
         (psessionEntry->limSystemRole == eLIM_BT_AMP_STA_ROLE) )
    {
        /* This check is required to ensure the beacon generation is not done 
           as a part of join request for a BT-AMP station */

        if(psessionEntry->statypeForBss == STA_ENTRY_SELF)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            PELOG1(limLog(pMac, LOG1, FL("Initializing BT-AMP beacon generation\n"));)
=======
            PELOG1(limLog(pMac, LOG1, FL("Initializing BT-AMP beacon generation"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            PELOG1(limLog(pMac, LOG1, FL("Initializing BT-AMP beacon generation"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            schSetBeaconInterval(pMac,psessionEntry);
            schSetFixedBeaconFields(pMac,psessionEntry);
        }
    }

    if (wlan_cfgGetInt(pMac, WNI_CFG_SCAN_IN_POWERSAVE, &val) != eSIR_SUCCESS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("could not retrieve WNI_CFG_SCAN_IN_POWERSAVE\n"));
=======
        limLog(pMac, LOGP, FL("could not retrieve WNI_CFG_SCAN_IN_POWERSAVE"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        limLog(pMac, LOGP, FL("could not retrieve WNI_CFG_SCAN_IN_POWERSAVE"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return;
    }
    pMac->lim.gScanInPowersave = (tANI_U8) val;

} /*** end limApplyConfiguration() ***/


/**
 * limUpdateConfig
 *
 * FUNCTION:
 * Update the local state from CFG database
 * (This used to be dphUpdateConfig)
 *
 * LOGIC:
 *
 * ASSUMPTIONS:
 *
 * NOTE:
 *
 * @param None
 * @return None
 */

static void
limUpdateConfig(tpAniSirGlobal pMac,tpPESession psessionEntry)
{
    tANI_U32 val;

    #if 0
    if (wlan_cfgGetStr(pMac, WNI_CFG_STA_ID, pMac->lim.gLimMyMacAddr, &len) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("cfg get sta id failed\n"));
=======
        limLog(pMac, LOGP, FL("cfg get sta id failed"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        limLog(pMac, LOGP, FL("cfg get sta id failed"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    #endif //To SUPPORT BT-AMP
    sirCopyMacAddr(pMac->lim.gLimMyMacAddr,psessionEntry->selfMacAddr);

    if (wlan_cfgGetInt(pMac, WNI_CFG_SHORT_PREAMBLE, &val) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("cfg get short preamble failed\n"));
    psessionEntry->beaconParams.fShortPreamble = (val) ? 1 : 0;

    if (wlan_cfgGetInt(pMac, WNI_CFG_WME_ENABLED, &val) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("cfg get wme enabled failed\n"));
    psessionEntry->limWmeEnabled = (val) ? 1 : 0;

    if (wlan_cfgGetInt(pMac, WNI_CFG_WSM_ENABLED, &val) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("cfg get wsm enabled failed\n"));
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        limLog(pMac, LOGP, FL("cfg get short preamble failed"));
    psessionEntry->beaconParams.fShortPreamble = (val) ? 1 : 0;

    if (wlan_cfgGetInt(pMac, WNI_CFG_WME_ENABLED, &val) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("cfg get wme enabled failed"));
    psessionEntry->limWmeEnabled = (val) ? 1 : 0;

    if (wlan_cfgGetInt(pMac, WNI_CFG_WSM_ENABLED, &val) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("cfg get wsm enabled failed"));
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    psessionEntry->limWsmEnabled = (val) ? 1 : 0;

    if ((! psessionEntry->limWmeEnabled) && (psessionEntry->limWsmEnabled))
    {
<<<<<<< HEAD
<<<<<<< HEAD
        PELOGE(limLog(pMac, LOGE, FL("Can't enable WSM without WME\n"));)
=======
        PELOGE(limLog(pMac, LOGE, FL("Can't enable WSM without WME"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        PELOGE(limLog(pMac, LOGE, FL("Can't enable WSM without WME"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        psessionEntry->limWsmEnabled = 0;
    }

    if (wlan_cfgGetInt(pMac, WNI_CFG_QOS_ENABLED, &val) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("cfg get qos enabled failed\n"));
    psessionEntry->limQosEnabled = (val) ? 1 : 0;

    if (wlan_cfgGetInt(pMac, WNI_CFG_HCF_ENABLED, &val) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("cfg get hcf enabled failed\n"));
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        limLog(pMac, LOGP, FL("cfg get qos enabled failed"));
    psessionEntry->limQosEnabled = (val) ? 1 : 0;

    if (wlan_cfgGetInt(pMac, WNI_CFG_HCF_ENABLED, &val) != eSIR_SUCCESS)
        limLog(pMac, LOGP, FL("cfg get hcf enabled failed"));
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    psessionEntry->limHcfEnabled = (val) ? 1 : 0;

    // Update the ADD BA Declined configuration 
    if(wlan_cfgGetInt(pMac, WNI_CFG_ADDBA_REQ_DECLINE, &val) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
        limLog( pMac, LOGP, FL( "Unable to get ADDBA_REQ_DECLINE cfg\n" ));
=======
        limLog( pMac, LOGP, FL( "Unable to get ADDBA_REQ_DECLINE cfg" ));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        limLog( pMac, LOGP, FL( "Unable to get ADDBA_REQ_DECLINE cfg" ));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    pMac->lim.gAddBA_Declined = (val) ?  0xff : 0x0;

    // AP: WSM should enable HCF as well, for STA enable WSM only after
    // association response is received
    if (psessionEntry->limWsmEnabled && psessionEntry->limSystemRole == eLIM_AP_ROLE)
        psessionEntry->limHcfEnabled = 1;

    if (wlan_cfgGetInt(pMac, WNI_CFG_11D_ENABLED, &val) != eSIR_SUCCESS)
<<<<<<< HEAD
<<<<<<< HEAD
        limLog(pMac, LOGP, FL("cfg get 11d enabled failed\n"));
=======
        limLog(pMac, LOGP, FL("cfg get 11d enabled failed"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        limLog(pMac, LOGP, FL("cfg get 11d enabled failed"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    psessionEntry->lim11dEnabled = (val) ? 1 : 0;

    if(wlan_cfgGetInt(pMac, WNI_CFG_ASSOC_STA_LIMIT, &val) != eSIR_SUCCESS) {
        limLog( pMac, LOGP, FL( "cfg get assoc sta limit failed" ));
    }
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if( (!WDI_getFwWlanFeatCaps(SAP32STA)) && (val >= WNI_CFG_ASSOC_STA_LIMIT_STAMAX))
    {
        if(ccmCfgSetInt(pMac, WNI_CFG_ASSOC_STA_LIMIT, WNI_CFG_ASSOC_STA_LIMIT_STADEF,
            NULL, eANI_BOOLEAN_FALSE) != eHAL_STATUS_SUCCESS)
        {
           limLog( pMac, LOGP, FL( "cfg get assoc sta limit failed" ));
        }
        val = WNI_CFG_ASSOC_STA_LIMIT_STADEF;
    }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    pMac->lim.gLimAssocStaLimit = (tANI_U16)val;

#if defined WLAN_FEATURE_VOWIFI
    rrmUpdateConfig( pMac, psessionEntry ); 
#endif
<<<<<<< HEAD
<<<<<<< HEAD
    PELOG1(limLog(pMac, LOG1, FL("Updated Lim shadow state based on CFG\n"));)
=======
    PELOG1(limLog(pMac, LOG1, FL("Updated Lim shadow state based on CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    PELOG1(limLog(pMac, LOG1, FL("Updated Lim shadow state based on CFG"));)
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    
}


