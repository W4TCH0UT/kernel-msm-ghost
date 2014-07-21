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

/** ------------------------------------------------------------------------ *
    ------------------------------------------------------------------------ *


    \file wlan_hdd_wext.c

    \brief Airgo Linux Wireless Extensions Common Control Plane Types and
    interfaces.

    $Id: wlan_hdd_wext.c,v 1.34 2007/04/14 01:49:23 jimz Exp jimz $

    Copyright (C) 2007 Airgo Networks, Incorporated

    This file defines all of the types that are utilized by the CCP module
    of the "Portable" HDD.   This file also includes the underlying Linux
    Wireless Extensions Data types referred to by CCP.

  ======================================================================== */

#include <linux/version.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/wireless.h>
#include <wlan_hdd_includes.h>
#include <wlan_btc_svc.h>
#include <wlan_nlink_common.h>
#ifdef WLAN_BTAMP_FEATURE
#include <bap_hdd_main.h>
#endif
#include <vos_api.h>
#include <net/arp.h>
#include "ccmApi.h"
#include "sirParams.h"
#include "csrApi.h"
#include "csrInsideApi.h"
#if defined WLAN_FEATURE_VOWIFI
#include "smeRrmInternal.h"
#endif
#include <aniGlobal.h>
#include "dot11f.h"
#include <wlan_hdd_wowl.h>
#include <wlan_hdd_cfg.h>
#include <wlan_hdd_wmm.h>
#include "utilsApi.h"
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
#include "wlan_hdd_p2p.h"
=======
#include "wlan_hdd_p2p.h"
#ifdef FEATURE_WLAN_TDLS
#include "wlan_hdd_tdls.h"
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#include "wlan_hdd_p2p.h"
#ifdef FEATURE_WLAN_TDLS
#include "wlan_hdd_tdls.h"
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#endif

#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#endif
#include "wlan_hdd_power.h"
#include "qwlan_version.h"
#include <vos_power.h>
#include "wlan_hdd_host_offload.h"
#include "wlan_hdd_keep_alive.h"
#ifdef WLAN_FEATURE_PACKET_FILTERING
#include "wlan_hdd_packet_filtering.h"
#endif

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef CONFIG_CFG80211
#include <linux/wireless.h>
#include <net/cfg80211.h>
#endif
#ifdef FEATURE_WLAN_INTEGRATED_SOC
#include "wlan_qct_pal_trace.h"
#endif // FEATURE_WLAN_INTEGRATED_SOC
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#include <linux/wireless.h>
#include <net/cfg80211.h>
#include "wlan_qct_pal_trace.h"
#include "wlan_qct_tl.h"
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

#include "wlan_hdd_misc.h"
#include "bap_hdd_misc.h"

#include "wlan_hdd_dev_pwr.h"
#include "qc_sap_ioctl.h"
<<<<<<< HEAD
<<<<<<< HEAD
#define WE_MAX_STR_LEN 1024
=======
#include "sme_Api.h"
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#include "sme_Api.h"
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

#ifdef CONFIG_HAS_EARLYSUSPEND
extern void hdd_suspend_wlan(struct early_suspend *wlan_suspend);
extern void hdd_resume_wlan(struct early_suspend *wlan_suspend);
#endif

#ifdef FEATURE_OEM_DATA_SUPPORT
<<<<<<< HEAD
<<<<<<< HEAD
#define MAX_OEM_DATA_RSP_LEN 1024
=======
#define MAX_OEM_DATA_RSP_LEN 2047
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#define MAX_OEM_DATA_RSP_LEN 2047
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#endif

#define HDD_FINISH_ULA_TIME_OUT    800

extern int wlan_hdd_cfg80211_update_band(struct wiphy *wiphy, eCsrBand eBand);
int hdd_setBand_helper(struct net_device *dev, tANI_U8* ptr);

<<<<<<< HEAD
<<<<<<< HEAD
static int ioctl_debug = 0;
=======
static int ioctl_debug;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
static int ioctl_debug;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
module_param(ioctl_debug, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

struct statsContext
{
   struct completion completion;
   hdd_adapter_t *pAdapter;
   unsigned int magic;
};

#define STATS_CONTEXT_MAGIC 0x53544154   //STAT
#define RSSI_CONTEXT_MAGIC  0x52535349   //RSSI
#define POWER_CONTEXT_MAGIC 0x504F5752   // POWR

/* To Validate Channel against the Frequency and Vice-Versa */
static const hdd_freq_chan_map_t freq_chan_map[] = { {2412, 1}, {2417, 2},
        {2422, 3}, {2427, 4}, {2432, 5}, {2437, 6}, {2442, 7}, {2447, 8},
        {2452, 9}, {2457, 10}, {2462, 11}, {2467 ,12}, {2472, 13},
        {2484, 14}, {4920, 240}, {4940, 244}, {4960, 248}, {4980, 252},
        {5040, 208}, {5060, 212}, {5080, 216}, {5180, 36}, {5200, 40}, {5220, 44},
        {5240, 48}, {5260, 52}, {5280, 56}, {5300, 60}, {5320, 64}, {5500, 100},
        {5520, 104}, {5540, 108}, {5560, 112}, {5580, 116}, {5600, 120},
        {5620, 124}, {5640, 128}, {5660, 132}, {5680, 136}, {5700, 140},
        {5745, 149}, {5765, 153}, {5785, 157}, {5805, 161}, {5825, 165} };

<<<<<<< HEAD
<<<<<<< HEAD
#define FREQ_CHAN_MAP_TABLE_SIZE sizeof(freq_chan_map)/sizeof(freq_chan_map[0])
=======
#define FREQ_CHAN_MAP_TABLE_SIZE (sizeof(freq_chan_map)/sizeof(freq_chan_map[0]))
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#define FREQ_CHAN_MAP_TABLE_SIZE (sizeof(freq_chan_map)/sizeof(freq_chan_map[0]))
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

/* Private ioctls and their sub-ioctls */
#define WLAN_PRIV_SET_INT_GET_NONE    (SIOCIWFIRSTPRIV + 0)
#define WE_SET_11D_STATE     1
#define WE_WOWL              2
#define WE_SET_POWER         3
#define WE_SET_MAX_ASSOC     4
#define WE_SET_SAP_AUTO_CHANNEL_SELECTION     5
#define WE_SET_DATA_INACTIVITY_TO  6
#define WE_SET_MAX_TX_POWER  7
#define WE_SET_HIGHER_DTIM_TRANSITION   8
#define WE_SET_TM_LEVEL      9
<<<<<<< HEAD
<<<<<<< HEAD
=======
#define WE_SET_CHANNEL_RANGE 10   // Motorola, IKJBREL1-4181
#define WE_SET_IPV6_FILTER_STATE 11 // IKJB42MAIN-1244, Motorola, a19091
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#define WE_SET_CHANNEL_RANGE 10   // Motorola, IKJBREL1-4181
#define WE_SET_IPV6_FILTER_STATE 11 // IKJB42MAIN-1244, Motorola, a19091
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

/* Private ioctls and their sub-ioctls */
#define WLAN_PRIV_SET_NONE_GET_INT    (SIOCIWFIRSTPRIV + 1)
#define WE_GET_11D_STATE     1
#define WE_IBSS_STATUS       2
#define WE_PMC_STATE         3
#define WE_GET_WLAN_DBG      4
#define WE_MODULE_DOWN_IND   5
#define WE_GET_MAX_ASSOC     6
#define WE_GET_WDI_DBG       7
#define WE_GET_SAP_AUTO_CHANNEL_SELECTION 8
#define WE_GET_CONCURRENCY_MODE 9
<<<<<<< HEAD
<<<<<<< HEAD
=======
#define WE_GET_MCC_MODE      10 /* MOTOROLA IKJB42MAIN-274 */
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#define WE_GET_MCC_MODE      10 /* MOTOROLA IKJB42MAIN-274 */
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
/* Private ioctls and their sub-ioctls */
#define WLAN_PRIV_SET_INT_GET_INT     (SIOCIWFIRSTPRIV + 2)

/* Private ioctls and their sub-ioctls */
#define WLAN_PRIV_SET_CHAR_GET_NONE   (SIOCIWFIRSTPRIV + 3)
#define WE_WOWL_ADD_PTRN     1
#define WE_WOWL_DEL_PTRN     2
#if defined WLAN_FEATURE_VOWIFI
#define WE_NEIGHBOR_REPORT_REQUEST 3
#endif
#define WE_SET_AP_WPS_IE     4  //This is called in station mode to set probe rsp ie.
#define WE_SET_CONFIG        5

/* Private ioctls and their sub-ioctls */
#define WLAN_PRIV_SET_THREE_INT_GET_NONE   (SIOCIWFIRSTPRIV + 4)
#define WE_SET_WLAN_DBG      1
#define WE_SET_WDI_DBG       2
#define WE_SET_SAP_CHANNELS  3
<<<<<<< HEAD
<<<<<<< HEAD
=======
//Begin Motorola dcw476 4/17/13 IKJBXLINE-5577:changing wlan driver log level dynamically
#define WE_SET_WLAN_DBG_TILL_LEVEL 4
//END IKJBXLINE-5577
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
//Begin Motorola dcw476 4/17/13 IKJBXLINE-5577:changing wlan driver log level dynamically
#define WE_SET_WLAN_DBG_TILL_LEVEL 4
//END IKJBXLINE-5577
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

/* Private ioctls and their sub-ioctls */
#define WLAN_PRIV_GET_CHAR_SET_NONE   (SIOCIWFIRSTPRIV + 5)
#define WE_WLAN_VERSION      1
#define WE_GET_STATS         2
#define WE_GET_CFG           3
#define WE_GET_WMM_STATUS    4
#define WE_GET_CHANNEL_LIST  5
#ifdef WLAN_FEATURE_11AC
#define WE_GET_RSSI          6
#endif
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#define WE_GET_ROAM_RSSI     7
#ifdef FEATURE_WLAN_TDLS
#define WE_GET_TDLS_PEERS    8
#endif
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

/* Private ioctls and their sub-ioctls */
#define WLAN_PRIV_SET_NONE_GET_NONE   (SIOCIWFIRSTPRIV + 6)
#define WE_CLEAR_STATS       1
#define WE_INIT_AP           2
#define WE_STOP_AP           3
#define WE_ENABLE_AMP        4
#define WE_DISABLE_AMP       5
#define WE_ENABLE_DXE_STALL_DETECT 6
#define WE_DISPLAY_DXE_SNAP_SHOT   7
<<<<<<< HEAD
<<<<<<< HEAD
=======
#define WE_DISPLAY_DATAPATH_SNAP_SHOT    9
#define WE_SET_REASSOC_TRIGGER     8
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#define WE_DISPLAY_DATAPATH_SNAP_SHOT    9
#define WE_SET_REASSOC_TRIGGER     8
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

/* Private ioctls and their sub-ioctls */
#define WLAN_PRIV_SET_VAR_INT_GET_NONE   (SIOCIWFIRSTPRIV + 7)
#define WE_LOG_DUMP_CMD      1

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
#define WE_P2P_NOA_CMD       2
#endif

#define MAX_VAR_ARGS         7
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#define WE_P2P_NOA_CMD       2
//IOCTL to configure MCC params
#define WE_MCC_CONFIG_CREDENTIAL 3
#define WE_MCC_CONFIG_PARAMS  4

#ifdef FEATURE_WLAN_TDLS
#define WE_TDLS_CONFIG_PARAMS   5
#endif

#ifdef FEATURE_WLAN_TDLS
#undef  MAX_VAR_ARGS
#define MAX_VAR_ARGS         10
#else
#define MAX_VAR_ARGS         7
#endif

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

/* Private ioctls (with no sub-ioctls) */
/* note that they must be odd so that they have "get" semantics */
#define WLAN_PRIV_ADD_TSPEC (SIOCIWFIRSTPRIV +  9)
#define WLAN_PRIV_DEL_TSPEC (SIOCIWFIRSTPRIV + 11)
#define WLAN_PRIV_GET_TSPEC (SIOCIWFIRSTPRIV + 13)

#ifdef FEATURE_WLAN_WAPI
/* Private ioctls EVEN NO: SET, ODD NO:GET */
#define WLAN_PRIV_SET_WAPI_MODE         (SIOCIWFIRSTPRIV + 8)
#define WLAN_PRIV_GET_WAPI_MODE         (SIOCIWFIRSTPRIV + 16)
#define WLAN_PRIV_SET_WAPI_ASSOC_INFO   (SIOCIWFIRSTPRIV + 10)
#define WLAN_PRIV_SET_WAPI_KEY          (SIOCIWFIRSTPRIV + 12)
#define WLAN_PRIV_SET_WAPI_BKID         (SIOCIWFIRSTPRIV + 14)
#define WLAN_PRIV_GET_WAPI_BKID         (SIOCIWFIRSTPRIV + 15)
#define WAPI_PSK_AKM_SUITE  0x02721400
#define WAPI_CERT_AKM_SUITE 0x01721400
#endif

#ifdef FEATURE_OEM_DATA_SUPPORT
/* Private ioctls for setting the measurement configuration */
#define WLAN_PRIV_SET_OEM_DATA_REQ (SIOCIWFIRSTPRIV + 17)
#define WLAN_PRIV_GET_OEM_DATA_RSP (SIOCIWFIRSTPRIV + 19)
#endif

#ifdef WLAN_FEATURE_VOWIFI_11R
#define WLAN_PRIV_SET_FTIES             (SIOCIWFIRSTPRIV + 20)
#endif

/* Private ioctl for setting the host offload feature */
#define WLAN_PRIV_SET_HOST_OFFLOAD (SIOCIWFIRSTPRIV + 18)

/* Private ioctl to get the statistics */
#define WLAN_GET_WLAN_STATISTICS (SIOCIWFIRSTPRIV + 21)

/* Private ioctl to set the Keep Alive Params */
#define WLAN_SET_KEEPALIVE_PARAMS (SIOCIWFIRSTPRIV + 22)
#ifdef WLAN_FEATURE_PACKET_FILTERING
/* Private ioctl to set the Packet Filtering Params */
#define WLAN_SET_PACKET_FILTER_PARAMS (SIOCIWFIRSTPRIV + 23)
#endif

#ifdef FEATURE_WLAN_SCAN_PNO
/* Private ioctl to get the statistics */
#define WLAN_SET_PNO (SIOCIWFIRSTPRIV + 24)
#endif

#define WLAN_SET_BAND_CONFIG  (SIOCIWFIRSTPRIV + 25)  /*Don't change this number*/

#define WLAN_PRIV_SET_MCBC_FILTER    (SIOCIWFIRSTPRIV + 26)
#define WLAN_PRIV_CLEAR_MCBC_FILTER  (SIOCIWFIRSTPRIV + 27)
<<<<<<< HEAD
<<<<<<< HEAD
=======
/* Private ioctl to trigger reassociation */

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
/* Private ioctl to trigger reassociation */

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#define WLAN_SET_POWER_PARAMS        (SIOCIWFIRSTPRIV + 29)
#define WLAN_GET_LINK_SPEED          (SIOCIWFIRSTPRIV + 31)

#define WLAN_STATS_INVALID            0
#define WLAN_STATS_RETRY_CNT          1
#define WLAN_STATS_MUL_RETRY_CNT      2
#define WLAN_STATS_TX_FRM_CNT         3
#define WLAN_STATS_RX_FRM_CNT         4
#define WLAN_STATS_FRM_DUP_CNT        5
#define WLAN_STATS_FAIL_CNT           6
#define WLAN_STATS_RTS_FAIL_CNT       7
#define WLAN_STATS_ACK_FAIL_CNT       8
#define WLAN_STATS_RTS_SUC_CNT        9
#define WLAN_STATS_RX_DISCARD_CNT     10
#define WLAN_STATS_RX_ERROR_CNT       11
#define WLAN_STATS_TX_BYTE_CNT        12

#define WLAN_STATS_RX_BYTE_CNT        13
#define WLAN_STATS_RX_RATE            14
#define WLAN_STATS_TX_RATE            15

#define WLAN_STATS_RX_UC_BYTE_CNT     16
#define WLAN_STATS_RX_MC_BYTE_CNT     17
#define WLAN_STATS_RX_BC_BYTE_CNT     18
#define WLAN_STATS_TX_UC_BYTE_CNT     19
#define WLAN_STATS_TX_MC_BYTE_CNT     20
#define WLAN_STATS_TX_BC_BYTE_CNT     21

<<<<<<< HEAD
<<<<<<< HEAD
#define FILL_TLV(__p, __type, __size, __val, __tlen) \
{\
    if ((__tlen + __size + 2) < WE_MAX_STR_LEN) \
    {\
        *__p++ = __type;\
        *__p++ = __size;\
        memcpy(__p, __val, __size);\
        __p += __size;\
        __tlen += __size + 2;\
    }\
    else \
    {                                                         \
        hddLog(VOS_TRACE_LEVEL_ERROR, "FILL_TLV Failed!!!\n");\
    }                                                         \
}while(0);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#define FILL_TLV(__p, __type, __size, __val, __tlen) do {           \
        if ((__tlen + __size + 2) < WE_MAX_STR_LEN)                 \
        {                                                           \
            *__p++ = __type;                                        \
            *__p++ = __size;                                        \
            memcpy(__p, __val, __size);                             \
            __p += __size;                                          \
            __tlen += __size + 2;                                   \
        }                                                           \
        else                                                        \
        {                                                           \
            hddLog(VOS_TRACE_LEVEL_ERROR, "FILL_TLV Failed!!!\n");  \
        }                                                           \
    } while(0);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

#define VERSION_VALUE_MAX_LEN 32

#define TX_PER_TRACKING_DEFAULT_RATIO             5
#define TX_PER_TRACKING_MAX_RATIO                10
#define TX_PER_TRACKING_DEFAULT_WATERMARK         5

<<<<<<< HEAD
<<<<<<< HEAD
#define WLAN_HDD_UI_BAND_AUTO                     0
#define WLAN_HDD_UI_BAND_5_GHZ                    1
#define WLAN_HDD_UI_BAND_2_4_GHZ                  2
#define WLAN_HDD_UI_SET_BAND_VALUE_OFFSET         8
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
/*MCC Configuration parameters */
enum {
    MCC_SCHEDULE_TIME_SLICE_CFG_PARAM = 1,
    MCC_MAX_NULL_SEND_TIME_CFG_PARAM,
    MCC_TX_EARLY_STOP_TIME_CFG_PARAM,
    MCC_RX_DRAIN_TIME_CFG_PARAM,
    MCC_CHANNEL_SWITCH_TIME_CFG_PARAM,
    MCC_MIN_CHANNEL_TIME_CFG_PARAM,
    MCC_PARK_BEFORE_TBTT_CFG_PARAM,
    MCC_MIN_AFTER_DTIM_CFG_PARAM,
    MCC_TOO_CLOSE_MARGIN_CFG_PARAM,
};

int hdd_validate_mcc_config(hdd_adapter_t *pAdapter, v_UINT_t staId,
                                v_UINT_t arg1, v_UINT_t arg2, v_UINT_t arg3);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

#ifdef WLAN_FEATURE_PACKET_FILTERING
int wlan_hdd_set_filter(hdd_context_t *pHddCtx, tpPacketFilterCfg pRequest, 
                           v_U8_t sessionId);
<<<<<<< HEAD
<<<<<<< HEAD
void wlan_hdd_set_mc_addr_list(hdd_context_t *pHddCtx, v_U8_t set, v_U8_t sessionId);
#endif

#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
=======
#endif

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#endif

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
/**---------------------------------------------------------------------------

  \brief hdd_wlan_get_version() -

<<<<<<< HEAD
<<<<<<< HEAD
   This function use to get Wlan Driver And Firmware Version.
=======
   This function use to get Wlan Driver, Firmware, & Hardware Version.
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
   This function use to get Wlan Driver, Firmware, & Hardware Version.
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

  \param  - pAdapter Pointer to the adapter.
            wrqu - Pointer to IOCTL REQUEST Data.
            extra - Pointer to char

<<<<<<< HEAD
<<<<<<< HEAD
  \return - 0 for success, non zero for failure

  --------------------------------------------------------------------------*/
int hdd_wlan_get_version(hdd_adapter_t *pAdapter, union iwreq_data *wrqu,
                         char *extra)
{
    VOS_STATUS status;
    FwVersionInfo fwversion;
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    v_U32_t reg_val;
    char *buf = extra;

    buf += snprintf(buf, VERSION_VALUE_MAX_LEN, "%s_", WLAN_CHIP_VERSION);
    /*Read the RevID*/
    status = sme_DbgReadRegister(hHal, QWLAN_RFAPB_REV_ID_REG, &reg_val);

    if ( !VOS_IS_STATUS_SUCCESS( status ) ) {
       hddLog(VOS_TRACE_LEVEL_ERROR, "%s Failed!!!\n", __func__);
       return -EINVAL;
    }

    buf += snprintf(buf, VERSION_VALUE_MAX_LEN, "%x.%x-", (v_U8_t)(reg_val >> 8),
                               (v_U8_t)(reg_val & 0x000000FF));

    status = sme_GetFwVersion(hHal, &fwversion);

    if ( !VOS_IS_STATUS_SUCCESS( status ) ) {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s Failed!!!\n", __func__);
        return -EINVAL;
    }
    buf += snprintf(buf, VERSION_VALUE_MAX_LEN, "%s-", QWLAN_VERSIONSTR);
    buf += snprintf(buf, VERSION_VALUE_MAX_LEN, "%ld.%ld.%ld.%ld",
                                    fwversion.uMj, fwversion.uMn,
                                    fwversion.uPatch, fwversion.uBuild);
    wrqu->data.length = strlen(extra);

    return 0;
}

#endif
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
  \return - none

  --------------------------------------------------------------------------*/
void hdd_wlan_get_version(hdd_adapter_t *pAdapter, union iwreq_data *wrqu,
                          char *extra)
{
    VOS_STATUS status;
    tSirVersionString wcnss_SW_version;
    tSirVersionString wcnss_HW_version;
    char *pSWversion;
    char *pHWversion;
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);

    status = sme_GetWcnssSoftwareVersion(hHal, wcnss_SW_version,
                                         sizeof(wcnss_SW_version));
    if (VOS_IS_STATUS_SUCCESS(status))
    {
        pSWversion = wcnss_SW_version;
    }
    else
    {
        pSWversion = "Unknown";
    }

    status = sme_GetWcnssHardwareVersion(hHal, wcnss_HW_version,
                                         sizeof(wcnss_HW_version));
    if (VOS_IS_STATUS_SUCCESS(status))
    {
        pHWversion = wcnss_HW_version;
    }
    else
    {
        pHWversion = "Unknown";
    }

    wrqu->data.length = scnprintf(extra, WE_MAX_STR_LEN,
                                 "Host SW:%s, FW:%s, HW:%s",
                                 QWLAN_VERSIONSTR,
                                 pSWversion,
                                 pHWversion);

    return;
}

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
int hdd_wlan_get_rts_threshold(hdd_adapter_t *pAdapter, union iwreq_data *wrqu)
{
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    v_U32_t threshold = 0,status = 0;

    ENTER();

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress) {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                                  "%s:LOGP in Progress. Ignore!!!",__func__);
      return status;
    }

    if ( eHAL_STATUS_SUCCESS !=
                     ccmCfgGetInt(hHal, WNI_CFG_RTS_THRESHOLD, &threshold) )
    {
       return -EIO;
    }
    wrqu->rts.value = threshold;

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                                 ("Rts-Threshold=%ld!!\n"), wrqu->rts.value);

    EXIT();

    return 0;
}

int hdd_wlan_get_frag_threshold(hdd_adapter_t *pAdapter, union iwreq_data *wrqu)
{
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    v_U32_t threshold = 0,status = 0;

    ENTER();

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress) {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                                  "%s:LOGP in Progress. Ignore!!!",__func__);
      return status;
    }

    if ( ccmCfgGetInt(hHal, WNI_CFG_FRAGMENTATION_THRESHOLD, &threshold)
                                                != eHAL_STATUS_SUCCESS )
    {
        return -EIO;
    }
    wrqu->frag.value = threshold;

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                               ("Frag-Threshold=%ld!!\n"), wrqu->frag.value);

    EXIT();

    return 0;
}

int hdd_wlan_get_freq(v_U32_t channel, v_U32_t *pfreq)
{
    int i;
    if (channel > 0)
    {
        for (i=0; i < FREQ_CHAN_MAP_TABLE_SIZE; i++)
        {
            if (channel == freq_chan_map[i].chan)
            {
                *pfreq = freq_chan_map[i].freq;
                return 1;
            }
        }
    }
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                               ("Invalid channel no=%d!!\n"), channel);
    return -EINVAL;
}

static v_BOOL_t
hdd_IsAuthTypeRSN( tHalHandle halHandle, eCsrAuthType authType)
{
    v_BOOL_t rsnType = VOS_FALSE;
    // is the authType supported?
    switch (authType)
    {
        case eCSR_AUTH_TYPE_NONE:    //never used
            rsnType = eANI_BOOLEAN_FALSE;
            break;
        // MAC layer authentication types
        case eCSR_AUTH_TYPE_OPEN_SYSTEM:
            rsnType = eANI_BOOLEAN_FALSE;
            break;
        case eCSR_AUTH_TYPE_SHARED_KEY:
            rsnType = eANI_BOOLEAN_FALSE;
            break;
        case eCSR_AUTH_TYPE_AUTOSWITCH:
            rsnType = eANI_BOOLEAN_FALSE;
            break;

        // Upper layer authentication types
        case eCSR_AUTH_TYPE_WPA:
            rsnType = eANI_BOOLEAN_TRUE;
            break;
        case eCSR_AUTH_TYPE_WPA_PSK:
            rsnType = eANI_BOOLEAN_TRUE;
            break;
        case eCSR_AUTH_TYPE_WPA_NONE:
            rsnType = eANI_BOOLEAN_TRUE;
            break;
#ifdef WLAN_FEATURE_VOWIFI_11R
        case eCSR_AUTH_TYPE_FT_RSN:
#endif
        case eCSR_AUTH_TYPE_RSN:
            rsnType = eANI_BOOLEAN_TRUE;
            break;
#ifdef WLAN_FEATURE_VOWIFI_11R
        case eCSR_AUTH_TYPE_FT_RSN_PSK:
#endif
        case eCSR_AUTH_TYPE_RSN_PSK:
            rsnType = eANI_BOOLEAN_TRUE;
            break;
        //case eCSR_AUTH_TYPE_FAILED:
        case eCSR_AUTH_TYPE_UNKNOWN:
            rsnType = eANI_BOOLEAN_FALSE;
            break;
        default:
            hddLog(LOGE, FL("%s called with unknown authType - default to Open, None\n"),
<<<<<<< HEAD
<<<<<<< HEAD
                                                                                      __FUNCTION__);
=======
                                                                                      __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                                                                                      __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            rsnType = eANI_BOOLEAN_FALSE;
            break;
    }
    hddLog(LOGE, FL("%s called with authType: %d, returned: %d\n"),
<<<<<<< HEAD
<<<<<<< HEAD
                                             __FUNCTION__, authType, rsnType);
=======
                                             __func__, authType, rsnType);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                                             __func__, authType, rsnType);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    return rsnType;
}

static void hdd_GetRssiCB( v_S7_t rssi, tANI_U32 staId, void *pContext )
{
   struct statsContext *pStatsContext;
   hdd_adapter_t *pAdapter;

   if (ioctl_debug)
   {
      pr_info("%s: rssi [%d] STA [%d] pContext [%p]\n",
<<<<<<< HEAD
<<<<<<< HEAD
              __FUNCTION__, (int)rssi, (int)staId, pContext);
=======
              __func__, (int)rssi, (int)staId, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
              __func__, (int)rssi, (int)staId, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   }

   if (NULL == pContext)
   {
      hddLog(VOS_TRACE_LEVEL_ERROR,
             "%s: Bad param, pContext [%p]",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, pContext);
=======
             __func__, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
             __func__, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
      return;
   }

   /* there is a race condition that exists between this callback function
      and the caller since the caller could time out either before or
      while this code is executing.  we'll assume the timeout hasn't
      occurred, but we'll verify that right before we save our work */

   pStatsContext = pContext;
   pAdapter      = pStatsContext->pAdapter;
   if ((NULL == pAdapter) || (RSSI_CONTEXT_MAGIC != pStatsContext->magic))
   {
      /* the caller presumably timed out so there is nothing we can do */
      hddLog(VOS_TRACE_LEVEL_WARN,
             "%s: Invalid context, pAdapter [%p] magic [%08x]",
<<<<<<< HEAD
<<<<<<< HEAD
              __FUNCTION__, pAdapter, pStatsContext->magic);
      if (ioctl_debug)
      {
         pr_info("%s: Invalid context, pAdapter [%p] magic [%08x]\n",
                 __FUNCTION__, pAdapter, pStatsContext->magic);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
              __func__, pAdapter, pStatsContext->magic);
      if (ioctl_debug)
      {
         pr_info("%s: Invalid context, pAdapter [%p] magic [%08x]\n",
                 __func__, pAdapter, pStatsContext->magic);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
      }
      return;
   }

   /* the race is on.  caller could have timed out immediately after
      we verified the magic, but if so, caller will wait a short time
      for us to copy over the rssi */
   pAdapter->rssi = rssi;

   /* and notify the caller */
   complete(&pStatsContext->completion);
}

VOS_STATUS wlan_hdd_get_rssi(hdd_adapter_t *pAdapter, v_S7_t *rssi_value)
{
   struct statsContext context;
   hdd_context_t *pHddCtx;
   hdd_station_ctx_t *pHddStaCtx;
   eHalStatus hstatus;
   long lrc;

   if (NULL == pAdapter)
   {
       hddLog(VOS_TRACE_LEVEL_WARN,
              "%s: Invalid context, pAdapter", __func__);
       return VOS_STATUS_E_FAULT;
   }
   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
   {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR, "%s:LOGP in Progress. Ignore!!!",__func__);
       /* return a cached value */
       *rssi_value = pAdapter->rssi;
       return VOS_STATUS_SUCCESS;
   }

   pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
   pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

   init_completion(&context.completion);
   context.pAdapter = pAdapter;
   context.magic = RSSI_CONTEXT_MAGIC;

   hstatus = sme_GetRssi(pHddCtx->hHal, hdd_GetRssiCB,
                         pHddStaCtx->conn_info.staId[ 0 ],
                         pHddStaCtx->conn_info.bssId,
                         &context, pHddCtx->pvosContext);
   if (eHAL_STATUS_SUCCESS != hstatus)
   {
       hddLog(VOS_TRACE_LEVEL_ERROR,"%s: Unable to retrieve RSSI",
<<<<<<< HEAD
<<<<<<< HEAD
              __FUNCTION__);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
              __func__);
       /* we'll returned a cached value below */
   }
   else
   {
       /* request was sent -- wait for the response */
       lrc = wait_for_completion_interruptible_timeout(&context.completion,
                                    msecs_to_jiffies(WLAN_WAIT_TIME_STATS));
       /* either we have a response or we timed out
          either way, first invalidate our magic */
       context.magic = 0;
       if (lrc <= 0)
       {
          hddLog(VOS_TRACE_LEVEL_ERROR,"%s: SME %s while retrieving RSSI ",
                 __func__, (0 == lrc) ? "timeout" : "interrupt");
          /* there is a race condition such that the callback
             function could be executing at the same time we are. of
             primary concern is if the callback function had already
             verified the "magic" but hasn't yet set the completion
             variable.  Since the completion variable is on our
             stack, we'll delay just a bit to make sure the data is
             still valid if that is the case */
          msleep(50);
          /* we'll now returned a cached value below */
       }
   }
   *rssi_value = pAdapter->rssi;

   return VOS_STATUS_SUCCESS;
}

#if defined WLAN_FEATURE_VOWIFI_11R || defined FEATURE_WLAN_CCX || defined(FEATURE_WLAN_LFR)

static void hdd_GetRoamRssiCB( v_S7_t rssi, tANI_U32 staId, void *pContext )
{
   struct statsContext *pStatsContext;
   hdd_adapter_t *pAdapter;
   if (ioctl_debug)
   {
      pr_info("%s: rssi [%d] STA [%d] pContext [%p]\n",
              __func__, (int)rssi, (int)staId, pContext);
   }

   if (NULL == pContext)
   {
      hddLog(VOS_TRACE_LEVEL_ERROR,
             "%s: Bad param, pContext [%p]",
             __func__, pContext);
      return;
   }

   /* there is a race condition that exists between this callback function
      and the caller since the caller could time out either before or
      while this code is executing.  we'll assume the timeout hasn't
      occurred, but we'll verify that right before we save our work */

   pStatsContext = pContext;
   pAdapter      = pStatsContext->pAdapter;
   if ((NULL == pAdapter) || (RSSI_CONTEXT_MAGIC != pStatsContext->magic))
   {
      /* the caller presumably timed out so there is nothing we can do */
      hddLog(VOS_TRACE_LEVEL_WARN,
             "%s: Invalid context, pAdapter [%p] magic [%08x]",
              __func__, pAdapter, pStatsContext->magic);
      if (ioctl_debug)
      {
         pr_info("%s: Invalid context, pAdapter [%p] magic [%08x]\n",
                 __func__, pAdapter, pStatsContext->magic);
      }
      return;
   }

   /* the race is on.  caller could have timed out immediately after
      we verified the magic, but if so, caller will wait a short time
      for us to copy over the rssi */
   pAdapter->rssi = rssi;

   /* and notify the caller */
   complete(&pStatsContext->completion);
}



VOS_STATUS wlan_hdd_get_roam_rssi(hdd_adapter_t *pAdapter, v_S7_t *rssi_value)
{
   struct statsContext context;
   hdd_context_t *pHddCtx = NULL;
   hdd_station_ctx_t *pHddStaCtx = NULL;
   eHalStatus hstatus;
   long lrc;

   if (NULL == pAdapter)
   {
       hddLog(VOS_TRACE_LEVEL_WARN,
              "%s: Invalid context, pAdapter", __func__);
       return VOS_STATUS_E_FAULT;
   }
   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
   {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR, "%s:LOGP in Progress. Ignore!!!",__func__);
       /* return a cached value */
       *rssi_value = pAdapter->rssi;
       return VOS_STATUS_SUCCESS;
   }

   pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
   pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

   if(eConnectionState_Associated != pHddStaCtx->conn_info.connState)
   {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "%s:Not associated!",__func__);
       /* return a cached value */
       *rssi_value = 0;
       return VOS_STATUS_SUCCESS;
   }
   init_completion(&context.completion);
   context.pAdapter = pAdapter;
   context.magic = RSSI_CONTEXT_MAGIC;

   hstatus = sme_GetRoamRssi(pHddCtx->hHal, hdd_GetRoamRssiCB,
                         pHddStaCtx->conn_info.staId[ 0 ],
                         pHddStaCtx->conn_info.bssId,
                         &context, pHddCtx->pvosContext);
   if (eHAL_STATUS_SUCCESS != hstatus)
   {
       hddLog(VOS_TRACE_LEVEL_ERROR,"%s: Unable to retrieve RSSI",
              __func__);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       /* we'll returned a cached value below */
   }
   else
   {
       /* request was sent -- wait for the response */
       lrc = wait_for_completion_interruptible_timeout(&context.completion,
                                    msecs_to_jiffies(WLAN_WAIT_TIME_STATS));
       /* either we have a response or we timed out
          either way, first invalidate our magic */
       context.magic = 0;
       if (lrc <= 0)
       {
          hddLog(VOS_TRACE_LEVEL_ERROR,"%s: SME %s while retrieving RSSI ",
<<<<<<< HEAD
<<<<<<< HEAD
                 __FUNCTION__, (0 == lrc) ? "timeout" : "interrupt");
=======
                 __func__, (0 == lrc) ? "timeout" : "interrupt");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                 __func__, (0 == lrc) ? "timeout" : "interrupt");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
          /* there is a race condition such that the callback
             function could be executing at the same time we are. of
             primary concern is if the callback function had already
             verified the "magic" but hasn't yet set the completion
             variable.  Since the completion variable is on our
             stack, we'll delay just a bit to make sure the data is
             still valid if that is the case */
          msleep(50);
          /* we'll now returned a cached value below */
       }
   }
   *rssi_value = pAdapter->rssi;

   return VOS_STATUS_SUCCESS;
}
<<<<<<< HEAD
<<<<<<< HEAD
=======
#endif

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#endif

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

void hdd_StatisticsCB( void *pStats, void *pContext )
{
   hdd_adapter_t             *pAdapter      = (hdd_adapter_t *)pContext;
   hdd_stats_t               *pStatsCache   = NULL;
   hdd_wext_state_t *pWextState;
   VOS_STATUS vos_status = VOS_STATUS_SUCCESS;

   tCsrSummaryStatsInfo      *pSummaryStats = NULL;
   tCsrGlobalClassAStatsInfo *pClassAStats  = NULL;
   tCsrGlobalClassBStatsInfo *pClassBStats  = NULL;
   tCsrGlobalClassCStatsInfo *pClassCStats  = NULL;
   tCsrGlobalClassDStatsInfo *pClassDStats  = NULL;
   tCsrPerStaStatsInfo       *pPerStaStats  = NULL;

   if (pAdapter!= NULL)
     pStatsCache = &pAdapter->hdd_stats;


   pSummaryStats = (tCsrSummaryStatsInfo *)pStats;
   pClassAStats  = (tCsrGlobalClassAStatsInfo *)( pSummaryStats + 1 );
   pClassBStats  = (tCsrGlobalClassBStatsInfo *)( pClassAStats + 1 );
   pClassCStats  = (tCsrGlobalClassCStatsInfo *)( pClassBStats + 1 );
   pClassDStats  = (tCsrGlobalClassDStatsInfo *)( pClassCStats + 1 );
   pPerStaStats  = (tCsrPerStaStatsInfo *)( pClassDStats + 1 );

   if (pStatsCache!=NULL)
   {
      // and copy the stats into the cache we keep in the adapter instance structure
      vos_mem_copy( &pStatsCache->summary_stat, pSummaryStats, sizeof( pStatsCache->summary_stat ) );
      vos_mem_copy( &pStatsCache->ClassA_stat, pClassAStats, sizeof( pStatsCache->ClassA_stat ) );
      vos_mem_copy( &pStatsCache->ClassB_stat, pClassBStats, sizeof( pStatsCache->ClassB_stat ) );
      vos_mem_copy( &pStatsCache->ClassC_stat, pClassCStats, sizeof( pStatsCache->ClassC_stat ) );
      vos_mem_copy( &pStatsCache->ClassD_stat, pClassDStats, sizeof( pStatsCache->ClassD_stat ) );
      vos_mem_copy( &pStatsCache->perStaStats, pPerStaStats, sizeof( pStatsCache->perStaStats ) );
   }

    if(pAdapter)
    {
        pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
        if(pWextState)
        {
           vos_status = vos_event_set(&pWextState->vosevent);
           if (!VOS_IS_STATUS_SUCCESS(vos_status))
           {
              VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
<<<<<<< HEAD
<<<<<<< HEAD
                        "%s: vos_event_set failed", __FUNCTION__);
=======
                        "%s: vos_event_set failed", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                        "%s: vos_event_set failed", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
              return;
           }
        }
    }
}

void ccmCfgSetCallback(tHalHandle halHandle, tANI_S32 result)
{
   v_CONTEXT_t pVosContext;
   hdd_context_t *pHddCtx;
   VOS_STATUS hdd_reconnect_all_adapters( hdd_context_t *pHddCtx );
#if 0
   hdd_wext_state_t *pWextState;
   v_U32_t roamId;
#endif

   ENTER();

   pVosContext = vos_get_global_context(VOS_MODULE_ID_SYS,NULL);

   pHddCtx = (hdd_context_t*) vos_get_context(VOS_MODULE_ID_HDD,pVosContext);
   if (NULL == pHddCtx)
   {
<<<<<<< HEAD
<<<<<<< HEAD
      hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid pHddCtx", __FUNCTION__);
=======
      hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid pHddCtx", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
      hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Invalid pHddCtx", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
      return;
   }
#if 0
   pWextState = pAdapter->pWextState;
#endif

   if (WNI_CFG_NEED_RESTART == result || WNI_CFG_NEED_RELOAD == result)
   {
      //TODO Verify is this is really used. If yes need to fix it.
      hdd_reconnect_all_adapters( pHddCtx );
#if 0
      pAdapter->conn_info.connState = eConnectionState_NotConnected;
      INIT_COMPLETION(pAdapter->disconnect_comp_var);
      vosStatus = sme_RoamDisconnect(halHandle, pAdapter->sessionId, eCSR_DISCONNECT_REASON_UNSPECIFIED);

      if(VOS_STATUS_SUCCESS == vosStatus)
          wait_for_completion_interruptible_timeout(&pAdapter->disconnect_comp_var,
                     msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));

      sme_RoamConnect(halHandle,
                     pAdapter->sessionId, &(pWextState->roamProfile),
                     &roamId);
#endif
   }

   EXIT();

}

void hdd_clearRoamProfileIe( hdd_adapter_t *pAdapter)
{
   int i = 0;
   hdd_wext_state_t *pWextState= WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);

   /* clear WPA/RSN/WSC IE information in the profile */
   pWextState->roamProfile.nWPAReqIELength = 0;
   pWextState->roamProfile.pWPAReqIE = (tANI_U8 *)NULL;
   pWextState->roamProfile.nRSNReqIELength = 0;
   pWextState->roamProfile.pRSNReqIE = (tANI_U8 *)NULL;

   pWextState->roamProfile.bWPSAssociation = VOS_FALSE;
   pWextState->roamProfile.pAddIEScan = (tANI_U8 *)NULL;
   pWextState->roamProfile.nAddIEScanLength = 0;
   pWextState->roamProfile.pAddIEAssoc = (tANI_U8 *)NULL;
   pWextState->roamProfile.nAddIEAssocLength = 0;

   pWextState->roamProfile.EncryptionType.numEntries = 1;
   pWextState->roamProfile.EncryptionType.encryptionType[0]
                                                     = eCSR_ENCRYPT_TYPE_NONE;

   pWextState->roamProfile.mcEncryptionType.numEntries = 1;
   pWextState->roamProfile.mcEncryptionType.encryptionType[0]
                                                     = eCSR_ENCRYPT_TYPE_NONE;

   pWextState->roamProfile.AuthType.numEntries = 1;
   pWextState->roamProfile.AuthType.authType[0] = eCSR_AUTH_TYPE_OPEN_SYSTEM;

   pWextState->authKeyMgmt = 0;

   for (i=0; i < CSR_MAX_NUM_KEY; i++)
   {
      if (pWextState->roamProfile.Keys.KeyMaterial[i])
      {
         pWextState->roamProfile.Keys.KeyLength[i] = 0;
      }
   }
#ifdef FEATURE_WLAN_WAPI
   pAdapter->wapi_info.wapiAuthMode = WAPI_AUTH_MODE_OPEN;
   pAdapter->wapi_info.nWapiMode = 0;
#endif

   vos_mem_zero((void *)(pWextState->req_bssId), WNI_CFG_BSSID_LEN);

}

void wlan_hdd_ula_done_cb(v_VOID_t *callbackContext)
{
    hdd_adapter_t *pAdapter = (hdd_adapter_t*)callbackContext;
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_wext_state_t *pWextState= WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);

    complete(&pWextState->completion_var);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    if (WLAN_HDD_ADAPTER_MAGIC != pAdapter->magic)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                  "%s: Invalid pAdapter magic", __func__);
    }
    else
    {
        complete(&pAdapter->ula_complete);
    }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
}

VOS_STATUS wlan_hdd_check_ula_done(hdd_adapter_t *pAdapter)
{
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
<<<<<<< HEAD
<<<<<<< HEAD
    hdd_wext_state_t  *pWextState =  WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    VOS_STATUS vos_status;

    if (VOS_FALSE == pHddStaCtx->conn_info.uIsAuthenticated)
    {
        INIT_COMPLETION(pWextState->completion_var);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    VOS_STATUS vos_status;
    unsigned long rc;

    if (VOS_FALSE == pHddStaCtx->conn_info.uIsAuthenticated)
    {
        INIT_COMPLETION(pAdapter->ula_complete);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        /*To avoid race condition between the set key and the last EAPOL
          packet, notify TL to finish upper layer authentication incase if the
          last EAPOL packet pending in the TL queue.*/
<<<<<<< HEAD
<<<<<<< HEAD
        vos_status = WLANTL_Finish_ULA(wlan_hdd_ula_done_cb,pAdapter);
=======
        vos_status = WLANTL_Finish_ULA(wlan_hdd_ula_done_cb, pAdapter);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        vos_status = WLANTL_Finish_ULA(wlan_hdd_ula_done_cb, pAdapter);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        if ( vos_status != VOS_STATUS_SUCCESS )
        {
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "[%4d] WLANTL_Finish_ULA returned ERROR status= %d",
                   __LINE__, vos_status );
            return vos_status;

        }

<<<<<<< HEAD
<<<<<<< HEAD
        wait_for_completion_timeout(&pWextState->completion_var,
                                    msecs_to_jiffies(HDD_FINISH_ULA_TIME_OUT));
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        rc = wait_for_completion_timeout(&pAdapter->ula_complete,
                                    msecs_to_jiffies(HDD_FINISH_ULA_TIME_OUT));
        if (0 == rc)
        {
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                      "%s: Timeout waiting for ULA to complete", __func__);
            /* we'll still fall through and return success since the
             * connection may still get established but is just taking
             * too long for us to wait */
        }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
    return VOS_STATUS_SUCCESS;
}

v_U8_t* wlan_hdd_get_vendor_oui_ie_ptr(v_U8_t *oui, v_U8_t oui_size, v_U8_t *ie, int ie_len)
{

    int left = ie_len;
    v_U8_t *ptr = ie;
    v_U8_t elem_id,elem_len;
    v_U8_t eid = 0xDD;

    if ( NULL == ie || 0 == ie_len )
       return NULL;

    while(left >= 2)
    {
        elem_id  = ptr[0];
        elem_len = ptr[1];
        left -= 2;
        if(elem_len > left)
        {
            hddLog(VOS_TRACE_LEVEL_FATAL,
                   FL("****Invalid IEs eid = %d elem_len=%d left=%d*****"),
                    eid,elem_len,left);
            return NULL;
        }
        if (elem_id == eid)
        {
            if(memcmp( &ptr[2], oui, oui_size)==0)
                return ptr;
        }

        left -= elem_len;
        ptr += (elem_len + 2);
    }
    return NULL;
}

static int iw_set_commit(struct net_device *dev, struct iw_request_info *info,
                         union iwreq_data *wrqu, char *extra)
{
<<<<<<< HEAD
<<<<<<< HEAD
    hddLog( LOG1, "In %s\n", __FUNCTION__);
=======
    hddLog( LOG1, "In %s\n", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    hddLog( LOG1, "In %s\n", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    /* Do nothing for now */
    return 0;
}

static int iw_get_name(struct net_device *dev,
                       struct iw_request_info *info,
                       char *wrqu, char *extra)
{

    ENTER();
    strlcpy(wrqu, "Qcom:802.11n", IFNAMSIZ);
    EXIT();
    return 0;
}

static int iw_set_mode(struct net_device *dev,
                             struct iw_request_info *info,
                             union iwreq_data *wrqu, char *extra)
{
    hdd_wext_state_t         *pWextState;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tCsrRoamProfile          *pRoamProfile;
    eCsrRoamBssType          LastBSSType;
    eMib_dot11DesiredBssType connectedBssType;
    hdd_config_t             *pConfig;
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef CONFIG_CFG80211
    struct wireless_dev      *wdev;
#endif
=======
    struct wireless_dev      *wdev;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    struct wireless_dev      *wdev;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    ENTER();

    if (NULL == pAdapter)
    {
        hddLog(VOS_TRACE_LEVEL_WARN,
               "%s: Invalid context, pAdapter", __func__);
        return 0;
    }

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress) {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
       return 0;
    }

    pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    if (pWextState == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog (LOGE, "%s ERROR: Data Storage Corruption", __FUNCTION__);
        return -EINVAL;
    }

#ifdef CONFIG_CFG80211
    wdev = dev->ieee80211_ptr;
#endif
    pRoamProfile = &pWextState->roamProfile;
    LastBSSType = pRoamProfile->BSSType;

    hddLog( LOG1,"%s Old Bss type = %d", __FUNCTION__, LastBSSType);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        hddLog (LOGE, "%s ERROR: Data Storage Corruption", __func__);
        return -EINVAL;
    }

    wdev = dev->ieee80211_ptr;
    pRoamProfile = &pWextState->roamProfile;
    LastBSSType = pRoamProfile->BSSType;

    hddLog( LOG1,"%s Old Bss type = %d", __func__, LastBSSType);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    switch (wrqu->mode)
    {
    case IW_MODE_ADHOC:
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog( LOG1,"%s Setting AP Mode as IW_MODE_ADHOC", __FUNCTION__);
=======
        hddLog( LOG1,"%s Setting AP Mode as IW_MODE_ADHOC", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        hddLog( LOG1,"%s Setting AP Mode as IW_MODE_ADHOC", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        pRoamProfile->BSSType = eCSR_BSS_TYPE_START_IBSS;
        // Set the phymode correctly for IBSS.
        pConfig  = (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini;
        pWextState->roamProfile.phyMode = hdd_cfg_xlate_to_csr_phy_mode(pConfig->dot11Mode);
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef CONFIG_CFG80211
        wdev->iftype = NL80211_IFTYPE_ADHOC;
#endif
        break;
    case IW_MODE_INFRA:
        hddLog( LOG1, "%s Setting AP Mode as IW_MODE_INFRA", __FUNCTION__);
        pRoamProfile->BSSType = eCSR_BSS_TYPE_INFRASTRUCTURE;
#ifdef CONFIG_CFG80211
        wdev->iftype = NL80211_IFTYPE_STATION;
#endif
        break;
    case IW_MODE_AUTO:
        hddLog(LOG1,"%s Setting AP Mode as IW_MODE_AUTO", __FUNCTION__);
        pRoamProfile->BSSType = eCSR_BSS_TYPE_ANY;
        break;
    default:
        hddLog(LOG1,"%s Unknown AP Mode value", __FUNCTION__);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        wdev->iftype = NL80211_IFTYPE_ADHOC;
        break;
    case IW_MODE_INFRA:
        hddLog( LOG1, "%s Setting AP Mode as IW_MODE_INFRA", __func__);
        pRoamProfile->BSSType = eCSR_BSS_TYPE_INFRASTRUCTURE;
        wdev->iftype = NL80211_IFTYPE_STATION;
        break;
    case IW_MODE_AUTO:
        hddLog(LOG1,"%s Setting AP Mode as IW_MODE_AUTO", __func__);
        pRoamProfile->BSSType = eCSR_BSS_TYPE_ANY;
        break;
    default:
        hddLog(LOG1,"%s Unknown AP Mode value", __func__);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return -EOPNOTSUPP;
    }

    if ( LastBSSType != pRoamProfile->BSSType )
    {
        //the BSS mode changed
        // We need to issue disconnect if connected or in IBSS disconnect state
        if ( hdd_connGetConnectedBssType( WLAN_HDD_GET_STATION_CTX_PTR(pAdapter), &connectedBssType ) ||
             ( eCSR_BSS_TYPE_START_IBSS == LastBSSType ) )
        {
            VOS_STATUS vosStatus;
            // need to issue a disconnect to CSR.
            INIT_COMPLETION(pAdapter->disconnect_comp_var);
            vosStatus = sme_RoamDisconnect( WLAN_HDD_GET_HAL_CTX(pAdapter),
                                          pAdapter->sessionId,
                                          eCSR_DISCONNECT_REASON_IBSS_LEAVE );
            if(VOS_STATUS_SUCCESS == vosStatus)
                 wait_for_completion_interruptible_timeout(&pAdapter->disconnect_comp_var,
                     msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));
        }
    }



    EXIT();
    return 0;
}


static int iw_get_mode(struct net_device *dev,
                             struct iw_request_info *info,
                             v_U32_t *uwrq, char *extra)
{

    hdd_wext_state_t *pWextState;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);

<<<<<<< HEAD
<<<<<<< HEAD
    hddLog (LOG1, "In %s",__FUNCTION__);
=======
    hddLog (LOG1, "In %s",__func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    hddLog (LOG1, "In %s",__func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    if (NULL == pAdapter)
    {
        hddLog(VOS_TRACE_LEVEL_WARN,
               "%s: Invalid context, pAdapter", __func__);
        return 0;
    }

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress) {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
       return 0;
    }

    pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    if (pWextState == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog (LOGE, "%s ERROR: Data Storage Corruption", __FUNCTION__);
=======
        hddLog (LOGE, "%s ERROR: Data Storage Corruption", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        hddLog (LOGE, "%s ERROR: Data Storage Corruption", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return -EINVAL;
    }

    switch (pWextState->roamProfile.BSSType)
    {
    case eCSR_BSS_TYPE_INFRASTRUCTURE:
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(LOG1, "%s returns IW_MODE_INFRA\n", __FUNCTION__);
=======
        hddLog(LOG1, "%s returns IW_MODE_INFRA\n", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        hddLog(LOG1, "%s returns IW_MODE_INFRA\n", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        *uwrq = IW_MODE_INFRA ;
        break;
    case eCSR_BSS_TYPE_IBSS:
    case eCSR_BSS_TYPE_START_IBSS:
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog( LOG1,"%s returns IW_MODE_ADHOC\n", __FUNCTION__);
        *uwrq= IW_MODE_ADHOC;
        break;
    case eCSR_BSS_TYPE_ANY:
        hddLog( LOG1,"%s returns IW_MODE_AUTO\n", __FUNCTION__);
        *uwrq= IW_MODE_AUTO;
        break;
    default:
        hddLog( LOG1,"%s returns APMODE_UNKNOWN\n", __FUNCTION__);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        hddLog( LOG1,"%s returns IW_MODE_ADHOC\n", __func__);
        *uwrq= IW_MODE_ADHOC;
        break;
    case eCSR_BSS_TYPE_ANY:
        hddLog( LOG1,"%s returns IW_MODE_AUTO\n", __func__);
        *uwrq= IW_MODE_AUTO;
        break;
    default:
        hddLog( LOG1,"%s returns APMODE_UNKNOWN\n", __func__);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        break;
    }
    return 0;
}

static int iw_set_freq(struct net_device *dev, struct iw_request_info *info,
             union iwreq_data *wrqu, char *extra)
{
    v_U32_t numChans = 0;
    v_U8_t validChan[WNI_CFG_VALID_CHANNEL_LIST_LEN];
    v_U32_t indx = 0;
    v_U32_t status = 0;

    hdd_wext_state_t *pWextState;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    tCsrRoamProfile * pRoamProfile;
    ENTER();

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress) {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
       return status;
    }

    pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);

    pRoamProfile = &pWextState->roamProfile;

    hddLog(LOG1,"setCHANNEL ioctl\n");

    /* Link is up then return cant set channel*/
    if(eConnectionState_IbssConnected == pHddStaCtx->conn_info.connState ||
       eConnectionState_Associated == pHddStaCtx->conn_info.connState)
    {
        hddLog( LOGE, "IBSS Associated\n");
        return -EOPNOTSUPP;
    }

    /* Settings by Frequency as input */
    if((wrqu->freq.e == 1) && (wrqu->freq.m >= (tANI_U32)2.412e8) &&
                            (wrqu->freq.m <= (tANI_U32)5.825e8))
    {
        tANI_U32 freq = wrqu->freq.m / 100000;

        while ((indx <  FREQ_CHAN_MAP_TABLE_SIZE) && (freq != freq_chan_map[indx].freq))
            indx++;
        if (indx >= FREQ_CHAN_MAP_TABLE_SIZE)
        {
            return -EINVAL;
        }
        wrqu->freq.e = 0;
        wrqu->freq.m = freq_chan_map[indx].chan;

    }

    if (wrqu->freq.e == 0)
    {
        if((wrqu->freq.m < WNI_CFG_CURRENT_CHANNEL_STAMIN) ||
                        (wrqu->freq.m > WNI_CFG_CURRENT_CHANNEL_STAMAX))
        {
            hddLog(LOG1,"%s: Channel [%d] is outside valid range from %d to %d\n",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__, wrqu->freq.m, WNI_CFG_CURRENT_CHANNEL_STAMIN,
=======
                __func__, wrqu->freq.m, WNI_CFG_CURRENT_CHANNEL_STAMIN,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                __func__, wrqu->freq.m, WNI_CFG_CURRENT_CHANNEL_STAMIN,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                    WNI_CFG_CURRENT_CHANNEL_STAMAX);
             return -EINVAL;
        }

        numChans = WNI_CFG_VALID_CHANNEL_LIST_LEN;

        if (ccmCfgGetStr(hHal, WNI_CFG_VALID_CHANNEL_LIST,
                validChan, &numChans) != eHAL_STATUS_SUCCESS){
            return -EIO;
        }

        for (indx = 0; indx < numChans; indx++) {
            if (wrqu->freq.m == validChan[indx]){
                break;
            }
        }
    }
    else{

        return -EINVAL;
    }

    if(indx >= numChans)
    {
        return -EINVAL;
    }

    /* Set the Operational Channel */
    numChans = pRoamProfile->ChannelInfo.numOfChannels = 1;
    pHddStaCtx->conn_info.operationChannel = wrqu->freq.m;
    pRoamProfile->ChannelInfo.ChannelList = &pHddStaCtx->conn_info.operationChannel;

    hddLog(LOG1,"pRoamProfile->operationChannel  = %d\n", wrqu->freq.m);

    EXIT();

    return status;
}

static int iw_get_freq(struct net_device *dev, struct iw_request_info *info,
             struct iw_freq *fwrq, char *extra)
{
   v_U32_t status = FALSE, channel = 0, freq = 0;
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   tHalHandle hHal;
   hdd_wext_state_t *pWextState;
   tCsrRoamProfile * pRoamProfile;
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

   ENTER();

   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress) {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
      return status;
   }

   pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
   hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);

   pRoamProfile = &pWextState->roamProfile;

   if( pHddStaCtx->conn_info.connState== eConnectionState_Associated )
   {
       if (sme_GetOperationChannel(hHal, &channel, pAdapter->sessionId) != eHAL_STATUS_SUCCESS)
       {
           return -EIO;
       }
       else
       {
           status = hdd_wlan_get_freq(channel, &freq);
           if( TRUE == status )
           {
               /* Set Exponent parameter as 6 (MHZ) in struct iw_freq
                * iwlist & iwconfig command shows frequency into proper
                * format (2.412 GHz instead of 246.2 MHz)*/
               fwrq->m = freq;
               fwrq->e = MHZ;
           }
       }
    }
    else
    {
<<<<<<< HEAD
<<<<<<< HEAD
       channel = pHddStaCtx->conn_info.operationChannel;
       status = hdd_wlan_get_freq(channel, &freq);
       if( TRUE == status )
       {
          /* Set Exponent parameter as 6 (MHZ) in struct iw_freq
           * iwlist & iwconfig command shows frequency into proper
           * format (2.412 GHz instead of 246.2 MHz)*/
           fwrq->m = freq;
           fwrq->e = MHZ;
       }
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       /* Set Exponent parameter as 6 (MHZ) in struct iw_freq
        * iwlist & iwconfig command shows frequency into proper
        * format (2.412 GHz instead of 246.2 MHz)*/
       fwrq->m = 0;
       fwrq->e = MHZ;
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
   return 0;
}

static int iw_get_tx_power(struct net_device *dev,
                           struct iw_request_info *info,
                           union iwreq_data *wrqu, char *extra)
{

   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

   if (pHddCtx->isLogpInProgress)
   {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
              "%s:LOGP in Progress. Ignore!!!",__func__);
      return -EBUSY;
   }

   if(eConnectionState_Associated != pHddStaCtx->conn_info.connState)
   {
      wrqu->txpower.value = 0;
      return 0;
   }
   wlan_hdd_get_classAstats(pAdapter);
   wrqu->txpower.value = pAdapter->hdd_stats.ClassA_stat.max_pwr;

   return 0;
}

static int iw_set_tx_power(struct net_device *dev,
                           struct iw_request_info *info,
                           union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
       return 0;
    }

    ENTER();

    if ( ccmCfgSetInt(hHal, WNI_CFG_CURRENT_TX_POWER_LEVEL, wrqu->txpower.value, ccmCfgSetCallback, eANI_BOOLEAN_TRUE) != eHAL_STATUS_SUCCESS )
    {
        return -EIO;
    }

    EXIT();

    return 0;
}

static int iw_get_bitrate(struct net_device *dev,
                          struct iw_request_info *info,
                          union iwreq_data *wrqu, char *extra)
{
   VOS_STATUS vos_status = VOS_STATUS_SUCCESS;
   eHalStatus status = eHAL_STATUS_SUCCESS;
   hdd_wext_state_t *pWextState;
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

   ENTER();

   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress) {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
      return status;
   }

   if(eConnectionState_Associated != pHddStaCtx->conn_info.connState) {
        wrqu->bitrate.value = 0;
   }
   else {
      status = sme_GetStatistics( WLAN_HDD_GET_HAL_CTX(pAdapter), eCSR_HDD,
                               SME_SUMMARY_STATS       |
                               SME_GLOBAL_CLASSA_STATS |
                               SME_GLOBAL_CLASSB_STATS |
                               SME_GLOBAL_CLASSC_STATS |
                               SME_GLOBAL_CLASSD_STATS |
                               SME_PER_STA_STATS,
                               hdd_StatisticsCB, 0, FALSE,
                               pHddStaCtx->conn_info.staId[0], pAdapter );

      if(eHAL_STATUS_SUCCESS != status)
      {
         hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: Unable to retrieve statistics",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__);
=======
                __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
         return status;
      }

      pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);

      vos_status = vos_wait_single_event(&pWextState->vosevent, WLAN_WAIT_TIME_STATS);

      if (!VOS_IS_STATUS_SUCCESS(vos_status))
      {
         hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: SME timeout while retrieving statistics",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__);
=======
                __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
         return VOS_STATUS_E_FAILURE;
      }

      wrqu->bitrate.value = pAdapter->hdd_stats.ClassA_stat.tx_rate*500*1000;
   }

   EXIT();

   return vos_status;
}
/* ccm call back function */

static int iw_set_bitrate(struct net_device *dev,
                          struct iw_request_info *info,
                          union iwreq_data *wrqu,
                          char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_wext_state_t *pWextState;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    v_U8_t supp_rates[WNI_CFG_SUPPORTED_RATES_11A_LEN];
    v_U32_t a_len = WNI_CFG_SUPPORTED_RATES_11A_LEN;
    v_U32_t b_len = WNI_CFG_SUPPORTED_RATES_11B_LEN;
    v_U32_t i, rate;
    v_U32_t valid_rate = FALSE, active_phy_mode = 0;

    ENTER();

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress) {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
       return 0;
    }

    pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);

    if (eConnectionState_Associated != pHddStaCtx->conn_info.connState)
    {
        return -ENXIO ;
    }

    rate = wrqu->bitrate.value;

    if (rate == -1)
    {
        rate = WNI_CFG_FIXED_RATE_AUTO;
        valid_rate = TRUE;
    }
    else if (ccmCfgGetInt(WLAN_HDD_GET_HAL_CTX(pAdapter),
                        WNI_CFG_DOT11_MODE, &active_phy_mode) == eHAL_STATUS_SUCCESS)
    {
        if (active_phy_mode == WNI_CFG_DOT11_MODE_11A || active_phy_mode == WNI_CFG_DOT11_MODE_11G
            || active_phy_mode == WNI_CFG_DOT11_MODE_11B)
        {
            if ((ccmCfgGetStr(WLAN_HDD_GET_HAL_CTX(pAdapter),
                        WNI_CFG_SUPPORTED_RATES_11A,
                        supp_rates, &a_len) == eHAL_STATUS_SUCCESS) &&
                (ccmCfgGetStr(WLAN_HDD_GET_HAL_CTX(pAdapter),
                        WNI_CFG_SUPPORTED_RATES_11B,
                        supp_rates, &b_len) == eHAL_STATUS_SUCCESS))
            {
                for (i = 0; i < (b_len + a_len); ++i)
                {
                    /* supported rates returned is double the actual rate so we divide it by 2 */
                    if ((supp_rates[i]&0x7F)/2 == rate)
                    {
                        valid_rate = TRUE;
                        rate = i + WNI_CFG_FIXED_RATE_1MBPS;
                        break;
                    }
                }
            }
        }
    }
    if (valid_rate != TRUE)
    {
        return -EINVAL;
    }
    if (ccmCfgSetInt(WLAN_HDD_GET_HAL_CTX(pAdapter),
                     WNI_CFG_FIXED_RATE, rate,
                     ccmCfgSetCallback,eANI_BOOLEAN_FALSE) != eHAL_STATUS_SUCCESS)
    {
        return -EIO;
    }
    return 0;
}


static int iw_set_genie(struct net_device *dev,
        struct iw_request_info *info,
        union iwreq_data *wrqu,
        char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    u_int8_t *genie;
    v_U16_t remLen;

   ENTER();
   if(!wrqu->data.length) {
      hdd_clearRoamProfileIe(pAdapter);
      EXIT();
      return 0;
   }

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress) {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
      return 0;
   }

    genie = wrqu->data.pointer;
    remLen = wrqu->data.length;

    hddLog(LOG1,"iw_set_genie ioctl IE[0x%X], LEN[%d]\n", genie[0], genie[1]);

    /* clear any previous genIE before this call */
    memset( &pWextState->genIE, 0, sizeof(pWextState->genIE) );

    while (remLen >= 2)
   {
        v_U16_t eLen = 0;
        v_U8_t elementId;
        elementId = *genie++;
        eLen  = *genie++;
        remLen -= 2;

        hddLog(VOS_TRACE_LEVEL_INFO, "%s: IE[0x%X], LEN[%d]\n",
            __func__, elementId, eLen);

        switch ( elementId )
         {
            case IE_EID_VENDOR:
                if ((IE_LEN_SIZE+IE_EID_SIZE+IE_VENDOR_OUI_SIZE) > eLen) /* should have at least OUI */
                return -EINVAL;

                if (0 == memcmp(&genie[0], "\x00\x50\xf2\x04", 4))
                {
                    v_U16_t curGenIELen = pWextState->genIE.length;
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set WPS OUI(%02x %02x %02x %02x) IE(len %d)",
                            __func__, genie[0], genie[1], genie[2], genie[3], eLen + 2);

                    if( SIR_MAC_MAX_IE_LENGTH < (pWextState->genIE.length + eLen) )
                    {
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accommodate genIE. "
                                                      "Need bigger buffer space\n");
                       VOS_ASSERT(0);
                       return -ENOMEM;
                    }
                    // save to Additional IE ; it should be accumulated to handle WPS IE + other IE
                    memcpy( pWextState->genIE.addIEdata + curGenIELen, genie - 2, eLen + 2);
                    pWextState->genIE.length += eLen + 2;
                }
                else if (0 == memcmp(&genie[0], "\x00\x50\xf2", 3))
                {
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set WPA IE (len %d)",__func__, eLen + 2);
                    memset( pWextState->WPARSNIE, 0, MAX_WPA_RSN_IE_LEN );
                    memcpy( pWextState->WPARSNIE, genie - 2, (eLen + 2));
                    pWextState->roamProfile.pWPAReqIE = pWextState->WPARSNIE;
                    pWextState->roamProfile.nWPAReqIELength = eLen + 2;
                }
                else /* any vendorId except WPA IE should be accumulated to genIE */
                {
                    v_U16_t curGenIELen = pWextState->genIE.length;
                    hddLog (VOS_TRACE_LEVEL_INFO, "%s Set OUI(%02x %02x %02x %02x) IE(len %d)",
                            __func__, genie[0], genie[1], genie[2], genie[3], eLen + 2);

                    if( SIR_MAC_MAX_IE_LENGTH < (pWextState->genIE.length + eLen) )
                    {
                       hddLog(VOS_TRACE_LEVEL_FATAL, "Cannot accommodate genIE. "
                                                      "Need bigger buffer space\n");
                       VOS_ASSERT(0);
                       return -ENOMEM;
                    }
                    // save to Additional IE ; it should be accumulated to handle WPS IE + other IE
                    memcpy( pWextState->genIE.addIEdata + curGenIELen, genie - 2, eLen + 2);
                    pWextState->genIE.length += eLen + 2;
                }
              break;
         case DOT11F_EID_RSN:
<<<<<<< HEAD
<<<<<<< HEAD
                hddLog (LOG1, "%s Set RSN IE (len %d)",__FUNCTION__, eLen+2);
=======
                hddLog (LOG1, "%s Set RSN IE (len %d)",__func__, eLen+2);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                hddLog (LOG1, "%s Set RSN IE (len %d)",__func__, eLen+2);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                memset( pWextState->WPARSNIE, 0, MAX_WPA_RSN_IE_LEN );
                memcpy( pWextState->WPARSNIE, genie - 2, (eLen + 2));
                pWextState->roamProfile.pRSNReqIE = pWextState->WPARSNIE;
                pWextState->roamProfile.nRSNReqIELength = eLen + 2;
              break;

         default:
<<<<<<< HEAD
<<<<<<< HEAD
                hddLog (LOGE, "%s Set UNKNOWN IE %X",__FUNCTION__, elementId);
=======
                hddLog (LOGE, "%s Set UNKNOWN IE %X",__func__, elementId);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                hddLog (LOGE, "%s Set UNKNOWN IE %X",__func__, elementId);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            return 0;
    }
        genie += eLen;
        remLen -= eLen;
    }
    EXIT();
    return 0;
}

static int iw_get_genie(struct net_device *dev,
                        struct iw_request_info *info,
                        union iwreq_data *wrqu,
                        char *extra)
{
    hdd_wext_state_t *pWextState;
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    eHalStatus status;
    v_U32_t length = DOT11F_IE_RSN_MAX_LEN;
    v_U8_t genIeBytes[DOT11F_IE_RSN_MAX_LEN];

    ENTER();

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress) {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
       return 0;
    }


    hddLog(LOG1,"getGEN_IE ioctl\n");

    pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);

    if( pHddStaCtx->conn_info.connState == eConnectionState_NotConnected)
    {
        return -ENXIO;
    }

    // Return something ONLY if we are associated with an RSN or WPA network
    if ( VOS_TRUE != hdd_IsAuthTypeRSN(WLAN_HDD_GET_HAL_CTX(pAdapter),
                                                pWextState->roamProfile.negotiatedAuthType))
    {
        return -ENXIO;
    }

    // Actually retrieve the RSN IE from CSR.  (We previously sent it down in the CSR Roam Profile.)
    status = csrRoamGetWpaRsnReqIE(WLAN_HDD_GET_HAL_CTX(pAdapter),
                                   pAdapter->sessionId,
                                   &length,
                                   genIeBytes);
    wrqu->data.length = VOS_MIN((u_int16_t) length, DOT11F_IE_RSN_MAX_LEN);

    vos_mem_copy( wrqu->data.pointer, (v_VOID_t*)genIeBytes, wrqu->data.length);

<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(LOG1,"%s: RSN IE of %d bytes returned\n", __FUNCTION__, wrqu->data.length );
=======
    hddLog(LOG1,"%s: RSN IE of %d bytes returned\n", __func__, wrqu->data.length );
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    hddLog(LOG1,"%s: RSN IE of %d bytes returned\n", __func__, wrqu->data.length );
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    EXIT();

    return 0;
}

static int iw_get_encode(struct net_device *dev,
                       struct iw_request_info *info,
                       struct iw_point *dwrq, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    tCsrRoamProfile *pRoamProfile = &(pWextState->roamProfile);
    int keyId;
    eCsrAuthType authType = eCSR_AUTH_TYPE_NONE;
    int i;

    ENTER();

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress) {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
       return 0;
    }

    keyId = pRoamProfile->Keys.defaultIndex;

    if(keyId < 0 || keyId >= MAX_WEP_KEYS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(LOG1,"%s: Invalid keyId : %d\n",__FUNCTION__,keyId);
=======
        hddLog(LOG1,"%s: Invalid keyId : %d\n",__func__,keyId);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        hddLog(LOG1,"%s: Invalid keyId : %d\n",__func__,keyId);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return -EINVAL;
    }

    if(pRoamProfile->Keys.KeyLength[keyId] > 0)
    {
        dwrq->flags |= IW_ENCODE_ENABLED;
        dwrq->length = pRoamProfile->Keys.KeyLength[keyId];
        vos_mem_copy(extra,&(pRoamProfile->Keys.KeyMaterial[keyId][0]),pRoamProfile->Keys.KeyLength[keyId]);

        dwrq->flags |= (keyId + 1);

    }
    else
    {
        dwrq->flags |= IW_ENCODE_DISABLED;
    }

    for(i=0; i < MAX_WEP_KEYS; i++)
    {
        if(pRoamProfile->Keys.KeyMaterial[i] == NULL)
        {
            continue;
        }
        else
        {
            break;
        }
    }

    if(MAX_WEP_KEYS == i)
    {
        dwrq->flags |= IW_ENCODE_NOKEY;
    }

    authType = ((hdd_station_ctx_t*)WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.authType;

    if(eCSR_AUTH_TYPE_OPEN_SYSTEM == authType)
    {
        dwrq->flags |= IW_ENCODE_OPEN;
    }
    else
    {
        dwrq->flags |= IW_ENCODE_RESTRICTED;
    }
    EXIT();
    return 0;
}

#define PAE_ROLE_AUTHENTICATOR 1 // =1 for authenticator,
#define PAE_ROLE_SUPPLICANT 0 // =0 for supplicant


/*
 * This function sends a single 'key' to LIM at all time.
 */

static int iw_get_rts_threshold(struct net_device *dev,
            struct iw_request_info *info,
            union iwreq_data *wrqu, char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   v_U32_t status = 0;

   status = hdd_wlan_get_rts_threshold(pAdapter,wrqu);

   return status;
}

static int iw_set_rts_threshold(struct net_device *dev,
                                struct iw_request_info *info,
                                union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);

    ENTER();

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
            "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EAGAIN;
    }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if ( wrqu->rts.value < WNI_CFG_RTS_THRESHOLD_STAMIN || wrqu->rts.value > WNI_CFG_RTS_THRESHOLD_STAMAX )
    {
        return -EINVAL;
    }

    if ( ccmCfgSetInt(hHal, WNI_CFG_RTS_THRESHOLD, wrqu->rts.value, ccmCfgSetCallback, eANI_BOOLEAN_TRUE) != eHAL_STATUS_SUCCESS )
    {
        return -EIO;
    }

    EXIT();

    return 0;
}

static int iw_get_frag_threshold(struct net_device *dev,
                                 struct iw_request_info *info,
                                 union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    v_U32_t status = 0;

    status = hdd_wlan_get_frag_threshold(pAdapter,wrqu);

    return status;
}

static int iw_set_frag_threshold(struct net_device *dev,
             struct iw_request_info *info,
                 union iwreq_data *wrqu, char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);

   ENTER();

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
   {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if ( wrqu->frag.value < WNI_CFG_FRAGMENTATION_THRESHOLD_STAMIN || wrqu->frag.value > WNI_CFG_FRAGMENTATION_THRESHOLD_STAMAX )
    {
        return -EINVAL;
    }

    if ( ccmCfgSetInt(hHal, WNI_CFG_FRAGMENTATION_THRESHOLD, wrqu->frag.value, ccmCfgSetCallback, eANI_BOOLEAN_TRUE) != eHAL_STATUS_SUCCESS )
    {
        return -EIO;
    }

   EXIT();

   return 0;
}

static int iw_get_power_mode(struct net_device *dev,
                             struct iw_request_info *info,
                             union iwreq_data *wrqu, char *extra)
{
   ENTER();
   return -EOPNOTSUPP;
}

static int iw_set_power_mode(struct net_device *dev,
                             struct iw_request_info *info,
                             union iwreq_data *wrqu, char *extra)
{
    ENTER();
    return -EOPNOTSUPP;
}

static int iw_get_range(struct net_device *dev, struct iw_request_info *info,
                        union iwreq_data *wrqu, char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
   struct iw_range *range = (struct iw_range *) extra;

   v_U8_t channels[WNI_CFG_VALID_CHANNEL_LIST_LEN];

   v_U32_t num_channels = sizeof(channels);
   v_U8_t supp_rates[WNI_CFG_SUPPORTED_RATES_11A_LEN];
   v_U32_t a_len;
   v_U32_t b_len;
   v_U32_t active_phy_mode = 0;
   v_U8_t index = 0, i;

   ENTER();

   wrqu->data.length = sizeof(struct iw_range);
   memset(range, 0, sizeof(struct iw_range));

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
   {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
      return -EBUSY;
   }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

   /*Get the phy mode*/
   if (ccmCfgGetInt(hHal,
                  WNI_CFG_DOT11_MODE, &active_phy_mode) == eHAL_STATUS_SUCCESS)
   {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                "active_phy_mode = %ld", active_phy_mode);

      if (active_phy_mode == WNI_CFG_DOT11_MODE_11A || active_phy_mode == WNI_CFG_DOT11_MODE_11G)
      {
         /*Get the supported rates for 11G band*/
<<<<<<< HEAD
<<<<<<< HEAD
=======
         a_len = WNI_CFG_SUPPORTED_RATES_11A_LEN;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
         a_len = WNI_CFG_SUPPORTED_RATES_11A_LEN;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
         if (ccmCfgGetStr(hHal,
                          WNI_CFG_SUPPORTED_RATES_11A,
                          supp_rates, &a_len) == eHAL_STATUS_SUCCESS)
         {
            if (a_len > WNI_CFG_SUPPORTED_RATES_11A_LEN)
            {
               a_len = WNI_CFG_SUPPORTED_RATES_11A_LEN;
            }
            for (i = 0; i < a_len; i++)
            {
               range->bitrate[i] = ((supp_rates[i] & 0x7F) / 2) * 1000000;
            }
            range->num_bitrates = a_len;
         }
         else
         {
            return -EIO;
         }
      }
      else if (active_phy_mode == WNI_CFG_DOT11_MODE_11B)
      {
         /*Get the supported rates for 11B band*/
<<<<<<< HEAD
<<<<<<< HEAD
=======
         b_len = WNI_CFG_SUPPORTED_RATES_11B_LEN;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
         b_len = WNI_CFG_SUPPORTED_RATES_11B_LEN;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
         if (ccmCfgGetStr(hHal,
                          WNI_CFG_SUPPORTED_RATES_11B,
                          supp_rates, &b_len) == eHAL_STATUS_SUCCESS)
         {
            if (b_len > WNI_CFG_SUPPORTED_RATES_11B_LEN)
            {
               b_len = WNI_CFG_SUPPORTED_RATES_11B_LEN;
            }
            for (i = 0; i < b_len; i++)
            {
               range->bitrate[i] = ((supp_rates[i] & 0x7F) / 2) * 1000000;
            }
            range->num_bitrates = b_len;
         }
         else
         {
            return -EIO;
         }
      }
   }

   range->max_rts = WNI_CFG_RTS_THRESHOLD_STAMAX;
   range->min_frag = WNI_CFG_FRAGMENTATION_THRESHOLD_STAMIN;
   range->max_frag = WNI_CFG_FRAGMENTATION_THRESHOLD_STAMAX;

   range->encoding_size[0] = 5;
   range->encoding_size[1] = 13;
   range->num_encoding_sizes = 2;
   range->max_encoding_tokens = MAX_WEP_KEYS;

   // we support through Wireless Extensions 22
   range->we_version_compiled = WIRELESS_EXT;
   range->we_version_source = 22;

   /*Supported Channels and Frequencies*/
   if (ccmCfgGetStr((hHal), WNI_CFG_VALID_CHANNEL_LIST, channels, &num_channels) != eHAL_STATUS_SUCCESS)
   {
      return -EIO;
   }
   if (num_channels > IW_MAX_FREQUENCIES)
   {
      num_channels = IW_MAX_FREQUENCIES;
   }

   range->num_channels = num_channels;
   range->num_frequency = num_channels;

   for (index=0; index < num_channels; index++)
   {
      v_U32_t frq_indx = 0;

      range->freq[index].i = channels[index];
      while (frq_indx <  FREQ_CHAN_MAP_TABLE_SIZE)
      {
           if(channels[index] == freq_chan_map[frq_indx].chan)
           {
             range->freq[index].m = freq_chan_map[frq_indx].freq * 100000;
             range->freq[index].e = 1;
             break;
           }
           frq_indx++;
      }
   }

   /* Event capability (kernel + driver) */
   range->event_capa[0] = (IW_EVENT_CAPA_K_0 |
                    IW_EVENT_CAPA_MASK(SIOCGIWAP) |
                    IW_EVENT_CAPA_MASK(SIOCGIWSCAN));
   range->event_capa[1] = IW_EVENT_CAPA_K_1;

   /*Encryption capability*/
   range->enc_capa = IW_ENC_CAPA_WPA | IW_ENC_CAPA_WPA2 |
                IW_ENC_CAPA_CIPHER_TKIP | IW_ENC_CAPA_CIPHER_CCMP;

   /* Txpower capability */
   range->txpower_capa = IW_TXPOW_MWATT;

   /*Scanning capability*/
   #if WIRELESS_EXT >= 22
   range->scan_capa = IW_SCAN_CAPA_ESSID | IW_SCAN_CAPA_TYPE | IW_SCAN_CAPA_CHANNEL;
   #endif

   EXIT();
   return 0;
}

/* Callback function registered with PMC to know status of PMC request */
static void iw_power_callback_fn (void *pContext, eHalStatus status)
{
   struct statsContext *pStatsContext;
   hdd_adapter_t *pAdapter;

   if (NULL == pContext)
   {
       hddLog(VOS_TRACE_LEVEL_ERROR,
            "%s: Bad param, pContext [%p]",
<<<<<<< HEAD
<<<<<<< HEAD
              __FUNCTION__, pContext);
=======
              __func__, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
              __func__, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       return;
   }

  /* there is a race condition that exists between this callback function
     and the caller since the caller could time out either before or
     while this code is executing.  we'll assume the timeout hasn't
     occurred, but we'll verify that right before we save our work */

   pStatsContext = (struct statsContext *)pContext;
   pAdapter = pStatsContext->pAdapter;

   if ((NULL == pAdapter) || (POWER_CONTEXT_MAGIC != pStatsContext->magic))
   {
       /* the caller presumably timed out so there is nothing we can do */
       hddLog(VOS_TRACE_LEVEL_WARN,
           "%s: Invalid context, pAdapter [%p] magic [%08x]",
<<<<<<< HEAD
<<<<<<< HEAD
           __FUNCTION__, pAdapter, pStatsContext->magic);
=======
           __func__, pAdapter, pStatsContext->magic);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
           __func__, pAdapter, pStatsContext->magic);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

       if (ioctl_debug)
       {
           pr_info("%s: Invalid context, pAdapter [%p] magic [%08x]\n",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, pAdapter, pStatsContext->magic);
=======
             __func__, pAdapter, pStatsContext->magic);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
             __func__, pAdapter, pStatsContext->magic);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       }
       return;
  }

  /* and notify the caller */
  complete(&pStatsContext->completion);
}

/* Callback function for tx per hit */
void hdd_tx_per_hit_cb (void *pCallbackContext)
{
    hdd_adapter_t *pAdapter = (hdd_adapter_t *)pCallbackContext;
    unsigned char tx_fail[16];
    union iwreq_data wrqu;

    if (NULL == pAdapter)
    {
        hddLog(LOGE, "hdd_tx_per_hit_cb: pAdapter is NULL\n");
        return;
    }
    memset(&wrqu, 0, sizeof(wrqu));
    wrqu.data.length = strlcpy(tx_fail, "TX_FAIL", sizeof(tx_fail));
    wireless_send_event(pAdapter->dev, IWEVCUSTOM, &wrqu, tx_fail);
}

void hdd_GetClassA_statisticsCB(void *pStats, void *pContext)
{
   struct statsContext *pStatsContext;
   tCsrGlobalClassAStatsInfo *pClassAStats;
   hdd_adapter_t *pAdapter;

   if (ioctl_debug)
   {
      pr_info("%s: pStats [%p] pContext [%p]\n",
<<<<<<< HEAD
<<<<<<< HEAD
              __FUNCTION__, pStats, pContext);
=======
              __func__, pStats, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
              __func__, pStats, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   }

   if ((NULL == pStats) || (NULL == pContext))
   {
      hddLog(VOS_TRACE_LEVEL_ERROR,
             "%s: Bad param, pStats [%p] pContext [%p]",
<<<<<<< HEAD
<<<<<<< HEAD
              __FUNCTION__, pStats, pContext);
=======
              __func__, pStats, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
              __func__, pStats, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
      return;
   }

   /* there is a race condition that exists between this callback function
      and the caller since the caller could time out either before or
      while this code is executing.  we'll assume the timeout hasn't
      occurred, but we'll verify that right before we save our work */

   pClassAStats  = pStats;
   pStatsContext = pContext;
   pAdapter      = pStatsContext->pAdapter;
   if ((NULL == pAdapter) || (STATS_CONTEXT_MAGIC != pStatsContext->magic))
   {
      /* the caller presumably timed out so there is nothing we can do */
      hddLog(VOS_TRACE_LEVEL_WARN,
             "%s: Invalid context, pAdapter [%p] magic [%08x]",
<<<<<<< HEAD
<<<<<<< HEAD
              __FUNCTION__, pAdapter, pStatsContext->magic);
      if (ioctl_debug)
      {
         pr_info("%s: Invalid context, pAdapter [%p] magic [%08x]\n",
                 __FUNCTION__, pAdapter, pStatsContext->magic);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
              __func__, pAdapter, pStatsContext->magic);
      if (ioctl_debug)
      {
         pr_info("%s: Invalid context, pAdapter [%p] magic [%08x]\n",
                 __func__, pAdapter, pStatsContext->magic);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
      }
      return;
   }

   /* the race is on.  caller could have timed out immediately after
      we verified the magic, but if so, caller will wait a short time
      for us to copy over the stats. do so as a struct copy */
   pAdapter->hdd_stats.ClassA_stat = *pClassAStats;

   /* and notify the caller */
   complete(&pStatsContext->completion);
}

VOS_STATUS  wlan_hdd_get_classAstats(hdd_adapter_t *pAdapter)
{
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   eHalStatus hstatus;
   long lrc;
   struct statsContext context;

   if (NULL == pAdapter)
   {
       hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Padapter is NULL", __func__);
       return VOS_STATUS_E_FAULT;
   }
   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
   {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR, "%s:LOGP in Progress. Ignore!!!",__func__);
       return VOS_STATUS_SUCCESS;
   }

   /* we are connected
   prepare our callback context */
   init_completion(&context.completion);
   context.pAdapter = pAdapter;
   context.magic = STATS_CONTEXT_MAGIC;
   /* query only for Class A statistics (which include link speed) */
   hstatus = sme_GetStatistics( WLAN_HDD_GET_HAL_CTX(pAdapter),
                                  eCSR_HDD,
                                  SME_GLOBAL_CLASSA_STATS,
                                  hdd_GetClassA_statisticsCB,
                                  0, // not periodic
                                  FALSE, //non-cached results
                                  pHddStaCtx->conn_info.staId[0],
                                  &context);
   if (eHAL_STATUS_SUCCESS != hstatus)
   {
       hddLog(VOS_TRACE_LEVEL_ERROR,
               "%s: Unable to retrieve Class A statistics ",
<<<<<<< HEAD
<<<<<<< HEAD
               __FUNCTION__);
=======
               __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
               __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       /* we'll returned a cached value below */
   }
   else
   {
       /* request was sent -- wait for the response */
       lrc = wait_for_completion_interruptible_timeout(&context.completion,
                                    msecs_to_jiffies(WLAN_WAIT_TIME_STATS));
       /* either we have a response or we timed out
          either way, first invalidate our magic */
       context.magic = 0;
       if (lrc <= 0)
       {
          hddLog(VOS_TRACE_LEVEL_ERROR,
                 "%s: SME %s while retrieving Class A statistics",
<<<<<<< HEAD
<<<<<<< HEAD
                 __FUNCTION__, (0 == lrc) ? "timeout" : "interrupt");
=======
                 __func__, (0 == lrc) ? "timeout" : "interrupt");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                 __func__, (0 == lrc) ? "timeout" : "interrupt");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
             /* there is a race condition such that the callback
             function could be executing at the same time we are. of
             primary concern is if the callback function had already
             verified the "magic" but hasn't yet set the completion
             variable.  Since the completion variable is on our
             stack, we'll delay just a bit to make sure the data is
             still valid if that is the case */
          msleep(50);
      }
   }
   return VOS_STATUS_SUCCESS;
}

static void hdd_get_station_statisticsCB(void *pStats, void *pContext)
{
   struct statsContext *pStatsContext;
   tCsrSummaryStatsInfo      *pSummaryStats;
   tCsrGlobalClassAStatsInfo *pClassAStats;
   hdd_adapter_t *pAdapter;

   if (ioctl_debug)
   {
      pr_info("%s: pStats [%p] pContext [%p]\n",
<<<<<<< HEAD
<<<<<<< HEAD
              __FUNCTION__, pStats, pContext);
=======
              __func__, pStats, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
              __func__, pStats, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   }

   if ((NULL == pStats) || (NULL == pContext))
   {
      hddLog(VOS_TRACE_LEVEL_ERROR,
             "%s: Bad param, pStats [%p] pContext [%p]",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, pStats, pContext);
=======
             __func__, pStats, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
             __func__, pStats, pContext);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
      return;
   }

   /* there is a race condition that exists between this callback function
      and the caller since the caller could time out either before or
      while this code is executing.  we'll assume the timeout hasn't
      occurred, but we'll verify that right before we save our work */

   pSummaryStats = (tCsrSummaryStatsInfo *)pStats;
   pClassAStats  = (tCsrGlobalClassAStatsInfo *)( pSummaryStats + 1 );
   pStatsContext = pContext;
   pAdapter      = pStatsContext->pAdapter;
   if ((NULL == pAdapter) || (STATS_CONTEXT_MAGIC != pStatsContext->magic))
   {
      /* the caller presumably timed out so there is nothing we can do */
      hddLog(VOS_TRACE_LEVEL_WARN,
             "%s: Invalid context, pAdapter [%p] magic [%08x]",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, pAdapter, pStatsContext->magic);
      if (ioctl_debug)
      {
         pr_info("%s: Invalid context, pAdapter [%p] magic [%08x]\n",
                 __FUNCTION__, pAdapter, pStatsContext->magic);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
             __func__, pAdapter, pStatsContext->magic);
      if (ioctl_debug)
      {
         pr_info("%s: Invalid context, pAdapter [%p] magic [%08x]\n",
                 __func__, pAdapter, pStatsContext->magic);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
      }
      return;
   }

   /* the race is on.  caller could have timed out immediately after
      we verified the magic, but if so, caller will wait a short time
      for us to copy over the stats. do so as a struct copy */
   pAdapter->hdd_stats.summary_stat = *pSummaryStats;
   pAdapter->hdd_stats.ClassA_stat = *pClassAStats;

   /* and notify the caller */
   complete(&pStatsContext->completion);
}

VOS_STATUS  wlan_hdd_get_station_stats(hdd_adapter_t *pAdapter)
{
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   eHalStatus hstatus;
   long lrc;
   struct statsContext context;

   if (NULL == pAdapter)
   {
       hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Padapter is NULL", __func__);
       return VOS_STATUS_SUCCESS;
   }

   /* we are connected
   prepare our callback context */
   init_completion(&context.completion);
   context.pAdapter = pAdapter;
   context.magic = STATS_CONTEXT_MAGIC;

   /* query only for Summary & Class A statistics */
   hstatus = sme_GetStatistics(WLAN_HDD_GET_HAL_CTX(pAdapter),
                               eCSR_HDD,
                               SME_SUMMARY_STATS |
                               SME_GLOBAL_CLASSA_STATS,
                               hdd_get_station_statisticsCB,
                               0, // not periodic
                               FALSE, //non-cached results
                               pHddStaCtx->conn_info.staId[0],
                               &context);
   if (eHAL_STATUS_SUCCESS != hstatus)
   {
      hddLog(VOS_TRACE_LEVEL_ERROR,
             "%s: Unable to retrieve statistics",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__);
=======
             __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
             __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
      /* we'll return with cached values */
   }
   else
   {
      /* request was sent -- wait for the response */
      lrc = wait_for_completion_interruptible_timeout(&context.completion,
                                    msecs_to_jiffies(WLAN_WAIT_TIME_STATS));
      /* either we have a response or we timed out
         either way, first invalidate our magic */
      context.magic = 0;
      if (lrc <= 0)
      {
         hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: SME %s while retrieving statistics",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__, (0 == lrc) ? "timeout" : "interrupt");
=======
                __func__, (0 == lrc) ? "timeout" : "interrupt");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                __func__, (0 == lrc) ? "timeout" : "interrupt");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
         /* there is a race condition such that the callback
            function could be executing at the same time we are. of
            primary concern is if the callback function had already
            verified the "magic" but hasn't yet set the completion
            variable.  Since the completion variable is on our
            stack, we'll delay just a bit to make sure the data is
            still valid if that is the case */
         msleep(50);
      }
   }
   return VOS_STATUS_SUCCESS;
}


/*
 * Support for the LINKSPEED private command
 * Per the WiFi framework the response must be of the form
 *         "LinkSpeed xx"
 */
static int iw_get_linkspeed(struct net_device *dev,
                            struct iw_request_info *info,
                            union iwreq_data *wrqu, char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
<<<<<<< HEAD
<<<<<<< HEAD
   char *pLinkSpeed = (char*)extra;
   int len = sizeof(v_U16_t) + 1;
   v_U16_t link_speed;
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   int rc;
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   hdd_context_t *pHddCtx;
   char *pLinkSpeed = (char*)extra;
   int len = sizeof(v_U32_t) + 1;
   v_U32_t link_speed;
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   VOS_STATUS status;
   int rc, valid;

   pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

   valid = wlan_hdd_validate_context(pHddCtx);

   if (0 != valid)
   {
       hddLog(VOS_TRACE_LEVEL_ERROR, FL("HDD context is not valid"));
       return valid;
   }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

   if (eConnectionState_Associated != pHddStaCtx->conn_info.connState)
   {
      /* we are not connected so we don't have a classAstats */
      link_speed = 0;
   }
   else
   {
<<<<<<< HEAD
<<<<<<< HEAD
       wlan_hdd_get_classAstats(pAdapter);
       //The linkspeed returned by HAL is in units of 500kbps.
       //converting it to mbps
       link_speed = pAdapter->hdd_stats.ClassA_stat.tx_rate/2;
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       status = wlan_hdd_get_classAstats(pAdapter);

       if (!VOS_IS_STATUS_SUCCESS(status ))
       {
           hddLog(VOS_TRACE_LEVEL_ERROR, FL("Unable to retrieve SME statistics"));
           return -EINVAL;
       }

       /* Unit of link capacity is obtained from the TL API is MbpsX10  */
       WLANTL_GetSTALinkCapacity(WLAN_HDD_GET_CTX(pAdapter)->pvosContext,
          (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.staId[0],
          &link_speed);

       link_speed = link_speed / 10;

       if (0 == link_speed)
       {
           /* The linkspeed returned by HAL is in units of 500kbps.
            * converting it to mbps.
            * This is required to support legacy firmware which does
            * not return link capacity.
            */
           link_speed = pAdapter->hdd_stats.ClassA_stat.tx_rate/2;
       }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   }

   wrqu->data.length = len;
   // return the linkspeed in the format required by the WiFi Framework
<<<<<<< HEAD
<<<<<<< HEAD
   rc = snprintf(pLinkSpeed, len, "%u", link_speed);
   if ((rc < 0) || (rc >= len))
   {
       // encoding or length error?
       hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: Unable to encode link speed, got [%s]",
                __FUNCTION__,pLinkSpeed);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   rc = snprintf(pLinkSpeed, len, "%lu", link_speed);
   if ((rc < 0) || (rc >= len))
   {
       // encoding or length error?
       hddLog(VOS_TRACE_LEVEL_ERROR,FL("Unable to encode link speed"));
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       return -EIO;
   }

  /* a value is being successfully returned */
   return 0;
}


/*
 * Support for the RSSI & RSSI-APPROX private commands
 * Per the WiFi framework the response must be of the form
 *         "<ssid> rssi <xx>"
 * unless we are not associated, in which case the response is
 *         "OK"
 */
static int iw_get_rssi(struct net_device *dev,
                       struct iw_request_info *info,
                       union iwreq_data *wrqu, char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   char *cmd = (char*)wrqu->data.pointer;
   int len = wrqu->data.length;
   v_S7_t s7Rssi = 0;
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   int ssidlen = pHddStaCtx->conn_info.SSID.SSID.length;
   VOS_STATUS vosStatus;
   int rc;

   if ((eConnectionState_Associated != pHddStaCtx->conn_info.connState) ||
       (0 == ssidlen) || (ssidlen >= len))
   {
      /* we are not connected or our SSID is too long
         so we cannot report an rssi */
<<<<<<< HEAD
<<<<<<< HEAD
      rc = snprintf(cmd, len, "OK");
=======
      rc = scnprintf(cmd, len, "OK");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
      rc = scnprintf(cmd, len, "OK");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   }
   else
   {
      /* we are connected with a valid SSID
         so we can write the SSID into the return buffer
         (note that it is not NUL-terminated) */
      memcpy(cmd, pHddStaCtx->conn_info.SSID.SSID.ssId, ssidlen );

      vosStatus = wlan_hdd_get_rssi(pAdapter, &s7Rssi);

      if (VOS_STATUS_SUCCESS == vosStatus)
      {
          /* append the rssi to the ssid in the format required by
             the WiFI Framework */
<<<<<<< HEAD
<<<<<<< HEAD
          rc = snprintf(&cmd[ssidlen], len - ssidlen, " rssi %d", s7Rssi);
=======
          rc = scnprintf(&cmd[ssidlen], len - ssidlen, " rssi %d", s7Rssi);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
          rc = scnprintf(&cmd[ssidlen], len - ssidlen, " rssi %d", s7Rssi);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
      }
      else
      {
          rc = -1;
      }
   }

   /* verify that we wrote a valid response */
   if ((rc < 0) || (rc >= len))
   {
      // encoding or length error?
      hddLog(VOS_TRACE_LEVEL_ERROR,
             "%s: Unable to encode RSSI, got [%s]",
<<<<<<< HEAD
<<<<<<< HEAD
             __FUNCTION__, cmd);
=======
             __func__, cmd);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
             __func__, cmd);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
      return -EIO;
   }

   /* a value is being successfully returned */
   return 0;
}

/*
 * Support for SoftAP channel range private command
 */
static int iw_softap_set_channel_range( struct net_device *dev,
                                        int startChannel,
                                        int endChannel,
                                        int band)
{
    VOS_STATUS status;
    int ret = 0;
    hdd_adapter_t *pHostapdAdapter = (netdev_priv(dev));
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pHostapdAdapter);
<<<<<<< HEAD
<<<<<<< HEAD
=======
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pHostapdAdapter);

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pHostapdAdapter);

>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    status = WLANSAP_SetChannelRange(hHal, startChannel, endChannel, band);
    if (VOS_STATUS_SUCCESS != status)
    {
        ret = -EINVAL;
    }
<<<<<<< HEAD
<<<<<<< HEAD
=======
    pHddCtx->is_dynamic_channel_range_set = 1;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    pHddCtx->is_dynamic_channel_range_set = 1;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    return ret;
}

VOS_STATUS  wlan_hdd_enter_bmps(hdd_adapter_t *pAdapter, int mode)
{
   struct statsContext context;
   eHalStatus status;
   hdd_context_t *pHddCtx;

   if (NULL == pAdapter)
   {
       hddLog(VOS_TRACE_LEVEL_FATAL, "Adapter NULL");
       return VOS_STATUS_E_FAULT;
   }

   hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "power mode=%d", mode);
   pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
   init_completion(&context.completion);

   context.pAdapter = pAdapter;
   context.magic = POWER_CONTEXT_MAGIC;

   if (DRIVER_POWER_MODE_ACTIVE == mode)
   {
       hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s:Wlan driver Entering "
               "Full Power", __func__);
       status = sme_RequestFullPower(WLAN_HDD_GET_HAL_CTX(pAdapter),
                       iw_power_callback_fn, &context,
                       eSME_FULL_PWR_NEEDED_BY_HDD);
       // Enter Full power command received from GUI this means we are disconnected
       // Set PMC remainInPowerActiveTillDHCP flag to disable auto BMPS entry by PMC
       sme_SetDHCPTillPowerActiveFlag(pHddCtx->hHal, TRUE);
       if (eHAL_STATUS_PMC_PENDING == status)
       {
           int lrc = wait_for_completion_interruptible_timeout(
                   &context.completion,
                   msecs_to_jiffies(WLAN_WAIT_TIME_POWER));
           context.magic = 0;
           if (lrc <= 0)
           {
               hddLog(VOS_TRACE_LEVEL_ERROR,"%s: SME %s while requesting fullpower ",
<<<<<<< HEAD
<<<<<<< HEAD
                  __FUNCTION__, (0 == lrc) ? "timeout" : "interrupt");
=======
                  __func__, (0 == lrc) ? "timeout" : "interrupt");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                  __func__, (0 == lrc) ? "timeout" : "interrupt");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
               /* there is a race condition such that the callback
                  function could be executing at the same time we are. of
                  primary concern is if the callback function had already
                  verified the "magic" but hasn't yet set the completion
                  variable. Since the completion variable is on our
                  stack, we'll delay just a bit to make sure the data is
                  still valid if that is the case */
               msleep(50);
               /* we'll now returned a cached value below */
           }
       }
   }
   else if (DRIVER_POWER_MODE_AUTO == mode)
   {
       if (pHddCtx->cfg_ini->fIsBmpsEnabled)
       {
           hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s:Wlan driver Entering Bmps ",
                  __func__);
           // Enter BMPS command received from GUI this means DHCP is completed
           // Clear PMC remainInPowerActiveTillDHCP flag to enable auto BMPS entry
           sme_SetDHCPTillPowerActiveFlag(WLAN_HDD_GET_HAL_CTX(pAdapter),
                    FALSE);
           status = sme_RequestBmps(WLAN_HDD_GET_HAL_CTX(pAdapter),
                           iw_power_callback_fn, &context);
           if (eHAL_STATUS_PMC_PENDING == status)
           {
               int lrc = wait_for_completion_interruptible_timeout(
                           &context.completion,
                           msecs_to_jiffies(WLAN_WAIT_TIME_POWER));
               context.magic = 0;
               if (lrc <= 0)
               {
                   hddLog(VOS_TRACE_LEVEL_ERROR,"%s: SME %s while requesting BMPS ",
<<<<<<< HEAD
<<<<<<< HEAD
                      __FUNCTION__, (0 == lrc) ? "timeout" : "interrupt");
=======
                      __func__, (0 == lrc) ? "timeout" : "interrupt");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                      __func__, (0 == lrc) ? "timeout" : "interrupt");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                   /* there is a race condition such that the callback
                      function could be executing at the same time we are. of
                      primary concern is if the callback function had already
                      verified the "magic" but hasn't yet set the completion
                      variable. Since the completion variable is on our
                      stack, we'll delay just a bit to make sure the data is
                      still valid if that is the case */
                   msleep(50);
                   /* we'll now returned a cached value below */
               }
           }
       }
       else
       {
           hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "BMPS is not "
                   "enabled in the cfg");
       }
   }
   return VOS_STATUS_SUCCESS;
}

VOS_STATUS wlan_hdd_exit_lowpower(hdd_context_t *pHddCtx,
                                       hdd_adapter_t *pAdapter)
{
   VOS_STATUS vos_Status;

   if ((NULL == pAdapter) || (NULL == pHddCtx))
   {
       hddLog(VOS_TRACE_LEVEL_FATAL, "Invalid pointer");
       return VOS_STATUS_E_FAULT;
   }

   /**Exit from Deep sleep or standby if we get the driver
   START cmd from android GUI
    */
   if (WLAN_MAP_DRIVER_STOP_TO_STANDBY == pHddCtx->cfg_ini->nEnableDriverStop)
   {
       hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: WLAN being exit "
              "from Stand by",__func__);
       vos_Status = hdd_exit_standby(pHddCtx);
   }
   else if (eHDD_SUSPEND_DEEP_SLEEP == pHddCtx->hdd_ps_state)
   {
       hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: WLAN being exit "
              "from deep sleep",__func__);
       vos_Status = hdd_exit_deep_sleep(pHddCtx, pAdapter);
   }
   else
   {
       hddLog(VOS_TRACE_LEVEL_WARN, "%s: Not in standby or deep sleep. "
               "Ignore start cmd %d", __func__, pHddCtx->hdd_ps_state);
       vos_Status = VOS_STATUS_SUCCESS;
   }

   return vos_Status;
}

VOS_STATUS wlan_hdd_enter_lowpower(hdd_context_t *pHddCtx)
{
   VOS_STATUS vos_Status = VOS_STATUS_E_FAILURE;

   if (NULL == pHddCtx)
   {
        hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "HDD context NULL");
        return VOS_STATUS_E_FAULT;
   }

   if (WLAN_MAP_DRIVER_STOP_TO_STANDBY == pHddCtx->cfg_ini->nEnableDriverStop)
   {
      //Execute standby procedure.
      //Executing standby procedure will cause the STA to
      //disassociate first and then the chip will be put into standby.
      hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "Wlan driver entering Stand by mode");
      vos_Status  = hdd_enter_standby(pHddCtx);
   }
   else if (WLAN_MAP_DRIVER_STOP_TO_DEEP_SLEEP ==
            pHddCtx->cfg_ini->nEnableDriverStop)
   {
       //Execute deep sleep procedure
       hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "Wlan driver entering "
               "deep sleep mode\n");
       //Deep sleep not supported
       vos_Status  = hdd_enter_standby(pHddCtx);
   }
   else
   {
       hddLog(VOS_TRACE_LEVEL_INFO_LOW, "%s: Driver stop is not enabled %d",
           __func__, pHddCtx->cfg_ini->nEnableDriverStop);
       vos_Status = VOS_STATUS_SUCCESS;
   }

   return vos_Status;
}


void* wlan_hdd_change_country_code_callback(void *pAdapter)
{

    hdd_adapter_t *call_back_pAdapter = pAdapter;
  
    complete(&call_back_pAdapter->change_country_code);

    return NULL;
}

static int iw_set_priv(struct net_device *dev,
                       struct iw_request_info *info,
                       union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
<<<<<<< HEAD
<<<<<<< HEAD
    char *cmd = (char*)wrqu->data.pointer;
    int cmd_len = wrqu->data.length;
=======
    int cmd_len = wrqu->data.length;
    char* cmd = (char *)kmalloc(cmd_len+1, GFP_KERNEL); //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    int cmd_len = wrqu->data.length;
    char* cmd = (char *)kmalloc(cmd_len+1, GFP_KERNEL); //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    int ret = 0;
    int status = 0;
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

    ENTER();

<<<<<<< HEAD
<<<<<<< HEAD
    if (ioctl_debug)
    {
       pr_info("%s: req [%s] len [%d]\n", __FUNCTION__, cmd, cmd_len);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    //IKHSS7-35965, a19091, Motorola changes -- BEGIN
    if(cmd == NULL){
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s Malloc failed for buff of size %d - ignoring ioctl!",
                __FUNCTION__, cmd_len);
        status = -ENOMEM;
        goto cleanup_and_return;
    }

    if(copy_from_user(cmd, (char*)(wrqu->data.pointer), cmd_len)) {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s -- copy_from_user --data pointer failed! bailing",
                __FUNCTION__);
        status = -EFAULT;
        goto cleanup_and_return;
    }
    //IKHSS7-35965, a19091, Motorola changes -- END

    if (ioctl_debug)
    {
       pr_info("%s: req [%s] len [%d]\n", __func__, cmd, cmd_len);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }

    hddLog(VOS_TRACE_LEVEL_INFO_MED,
           "%s: ***Received %s cmd from Wi-Fi GUI***", __func__, cmd);

    if (pHddCtx->isLogpInProgress) {
       if (ioctl_debug)
       {
<<<<<<< HEAD
<<<<<<< HEAD
          pr_info("%s: RESTART in progress\n", __FUNCTION__);
=======
          pr_info("%s: RESTART in progress\n", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
          pr_info("%s: RESTART in progress\n", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       }

       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                 "%s:LOGP in Progress. Ignore!!!",__func__);
<<<<<<< HEAD
<<<<<<< HEAD
       return status;
=======
       goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
       goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }

    if(strncmp(cmd, "CSCAN",5) == 0 )
    {
       status = iw_set_cscan(dev, info, wrqu, extra);
    }
    else if( strcasecmp(cmd, "start") == 0 ) {

        hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "Start command\n");
        /*Exit from Deep sleep or standby if we get the driver START cmd from android GUI*/
        status = wlan_hdd_exit_lowpower(pHddCtx, pAdapter);

        if(status == VOS_STATUS_SUCCESS)
        {
            union iwreq_data wrqu;
            char buf[10];

            memset(&wrqu, 0, sizeof(wrqu));
            wrqu.data.length = strlcpy(buf, "START", sizeof(buf));
            wireless_send_event(pAdapter->dev, IWEVCUSTOM, &wrqu, buf);
        }
        else
        {
            hddLog(VOS_TRACE_LEVEL_FATAL, "%s: START CMD Status %d", __func__, status);
        }
<<<<<<< HEAD
<<<<<<< HEAD
        goto done;
=======
        goto done; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto done; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
    else if( strcasecmp(cmd, "stop") == 0 )
    {
        union iwreq_data wrqu;
        char buf[10];

        hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "Stop command\n");

        wlan_hdd_enter_lowpower(pHddCtx);
        memset(&wrqu, 0, sizeof(wrqu));
        wrqu.data.length = strlcpy(buf, "STOP", sizeof(buf));
        wireless_send_event(pAdapter->dev, IWEVCUSTOM, &wrqu, buf);
        status = VOS_STATUS_SUCCESS;
<<<<<<< HEAD
<<<<<<< HEAD
        goto done;
=======
        goto done; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto done; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
    else if (strcasecmp(cmd, "macaddr") == 0)
    {
        ret = snprintf(cmd, cmd_len, "Macaddr = " MAC_ADDRESS_STR,
                       MAC_ADDR_ARRAY(pAdapter->macAddressCurrent.bytes));
    }
    else if (strcasecmp(cmd, "scan-active") == 0)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        pAdapter->scan_info.scan_mode = eSIR_ACTIVE_SCAN;
=======
        pHddCtx->scan_info.scan_mode = eSIR_ACTIVE_SCAN;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        pHddCtx->scan_info.scan_mode = eSIR_ACTIVE_SCAN;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        ret = snprintf(cmd, cmd_len, "OK");
    }
    else if (strcasecmp(cmd, "scan-passive") == 0)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        pAdapter->scan_info.scan_mode = eSIR_PASSIVE_SCAN;
=======
        pHddCtx->scan_info.scan_mode = eSIR_PASSIVE_SCAN;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        pHddCtx->scan_info.scan_mode = eSIR_PASSIVE_SCAN;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        ret = snprintf(cmd, cmd_len, "OK");
    }
    else if( strcasecmp(cmd, "scan-mode") == 0 )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        ret = snprintf(cmd, cmd_len, "ScanMode = %u", pAdapter->scan_info.scan_mode);
=======
        ret = snprintf(cmd, cmd_len, "ScanMode = %u", pHddCtx->scan_info.scan_mode);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        ret = snprintf(cmd, cmd_len, "ScanMode = %u", pHddCtx->scan_info.scan_mode);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
    else if( strcasecmp(cmd, "linkspeed") == 0 )
    {
        status = iw_get_linkspeed(dev, info, wrqu, extra);
    }
    else if( strncasecmp(cmd, "COUNTRY", 7) == 0 ) {
        char *country_code;
        long lrc;

        country_code =  cmd + 8;

        init_completion(&pAdapter->change_country_code);

        status = (int)sme_ChangeCountryCode(pHddCtx->hHal,
                                            (void *)(tSmeChangeCountryCallback)wlan_hdd_change_country_code_callback,
                                            country_code,
                                            pAdapter,
                                            pHddCtx->pvosContext);

        /* Wait for completion */
        lrc = wait_for_completion_interruptible_timeout(&pAdapter->change_country_code,
                                    msecs_to_jiffies(WLAN_WAIT_TIME_STATS));

        if (lrc <= 0)
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,"%s: SME %s while setting country code ",
<<<<<<< HEAD
<<<<<<< HEAD
                 __FUNCTION__, "Timed out");
=======
                 __func__, "Timed out");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                 __func__, "Timed out");
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        }

        if( 0 != status )
        {
            VOS_TRACE( VOS_MODULE_ID_VOSS, VOS_TRACE_LEVEL_ERROR,
                       "%s: SME Change Country code fail \n",__func__);
<<<<<<< HEAD
<<<<<<< HEAD
            return VOS_STATUS_E_FAILURE;
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
             //IKHSS7-35965, a19091, Motorola changes -- BEGIN
             status = VOS_STATUS_E_FAILURE;
             goto cleanup_and_return;
             //IKHSS7-35965, a19091, Motorola changes -- END
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        }
    }
    else if( strncasecmp(cmd, "rssi", 4) == 0 )
    {
        status = iw_get_rssi(dev, info, wrqu, extra);
    }
    else if( strncasecmp(cmd, "powermode", 9) == 0 ) {
        int mode;
        char *ptr = (char*)(cmd + 9);

        sscanf(ptr,"%d",&mode);
        wlan_hdd_enter_bmps(pAdapter, mode);
<<<<<<< HEAD
<<<<<<< HEAD
=======
		goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
		goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        /*TODO:Set the power mode*/
    }
    else if (strncasecmp(cmd, "getpower", 8) == 0 ) {
        v_U32_t pmc_state;
        v_U16_t value;

        pmc_state = pmcGetPmcState(WLAN_HDD_GET_HAL_CTX(pAdapter));
        if(pmc_state == BMPS) {
           value = DRIVER_POWER_MODE_AUTO;
        }
        else {
           value = DRIVER_POWER_MODE_ACTIVE;
        }
        ret = snprintf(cmd, cmd_len, "powermode = %u", value);
    }
    else if( strncasecmp(cmd, "btcoexmode", 10) == 0 ) {
        hddLog( VOS_TRACE_LEVEL_INFO, "btcoexmode\n");
<<<<<<< HEAD
<<<<<<< HEAD
=======
        goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        /*TODO: set the btcoexmode*/
    }
    else if( strcasecmp(cmd, "btcoexstat") == 0 ) {

        hddLog(VOS_TRACE_LEVEL_INFO, "BtCoex Status\n");
<<<<<<< HEAD
<<<<<<< HEAD
=======
        goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        /*TODO: Return the btcoex status*/
    }
    else if( strcasecmp(cmd, "rxfilter-start") == 0 ) {

        hddLog(VOS_TRACE_LEVEL_INFO, "Rx Data Filter Start command\n");
<<<<<<< HEAD
<<<<<<< HEAD
=======
        goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        /*TODO: Enable Rx data Filter*/
    }
    else if( strcasecmp(cmd, "rxfilter-stop") == 0 ) {

        hddLog(VOS_TRACE_LEVEL_INFO, "Rx Data Filter Stop command\n");
<<<<<<< HEAD
<<<<<<< HEAD

=======
        goto done;  //IKHSS7-35965, a19091, Motorola
		
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto done;  //IKHSS7-35965, a19091, Motorola
		
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        /*TODO: Disable Rx data Filter*/
    }
    else if( strcasecmp(cmd, "rxfilter-statistics") == 0 ) {

        hddLog( VOS_TRACE_LEVEL_INFO, "Rx Data Filter Statistics command\n");
<<<<<<< HEAD
<<<<<<< HEAD
=======
		goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
		goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        /*TODO: rxfilter-statistics*/
    }
    else if( strncasecmp(cmd, "rxfilter-add", 12) == 0 ) {

        hddLog( VOS_TRACE_LEVEL_INFO, "rxfilter-add\n");
<<<<<<< HEAD
<<<<<<< HEAD
=======
        goto done;  //IKHSS7-35965, a19091, Motorola		
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto done;  //IKHSS7-35965, a19091, Motorola		
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        /*TODO: rxfilter-add*/
    }
    else if( strncasecmp(cmd, "rxfilter-remove",15) == 0 ) {

        hddLog( VOS_TRACE_LEVEL_INFO, "rxfilter-remove\n");
<<<<<<< HEAD
<<<<<<< HEAD
=======
        goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto done;  //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        /*TODO: rxfilter-remove*/
    }
#ifdef FEATURE_WLAN_SCAN_PNO
    else if( strncasecmp(cmd, "pnosetup", 8) == 0 ) {
        hddLog( VOS_TRACE_LEVEL_INFO, "pnosetup");
<<<<<<< HEAD
<<<<<<< HEAD
=======
        goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        /*TODO: support pnosetup*/
    }
    else if( strncasecmp(cmd, "pnoforce", 8) == 0 ) {
        hddLog( VOS_TRACE_LEVEL_INFO, "pnoforce");
<<<<<<< HEAD
<<<<<<< HEAD
=======
        goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        /*TODO: support pnoforce*/
    }
    else if( strncasecmp(cmd, "pno",3) == 0 ) {

        hddLog( VOS_TRACE_LEVEL_INFO, "pno\n");
        status = iw_set_pno(dev, info, wrqu, extra, 3);
<<<<<<< HEAD
<<<<<<< HEAD
        return status;
=======
        goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
    else if( strncasecmp(cmd, "rssifilter",10) == 0 ) {

        hddLog( VOS_TRACE_LEVEL_INFO, "rssifilter\n");
        status = iw_set_rssi_filter(dev, info, wrqu, extra, 10);
<<<<<<< HEAD
<<<<<<< HEAD
        return status;
=======
        goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
#endif /*FEATURE_WLAN_SCAN_PNO*/
    else if( strncasecmp(cmd, "powerparams",11) == 0 ) {
      hddLog( VOS_TRACE_LEVEL_INFO, "powerparams\n");
      status = iw_set_power_params(dev, info, wrqu, extra, 11);
<<<<<<< HEAD
<<<<<<< HEAD
      return status;
=======
      goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
      goto cleanup_and_return; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
    else if( 0 == strncasecmp(cmd, "CONFIG-TX-TRACKING", 18) ) {
        tSirTxPerTrackingParam tTxPerTrackingParam;
        char *ptr = (char*)(cmd + 18);
        sscanf(ptr,"%hhu %hhu %hhu %lu",&(tTxPerTrackingParam.ucTxPerTrackingEnable), &(tTxPerTrackingParam.ucTxPerTrackingPeriod),
               &(tTxPerTrackingParam.ucTxPerTrackingRatio), &(tTxPerTrackingParam.uTxPerTrackingWatermark));

        // parameters checking
        // period has to be larger than 0
        if (0 == tTxPerTrackingParam.ucTxPerTrackingPeriod)
        {
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN, "Period input is not correct");
<<<<<<< HEAD
<<<<<<< HEAD
            return VOS_STATUS_E_FAILURE;
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            //IKHSS7-35965, a19091, Motorola changes -- BEGIN
            status = VOS_STATUS_E_FAILURE;
            goto cleanup_and_return;
            //IKHSS7-35965, a19091, Motorola changes -- END
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        }

        // use default value 5 is the input is not reasonable. in unit of 10%
        if ((tTxPerTrackingParam.ucTxPerTrackingRatio > TX_PER_TRACKING_MAX_RATIO) || (0 == tTxPerTrackingParam.ucTxPerTrackingRatio))
        {
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN, "Ratio input is not good. use default 5");
            tTxPerTrackingParam.ucTxPerTrackingRatio = TX_PER_TRACKING_DEFAULT_RATIO;
        }

        // default is 5
        if (0 == tTxPerTrackingParam.uTxPerTrackingWatermark)
        {
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN, "Tx Packet number input is not good. use default 5");
            tTxPerTrackingParam.uTxPerTrackingWatermark = TX_PER_TRACKING_DEFAULT_WATERMARK;
        }

        status = sme_SetTxPerTracking(pHddCtx->hHal, hdd_tx_per_hit_cb, (void*)pAdapter, &tTxPerTrackingParam);
        if(status != eHAL_STATUS_SUCCESS){
           VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN, "Set Tx PER Tracking Failed!");
        }
    }
    else {
        hddLog( VOS_TRACE_LEVEL_WARN, "%s: Unsupported GUI command %s",
                __func__, cmd);
    }
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    //IKHSS7-35965, a19091, Motorola changes -- BEGIN
    if(copy_to_user((char*)(wrqu->data.pointer), cmd, cmd_len)) {
        hddLog( VOS_TRACE_LEVEL_FATAL, "%s: COPY to user failed ... ignoring",__FUNCTION__);
    }
    //IKHSS7-35965, a19091, Motorola changes -- END
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
done:
    /* many of the commands write information back into the command
       string using snprintf().  check the return value here in one
       place */
    if ((ret < 0) || (ret >= cmd_len))
    {
       /* there was an encoding error or overflow */
       status = -EIO;
    }

    if (ioctl_debug)
    {
       pr_info("%s: rsp [%s] len [%d] status %d\n",
<<<<<<< HEAD
<<<<<<< HEAD
               __FUNCTION__, cmd, wrqu->data.length, status);
    }
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
               __func__, cmd, wrqu->data.length, status);
    }
    //IKHSS7-35965, a19091, Motorola changes -- BEGIN
cleanup_and_return:
    if(cmd != NULL) {
        kfree(cmd);
    }
    //IKHSS7-35965, a19091, Motorola changes -- END
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    return status;

}

static int iw_set_nick(struct net_device *dev,
                       struct iw_request_info *info,
                       union iwreq_data *wrqu, char *extra)
{
   ENTER();
   return 0;
}

static int iw_get_nick(struct net_device *dev,
                       struct iw_request_info *info,
                       union iwreq_data *wrqu, char *extra)
{
   ENTER();
   return 0;
}

static struct iw_statistics *get_wireless_stats(struct net_device *dev)
{
   ENTER();
   return NULL;
}

static int iw_set_encode(struct net_device *dev,struct iw_request_info *info,
                        union iwreq_data *wrqu,char *extra)

{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   hdd_wext_state_t  *pWextState =  WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
   struct iw_point *encoderq = &(wrqu->encoding);
   v_U32_t keyId;
   v_U8_t key_length;
   eCsrEncryptionType encryptionType = eCSR_ENCRYPT_TYPE_NONE;
   v_BOOL_t fKeyPresent = 0;
   int i;
   eHalStatus status = eHAL_STATUS_SUCCESS;


   ENTER();

   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
   {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!",__func__);
        return 0;
   }


   keyId = encoderq->flags & IW_ENCODE_INDEX;

   if(keyId)
   {
       if(keyId > MAX_WEP_KEYS)
       {
           return -EINVAL;
       }

       fKeyPresent = 1;
       keyId--;
   }
   else
   {
       fKeyPresent = 0;
   }


   if(wrqu->data.flags & IW_ENCODE_DISABLED)
   {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "****iwconfig wlan0 key off*****\n");
       if(!fKeyPresent) {

          for(i=0;i < CSR_MAX_NUM_KEY; i++) {

             if(pWextState->roamProfile.Keys.KeyMaterial[i])
                pWextState->roamProfile.Keys.KeyLength[i] = 0;
          }
       }
       pHddStaCtx->conn_info.authType =  eCSR_AUTH_TYPE_OPEN_SYSTEM;
       pWextState->wpaVersion = IW_AUTH_WPA_VERSION_DISABLED;
       pWextState->roamProfile.EncryptionType.encryptionType[0] = eCSR_ENCRYPT_TYPE_NONE;
       pWextState->roamProfile.mcEncryptionType.encryptionType[0] = eCSR_ENCRYPT_TYPE_NONE;

       pHddStaCtx->conn_info.ucEncryptionType = eCSR_ENCRYPT_TYPE_NONE;
       pHddStaCtx->conn_info.mcEncryptionType = eCSR_ENCRYPT_TYPE_NONE;

       if(eConnectionState_Associated == pHddStaCtx->conn_info.connState)
       {
           INIT_COMPLETION(pAdapter->disconnect_comp_var);
           status = sme_RoamDisconnect( WLAN_HDD_GET_HAL_CTX(pAdapter), pAdapter->sessionId, eCSR_DISCONNECT_REASON_UNSPECIFIED );
           if(eHAL_STATUS_SUCCESS == status)
                 wait_for_completion_interruptible_timeout(&pAdapter->disconnect_comp_var,
                     msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));
       }

       return status;

   }

   if (wrqu->data.flags & (IW_ENCODE_OPEN | IW_ENCODE_RESTRICTED))
   {
      hddLog(VOS_TRACE_LEVEL_INFO, "iwconfig wlan0 key on");

      pHddStaCtx->conn_info.authType = (encoderq->flags & IW_ENCODE_RESTRICTED) ? eCSR_AUTH_TYPE_SHARED_KEY : eCSR_AUTH_TYPE_OPEN_SYSTEM;

   }


   if(wrqu->data.length > 0)
   {
<<<<<<< HEAD
<<<<<<< HEAD
       hddLog(VOS_TRACE_LEVEL_INFO, "%s : wrqu->data.length : %d",__FUNCTION__,wrqu->data.length);
=======
       hddLog(VOS_TRACE_LEVEL_INFO, "%s : wrqu->data.length : %d",__func__,wrqu->data.length);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
       hddLog(VOS_TRACE_LEVEL_INFO, "%s : wrqu->data.length : %d",__func__,wrqu->data.length);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

       key_length = wrqu->data.length;

       /* IW_ENCODING_TOKEN_MAX is the value that is set for wrqu->data.length by iwconfig.c when 'iwconfig wlan0 key on' is issued.*/

       if(5 == key_length)
       {
<<<<<<< HEAD
<<<<<<< HEAD
           hddLog(VOS_TRACE_LEVEL_INFO, "%s: Call with WEP40,key_len=%d",__FUNCTION__,key_length);
=======
           hddLog(VOS_TRACE_LEVEL_INFO, "%s: Call with WEP40,key_len=%d",__func__,key_length);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
           hddLog(VOS_TRACE_LEVEL_INFO, "%s: Call with WEP40,key_len=%d",__func__,key_length);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

           if((IW_AUTH_KEY_MGMT_802_1X == pWextState->authKeyMgmt) && (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType))
           {
               encryptionType = eCSR_ENCRYPT_TYPE_WEP40;
           }
           else
           {
               encryptionType = eCSR_ENCRYPT_TYPE_WEP40_STATICKEY;
           }
       }
       else if(13 == key_length)
       {
<<<<<<< HEAD
<<<<<<< HEAD
           hddLog(VOS_TRACE_LEVEL_INFO, "%s:Call with WEP104,key_len:%d",__FUNCTION__,key_length);
=======
           hddLog(VOS_TRACE_LEVEL_INFO, "%s:Call with WEP104,key_len:%d",__func__,key_length);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
           hddLog(VOS_TRACE_LEVEL_INFO, "%s:Call with WEP104,key_len:%d",__func__,key_length);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

           if((IW_AUTH_KEY_MGMT_802_1X == pWextState->authKeyMgmt) && (eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType))
           {
               encryptionType = eCSR_ENCRYPT_TYPE_WEP104;
           }
           else
           {
               encryptionType = eCSR_ENCRYPT_TYPE_WEP104_STATICKEY;
           }
       }
       else
       {
           hddLog(VOS_TRACE_LEVEL_WARN, "%s: Invalid WEP key length :%d",
<<<<<<< HEAD
<<<<<<< HEAD
                  __FUNCTION__, key_length);
=======
                  __func__, key_length);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                  __func__, key_length);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           return -EINVAL;
       }

       pHddStaCtx->conn_info.ucEncryptionType = encryptionType;
       pHddStaCtx->conn_info.mcEncryptionType = encryptionType;
       pWextState->roamProfile.EncryptionType.numEntries = 1;
       pWextState->roamProfile.EncryptionType.encryptionType[0] = encryptionType;
       pWextState->roamProfile.mcEncryptionType.numEntries = 1;
       pWextState->roamProfile.mcEncryptionType.encryptionType[0] = encryptionType;

       if((eConnectionState_NotConnected == pHddStaCtx->conn_info.connState) &&
            ((eCSR_AUTH_TYPE_OPEN_SYSTEM == pHddStaCtx->conn_info.authType) ||
              (eCSR_AUTH_TYPE_SHARED_KEY == pHddStaCtx->conn_info.authType)))
       {

          vos_mem_copy(&pWextState->roamProfile.Keys.KeyMaterial[keyId][0],extra,key_length);

          pWextState->roamProfile.Keys.KeyLength[keyId] = (v_U8_t)key_length;
          pWextState->roamProfile.Keys.defaultIndex = (v_U8_t)keyId;

          return status;
       }
   }

   return 0;
}

static int iw_get_encodeext(struct net_device *dev,
               struct iw_request_info *info,
               struct iw_point *dwrq,
               char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_wext_state_t  *pWextState =  WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    tCsrRoamProfile *pRoamProfile = &(pWextState->roamProfile);
    int keyId;
    eCsrEncryptionType encryptionType = eCSR_ENCRYPT_TYPE_NONE;
    eCsrAuthType authType = eCSR_AUTH_TYPE_NONE;
    int i;

    ENTER();

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
              "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EBUSY;
    }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    keyId = pRoamProfile->Keys.defaultIndex;

    if(keyId < 0 || keyId >= MAX_WEP_KEYS)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(LOG1,"%s: Invalid keyId : %d\n",__FUNCTION__,keyId);
=======
        hddLog(LOG1,"%s: Invalid keyId : %d\n",__func__,keyId);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        hddLog(LOG1,"%s: Invalid keyId : %d\n",__func__,keyId);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return -EINVAL;
    }

    if(pRoamProfile->Keys.KeyLength[keyId] > 0)
    {
        dwrq->flags |= IW_ENCODE_ENABLED;
        dwrq->length = pRoamProfile->Keys.KeyLength[keyId];
        palCopyMemory(dev,extra,&(pRoamProfile->Keys.KeyMaterial[keyId][0]),pRoamProfile->Keys.KeyLength[keyId]);
    }
    else
    {
        dwrq->flags |= IW_ENCODE_DISABLED;
    }

    for(i=0; i < MAX_WEP_KEYS; i++)
    {
        if(pRoamProfile->Keys.KeyMaterial[i] == NULL)
        {
            continue;
        }
        else
        {
            break;
        }
    }

    if(MAX_WEP_KEYS == i)
    {
        dwrq->flags |= IW_ENCODE_NOKEY;
    }
    else
    {
        dwrq->flags |= IW_ENCODE_ENABLED;
    }

    encryptionType = pRoamProfile->EncryptionType.encryptionType[0];

    if(eCSR_ENCRYPT_TYPE_NONE == encryptionType)
    {
        dwrq->flags |= IW_ENCODE_DISABLED;
    }

    authType = (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.authType;

    if(IW_AUTH_ALG_OPEN_SYSTEM == authType)
    {
        dwrq->flags |= IW_ENCODE_OPEN;
    }
    else
    {
        dwrq->flags |= IW_ENCODE_RESTRICTED;
    }
    EXIT();
    return 0;

}

static int iw_set_encodeext(struct net_device *dev,
                        struct iw_request_info *info,
                        union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    hdd_wext_state_t  *pWextState =  WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    eHalStatus halStatus= eHAL_STATUS_SUCCESS;

    tCsrRoamProfile *pRoamProfile = &pWextState->roamProfile;
    v_U32_t status = 0;

    struct iw_encode_ext *ext = (struct iw_encode_ext*)extra;

    v_U8_t groupmacaddr[WNI_CFG_BSSID_LEN] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

    int key_index;
    struct iw_point *encoding = &wrqu->encoding;
    tCsrRoamSetKey  setKey;
    v_U32_t  roamId= 0xFF;
    VOS_STATUS vos_status;

    ENTER();

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!",__func__);
        return 0;
    }

    key_index = encoding->flags & IW_ENCODE_INDEX;

    if(key_index > 0) {

         /*Convert from 1-based to 0-based keying*/
        key_index--;
    }
    if(!ext->key_len) {

      /*Set the encrytion type to NONE*/
       pRoamProfile->EncryptionType.encryptionType[0] = eCSR_ENCRYPT_TYPE_NONE;
       return status;
    }

    if(eConnectionState_NotConnected == pHddStaCtx->conn_info.connState &&
                                                  (IW_ENCODE_ALG_WEP == ext->alg))
    {
       if(IW_AUTH_KEY_MGMT_802_1X == pWextState->authKeyMgmt) {

<<<<<<< HEAD
<<<<<<< HEAD
          VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,("Invalid Configuration:%s \n"),__FUNCTION__);
=======
          VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,("Invalid Configuration:%s \n"),__func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
          VOS_TRACE (VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,("Invalid Configuration:%s \n"),__func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
          return -EINVAL;
       }
       else {
         /*Static wep, update the roam profile with the keys */
          if(ext->key && (ext->key_len <= eCSR_SECURITY_WEP_KEYSIZE_MAX_BYTES) &&
                                                               key_index < CSR_MAX_NUM_KEY) {
             vos_mem_copy(&pRoamProfile->Keys.KeyMaterial[key_index][0],ext->key,ext->key_len);
             pRoamProfile->Keys.KeyLength[key_index] = (v_U8_t)ext->key_len;

             if(ext->ext_flags & IW_ENCODE_EXT_SET_TX_KEY)
                pRoamProfile->Keys.defaultIndex = (v_U8_t)key_index;

          }
       }
       return status;
    }

    vos_mem_zero(&setKey,sizeof(tCsrRoamSetKey));

    setKey.keyId = key_index;
    setKey.keyLength = ext->key_len;

    if(ext->key_len <= CSR_MAX_KEY_LEN) {
       vos_mem_copy(&setKey.Key[0],ext->key,ext->key_len);
    }

    if(ext->ext_flags & IW_ENCODE_EXT_GROUP_KEY) {
      /*Key direction for group is RX only*/
       setKey.keyDirection = eSIR_RX_ONLY;
       vos_mem_copy(setKey.peerMac,groupmacaddr,WNI_CFG_BSSID_LEN);
    }
    else {

       setKey.keyDirection =  eSIR_TX_RX;
       vos_mem_copy(setKey.peerMac,ext->addr.sa_data,WNI_CFG_BSSID_LEN);
    }

    /*For supplicant pae role is zero*/
    setKey.paeRole = 0;

    switch(ext->alg)
    {
       case IW_ENCODE_ALG_NONE:
         setKey.encType = eCSR_ENCRYPT_TYPE_NONE;
         break;

       case IW_ENCODE_ALG_WEP:
         setKey.encType = (ext->key_len== 5) ? eCSR_ENCRYPT_TYPE_WEP40:eCSR_ENCRYPT_TYPE_WEP104;
         break;

       case IW_ENCODE_ALG_TKIP:
       {
          v_U8_t *pKey = &setKey.Key[0];

          setKey.encType = eCSR_ENCRYPT_TYPE_TKIP;

          vos_mem_zero(pKey, CSR_MAX_KEY_LEN);

          /*Supplicant sends the 32bytes key in this order

                |--------------|----------|----------|
                |   Tk1        |TX-MIC    |  RX Mic  |
                |--------------|----------|----------|
                <---16bytes---><--8bytes--><--8bytes-->

                */
          /*Sme expects the 32 bytes key to be in the below order

                |--------------|----------|----------|
                |   Tk1        |RX-MIC    |  TX Mic  |
                |--------------|----------|----------|
                <---16bytes---><--8bytes--><--8bytes-->
               */
          /* Copy the Temporal Key 1 (TK1) */
          vos_mem_copy(pKey,ext->key,16);

         /*Copy the rx mic first*/
          vos_mem_copy(&pKey[16],&ext->key[24],8);

         /*Copy the tx mic */
          vos_mem_copy(&pKey[24],&ext->key[16],8);

       }
       break;

       case IW_ENCODE_ALG_CCMP:
          setKey.encType = eCSR_ENCRYPT_TYPE_AES;
          break;

#ifdef FEATURE_WLAN_CCX
#define IW_ENCODE_ALG_KRK 6
       case IW_ENCODE_ALG_KRK:
          setKey.encType = eCSR_ENCRYPT_TYPE_KRK;
          break;
#endif  /* FEATURE_WLAN_CCX */

       default:
          setKey.encType = eCSR_ENCRYPT_TYPE_NONE;
          break;
    }

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
<<<<<<< HEAD
<<<<<<< HEAD
          ("%s:cipher_alg:%d key_len[%d] *pEncryptionType :%d \n"),__FUNCTION__,(int)ext->alg,(int)ext->key_len,setKey.encType);

#ifdef WLAN_FEATURE_VOWIFI_11R
/* The supplicant may attempt to set the PTK once pre-authentication is done.
   Save the key in the UMAC and include it in the ADD BSS request */
    halStatus = sme_FTUpdateKey( WLAN_HDD_GET_HAL_CTX(pAdapter), &setKey);
    if( halStatus == eHAL_STATUS_SUCCESS )
    {
       return halStatus;
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
          ("%s:cipher_alg:%d key_len[%d] *pEncryptionType :%d \n"),__func__,(int)ext->alg,(int)ext->key_len,setKey.encType);

#ifdef WLAN_FEATURE_VOWIFI_11R
    /* The supplicant may attempt to set the PTK once pre-authentication
       is done. Save the key in the UMAC and include it in the ADD
       BSS request */
    halStatus = sme_FTUpdateKey( WLAN_HDD_GET_HAL_CTX(pAdapter), &setKey);
    if ( halStatus == eHAL_STATUS_FT_PREAUTH_KEY_SUCCESS )
    {
        hddLog(VOS_TRACE_LEVEL_INFO_MED,
               "%s: Update PreAuth Key success", __func__);
        return 0;
    }
    else if ( halStatus == eHAL_STATUS_FT_PREAUTH_KEY_FAILED )
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
               "%s: Update PreAuth Key failed", __func__);
        return -EINVAL;
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
#endif /* WLAN_FEATURE_VOWIFI_11R */

    pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_SETTING_KEY;

    vos_status = wlan_hdd_check_ula_done(pAdapter);
    if ( vos_status != VOS_STATUS_SUCCESS )
    {
       VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "[%4d] wlan_hdd_check_ula_done returned ERROR status= %d",
                   __LINE__, vos_status );

       pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_NONE;
    }

    halStatus = sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter),pAdapter->sessionId, &setKey, &roamId );

    if ( halStatus != eHAL_STATUS_SUCCESS )
    {
       VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                   "[%4d] sme_RoamSetKey returned ERROR status= %d",
                   __LINE__, halStatus );

       pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_NONE;
    }

   return halStatus;
}

static int iw_set_retry(struct net_device *dev, struct iw_request_info *info,
           union iwreq_data *wrqu, char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);

   ENTER();

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
   {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                   "%s:LOGP in Progress. Ignore!!!", __func__);
      return -EBUSY;
   }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   if(wrqu->retry.value < WNI_CFG_LONG_RETRY_LIMIT_STAMIN ||
       wrqu->retry.value > WNI_CFG_LONG_RETRY_LIMIT_STAMAX) {

      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR, ("Invalid Retry-Limit=%ld!!\n"),wrqu->retry.value);

      return -EINVAL;
   }

   if(wrqu->retry.flags & IW_RETRY_LIMIT) {

       if((wrqu->retry.flags & IW_RETRY_LONG))
       {
          if ( ccmCfgSetInt(hHal, WNI_CFG_LONG_RETRY_LIMIT, wrqu->retry.value, ccmCfgSetCallback, eANI_BOOLEAN_TRUE) != eHAL_STATUS_SUCCESS )
          {
             return -EIO;
          }
       }
       else if((wrqu->retry.flags & IW_RETRY_SHORT))
       {
          if ( ccmCfgSetInt(hHal, WNI_CFG_SHORT_RETRY_LIMIT, wrqu->retry.value, ccmCfgSetCallback, eANI_BOOLEAN_TRUE) != eHAL_STATUS_SUCCESS )
          {
             return -EIO;
          }
       }
   }
   else
   {
       return -EOPNOTSUPP;
   }

   VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, ("Set Retry-Limit=%ld!!\n"),wrqu->retry.value);

   EXIT();

   return 0;

}

static int iw_get_retry(struct net_device *dev, struct iw_request_info *info,
           union iwreq_data *wrqu, char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
   v_U32_t retry = 0;

   ENTER();

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
   {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
              "%s:LOGP in Progress. Ignore!!!", __func__);
      return -EBUSY;
   }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   if((wrqu->retry.flags & IW_RETRY_LONG))
   {
      wrqu->retry.flags = IW_RETRY_LIMIT | IW_RETRY_LONG;

      if ( ccmCfgGetInt(hHal, WNI_CFG_LONG_RETRY_LIMIT, &retry) != eHAL_STATUS_SUCCESS )
      {
         return -EIO;
      }

      wrqu->retry.value = retry;
   }
   else if ((wrqu->retry.flags & IW_RETRY_SHORT))
   {
      wrqu->retry.flags = IW_RETRY_LIMIT | IW_RETRY_SHORT;

      if ( ccmCfgGetInt(hHal, WNI_CFG_SHORT_RETRY_LIMIT, &retry) != eHAL_STATUS_SUCCESS )
      {
         return -EIO;
      }

      wrqu->retry.value = retry;
   }
   else {
      return -EOPNOTSUPP;
   }

   VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, ("Retry-Limit=%ld!!\n"),retry);

   EXIT();

   return 0;
}

static int iw_set_mlme(struct net_device *dev,
                       struct iw_request_info *info,
                       union iwreq_data *wrqu,
                       char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    struct iw_mlme *mlme = (struct iw_mlme *)extra;
    eHalStatus status = eHAL_STATUS_SUCCESS;

    ENTER();

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!",__func__);
        return 0;
    }

    //reason_code is unused. By default it is set to eCSR_DISCONNECT_REASON_UNSPECIFIED
    switch (mlme->cmd) {
        case IW_MLME_DISASSOC:
        case IW_MLME_DEAUTH:

            if( pHddStaCtx->conn_info.connState == eConnectionState_Associated )
            {
                eCsrRoamDisconnectReason reason = eCSR_DISCONNECT_REASON_UNSPECIFIED;

                if( mlme->reason_code == HDD_REASON_MICHAEL_MIC_FAILURE )
                    reason = eCSR_DISCONNECT_REASON_MIC_ERROR;

                INIT_COMPLETION(pAdapter->disconnect_comp_var);
                status = sme_RoamDisconnect( WLAN_HDD_GET_HAL_CTX(pAdapter), pAdapter->sessionId,reason);

                if(eHAL_STATUS_SUCCESS == status)
                    wait_for_completion_interruptible_timeout(&pAdapter->disconnect_comp_var,
                        msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));
                else
                    hddLog(LOGE,"%s %d Command Disassociate/Deauthenticate : csrRoamDisconnect failure returned %d \n",
<<<<<<< HEAD
<<<<<<< HEAD
                       __FUNCTION__, (int)mlme->cmd, (int)status );
=======
                       __func__, (int)mlme->cmd, (int)status );
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                       __func__, (int)mlme->cmd, (int)status );
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

                /* Resetting authKeyMgmt */
                (WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter))->authKeyMgmt = 0;

                netif_tx_disable(dev);
                netif_carrier_off(dev);

            }
            else
            {
<<<<<<< HEAD
<<<<<<< HEAD
                hddLog(LOGE,"%s %d Command Disassociate/Deauthenticate called but station is not in associated state \n", __FUNCTION__, (int)mlme->cmd );
            }
            break;
        default:
            hddLog(LOGE,"%s %d Command should be Disassociate/Deauthenticate \n", __FUNCTION__, (int)mlme->cmd );
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                hddLog(LOGE,"%s %d Command Disassociate/Deauthenticate called but station is not in associated state \n", __func__, (int)mlme->cmd );
            }
            break;
        default:
            hddLog(LOGE,"%s %d Command should be Disassociate/Deauthenticate \n", __func__, (int)mlme->cmd );
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            return -EINVAL;
    }//end of switch

    EXIT();

    return status;

}

/* set param sub-ioctls */
static int iw_setint_getnone(struct net_device *dev, struct iw_request_info *info,
                       union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    hdd_wext_state_t  *pWextState =  WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
<<<<<<< HEAD
<<<<<<< HEAD
    int *value = (int *)extra;
    int sub_cmd = value[0];
    int set_value = value[1];
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    int cmd_len = wrqu->data.length;
    int *value = (int *) kmalloc(cmd_len+1, GFP_KERNEL);  // Motorola, IKHSS7-39028
    int sub_cmd;
    int set_value;
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    int ret = 0; /* success */
    int enable_pbm, enable_mp;
#ifdef CONFIG_HAS_EARLYSUSPEND
    v_U8_t nEnableSuspendOld;
#endif
    INIT_COMPLETION(pWextState->completion_var);

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EBUSY;
    }

	    if(value == NULL)
        return -ENOMEM;

    if(copy_from_user((char *) value, (char*)(wrqu->data.pointer), cmd_len)) {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s -- copy_from_user --data pointer failed! bailing",
                __FUNCTION__);
        kfree(value);
        return -EFAULT;
    }

    sub_cmd = value[0];
    set_value = value[1];
    kfree(value);

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    switch(sub_cmd)
    {
        case WE_SET_11D_STATE:
        {
<<<<<<< HEAD
<<<<<<< HEAD
            tSmeConfigParams smeConfig;;
=======
            tSmeConfigParams smeConfig;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            tSmeConfigParams smeConfig;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            if((ENABLE_11D == set_value) || (DISABLE_11D == set_value)) {

                sme_GetConfigParam(hHal,&smeConfig);
                smeConfig.csrConfig.Is11dSupportEnabled = (v_BOOL_t)set_value;

                VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, ("11D state=%ld!!\n"),smeConfig.csrConfig.Is11dSupportEnabled);

                sme_UpdateConfig(hHal,&smeConfig);
            }
            else {
               return -EINVAL;
            }
            break;
        }

        case WE_WOWL:
        {
           switch (set_value)
           {
              case 0x00:
<<<<<<< HEAD
<<<<<<< HEAD
                 hdd_exit_wowl();
=======
                 hdd_exit_wowl(pAdapter);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                 hdd_exit_wowl(pAdapter);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                 break;
              case 0x01:
              case 0x02:
              case 0x03:
                 enable_mp =  (set_value & 0x01) ? 1 : 0;
                 enable_pbm = (set_value & 0x02) ? 1 : 0;
                 hddLog(LOGE, "magic packet ? = %s pattern byte matching ? = %s\n",
                     (enable_mp ? "YES":"NO"), (enable_pbm ? "YES":"NO"));
                 hdd_enter_wowl(pAdapter, enable_mp, enable_pbm);
                 break;
              default:
                 hddLog(LOGE, "Invalid arg  %d in WE_WOWL IOCTL\n", set_value);
                 ret = -EINVAL;
                 break;
           }

           break;
        }
        case WE_SET_POWER:
        {
           switch (set_value)
           {
              case  0: //Full Power
              {
                 struct statsContext context;
                 eHalStatus status;

                 init_completion(&context.completion);

                 context.pAdapter = pAdapter;
                 context.magic = POWER_CONTEXT_MAGIC;

                 status = sme_RequestFullPower(WLAN_HDD_GET_HAL_CTX(pAdapter),
                              iw_power_callback_fn, &context,
                              eSME_FULL_PWR_NEEDED_BY_HDD);
                 if(eHAL_STATUS_PMC_PENDING == status)
                 {
                    int lrc = wait_for_completion_interruptible_timeout(
                                  &context.completion,
                                  msecs_to_jiffies(WLAN_WAIT_TIME_POWER));
                    context.magic = 0;
                    if (lrc <= 0)
                    {
                       hddLog(VOS_TRACE_LEVEL_ERROR,"%s: SME %s while "
                                 "requesting fullpower ",
<<<<<<< HEAD
<<<<<<< HEAD
                                 __FUNCTION__, (0 == lrc) ?
=======
                                 __func__, (0 == lrc) ?
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                                 __func__, (0 == lrc) ?
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                                 "timeout" : "interrupt");
                       /* there is a race condition such that the callback
                          function could be executing at the same time we are. of
                          primary concern is if the callback function had already
                          verified the "magic" but hasn't yet set the completion
                          variable. Since the completion variable is on our
                          stack, we'll delay just a bit to make sure the data is
                          still valid if that is the case */
                       msleep(50);
                       /* we'll now returned a cached value below */
                    }
                 }
                 hddLog(LOGE, "iwpriv Full Power completed\n");
                 break;
              }
              case  1: //Enable BMPS
                 sme_EnablePowerSave(hHal, ePMC_BEACON_MODE_POWER_SAVE);
                 break;
              case  2: //Disable BMPS
                 sme_DisablePowerSave(hHal, ePMC_BEACON_MODE_POWER_SAVE);
                 break;
              case  3: //Request Bmps
              {
                 struct statsContext context;
                 eHalStatus status;

                 init_completion(&context.completion);

                 context.pAdapter = pAdapter;
                 context.magic = POWER_CONTEXT_MAGIC;

                 status = sme_RequestBmps(WLAN_HDD_GET_HAL_CTX(pAdapter),
                           iw_power_callback_fn, &context);
                 if(eHAL_STATUS_PMC_PENDING == status)
                 {
                    int lrc = wait_for_completion_interruptible_timeout(
                                  &context.completion,
                                  msecs_to_jiffies(WLAN_WAIT_TIME_POWER));
                    context.magic = 0;
                    if (lrc <= 0)
                    {
                       hddLog(VOS_TRACE_LEVEL_ERROR,"%s: SME %s while "
                                "requesting BMPS",
<<<<<<< HEAD
<<<<<<< HEAD
                                 __FUNCTION__, (0 == lrc) ? "timeout" :
=======
                                 __func__, (0 == lrc) ? "timeout" :
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                                 __func__, (0 == lrc) ? "timeout" :
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                                 "interrupt");
                       /* there is a race condition such that the callback
                          function could be executing at the same time we are. of
                          primary concern is if the callback function had already
                          verified the "magic" but hasn't yet set the completion
                          variable. Since the completion variable is on our
                          stack, we'll delay just a bit to make sure the data is
                          still valid if that is the case */
                       msleep(50);
                       /* we'll now returned a cached value below */
                    }
                 }
                 hddLog(LOGE, "iwpriv Request BMPS completed\n");
                 break;
              }
              case  4: //Enable IMPS
                 sme_EnablePowerSave(hHal, ePMC_IDLE_MODE_POWER_SAVE);
                 break;
              case  5: //Disable IMPS
                 sme_DisablePowerSave(hHal, ePMC_IDLE_MODE_POWER_SAVE);
                 break;
              case  6: //Enable Standby
                 sme_EnablePowerSave(hHal, ePMC_STANDBY_MODE_POWER_SAVE);
                 break;
              case  7: //Disable Standby
                 sme_DisablePowerSave(hHal, ePMC_STANDBY_MODE_POWER_SAVE);
                 break;
              case  8: //Request Standby
#ifdef CONFIG_HAS_EARLYSUSPEND
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
                 (void)hdd_enter_standby(pAdapter->pHddCtx);
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#endif
                 break;
              case  9: //Start Auto Bmps Timer
                 sme_StartAutoBmpsTimer(hHal);
                 break;
              case  10://Stop Auto BMPS Timer
                 sme_StopAutoBmpsTimer(hHal);
                 break;
#ifdef CONFIG_HAS_EARLYSUSPEND
              case  11://suspend to standby
#ifdef CONFIG_HAS_EARLYSUSPEND
                 nEnableSuspendOld = (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->nEnableSuspend;
                 (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->nEnableSuspend = 1;
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
                 hdd_suspend_wlan(NULL);
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                 (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->nEnableSuspend = nEnableSuspendOld;
#endif
                 break;
              case  12://suspend to deep sleep
#ifdef CONFIG_HAS_EARLYSUSPEND
                 nEnableSuspendOld = (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->nEnableSuspend;
                 (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->nEnableSuspend = 2;
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
                 hdd_suspend_wlan(NULL);
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                 (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->nEnableSuspend = nEnableSuspendOld;
#endif
                 break;
              case  13://resume from suspend
#ifdef CONFIG_HAS_EARLYSUSPEND
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
                 hdd_resume_wlan(NULL);
#endif
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#endif
                 break;
#endif
              case  14://reset wlan (power down/power up)
                 vos_chipReset(NULL, VOS_FALSE, NULL, NULL, VOS_CHIP_RESET_UNKNOWN_EXCEPTION);
                 break;
              default:
                 hddLog(LOGE, "Invalid arg  %d in WE_SET_POWER IOCTL\n", set_value);
                 ret = -EINVAL;
                 break;
           }
           break;
        }

        case WE_SET_MAX_ASSOC:
        {
            if ((WNI_CFG_ASSOC_STA_LIMIT_STAMIN > set_value) ||
                (WNI_CFG_ASSOC_STA_LIMIT_STAMAX < set_value))
            {
                ret = -EINVAL;
            }
            else if ( ccmCfgSetInt(hHal, WNI_CFG_ASSOC_STA_LIMIT,
                                   set_value, NULL, eANI_BOOLEAN_FALSE)
                      != eHAL_STATUS_SUCCESS )
            {
                ret = -EIO;
            }
            break;
        }

        case WE_SET_SAP_AUTO_CHANNEL_SELECTION:
        {
            if( 0 == set_value )
            {
                (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->apAutoChannelSelection = 0;
            }
            else if ( 1 == set_value )
            {
                (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->apAutoChannelSelection = 1;
            }
            else
            {
                 hddLog(LOGE, "Invalid arg  %d in WE_SET_SAP_AUTO_CHANNEL_SELECTION IOCTL\n", set_value);
                 ret = -EINVAL;
            }
            break;
         }

        case  WE_SET_DATA_INACTIVITY_TO:
        {
           if  ((set_value < CFG_DATA_INACTIVITY_TIMEOUT_MIN) ||
                (set_value > CFG_DATA_INACTIVITY_TIMEOUT_MAX) ||
                (ccmCfgSetInt((WLAN_HDD_GET_CTX(pAdapter))->hHal,
                    WNI_CFG_PS_DATA_INACTIVITY_TIMEOUT,
                    set_value,
                    NULL, eANI_BOOLEAN_FALSE)==eHAL_STATUS_FAILURE))
           {
               hddLog(LOGE,"Failure: Could not pass on "
                "WNI_CFG_PS_DATA_INACTIVITY_TIMEOUT configuration info "
                "to CCM\n");
               ret = -EINVAL;
           }
           break;
        }
        case WE_SET_MAX_TX_POWER:
        {
           tSirMacAddr bssid = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
           tSirMacAddr selfMac = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

           hddLog(VOS_TRACE_LEVEL_INFO, "%s: Setting maximum tx power %d dBm",
                  __func__, set_value);
           if( sme_SetMaxTxPower(hHal, bssid, selfMac, set_value) !=
               eHAL_STATUS_SUCCESS )
           {
              hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Setting maximum tx power failed",
              __func__);
              return -EIO;
           }

           break;
        }
        case WE_SET_HIGHER_DTIM_TRANSITION:
        {
            if(!((set_value == eANI_BOOLEAN_FALSE) ||
                          (set_value == eANI_BOOLEAN_TRUE)))
            {
                hddLog(LOGE, "Dynamic DTIM Incorrect data:%d", set_value);
                ret = -EINVAL;
            }
            else
            {
                if(pAdapter->higherDtimTransition != set_value)
                {
                    pAdapter->higherDtimTransition = set_value;
<<<<<<< HEAD
<<<<<<< HEAD
                    hddLog(LOG1, "%s: higherDtimTransition set to :%d", __FUNCTION__, pAdapter->higherDtimTransition);
=======
                    hddLog(LOG1, "%s: higherDtimTransition set to :%d", __func__, pAdapter->higherDtimTransition);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                    hddLog(LOG1, "%s: higherDtimTransition set to :%d", __func__, pAdapter->higherDtimTransition);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                }
            }

           break;
        }

        case WE_SET_TM_LEVEL:
        {
           hdd_context_t *hddCtxt = WLAN_HDD_GET_CTX(pAdapter);
           hddLog(VOS_TRACE_LEVEL_INFO, "Set Thermal Mitigation Level %d", (int)set_value); 
           hddDevTmLevelChangedHandler(hddCtxt->parent_dev, set_value);

           break;
        }
<<<<<<< HEAD
<<<<<<< HEAD

=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
		// Motorola, IKJBREL1-4181
        case WE_SET_CHANNEL_RANGE:
        {
            int startChannel, endChannel;
            if (set_value == 3) {
                startChannel = 153;
                endChannel   = 165;
            } else if (set_value == 2) {
                startChannel = 104;
                endChannel   = 140;
            } else if (set_value == 1) {
                startChannel = 40;
                endChannel   = 64;
            } else {
                set_value = 0;
                startChannel = 1;
                //BEGIN MOT a19110 IKJBXLINE-2149 MHS frequency band support
                endChannel   = 14;
                //END IKJBXLINE-2149
            }

            ret = iw_softap_set_channel_range( dev, startChannel, endChannel, set_value);

            break;
        }
        // End IKJBREL1-4181
        // IKJB42MAIN-1244, Motorola, a19091  -- BEGIN
        case WE_SET_IPV6_FILTER_STATE:
        {
             hddLog(LOGE, "Revieeved ioctl WE_SET_IPV6_FILTER_STATE");
            ret = wlan_hdd_set_v6_filter(pAdapter, set_value, TRUE);
            break;
        }
        // IKJB42MAIN-1244, Motorola, a19091  -- END
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        default:
        {
            hddLog(LOGE, "Invalid IOCTL setvalue command %d value %d \n",
                sub_cmd, set_value);
            break;
        }
    }

    return ret;
}

/* set param sub-ioctls */
static int iw_setchar_getnone(struct net_device *dev, struct iw_request_info *info,
                       union iwreq_data *wrqu, char *extra)
{
    VOS_STATUS vstatus;
    int sub_cmd = wrqu->data.flags;
    int ret = 0; /* success */
    hdd_adapter_t *pAdapter = (netdev_priv(dev));
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
#ifdef WLAN_FEATURE_VOWIFI
    hdd_config_t  *pConfig = pHddCtx->cfg_ini;
#endif /* WLAN_FEATURE_VOWIFI */

<<<<<<< HEAD
<<<<<<< HEAD
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "%s: Received length %d", __FUNCTION__, wrqu->data.length);
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "%s: Received data %s", __FUNCTION__, (char*)wrqu->data.pointer);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "%s: Received length %d", __func__, wrqu->data.length);
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "%s: Received data %s", __func__, (char*)wrqu->data.pointer);

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EBUSY;
    }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    switch(sub_cmd)
    {
       case WE_WOWL_ADD_PTRN:
          VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "ADD_PTRN\n");
<<<<<<< HEAD
<<<<<<< HEAD
          hdd_add_wowl_ptrn((char*)wrqu->data.pointer);
          break;
       case WE_WOWL_DEL_PTRN:
          VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "DEL_PTRN\n");
          hdd_del_wowl_ptrn((char*)wrqu->data.pointer);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
          hdd_add_wowl_ptrn(pAdapter, (char*)wrqu->data.pointer);
          break;
       case WE_WOWL_DEL_PTRN:
          VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "DEL_PTRN\n");
          hdd_del_wowl_ptrn(pAdapter, (char*)wrqu->data.pointer);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
          break;
#if defined WLAN_FEATURE_VOWIFI
       case WE_NEIGHBOR_REPORT_REQUEST:
          {
             tRrmNeighborReq neighborReq;
             tRrmNeighborRspCallbackInfo callbackInfo;

             if (pConfig->fRrmEnable)
             {
                VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "Neighbor Request\n");
                neighborReq.no_ssid = (wrqu->data.length - 1) ? false : true ;
                if( !neighborReq.no_ssid )
                {
                   neighborReq.ssid.length = (wrqu->data.length - 1) > 32 ? 32 : (wrqu->data.length - 1) ;
                   vos_mem_copy( neighborReq.ssid.ssId, wrqu->data.pointer, neighborReq.ssid.length );
                }

                callbackInfo.neighborRspCallback = NULL;
                callbackInfo.neighborRspCallbackContext = NULL;
                callbackInfo.timeout = 5000;   //5 seconds
                sme_NeighborReportRequest(  WLAN_HDD_GET_HAL_CTX(pAdapter), pAdapter->sessionId, &neighborReq, &callbackInfo );
             }
             else
             {
                hddLog(LOGE, "%s: Ignoring neighbor request as RRM is not enabled\n", __func__);
                ret = -EINVAL;
             }
          }
          break;
#endif
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
       case WE_SET_AP_WPS_IE:
          hddLog( LOGE, "Received WE_SET_AP_WPS_IE" );
#ifdef WLAN_FEATURE_P2P
          sme_updateP2pIe( WLAN_HDD_GET_HAL_CTX(pAdapter), wrqu->data.pointer, wrqu->data.length );
#endif // WLAN_FEATURE_P2P
          break;
#endif
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       case WE_SET_AP_WPS_IE:
          hddLog( LOGE, "Received WE_SET_AP_WPS_IE" );
          sme_updateP2pIe( WLAN_HDD_GET_HAL_CTX(pAdapter), wrqu->data.pointer, wrqu->data.length );
          break;
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       case WE_SET_CONFIG:
          vstatus = hdd_execute_config_command(pHddCtx, wrqu->data.pointer);
          if (VOS_STATUS_SUCCESS != vstatus)
          {
             ret = -EINVAL;
          }
          break;
       default:
       {
<<<<<<< HEAD
<<<<<<< HEAD
           hddLog(LOGE, "%s: Invalid sub command %d\n",__FUNCTION__, sub_cmd);
=======
           hddLog(LOGE, "%s: Invalid sub command %d\n",__func__, sub_cmd);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
           hddLog(LOGE, "%s: Invalid sub command %d\n",__func__, sub_cmd);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           ret = -EINVAL;
           break;
       }
    }
    return ret;
}

/* get param sub-ioctls */
static int iw_setnone_getint(struct net_device *dev, struct iw_request_info *info,
                       union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    int *value = (int *)extra;
    int ret = 0; /* success */

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EBUSY;
    }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    switch (value[0])
    {
        case WE_GET_11D_STATE:
        {
<<<<<<< HEAD
<<<<<<< HEAD
           tSmeConfigParams smeConfig;;
=======
           tSmeConfigParams smeConfig;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
           tSmeConfigParams smeConfig;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           
           sme_GetConfigParam(hHal,&smeConfig);
           
           *value = smeConfig.csrConfig.Is11dSupportEnabled;

            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, ("11D state=%ld!!\n"),*value);

           break;
        }

        case WE_IBSS_STATUS:
           VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "****Return IBSS Status*****\n");
           break;

        case WE_PMC_STATE:
        {
             *value = pmcGetPmcState(hHal);
             VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, ("PMC state=%ld!!\n"),*value);
             break;
        }
        case WE_GET_WLAN_DBG:
        {
           vos_trace_display();
           *value = 0;
           break;
        }
        case WE_MODULE_DOWN_IND:
        {
<<<<<<< HEAD
<<<<<<< HEAD
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: sending WLAN_MODULE_DOWN_IND", __FUNCTION__);
            send_btc_nlink_msg(WLAN_MODULE_DOWN_IND, 0);
#ifdef WLAN_BTAMP_FEATURE
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: Take down AMP PAL", __FUNCTION__);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: sending WLAN_MODULE_DOWN_IND", __func__);
            send_btc_nlink_msg(WLAN_MODULE_DOWN_IND, 0);
#ifdef WLAN_BTAMP_FEATURE
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: Take down AMP PAL", __func__);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            BSL_Deinit(vos_get_global_context(VOS_MODULE_ID_HDD, NULL));
#endif
            //WLANBAP_Close(vos_get_global_context(VOS_MODULE_ID_HDD, NULL));

            *value = 0;
            break;
        }
        case WE_GET_MAX_ASSOC:
        {
            if (ccmCfgGetInt(hHal, WNI_CFG_ASSOC_STA_LIMIT, (tANI_U32 *)value) != eHAL_STATUS_SUCCESS)
            {
                ret = -EIO;
            }
            break;
        }

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_INTEGRATED_SOC
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        case WE_GET_WDI_DBG:
        {
           wpalTraceDisplay();
           *value = 0;
           break;
        }
<<<<<<< HEAD
<<<<<<< HEAD
#endif // FEATURE_WLAN_INTEGRATED_SOC
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        case WE_GET_SAP_AUTO_CHANNEL_SELECTION:
        {
            *value = (WLAN_HDD_GET_CTX(pAdapter))->cfg_ini->apAutoChannelSelection;
            break;
        }
        case WE_GET_CONCURRENCY_MODE:
        {
           *value = hdd_get_concurrency_mode ( );

           VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, ("concurrency mode=%d \n"),*value);
           break;
        }
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        // BEGIN MOTOROLA IKJB42MAIN-274, dpn473, 01/02/2013, Add flag to disable/enable MCC mode
        case WE_GET_MCC_MODE:
        {
           *value = (int)hdd_get_mcc_mode();
           break;
        }
        // IKJB42MAIN-274
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        default:
        {
            hddLog(LOGE, "Invalid IOCTL get_value command %d ",value[0]);
            break;
        }
    }

    return ret;
}

/* set param sub-ioctls */
int iw_set_three_ints_getnone(struct net_device *dev, struct iw_request_info *info,
                       union iwreq_data *wrqu, char *extra)
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    int *value = (int *)extra;
    int sub_cmd = value[0];
    int ret = 0;

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EBUSY;
    }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    switch(sub_cmd)
    {
        case WE_SET_WLAN_DBG:
        {
<<<<<<< HEAD
<<<<<<< HEAD
            vos_trace_setValue( value[1], value[2], value[3]);
            break;
        }
#ifdef FEATURE_WLAN_INTEGRATED_SOC
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

            vos_trace_setValue( value[1], value[2], value[3]);
            break;
        }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        case WE_SET_WDI_DBG:
        {
            wpalTraceSetLevel( value[1], value[2], value[3]);
            break;
        }
<<<<<<< HEAD
<<<<<<< HEAD
#endif // FEATURE_WLAN_INTEGRATED_SOC
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        case WE_SET_SAP_CHANNELS:
        {
            ret = iw_softap_set_channel_range( dev, value[1], value[2], value[3]);
            break;
        }
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        //Begin Motorola dcw476 4/17/13 IKJBXLINE-5577:changing wlan driver log level dynamically
        case WE_SET_WLAN_DBG_TILL_LEVEL:
        {
            vos_trace_setValue_till_level(value[1], value[2], value[3]);
        }
        break;
        //END IKJBXLINE-5577
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        default:
        {
            hddLog(LOGE, "Invalid IOCTL command %d  \n",  sub_cmd );
            break;
        }
    }
    return ret;
}

static int iw_get_char_setnone(struct net_device *dev, struct iw_request_info *info,
                       union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    int sub_cmd = wrqu->data.flags;
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
    VOS_STATUS status;
#endif // FEATURE_WLAN_NON_INTEGRATED_SOC
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EBUSY;
    }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    switch(sub_cmd)
    {
        case WE_WLAN_VERSION:
        {
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_NON_INTEGRATED_SOC
            status = hdd_wlan_get_version(pAdapter, wrqu, extra);
#else // FEATURE_WLAN_NON_INTEGRATED_SOC
            char *buf = extra;
            wrqu->data.length = snprintf(buf, WE_MAX_STR_LEN, "%s_",
                                         WLAN_CHIP_VERSION);
#endif
=======
            hdd_wlan_get_version(pAdapter, wrqu, extra);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            hdd_wlan_get_version(pAdapter, wrqu, extra);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;
        }

        case WE_GET_STATS:
        {
            hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
            hdd_tx_rx_stats_t *pStats = &pAdapter->hdd_stats.hddTxRxStats;
            hdd_chip_reset_stats_t *pResetStats = &pHddCtx->hddChipResetStats;

            snprintf(extra, WE_MAX_STR_LEN,
                     "\nTransmit"
                     "\ncalled %u, dropped %u, backpressured %u, queued %u"
                     "\n      dropped BK %u, BE %u, VI %u, VO %u"
                     "\n   classified BK %u, BE %u, VI %u, VO %u"
                     "\nbackpressured BK %u, BE %u, VI %u, VO %u"
                     "\n       queued BK %u, BE %u, VI %u, VO %u"
                     "\nfetched %u, empty %u, lowres %u, deqerr %u"
                     "\ndequeued %u, depressured %u, completed %u, flushed %u"
                     "\n      fetched BK %u, BE %u, VI %u, VO %u"
                     "\n     dequeued BK %u, BE %u, VI %u, VO %u"
                     "\n  depressured BK %u, BE %u, VI %u, VO %u"
                     "\n      flushed BK %u, BE %u, VI %u, VO %u"
                     "\n\nReceive"
                     "\nchains %u, packets %u, dropped %u, delivered %u, refused %u"
                     "\n\nResetsStats"
                     "\n TotalLogp %u Cmd53 %u MutexRead %u  MIF-Error %u FW-Heartbeat %u Others %u"
                     "\n",
                     pStats->txXmitCalled,
                     pStats->txXmitDropped,
                     pStats->txXmitBackPressured,
                     pStats->txXmitQueued,

                     pStats->txXmitDroppedAC[WLANTL_AC_BK],
                     pStats->txXmitDroppedAC[WLANTL_AC_BE],
                     pStats->txXmitDroppedAC[WLANTL_AC_VI],
                     pStats->txXmitDroppedAC[WLANTL_AC_VO],

                     pStats->txXmitClassifiedAC[WLANTL_AC_BK],
                     pStats->txXmitClassifiedAC[WLANTL_AC_BE],
                     pStats->txXmitClassifiedAC[WLANTL_AC_VI],
                     pStats->txXmitClassifiedAC[WLANTL_AC_VO],

                     pStats->txXmitBackPressuredAC[WLANTL_AC_BK],
                     pStats->txXmitBackPressuredAC[WLANTL_AC_BE],
                     pStats->txXmitBackPressuredAC[WLANTL_AC_VI],
                     pStats->txXmitBackPressuredAC[WLANTL_AC_VO],

                     pStats->txXmitQueuedAC[WLANTL_AC_BK],
                     pStats->txXmitQueuedAC[WLANTL_AC_BE],
                     pStats->txXmitQueuedAC[WLANTL_AC_VI],
                     pStats->txXmitQueuedAC[WLANTL_AC_VO],

                     pStats->txFetched,
                     pStats->txFetchEmpty,
                     pStats->txFetchLowResources,
                     pStats->txFetchDequeueError,

                     pStats->txFetchDequeued,
                     pStats->txFetchDePressured,
                     pStats->txCompleted,
                     pStats->txFlushed,

                     pStats->txFetchedAC[WLANTL_AC_BK],
                     pStats->txFetchedAC[WLANTL_AC_BE],
                     pStats->txFetchedAC[WLANTL_AC_VI],
                     pStats->txFetchedAC[WLANTL_AC_VO],

                     pStats->txFetchDequeuedAC[WLANTL_AC_BK],
                     pStats->txFetchDequeuedAC[WLANTL_AC_BE],
                     pStats->txFetchDequeuedAC[WLANTL_AC_VI],
                     pStats->txFetchDequeuedAC[WLANTL_AC_VO],

                     pStats->txFetchDePressuredAC[WLANTL_AC_BK],
                     pStats->txFetchDePressuredAC[WLANTL_AC_BE],
                     pStats->txFetchDePressuredAC[WLANTL_AC_VI],
                     pStats->txFetchDePressuredAC[WLANTL_AC_VO],

                     pStats->txFlushedAC[WLANTL_AC_BK],
                     pStats->txFlushedAC[WLANTL_AC_BE],
                     pStats->txFlushedAC[WLANTL_AC_VI],
                     pStats->txFlushedAC[WLANTL_AC_VO],

                     pStats->rxChains,
                     pStats->rxPackets,
                     pStats->rxDropped,
                     pStats->rxDelivered,
                     pStats->rxRefused,

                     pResetStats->totalLogpResets,
                     pResetStats->totalCMD53Failures,
                     pResetStats->totalMutexReadFailures,
                     pResetStats->totalMIFErrorFailures,
                     pResetStats->totalFWHearbeatFailures,
                     pResetStats->totalUnknownExceptions
                     );
            wrqu->data.length = strlen(extra)+1;
            break;
        }

        case WE_GET_CFG:
        {
            hdd_cfg_get_config(WLAN_HDD_GET_CTX(pAdapter), extra, WE_MAX_STR_LEN);
            wrqu->data.length = strlen(extra)+1;
            break;
        }
#ifdef WLAN_FEATURE_11AC
        case WE_GET_RSSI:
        {
            v_S7_t s7Rssi = 0;
            wlan_hdd_get_rssi(pAdapter, &s7Rssi);
            snprintf(extra, WE_MAX_STR_LEN, "rssi=%d",s7Rssi);
            wrqu->data.length = strlen(extra)+1;
            break;
        }
#endif
           
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#if defined WLAN_FEATURE_VOWIFI_11R || defined FEATURE_WLAN_CCX || defined(FEATURE_WLAN_LFR)
        case WE_GET_ROAM_RSSI:
        {
            v_S7_t s7Rssi = 0;
            wlan_hdd_get_roam_rssi(pAdapter, &s7Rssi);
            snprintf(extra, WE_MAX_STR_LEN, "rssi=%d", s7Rssi);
            wrqu->data.length = strlen(extra)+1;
            break;
        }
#endif
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        case WE_GET_WMM_STATUS:
        {
            snprintf(extra, WE_MAX_STR_LEN,
                    "\nDir: 0=up, 1=down, 3=both\n"
                    "|------------------------|\n"
                    "|AC | ACM |Admitted| Dir |\n"
                    "|------------------------|\n"
                    "|VO |  %d  |  %3s   |  %d  |\n"
                    "|VI |  %d  |  %3s   |  %d  |\n"
                    "|BE |  %d  |  %3s   |  %d  |\n"
                    "|BK |  %d  |  %3s   |  %d  |\n"
                    "|------------------------|\n",
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_VO].wmmAcAccessRequired,
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_VO].wmmAcAccessAllowed?"YES":"NO",
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_VO].wmmAcTspecInfo.ts_info.direction,
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_VI].wmmAcAccessRequired,
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_VI].wmmAcAccessAllowed?"YES":"NO",
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_VI].wmmAcTspecInfo.ts_info.direction,
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_BE].wmmAcAccessRequired,
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_BE].wmmAcAccessAllowed?"YES":"NO",
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_BE].wmmAcTspecInfo.ts_info.direction,
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_BK].wmmAcAccessRequired,
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_BK].wmmAcAccessAllowed?"YES":"NO",
                    pAdapter->hddWmmStatus.wmmAcStatus[WLANTL_AC_BK].wmmAcTspecInfo.ts_info.direction);


            wrqu->data.length = strlen(extra)+1;
            break;
        }
        case WE_GET_CHANNEL_LIST:
        {
            VOS_STATUS status;
            v_U8_t i, len;
            char* buf ;
<<<<<<< HEAD
<<<<<<< HEAD
            tChannelListInfo channel_list;

=======

            tChannelListInfo channel_list;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======

            tChannelListInfo channel_list;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            status = iw_softap_get_channel_list(dev, info, wrqu, (char *)&channel_list);
            if ( !VOS_IS_STATUS_SUCCESS( status ) ) 
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s GetChannelList Failed!!!\n",__func__);
                return -EINVAL;
            }
            buf = extra;

            /**
<<<<<<< HEAD
<<<<<<< HEAD
                       * Maximum channels = WNI_CFG_VALID_CHANNEL_LIST_LEN. Maximum buffer
                       * needed = 5 * number of channels. Check if sufficient buffer is available and 
                       * then proceed to fill the buffer.
                       */
            if(WE_MAX_STR_LEN < (5 * WNI_CFG_VALID_CHANNEL_LIST_LEN))
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s Insufficient Buffer to populate channel list\n",__func__);
                return -EINVAL;
            }
            len = snprintf(buf, 5, "%u ", channel_list.num_channels);
            buf += len;
            for(i = 0 ; i < channel_list.num_channels; i++)
            {
                len = snprintf(buf, 5,
                               "%u ", channel_list.channels[i]);
                buf += len;
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
             * Maximum channels = WNI_CFG_VALID_CHANNEL_LIST_LEN. Maximum buffer
             * needed = 5 * number of channels. Check ifsufficient
             * buffer is available and then proceed to fill the buffer.
             */
            if(WE_MAX_STR_LEN < (5 * WNI_CFG_VALID_CHANNEL_LIST_LEN))
            {
                hddLog(VOS_TRACE_LEVEL_ERROR,
                        "%s Insufficient Buffer to populate channel list\n",
                            __func__);
                return -EINVAL;
            }
            len = scnprintf(buf, WE_MAX_STR_LEN, "%u ",
                    channel_list.num_channels);
            for(i = 0 ; i < channel_list.num_channels; i++)
            {
                len += scnprintf(buf + len, WE_MAX_STR_LEN - len,
                               "%u ", channel_list.channels[i]);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            }
            wrqu->data.length = strlen(extra)+1;

            break;
        }
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#ifdef FEATURE_WLAN_TDLS
        case WE_GET_TDLS_PEERS:
        {
            wrqu->data.length = wlan_hdd_tdls_get_all_peers(pAdapter, extra, WE_MAX_STR_LEN)+1;
            break;
        }
#endif
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        default:  
        {
            hddLog(LOGE, "Invalid IOCTL command %d  \n",  sub_cmd );
            break;
        }
    }

    return 0;
}

/*  action sub-ioctls */
static int iw_setnone_getnone(struct net_device *dev, struct iw_request_info *info,
                       union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    int sub_cmd = wrqu->data.flags;
<<<<<<< HEAD
<<<<<<< HEAD
    int ret = 0; /* sucess */
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    int ret = 0; /* success */

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EBUSY;
    }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    switch (sub_cmd)
    {
        case WE_CLEAR_STATS:
        {
<<<<<<< HEAD
<<<<<<< HEAD
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: clearing", __FUNCTION__);
=======
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: clearing", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: clearing", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            memset(&pAdapter->stats, 0, sizeof(pAdapter->stats));
            memset(&pAdapter->hdd_stats, 0, sizeof(pAdapter->hdd_stats));
            break;
        }
<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_SOFTAP_FEATURE
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        case WE_INIT_AP:
        {
          pr_info("Init AP trigger\n");
          hdd_open_adapter( WLAN_HDD_GET_CTX(pAdapter), WLAN_HDD_SOFTAP, "softap.%d",
                 wlan_hdd_get_intf_addr( WLAN_HDD_GET_CTX(pAdapter) ),TRUE);
          break;
        }
        case WE_STOP_AP:
        {
           /*FIX ME: Need to be revisited if multiple SAPs to be supported */
           /* As Soft AP mode has been changed to STA already with killing of Hostapd,
            * this is a dead code and need to find the adpater by name rather than mode */
           hdd_adapter_t* pAdapter_to_stop =
                hdd_get_adapter_by_name(WLAN_HDD_GET_CTX(pAdapter), "softap.0");
           if( pAdapter_to_stop )
           {
               hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

               pr_info("Stopping AP mode\n");

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
               if (TRUE == sme_IsPmcBmps(WLAN_HDD_GET_HAL_CTX(pAdapter)))
               {
                  /* EXIT BMPS as fw cannot handle DEL_STA when its in BMPS */
                  wlan_hdd_enter_bmps(pAdapter, DRIVER_POWER_MODE_ACTIVE);
               }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
               /*Make sure that pAdapter cleaned properly*/
               hdd_stop_adapter( pHddCtx, pAdapter_to_stop );
               hdd_deinit_adapter( pHddCtx, pAdapter_to_stop );
               memset(&pAdapter_to_stop->sessionCtx, 0, sizeof(pAdapter_to_stop->sessionCtx));

               wlan_hdd_release_intf_addr(WLAN_HDD_GET_CTX(pAdapter),
                       pAdapter_to_stop->macAddressCurrent.bytes);
               hdd_close_adapter(WLAN_HDD_GET_CTX(pAdapter), pAdapter_to_stop,
                       TRUE);
<<<<<<< HEAD
<<<<<<< HEAD
           }
           else
           {
              printk(KERN_ERR"SAP adaptor not found to stop it!\n");
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

               if (FALSE == sme_IsPmcBmps(WLAN_HDD_GET_HAL_CTX(pAdapter)))
               {
                  /* put the device back into BMPS */
                  wlan_hdd_enter_bmps(pAdapter, DRIVER_POWER_MODE_AUTO);
               }
           }
           else
           {
              printk(KERN_ERR"SAP adapter not found to stop it!\n");
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           }

           break;
        }
<<<<<<< HEAD
<<<<<<< HEAD
#endif
#ifdef WLAN_BTAMP_FEATURE
        case WE_ENABLE_AMP:
        {
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: enabling AMP", __FUNCTION__);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#ifdef WLAN_BTAMP_FEATURE
        case WE_ENABLE_AMP:
        {
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: enabling AMP", __func__);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            WLANBAP_RegisterWithHCI(pAdapter);
            break;
        }
        case WE_DISABLE_AMP:
        {
            hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX( pAdapter );
            VOS_STATUS status;

<<<<<<< HEAD
<<<<<<< HEAD
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: disabling AMP", __FUNCTION__);
=======
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: disabling AMP", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,"%s: disabling AMP", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

            pHddCtx = WLAN_HDD_GET_CTX( pAdapter );
            status = WLANBAP_StopAmp();
            if(VOS_STATUS_SUCCESS != status )
            {
               pHddCtx->isAmpAllowed = VOS_TRUE;
               hddLog(VOS_TRACE_LEVEL_FATAL,
                      "%s: Failed to stop AMP", __func__);
            }
            else
            {
               //a state m/c implementation in PAL is TBD to avoid this delay
               msleep(500);
               pHddCtx->isAmpAllowed = VOS_FALSE;
               WLANBAP_DeregisterFromHCI();
            }

            break;
        }
#endif

        case WE_ENABLE_DXE_STALL_DETECT:
        {
<<<<<<< HEAD
<<<<<<< HEAD
            sme_transportDebug(VOS_FALSE, VOS_TRUE);
=======
            tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
            sme_transportDebug(hHal, VOS_FALSE, VOS_TRUE);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
            sme_transportDebug(hHal, VOS_FALSE, VOS_TRUE);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;
        }
        case WE_DISPLAY_DXE_SNAP_SHOT:
        {
<<<<<<< HEAD
<<<<<<< HEAD
            sme_transportDebug(VOS_TRUE, VOS_FALSE);
            break;
        }

        default:
        {
            hddLog(LOGE, "%s: unknown ioctl %d", __FUNCTION__, sub_cmd);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
            sme_transportDebug(hHal, VOS_TRUE, VOS_FALSE);
            break;
        }
        case WE_DISPLAY_DATAPATH_SNAP_SHOT:
        {
            hddLog(LOGE, "%s: called %d",__func__, sub_cmd);
            hdd_wmm_tx_snapshot(pAdapter);
            WLANTL_TLDebugMessage(VOS_TRUE);
            break;
        }
        case  WE_SET_REASSOC_TRIGGER:
        {
            hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
            tpAniSirGlobal pMac = WLAN_HDD_GET_HAL_CTX(pAdapter);
            v_U32_t roamId = 0;
            tCsrRoamModifyProfileFields modProfileFields;
            sme_GetModifyProfileFields(pMac, pAdapter->sessionId, &modProfileFields);
            sme_RoamReassoc(pMac, pAdapter->sessionId, NULL, modProfileFields, &roamId, 1);
            return 0;
        }
        

        default:
        {
            hddLog(LOGE, "%s: unknown ioctl %d", __func__, sub_cmd);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;
        }
    }

    return ret;
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
void hdd_wmm_tx_snapshot(hdd_adapter_t *pAdapter)
{
    /*
     * Function to display HDD WMM information
     * for Tx Queues.
     * Prints globala as well as per client depending
     * whether the clients are registered or not.
     */
    int i = 0, j = 0;
    for ( i=0; i< NUM_TX_QUEUES; i++)
    {
        spin_lock_bh(&pAdapter->wmm_tx_queue[i].lock);
        hddLog(LOGE, "HDD WMM TxQueue Info For AC: %d Count: %d PrevAdress:0x%x, NextAddress:0x%x",
               i, pAdapter->wmm_tx_queue[i].count,
               pAdapter->wmm_tx_queue[i].anchor.prev, pAdapter->wmm_tx_queue[i].anchor.next);
        spin_unlock_bh(&pAdapter->wmm_tx_queue[i].lock);
    }

    for(i =0; i<WLAN_MAX_STA_COUNT; i++)
    {
        if(pAdapter->aStaInfo[i].isUsed)
        {
             hddLog(LOGE, "******STAIndex: %d*********", i);
             for ( j=0; j< NUM_TX_QUEUES; j++)
             {
                spin_lock_bh(&pAdapter->aStaInfo[i].wmm_tx_queue[j].lock);
                hddLog(LOGE, "HDD TxQueue Info For AC: %d Count: %d PrevAdress:0x%x, NextAddress:0x%x",
                       j, pAdapter->aStaInfo[i].wmm_tx_queue[j].count,
                       pAdapter->aStaInfo[i].wmm_tx_queue[j].anchor.prev,
                       pAdapter->aStaInfo[i].wmm_tx_queue[j].anchor.next);
                spin_unlock_bh(&pAdapter->aStaInfo[i].wmm_tx_queue[j].lock);
             }
        }
    }

}
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
int iw_set_var_ints_getnone(struct net_device *dev, struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    int sub_cmd = wrqu->data.flags;
    int *value = (int*)wrqu->data.pointer;
    int apps_args[MAX_VAR_ARGS] = {0};
    int num_args = wrqu->data.length;
<<<<<<< HEAD
<<<<<<< HEAD

    hddLog(LOG1, "%s: Received length %d", __FUNCTION__, wrqu->data.length);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    hdd_station_ctx_t *pStaCtx = NULL ;
    hdd_ap_ctx_t  *pAPCtx = NULL;
    int cmd = 0;
    int staId = 0;

    hddLog(LOG1, "%s: Received length %d", __func__, wrqu->data.length);

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EBUSY;
    }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if (num_args > MAX_VAR_ARGS)
    {
       num_args = MAX_VAR_ARGS;
    }
    vos_mem_copy(apps_args, value, (sizeof(int)) * num_args);

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if(( sub_cmd == WE_MCC_CONFIG_CREDENTIAL ) ||
        (sub_cmd == WE_MCC_CONFIG_PARAMS ))
    {
        if(( pAdapter->device_mode == WLAN_HDD_INFRA_STATION )||
           ( pAdapter->device_mode == WLAN_HDD_P2P_CLIENT ))
        {
            pStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
            staId = pStaCtx->conn_info.staId[0];
        }
        else if (( pAdapter->device_mode == WLAN_HDD_P2P_GO ) ||
                 ( pAdapter->device_mode == WLAN_HDD_SOFTAP ))
        {
            pAPCtx = WLAN_HDD_GET_AP_CTX_PTR(pAdapter);
            staId = pAPCtx->uBCStaId;
        }
        else
        {
            hddLog(LOGE, "%s: Device mode %d not recognised", __FUNCTION__, pAdapter->device_mode);
            return 0;
        }
    }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    switch (sub_cmd)
    {
        case WE_LOG_DUMP_CMD:
            {
                hddLog(LOG1, "%s: LOG_DUMP %d arg1 %d arg2 %d arg3 %d arg4 %d",
<<<<<<< HEAD
<<<<<<< HEAD
                        __FUNCTION__, apps_args[0], apps_args[1], apps_args[2],
=======
                        __func__, apps_args[0], apps_args[1], apps_args[2],
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                        __func__, apps_args[0], apps_args[1], apps_args[2],
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                        apps_args[3], apps_args[4]);

                logPrintf(hHal, apps_args[0], apps_args[1], apps_args[2],
                        apps_args[3], apps_args[4]);

            }
            break;

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef WLAN_FEATURE_P2P
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        case WE_P2P_NOA_CMD:
            {
                p2p_app_setP2pPs_t p2pNoA;

                p2pNoA.opp_ps = apps_args[0];
                p2pNoA.ctWindow = apps_args[1];
                p2pNoA.duration = apps_args[2];
                p2pNoA.interval  = apps_args[3];
                p2pNoA.count = apps_args[4];
                p2pNoA.single_noa_duration = apps_args[5];
                p2pNoA.psSelection = apps_args[6];

                hddLog(LOG1, "%s: P2P_NOA_ATTR:oppPS %d ctWindow %d duration %d "
                       "interval %d count %d single noa duration %d PsSelection %x",
<<<<<<< HEAD
<<<<<<< HEAD
                       __FUNCTION__, apps_args[0], apps_args[1], apps_args[2],
=======
                       __func__, apps_args[0], apps_args[1], apps_args[2],
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                       __func__, apps_args[0], apps_args[1], apps_args[2],
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                       apps_args[3], apps_args[4], apps_args[5], apps_args[6]);

                hdd_setP2pPs(dev, &p2pNoA);

            }
            break;
<<<<<<< HEAD
<<<<<<< HEAD
#endif

=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        case WE_MCC_CONFIG_CREDENTIAL :
            {
                cmd = 287; //Command should be updated if there is any change
                           // in the Riva dump command
                if((apps_args[0] >= 40 ) && (apps_args[0] <= 160 ))
                {
                    logPrintf(hHal, cmd, staId, apps_args[0], apps_args[1], apps_args[2]);
                }
                else
                {
                     hddLog(LOGE, "%s : Enter valid MccCredential value between MIN :40 and MAX:160\n", __func__);
                     return 0;
                }
            }
            break;

        case WE_MCC_CONFIG_PARAMS :
            {
                cmd = 288; //command Should be updated if there is any change
                           // in the Riva dump command
                 hdd_validate_mcc_config(pAdapter, staId, apps_args[0], apps_args[1],apps_args[2]);
            }
        break;

#ifdef FEATURE_WLAN_TDLS
        case WE_TDLS_CONFIG_PARAMS :
            {
                tdls_config_params_t tdlsParams;

                tdlsParams.tdls                    = apps_args[0];
                tdlsParams.tx_period_t             = apps_args[1];
                tdlsParams.tx_packet_n             = apps_args[2];
                tdlsParams.discovery_period_t      = apps_args[3];
                tdlsParams.discovery_tries_n       = apps_args[4];
                tdlsParams.idle_timeout_t          = apps_args[5];
                tdlsParams.idle_packet_n           = apps_args[6];
                tdlsParams.rssi_hysteresis         = apps_args[7];
                tdlsParams.rssi_trigger_threshold  = apps_args[8];
                tdlsParams.rssi_teardown_threshold = apps_args[9];

                wlan_hdd_tdls_set_params(dev, &tdlsParams);
            }
        break;
#endif
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        default:
            {
                hddLog(LOGE, "Invalid IOCTL command %d",  sub_cmd );
            }
            break;
    }

    return 0;
}


static int iw_add_tspec(struct net_device *dev, struct iw_request_info *info,
                        union iwreq_data *wrqu, char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
   hdd_wlan_wmm_status_e *pStatus = (hdd_wlan_wmm_status_e *)extra;
   int params[HDD_WLAN_WMM_PARAM_COUNT];
   sme_QosWmmTspecInfo tSpec;
   v_U32_t handle;

   // make sure the application is sufficiently priviledged
   // note that the kernel will do this for "set" ioctls, but since
   // this ioctl wants to return status to user space it must be
   // defined as a "get" ioctl
   if (!capable(CAP_NET_ADMIN))
   {
      return -EPERM;
   }

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
   {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
      return -EBUSY;
   }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   // we must be associated in order to add a tspec
   if (eConnectionState_Associated != pHddStaCtx->conn_info.connState)
   {
      *pStatus = HDD_WLAN_WMM_STATUS_SETUP_FAILED_BAD_PARAM;
      return 0;
   }

   // since we are defined to be a "get" ioctl, and since the number
   // of params exceeds the number of params that wireless extensions
   // will pass down in the iwreq_data, we must copy the "set" params
   // from user space ourselves
   if (copy_from_user(&params, wrqu->data.pointer, sizeof(params)))
   {
      // hmmm, can't get them
      return -EIO;
   }

   // clear the tspec
   memset(&tSpec, 0, sizeof(tSpec));

   // validate the handle
   handle = params[HDD_WLAN_WMM_PARAM_HANDLE];
   if (HDD_WMM_HANDLE_IMPLICIT == handle)
   {
      // that one is reserved
      *pStatus = HDD_WLAN_WMM_STATUS_SETUP_FAILED_BAD_PARAM;
      return 0;
   }

   // validate the TID
   if (params[HDD_WLAN_WMM_PARAM_TID] > 7)
   {
      // out of range
      *pStatus = HDD_WLAN_WMM_STATUS_SETUP_FAILED_BAD_PARAM;
      return 0;
   }
   tSpec.ts_info.tid = params[HDD_WLAN_WMM_PARAM_TID];

   // validate the direction
   switch (params[HDD_WLAN_WMM_PARAM_DIRECTION])
   {
   case HDD_WLAN_WMM_DIRECTION_UPSTREAM:
      tSpec.ts_info.direction = SME_QOS_WMM_TS_DIR_UPLINK;
      break;

   case HDD_WLAN_WMM_DIRECTION_DOWNSTREAM:
      tSpec.ts_info.direction = SME_QOS_WMM_TS_DIR_DOWNLINK;
      break;

   case HDD_WLAN_WMM_DIRECTION_BIDIRECTIONAL:
      tSpec.ts_info.direction = SME_QOS_WMM_TS_DIR_BOTH;
      break;

   default:
      // unknown
      *pStatus = HDD_WLAN_WMM_STATUS_SETUP_FAILED_BAD_PARAM;
      return 0;
   }

   // validate the user priority
   if (params[HDD_WLAN_WMM_PARAM_USER_PRIORITY] >= SME_QOS_WMM_UP_MAX)
   {
      // out of range
      *pStatus = HDD_WLAN_WMM_STATUS_SETUP_FAILED_BAD_PARAM;
      return 0;
   }
   tSpec.ts_info.up = params[HDD_WLAN_WMM_PARAM_USER_PRIORITY];

   tSpec.nominal_msdu_size = params[HDD_WLAN_WMM_PARAM_NOMINAL_MSDU_SIZE];
   tSpec.maximum_msdu_size = params[HDD_WLAN_WMM_PARAM_MAXIMUM_MSDU_SIZE];
   tSpec.min_data_rate = params[HDD_WLAN_WMM_PARAM_MINIMUM_DATA_RATE];
   tSpec.mean_data_rate = params[HDD_WLAN_WMM_PARAM_MEAN_DATA_RATE];
   tSpec.peak_data_rate = params[HDD_WLAN_WMM_PARAM_PEAK_DATA_RATE];
   tSpec.max_burst_size = params[HDD_WLAN_WMM_PARAM_MAX_BURST_SIZE];
   tSpec.min_phy_rate = params[HDD_WLAN_WMM_PARAM_MINIMUM_PHY_RATE];
   tSpec.surplus_bw_allowance = params[HDD_WLAN_WMM_PARAM_SURPLUS_BANDWIDTH_ALLOWANCE];
   tSpec.min_service_interval = params[HDD_WLAN_WMM_PARAM_SERVICE_INTERVAL];
   tSpec.max_service_interval = params[HDD_WLAN_WMM_PARAM_MAX_SERVICE_INTERVAL];
   tSpec.suspension_interval = params[HDD_WLAN_WMM_PARAM_SUSPENSION_INTERVAL];
   tSpec.inactivity_interval = params[HDD_WLAN_WMM_PARAM_INACTIVITY_INTERVAL];

   tSpec.ts_info.burst_size_defn = params[HDD_WLAN_WMM_PARAM_BURST_SIZE_DEFN];

   // validate the ts info ack policy
   switch (params[HDD_WLAN_WMM_PARAM_ACK_POLICY])
   {
   case HDD_WLAN_WMM_TS_INFO_ACK_POLICY_NORMAL_ACK:
      tSpec.ts_info.ack_policy = SME_QOS_WMM_TS_ACK_POLICY_NORMAL_ACK;
      break;

   case HDD_WLAN_WMM_TS_INFO_ACK_POLICY_HT_IMMEDIATE_BLOCK_ACK:
      tSpec.ts_info.ack_policy = SME_QOS_WMM_TS_ACK_POLICY_HT_IMMEDIATE_BLOCK_ACK;
      break;

   default:
      // unknown
      *pStatus = HDD_WLAN_WMM_STATUS_SETUP_FAILED_BAD_PARAM;
      return 0;
   }

   *pStatus = hdd_wmm_addts(pAdapter, handle, &tSpec);
   return 0;
}


static int iw_del_tspec(struct net_device *dev, struct iw_request_info *info,
                        union iwreq_data *wrqu, char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   int *params = (int *)extra;
   hdd_wlan_wmm_status_e *pStatus = (hdd_wlan_wmm_status_e *)extra;
   v_U32_t handle;

   // make sure the application is sufficiently priviledged
   // note that the kernel will do this for "set" ioctls, but since
   // this ioctl wants to return status to user space it must be
   // defined as a "get" ioctl
   if (!capable(CAP_NET_ADMIN))
   {
      return -EPERM;
   }

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
   {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
      return -EBUSY;
   }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   // although we are defined to be a "get" ioctl, the params we require
   // will fit in the iwreq_data, therefore unlike iw_add_tspec() there
   // is no need to copy the params from user space

   // validate the handle
   handle = params[HDD_WLAN_WMM_PARAM_HANDLE];
   if (HDD_WMM_HANDLE_IMPLICIT == handle)
   {
      // that one is reserved
      *pStatus = HDD_WLAN_WMM_STATUS_SETUP_FAILED_BAD_PARAM;
      return 0;
   }

   *pStatus = hdd_wmm_delts(pAdapter, handle);
   return 0;
}


static int iw_get_tspec(struct net_device *dev, struct iw_request_info *info,
                        union iwreq_data *wrqu, char *extra)
{
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
   int *params = (int *)extra;
   hdd_wlan_wmm_status_e *pStatus = (hdd_wlan_wmm_status_e *)extra;
   v_U32_t handle;

   // although we are defined to be a "get" ioctl, the params we require
   // will fit in the iwreq_data, therefore unlike iw_add_tspec() there
   // is no need to copy the params from user space

   // validate the handle
   handle = params[HDD_WLAN_WMM_PARAM_HANDLE];
   if (HDD_WMM_HANDLE_IMPLICIT == handle)
   {
      // that one is reserved
      *pStatus = HDD_WLAN_WMM_STATUS_SETUP_FAILED_BAD_PARAM;
      return 0;
   }

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
   {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
      return -EBUSY;
   }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   *pStatus = hdd_wmm_checkts(pAdapter, handle);
   return 0;
}


#ifdef FEATURE_WLAN_WAPI
static int iw_qcom_set_wapi_mode(struct net_device *dev, struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_wext_state_t *pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    tCsrRoamProfile *pRoamProfile = &pWextState->roamProfile;

    WAPI_FUNCTION_MODE *pWapiMode = (WAPI_FUNCTION_MODE *)wrqu->data.pointer;

    hddLog(LOG1, "The function iw_qcom_set_wapi_mode called");
<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(LOG1, "%s: Received data %s", __FUNCTION__, (char*)wrqu->data.pointer);
    hddLog(LOG1, "%s: Received length %d", __FUNCTION__, wrqu->data.length);
    hddLog(LOG1, "%s: Input Data (wreq) WAPI Mode:%02d", __FUNCTION__, pWapiMode->wapiMode);


    if(WZC_ORIGINAL == pWapiMode->wapiMode) {
        hddLog(LOG1, "%s: WAPI Mode Set to OFF", __FUNCTION__);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    hddLog(LOG1, "%s: Received data %s", __func__, (char*)wrqu->data.pointer);
    hddLog(LOG1, "%s: Received length %d", __func__, wrqu->data.length);
    hddLog(LOG1, "%s: Input Data (wreq) WAPI Mode:%02d", __func__, pWapiMode->wapiMode);

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }

    if(WZC_ORIGINAL == pWapiMode->wapiMode) {
        hddLog(LOG1, "%s: WAPI Mode Set to OFF", __func__);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
         /* Set Encryption mode to defualt , this allows next successfull non-WAPI Association */
        pRoamProfile->EncryptionType.numEntries = 1;
        pRoamProfile->EncryptionType.encryptionType[0] = eCSR_ENCRYPT_TYPE_NONE;
        pRoamProfile->mcEncryptionType.numEntries = 1;
        pRoamProfile->mcEncryptionType.encryptionType[0] = eCSR_ENCRYPT_TYPE_NONE;

        pRoamProfile->AuthType.numEntries = 1;
        pHddStaCtx->conn_info.authType = eCSR_AUTH_TYPE_OPEN_SYSTEM;
        pRoamProfile->AuthType.authType[0] = pHddStaCtx->conn_info.authType;
    }
    else if(WAPI_EXTENTION == pWapiMode->wapiMode) {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(LOG1, "%s: WAPI Mode Set to ON", __FUNCTION__);
=======
        hddLog(LOG1, "%s: WAPI Mode Set to ON", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        hddLog(LOG1, "%s: WAPI Mode Set to ON", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
    else
         return -EINVAL;

    pAdapter->wapi_info.nWapiMode = pWapiMode->wapiMode;

    return 0;
}

static int iw_qcom_get_wapi_mode(struct net_device *dev, struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    WAPI_FUNCTION_MODE *pWapiMode = (WAPI_FUNCTION_MODE *)(extra);

<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(LOG1, "The function iw_qcom_get_wapi_mode called");

    pWapiMode->wapiMode = pAdapter->wapi_info.nWapiMode;
    hddLog(LOG1, "%s: GET WAPI Mode Value:%02d", __FUNCTION__, pWapiMode->wapiMode);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }
    hddLog(LOG1, "The function iw_qcom_get_wapi_mode called");

    pWapiMode->wapiMode = pAdapter->wapi_info.nWapiMode;
    hddLog(LOG1, "%s: GET WAPI Mode Value:%02d", __func__, pWapiMode->wapiMode);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    printk("\nGET WAPI MODE:%d",pWapiMode->wapiMode);
    return 0;
}

static int iw_qcom_set_wapi_assoc_info(struct net_device *dev, struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
//    WAPI_AssocInfo *pWapiAssocInfo = (WAPI_AssocInfo *)(wrqu->data.pointer);
    WAPI_AssocInfo *pWapiAssocInfo = (WAPI_AssocInfo *)(extra);
    int i = 0, j = 0;
    hddLog(LOG1, "The function iw_qcom_set_wapi_assoc_info called");
<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(LOG1, "%s: Received length %d", __FUNCTION__, wrqu->data.length);
    hddLog(LOG1, "%s: Received data %s", __FUNCTION__, (char*)wrqu->data.pointer);
    hddLog(LOG1, "%s: Received data %s", __FUNCTION__, (char*)extra);

    VOS_ASSERT(pWapiAssocInfo);

    hddLog(LOG1, "%s: INPUT DATA:\nElement ID:0x%02x Length:0x%02x Version:0x%04x\n",__FUNCTION__,pWapiAssocInfo->elementID,pWapiAssocInfo->length,pWapiAssocInfo->version);
    hddLog(LOG1,"%s: akm Suite Cnt:0x%04x",__FUNCTION__,pWapiAssocInfo->akmSuiteCount);
    for(i =0 ; i < 16 ; i++)
        hddLog(LOG1,"akm suite[%02d]:0x%08lx",i,pWapiAssocInfo->akmSuite[i]);

    hddLog(LOG1,"%s: Unicast Suite Cnt:0x%04x",__FUNCTION__,pWapiAssocInfo->unicastSuiteCount);
    for(i =0 ; i < 16 ; i++)
        hddLog(LOG1, "Unicast suite[%02d]:0x%08lx",i,pWapiAssocInfo->unicastSuite[i]);

    hddLog(LOG1,"%s: Multicast suite:0x%08lx Wapi capa:0x%04x",__FUNCTION__,pWapiAssocInfo->multicastSuite,pWapiAssocInfo->wapiCability);
    hddLog(LOG1, "%s: BKID Cnt:0x%04x\n",__FUNCTION__,pWapiAssocInfo->bkidCount);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    hddLog(LOG1, "%s: Received length %d", __func__, wrqu->data.length);
    hddLog(LOG1, "%s: Received data %s", __func__, (char*)wrqu->data.pointer);
    hddLog(LOG1, "%s: Received data %s", __func__, (char*)extra);

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }
    VOS_ASSERT(pWapiAssocInfo);

    hddLog(LOG1, "%s: INPUT DATA:\nElement ID:0x%02x Length:0x%02x Version:0x%04x\n",__func__,pWapiAssocInfo->elementID,pWapiAssocInfo->length,pWapiAssocInfo->version);
    hddLog(LOG1,"%s: akm Suite Cnt:0x%04x",__func__,pWapiAssocInfo->akmSuiteCount);
    for(i =0 ; i < 16 ; i++)
        hddLog(LOG1,"akm suite[%02d]:0x%08lx",i,pWapiAssocInfo->akmSuite[i]);

    hddLog(LOG1,"%s: Unicast Suite Cnt:0x%04x",__func__,pWapiAssocInfo->unicastSuiteCount);
    for(i =0 ; i < 16 ; i++)
        hddLog(LOG1, "Unicast suite[%02d]:0x%08lx",i,pWapiAssocInfo->unicastSuite[i]);

    hddLog(LOG1,"%s: Multicast suite:0x%08lx Wapi capa:0x%04x",__func__,pWapiAssocInfo->multicastSuite,pWapiAssocInfo->wapiCability);
    hddLog(LOG1, "%s: BKID Cnt:0x%04x\n",__func__,pWapiAssocInfo->bkidCount);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    for(i = 0 ; i < 16 ; i++) {
        hddLog(LOG1, "BKID List[%02d].bkid:0x",i);
        for(j = 0 ; j < 16 ; j++)
            hddLog(LOG1,"%02x",pWapiAssocInfo->bkidList[i].bkid[j]);
    }

    /* We are not using the entire IE as provided by the supplicant.
     * This is being calculated by SME. This is the same as in the
     * case of WPA. Only the auth mode information needs to be
     * extracted here*/
    if ( pWapiAssocInfo->akmSuite[0] == WAPI_PSK_AKM_SUITE ) {
<<<<<<< HEAD
<<<<<<< HEAD
       hddLog(LOG1, "%s: WAPI AUTH MODE SET TO PSK",__FUNCTION__);
=======
       hddLog(LOG1, "%s: WAPI AUTH MODE SET TO PSK",__func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
       hddLog(LOG1, "%s: WAPI AUTH MODE SET TO PSK",__func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       pAdapter->wapi_info.wapiAuthMode = WAPI_AUTH_MODE_PSK;
    }

    if ( pWapiAssocInfo->akmSuite[0] == WAPI_CERT_AKM_SUITE) {
<<<<<<< HEAD
<<<<<<< HEAD
       hddLog(LOG1, "%s: WAPI AUTH MODE SET TO CERTIFICATE",__FUNCTION__);
=======
       hddLog(LOG1, "%s: WAPI AUTH MODE SET TO CERTIFICATE",__func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
       hddLog(LOG1, "%s: WAPI AUTH MODE SET TO CERTIFICATE",__func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       pAdapter->wapi_info.wapiAuthMode = WAPI_AUTH_MODE_CERT;
    }
    return 0;
}

static int iw_qcom_set_wapi_key(struct net_device *dev, struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    eHalStatus       halStatus   = eHAL_STATUS_SUCCESS;
    tANI_U32         roamId      = 0xFF;
    tANI_U8         *pKeyPtr     = NULL;
    v_BOOL_t         isConnected = TRUE;
    tCsrRoamSetKey   setKey;
    int i = 0;
<<<<<<< HEAD
<<<<<<< HEAD

//    WLAN_WAPI_KEY *pWapiKey = (WLAN_WAPI_KEY *)(wrqu->data.pointer);
    WLAN_WAPI_KEY *pWapiKey = (WLAN_WAPI_KEY *)(extra);

    hddLog(LOG1, "The function iw_qcom_set_wapi_key called ");
    hddLog(LOG1, "%s: Received length %d", __FUNCTION__, wrqu->data.length);
    hddLog(LOG1, "%s: Received data %s", __FUNCTION__, (char*)wrqu->data.pointer);
    hddLog(LOG1, "%s: Received data %s", __FUNCTION__, (char*)extra);

    hddLog(LOG1,":s: INPUT DATA:\nKey Type:0x%02x Key Direction:0x%02x KEY ID:0x%02x\n", __FUNCTION__,pWapiKey->keyType,pWapiKey->keyDirection,pWapiKey->keyId);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    WLAN_WAPI_KEY *pWapiKey = (WLAN_WAPI_KEY *)(extra);

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }

    hddLog(LOG1, "The function iw_qcom_set_wapi_key called ");
    hddLog(LOG1, "%s: Received length %d", __func__, wrqu->data.length);
    hddLog(LOG1, "%s: Received data %s", __func__, (char*)wrqu->data.pointer);
    hddLog(LOG1, "%s: Received data %s", __func__, (char*)extra);

    hddLog(LOG1,":%s: INPUT DATA:\nKey Type:0x%02x Key Direction:0x%02x KEY ID:0x%02x\n", __func__, pWapiKey->keyType, pWapiKey->keyDirection, pWapiKey->keyId);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    hddLog(LOG1,"Add Index:0x");
    for(i =0 ; i < 12 ; i++)
        hddLog(LOG1,"%02x",pWapiKey->addrIndex[i]);

<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(LOG1,"\n%s: WAPI ENCRYPTION KEY LENGTH:0x%04x", __FUNCTION__,pWapiKey->wpiekLen);
=======
    hddLog(LOG1,"\n%s: WAPI ENCRYPTION KEY LENGTH:0x%04x", __func__,pWapiKey->wpiekLen);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    hddLog(LOG1,"\n%s: WAPI ENCRYPTION KEY LENGTH:0x%04x", __func__,pWapiKey->wpiekLen);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    hddLog(LOG1, "WAPI ENCRYPTION KEY:0x");
    for(i =0 ; i < 16 ; i++)
        hddLog(LOG1,"%02x",pWapiKey->wpiek[i]);

<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(LOG1,"\n%s: WAPI INTEGRITY CHECK KEY LENGTH:0x%04x", __FUNCTION__,pWapiKey->wpickLen);
=======
    hddLog(LOG1,"\n%s: WAPI INTEGRITY CHECK KEY LENGTH:0x%04x", __func__,pWapiKey->wpickLen);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    hddLog(LOG1,"\n%s: WAPI INTEGRITY CHECK KEY LENGTH:0x%04x", __func__,pWapiKey->wpickLen);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    hddLog(LOG1,"WAPI INTEGRITY CHECK KEY:0x");
    for(i =0 ; i < 16 ; i++)
        hddLog(LOG1,"%02x",pWapiKey->wpick[i]);

    hddLog(LOG1,"\nWAPI PN NUMBER:0x");
    for(i = 0 ; i < 16 ; i++)
        hddLog(LOG1,"%02x",pWapiKey->pn[i]);

    // Clear the setkey memory
    vos_mem_zero(&setKey,sizeof(tCsrRoamSetKey));
    // Store Key ID
    setKey.keyId = (unsigned char)( pWapiKey->keyId );
    // SET WAPI Encryption
    setKey.encType  = eCSR_ENCRYPT_TYPE_WPI;
    // Key Directionn both TX and RX
    setKey.keyDirection = eSIR_TX_RX; // Do WE NEED to update this based on Key Type as GRP/UNICAST??
    // the PAE role
    setKey.paeRole = 0 ;

    switch ( pWapiKey->keyType )
    {
<<<<<<< HEAD
<<<<<<< HEAD
        case HDD_PAIRWISE_WAPI_KEY:
=======
        case PAIRWISE_KEY:
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        case PAIRWISE_KEY:
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        {
            isConnected = hdd_connIsConnected(pHddStaCtx);
            vos_mem_copy(setKey.peerMac,&pHddStaCtx->conn_info.bssId,WNI_CFG_BSSID_LEN);
            break;
        }
<<<<<<< HEAD
<<<<<<< HEAD
        case HDD_GROUP_WAPI_KEY:
=======
        case GROUP_KEY:
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        case GROUP_KEY:
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        {
            vos_set_macaddr_broadcast( (v_MACADDR_t *)setKey.peerMac );
            break;
        }
        default:
        {
            //Any other option is invalid.
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
<<<<<<< HEAD
<<<<<<< HEAD
                       "[%4d] %s() failed to Set Key. Invalid key type %d", __LINE__,__FUNCTION__ , -1 );

            hddLog(LOGE," %s: Error WAPI Key Add Type",__FUNCTION__);
=======
                       "[%4d] %s() failed to Set Key. Invalid key type %d", __LINE__,__func__ , -1 );

            hddLog(LOGE," %s: Error WAPI Key Add Type",__func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                       "[%4d] %s() failed to Set Key. Invalid key type %d", __LINE__,__func__ , -1 );

            hddLog(LOGE," %s: Error WAPI Key Add Type",__func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            halStatus = !eHAL_STATUS_SUCCESS; // NEED TO UPDATE THIS WITH CORRECT VALUE
            break; // NEED RETURN FROM HERE ????
        }
    }

    // Concatenating the Encryption Key (EK) and the MIC key (CK): EK followed by CK
    setKey.keyLength = (v_U16_t)((pWapiKey->wpiekLen)+(pWapiKey->wpickLen));
    pKeyPtr = setKey.Key;
    memcpy( pKeyPtr, pWapiKey->wpiek, pWapiKey->wpiekLen );
    pKeyPtr += pWapiKey->wpiekLen;
    memcpy( pKeyPtr, pWapiKey->wpick, pWapiKey->wpickLen );

    // Set the new key with SME.
    pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_SETTING_KEY;

    if ( isConnected ) {
        halStatus = sme_RoamSetKey( WLAN_HDD_GET_HAL_CTX(pAdapter), pAdapter->sessionId, &setKey, &roamId );
        if ( halStatus != eHAL_STATUS_SUCCESS )
        {
            VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                       "[%4d] sme_RoamSetKey returned ERROR status= %d", __LINE__, halStatus );

            pHddStaCtx->roam_info.roamingState = HDD_ROAM_STATE_NONE;
        }
    }
#if 0 /// NEED TO CHECK ON THIS
    else
    {
        // Store the keys in the adapter to be moved to the profile & passed to
        // SME in the ConnectRequest if we are not yet in connected state.
         memcpy( &pAdapter->setKey[ setKey.keyId ], &setKey, sizeof( setKey ) );
         pAdapter->fKeySet[ setKey.keyId ] = TRUE;

         VOS_TRACE( VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO_MED,
                    "  Saving key [idx= %d] to apply when moving to connected state ",
                    setKey.keyId );

    }
#endif
    return halStatus;
}

static int iw_qcom_set_wapi_bkid(struct net_device *dev, struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#ifdef WLAN_DEBUG
    int i = 0;
    WLAN_BKID_LIST  *pBkid       = ( WLAN_BKID_LIST *) (wrqu->data.pointer);
#endif

    hddLog(LOG1, "The function iw_qcom_set_wapi_bkid called");
<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(LOG1, "%s: Received length %d", __FUNCTION__, wrqu->data.length);
    hddLog(LOG1, "%s: Received data %s", __FUNCTION__, (char*)wrqu->data.pointer);
    hddLog(LOG1, "%s: Received data %s", __FUNCTION__, (char*)extra);

    hddLog(LOG1,"%s: INPUT DATA:\n BKID Length:0x%08lx\n", __FUNCTION__,pBkid->length);
    hddLog(LOG1,"%s: BKID Cnt:0x%04lx",pBkid->BKIDCount);

    hddLog(LOG1,"BKID KEY LIST[0]:0x");
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    hddLog(LOG1, "%s: Received length %d", __func__, wrqu->data.length);
    hddLog(LOG1, "%s: Received data %s", __func__, (char*)wrqu->data.pointer);
    hddLog(LOG1, "%s: Received data %s", __func__, (char*)extra);

    hddLog(LOG1,"%s: INPUT DATA:\n BKID Length:0x%08lx\n", __func__,pBkid->length);
    hddLog(LOG1,"%s: BKID Cnt:0x%04lx",pBkid->BKIDCount);

    hddLog(LOG1,"BKID KEY LIST[0]:0x");

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#ifdef WLAN_DEBUG
    for(i =0 ; i < 16 ; i++)
        hddLog(LOG1,"%02x",pBkid->BKID[0].bkid[i]);
#endif

    return 0;
}

static int iw_qcom_get_wapi_bkid(struct net_device *dev, struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
    /* Yet to implement this function, 19th April 2010 */
    hddLog(LOG1, "The function iw_qcom_get_wapi_bkid called ");

    return 0;
}
#endif /* FEATURE_WLAN_WAPI */

#ifdef WLAN_FEATURE_VOWIFI_11R
//
//
// Each time the supplicant has the auth_request or reassoc request
// IEs ready. This is pushed to the driver. The driver will inturn use
// it to send out the auth req and reassoc req for 11r FT Assoc.
//
static int iw_set_fties(struct net_device *dev, struct iw_request_info *info,
                        union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
    //v_CONTEXT_t pVosContext;

<<<<<<< HEAD
<<<<<<< HEAD
    if (!wrqu->data.length)
    {
        hddLog(LOGE, FL("%s called with 0 length IEs\n"));
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }
    if (!wrqu->data.length)
    {
        hddLog(LOGE, FL("called with 0 length IEs\n"));
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return -EINVAL;
    }
    if (wrqu->data.pointer == NULL)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        hddLog(LOGE, FL("%s called with NULL IE\n"));
=======
        hddLog(LOGE, FL("called with NULL IE\n"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        hddLog(LOGE, FL("called with NULL IE\n"));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return -EINVAL;
    }

    // Added for debug on reception of Re-assoc Req.
    if (eConnectionState_Associated != pHddStaCtx->conn_info.connState)
    {
        hddLog(LOGE, FL("Called with Ie of length = %d when not associated\n"),
            wrqu->data.length);
        hddLog(LOGE, FL("Should be Re-assoc Req IEs\n"));
    }

#ifdef WLAN_FEATURE_VOWIFI_11R_DEBUG
    hddLog(LOGE, FL("%s called with Ie of length = %d\n"), __func__, wrqu->data.length);
#endif

    // Pass the received FT IEs to SME
    sme_SetFTIEs( WLAN_HDD_GET_HAL_CTX(pAdapter), pAdapter->sessionId, wrqu->data.pointer,
        wrqu->data.length);

    return 0;
}
#endif

<<<<<<< HEAD
<<<<<<< HEAD
static int iw_set_dynamic_mcbc_filter(struct net_device *dev, 
        struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{   
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tpMcBcFilterCfg pRequest = (tpMcBcFilterCfg)wrqu->data.pointer;
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    tpSirWlanSetRxpFilters wlanRxpFilterParam;
    VOS_STATUS vstatus = VOS_STATUS_E_FAILURE;

    hddLog(VOS_TRACE_LEVEL_INFO_HIGH, 
           "%s: Set MC BC Filter Config request: %d suspend %d",
           __FUNCTION__, pRequest->mcastBcastFilterSetting,
           pHddCtx->hdd_wlan_suspended);

    wlanRxpFilterParam = vos_mem_malloc(sizeof(tSirWlanSetRxpFilters));
    if(NULL == wlanRxpFilterParam)
    {
        hddLog(VOS_TRACE_LEVEL_FATAL,
           "%s: vos_mem_alloc failed ", __func__);
        return -EINVAL;
    }

    pHddCtx->dynamic_mcbc_filter.mcastBcastFilterSetting = 
                               pRequest->mcastBcastFilterSetting; 
    pHddCtx->dynamic_mcbc_filter.enableCfg = TRUE; 

    if(pHddCtx->hdd_wlan_suspended)
    {
      wlanRxpFilterParam->configuredMcstBcstFilterSetting = 
                               pRequest->mcastBcastFilterSetting;
      wlanRxpFilterParam->setMcstBcstFilter = TRUE;

      if((pHddCtx->cfg_ini->fhostArpOffload) && 
         (eConnectionState_Associated == 
         (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.connState))
      {
        vstatus = hdd_conf_hostarpoffload(pHddCtx, TRUE);
        if (!VOS_IS_STATUS_SUCCESS(vstatus))
        {
          hddLog(VOS_TRACE_LEVEL_INFO, 
                 "%s:Failed to enable ARPOFFLOAD Feature %d\n",
                 __func__, vstatus);
        }
        else
        {
          if (HDD_MCASTBCASTFILTER_FILTER_ALL_MULTICAST_BROADCAST == 
              pHddCtx->dynamic_mcbc_filter.mcastBcastFilterSetting)
          {
            wlanRxpFilterParam->configuredMcstBcstFilterSetting = 
                       HDD_MCASTBCASTFILTER_FILTER_ALL_MULTICAST;
          }
          else if(HDD_MCASTBCASTFILTER_FILTER_ALL_BROADCAST == 
                  pHddCtx->dynamic_mcbc_filter.mcastBcastFilterSetting)
          {
            wlanRxpFilterParam->configuredMcstBcstFilterSetting = 
                           HDD_MCASTBCASTFILTER_FILTER_NONE;
          }
        }
      }

      hddLog(VOS_TRACE_LEVEL_INFO, "%s:MC/BC changed Req %d Set %d En %d",
             __func__,
             pHddCtx->dynamic_mcbc_filter.mcastBcastFilterSetting,
             wlanRxpFilterParam->configuredMcstBcstFilterSetting,
             wlanRxpFilterParam->setMcstBcstFilter);

      if (eHAL_STATUS_SUCCESS != sme_ConfigureRxpFilter(WLAN_HDD_GET_HAL_CTX(pAdapter),
                                                   wlanRxpFilterParam))
      {
        hddLog(VOS_TRACE_LEVEL_ERROR, 
               "%s: Failure to execute set HW MC/BC Filter request\n",
               __func__);
        return -EINVAL;
      }

      pHddCtx->dynamic_mcbc_filter.mcBcFilterSuspend = 
                         wlanRxpFilterParam->configuredMcstBcstFilterSetting;
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
static int iw_set_dynamic_mcbc_filter(struct net_device *dev,
        struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tpRcvFltMcAddrList pRequest = (tpRcvFltMcAddrList)wrqu->data.pointer;
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    tpSirWlanSetRxpFilters wlanRxpFilterParam;
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    VOS_STATUS vstatus = VOS_STATUS_E_FAILURE;
    tpSirRcvFltMcAddrList mc_addr_list_ptr;
    int idx;
    eHalStatus ret_val;
    tANI_U8 mcastBcastFilterSetting;

    if (pHddCtx->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }

    if (HDD_MULTICAST_FILTER_LIST == pRequest->mcastBcastFilterSetting) {

        mc_addr_list_ptr = vos_mem_malloc(sizeof(tSirRcvFltMcAddrList));
        if (NULL == mc_addr_list_ptr)
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                   "%s: vos_mem_alloc failed", __func__);
            return -ENOMEM;
        }

        mc_addr_list_ptr->ulMulticastAddrCnt = pRequest->mcast_addr_cnt;

        if (mc_addr_list_ptr->ulMulticastAddrCnt > HDD_MAX_NUM_MULTICAST_ADDRESS)
            mc_addr_list_ptr->ulMulticastAddrCnt = HDD_MAX_NUM_MULTICAST_ADDRESS;

        hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s MC Addr List Cnt %d", __func__,
               mc_addr_list_ptr->ulMulticastAddrCnt);

        for (idx = 0; idx < mc_addr_list_ptr->ulMulticastAddrCnt; idx++)
        {
            memcpy(&mc_addr_list_ptr->multicastAddr[idx],
                   pRequest->multicastAddr[idx], HDD_WLAN_MAC_ADDR_LEN);

            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s MC Addr for Idx %d ="MAC_ADDRESS_STR, __func__,
                   idx, MAC_ADDR_ARRAY(mc_addr_list_ptr->multicastAddr[idx]));
        }

        ret_val = sme_8023MulticastList(hHal, pAdapter->sessionId, mc_addr_list_ptr);
        vos_mem_free(mc_addr_list_ptr);
        if (eHAL_STATUS_SUCCESS != ret_val)
        {
            hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Failure to Set MC Address List",
                   __func__);
            return -EINVAL;
        }
    } else {

        hddLog(VOS_TRACE_LEVEL_INFO_HIGH,
               "%s: Set MC BC Filter Config request: %d suspend %d",
               __func__, pRequest->mcastBcastFilterSetting,
               pHddCtx->hdd_wlan_suspended);

        pHddCtx->dynamic_mcbc_filter.mcastBcastFilterSetting =
            pRequest->mcastBcastFilterSetting;
        pHddCtx->dynamic_mcbc_filter.enableCfg = TRUE;

        if (pHddCtx->hdd_wlan_suspended)
        {
            wlanRxpFilterParam = vos_mem_malloc(sizeof(tSirWlanSetRxpFilters));
            if (NULL == wlanRxpFilterParam)
            {
                hddLog(VOS_TRACE_LEVEL_FATAL,
                       "%s: vos_mem_alloc failed", __func__);
                return -EINVAL;
            }

            wlanRxpFilterParam->configuredMcstBcstFilterSetting =
                pRequest->mcastBcastFilterSetting;
            wlanRxpFilterParam->setMcstBcstFilter = TRUE;

            if ((pHddCtx->cfg_ini->fhostArpOffload) &&
                (eConnectionState_Associated ==
                 (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.connState))
            {
                vstatus = hdd_conf_hostarpoffload(pAdapter, TRUE);
                if (!VOS_IS_STATUS_SUCCESS(vstatus))
                {
                    hddLog(VOS_TRACE_LEVEL_INFO,
                           "%s:Failed to enable ARPOFFLOAD Feature %d",
                           __func__, vstatus);
                }
                else
                {
                    if (HDD_MCASTBCASTFILTER_FILTER_ALL_MULTICAST_BROADCAST ==
                        pHddCtx->dynamic_mcbc_filter.mcastBcastFilterSetting)
                    {
                        wlanRxpFilterParam->configuredMcstBcstFilterSetting =
                            HDD_MCASTBCASTFILTER_FILTER_ALL_MULTICAST;
                    }
                    else if (HDD_MCASTBCASTFILTER_FILTER_ALL_BROADCAST ==
                             pHddCtx->dynamic_mcbc_filter.mcastBcastFilterSetting)
                    {
                        wlanRxpFilterParam->configuredMcstBcstFilterSetting =
                            HDD_MCASTBCASTFILTER_FILTER_NONE;
                    }
                }
            }

            hddLog(VOS_TRACE_LEVEL_INFO, "%s:MC/BC changed Req %d Set %d En %d",
                   __func__,
                   pHddCtx->dynamic_mcbc_filter.mcastBcastFilterSetting,
                   wlanRxpFilterParam->configuredMcstBcstFilterSetting,
                   wlanRxpFilterParam->setMcstBcstFilter);

            mcastBcastFilterSetting = wlanRxpFilterParam->configuredMcstBcstFilterSetting;

            if (eHAL_STATUS_SUCCESS != sme_ConfigureRxpFilter(WLAN_HDD_GET_HAL_CTX(pAdapter),
                                                              wlanRxpFilterParam))
            {
                hddLog(VOS_TRACE_LEVEL_ERROR,
                       "%s: Failure to execute set HW MC/BC Filter request",
                       __func__);
                vos_mem_free(wlanRxpFilterParam);
                return -EINVAL;
            }

            pHddCtx->dynamic_mcbc_filter.mcBcFilterSuspend =
                mcastBcastFilterSetting;
        }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }

    return 0;
}

static int iw_clear_dynamic_mcbc_filter(struct net_device *dev, 
        struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

<<<<<<< HEAD
<<<<<<< HEAD
    hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: ", __FUNCTION__);
=======
    hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: ", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: ", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    pHddCtx->dynamic_mcbc_filter.enableCfg = FALSE;

    return 0;
}

static int iw_set_host_offload(struct net_device *dev, struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tpHostOffloadRequest pRequest = (tpHostOffloadRequest)wrqu->data.pointer;
    tSirHostOffloadReq offloadRequest;

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    /* Debug display of request components. */
    switch (pRequest->offloadType)
    {
        case WLAN_IPV4_ARP_REPLY_OFFLOAD:
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_WARN, "%s: Host offload request: ARP reply", __FUNCTION__);
=======
            hddLog(VOS_TRACE_LEVEL_WARN, "%s: Host offload request: ARP reply", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            hddLog(VOS_TRACE_LEVEL_WARN, "%s: Host offload request: ARP reply", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            switch (pRequest->enableOrDisable)
            {
                case WLAN_OFFLOAD_DISABLE:
                    hddLog(VOS_TRACE_LEVEL_WARN, "   disable");
                    break;
                case WLAN_OFFLOAD_ARP_AND_BC_FILTER_ENABLE:
                    hddLog(VOS_TRACE_LEVEL_WARN, "   BC Filtering enable");
                case WLAN_OFFLOAD_ENABLE:
                    hddLog(VOS_TRACE_LEVEL_WARN, "   ARP offload enable");
                    hddLog(VOS_TRACE_LEVEL_WARN, "   IP address: %d.%d.%d.%d",
                            pRequest->params.hostIpv4Addr[0], pRequest->params.hostIpv4Addr[1],
                            pRequest->params.hostIpv4Addr[2], pRequest->params.hostIpv4Addr[3]);
            }
            break;

    case WLAN_IPV6_NEIGHBOR_DISCOVERY_OFFLOAD:
        hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: Host offload request: neighbor discovery\n",
<<<<<<< HEAD
<<<<<<< HEAD
               __FUNCTION__);
=======
               __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
               __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        switch (pRequest->enableOrDisable)
        {
        case WLAN_OFFLOAD_DISABLE:
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "   disable");
            break;
        case WLAN_OFFLOAD_ENABLE:
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "   enable");
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "   IP address: %x:%x:%x:%x:%x:%x:%x:%x",
                   *(v_U16_t *)(pRequest->params.hostIpv6Addr),
                   *(v_U16_t *)(pRequest->params.hostIpv6Addr + 2),
                   *(v_U16_t *)(pRequest->params.hostIpv6Addr + 4),
                   *(v_U16_t *)(pRequest->params.hostIpv6Addr + 6),
                   *(v_U16_t *)(pRequest->params.hostIpv6Addr + 8),
                   *(v_U16_t *)(pRequest->params.hostIpv6Addr + 10),
                   *(v_U16_t *)(pRequest->params.hostIpv6Addr + 12),
                   *(v_U16_t *)(pRequest->params.hostIpv6Addr + 14));
        }
    }

    /* Execute offload request. The reason that we can copy the request information
       from the ioctl structure to the SME structure is that they are laid out
       exactly the same.  Otherwise, each piece of information would have to be
       copied individually. */
    memcpy(&offloadRequest, pRequest, wrqu->data.length);
    if (eHAL_STATUS_SUCCESS != sme_SetHostOffload(WLAN_HDD_GET_HAL_CTX(pAdapter),
                                        pAdapter->sessionId, &offloadRequest))
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Failure to execute host offload request\n",
               __func__);
        return -EINVAL;
    }

    return 0;
}

static int iw_set_keepalive_params(struct net_device *dev, struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tpKeepAliveRequest pRequest = (tpKeepAliveRequest)wrqu->data.pointer;
    tSirKeepAliveReq keepaliveRequest;

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
<<<<<<< HEAD
<<<<<<< HEAD
                                  "%s:LOGP in Progress. Ignore!!!",__func__);
=======
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return 0;
    }

    /* Debug display of request components. */
    hddLog(VOS_TRACE_LEVEL_INFO, "%s: Set Keep Alive Request : TimePeriod %d size %d",
<<<<<<< HEAD
<<<<<<< HEAD
           __FUNCTION__,pRequest->timePeriod, sizeof(tKeepAliveRequest));
=======
           __func__,pRequest->timePeriod, sizeof(tKeepAliveRequest));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
           __func__,pRequest->timePeriod, sizeof(tKeepAliveRequest));
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

      switch (pRequest->packetType)
      {
        case WLAN_KEEP_ALIVE_NULL_PKT:
<<<<<<< HEAD
<<<<<<< HEAD
            hddLog(VOS_TRACE_LEVEL_WARN, "%s: Keep Alive Request: Tx NULL", __FUNCTION__);
=======
            hddLog(VOS_TRACE_LEVEL_WARN, "%s: Keep Alive Request: Tx NULL", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            hddLog(VOS_TRACE_LEVEL_WARN, "%s: Keep Alive Request: Tx NULL", __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            break;

        case WLAN_KEEP_ALIVE_UNSOLICIT_ARP_RSP:

            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: Keep Alive Request: Tx UnSolicited ARP RSP\n",
<<<<<<< HEAD
<<<<<<< HEAD
               __FUNCTION__);
=======
               __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
               __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

            hddLog(VOS_TRACE_LEVEL_WARN, "  Host IP address: %d.%d.%d.%d",
            pRequest->hostIpv4Addr[0], pRequest->hostIpv4Addr[1],
            pRequest->hostIpv4Addr[2], pRequest->hostIpv4Addr[3]);

            hddLog(VOS_TRACE_LEVEL_WARN, "  Dest IP address: %d.%d.%d.%d",
            pRequest->destIpv4Addr[0], pRequest->destIpv4Addr[1],
            pRequest->destIpv4Addr[2], pRequest->destIpv4Addr[3]);

            hddLog(VOS_TRACE_LEVEL_WARN, "  Dest MAC address: %d:%d:%d:%d:%d:%d",
            pRequest->destMacAddr[0], pRequest->destMacAddr[1],
            pRequest->destMacAddr[2], pRequest->destMacAddr[3],
            pRequest->destMacAddr[4], pRequest->destMacAddr[5]);
            break;

      }

    /* Execute keep alive request. The reason that we can copy the request information
       from the ioctl structure to the SME structure is that they are laid out
       exactly the same.  Otherwise, each piece of information would have to be
       copied individually. */
       memcpy(&keepaliveRequest, pRequest, wrqu->data.length);

       hddLog(VOS_TRACE_LEVEL_ERROR, "set Keep: TP before SME %d\n", keepaliveRequest.timePeriod);

    if (eHAL_STATUS_SUCCESS != sme_SetKeepAlive(WLAN_HDD_GET_HAL_CTX(pAdapter), 
                                        pAdapter->sessionId, &keepaliveRequest))
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Failure to execute Keep Alive\n",
               __func__);
        return -EINVAL;
    }

    return 0;
}

#ifdef WLAN_FEATURE_PACKET_FILTERING
int wlan_hdd_set_filter(hdd_context_t *pHddCtx, tpPacketFilterCfg pRequest, 
                            tANI_U8 sessionId)
{
<<<<<<< HEAD
<<<<<<< HEAD
    tSirRcvPktFilterCfgType    packetFilterSetReq;
    tSirRcvFltPktClearParam    packetFilterClrReq;
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    tSirRcvPktFilterCfgType    packetFilterSetReq = {0};
    tSirRcvFltPktClearParam    packetFilterClrReq = {0};
    //IKHSS7-35965, a19091, Motorola changes -- BEGIN
    int retVal=0;
    //IKHSS7-35965, a19091, Motorola changes -- END
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    int i=0;

    if (pHddCtx->cfg_ini->disablePacketFilter)
    {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Packet Filtering Disabled. Returning ",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__ );
        return 0;
    }

    /* Debug display of request components. */
    hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Packet Filter Request : FA %d params %d",
            __FUNCTION__, pRequest->filterAction, pRequest->numParams);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                __func__ );
        return retVal;
    }
    if (pHddCtx->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }
    /* Debug display of request components. */
    hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Packet Filter Request : FA %d params %d",
            __func__, pRequest->filterAction, pRequest->numParams);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    switch (pRequest->filterAction)
    {
        case HDD_RCV_FILTER_SET:
            hddLog(VOS_TRACE_LEVEL_INFO, "%s: Set Packet Filter Request for Id: %d",
<<<<<<< HEAD
<<<<<<< HEAD
                    __FUNCTION__, pRequest->filterId);
=======
                    __func__, pRequest->filterId);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                    __func__, pRequest->filterId);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

            packetFilterSetReq.filterId = pRequest->filterId;
            if ( pRequest->numParams >= HDD_MAX_CMP_PER_PACKET_FILTER)
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Number of Params exceed Max limit %d\n",
                        __func__, pRequest->numParams);
<<<<<<< HEAD
<<<<<<< HEAD
                return -EINVAL;
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
				//IKHSS7-35965, a19091, Motorola changes -- BEGIN
				retVal = -EINVAL;
				break;
				//IKHSS7-35965, a19091, Motorola changes -- END
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            }
            packetFilterSetReq.numFieldParams = pRequest->numParams;
            packetFilterSetReq.coalesceTime = 0;
            packetFilterSetReq.filterType = 1;
            for (i=0; i < pRequest->numParams; i++)
            {
                packetFilterSetReq.paramsData[i].protocolLayer = pRequest->paramsData[i].protocolLayer;
                packetFilterSetReq.paramsData[i].cmpFlag = pRequest->paramsData[i].cmpFlag;
                packetFilterSetReq.paramsData[i].dataOffset = pRequest->paramsData[i].dataOffset;
                packetFilterSetReq.paramsData[i].dataLength = pRequest->paramsData[i].dataLength;
                packetFilterSetReq.paramsData[i].reserved = 0;

<<<<<<< HEAD
<<<<<<< HEAD
                hddLog(VOS_TRACE_LEVEL_INFO, "Proto %d Comp Flag %d Filter Type\n",
=======
                hddLog(VOS_TRACE_LEVEL_INFO, "Proto %d Comp Flag %d Filter Type %d\n",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                hddLog(VOS_TRACE_LEVEL_INFO, "Proto %d Comp Flag %d Filter Type %d\n",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                        pRequest->paramsData[i].protocolLayer, pRequest->paramsData[i].cmpFlag,
                        packetFilterSetReq.filterType);

                hddLog(VOS_TRACE_LEVEL_INFO, "Data Offset %d Data Len %d\n",
                        pRequest->paramsData[i].dataOffset, pRequest->paramsData[i].dataLength);

                memcpy(&packetFilterSetReq.paramsData[i].compareData,
                        pRequest->paramsData[i].compareData, pRequest->paramsData[i].dataLength);
                memcpy(&packetFilterSetReq.paramsData[i].dataMask,
                        pRequest->paramsData[i].dataMask, pRequest->paramsData[i].dataLength);

                hddLog(VOS_TRACE_LEVEL_INFO, "CData %d CData %d CData %d CData %d CData %d CData %d\n",
                        pRequest->paramsData[i].compareData[0], pRequest->paramsData[i].compareData[1],
                        pRequest->paramsData[i].compareData[2], pRequest->paramsData[i].compareData[3],
                        pRequest->paramsData[i].compareData[4], pRequest->paramsData[i].compareData[5]);

                hddLog(VOS_TRACE_LEVEL_INFO, "MData %d MData %d MData %d MData %d MData %d MData %d\n",
                        pRequest->paramsData[i].dataMask[0], pRequest->paramsData[i].dataMask[1],
                        pRequest->paramsData[i].dataMask[2], pRequest->paramsData[i].dataMask[3],
                        pRequest->paramsData[i].dataMask[4], pRequest->paramsData[i].dataMask[5]);
            }

            if (eHAL_STATUS_SUCCESS != sme_ReceiveFilterSetFilter(pHddCtx->hHal, &packetFilterSetReq, sessionId))
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Failure to execute Set Filter\n",
                        __func__);
<<<<<<< HEAD
<<<<<<< HEAD
                return -EINVAL;
=======
                retVal = -EINVAL; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                retVal = -EINVAL; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            }

            break;

        case HDD_RCV_FILTER_CLEAR:

            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: Clear Packet Filter Request for Id: %d\n",
<<<<<<< HEAD
<<<<<<< HEAD
                    __FUNCTION__, pRequest->filterId);
=======
                    __func__, pRequest->filterId);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                    __func__, pRequest->filterId);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            packetFilterClrReq.filterId = pRequest->filterId;
            if (eHAL_STATUS_SUCCESS != sme_ReceiveFilterClearFilter(pHddCtx->hHal, &packetFilterClrReq, sessionId))
            {
                hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Failure to execute Clear Filter\n",
                        __func__);
<<<<<<< HEAD
<<<<<<< HEAD
                return -EINVAL;
=======
                retVal = -EINVAL; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                retVal = -EINVAL; //IKHSS7-35965, a19091, Motorola
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            }
            break;

        default :
            hddLog(VOS_TRACE_LEVEL_INFO_HIGH, "%s: Packet Filter Request: Invalid %d\n",
<<<<<<< HEAD
<<<<<<< HEAD
                    __FUNCTION__, pRequest->filterAction);
            return -EINVAL;
    }
    return 0;
}

void wlan_hdd_set_mc_addr_list(hdd_context_t *pHddCtx, v_U8_t set, v_U8_t sessionId)
{
    v_U8_t filterAction = 0; 
    tPacketFilterCfg request = {0}; 
    v_U8_t i = 0;

    filterAction = set ? HDD_RCV_FILTER_SET : HDD_RCV_FILTER_CLEAR;

    /*set mulitcast addr list*/
    for (i = 0; i < pHddCtx->mc_addr_list.mc_cnt; i++)
    {
        memset(&request, 0, sizeof (tPacketFilterCfg));
        request.filterAction = filterAction;
        request.filterId = i; 
        if (set)
        {
            request.numParams = 1; 
            request.paramsData[0].protocolLayer = HDD_FILTER_PROTO_TYPE_MAC; 
            request.paramsData[0].cmpFlag = HDD_FILTER_CMP_TYPE_EQUAL;   
            request.paramsData[0].dataOffset = WLAN_HDD_80211_FRM_DA_OFFSET;
            request.paramsData[0].dataLength = ETH_ALEN;
            memcpy(&(request.paramsData[0].compareData[0]), 
                    &(pHddCtx->mc_addr_list.addr[i][0]), ETH_ALEN);
            /*set mulitcast filters*/
            hddLog(VOS_TRACE_LEVEL_INFO, 
                    "%s: %s multicast filter: addr =" 
                    "%02x:%02x:%02x:%02x:%02x:%02x", 
                    __func__, set ? "setting" : "clearing", 
                    request.paramsData[0].compareData[0], 
                    request.paramsData[0].compareData[1],
                    request.paramsData[0].compareData[2], 
                    request.paramsData[0].compareData[3],
                    request.paramsData[0].compareData[4], 
                    request.paramsData[0].compareData[5]);
        }
        wlan_hdd_set_filter(pHddCtx, &request, sessionId);
    }
    pHddCtx->mc_addr_list.isFilterApplied = set ? TRUE : FALSE;
}
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                    __func__, pRequest->filterAction);
            retVal = -EINVAL; //IKHSS7-35965, a19091, Motorola
    }
    return retVal;
}

int wlan_hdd_setIPv6Filter(hdd_context_t *pHddCtx, tANI_U8 filterType,
                           tANI_U8 sessionId)
{
    tSirRcvPktFilterCfgType    packetFilterSetReq = {0};
    tSirRcvFltPktClearParam    packetFilterClrReq = {0};

    if (NULL == pHddCtx)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, FL(" NULL HDD Context Passed"));
        return -EINVAL;
    }

    if (pHddCtx->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }

    if (pHddCtx->cfg_ini->disablePacketFilter)
    {
        hddLog(VOS_TRACE_LEVEL_ERROR,
                "%s: Packet Filtering Disabled. Returning ",
                __func__ );
        return -EINVAL;
    }

    switch (filterType)
    {
        /* For setting IPV6 MC and UC Filter we need to configure
         * 2 filters, one for MC and one for UC.
         * The Filter ID shouldn't be swapped, which results in making
         * UC Filter ineffective.
         * We have Hardcode all the values
         *
         * Reason for a seperate UC filter is because, driver need to
         * specify the FW that the specific filter is for unicast
         * otherwise FW will not pass the unicast frames by default
         * through the filter. This is required to avoid any performance
         * hits when no unicast filter is set and only MC/BC are set.
         * The way driver informs host is by using the MAC protocol
         * layer, CMP flag set to MAX, CMP Data set to 1.
         */

    case HDD_FILTER_IPV6_MC_UC:
        /* Setting IPV6 MC Filter below
         */
        packetFilterSetReq.filterType = HDD_RCV_FILTER_SET;
        packetFilterSetReq.filterId = HDD_FILTER_ID_IPV6_MC;
        packetFilterSetReq.numFieldParams = 2;
        packetFilterSetReq.paramsData[0].protocolLayer =
                                         HDD_FILTER_PROTO_TYPE_MAC;
        packetFilterSetReq.paramsData[0].cmpFlag =
                                         HDD_FILTER_CMP_TYPE_NOT_EQUAL;
        packetFilterSetReq.paramsData[0].dataOffset =
                                         WLAN_HDD_80211_FRM_DA_OFFSET;
        packetFilterSetReq.paramsData[0].dataLength = 1;
        packetFilterSetReq.paramsData[0].compareData[0] =
                                         HDD_IPV6_MC_CMP_DATA;

        packetFilterSetReq.paramsData[1].protocolLayer =
                                         HDD_FILTER_PROTO_TYPE_ARP;
        packetFilterSetReq.paramsData[1].cmpFlag =
                                         HDD_FILTER_CMP_TYPE_NOT_EQUAL;
        packetFilterSetReq.paramsData[1].dataOffset = ETH_ALEN;
        packetFilterSetReq.paramsData[1].dataLength = 2;
        packetFilterSetReq.paramsData[1].compareData[0] =
                                         HDD_IPV6_CMP_DATA_0;
        packetFilterSetReq.paramsData[1].compareData[1] =
                                         HDD_IPV6_CMP_DATA_1;


        if (eHAL_STATUS_SUCCESS != sme_ReceiveFilterSetFilter(pHddCtx->hHal,
                                    &packetFilterSetReq, sessionId))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: Failure to execute Set IPv6 Mulicast Filter",
                    __func__);
            return -EINVAL;
        }

        memset( &packetFilterSetReq, 0, sizeof(tSirRcvPktFilterCfgType));

        /*
         * Setting IPV6 UC Filter below
         */
        packetFilterSetReq.filterType = HDD_RCV_FILTER_SET;
        packetFilterSetReq.filterId = HDD_FILTER_ID_IPV6_UC;
        packetFilterSetReq.numFieldParams = 2;
        packetFilterSetReq.paramsData[0].protocolLayer =
                                         HDD_FILTER_PROTO_TYPE_MAC;
        packetFilterSetReq.paramsData[0].cmpFlag =
                                         HDD_FILTER_CMP_TYPE_MAX;
        packetFilterSetReq.paramsData[0].dataOffset = 0;
        packetFilterSetReq.paramsData[0].dataLength = 1;
        packetFilterSetReq.paramsData[0].compareData[0] =
                                         HDD_IPV6_UC_CMP_DATA;

        packetFilterSetReq.paramsData[1].protocolLayer =
                                         HDD_FILTER_PROTO_TYPE_ARP;
        packetFilterSetReq.paramsData[1].cmpFlag =
                                         HDD_FILTER_CMP_TYPE_NOT_EQUAL;
        packetFilterSetReq.paramsData[1].dataOffset = ETH_ALEN;
        packetFilterSetReq.paramsData[1].dataLength = 2;
        packetFilterSetReq.paramsData[1].compareData[0] =
                                         HDD_IPV6_CMP_DATA_0;
        packetFilterSetReq.paramsData[1].compareData[1] =
                                         HDD_IPV6_CMP_DATA_1;

        if (eHAL_STATUS_SUCCESS != sme_ReceiveFilterSetFilter(pHddCtx->hHal,
                                    &packetFilterSetReq, sessionId))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: Failure to execute Set IPv6 Unicast Filter",
                    __func__);
            return -EINVAL;
        }

        break;

    case HDD_FILTER_IPV6_MC:
        /*
         * IPV6 UC Filter might be already set,
         * clear the UC Filter. As the Filter
         * IDs are static, we can directly clear it.
         */
        packetFilterSetReq.filterType = HDD_RCV_FILTER_SET;
        packetFilterClrReq.filterId = HDD_FILTER_ID_IPV6_UC;
        if (eHAL_STATUS_SUCCESS != sme_ReceiveFilterClearFilter(pHddCtx->hHal,
                                    &packetFilterClrReq, sessionId))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: Failure to execute Clear IPv6 Unicast Filter",
                    __func__);
            return -EINVAL;
        }

        /*
         * Setting IPV6 MC Filter below
         */
        packetFilterSetReq.filterId = HDD_FILTER_ID_IPV6_MC;
        packetFilterSetReq.numFieldParams = 2;
        packetFilterSetReq.paramsData[0].protocolLayer =
                                         HDD_FILTER_PROTO_TYPE_MAC;
        packetFilterSetReq.paramsData[0].cmpFlag =
                                         HDD_FILTER_CMP_TYPE_NOT_EQUAL;
        packetFilterSetReq.paramsData[0].dataOffset =
                                         WLAN_HDD_80211_FRM_DA_OFFSET;
        packetFilterSetReq.paramsData[0].dataLength = 1;
        packetFilterSetReq.paramsData[0].compareData[0] =
                                         HDD_IPV6_MC_CMP_DATA;

        packetFilterSetReq.paramsData[1].protocolLayer =
                                         HDD_FILTER_PROTO_TYPE_ARP;
        packetFilterSetReq.paramsData[1].cmpFlag =
                                         HDD_FILTER_CMP_TYPE_NOT_EQUAL;
        packetFilterSetReq.paramsData[1].dataOffset = ETH_ALEN;
        packetFilterSetReq.paramsData[1].dataLength = 2;
        packetFilterSetReq.paramsData[1].compareData[0] =
                                         HDD_IPV6_CMP_DATA_0;
        packetFilterSetReq.paramsData[1].compareData[1] =
                                         HDD_IPV6_CMP_DATA_1;


        if (eHAL_STATUS_SUCCESS != sme_ReceiveFilterSetFilter(pHddCtx->hHal,
                                    &packetFilterSetReq, sessionId))
        {
            hddLog(VOS_TRACE_LEVEL_ERROR,
                    "%s: Failure to execute Set IPv6 Multicast Filter",
                    __func__);
            return -EINVAL;
        }
        break;

    default :
        hddLog(VOS_TRACE_LEVEL_INFO_HIGH,
                "%s: Packet Filter Request: Invalid",
                __func__);
        return -EINVAL;
    }
    return 0;
}
// IKJB42MAIN-1244, Motorola, a19091 - BEGIN
#define SET_FILTER_BMAP(filter_map, set, index) { if(set){(filter_map)|=(1<<(index));}\
    else {(filter_map)&=(~(1<<(index)));}}

#define IS_FILTER_INDEX_FREE(filter_map, index) (((filter_map)&(1<<(index)))==0)

#define IPV6_CONFIG_ALLOW_ALL 1
#define IPV6_CONFIG_MANDATORY 0

void wlan_hdd_set_mc_v6(hdd_adapter_t *pAdapter, v_U8_t set) {
    tPacketFilterCfg request = {0};
    v_SCHAR_t mcFilterIndex = WLAN_HDD_MAX_MC_ADDR_LIST;
    int ret;
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

    if(set) {
        if(pAdapter->filter_v6_index != -1) {
            hddLog(VOS_TRACE_LEVEL_INFO, "IPV6 pass through already set, skipping");
            return;
        }
        /* Add v6 pass through rule */
        if(pAdapter->mc_addr_list.isFilterApplied)
            wlan_hdd_set_mc_addr_list(pAdapter, FALSE);
        /* Find a suitable slot and stick in filter */
        while(--mcFilterIndex >=0 ) {
            if(IS_FILTER_INDEX_FREE(pAdapter->user_filter_config, mcFilterIndex)) {
                request.filterAction = HDD_RCV_FILTER_SET;
                request.filterId = mcFilterIndex;
                request.numParams = 1;
                request.paramsData[0].protocolLayer = HDD_FILTER_PROTO_TYPE_MAC;
                request.paramsData[0].dataOffset = WLAN_HDD_80211_FRM_DA_OFFSET;
                request.paramsData[0].dataLength = 2;
                request.paramsData[0].compareData[0]=0x33;
                request.paramsData[0].compareData[1]=0x33;
                ret = wlan_hdd_set_filter(pHddCtx, &request, pAdapter->sessionId);
                if(ret == 0) {
                    pAdapter->filter_v6_index = mcFilterIndex;
                    SET_FILTER_BMAP(pAdapter->driver_filter_config, set, request.filterId);
                    hddLog(VOS_TRACE_LEVEL_INFO, "Programmed IPV6 pass through at index %d",
                            mcFilterIndex);
                    break;
                } else {
                    hddLog(VOS_TRACE_LEVEL_ERROR,
                            "Failed programming IPV6 pass through at index %d - TRY NEXT",
                            mcFilterIndex);
                }
            }
        }
        if(mcFilterIndex<0)
            hddLog(VOS_TRACE_LEVEL_ERROR, "IPV6 pass through rule prog failed!!");
    } else if(pAdapter->filter_v6_index != -1) {
        /* Remove pass through rule */
        request.filterAction = HDD_RCV_FILTER_CLEAR;
        request.filterId = pAdapter->filter_v6_index;
        request.numParams = 1;
        ret = wlan_hdd_set_filter(pHddCtx, &request, pAdapter->sessionId);
        if(ret == 0) {
            pAdapter->filter_v6_index = -1;
            SET_FILTER_BMAP(pAdapter->driver_filter_config, set, request.filterId);
            hddLog(VOS_TRACE_LEVEL_INFO, "Cleared IPV6 pass through at index %d",
                    request.filterId);
        } else {
             hddLog(VOS_TRACE_LEVEL_ERROR, "IPV6 pass through rule CLEAR failed!!");
        }
    } else {
        hddLog(VOS_TRACE_LEVEL_INFO, "Clear IPV6 passthrough when not set - ignore");
    }
}
// IKJB42MAIN-1244, Motorola, a19091 -- END

void wlan_hdd_set_mc_addr_list(hdd_adapter_t *pAdapter, v_U8_t set)
{
    v_U8_t filterAction;
    tPacketFilterCfg request;
    v_U8_t i;
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    // IKJB42MAIN-1244, Motorola, a19091 - BEGIN
    int ret;
    v_SCHAR_t mcFilterIndex = WLAN_HDD_MAX_MC_ADDR_LIST;
    // IKJB42MAIN-1244, Motorola, a19091 - END

    filterAction = set ? HDD_RCV_FILTER_SET : HDD_RCV_FILTER_CLEAR;

    // IKJB42MAIN-1244, Motorola, a19091 - BEGIN
    hddLog(VOS_TRACE_LEVEL_INFO, "%s: Entered for %s",
            __func__, set?"SET":"CLEAR");

    if(pAdapter->filter_v6_index != -1) {
        hddLog(VOS_TRACE_LEVEL_INFO, "%s: First calling CLEAR V6 ALLOW_ALL!",
                __func__);
        wlan_hdd_set_mc_v6(pAdapter, FALSE);
    }
    // IKJB42MAIN-1244, Motorola, a19091 - END

    /*set mulitcast addr list*/
    for (i = 0; i < pAdapter->mc_addr_list.mc_cnt; i++)
    {
        memset(&request, 0, sizeof (tPacketFilterCfg));
        request.filterAction = filterAction;
        if (set)
        {
            // IKJB42MAIN-1244, Motorola, a19091 - BEGIN
            while(--mcFilterIndex >=0 ) {
                if(IS_FILTER_INDEX_FREE(pAdapter->user_filter_config, mcFilterIndex)) {
                    /* Non user filter index! */
                    if(!IS_FILTER_INDEX_FREE(pAdapter->driver_filter_config, mcFilterIndex)) {
                        hddLog(VOS_TRACE_LEVEL_INFO, "Clearing Filter index %d, before reprog",
                            mcFilterIndex);
                        request.filterAction = HDD_RCV_FILTER_CLEAR;
                        request.filterId = mcFilterIndex;
                        ret = wlan_hdd_set_filter(pHddCtx, &request, pAdapter->sessionId);
                        if(ret == 0) {
                            SET_FILTER_BMAP(pAdapter->driver_filter_config, FALSE, request.filterId);
                        } else {
                            hddLog(VOS_TRACE_LEVEL_ERROR,"failed to clear filter index %d",mcFilterIndex);
                        }
                    }
                    if(!IS_FILTER_INDEX_FREE(pAdapter->driver_filter_config, mcFilterIndex)) {
                        hddLog(VOS_TRACE_LEVEL_ERROR, "Failed to clear filter %d - try next",
                            mcFilterIndex);
                        continue;
                    }
                    request.filterAction = HDD_RCV_FILTER_SET;
                    request.filterId = mcFilterIndex;
                    request.numParams = 1;
                    request.paramsData[0].protocolLayer = HDD_FILTER_PROTO_TYPE_MAC;
                    request.paramsData[0].cmpFlag = HDD_FILTER_CMP_TYPE_EQUAL;
                    request.paramsData[0].dataOffset = WLAN_HDD_80211_FRM_DA_OFFSET;
                    request.paramsData[0].dataLength = ETH_ALEN;
                    memcpy(&(request.paramsData[0].compareData[0]),
                        &(pAdapter->mc_addr_list.addr[i][0]), ETH_ALEN);
                    /*set mulitcast filters*/
                    hddLog(VOS_TRACE_LEVEL_INFO,
                        "%s: %s multicast filter: addr ="
                        "%02x:%02x:%02x:%02x:%02x:%02x",
                        __func__, set ? "setting" : "clearing",
                        request.paramsData[0].compareData[0],
                        request.paramsData[0].compareData[1],
                        request.paramsData[0].compareData[2],
                        request.paramsData[0].compareData[3],
                        request.paramsData[0].compareData[4], 
                        request.paramsData[0].compareData[5]);
                    pAdapter->mc_addr_list.filter_index[i] = request.filterId;
                    break;
                } else {
                    /*user filter index - try next*/
                    hddLog(VOS_TRACE_LEVEL_ERROR,
                        "Index %d used by user filter - try next", mcFilterIndex);
                }
            }
            if(mcFilterIndex < 0 ) {
                /*No Free index in driver config available*/
                hddLog(VOS_TRACE_LEVEL_FATAL,
                        "No available slots to allow mcast filter - Too many user filters");
                return;
            }
        } else { /* !set */
            if(pAdapter->mc_addr_list.isFilterApplied == FALSE) {
                hddLog(VOS_TRACE_LEVEL_INFO, "No previous filter ... skipping");
                continue;
            }
            hddLog(VOS_TRACE_LEVEL_INFO, "Gonna clear index %d",
                    pAdapter->mc_addr_list.filter_index[i]);
            request.filterId = pAdapter->mc_addr_list.filter_index[i];
            request.numParams = 1;
        }
        ret = wlan_hdd_set_filter(pHddCtx, &request, pAdapter->sessionId);
        if(ret == 0) {
            SET_FILTER_BMAP(pAdapter->driver_filter_config, set, request.filterId);
        }
    }

    if(set) {
        // Clear out any extraneous driver filters
        request.filterAction = HDD_RCV_FILTER_CLEAR;
        while(--mcFilterIndex>=0) {
            request.filterId = mcFilterIndex;
            if(!IS_FILTER_INDEX_FREE(pAdapter->driver_filter_config, mcFilterIndex) &&
                    IS_FILTER_INDEX_FREE(pAdapter->user_filter_config, mcFilterIndex)) {
                hddLog(VOS_TRACE_LEVEL_INFO, "Clearing Filter index %d,", mcFilterIndex);
                ret = wlan_hdd_set_filter(pHddCtx, &request, pAdapter->sessionId);
                if(ret == 0) {
                    SET_FILTER_BMAP(pAdapter->driver_filter_config, FALSE, request.filterId);
                } else {
                    hddLog(VOS_TRACE_LEVEL_ERROR,"failed to clear filter index %d",mcFilterIndex);
                }
            }
        }
        // IKJB42MAIN-1244, Motorola, a19091 - END
    }
    pAdapter->mc_addr_list.isFilterApplied = set ? TRUE : FALSE;
}

// IKJB42MAIN-1244, Motorola, a19091 - BEGIN
int wlan_hdd_update_v6_filters(hdd_adapter_t *pAdapter, v_U8_t set){
    tSirInvokeV6Filter filterConfig;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

    if(!hdd_connIsConnected(pHddStaCtx))
    {
        hddLog(VOS_TRACE_LEVEL_WARN,
                "Not associated - ignoring wlan_hdd_update_v6_filters");
        return 0;
    }
    filterConfig.configureFilterFn = wlan_hdd_set_v6_filter;
    filterConfig.pHddAdapter = pAdapter;
    filterConfig.set = set;

    if (eHAL_STATUS_SUCCESS != sme_ReceiveSetMcFilter(&filterConfig))
    {
        hddLog(VOS_TRACE_LEVEL_ERROR, "%s: Failure to execute Set Filter\n",
            __func__);
        return -1;
    }
    return 0;
}

int wlan_hdd_set_v6_filter(void *pAdapter, v_U8_t set, v_U8_t userSet) {
    hdd_adapter_t* pTAdapter = (hdd_adapter_t*)pAdapter;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pTAdapter);
    int ret = 0;

    if(userSet)
        pTAdapter->ipv6_user_set_map = (set)?IPV6_CONFIG_ALLOW_ALL:IPV6_CONFIG_MANDATORY;
    else
        pTAdapter->ipv6_code_set_map = (set)?IPV6_CONFIG_ALLOW_ALL:IPV6_CONFIG_MANDATORY;

    hddLog(VOS_TRACE_LEVEL_INFO, "wlan_hdd_set_v6_filter - %s - set map is now - code = %s, user = %s",
        userSet?"USER-SET":"CODE-SET",
        (pTAdapter->ipv6_code_set_map == IPV6_CONFIG_MANDATORY) ? "MANDATORY":"ALLOW_ALL",
        (pTAdapter->ipv6_user_set_map == IPV6_CONFIG_MANDATORY) ? "MANDATORY":"ALLOW_ALL");

    if(!hdd_connIsConnected(pHddStaCtx))
    {
        hddLog(VOS_TRACE_LEVEL_WARN,
                 "Not associated - ignoring wlan_hdd_set_v6_filter");
        return ret;
    }
    if(pTAdapter->ipv6_code_set_map == pTAdapter->ipv6_user_set_map  &&
            pTAdapter->ipv6_code_set_map == IPV6_CONFIG_MANDATORY ) {
        hddLog(VOS_TRACE_LEVEL_INFO, "Set IPV6 filter to MANDATORY");
        wlan_hdd_set_mc_v6(pAdapter, FALSE);
        wlan_hdd_set_mc_addr_list(pTAdapter, TRUE);
    } else {
        hddLog(VOS_TRACE_LEVEL_INFO, "Set IPV6 filter to ALLOW_ALL");
        if(pTAdapter->filter_v6_index == -1) {
            hddLog(VOS_TRACE_LEVEL_INFO, "Program V6!");
            wlan_hdd_set_mc_addr_list(pTAdapter, FALSE);
            wlan_hdd_set_mc_v6(pTAdapter, TRUE);
        } else {
            hddLog(VOS_TRACE_LEVEL_INFO, "Skip program V6 - already set!");
        }
    }
    return ret;
}
// IKJB42MAIN-1244, Motorola, a19091 - END
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

static int iw_set_packet_filter_params(struct net_device *dev, struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra)
{   
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
<<<<<<< HEAD
<<<<<<< HEAD
    tpPacketFilterCfg pRequest = (tpPacketFilterCfg)wrqu->data.pointer;
    return wlan_hdd_set_filter(WLAN_HDD_GET_CTX(pAdapter), pRequest, pAdapter->sessionId);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    // IKJB42MAIN-1244, Motorola, a19091 - BEGIN
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    int retVal;
    v_U8_t mcFilterReset = FALSE;
    // IKJB42MAIN-1244, Motorola, a19091 - END

    //IKHSS7-35965, a19091, Motorola changes -- BEGIN
    tpPacketFilterCfg pRequest = (tpPacketFilterCfg)kmalloc(sizeof(tPacketFilterCfg), GFP_KERNEL);

    if(pRequest == NULL) {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s: Out of memory - cant alloc %d bytes",
                sizeof(tpPacketFilterCfg),__FUNCTION__);
        return -ENOMEM;
    }

    if(copy_from_user(pRequest, wrqu->data.pointer, sizeof(tPacketFilterCfg))) {
        hddLog(VOS_TRACE_LEVEL_FATAL, "%s -- copy_from_user -- data pointer failed! bailing",
                __FUNCTION__);
        kfree(pRequest);
        return -EFAULT;
    }
    //IKHSS7-35965, a19091, Motorola changes -- END

    // IKJB42MAIN-1244, Motorola, a19091 - BEGIN
    if(!IS_FILTER_INDEX_FREE(pAdapter->driver_filter_config, pRequest->filterId) &&
            IS_FILTER_INDEX_FREE(pAdapter->user_filter_config, pRequest->filterId)) {
        // Need to re-adjust MC filter - disable and re-enable
        hddLog(VOS_TRACE_LEVEL_INFO, "%s, Filter ID %d already in use - disable and re-enable mc filters!!",
                __FUNCTION__, pRequest->filterId);
        wlan_hdd_set_mc_addr_list(pAdapter, FALSE);
        mcFilterReset = TRUE;
    }
    // IKJB42MAIN-1244, Motorola, a19091 - END

    retVal = wlan_hdd_set_filter(pHddCtx, pRequest, pAdapter->sessionId);

    // IKJB42MAIN-1244, Motorola, a19091 - BEGIN
    if(retVal == 0) {
        SET_FILTER_BMAP(pAdapter->driver_filter_config, (pRequest->filterAction), pRequest->filterId);
        SET_FILTER_BMAP(pAdapter->user_filter_config, (pRequest->filterAction), pRequest->filterId);
    }

    if(mcFilterReset) {
        hddLog(VOS_TRACE_LEVEL_INFO, "%s, Re -enabling MC filters",
                __FUNCTION__);
        wlan_hdd_set_mc_addr_list(pAdapter, TRUE);
    }

    if(pRequest!= NULL)
        kfree(pRequest);

    return retVal;
    // IKJB42MAIN-1244, Motorola, a19091 - END
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
}
#endif
static int iw_get_statistics(struct net_device *dev,
                           struct iw_request_info *info,
                           union iwreq_data *wrqu, char *extra)
{

  VOS_STATUS vos_status = VOS_STATUS_SUCCESS;
  eHalStatus status = eHAL_STATUS_SUCCESS;
  hdd_wext_state_t *pWextState;
  hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
  hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
  char *p = extra;
  int tlen = 0;
  tCsrSummaryStatsInfo *pStats = &(pAdapter->hdd_stats.summary_stat);

  tCsrGlobalClassAStatsInfo *aStats = &(pAdapter->hdd_stats.ClassA_stat);
  tCsrGlobalClassDStatsInfo *dStats = &(pAdapter->hdd_stats.ClassD_stat);

  ENTER();

  if (pHddCtx->isLogpInProgress) {
     VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL, "%s:LOGP in Progress. Ignore!!!",__func__);
     return -EINVAL;
  }

  if (eConnectionState_Associated != (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.connState) {

     wrqu->txpower.value = 0;
  }
  else {
    status = sme_GetStatistics( pHddCtx->hHal, eCSR_HDD,
                       SME_SUMMARY_STATS      |
                       SME_GLOBAL_CLASSA_STATS |
                       SME_GLOBAL_CLASSB_STATS |
                       SME_GLOBAL_CLASSC_STATS |
                       SME_GLOBAL_CLASSD_STATS |
                       SME_PER_STA_STATS,
                       hdd_StatisticsCB, 0, FALSE,
                       (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.staId[0], pAdapter );

    if (eHAL_STATUS_SUCCESS != status)
    {
       hddLog(VOS_TRACE_LEVEL_ERROR,
              "%s: Unable to retrieve SME statistics",
<<<<<<< HEAD
<<<<<<< HEAD
              __FUNCTION__);
=======
              __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
              __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return -EINVAL;
    }

    pWextState = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);

    vos_status = vos_wait_single_event(&pWextState->vosevent, WLAN_WAIT_TIME_STATS);
    if (!VOS_IS_STATUS_SUCCESS(vos_status))
    {
       hddLog(VOS_TRACE_LEVEL_ERROR,
              "%s: SME timeout while retrieving statistics",
<<<<<<< HEAD
<<<<<<< HEAD
              __FUNCTION__);
=======
              __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
              __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
       /*Remove the SME statistics list by passing NULL in callback argument*/
       status = sme_GetStatistics( pHddCtx->hHal, eCSR_HDD,
                       SME_SUMMARY_STATS      |
                       SME_GLOBAL_CLASSA_STATS |
                       SME_GLOBAL_CLASSB_STATS |
                       SME_GLOBAL_CLASSC_STATS |
                       SME_GLOBAL_CLASSD_STATS |
                       SME_PER_STA_STATS,
                       NULL, 0, FALSE,
                       (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.staId[0], pAdapter );

       return -EINVAL;
    }
    FILL_TLV(p, (tANI_U8)WLAN_STATS_RETRY_CNT,
              (tANI_U8) sizeof (pStats->retry_cnt),
              (char*) &(pStats->retry_cnt[0]),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_MUL_RETRY_CNT,
              (tANI_U8) sizeof (pStats->multiple_retry_cnt),
              (char*) &(pStats->multiple_retry_cnt[0]),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_TX_FRM_CNT,
              (tANI_U8) sizeof (pStats->tx_frm_cnt),
              (char*) &(pStats->tx_frm_cnt[0]),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_RX_FRM_CNT,
              (tANI_U8) sizeof (pStats->rx_frm_cnt),
              (char*) &(pStats->rx_frm_cnt),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_FRM_DUP_CNT,
              (tANI_U8) sizeof (pStats->frm_dup_cnt),
              (char*) &(pStats->frm_dup_cnt),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_FAIL_CNT,
              (tANI_U8) sizeof (pStats->fail_cnt),
              (char*) &(pStats->fail_cnt[0]),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_RTS_FAIL_CNT,
              (tANI_U8) sizeof (pStats->rts_fail_cnt),
              (char*) &(pStats->rts_fail_cnt),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_ACK_FAIL_CNT,
              (tANI_U8) sizeof (pStats->ack_fail_cnt),
              (char*) &(pStats->ack_fail_cnt),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_RTS_SUC_CNT,
              (tANI_U8) sizeof (pStats->rts_succ_cnt),
              (char*) &(pStats->rts_succ_cnt),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_RX_DISCARD_CNT,
              (tANI_U8) sizeof (pStats->rx_discard_cnt),
              (char*) &(pStats->rx_discard_cnt),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_RX_ERROR_CNT,
              (tANI_U8) sizeof (pStats->rx_error_cnt),
              (char*) &(pStats->rx_error_cnt),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_TX_BYTE_CNT, 
              (tANI_U8) sizeof (dStats->tx_uc_byte_cnt[0]),
              (char*) &(dStats->tx_uc_byte_cnt[0]), 
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_RX_BYTE_CNT,
              (tANI_U8) sizeof (dStats->rx_byte_cnt),
              (char*) &(dStats->rx_byte_cnt),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_RX_RATE,
              (tANI_U8) sizeof (dStats->rx_rate),
              (char*) &(dStats->rx_rate),
              tlen);

    /* Transmit rate, in units of 500 kbit/sec */
    FILL_TLV(p, (tANI_U8)WLAN_STATS_TX_RATE,
              (tANI_U8) sizeof (aStats->tx_rate),
              (char*) &(aStats->tx_rate),
              tlen);

    FILL_TLV(p, (tANI_U8)WLAN_STATS_RX_UC_BYTE_CNT, 
              (tANI_U8) sizeof (dStats->rx_uc_byte_cnt[0]), 
              (char*) &(dStats->rx_uc_byte_cnt[0]), 
              tlen);
    FILL_TLV(p, (tANI_U8)WLAN_STATS_RX_MC_BYTE_CNT, 
              (tANI_U8) sizeof (dStats->rx_mc_byte_cnt), 
              (char*) &(dStats->rx_mc_byte_cnt), 
              tlen);
    FILL_TLV(p, (tANI_U8)WLAN_STATS_RX_BC_BYTE_CNT, 
              (tANI_U8) sizeof (dStats->rx_bc_byte_cnt), 
              (char*) &(dStats->rx_bc_byte_cnt), 
              tlen);
    FILL_TLV(p, (tANI_U8)WLAN_STATS_TX_UC_BYTE_CNT, 
              (tANI_U8) sizeof (dStats->tx_uc_byte_cnt[0]), 
              (char*) &(dStats->tx_uc_byte_cnt[0]), 
              tlen);
    FILL_TLV(p, (tANI_U8)WLAN_STATS_TX_MC_BYTE_CNT, 
              (tANI_U8) sizeof (dStats->tx_mc_byte_cnt), 
              (char*) &(dStats->tx_mc_byte_cnt), 
              tlen);
    FILL_TLV(p, (tANI_U8)WLAN_STATS_TX_BC_BYTE_CNT, 
              (tANI_U8) sizeof (dStats->tx_bc_byte_cnt), 
              (char*) &(dStats->tx_bc_byte_cnt), 
              tlen);

    wrqu->data.length = tlen;

  }

  EXIT();

  return 0;
}


#ifdef FEATURE_WLAN_SCAN_PNO

/*Max Len for PNO notification*/
#define MAX_PNO_NOTIFY_LEN 100
void found_pref_network_cb (void *callbackContext,
                              tSirPrefNetworkFoundInd *pPrefNetworkFoundInd)
{
  hdd_adapter_t* pAdapter = (hdd_adapter_t*)callbackContext;
  union iwreq_data wrqu;
  char buf[MAX_PNO_NOTIFY_LEN+1];
<<<<<<< HEAD
<<<<<<< HEAD

=======
  int bp = 0;
  
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
  int bp = 0;
  
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
  hddLog(VOS_TRACE_LEVEL_WARN, "A preferred network was found: %s with rssi: -%d",
         pPrefNetworkFoundInd->ssId.ssId, pPrefNetworkFoundInd->rssi);

  // create the event
  memset(&wrqu, 0, sizeof(wrqu));
  memset(buf, 0, sizeof(buf));

<<<<<<< HEAD
<<<<<<< HEAD
  snprintf(buf, MAX_PNO_NOTIFY_LEN, "QCOM: Found preferred network: %s with RSSI of -%u",
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
  // stop PNO
  bp = strlcpy(buf, "0 ", sizeof(buf));
  buf[bp++] = '\0';
  wrqu.data.pointer = buf;
  wrqu.data.length = strlen(buf);
  iw_set_pno(pAdapter->dev, NULL, &wrqu, NULL, 0);
  //printk("PNO Callback: Stopping PNO \n");

  // send event to supplicant
  memset(&wrqu, 0, sizeof(wrqu));
  memset(buf, 0, sizeof(buf));
  snprintf(buf, MAX_PNO_NOTIFY_LEN, "PNOFOUND : Found preferred network: %s with RSSI of -%u",
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
           pPrefNetworkFoundInd->ssId.ssId,
          (unsigned int)pPrefNetworkFoundInd->rssi);

  wrqu.data.pointer = buf;
  wrqu.data.length = strlen(buf);

  // send the event

  wireless_send_event(pAdapter->dev, IWEVCUSTOM, &wrqu, buf);

}


/*string based input*/
VOS_STATUS iw_set_pno(struct net_device *dev, struct iw_request_info *info,
                      union iwreq_data *wrqu, char *extra, int nOffset)
{
  hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
  /* pnoRequest is a large struct, so we make it static to avoid stack
     overflow.  This API is only invoked via ioctl, so it is
     serialized by the kernel rtnl_lock and hence does not need to be
     reentrant */
  static tSirPNOScanReq pnoRequest;
  char *ptr;
  v_U8_t i,j, ucParams, ucMode;
  /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
            "PNO data len %d data %s",
            wrqu->data.length,
<<<<<<< HEAD
<<<<<<< HEAD
            wrqu->data.pointer);
=======
            (char *)wrqu->data.pointer);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
            (char *)wrqu->data.pointer);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

  if (wrqu->data.length <= nOffset )
  {
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN, "PNO input is not correct");
    return VOS_STATUS_E_FAILURE;
  }

  pnoRequest.enable = 0;
  pnoRequest.ucNetworksCount = 0;
  /*-----------------------------------------------------------------------
    Input is string based and expected to be like this:

    <enabled> <netw_count>
    for each network:
    <ssid_len> <ssid> <authentication> <encryption>
    <ch_num> <channel_list optional> <bcast_type> <rssi_threshold>
    <scan_timers> <scan_time> <scan_repeat> <scan_time> <scan_repeat>

    e.g:
<<<<<<< HEAD
<<<<<<< HEAD
    1 2 4 test 0 0 3 1 6 11 2 40 5 test2 4 4 6 1 2 3 4 5 6 1 0 2 5 2 300 0 
=======
    1 2 4 test 0 0 3 1 6 11 2 40 5 test2 4 4 6 1 2 3 4 5 6 1 0 2 5 2 300 0
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    1 2 4 test 0 0 3 1 6 11 2 40 5 test2 4 4 6 1 2 3 4 5 6 1 0 2 5 2 300 0
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    this translates into:
    -----------------------------
    enable PNO
    look for 2 networks:
    test - with authentication type 0 and encryption type 0,
    that can be found on 3 channels: 1 6 and 11 ,
    SSID bcast type is unknown (directed probe will be sent if AP not found)
    and must meet -40dBm RSSI

    test2 - with auth and enrytption type 4/4
    that can be found on 6 channels 1, 2, 3, 4, 5 and 6
    bcast type is non-bcast (directed probe will be sent)
    and must not meet any RSSI threshold

<<<<<<< HEAD
<<<<<<< HEAD
    scan every 5 seconds 2 times, scan every 300 seconds until stopped 
=======
    scan every 5 seconds 2 times, scan every 300 seconds until stopped
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    scan every 5 seconds 2 times, scan every 300 seconds until stopped
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
  -----------------------------------------------------------------------*/
  ptr = (char*)(wrqu->data.pointer + nOffset);

  sscanf(ptr,"%hhu%n", &(pnoRequest.enable), &nOffset);

  if ( 0 == pnoRequest.enable )
  {
    /*Disable PNO*/
    memset(&pnoRequest, 0, sizeof(pnoRequest));
    sme_SetPreferredNetworkList(WLAN_HDD_GET_HAL_CTX(pAdapter), &pnoRequest,
                                pAdapter->sessionId,
                                found_pref_network_cb, pAdapter);
    return VOS_STATUS_SUCCESS;
  }

  ptr += nOffset;
  sscanf(ptr,"%hhu %n", &(pnoRequest.ucNetworksCount), &nOffset);

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
            "PNO enable %d networks count %d offset %d",
            pnoRequest.enable,
            pnoRequest.ucNetworksCount,
            nOffset);

  /* Parameters checking:
      ucNetworksCount has to be larger than 0*/
  if (( 0 == pnoRequest.ucNetworksCount ) ||
      ( pnoRequest.ucNetworksCount > SIR_PNO_MAX_SUPP_NETWORKS ))
  {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN, "Network input is not correct");
      return VOS_STATUS_E_FAILURE;
  }

  ptr += nOffset;

  for ( i = 0; i < pnoRequest.ucNetworksCount; i++ )
  {

    pnoRequest.aNetworks[i].ssId.length = 0;

    sscanf(ptr,"%hhu %n",
           &(pnoRequest.aNetworks[i].ssId.length), &nOffset);

    if (( 0 == pnoRequest.aNetworks[i].ssId.length ) ||
        ( pnoRequest.aNetworks[i].ssId.length > 32 ) )
    {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
                "SSID Len %d is not correct for network %d",
                pnoRequest.aNetworks[i].ssId.length, i);
      return VOS_STATUS_E_FAILURE;
    }

    /*Advance to SSID*/
    ptr += nOffset;

<<<<<<< HEAD
<<<<<<< HEAD
    ucParams = sscanf(ptr,"%32s %lu %lu %hhu %n",
           pnoRequest.aNetworks[i].ssId.ssId,
           &(pnoRequest.aNetworks[i].authentication),
           &(pnoRequest.aNetworks[i].encryption),
           &(pnoRequest.aNetworks[i].ucChannelCount),
           &nOffset);

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
            "PNO len %d ssid %s auth %d encry %d channel count %d offset %d",
            pnoRequest.aNetworks[i].ssId.length,
            pnoRequest.aNetworks[i].ssId.ssId,
            pnoRequest.aNetworks[i].authentication,
            pnoRequest.aNetworks[i].encryption,
            pnoRequest.aNetworks[i].ucChannelCount,
            nOffset );

    if ( 4 != ucParams )
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    memcpy(pnoRequest.aNetworks[i].ssId.ssId, ptr,
           pnoRequest.aNetworks[i].ssId.length);
    ptr += pnoRequest.aNetworks[i].ssId.length;

    ucParams = sscanf(ptr,"%lu %lu %hhu %n",
                      &(pnoRequest.aNetworks[i].authentication),
                      &(pnoRequest.aNetworks[i].encryption),
                      &(pnoRequest.aNetworks[i].ucChannelCount),
                      &nOffset);

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
              "PNO len %d ssid 0x%08lx%08lx%08lx%08lx%08lx%08lx%08lx%08lx"
              "auth %d encry %d channel count %d offset %d",
              pnoRequest.aNetworks[i].ssId.length,
              *((v_U32_t *) &pnoRequest.aNetworks[i].ssId.ssId[0]),
              *((v_U32_t *) &pnoRequest.aNetworks[i].ssId.ssId[4]),
              *((v_U32_t *) &pnoRequest.aNetworks[i].ssId.ssId[8]),
              *((v_U32_t *) &pnoRequest.aNetworks[i].ssId.ssId[12]),
              *((v_U32_t *) &pnoRequest.aNetworks[i].ssId.ssId[16]),
              *((v_U32_t *) &pnoRequest.aNetworks[i].ssId.ssId[20]),
              *((v_U32_t *) &pnoRequest.aNetworks[i].ssId.ssId[24]),
              *((v_U32_t *) &pnoRequest.aNetworks[i].ssId.ssId[28]),
              pnoRequest.aNetworks[i].authentication,
              pnoRequest.aNetworks[i].encryption,
              pnoRequest.aNetworks[i].ucChannelCount,
              nOffset );

    if ( 3 != ucParams )
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                "Incorrect cmd");
      return VOS_STATUS_E_FAILURE;
    }

    /*Advance to channel list*/
    ptr += nOffset;

    if ( SIR_PNO_MAX_NETW_CHANNELS < pnoRequest.aNetworks[i].ucChannelCount )
    {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                "Incorrect number of channels");
      return VOS_STATUS_E_FAILURE;
    }

    if ( 0 !=  pnoRequest.aNetworks[i].ucChannelCount)
    {
      for ( j = 0; j < pnoRequest.aNetworks[i].ucChannelCount; j++)
      {
        sscanf(ptr,"%hhu %n",
              &(pnoRequest.aNetworks[i].aChannels[j]), &nOffset);
        /*Advance to next channel number*/
        ptr += nOffset;
      }
    }

    sscanf(ptr,"%lu %n",
              &(pnoRequest.aNetworks[i].bcastNetwType), &nOffset);

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
            "PNO bcastNetwType %d offset %d",
            pnoRequest.aNetworks[i].bcastNetwType,
            nOffset );

    /*Advance to rssi Threshold*/
    ptr += nOffset;

    sscanf(ptr,"%hhu %n",
              &(pnoRequest.aNetworks[i].rssiThreshold), &nOffset);

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
            "PNO rssi %d offset %d",
            pnoRequest.aNetworks[i].rssiThreshold,
            nOffset );
    /*Advance to next network*/
    ptr += nOffset;
  }/*For ucNetworkCount*/

  ucParams = sscanf(ptr,"%hhu %n",
              &(pnoRequest.scanTimers.ucScanTimersCount), &nOffset);

  /*Read the scan timers*/
<<<<<<< HEAD
<<<<<<< HEAD
  if (( 1 == ucParams )&&(  pnoRequest.scanTimers.ucScanTimersCount >= 0 ))
  {
     ptr += nOffset;

     VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, 
        "Scan timer count %d offset %d", 
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
  if (( 1 == ucParams ) && ( pnoRequest.scanTimers.ucScanTimersCount > 0 ))
  {
     ptr += nOffset;

     VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
        "Scan timer count %d offset %d",
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        pnoRequest.scanTimers.ucScanTimersCount,
        nOffset );

     if ( SIR_PNO_MAX_SCAN_TIMERS < pnoRequest.scanTimers.ucScanTimersCount )
     {
<<<<<<< HEAD
<<<<<<< HEAD
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR, 
=======
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                    "Incorrect cmd - too many scan timers");
       return VOS_STATUS_E_FAILURE;
     }

     for ( i = 0; i < pnoRequest.scanTimers.ucScanTimersCount; i++ )
     {
        ucParams = sscanf(ptr,"%lu %lu %n",
           &(pnoRequest.scanTimers.aTimerValues[i].uTimerValue),
           &( pnoRequest.scanTimers.aTimerValues[i].uTimerRepeat),
           &nOffset);

<<<<<<< HEAD
<<<<<<< HEAD
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, 
            "PNO Timer value %d Timer repeat %d offset %d", 
            pnoRequest.scanTimers.aTimerValues[i].uTimerValue, 
=======
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
            "PNO Timer value %d Timer repeat %d offset %d",
            pnoRequest.scanTimers.aTimerValues[i].uTimerValue,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
            "PNO Timer value %d Timer repeat %d offset %d",
            pnoRequest.scanTimers.aTimerValues[i].uTimerValue,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            pnoRequest.scanTimers.aTimerValues[i].uTimerRepeat,
            nOffset );

        if ( 2 != ucParams )
        {
<<<<<<< HEAD
<<<<<<< HEAD
          VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR, 
=======
          VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
          VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                    "Incorrect cmd - diff params then expected %d", ucParams);
          return VOS_STATUS_E_FAILURE;
        }

        ptr += nOffset;
     }

  }
  else
  {
<<<<<<< HEAD
<<<<<<< HEAD
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, 
       "No scan timers provided param count %d scan timers %d", 
=======
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
       "No scan timers provided param count %d scan timers %d",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
       "No scan timers provided param count %d scan timers %d",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        ucParams,  pnoRequest.scanTimers.ucScanTimersCount );

    /*Scan timers defaults to 5 minutes*/
    pnoRequest.scanTimers.ucScanTimersCount = 1;
    pnoRequest.scanTimers.aTimerValues[0].uTimerValue  = 60;
    pnoRequest.scanTimers.aTimerValues[0].uTimerRepeat = 0;
  }

  ucParams = sscanf(ptr,"%hhu %n",
              &(ucMode), &nOffset);

  pnoRequest.modePNO = ucMode;
  /*for LA we just expose suspend option*/
  if (( 1 != ucParams )||(  ucMode >= SIR_PNO_MODE_MAX ))
  {
     pnoRequest.modePNO = SIR_PNO_MODE_ON_SUSPEND;
  }

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
  // IKHSS7-5797: set PNO intervals
  /* A set value represents the amount of time that PNO will wait between
     two consecutive scan procedures.
     If the desired is for a uniform timer that fires always at the exact same
     interval - one single value is to be set

     If there is a desire for a more complex - telescopic like timer multiple
     values can be set - once PNO reaches the end of the array it will
     continue scanning at intervals presented by the last value

     uTimerRepeat
     How many times it should repeat that wait value
     0 - keep using this timer until PNO is disabled/
     e.g:   2 3
            4 0
    - it will wait 2s between consecutive scans for 3 times
    - after that it will wait 4s between consecutive scans until disabled
  */
  pnoRequest.scanTimers.ucScanTimersCount = 2;
  pnoRequest.scanTimers.aTimerValues[0].uTimerRepeat = 7;
  pnoRequest.scanTimers.aTimerValues[0].uTimerValue = 45;
  pnoRequest.scanTimers.aTimerValues[1].uTimerRepeat = 0;
  pnoRequest.scanTimers.aTimerValues[1].uTimerValue = 480;

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
  sme_SetPreferredNetworkList(WLAN_HDD_GET_HAL_CTX(pAdapter), &pnoRequest,
                                pAdapter->sessionId,
                                found_pref_network_cb, pAdapter);

  return VOS_STATUS_SUCCESS;
}/*iw_set_pno*/

VOS_STATUS iw_set_rssi_filter(struct net_device *dev, struct iw_request_info *info,
        union iwreq_data *wrqu, char *extra, int nOffset)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    v_U8_t rssiThreshold = 0;
    v_U8_t nRead;

    nRead = sscanf(wrqu->data.pointer + nOffset,"%hhu",
           &rssiThreshold);

    if ( 1 != nRead )
    {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN,
                "Incorrect format");
      return VOS_STATUS_E_FAILURE;
    }

    sme_SetRSSIFilter(WLAN_HDD_GET_HAL_CTX(pAdapter), rssiThreshold);
    return VOS_STATUS_SUCCESS;
}


static int iw_set_pno_priv(struct net_device *dev,
                           struct iw_request_info *info,
                           union iwreq_data *wrqu, char *extra)
{
<<<<<<< HEAD
<<<<<<< HEAD
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                "Set PNO Private");
  return iw_set_pno(dev,info,wrqu,extra,0);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                "Set PNO Private");

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
       VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
       return -EBUSY;
    }
    return iw_set_pno(dev,info,wrqu,extra,0);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
}
#endif /*FEATURE_WLAN_SCAN_PNO*/

//Common function to SetBand
int hdd_setBand_helper(struct net_device *dev, tANI_U8* ptr)
{
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    tANI_U8 band = 0;
    eCsrBand currBand = eCSR_BAND_MAX;

    band = ptr[WLAN_HDD_UI_SET_BAND_VALUE_OFFSET] - '0'; /*convert the band value from ascii to integer*/

    switch(band)
    {
        case WLAN_HDD_UI_BAND_AUTO:
             band = eCSR_BAND_ALL;
        break;
        case WLAN_HDD_UI_BAND_5_GHZ:
            band = eCSR_BAND_5G;
        break;
        case WLAN_HDD_UI_BAND_2_4_GHZ:
            band = eCSR_BAND_24;
        break;
        default:
            band = eCSR_BAND_MAX;
    }

        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, "%s: change band to %u",
<<<<<<< HEAD
<<<<<<< HEAD
                __FUNCTION__, band);
=======
                __func__, band);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                __func__, band);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    if (band == eCSR_BAND_MAX)
    {
        /* Received change band request with invalid band value */
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
<<<<<<< HEAD
<<<<<<< HEAD
               "%s: Invalid band value %u", __FUNCTION__, band);
=======
               "%s: Invalid band value %u", __func__, band);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
               "%s: Invalid band value %u", __func__, band);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        return -EIO;
    }

    if ( (band == eCSR_BAND_24 && pHddCtx->cfg_ini->nBandCapability==2) || 
         (band == eCSR_BAND_5G && pHddCtx->cfg_ini->nBandCapability==1) || 
         (band == eCSR_BAND_ALL && pHddCtx->cfg_ini->nBandCapability!=0)) 
    {       
         VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
<<<<<<< HEAD
<<<<<<< HEAD
             "%s: band value %u violate INI settings %u", __FUNCTION__,
=======
             "%s: band value %u violate INI settings %u", __func__,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
             "%s: band value %u violate INI settings %u", __func__,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
             band, pHddCtx->cfg_ini->nBandCapability);
         return -EIO;
    }

    if (eHAL_STATUS_SUCCESS != sme_GetFreqBand(hHal, &currBand))
    {
         VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
              "%s: Failed to get current band config",
<<<<<<< HEAD
<<<<<<< HEAD
                 __FUNCTION__);
=======
                 __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                 __func__);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
         return -EIO;
    }

    if (currBand != band)
    {
        /* Change band request received.
         * Abort pending scan requests, flush the existing scan results,
         * and change the band capability
         */
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                "%s: Current band value = %u, new setting %u ",
<<<<<<< HEAD
<<<<<<< HEAD
                 __FUNCTION__, currBand, band);
=======
                 __func__, currBand, band);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                 __func__, currBand, band);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

        if (hdd_connIsConnected(WLAN_HDD_GET_STATION_CTX_PTR(pAdapter)))
        {
             hdd_station_ctx_t *pHddStaCtx = &(pAdapter)->sessionCtx.station;
             eHalStatus status = eHAL_STATUS_SUCCESS;
             long lrc;

             /* STA already connected on current band, So issue disconnect first,
                        * then change the band*/

             hddLog(VOS_TRACE_LEVEL_INFO,
                     "%s STA connected in band %u, Changing band to %u, Issuing Disconnect",
                        __func__, csrGetCurrentBand(hHal), band);

             pHddStaCtx->conn_info.connState = eConnectionState_NotConnected;
             INIT_COMPLETION(pAdapter->disconnect_comp_var);

             status = sme_RoamDisconnect( WLAN_HDD_GET_HAL_CTX(pAdapter),
             pAdapter->sessionId, eCSR_DISCONNECT_REASON_UNSPECIFIED);

             if ( eHAL_STATUS_SUCCESS != status)
             {
                 hddLog(VOS_TRACE_LEVEL_ERROR,
                         "%s csrRoamDisconnect failure, returned %d \n",
                           __func__, (int)status );
                 return -EINVAL;
             }

             lrc = wait_for_completion_interruptible_timeout(
                     &pAdapter->disconnect_comp_var,
                     msecs_to_jiffies(WLAN_WAIT_TIME_DISCONNECT));

<<<<<<< HEAD
<<<<<<< HEAD
             if(lrc <= 0) {

                hddLog(VOS_TRACE_LEVEL_ERROR,"%s: %s while while waiting for csrRoamDisconnect ",
                 __FUNCTION__, (0 == lrc) ? "Timeout" : "Interrupt");
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
             if (lrc <= 0) {

                hddLog(VOS_TRACE_LEVEL_ERROR,"%s: %s while waiting for csrRoamDisconnect ",
                 __func__, (0 == lrc) ? "Timeout" : "Interrupt");
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

                return (0 == lrc) ? -ETIMEDOUT : -EINTR;
             }
        }

        hdd_abort_mac_scan(pHddCtx);
        sme_ScanFlushResult(hHal, pAdapter->sessionId);
<<<<<<< HEAD
<<<<<<< HEAD
        if(eHAL_STATUS_SUCCESS != sme_SetFreqBand(hHal, (eCsrBand)band))
        {
             VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                     "%s: failed to set the band value to %u ",
                        __FUNCTION__, band);
             return -EINVAL;
        }
#ifdef CONFIG_CFG80211
        wlan_hdd_cfg80211_update_band(pHddCtx->wiphy, (eCsrBand)band);
#endif
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#if  defined (WLAN_FEATURE_VOWIFI_11R) || defined (FEATURE_WLAN_CCX) || defined(FEATURE_WLAN_LFR)
        sme_UpdateBgScanConfigIniChannelList(hHal, (eCsrBand) band);
#endif
        if (eHAL_STATUS_SUCCESS != sme_SetFreqBand(hHal, (eCsrBand)band))
        {
             VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                     "%s: failed to set the band value to %u ",
                        __func__, band);
             return -EINVAL;
        }
        wlan_hdd_cfg80211_update_band(pHddCtx->wiphy, (eCsrBand)band);
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    }
    return 0;
}

static int iw_set_band_config(struct net_device *dev,
                           struct iw_request_info *info,
                           union iwreq_data *wrqu, char *extra)
{
<<<<<<< HEAD
<<<<<<< HEAD
    tANI_U8 *ptr = (tANI_U8*)wrqu->data.pointer;
    int ret = 0;

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,"%s: ", __FUNCTION__);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    tANI_U8 *ptr = (tANI_U8*)wrqu->data.pointer;
    int ret = 0;

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,"%s: ", __func__);

    if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
        return -EBUSY;
    }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    if (memcmp(ptr, "SETBAND ", 8) == 0)
    {
        /* Change band request received */
        ret = hdd_setBand_helper(dev, ptr);
        return ret;

    }
    return 0;
}

static int iw_set_power_params_priv(struct net_device *dev,
                           struct iw_request_info *info,
                           union iwreq_data *wrqu, char *extra)
{
  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
                "Set power params Private");
  return iw_set_power_params(dev,info,wrqu,extra,0);
}



/*string based input*/
VOS_STATUS iw_set_power_params(struct net_device *dev, struct iw_request_info *info,
                      union iwreq_data *wrqu, char *extra, int nOffset)
{
  hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
  tSirSetPowerParamsReq powerRequest;
  char *ptr;
  v_U8_t  ucType;
  v_U32_t  uTotalSize, uValue;
  /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

  VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
            "Power Params data len %d data %s",
            wrqu->data.length,
<<<<<<< HEAD
<<<<<<< HEAD
            wrqu->data.pointer);
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
            (char *)wrqu->data.pointer);

  if ((WLAN_HDD_GET_CTX(pAdapter))->isLogpInProgress)
  {
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_FATAL,
                                  "%s:LOGP in Progress. Ignore!!!", __func__);
    return -EBUSY;
  }
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

  if (wrqu->data.length <= nOffset )
  {
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_WARN, "set power param input is not correct");
    return VOS_STATUS_E_FAILURE;
  }

  uTotalSize = wrqu->data.length - nOffset;

  /*-----------------------------------------------------------------------
    Input is string based and expected to be like this:

    <param_type> <param_value> <param_type> <param_value> ...

    e.g:
    1 2 2 3 3 0 4 1 5 1

    e.g. setting just a few:
    1 2 4 1

    parameter types:
    -----------------------------
    1 - Ignore DTIM
    2 - Listen Interval
    3 - Broadcast Multicas Filter
    4 - Beacon Early Termination
    5 - Beacon Early Termination Interval
  -----------------------------------------------------------------------*/
  powerRequest.uIgnoreDTIM       = SIR_NOCHANGE_POWER_VALUE;
  powerRequest.uListenInterval   = SIR_NOCHANGE_POWER_VALUE;
  powerRequest.uBcastMcastFilter = SIR_NOCHANGE_POWER_VALUE;
  powerRequest.uEnableBET        = SIR_NOCHANGE_POWER_VALUE;
  powerRequest.uBETInterval      = SIR_NOCHANGE_POWER_VALUE;

  ptr = (char*)(wrqu->data.pointer + nOffset);

  while ( uTotalSize )
  {
    sscanf(ptr,"%hhu %n", &(ucType), &nOffset);

    uTotalSize -= nOffset;

    if (!uTotalSize)
    {
      VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
<<<<<<< HEAD
<<<<<<< HEAD
                "Invalid input parametery type : %d with no value at offset %d",
=======
                "Invalid input parameter type : %d with no value at offset %d",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                "Invalid input parameter type : %d with no value at offset %d",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                ucType, nOffset);
      return VOS_STATUS_E_FAILURE;
    }

    ptr += nOffset;
    sscanf(ptr,"%lu %n", &(uValue), &nOffset);

    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO,
              "Power request parameter %d value %d offset %d",
              ucType, uValue, nOffset);

    switch (ucType)
    {
      case eSIR_IGNORE_DTIM:
      powerRequest.uIgnoreDTIM       = uValue;
      break;
      case eSIR_LISTEN_INTERVAL:
      powerRequest.uListenInterval   = uValue;
      break;
      case eSIR_MCAST_BCAST_FILTER:
      powerRequest.uBcastMcastFilter = uValue;
      break;
      case eSIR_ENABLE_BET:
      powerRequest.uEnableBET        = uValue;
      break;
      case eSIR_BET_INTERVAL:
      powerRequest.uBETInterval      = uValue;
      break;
      default:
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR,
<<<<<<< HEAD
<<<<<<< HEAD
                "Invalid input parametery type : %d with value: %d at offset %d",
=======
                "Invalid input parameter type : %d with value: %d at offset %d",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
                "Invalid input parameter type : %d with value: %d at offset %d",
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
                ucType, uValue,  nOffset);
      return VOS_STATUS_E_FAILURE;
    }

    uTotalSize -= nOffset;
    VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_INFO, 
              "Power request parameter %d Total size", 
              uTotalSize);
    ptr += nOffset;
    /* This is added for dynamic Tele LI enable (0xF1) /disable (0xF0)*/
    if(!(uTotalSize - nOffset) && 
       (powerRequest.uListenInterval != SIR_NOCHANGE_POWER_VALUE))
    {
        uTotalSize = 0;
    }

  }/*Go for as long as we have a valid string*/

  /* put the device into full power*/
  wlan_hdd_enter_bmps(pAdapter, DRIVER_POWER_MODE_ACTIVE);

  /* Apply the power save params*/
<<<<<<< HEAD
<<<<<<< HEAD
  sme_SetPowerParams( WLAN_HDD_GET_HAL_CTX(pAdapter), &powerRequest);
=======
  sme_SetPowerParams( WLAN_HDD_GET_HAL_CTX(pAdapter), &powerRequest, FALSE);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
  sme_SetPowerParams( WLAN_HDD_GET_HAL_CTX(pAdapter), &powerRequest, FALSE);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

  /* put the device back to power save*/
  wlan_hdd_enter_bmps(pAdapter, DRIVER_POWER_MODE_AUTO);

  return VOS_STATUS_SUCCESS;
}/*iw_set_power_params*/


// Define the Wireless Extensions to the Linux Network Device structure
// A number of these routines are NULL (meaning they are not implemented.)

static const iw_handler      we_handler[] =
{
   (iw_handler) iw_set_commit,      /* SIOCSIWCOMMIT */
   (iw_handler) iw_get_name,      /* SIOCGIWNAME */
   (iw_handler) NULL,            /* SIOCSIWNWID */
   (iw_handler) NULL,            /* SIOCGIWNWID */
   (iw_handler) iw_set_freq,      /* SIOCSIWFREQ */
   (iw_handler) iw_get_freq,      /* SIOCGIWFREQ */
   (iw_handler) iw_set_mode,      /* SIOCSIWMODE */
   (iw_handler) iw_get_mode,      /* SIOCGIWMODE */
   (iw_handler) NULL,              /* SIOCSIWSENS */
   (iw_handler) NULL,              /* SIOCGIWSENS */
   (iw_handler) NULL,             /* SIOCSIWRANGE */
   (iw_handler) iw_get_range,      /* SIOCGIWRANGE */
   (iw_handler) iw_set_priv,       /* SIOCSIWPRIV */
   (iw_handler) NULL,             /* SIOCGIWPRIV */
   (iw_handler) NULL,             /* SIOCSIWSTATS */
   (iw_handler) NULL,             /* SIOCGIWSTATS */
   iw_handler_set_spy,             /* SIOCSIWSPY */
   iw_handler_get_spy,             /* SIOCGIWSPY */
   iw_handler_set_thrspy,         /* SIOCSIWTHRSPY */
   iw_handler_get_thrspy,         /* SIOCGIWTHRSPY */
   (iw_handler) iw_set_ap_address,   /* SIOCSIWAP */
   (iw_handler) iw_get_ap_address,   /* SIOCGIWAP */
   (iw_handler) iw_set_mlme,              /* SIOCSIWMLME */
   (iw_handler) NULL,              /* SIOCGIWAPLIST */
   (iw_handler) iw_set_scan,      /* SIOCSIWSCAN */
   (iw_handler) iw_get_scan,      /* SIOCGIWSCAN */
   (iw_handler) iw_set_essid,      /* SIOCSIWESSID */
   (iw_handler) iw_get_essid,      /* SIOCGIWESSID */
   (iw_handler) iw_set_nick,      /* SIOCSIWNICKN */
   (iw_handler) iw_get_nick,      /* SIOCGIWNICKN */
   (iw_handler) NULL,             /* -- hole -- */
   (iw_handler) NULL,             /* -- hole -- */
   (iw_handler) iw_set_bitrate,   /* SIOCSIWRATE */
   (iw_handler) iw_get_bitrate,   /* SIOCGIWRATE */
   (iw_handler) iw_set_rts_threshold,/* SIOCSIWRTS */
   (iw_handler) iw_get_rts_threshold,/* SIOCGIWRTS */
   (iw_handler) iw_set_frag_threshold,   /* SIOCSIWFRAG */
   (iw_handler) iw_get_frag_threshold,   /* SIOCGIWFRAG */
   (iw_handler) iw_set_tx_power,      /* SIOCSIWTXPOW */
   (iw_handler) iw_get_tx_power,      /* SIOCGIWTXPOW */
   (iw_handler) iw_set_retry,          /* SIOCSIWRETRY */
   (iw_handler) iw_get_retry,          /* SIOCGIWRETRY */
   (iw_handler) iw_set_encode,          /* SIOCSIWENCODE */
   (iw_handler) iw_get_encode,          /* SIOCGIWENCODE */
   (iw_handler) iw_set_power_mode,      /* SIOCSIWPOWER */
   (iw_handler) iw_get_power_mode,      /* SIOCGIWPOWER */
   (iw_handler) NULL,                 /* -- hole -- */
   (iw_handler) NULL,                /* -- hole -- */
   (iw_handler) iw_set_genie,      /* SIOCSIWGENIE */
   (iw_handler) iw_get_genie,      /* SIOCGIWGENIE */
   (iw_handler) iw_set_auth,      /* SIOCSIWAUTH */
   (iw_handler) iw_get_auth,      /* SIOCGIWAUTH */
   (iw_handler) iw_set_encodeext,   /* SIOCSIWENCODEEXT */
   (iw_handler) iw_get_encodeext,   /* SIOCGIWENCODEEXT */
   (iw_handler) NULL,         /* SIOCSIWPMKSA */
};

static const iw_handler we_private[] = {

   [WLAN_PRIV_SET_INT_GET_NONE      - SIOCIWFIRSTPRIV]   = iw_setint_getnone,  //set priv ioctl
   [WLAN_PRIV_SET_NONE_GET_INT      - SIOCIWFIRSTPRIV]   = iw_setnone_getint,  //get priv ioctl
   [WLAN_PRIV_SET_CHAR_GET_NONE     - SIOCIWFIRSTPRIV]   = iw_setchar_getnone, //get priv ioctl
   [WLAN_PRIV_SET_THREE_INT_GET_NONE - SIOCIWFIRSTPRIV]  = iw_set_three_ints_getnone,
   [WLAN_PRIV_GET_CHAR_SET_NONE      - SIOCIWFIRSTPRIV]  = iw_get_char_setnone,
   [WLAN_PRIV_SET_NONE_GET_NONE     - SIOCIWFIRSTPRIV]   = iw_setnone_getnone, //action priv ioctl
   [WLAN_PRIV_SET_VAR_INT_GET_NONE  - SIOCIWFIRSTPRIV]   = iw_set_var_ints_getnone,
   [WLAN_PRIV_ADD_TSPEC             - SIOCIWFIRSTPRIV]   = iw_add_tspec,
   [WLAN_PRIV_DEL_TSPEC             - SIOCIWFIRSTPRIV]   = iw_del_tspec,
   [WLAN_PRIV_GET_TSPEC             - SIOCIWFIRSTPRIV]   = iw_get_tspec,
#ifdef FEATURE_OEM_DATA_SUPPORT
   [WLAN_PRIV_SET_OEM_DATA_REQ - SIOCIWFIRSTPRIV] = iw_set_oem_data_req, //oem data req Specifc
   [WLAN_PRIV_GET_OEM_DATA_RSP - SIOCIWFIRSTPRIV] = iw_get_oem_data_rsp, //oem data req Specifc
#endif

#ifdef FEATURE_WLAN_WAPI
   [WLAN_PRIV_SET_WAPI_MODE             - SIOCIWFIRSTPRIV]  = iw_qcom_set_wapi_mode,
   [WLAN_PRIV_GET_WAPI_MODE             - SIOCIWFIRSTPRIV]  = iw_qcom_get_wapi_mode,
   [WLAN_PRIV_SET_WAPI_ASSOC_INFO       - SIOCIWFIRSTPRIV]  = iw_qcom_set_wapi_assoc_info,
   [WLAN_PRIV_SET_WAPI_KEY              - SIOCIWFIRSTPRIV]  = iw_qcom_set_wapi_key,
   [WLAN_PRIV_SET_WAPI_BKID             - SIOCIWFIRSTPRIV]  = iw_qcom_set_wapi_bkid,
   [WLAN_PRIV_GET_WAPI_BKID             - SIOCIWFIRSTPRIV]  = iw_qcom_get_wapi_bkid,
#endif /* FEATURE_WLAN_WAPI */
#ifdef WLAN_FEATURE_VOWIFI_11R
   [WLAN_PRIV_SET_FTIES                 - SIOCIWFIRSTPRIV]   = iw_set_fties,
#endif
   [WLAN_PRIV_SET_HOST_OFFLOAD          - SIOCIWFIRSTPRIV]   = iw_set_host_offload,
   [WLAN_GET_WLAN_STATISTICS            - SIOCIWFIRSTPRIV]   = iw_get_statistics,
   [WLAN_SET_KEEPALIVE_PARAMS           - SIOCIWFIRSTPRIV]   = iw_set_keepalive_params
#ifdef WLAN_FEATURE_PACKET_FILTERING
   ,
   [WLAN_SET_PACKET_FILTER_PARAMS       - SIOCIWFIRSTPRIV]   = iw_set_packet_filter_params
#endif
#ifdef FEATURE_WLAN_SCAN_PNO
   ,
   [WLAN_SET_PNO                        - SIOCIWFIRSTPRIV]   = iw_set_pno_priv
#endif
   ,
   [WLAN_SET_BAND_CONFIG                - SIOCIWFIRSTPRIV]   = iw_set_band_config,
   [WLAN_PRIV_SET_MCBC_FILTER           - SIOCIWFIRSTPRIV]   = iw_set_dynamic_mcbc_filter,
   [WLAN_PRIV_CLEAR_MCBC_FILTER         - SIOCIWFIRSTPRIV]   = iw_clear_dynamic_mcbc_filter,
   [WLAN_SET_POWER_PARAMS               - SIOCIWFIRSTPRIV]   = iw_set_power_params_priv,
<<<<<<< HEAD
<<<<<<< HEAD
   [WLAN_GET_LINK_SPEED                 - SIOCIWFIRSTPRIV]   = iw_get_linkspeed
=======
   [WLAN_GET_LINK_SPEED                 - SIOCIWFIRSTPRIV]   = iw_get_linkspeed,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
   [WLAN_GET_LINK_SPEED                 - SIOCIWFIRSTPRIV]   = iw_get_linkspeed,
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
};

/*Maximum command length can be only 15 */
static const struct iw_priv_args we_private_args[] = {

    /* handlers for main ioctl */
    {   WLAN_PRIV_SET_INT_GET_NONE,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "" },

    /* handlers for sub-ioctl */
    {   WE_SET_11D_STATE,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "set11Dstate" },

    {   WE_WOWL,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "wowl" },

    {   WE_SET_POWER,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "setPower" },

    {   WE_SET_MAX_ASSOC,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "setMaxAssoc" },

    {   WE_SET_SAP_AUTO_CHANNEL_SELECTION,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "setAutoChannel" },

    {   WE_SET_DATA_INACTIVITY_TO,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "inactivityTO" },

    {   WE_SET_MAX_TX_POWER,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "setMaxTxPower" },
    /* set Higher DTIM Transition (DTIM1 to DTIM3)
     * 1 = enable and 0 = disable */
    {
        WE_SET_HIGHER_DTIM_TRANSITION,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "setHDtimTransn" },

    {   WE_SET_TM_LEVEL,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0, 
        "setTmLevel" },

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    {   WE_SET_CHANNEL_RANGE,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "setChannelRange" },

    // IKJB42MAIN-1244, Motorola, a19091 - BEGIN
    {   WE_SET_IPV6_FILTER_STATE,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "setIPV6FilState" },
    // IKJB42MAIN-1244, Motorola, a19091 - END

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    /* handlers for main ioctl */
    {   WLAN_PRIV_SET_NONE_GET_INT,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "" },

    /* handlers for sub-ioctl */
    {   WE_GET_11D_STATE,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "get11Dstate" },

    {   WE_IBSS_STATUS,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "getAdhocStatus" },

    {   WE_PMC_STATE,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "pmcState" },

    {   WE_GET_WLAN_DBG,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "getwlandbg" },

    {   WE_MODULE_DOWN_IND,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "moduleDownInd" },

    {   WE_GET_MAX_ASSOC,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "getMaxAssoc" },

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_INTEGRATED_SOC
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    {   WE_GET_WDI_DBG,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "getwdidbg" },
<<<<<<< HEAD
<<<<<<< HEAD
#endif // FEATURE_WLAN_INTEGRATED_SOC
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    {   WE_GET_SAP_AUTO_CHANNEL_SELECTION,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "getAutoChannel" },

    {   WE_GET_CONCURRENCY_MODE,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "getconcurrency" },

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    /* MOTOROLA IKJB42MAIN-274 */
    {   WE_GET_MCC_MODE,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "getMccMode" },

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    /* handlers for main ioctl */
    {   WLAN_PRIV_SET_CHAR_GET_NONE,
        IW_PRIV_TYPE_CHAR| 512,
        0,
        "" },

    /* handlers for sub-ioctl */
    {   WE_WOWL_ADD_PTRN,
        IW_PRIV_TYPE_CHAR| 512,
        0,
        "wowlAddPtrn" },

    {   WE_WOWL_DEL_PTRN,
        IW_PRIV_TYPE_CHAR| 512,
        0,
        "wowlDelPtrn" },

#if defined WLAN_FEATURE_VOWIFI
    /* handlers for sub-ioctl */
    {   WE_NEIGHBOR_REPORT_REQUEST,
        IW_PRIV_TYPE_CHAR | 512,
        0,
        "neighbor" },
#endif
    {   WE_SET_AP_WPS_IE,
        IW_PRIV_TYPE_CHAR| 512,
        0,
        "set_ap_wps_ie" },

    {   WE_SET_CONFIG,
        IW_PRIV_TYPE_CHAR| 512,
        0,
        "setConfig" },

    /* handlers for main ioctl */
    {   WLAN_PRIV_SET_THREE_INT_GET_NONE,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 3,
        0,
        "" },

    /* handlers for sub-ioctl */
    {   WE_SET_WLAN_DBG,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 3,
        0,
        "setwlandbg" },

<<<<<<< HEAD
<<<<<<< HEAD
#ifdef FEATURE_WLAN_INTEGRATED_SOC
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    {   WE_SET_WDI_DBG,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 3,
        0,
        "setwdidbg" },
<<<<<<< HEAD
<<<<<<< HEAD
#endif // FEATURE_WLAN_INTEGRATED_SOC
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    {   WE_SET_SAP_CHANNELS,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 3,
        0,
        "setsapchannels" },

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
   //Begin Motorola dcw476 4/17/13 IKJBXLINE-5577:changing wlan driver log level dynamically
   {    WE_SET_WLAN_DBG_TILL_LEVEL,
         IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 3,
         0,
         "setwlanloglevel" },
   //END IKJBXLINE-5577

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    /* handlers for main ioctl */
    {   WLAN_PRIV_GET_CHAR_SET_NONE,
        0,
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        "" },

    /* handlers for sub-ioctl */
    {   WE_WLAN_VERSION,
        0,
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        "version" },
    {   WE_GET_STATS,
        0,
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        "getStats" },
    {   WE_GET_CFG,
        0,
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        "getConfig" },
#ifdef WLAN_FEATURE_11AC
    {   WE_GET_RSSI,
        0,
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        "getRSSI" },
#endif
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#if defined WLAN_FEATURE_VOWIFI_11R || defined FEATURE_WLAN_CCX || defined(FEATURE_WLAN_LFR)
    {   WE_GET_ROAM_RSSI,
        0,
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        "getRoamRSSI" },
#endif
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    {   WE_GET_WMM_STATUS,
        0,
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        "getWmmStatus" },
    {
        WE_GET_CHANNEL_LIST,
        0, 
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        "getChannelList" },
<<<<<<< HEAD
<<<<<<< HEAD

=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#ifdef FEATURE_WLAN_TDLS
    {
        WE_GET_TDLS_PEERS,
        0,
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        "getTdlsPeers" },
#endif
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    /* handlers for main ioctl */
    {   WLAN_PRIV_SET_NONE_GET_NONE,
        0,
        0,
        "" },

    /* handlers for sub-ioctl */
    {   WE_CLEAR_STATS,
        0,
        0,
        "clearStats" },
    {   WE_INIT_AP,
        0,
        0,
        "initAP" },
    {   WE_STOP_AP,
        0,
        0,
        "exitAP" },
<<<<<<< HEAD
<<<<<<< HEAD
=======
#ifdef WLAN_BTAMP_FEATURE
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#ifdef WLAN_BTAMP_FEATURE
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    {   WE_ENABLE_AMP,
        0,
        0,
        "enableAMP" },
    {   WE_DISABLE_AMP,
        0,
        0,
        "disableAMP" },
<<<<<<< HEAD
<<<<<<< HEAD
=======
#endif
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
#endif
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    {   WE_ENABLE_DXE_STALL_DETECT,
        0,
        0,
        "dxeStallDetect" },
    {   WE_DISPLAY_DXE_SNAP_SHOT,
        0,
        0,
        "dxeSnapshot" },
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    {   WE_DISPLAY_DATAPATH_SNAP_SHOT,
        0,
        0,
        "dataSnapshot"},
    {
        WE_SET_REASSOC_TRIGGER,
        0,
        0,
        "reassoc" },
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    /* handlers for main ioctl */
    {   WLAN_PRIV_SET_VAR_INT_GET_NONE,
        IW_PRIV_TYPE_INT | MAX_VAR_ARGS,
        0,
        "" },

    /* handlers for sub-ioctl */
    {   WE_LOG_DUMP_CMD,
        IW_PRIV_TYPE_INT | MAX_VAR_ARGS,
        0,
        "dump" },

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    /* handlers for sub ioctl */
   {
       WE_MCC_CONFIG_CREDENTIAL,
       IW_PRIV_TYPE_INT | MAX_VAR_ARGS,
       0,
       "setMccCrdnl" },

    /* handlers for sub ioctl */
   {
       WE_MCC_CONFIG_PARAMS,
       IW_PRIV_TYPE_INT | MAX_VAR_ARGS,
       0,
       "setMccConfig" },

#ifdef FEATURE_WLAN_TDLS
    /* handlers for sub ioctl */
   {
       WE_TDLS_CONFIG_PARAMS,
       IW_PRIV_TYPE_INT | MAX_VAR_ARGS,
       0,
       "setTdlsConfig" },
#endif

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    /* handlers for main ioctl */
    {   WLAN_PRIV_ADD_TSPEC,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | HDD_WLAN_WMM_PARAM_COUNT,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "addTspec" },

    /* handlers for main ioctl */
    {   WLAN_PRIV_DEL_TSPEC,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "delTspec" },

    /* handlers for main ioctl */
    {   WLAN_PRIV_GET_TSPEC,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "getTspec" },

#ifdef FEATURE_OEM_DATA_SUPPORT
    /* handlers for main ioctl - OEM DATA */
    {
        WLAN_PRIV_SET_OEM_DATA_REQ,
        IW_PRIV_TYPE_BYTE | sizeof(struct iw_oem_data_req) | IW_PRIV_SIZE_FIXED,
        0,
        "set_oem_data_req" },

    /* handlers for main ioctl - OEM DATA */
    {
        WLAN_PRIV_GET_OEM_DATA_RSP,
        0,
        IW_PRIV_TYPE_BYTE | MAX_OEM_DATA_RSP_LEN,
        "get_oem_data_rsp" },
#endif

#ifdef FEATURE_WLAN_WAPI
   /* handlers for main ioctl SET_WAPI_MODE */
    {   WLAN_PRIV_SET_WAPI_MODE,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        0,
        "SET_WAPI_MODE" },

   /* handlers for main ioctl GET_WAPI_MODE */
    {   WLAN_PRIV_GET_WAPI_MODE,
        0,
        IW_PRIV_TYPE_INT | IW_PRIV_SIZE_FIXED | 1,
        "GET_WAPI_MODE" },

   /* handlers for main ioctl SET_ASSOC_INFO */
    {   WLAN_PRIV_SET_WAPI_ASSOC_INFO,
        IW_PRIV_TYPE_BYTE | IW_PRIV_SIZE_FIXED | 400,
        0,
        "SET_WAPI_ASSOC" },

   /* handlers for main ioctl SET_WAPI_KEY */
    {   WLAN_PRIV_SET_WAPI_KEY,
        IW_PRIV_TYPE_BYTE | IW_PRIV_SIZE_FIXED | 71,
        0,
        "SET_WAPI_KEY" },

   /* handlers for main ioctl SET_WAPI_BKID */
    {   WLAN_PRIV_SET_WAPI_BKID,
        IW_PRIV_TYPE_BYTE | IW_PRIV_SIZE_FIXED | 24,
        0,
        "SET_WAPI_BKID" },

   /* handlers for main ioctl GET_WAPI_BKID */
    {   WLAN_PRIV_GET_WAPI_BKID,
        0,
        IW_PRIV_TYPE_BYTE | IW_PRIV_SIZE_FIXED | 24,
        "GET_WAPI_BKID" },
#endif /* FEATURE_WLAN_WAPI */

    /* handlers for main ioctl - host offload */
    {
        WLAN_PRIV_SET_HOST_OFFLOAD,
        IW_PRIV_TYPE_BYTE | sizeof(tHostOffloadRequest),
        0,
        "setHostOffload" },

    {
        WLAN_GET_WLAN_STATISTICS,
        0,
        IW_PRIV_TYPE_BYTE | WE_MAX_STR_LEN,
        "getWlanStats" },

    {
        WLAN_SET_KEEPALIVE_PARAMS,
        IW_PRIV_TYPE_BYTE  | sizeof(tKeepAliveRequest),
        0,
        "setKeepAlive" },
#ifdef WLAN_FEATURE_PACKET_FILTERING
    {
        WLAN_SET_PACKET_FILTER_PARAMS,
        IW_PRIV_TYPE_BYTE  | sizeof(tPacketFilterCfg),
        0,
        "setPktFilter" },
#endif
#ifdef FEATURE_WLAN_SCAN_PNO
    {
        WLAN_SET_PNO,
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        0,
        "setpno" },
#endif
    {
        WLAN_SET_BAND_CONFIG,
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        0,
        "SETBAND" },
    /* handlers for dynamic MC BC ioctl */
    {
        WLAN_PRIV_SET_MCBC_FILTER,
<<<<<<< HEAD
<<<<<<< HEAD
        IW_PRIV_TYPE_BYTE | sizeof(tMcBcFilterCfg),
=======
        IW_PRIV_TYPE_BYTE | sizeof(tRcvFltMcAddrList),
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        IW_PRIV_TYPE_BYTE | sizeof(tRcvFltMcAddrList),
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
        0,
        "setMCBCFilter" },
    {
        WLAN_PRIV_CLEAR_MCBC_FILTER,
        0,
        0,
        "clearMCBCFilter" },
    {
        WLAN_SET_POWER_PARAMS,
        IW_PRIV_TYPE_CHAR| WE_MAX_STR_LEN,
        0,
        "setpowerparams" },
    {
        WLAN_GET_LINK_SPEED,
        IW_PRIV_TYPE_CHAR | 18,
<<<<<<< HEAD
<<<<<<< HEAD
        IW_PRIV_TYPE_CHAR | 3, "getLinkSpeed" },
=======
        IW_PRIV_TYPE_CHAR | 5, "getLinkSpeed" },
   
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
        IW_PRIV_TYPE_CHAR | 5, "getLinkSpeed" },
   
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
};



const struct iw_handler_def we_handler_def = {
   .num_standard     = sizeof(we_handler) / sizeof(we_handler[0]),
   .num_private      = sizeof(we_private) / sizeof(we_private[0]),
   .num_private_args = sizeof(we_private_args) / sizeof(we_private_args[0]),

   .standard         = (iw_handler *)we_handler,
   .private          = (iw_handler *)we_private,
   .private_args     = we_private_args,
   .get_wireless_stats = get_wireless_stats,
};

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
int hdd_validate_mcc_config(hdd_adapter_t *pAdapter, v_UINT_t staId, v_UINT_t arg1, v_UINT_t arg2, v_UINT_t arg3)
{
    v_U32_t  cmd = 288; //Command to RIVA
    hdd_context_t *pHddCtx = NULL;
    tHalHandle hHal = WLAN_HDD_GET_HAL_CTX(pAdapter);
    pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
    /*
     *configMccParam : specify the bit which needs to be modified
     *allowed to update based on wlan_qcom_cfg.ini
     * configuration
     * Bit 0 : SCHEDULE_TIME_SLICE   MIN : 5 MAX : 20
     * Bit 1 : MAX_NULL_SEND_TIME    MIN : 1 MAX : 10
     * Bit 2 : TX_EARLY_STOP_TIME    MIN : 1 MAX : 10
     * Bit 3 : RX_DRAIN_TIME         MIN : 1 MAX : 10
     * Bit 4 : CHANNEL_SWITCH_TIME   MIN : 1 MAX : 20
     * Bit 5 : MIN_CHANNEL_TIME      MIN : 5 MAX : 20
     * Bit 6 : PARK_BEFORE_TBTT      MIN : 1 MAX :  5
     * Bit 7 : MIN_AFTER_DTIM        MIN : 5 MAX : 15
     * Bit 8 : TOO_CLOSE_MARGIN      MIN : 1 MAX :  3
     * Bit 9 : Reserved
     */
    switch (arg1)
    {
        //Update MCC SCHEDULE_TIME_SLICE parameter
        case MCC_SCHEDULE_TIME_SLICE_CFG_PARAM :
            if( pHddCtx->cfg_ini->configMccParam & 0x0001)
            {
                if((arg2 >= 5) && (arg2 <= 20))
                {
                    logPrintf(hHal, cmd, staId, arg1, arg2, arg3);
                }
                else
                {
                    hddLog(LOGE, "%s : Enter a valid MCC configuration value\n",__FUNCTION__);
                    return 0;
                }
            }
            break;

        //Update MCC MAX_NULL_SEND_TIME parameter
        case MCC_MAX_NULL_SEND_TIME_CFG_PARAM :
            if( pHddCtx->cfg_ini->configMccParam & 0x0002)
            {
                if((arg2 >= 1) && (arg2 <= 10))
                {
                    logPrintf(hHal, cmd, staId, arg1, arg2, arg3);
                }
                else
                {
                    hddLog(LOGE, "%s : Enter a valid MCC configuration value\n",__FUNCTION__);
                    return 0;
                }
            }
            break;

        //Update MCC TX_EARLY_STOP_TIME parameter
        case MCC_TX_EARLY_STOP_TIME_CFG_PARAM :
            if( pHddCtx->cfg_ini->configMccParam & 0x0004)
            {
                if((arg2 >= 1) && (arg2 <= 10))
                {
                    logPrintf(hHal, cmd, staId, arg1, arg2, arg3);
                }
                else
                {
                    hddLog(LOGE, "%s : Enter a valid MCC configuration value\n",__FUNCTION__);
                    return 0;
                }
            }
            break;

        //Update MCC RX_DRAIN_TIME parameter
        case MCC_RX_DRAIN_TIME_CFG_PARAM :
            if( pHddCtx->cfg_ini->configMccParam & 0x0008)
            {
                if((arg2 >= 1) && (arg2 <= 10))
                {
                    logPrintf(hHal, cmd, staId, arg1, arg2, arg3);
                }
                else
                {
                    hddLog(LOGE, "%s : Enter a valid MCC configuration value\n",__FUNCTION__);
                    return 0;
                }
            }
        break;

        //Update MCC CHANNEL_SWITCH_TIME parameter
        case MCC_CHANNEL_SWITCH_TIME_CFG_PARAM :
            if( pHddCtx->cfg_ini->configMccParam & 0x0010)
            {
                if((arg2 >= 1) && (arg2 <= 20))
                {
                    logPrintf(hHal, cmd, staId, arg1, arg2, arg3);
                }
                else
                {
                    hddLog(LOGE, "%s : Enter a valid MCC configuration value\n",__FUNCTION__);
                    return 0;
                }
            }
            break;

        //Update MCC MIN_CHANNEL_TIME parameter
        case MCC_MIN_CHANNEL_TIME_CFG_PARAM :
            if( pHddCtx->cfg_ini->configMccParam & 0x0020)
            {
                if((arg2 >= 5) && (arg2 <= 20))
                {
                    logPrintf(hHal, cmd, staId, arg1, arg2, arg3);
                }
                else
                {
                    hddLog(LOGE, "%s : Enter a valid MCC configuration value\n",__FUNCTION__);
                    return 0;
                }
            }
            break;

        //Update MCC PARK_BEFORE_TBTT parameter
        case MCC_PARK_BEFORE_TBTT_CFG_PARAM :
            if( pHddCtx->cfg_ini->configMccParam & 0x0040)
            {
                if((arg2 >= 1) && (arg2 <= 5))
                {
                    logPrintf(hHal, cmd, staId, arg1, arg2, arg3);
                }
                else
                {
                    hddLog(LOGE, "%s : Enter a valid MCC configuration value\n",__FUNCTION__);
                    return 0;
                }
            }
            break;

        //Update MCC MIN_AFTER_DTIM parameter
        case MCC_MIN_AFTER_DTIM_CFG_PARAM :
            if( pHddCtx->cfg_ini->configMccParam & 0x0080)
            {
                if((arg2 >= 5) && (arg2 <= 15))
                {
                    logPrintf(hHal, cmd, staId, arg1, arg2, arg3);
                }
                else
                {
                    hddLog(LOGE, "%s : Enter a valid MCC configuration value\n",__FUNCTION__);
                    return 0;
                }
            }
            break;

        //Update MCC TOO_CLOSE_MARGIN parameter
        case MCC_TOO_CLOSE_MARGIN_CFG_PARAM :
            if( pHddCtx->cfg_ini->configMccParam & 0x0100)
            {
                if((arg2 >= 1) && (arg2 <= 3))
                {
                    logPrintf(hHal, cmd, staId, arg1, arg2, arg3);
                }
                else
                {
                    hddLog(LOGE, "%s : Enter a valid MCC configuration value\n",__FUNCTION__);
                    return 0;
                }
            }
            break;

        default :
            hddLog(LOGE, "%s : Uknown / Not allowed to configure parameter :  %d\n",
                        __FUNCTION__,arg1);
            break;
    }
    return 0;
}

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
int hdd_set_wext(hdd_adapter_t *pAdapter)
{
    hdd_wext_state_t *pwextBuf;
    hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
<<<<<<< HEAD
<<<<<<< HEAD
=======
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    pwextBuf = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);

    // Now configure the roaming profile links. To SSID and bssid.
    pwextBuf->roamProfile.SSIDs.numOfSSIDs = 0;
    pwextBuf->roamProfile.SSIDs.SSIDList = &pHddStaCtx->conn_info.SSID;

    pwextBuf->roamProfile.BSSIDs.numOfBSSIDs = 0;
    pwextBuf->roamProfile.BSSIDs.bssid = &pHddStaCtx->conn_info.bssId;

    /*Set the numOfChannels to zero to scan all the channels*/
    pwextBuf->roamProfile.ChannelInfo.numOfChannels = 0;
    pwextBuf->roamProfile.ChannelInfo.ChannelList = NULL;

    /* Default is no encryption */
    pwextBuf->roamProfile.EncryptionType.numEntries = 1;
    pwextBuf->roamProfile.EncryptionType.encryptionType[0] = eCSR_ENCRYPT_TYPE_NONE;

    pwextBuf->roamProfile.mcEncryptionType.numEntries = 1;
    pwextBuf->roamProfile.mcEncryptionType.encryptionType[0] = eCSR_ENCRYPT_TYPE_NONE;

    pwextBuf->roamProfile.BSSType = eCSR_BSS_TYPE_INFRASTRUCTURE;

    /* Default is no authentication */
    pwextBuf->roamProfile.AuthType.numEntries = 1;
    pwextBuf->roamProfile.AuthType.authType[0] = eCSR_AUTH_TYPE_OPEN_SYSTEM;

    pwextBuf->roamProfile.phyMode = eCSR_DOT11_MODE_TAURUS;
    pwextBuf->wpaVersion = IW_AUTH_WPA_VERSION_DISABLED;

    /*Set the default scan mode*/
<<<<<<< HEAD
<<<<<<< HEAD
    pAdapter->scan_info.scan_mode = eSIR_ACTIVE_SCAN;
=======
    pHddCtx->scan_info.scan_mode = eSIR_ACTIVE_SCAN;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    pHddCtx->scan_info.scan_mode = eSIR_ACTIVE_SCAN;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

    hdd_clearRoamProfileIe(pAdapter);

    return VOS_STATUS_SUCCESS;

    }

int hdd_register_wext(struct net_device *dev)
    {
    hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
    hdd_wext_state_t *pwextBuf = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
    VOS_STATUS status;

   ENTER();

    // Zero the memory.  This zeros the profile structure.
   memset(pwextBuf, 0,sizeof(hdd_wext_state_t));

    init_completion(&(WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter))->completion_var);


    status = hdd_set_wext(pAdapter);

    if(!VOS_IS_STATUS_SUCCESS(status)) {

        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR, ("ERROR: hdd_set_wext failed!!\n"));
        return eHAL_STATUS_FAILURE;
    }

    if (!VOS_IS_STATUS_SUCCESS(vos_event_init(&pwextBuf->vosevent)))
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR, ("ERROR: HDD vos event init failed!!\n"));
        return eHAL_STATUS_FAILURE;
    }

    if (!VOS_IS_STATUS_SUCCESS(vos_event_init(&pwextBuf->scanevent)))
    {
        VOS_TRACE(VOS_MODULE_ID_HDD, VOS_TRACE_LEVEL_ERROR, ("ERROR: HDD scan event init failed!!\n"));
        return eHAL_STATUS_FAILURE;
    }

    // Register as a wireless device
    dev->wireless_handlers = (struct iw_handler_def *)&we_handler_def;

    EXIT();
    return 0;
}

int hdd_UnregisterWext(struct net_device *dev)
{
#if 0
   hdd_wext_state_t *wextBuf;
   hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);

   ENTER();
   // Set up the pointer to the Wireless Extensions state structure
   wextBuf = pAdapter->pWextState;

   // De-allocate the Wireless Extensions state structure
   kfree(wextBuf);

   // Clear out the pointer to the Wireless Extensions state structure
   pAdapter->pWextState = NULL;

   EXIT();
#endif
   dev->wireless_handlers = NULL;
   return 0;
}


