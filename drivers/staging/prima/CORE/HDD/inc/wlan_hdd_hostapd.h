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

#if !defined( WLAN_HDD_HOSTAPD_H )
#define WLAN_HDD_HOSTAPD_H

/**===========================================================================
<<<<<<< HEAD
<<<<<<< HEAD
  
  \file  WLAN_HDD_HOSTAPD_H.h
  
  \brief Linux HDD HOSTAPD include file
         Copyright 2008 (c) Qualcomm, Incorporated.
         All Rights Reserved.
         Qualcomm Confidential and Proprietary.
  
  ==========================================================================*/
  
/*--------------------------------------------------------------------------- 
  Include files
  -------------------------------------------------------------------------*/ 
  
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

  \file  WLAN_HDD_HOSTAPD_H.h

  \brief Linux HDD HOSTAPD include file
         Copyright 2008-2013 (c) Qualcomm, Incorporated.
         All Rights Reserved.
<<<<<<< HEAD:CORE/HDD/inc/wlan_hdd_hostapd.h
         Qualcomm Confidential and Proprietary.
  
=======
         Qualcomm Technologies Confidential and Proprietary.

>>>>>>> 009551c... wlan: hdd: remove obsolete "WLAN_SOFTAP_FEATURE" featurization:prima/CORE/HDD/inc/wlan_hdd_hostapd.h
  ==========================================================================*/

/*---------------------------------------------------------------------------
  Include files
  -------------------------------------------------------------------------*/

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#include <linux/netdevice.h>
#include <linux/skbuff.h>
#include <vos_list.h>
#include <vos_types.h>

#include <wlan_qct_tl.h>
#include <wlan_hdd_main.h>

<<<<<<< HEAD
<<<<<<< HEAD
/*--------------------------------------------------------------------------- 
  Preprocessor definitions and constants
  -------------------------------------------------------------------------*/ 
=======
/*---------------------------------------------------------------------------
  Preprocessor definitions and constants
  -------------------------------------------------------------------------*/
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
/*---------------------------------------------------------------------------
  Preprocessor definitions and constants
  -------------------------------------------------------------------------*/
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

hdd_adapter_t* hdd_wlan_create_ap_dev( hdd_context_t *pHddCtx, tSirMacAddr macAddr, tANI_U8 *name);

VOS_STATUS hdd_register_hostapd(hdd_adapter_t *pAdapter, tANI_U8 rtnl_held);

VOS_STATUS hdd_unregister_hostapd(hdd_adapter_t *pAdapter);

eCsrAuthType 
hdd_TranslateRSNToCsrAuthType( u_int8_t auth_suite[4]);

eCsrEncryptionType 
hdd_TranslateRSNToCsrEncryptionType(u_int8_t cipher_suite[4]);

eCsrEncryptionType 
hdd_TranslateRSNToCsrEncryptionType(u_int8_t cipher_suite[4]);

eCsrAuthType 
hdd_TranslateWPAToCsrAuthType(u_int8_t auth_suite[4]);

eCsrEncryptionType 
hdd_TranslateWPAToCsrEncryptionType(u_int8_t cipher_suite[4]);

<<<<<<< HEAD
<<<<<<< HEAD
void hdd_softap_sta_deauth(hdd_adapter_t*,v_U8_t*);
=======
VOS_STATUS hdd_softap_sta_deauth(hdd_adapter_t*,v_U8_t*);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
VOS_STATUS hdd_softap_sta_deauth(hdd_adapter_t*,v_U8_t*);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
void hdd_softap_sta_disassoc(hdd_adapter_t*,v_U8_t*);
void hdd_softap_tkip_mic_fail_counter_measure(hdd_adapter_t*,v_BOOL_t);
int hdd_softap_unpackIE( tHalHandle halHandle,
                eCsrEncryptionType *pEncryptType, 
                eCsrEncryptionType *mcEncryptType, 
                eCsrAuthType *pAuthType, 
                u_int16_t gen_ie_len, 
                u_int8_t *gen_ie );

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
VOS_STATUS hdd_hostapd_SAPEventCB( tpSap_Event pSapEvent, v_PVOID_t usrDataForCallback);
VOS_STATUS hdd_init_ap_mode( hdd_adapter_t *pAdapter );
void hdd_set_ap_ops( struct net_device *pWlanHostapdDev );
#endif
=======
VOS_STATUS hdd_hostapd_SAPEventCB( tpSap_Event pSapEvent, v_PVOID_t usrDataForCallback);
VOS_STATUS hdd_init_ap_mode( hdd_adapter_t *pAdapter );
void hdd_set_ap_ops( struct net_device *pWlanHostapdDev );
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
VOS_STATUS hdd_hostapd_SAPEventCB( tpSap_Event pSapEvent, v_PVOID_t usrDataForCallback);
VOS_STATUS hdd_init_ap_mode( hdd_adapter_t *pAdapter );
void hdd_set_ap_ops( struct net_device *pWlanHostapdDev );
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

#endif    // end #if !defined( WLAN_HDD_HOSTAPD_H )
