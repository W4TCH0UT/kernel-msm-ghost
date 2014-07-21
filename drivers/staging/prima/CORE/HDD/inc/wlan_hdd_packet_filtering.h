/*
<<<<<<< HEAD
<<<<<<< HEAD
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
 * Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
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

/******************************************************************************
*
* Name:  wlan_hdd_packet_filtering.h
*
* Description: Packet Filter Definitions.
*
<<<<<<< HEAD
<<<<<<< HEAD
* Copyright (c) 2011 QUALCOMM Incorporated. All Rights Reserved.
* QUALCOMM Proprietary and Confidential.
=======
* Copyright (c) 2011 Qualcomm Technologies, Inc. All Rights Reserved.
* Qualcomm Technologies Proprietary and Confidential.
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
* Copyright (c) 2011 Qualcomm Technologies, Inc. All Rights Reserved.
* Qualcomm Technologies Proprietary and Confidential.
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
*
******************************************************************************/

#ifndef __WLAN_HDD_PACKET_FILTERING_H__
#define __WLAN_HDD_PACKET_FILTERING_H__

<<<<<<< HEAD
<<<<<<< HEAD
typedef struct
{
    v_U8_t       mcastBcastFilterSetting;
}tMcBcFilterCfg, *tpMcBcFilterCfg;


#ifdef WLAN_FEATURE_PACKET_FILTERING
#define HDD_MAX_CMP_PER_PACKET_FILTER     5     
=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release


#ifdef WLAN_FEATURE_PACKET_FILTERING

#define HDD_MAX_CMP_PER_PACKET_FILTER     5
#define HDD_FILTER_IPV6_MC_UC             1
#define HDD_FILTER_IPV6_MC                0
#define HDD_FILTER_ID_IPV6_MC             10
#define HDD_FILTER_ID_IPV6_UC             11

#define HDD_IPV6_MC_CMP_DATA              0x33
#define HDD_IPV6_UC_CMP_DATA              0x01
#define HDD_IPV6_CMP_DATA_0               0x86
#define HDD_IPV6_CMP_DATA_1               0xDD

#define HDD_WLAN_MAC_ADDR_LEN             6
#define HDD_MAX_NUM_MULTICAST_ADDRESS     10
<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release

typedef enum
{
  HDD_FILTER_PROTO_TYPE_INVALID = 0,
  HDD_FILTER_PROTO_TYPE_MAC = 1,
  HDD_FILTER_PROTO_TYPE_ARP = 2,
  HDD_FILTER_PROTO_TYPE_IPV4 =3 ,
  HDD_FILTER_PROTO_TYPE_IPV6 = 4,
  HDD_FILTER_PROTO_TYPE_UDP = 5,
  HDD_FILTER_PROTO_TYPE_MAX
} eProtoLayer;

typedef enum
{
  HDD_RCV_FILTER_INVALID = 0,
  HDD_RCV_FILTER_SET = 1,
  HDD_RCV_FILTER_CLEAR = 2,
  HDD_RCV_FILTER_MAX
}eFilterAction;

<<<<<<< HEAD
<<<<<<< HEAD
typedef enum 
=======
typedef enum
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
typedef enum
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
{
  HDD_FILTER_CMP_TYPE_INVALID = 0,
  HDD_FILTER_CMP_TYPE_EQUAL = 1,
  HDD_FILTER_CMP_TYPE_MASK_EQUAL = 2,
  HDD_FILTER_CMP_TYPE_NOT_EQUAL = 3,
  HDD_FILTER_CMP_TYPE_MASK_NOT_EQUAL = 4,
  HDD_FILTER_CMP_TYPE_MAX
}eCompareFlag;

struct PacketFilterParamsCfg
{
    v_U8_t              protocolLayer;
<<<<<<< HEAD
<<<<<<< HEAD
    v_U8_t              cmpFlag;   
=======
    v_U8_t              cmpFlag;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
    v_U8_t              cmpFlag;
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    v_U8_t              dataOffset;
    v_U8_t              dataLength;
    v_U8_t              compareData[8];
    v_U8_t              dataMask[8];
};

typedef struct
{
<<<<<<< HEAD
<<<<<<< HEAD
    v_U8_t            filterAction;    
    v_U8_t            filterId;
    v_U8_t            numParams;
    struct PacketFilterParamsCfg paramsData [HDD_MAX_CMP_PER_PACKET_FILTER];
    v_U8_t            bssIdx;
}tPacketFilterCfg, *tpPacketFilterCfg;

=======
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
    v_U8_t            filterAction;
    v_U8_t            filterId;
    v_U8_t            numParams;
    struct PacketFilterParamsCfg paramsData [HDD_MAX_CMP_PER_PACKET_FILTER];
}tPacketFilterCfg, *tpPacketFilterCfg;

typedef v_U8_t tHddMacAddr[HDD_WLAN_MAC_ADDR_LEN];

typedef struct
{
    v_U8_t         mcastBcastFilterSetting;
    v_U8_t         mcast_addr_cnt;
    tHddMacAddr    multicastAddr[HDD_MAX_NUM_MULTICAST_ADDRESS];
} tRcvFltMcAddrList, *tpRcvFltMcAddrList;

<<<<<<< HEAD
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
=======
>>>>>>> 1eaa4f9... prima: import from Ghost KK mr2 source release
#endif
#endif // __WLAN_HDD_PACKET_FILTERING_H__
