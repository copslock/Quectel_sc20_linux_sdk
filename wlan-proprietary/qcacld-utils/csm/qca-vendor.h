/**
 * Copyright (c) 2016 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

/*
 * Qualcomm Atheros OUI and vendor specific assignments
 * Copyright (c) 2014-2015, Qualcomm Atheros, Inc.
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef QCA_VENDOR_H
#define QCA_VENDOR_H

/*
 * This file is a registry of identifier assignments from the Qualcomm Atheros
 * OUI 00:13:74 for purposes other than MAC address assignment. New identifiers
 * can be assigned through normal review process for changes to the upstream
 * hostap.git repository.
 */

#define OUI_QCA 0x001374

/**
 * enum qca_radiotap_vendor_ids - QCA radiotap vendor namespace IDs
 */
enum qca_radiotap_vendor_ids {
	QCA_RADIOTAP_VID_WLANTEST = 0,
};

/**
 * enum qca_nl80211_vendor_subcmds - QCA nl80211 vendor command identifiers
 *
 * @QCA_NL80211_VENDOR_SUBCMD_UNSPEC: Reserved value 0
 *
 * @QCA_NL80211_VENDOR_SUBCMD_TEST: Test command/event
 *
 * @QCA_NL80211_VENDOR_SUBCMD_ROAMING: Set roaming policy for drivers that use
 *	internal BSS-selection. This command uses
 *	@QCA_WLAN_VENDOR_ATTR_ROAMING_POLICY to specify the new roaming policy
 *	for the current connection (i.e., changes policy set by the nl80211
 *	Connect command). @QCA_WLAN_VENDOR_ATTR_MAC_ADDR may optionally be
 *	included to indicate which BSS to use in case roaming is disabled.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_AVOID_FREQUENCY: Recommendation of frequency
 *	ranges to avoid to reduce issues due to interference or internal
 *	co-existence information in the driver. The event data structure is
 *	defined in struct qca_avoid_freq_list.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_DFS_CAPABILITY: Command to check driver support
 *	for DFS offloading.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_NAN: NAN command/event which is used to pass
 *	NAN Request/Response and NAN Indication messages. These messages are
 *	interpreted between the framework and the firmware component.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_KEY_MGMT_SET_KEY: Set key operation that can be
 *	used to configure PMK to the driver even when not connected. This can
 *	be used to request offloading of key management operations. Only used
 *	if device supports QCA_WLAN_VENDOR_FEATURE_KEY_MGMT_OFFLOAD.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_KEY_MGMT_ROAM_AUTH: An extended version of
 *	NL80211_CMD_ROAM event with optional attributes including information
 *	from offloaded key management operation. Uses
 *	enum qca_wlan_vendor_attr_roam_auth attributes. Only used
 *	if device supports QCA_WLAN_VENDOR_FEATURE_KEY_MGMT_OFFLOAD.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_DO_ACS: ACS command/event which is used to
 *	invoke the ACS function in device and pass selected channels to
 *	hostapd.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_GET_FEATURES: Command to get the features
 *	supported by the driver. enum qca_wlan_vendor_features defines
 *	the possible features.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_STARTED: Event used by driver,
 *	which supports DFS offloading, to indicate a channel availability check
 *	start.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_FINISHED: Event used by driver,
 *	which supports DFS offloading, to indicate a channel availability check
 *	completion.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_ABORTED: Event used by driver,
 *	which supports DFS offloading, to indicate that the channel availability
 *	check aborted, no change to the channel status.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_NOP_FINISHED: Event used by
 *	driver, which supports DFS offloading, to indicate that the
 *	Non-Occupancy Period for this channel is over, channel becomes usable.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_RADAR_DETECTED: Event used by driver,
 *	which supports DFS offloading, to indicate a radar pattern has been
 *	detected. The channel is now unusable.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_P2P_LISTEN_OFFLOAD_START: Command used to
 *	start the P2P Listen offload function in device and pass the listen
 *	channel, period, interval, count, device types, and vendor specific
 *	information elements to the device driver and firmware.
 *	Uses the attributes defines in
 *	enum qca_wlan_vendor_attr_p2p_listen_offload.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_P2P_LISTEN_OFFLOAD_STOP: Command/event used to
 *	indicate stop request/response of the P2P Listen offload function in
 *	device. As an event, it indicates either the feature stopped after it
 *	was already running or feature has actually failed to start. Uses the
 *	attributes defines in enum qca_wlan_vendor_attr_p2p_listen_offload.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_SAP_CONDITIONAL_CHAN_SWITCH: After AP starts
 *	beaconing, this sub command provides the driver, the frequencies on the
 *	5 GHz band to check for any radar activity. Driver selects one channel
 *	from this priority list provided through
 *	@QCA_WLAN_VENDOR_ATTR_SAP_CONDITIONAL_CHAN_SWITCH_FREQ_LIST and starts
 *	to check for radar activity on it. If no radar activity is detected
 *	during the channel availability check period, driver internally switches
 *	to the selected frequency of operation. If the frequency is zero, driver
 *	internally selects a channel. The status of this conditional switch is
 *	indicated through an event using the same sub command through
 *	@QCA_WLAN_VENDOR_ATTR_SAP_CONDITIONAL_CHAN_SWITCH_STATUS. Attributes are
 *	listed in qca_wlan_vendor_attr_sap_conditional_chan_switch.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_GPIO_CONFIG_COMMAND: Set GPIO pins. This uses the
 *	attributes defined in enum qca_wlan_gpio_attr.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_GET_HW_CAPABILITY: Fetch hardware capabilities.
 *	This uses @QCA_WLAN_VENDOR_ATTR_GET_HW_CAPABILITY to indicate which
 *	capabilities are to be fetched and other
 *	enum qca_wlan_vendor_attr_get_hw_capability attributes to return the
 *	requested capabilities.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_LL_STATS_EXT: Link layer statistics extension.
 *	enum qca_wlan_vendor_attr_ll_stats_ext attributes are used with this
 *	command and event.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_LOC_GET_CAPA: Get capabilities for
 *	indoor location features. Capabilities are reported in
 *	QCA_WLAN_VENDOR_ATTR_LOC_CAPA.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_FTM_START_SESSION: Start an FTM
 *	(fine timing measurement) session with one or more peers.
 *	Specify Session cookie in QCA_WLAN_VENDOR_ATTR_FTM_SESSION_COOKIE and
 *	peer information in QCA_WLAN_VENDOR_ATTR_FTM_MEAS_PEERS.
 *	On success, 0 or more QCA_NL80211_VENDOR_SUBCMD_FTM_MEAS_RESULT
 *	events will be reported, followed by
 *	QCA_NL80211_VENDOR_SUBCMD_FTM_SESSION_DONE event to indicate
 *	end of session.
 *	Refer to IEEE P802.11-REVmc/D7.0, 11.24.6
 *
 * @QCA_NL80211_VENDOR_SUBCMD_FTM_ABORT_SESSION: Abort a running session.
 *	A QCA_NL80211_VENDOR_SUBCMD_FTM_SESSION_DONE will be reported with
 *	status code indicating session was aborted.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_FTM_MEAS_RESULT: Event with measurement
 *	results for one peer. Results are reported in
 *	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_PEER_RESULTS.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_FTM_SESSION_DONE: Event triggered when
 *	FTM session is finished, either successfully or aborted by
 *	request.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_FTM_CFG_RESPONDER: Configure FTM responder
 *	mode. QCA_WLAN_VENDOR_ATTR_FTM_RESPONDER_ENABLE specifies whether
 *	to enable or disable the responder. LCI/LCR reports can be
 *	configured with QCA_WLAN_VENDOR_ATTR_FTM_LCI and
 *	QCA_WLAN_VENDOR_ATTR_FTM_LCR. Can be called multiple
 *	times to update the LCI/LCR reports.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_AOA_MEAS: Perform a standalone AOA (angle of
 *	arrival) measurement with a single peer. Specify peer MAC address in
 *	QCA_WLAN_VENDOR_ATTR_MAC_ADDR and optionally frequency (MHz) in
 *	QCA_WLAN_VENDOR_ATTR_FREQ (if not specified, locate peer in kernel
 *	scan results cache and use the frequency from there).
 *	Also specify measurement type in QCA_WLAN_VENDOR_ATTR_AOA_TYPE.
 *	Measurement result is reported in
 *	QCA_NL80211_VENDOR_SUBCMD_AOA_MEAS_RESULT event.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_AOA_ABORT_MEAS: Abort an AOA measurement. Specify
 *	peer MAC address in QCA_WLAN_VENDOR_ATTR_MAC_ADDR.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_AOA_MEAS_RESULT: Event that reports
 *	the AOA measurement result.
 *	Peer MAC address reported in QCA_WLAN_VENDOR_ATTR_MAC_ADDR.
 *	success/failure status is reported in
 *	QCA_WLAN_VENDOR_ATTR_LOC_SESSION_STATUS.
 *	Measurement data is reported in QCA_WLAN_VENDOR_ATTR_AOA_MEAS_RESULT.
 *	The antenna array(s) used in the measurement are reported in
 *	QCA_WLAN_VENDOR_ATTR_LOC_ANTENNA_ARRAY_MASK.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_ENCRYPTION_TEST: Encrypt/decrypt the given
 *	data as per the given parameters.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_GET_CHAIN_RSSI: Get antenna RSSI value for a
 *	specific chain.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_DMG_RF_GET_SECTOR_CFG: Get low level
 *	configuration for a DMG RF sector. Specify sector index in
 *	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_INDEX, sector type in
 *	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_TYPE and RF modules
 *	to return sector information for in
 *	QCA_WLAN_VENDOR_ATTR_DMG_RF_MODULE_MASK. Returns sector configuration
 *	in QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG. Also return the
 *	exact time where information was captured in
 *	QCA_WLAN_VENDOR_ATTR_TSF.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_DMG_RF_SET_SECTOR_CFG: Set low level
 *	configuration for a DMG RF sector. Specify sector index in
 *	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_INDEX, sector type in
 *	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_TYPE and sector configuration
 *	for one or more DMG RF modules in
 *	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_DMG_RF_GET_SELECTED_SECTOR: Get selected
 *	DMG RF sector for a station. This is the sector that the HW
 *	will use to communicate with the station. Specify the MAC address
 *	of associated station/AP/PCP in QCA_WLAN_VENDOR_ATTR_MAC_ADDR (not
 *	needed for unassociated	station). Specify sector type to return in
 *	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_TYPE. Returns the selected
 *	sector index in QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_INDEX.
 *	Also return the exact time where the information was captured
 *	in QCA_WLAN_VENDOR_ATTR_TSF.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_DMG_RF_SET_SELECTED_SECTOR: Set the
 *	selected DMG RF sector for a station. This is the sector that
 *	the HW will use to communicate with the station.
 *	Specify the MAC address of associated station/AP/PCP in
 *	QCA_WLAN_VENDOR_ATTR_MAC_ADDR, the sector type to select in
 *	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_TYPE and the sector index
 *	in QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_INDEX.
 *	The selected sector will be locked such that it will not be
 *	modified like it normally does (for example when station
 *	moves around). To unlock the selected sector for a station
 *	pass the special value 0xFFFF in the sector index. To unlock
 *	all connected stations also pass a broadcast MAC address.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_CONFIGURE_TDLS: Configure the TDLS behavior
 *	in the host driver. The different TDLS configurations are defined
 *	by the attributes in enum qca_wlan_vendor_attr_tdls_configuration.
 *
 * @QCA_NL80211_VENDOR_SUBCMD_ABORT_SCAN: Abort an ongoing vendor scan that was
 *	started with QCA_NL80211_VENDOR_SUBCMD_TRIGGER_SCAN. This command
 *	carries the scan cookie of the corresponding scan request. The scan
 *	cookie is represented by QCA_WLAN_VENDOR_ATTR_SCAN_COOKIE.
 */
enum qca_nl80211_vendor_subcmds {
	QCA_NL80211_VENDOR_SUBCMD_UNSPEC = 0,
	QCA_NL80211_VENDOR_SUBCMD_TEST = 1,
	/* subcmds 2..8 not yet allocated */
	QCA_NL80211_VENDOR_SUBCMD_ROAMING = 9,
	QCA_NL80211_VENDOR_SUBCMD_AVOID_FREQUENCY = 10,
	QCA_NL80211_VENDOR_SUBCMD_DFS_CAPABILITY =  11,
	QCA_NL80211_VENDOR_SUBCMD_NAN =  12,
	QCA_NL80211_VENDOR_SUBCMD_STATS_EXT = 13,
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_SET = 14,
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_GET = 15,
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_CLR = 16,
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_RADIO_RESULTS = 17,
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_IFACE_RESULTS = 18,
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_PEERS_RESULTS = 19,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_START = 20,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_STOP = 21,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_GET_VALID_CHANNELS = 22,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_GET_CAPABILITIES = 23,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_GET_CACHED_RESULTS = 24,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_SCAN_RESULTS_AVAILABLE = 25,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_FULL_SCAN_RESULT = 26,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_SCAN_EVENT = 27,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_HOTLIST_AP_FOUND = 28,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_SET_BSSID_HOTLIST = 29,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_RESET_BSSID_HOTLIST = 30,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_SIGNIFICANT_CHANGE = 31,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_SET_SIGNIFICANT_CHANGE = 32,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_RESET_SIGNIFICANT_CHANGE = 33,
	QCA_NL80211_VENDOR_SUBCMD_TDLS_ENABLE = 34,
	QCA_NL80211_VENDOR_SUBCMD_TDLS_DISABLE = 35,
	QCA_NL80211_VENDOR_SUBCMD_TDLS_GET_STATUS = 36,
	QCA_NL80211_VENDOR_SUBCMD_TDLS_STATE = 37,
	QCA_NL80211_VENDOR_SUBCMD_GET_SUPPORTED_FEATURES = 38,
	QCA_NL80211_VENDOR_SUBCMD_SCANNING_MAC_OUI = 39,
	QCA_NL80211_VENDOR_SUBCMD_NO_DFS_FLAG = 40,
	QCA_NL80211_VENDOR_SUBCMD_GSCAN_HOTLIST_AP_LOST = 41,
	QCA_NL80211_VENDOR_SUBCMD_GET_CONCURRENCY_MATRIX = 42,
	/* 43..49 - reserved for QCA */
	QCA_NL80211_VENDOR_SUBCMD_KEY_MGMT_SET_KEY = 50,
	QCA_NL80211_VENDOR_SUBCMD_KEY_MGMT_ROAM_AUTH = 51,
	QCA_NL80211_VENDOR_SUBCMD_APFIND = 52,
	/* 53 - reserved - was used by QCA, but not in use anymore */
	QCA_NL80211_VENDOR_SUBCMD_DO_ACS = 54,
	QCA_NL80211_VENDOR_SUBCMD_GET_FEATURES = 55,
	QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_STARTED = 56,
	QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_FINISHED = 57,
	QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_ABORTED = 58,
	QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_CAC_NOP_FINISHED = 59,
	QCA_NL80211_VENDOR_SUBCMD_DFS_OFFLOAD_RADAR_DETECTED = 60,
	/* 61-73 - reserved for QCA */
	/* Wi-Fi configuration subcommands */
	QCA_NL80211_VENDOR_SUBCMD_SET_WIFI_CONFIGURATION = 74,
	QCA_NL80211_VENDOR_SUBCMD_GET_WIFI_CONFIGURATION = 75,
	/* 76-90 - reserved for QCA */
	QCA_NL80211_VENDOR_SUBCMD_DATA_OFFLOAD = 91,
	QCA_NL80211_VENDOR_SUBCMD_OCB_SET_CONFIG = 92,
	QCA_NL80211_VENDOR_SUBCMD_OCB_SET_UTC_TIME = 93,
	QCA_NL80211_VENDOR_SUBCMD_OCB_START_TIMING_ADVERT = 94,
	QCA_NL80211_VENDOR_SUBCMD_OCB_STOP_TIMING_ADVERT = 95,
	QCA_NL80211_VENDOR_SUBCMD_OCB_GET_TSF_TIMER = 96,
	QCA_NL80211_VENDOR_SUBCMD_DCC_GET_STATS = 97,
	QCA_NL80211_VENDOR_SUBCMD_DCC_CLEAR_STATS = 98,
	QCA_NL80211_VENDOR_SUBCMD_DCC_UPDATE_NDL = 99,
	QCA_NL80211_VENDOR_SUBCMD_DCC_STATS_EVENT = 100,
	QCA_NL80211_VENDOR_SUBCMD_LINK_PROPERTIES = 101,
	QCA_NL80211_VENDOR_SUBCMD_GW_PARAM_CONFIG = 102,
	QCA_NL80211_VENDOR_SUBCMD_GET_PREFERRED_FREQ_LIST = 103,
	QCA_NL80211_VENDOR_SUBCMD_SET_PROBABLE_OPER_CHANNEL = 104,
	QCA_NL80211_VENDOR_SUBCMD_SETBAND = 105,
	QCA_NL80211_VENDOR_SUBCMD_TRIGGER_SCAN = 106,
	QCA_NL80211_VENDOR_SUBCMD_SCAN_DONE = 107,
	QCA_NL80211_VENDOR_SUBCMD_OTA_TEST = 108,
	QCA_NL80211_VENDOR_SUBCMD_SET_TXPOWER_SCALE = 109,
	/* 110..114 - reserved for QCA */
	QCA_NL80211_VENDOR_SUBCMD_SET_TXPOWER_DECR_DB = 115,
	/* 116..117 - reserved for QCA */
	QCA_NL80211_VENDOR_SUBCMD_SET_SAP_CONFIG = 118,
	QCA_NL80211_VENDOR_SUBCMD_TSF = 119,
	QCA_NL80211_VENDOR_SUBCMD_WISA = 120,
	/* 121 - reserved for QCA */
	QCA_NL80211_VENDOR_SUBCMD_P2P_LISTEN_OFFLOAD_START = 122,
	QCA_NL80211_VENDOR_SUBCMD_P2P_LISTEN_OFFLOAD_STOP = 123,
	QCA_NL80211_VENDOR_SUBCMD_SAP_CONDITIONAL_CHAN_SWITCH = 124,
	QCA_NL80211_VENDOR_SUBCMD_GPIO_CONFIG_COMMAND = 125,
	QCA_NL80211_VENDOR_SUBCMD_GET_HW_CAPABILITY = 126,
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_EXT = 127,
	/* FTM/indoor location subcommands */
	QCA_NL80211_VENDOR_SUBCMD_LOC_GET_CAPA = 128,
	QCA_NL80211_VENDOR_SUBCMD_FTM_START_SESSION = 129,
	QCA_NL80211_VENDOR_SUBCMD_FTM_ABORT_SESSION = 130,
	QCA_NL80211_VENDOR_SUBCMD_FTM_MEAS_RESULT = 131,
	QCA_NL80211_VENDOR_SUBCMD_FTM_SESSION_DONE = 132,
	QCA_NL80211_VENDOR_SUBCMD_FTM_CFG_RESPONDER = 133,
	QCA_NL80211_VENDOR_SUBCMD_AOA_MEAS = 134,
	QCA_NL80211_VENDOR_SUBCMD_AOA_ABORT_MEAS = 135,
	QCA_NL80211_VENDOR_SUBCMD_AOA_MEAS_RESULT = 136,
	QCA_NL80211_VENDOR_SUBCMD_ENCRYPTION_TEST = 137,
	QCA_NL80211_VENDOR_SUBCMD_GET_CHAIN_RSSI = 138,
	/* DMG low level RF sector operations */
	QCA_NL80211_VENDOR_SUBCMD_DMG_RF_GET_SECTOR_CFG = 139,
	QCA_NL80211_VENDOR_SUBCMD_DMG_RF_SET_SECTOR_CFG = 140,
	QCA_NL80211_VENDOR_SUBCMD_DMG_RF_GET_SELECTED_SECTOR = 141,
	QCA_NL80211_VENDOR_SUBCMD_DMG_RF_SET_SELECTED_SECTOR = 142,
	QCA_NL80211_VENDOR_SUBCMD_CONFIGURE_TDLS = 143,
	/* 144 - reserved for QCA */
	QCA_NL80211_VENDOR_SUBCMD_ABORT_SCAN = 145,
};


enum qca_wlan_vendor_attr {
	QCA_WLAN_VENDOR_ATTR_INVALID = 0,
	/* used by QCA_NL80211_VENDOR_SUBCMD_DFS_CAPABILITY */
	QCA_WLAN_VENDOR_ATTR_DFS     = 1,
	/* used by QCA_NL80211_VENDOR_SUBCMD_NAN */
	QCA_WLAN_VENDOR_ATTR_NAN     = 2,
	/* used by QCA_NL80211_VENDOR_SUBCMD_STATS_EXT */
	QCA_WLAN_VENDOR_ATTR_STATS_EXT     = 3,
	/* used by QCA_NL80211_VENDOR_SUBCMD_STATS_EXT */
	QCA_WLAN_VENDOR_ATTR_IFINDEX     = 4,
	/* used by QCA_NL80211_VENDOR_SUBCMD_ROAMING, u32 with values defined
	 * by enum qca_roaming_policy. */
	QCA_WLAN_VENDOR_ATTR_ROAMING_POLICY = 5,
	QCA_WLAN_VENDOR_ATTR_MAC_ADDR = 6,
	/* used by QCA_NL80211_VENDOR_SUBCMD_GET_FEATURES */
	QCA_WLAN_VENDOR_ATTR_FEATURE_FLAGS = 7,
	QCA_WLAN_VENDOR_ATTR_TEST = 8,
	/* used by QCA_NL80211_VENDOR_SUBCMD_GET_FEATURES */
	/* Unsigned 32-bit value. */
	QCA_WLAN_VENDOR_ATTR_CONCURRENCY_CAPA = 9,
	/* Unsigned 32-bit value */
	QCA_WLAN_VENDOR_ATTR_MAX_CONCURRENT_CHANNELS_2_4_BAND = 10,
	/* Unsigned 32-bit value */
	QCA_WLAN_VENDOR_ATTR_MAX_CONCURRENT_CHANNELS_5_0_BAND = 11,
	/* Unsigned 32-bit value from enum qca_set_band. */
	QCA_WLAN_VENDOR_ATTR_SETBAND_VALUE = 12,
	/* Dummy (NOP) attribute for 64 bit padding */
	QCA_WLAN_VENDOR_ATTR_PAD = 13,
	/* Unique FTM session cookie (Unsigned 64 bit). Specified in
	 * QCA_NL80211_VENDOR_SUBCMD_FTM_START_SESSION. Reported in
	 * the session in QCA_NL80211_VENDOR_SUBCMD_FTM_MEAS_RESULT and
	 * QCA_NL80211_VENDOR_SUBCMD_FTM_SESSION_DONE.
	 */
	QCA_WLAN_VENDOR_ATTR_FTM_SESSION_COOKIE = 14,
	/* Indoor location capabilities, returned by
	 * QCA_NL80211_VENDOR_SUBCMD_LOC_GET_CAPA.
	 * see enum qca_wlan_vendor_attr_loc_capa.
	 */
	QCA_WLAN_VENDOR_ATTR_LOC_CAPA = 15,
	/* Array of nested attributes containing information about each peer
	 * in FTM measurement session. See enum qca_wlan_vendor_attr_peer_info
	 * for supported attributes for each peer.
	 */
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_PEERS = 16,
	/* Array of nested attributes containing measurement results for
	 * one or more peers, reported by the
	 * QCA_NL80211_VENDOR_SUBCMD_FTM_MEAS_RESULT event.
	 * See enum qca_wlan_vendor_attr_peer_result for list of supported
	 * attributes.
	 */
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_PEER_RESULTS = 17,
	/* Flag attribute for enabling or disabling responder functionality. */
	QCA_WLAN_VENDOR_ATTR_FTM_RESPONDER_ENABLE = 18,
	/* Used in the QCA_NL80211_VENDOR_SUBCMD_FTM_CFG_RESPONDER
	 * command to specify the LCI report that will be sent by
	 * the responder during a measurement exchange. The format is
	 * defined in IEEE P802.11-REVmc/D7.0, 9.4.2.22.10.
	 */
	QCA_WLAN_VENDOR_ATTR_FTM_LCI = 19,
	/* Used in the QCA_NL80211_VENDOR_SUBCMD_FTM_CFG_RESPONDER
	 * command to specify the location civic report that will
	 * be sent by the responder during a measurement exchange.
	 * The format is defined in IEEE P802.11-REVmc/D7.0, 9.4.2.22.13.
	 */
	QCA_WLAN_VENDOR_ATTR_FTM_LCR = 20,
	/* Session/measurement completion status code,
	 * reported in QCA_NL80211_VENDOR_SUBCMD_FTM_SESSION_DONE and
	 * QCA_NL80211_VENDOR_SUBCMD_AOA_MEAS_RESULT
	 * see enum qca_vendor_attr_loc_session_status.
	 */
	QCA_WLAN_VENDOR_ATTR_LOC_SESSION_STATUS = 21,
	/* Initial dialog token used by responder (0 if not specified),
	 * unsigned 8 bit value.
	 */
	QCA_WLAN_VENDOR_ATTR_FTM_INITIAL_TOKEN = 22,
	/* AOA measurement type. Requested in QCA_NL80211_VENDOR_SUBCMD_AOA_MEAS
	 * and optionally in QCA_NL80211_VENDOR_SUBCMD_FTM_START_SESSION if
	 * AOA measurements are needed as part of an FTM session.
	 * Reported by QCA_NL80211_VENDOR_SUBCMD_AOA_MEAS_RESULT. See
	 * enum qca_wlan_vendor_attr_aoa_type.
	 */
	QCA_WLAN_VENDOR_ATTR_AOA_TYPE = 23,
	/* A bit mask (unsigned 32 bit value) of antenna arrays used
	 * by indoor location measurements. Refers to the antenna
	 * arrays described by QCA_VENDOR_ATTR_LOC_CAPA_ANTENNA_ARRAYS.
	 */
	QCA_WLAN_VENDOR_ATTR_LOC_ANTENNA_ARRAY_MASK = 24,
	/* AOA measurement data. Its contents depends on the AOA measurement
	 * type and antenna array mask:
	 * QCA_WLAN_VENDOR_ATTR_AOA_TYPE_TOP_CIR_PHASE: array of U16 values,
	 * phase of the strongest CIR path for each antenna in the measured
	 * array(s).
	 * QCA_WLAN_VENDOR_ATTR_AOA_TYPE_TOP_CIR_PHASE_AMP: array of 2 U16
	 * values, phase and amplitude of the strongest CIR path for each
	 * antenna in the measured array(s).
	 */
	QCA_WLAN_VENDOR_ATTR_AOA_MEAS_RESULT = 25,
	/* Used in QCA_NL80211_VENDOR_SUBCMD_GET_CHAIN_RSSI command
	 * to specify the chain number (unsigned 32 bit value) to inquire
	 * the corresponding antenna RSSI value */
	QCA_WLAN_VENDOR_ATTR_CHAIN_INDEX = 26,
	/* Used in QCA_NL80211_VENDOR_SUBCMD_GET_CHAIN_RSSI command
	 * to report the specific antenna RSSI value (unsigned 32 bit value) */
	QCA_WLAN_VENDOR_ATTR_CHAIN_RSSI = 27,
	/* Frequency in MHz, various uses. Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_FREQ = 28,
	/* TSF timer value, unsigned 64 bit value.
	 * May be returned by various commands.
	 */
	QCA_WLAN_VENDOR_ATTR_TSF = 29,
	/* DMG RF sector index, unsigned 16 bit number. Valid values are
	 * 0..127 for sector indices or 65535 as special value used to
	 * unlock sector selection in
	 * QCA_NL80211_VENDOR_SUBCMD_DMG_RF_SET_SELECTED_SECTOR.
	 */
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_INDEX = 30,
	/* DMG RF sector type, unsigned 8 bit value. One of the values
	 * in enum qca_wlan_vendor_attr_dmg_rf_sector_type.
	 */
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_TYPE = 31,
	/* Bitmask of DMG RF modules for which information is requested. Each
	 * bit corresponds to an RF module with the same index as the bit
	 * number. Unsigned 32 bit number but only low 8 bits can be set since
	 * all DMG chips currently have up to 8 RF modules.
	 */
	QCA_WLAN_VENDOR_ATTR_DMG_RF_MODULE_MASK = 32,
	/* Array of nested attributes where each entry is DMG RF sector
	 * configuration for a single RF module.
	 * Attributes for each entry are taken from enum
	 * qca_wlan_vendor_attr_dmg_rf_sector_cfg.
	 * Specified in QCA_NL80211_VENDOR_SUBCMD_DMG_RF_SET_SECTOR_CFG
	 * and returned by QCA_NL80211_VENDOR_SUBCMD_DMG_RF_GET_SECTOR_CFG.
	 */
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG = 33,
	/* Used in QCA_NL80211_VENDOR_SUBCMD_STATS_EXT command
	 * to report frame aggregation statistics to userspace.
	 */
	QCA_WLAN_VENDOR_ATTR_RX_AGGREGATION_STATS_HOLES_NUM = 34,
	QCA_WLAN_VENDOR_ATTR_RX_AGGREGATION_STATS_HOLES_INFO = 35,

	/* keep last */
	QCA_WLAN_VENDOR_ATTR_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_MAX	= QCA_WLAN_VENDOR_ATTR_AFTER_LAST - 1,
};


enum qca_roaming_policy {
	QCA_ROAMING_NOT_ALLOWED,
	QCA_ROAMING_ALLOWED_WITHIN_ESS,
};

enum qca_wlan_vendor_attr_roam_auth {
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_INVALID = 0,
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_BSSID,
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_REQ_IE,
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_RESP_IE,
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_AUTHORIZED,
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_KEY_REPLAY_CTR,
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_PTK_KCK,
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_PTK_KEK,
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_SUBNET_STATUS,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_MAX =
	QCA_WLAN_VENDOR_ATTR_ROAM_AUTH_AFTER_LAST - 1
};

enum qca_wlan_vendor_attr_p2p_listen_offload {
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_INVALID = 0,
	/* A 32-bit unsigned value; the P2P listen frequency (MHz); must be one
	 * of the social channels.
	 */
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_CHANNEL,
	/* A 32-bit unsigned value; the P2P listen offload period (ms).
	 */
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_PERIOD,
	/* A 32-bit unsigned value; the P2P listen interval duration (ms).
	 */
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_INTERVAL,
	/* A 32-bit unsigned value; number of interval times the firmware needs
	 * to run the offloaded P2P listen operation before it stops.
	 */
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_COUNT,
	/* An array of arbitrary binary data with one or more 8-byte values.
	 * The device types include both primary and secondary device types.
	 */
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_DEVICE_TYPES,
	/* An array of unsigned 8-bit characters; vendor information elements.
	 */
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_VENDOR_IE,
	/* A 32-bit unsigned value; a control flag to indicate whether listen
	 * results need to be flushed to wpa_supplicant.
	 */
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_CTRL_FLAG,
	/* A 8-bit unsigned value; reason code for P2P listen offload stop
	 * event.
	 */
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_STOP_REASON,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_MAX =
	QCA_WLAN_VENDOR_ATTR_P2P_LISTEN_OFFLOAD_AFTER_LAST - 1
};

enum qca_wlan_vendor_attr_acs_offload {
	QCA_WLAN_VENDOR_ATTR_ACS_CHANNEL_INVALID = 0,
	QCA_WLAN_VENDOR_ATTR_ACS_PRIMARY_CHANNEL,
	QCA_WLAN_VENDOR_ATTR_ACS_SECONDARY_CHANNEL,
	QCA_WLAN_VENDOR_ATTR_ACS_HW_MODE,
	QCA_WLAN_VENDOR_ATTR_ACS_HT_ENABLED,
	QCA_WLAN_VENDOR_ATTR_ACS_HT40_ENABLED,
	QCA_WLAN_VENDOR_ATTR_ACS_VHT_ENABLED,
	QCA_WLAN_VENDOR_ATTR_ACS_CHWIDTH,
	QCA_WLAN_VENDOR_ATTR_ACS_CH_LIST,
	QCA_WLAN_VENDOR_ATTR_ACS_VHT_SEG0_CENTER_CHANNEL,
	QCA_WLAN_VENDOR_ATTR_ACS_VHT_SEG1_CENTER_CHANNEL,
	QCA_WLAN_VENDOR_ATTR_ACS_FREQ_LIST,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_ACS_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_ACS_MAX =
	QCA_WLAN_VENDOR_ATTR_ACS_AFTER_LAST - 1
};

enum qca_wlan_vendor_acs_hw_mode {
	QCA_ACS_MODE_IEEE80211B,
	QCA_ACS_MODE_IEEE80211G,
	QCA_ACS_MODE_IEEE80211A,
	QCA_ACS_MODE_IEEE80211AD,
	QCA_ACS_MODE_IEEE80211ANY,
};

/**
 * enum qca_wlan_vendor_features - Vendor device/driver feature flags
 *
 * @QCA_WLAN_VENDOR_FEATURE_KEY_MGMT_OFFLOAD: Device supports key
 *	management offload, a mechanism where the station's firmware
 *	does the exchange with the AP to establish the temporal keys
 *	after roaming, rather than having the user space wpa_supplicant do it.
 * @QCA_WLAN_VENDOR_FEATURE_SUPPORT_HW_MODE_ANY: Device supports automatic
 *	band selection based on channel selection results.
 * @QCA_WLAN_VENDOR_FEATURE_OFFCHANNEL_SIMULTANEOUS: Device supports
 * 	simultaneous off-channel operations.
 * @QCA_WLAN_VENDOR_FEATURE_P2P_LISTEN_OFFLOAD: Device supports P2P
 *	Listen offload; a mechanism where the station's firmware takes care of
 *	responding to incoming Probe Request frames received from other P2P
 *	Devices whilst in Listen state, rather than having the user space
 *	wpa_supplicant do it. Information from received P2P requests are
 *	forwarded from firmware to host whenever the host processor wakes up.
 * @NUM_QCA_WLAN_VENDOR_FEATURES: Number of assigned feature bits
 */
enum qca_wlan_vendor_features {
	QCA_WLAN_VENDOR_FEATURE_KEY_MGMT_OFFLOAD	= 0,
	QCA_WLAN_VENDOR_FEATURE_SUPPORT_HW_MODE_ANY     = 1,
	QCA_WLAN_VENDOR_FEATURE_OFFCHANNEL_SIMULTANEOUS = 2,
	QCA_WLAN_VENDOR_FEATURE_P2P_LISTEN_OFFLOAD	= 3,
	NUM_QCA_WLAN_VENDOR_FEATURES /* keep last */
};

/**
 * enum qca_wlan_vendor_attr_data_offload_ind - Vendor Data Offload Indication
 *
 * @QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_SESSION: Session corresponding to
 *	the offloaded data.
 * @QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_PROTOCOL: Protocol of the offloaded
 *	data.
 * @QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_EVENT: Event type for the data offload
 *	indication.
 */
enum qca_wlan_vendor_attr_data_offload_ind {
	QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_INVALID = 0,
	QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_SESSION,
	QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_PROTOCOL,
	QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_EVENT,

	/* keep last */
	QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_MAX =
	QCA_WLAN_VENDOR_ATTR_DATA_OFFLOAD_IND_AFTER_LAST - 1
};

enum qca_vendor_attr_get_preferred_freq_list {
	QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST_INVALID,
	/* A 32-unsigned value; the interface type/mode for which the preferred
	 * frequency list is requested (see enum qca_iface_type for possible
	 * values); used in GET_PREFERRED_FREQ_LIST command from user-space to
	 * kernel and in the kernel response back to user-space.
	 */
	QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST_IFACE_TYPE,
	/* An array of 32-unsigned values; values are frequency (MHz); sent
	 * from kernel space to user space.
	 */
	QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST_MAX =
	QCA_WLAN_VENDOR_ATTR_GET_PREFERRED_FREQ_LIST_AFTER_LAST - 1
};

enum qca_vendor_attr_probable_oper_channel {
	QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_INVALID,
	/* 32-bit unsigned value; indicates the connection/iface type likely to
	 * come on this channel (see enum qca_iface_type).
	 */
	QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_IFACE_TYPE,
	/* 32-bit unsigned value; the frequency (MHz) of the probable channel */
	QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_FREQ,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_MAX =
	QCA_WLAN_VENDOR_ATTR_PROBABLE_OPER_CHANNEL_AFTER_LAST - 1
};

enum qca_iface_type {
	QCA_IFACE_TYPE_STA,
	QCA_IFACE_TYPE_AP,
	QCA_IFACE_TYPE_P2P_CLIENT,
	QCA_IFACE_TYPE_P2P_GO,
	QCA_IFACE_TYPE_IBSS,
	QCA_IFACE_TYPE_TDLS,
};

enum qca_set_band {
	QCA_SETBAND_AUTO,
	QCA_SETBAND_5G,
	QCA_SETBAND_2G,
};

/**
 * enum qca_access_policy - Access control policy
 *
 * Access control policy is applied on the configured IE
 * (QCA_WLAN_VENDOR_ATTR_CONFIG_ACCESS_POLICY_IE).
 * To be set with QCA_WLAN_VENDOR_ATTR_CONFIG_ACCESS_POLICY.
 *
 * @QCA_ACCESS_POLICY_ACCEPT_UNLESS_LISTED: Deny Wi-Fi connections which match
 *	the specific configuration (IE) set, i.e., allow all the
 *	connections which do not match the configuration.
 * @QCA_ACCESS_POLICY_DENY_UNLESS_LISTED: Accept Wi-Fi connections which match
 *	the specific configuration (IE) set, i.e., deny all the
 *	connections which do not match the configuration.
 */
enum qca_access_policy {
	QCA_ACCESS_POLICY_ACCEPT_UNLESS_LISTED,
	QCA_ACCESS_POLICY_DENY_UNLESS_LISTED,
};

/**
 * enum qca_vendor_attr_get_tsf: Vendor attributes for TSF capture
 * @QCA_WLAN_VENDOR_ATTR_TSF_CMD: enum qca_tsf_operation (u32)
 * @QCA_WLAN_VENDOR_ATTR_TSF_TIMER_VALUE: Unsigned 64 bit TSF timer value
 * @QCA_WLAN_VENDOR_ATTR_TSF_SOC_TIMER_VALUE: Unsigned 64 bit Synchronized
 *	SOC timer value at TSF capture
 */
enum qca_vendor_attr_tsf_cmd {
	QCA_WLAN_VENDOR_ATTR_TSF_INVALID = 0,
	QCA_WLAN_VENDOR_ATTR_TSF_CMD,
	QCA_WLAN_VENDOR_ATTR_TSF_TIMER_VALUE,
	QCA_WLAN_VENDOR_ATTR_TSF_SOC_TIMER_VALUE,
	QCA_WLAN_VENDOR_ATTR_TSF_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_TSF_MAX =
	QCA_WLAN_VENDOR_ATTR_TSF_AFTER_LAST - 1
};

/**
 * enum qca_tsf_operation: TSF driver commands
 * @QCA_TSF_CAPTURE: Initiate TSF Capture
 * @QCA_TSF_GET: Get TSF capture value
 * @QCA_TSF_SYNC_GET: Initiate TSF capture and return with captured value
 */
enum qca_tsf_cmd {
	QCA_TSF_CAPTURE,
	QCA_TSF_GET,
	QCA_TSF_SYNC_GET,
};

/**
 * enum qca_vendor_attr_wisa_cmd
 * @QCA_WLAN_VENDOR_ATTR_WISA_MODE: WISA mode value (u32)
 * WISA setup vendor commands
 */
enum qca_vendor_attr_wisa_cmd {
	QCA_WLAN_VENDOR_ATTR_WISA_INVALID = 0,
	QCA_WLAN_VENDOR_ATTR_WISA_MODE,
	QCA_WLAN_VENDOR_ATTR_WISA_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_WISA_MAX =
	QCA_WLAN_VENDOR_ATTR_WISA_AFTER_LAST - 1
};

/* IEEE 802.11 Vendor Specific elements */

/**
 * enum qca_vendor_element_id - QCA Vendor Specific element types
 *
 * These values are used to identify QCA Vendor Specific elements. The
 * payload of the element starts with the three octet OUI (OUI_QCA) and
 * is followed by a single octet type which is defined by this enum.
 *
 * @QCA_VENDOR_ELEM_P2P_PREF_CHAN_LIST: P2P preferred channel list.
 *	This element can be used to specify preference order for supported
 *	channels. The channels in this list are in preference order (the first
 *	one has the highest preference) and are described as a pair of
 *	(global) Operating Class and Channel Number (each one octet) fields.
 *
 *	This extends the standard P2P functionality by providing option to have
 *	more than one preferred operating channel. When this element is present,
 *	it replaces the preference indicated in the Operating Channel attribute.
 *	For supporting other implementations, the Operating Channel attribute is
 *	expected to be used with the highest preference channel. Similarly, all
 *	the channels included in this Preferred channel list element are
 *	expected to be included in the Channel List attribute.
 *
 *	This vendor element may be included in GO Negotiation Request, P2P
 *	Invitation Request, and Provision Discovery Request frames.
 *
 * @QCA_VENDOR_ELEM_HE_CAPAB: HE Capabilities element.
 *	This element can be used for pre-standard publication testing of HE
 *	before P802.11ax draft assigns the element ID. The payload of this
 *	vendor specific element is defined by the latest P802.11ax draft.
 *	Please note that the draft is still work in progress and this element
 *	payload is subject to change.
 *
 * @QCA_VENDOR_ELEM_HE_OPER: HE Operation element.
 *	This element can be used for pre-standard publication testing of HE
 *	before P802.11ax draft assigns the element ID. The payload of this
 *	vendor specific element is defined by the latest P802.11ax draft.
 *	Please note that the draft is still work in progress and this element
 *	payload is subject to change.
 */
enum qca_vendor_element_id {
	QCA_VENDOR_ELEM_P2P_PREF_CHAN_LIST = 0,
	QCA_VENDOR_ELEM_HE_CAPAB = 1,
	QCA_VENDOR_ELEM_HE_OPER = 2,
};

/**
 * enum qca_wlan_vendor_attr_scan - Specifies vendor scan attributes
 *
 * @QCA_WLAN_VENDOR_ATTR_SCAN_IE: IEs that should be included as part of scan
 * @QCA_WLAN_VENDOR_ATTR_SCAN_FREQUENCIES: Nested unsigned 32-bit attributes
 *	with frequencies to be scanned (in MHz)
 * @QCA_WLAN_VENDOR_ATTR_SCAN_SSIDS: Nested attribute with SSIDs to be scanned
 * @QCA_WLAN_VENDOR_ATTR_SCAN_SUPP_RATES: Nested array attribute of supported
 *	rates to be included
 * @QCA_WLAN_VENDOR_ATTR_SCAN_TX_NO_CCK_RATE: flag used to send probe requests
 * 	at non CCK rate in 2GHz band
 * @QCA_WLAN_VENDOR_ATTR_SCAN_FLAGS: Unsigned 32-bit scan flags
 * @QCA_WLAN_VENDOR_ATTR_SCAN_COOKIE: Unsigned 64-bit cookie provided by the
 * 	driver for the specific scan request
 * @QCA_WLAN_VENDOR_ATTR_SCAN_STATUS: Unsigned 8-bit status of the scan
 * 	request decoded as in enum scan_status
 * @QCA_WLAN_VENDOR_ATTR_SCAN_MAC: 6-byte MAC address to use when randomisation
 * 	scan flag is set
 * @QCA_WLAN_VENDOR_ATTR_SCAN_MAC_MASK: 6-byte MAC address mask to be used with
 * 	randomisation
 */
enum qca_wlan_vendor_attr_scan {
	QCA_WLAN_VENDOR_ATTR_SCAN_INVALID_PARAM = 0,
	QCA_WLAN_VENDOR_ATTR_SCAN_IE,
	QCA_WLAN_VENDOR_ATTR_SCAN_FREQUENCIES,
	QCA_WLAN_VENDOR_ATTR_SCAN_SSIDS,
	QCA_WLAN_VENDOR_ATTR_SCAN_SUPP_RATES,
	QCA_WLAN_VENDOR_ATTR_SCAN_TX_NO_CCK_RATE,
	QCA_WLAN_VENDOR_ATTR_SCAN_FLAGS,
	QCA_WLAN_VENDOR_ATTR_SCAN_COOKIE,
	QCA_WLAN_VENDOR_ATTR_SCAN_STATUS,
	QCA_WLAN_VENDOR_ATTR_SCAN_MAC,
	QCA_WLAN_VENDOR_ATTR_SCAN_MAC_MASK,
	QCA_WLAN_VENDOR_ATTR_SCAN_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_SCAN_MAX =
	QCA_WLAN_VENDOR_ATTR_SCAN_AFTER_LAST - 1
};

/**
 * enum scan_status - Specifies the valid values the vendor scan attribute
 * 	QCA_WLAN_VENDOR_ATTR_SCAN_STATUS can take
 *
 * @VENDOR_SCAN_STATUS_NEW_RESULTS: implies the vendor scan is successful with
 * 	new scan results
 * @VENDOR_SCAN_STATUS_ABORTED: implies the vendor scan was aborted in-between
 */
enum scan_status {
	VENDOR_SCAN_STATUS_NEW_RESULTS,
	VENDOR_SCAN_STATUS_ABORTED,
	VENDOR_SCAN_STATUS_MAX,
};

/**
 * enum qca_vendor_attr_ota_test - Specifies the values for vendor
 *                       command QCA_NL80211_VENDOR_SUBCMD_OTA_TEST
 * @QCA_WLAN_VENDOR_ATTR_OTA_TEST_ENABLE: enable ota test
 */
enum qca_vendor_attr_ota_test {
	QCA_WLAN_VENDOR_ATTR_OTA_TEST_INVALID,
	/* 8-bit unsigned value to indicate if OTA test is enabled */
	QCA_WLAN_VENDOR_ATTR_OTA_TEST_ENABLE,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_OTA_TEST_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_OTA_TEST_MAX =
	QCA_WLAN_VENDOR_ATTR_OTA_TEST_AFTER_LAST - 1
};

/**
 * enum qca_vendor_attr_txpower_scale - vendor sub commands index
 *
 * @QCA_WLAN_VENDOR_ATTR_TXPOWER_SCALE: scaling value
 */
enum qca_vendor_attr_txpower_scale {
	QCA_WLAN_VENDOR_ATTR_TXPOWER_SCALE_INVALID,
	/* 8-bit unsigned value to indicate the scaling of tx power */
	QCA_WLAN_VENDOR_ATTR_TXPOWER_SCALE,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_TXPOWER_SCALE_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_TXPOWER_SCALE_MAX =
	QCA_WLAN_VENDOR_ATTR_TXPOWER_SCALE_AFTER_LAST - 1
};

/**
 * enum qca_vendor_attr_txpower_decr_db - Attributes for TX power decrease
 *
 * These attributes are used with QCA_NL80211_VENDOR_SUBCMD_SET_TXPOWER_DECR_DB.
 */
enum qca_vendor_attr_txpower_decr_db {
	QCA_WLAN_VENDOR_ATTR_TXPOWER_DECR_DB_INVALID,
	/* 8-bit unsigned value to indicate the reduction of TX power in dB for
	 * a virtual interface. */
	QCA_WLAN_VENDOR_ATTR_TXPOWER_DECR_DB,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_TXPOWER_DECR_DB_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_TXPOWER_DECR_DB_MAX =
	QCA_WLAN_VENDOR_ATTR_TXPOWER_DECR_DB_AFTER_LAST - 1
};

/* Attributes for data used by
 * QCA_NL80211_VENDOR_SUBCMD_SET_WIFI_CONFIGURATION and
 * QCA_NL80211_VENDOR_SUBCMD_GET_WIFI_CONFIGURATION subcommands.
 */
enum qca_wlan_vendor_attr_config {
	QCA_WLAN_VENDOR_ATTR_CONFIG_INVALID = 0,
	/* Unsigned 32-bit value to set the DTIM period.
	 * Whether the wifi chipset wakes at every dtim beacon or a multiple of
	 * the DTIM period. If DTIM is set to 3, the STA shall wake up every 3
	 * DTIM beacons.
	 */
	QCA_WLAN_VENDOR_ATTR_CONFIG_DYNAMIC_DTIM = 1,
	/* Unsigned 32-bit value to set the wifi_iface stats averaging factor
	 * used to calculate statistics like average the TSF offset or average
	 * number of frame leaked.
	 * For instance, upon Beacon frame reception:
	 * current_avg = ((beacon_TSF - TBTT) * factor + previous_avg * (0x10000 - factor) ) / 0x10000
	 * For instance, when evaluating leaky APs:
	 * current_avg = ((num frame received within guard time) * factor + previous_avg * (0x10000 - factor)) / 0x10000
	 */
	QCA_WLAN_VENDOR_ATTR_CONFIG_STATS_AVG_FACTOR = 2,
	/* Unsigned 32-bit value to configure guard time, i.e., when
	 * implementing IEEE power management based on frame control PM bit, how
	 * long the driver waits before shutting down the radio and after
	 * receiving an ACK frame for a Data frame with PM bit set.
	 */
	QCA_WLAN_VENDOR_ATTR_CONFIG_GUARD_TIME = 3,
	/* Unsigned 32-bit value to change the FTM capability dynamically */
	QCA_WLAN_VENDOR_ATTR_CONFIG_FINE_TIME_MEASUREMENT = 4,
	/* Unsigned 16-bit value to configure maximum TX rate dynamically */
	QCA_WLAN_VENDOR_ATTR_CONF_TX_RATE = 5,
	/* Unsigned 32-bit value to configure the number of continuous
	 * Beacon Miss which shall be used by the firmware to penalize
	 * the RSSI.
	 */
	QCA_WLAN_VENDOR_ATTR_CONFIG_PENALIZE_AFTER_NCONS_BEACON_MISS = 6,
	/* Unsigned 8-bit value to configure the channel avoidance indication
	 * behavior. Firmware to send only one indication and ignore duplicate
	 * indications when set to avoid multiple Apps wakeups.
	 */
	QCA_WLAN_VENDOR_ATTR_CONFIG_CHANNEL_AVOIDANCE_IND = 7,
	/* 8-bit unsigned value to configure the maximum TX MPDU for
	 * aggregation. */
	QCA_WLAN_VENDOR_ATTR_CONFIG_TX_MPDU_AGGREGATION = 8,
	/* 8-bit unsigned value to configure the maximum RX MPDU for
	 * aggregation. */
	QCA_WLAN_VENDOR_ATTR_CONFIG_RX_MPDU_AGGREGATION = 9,
	/* 8-bit unsigned value to configure the Non aggregrate/11g sw
	 * retry threshold (0 disable, 31 max). */
	QCA_WLAN_VENDOR_ATTR_CONFIG_NON_AGG_RETRY = 10,
	/* 8-bit unsigned value to configure the aggregrate sw
	 * retry threshold (0 disable, 31 max). */
	QCA_WLAN_VENDOR_ATTR_CONFIG_AGG_RETRY = 11,
	/* 8-bit unsigned value to configure the MGMT frame
	 * retry threshold (0 disable, 31 max). */
	QCA_WLAN_VENDOR_ATTR_CONFIG_MGMT_RETRY = 12,
	/* 8-bit unsigned value to configure the CTRL frame
	 * retry threshold (0 disable, 31 max). */
	QCA_WLAN_VENDOR_ATTR_CONFIG_CTRL_RETRY = 13,
	/* 8-bit unsigned value to configure the propagation delay for
	 * 2G/5G band (0~63, units in us) */
	QCA_WLAN_VENDOR_ATTR_CONFIG_PROPAGATION_DELAY = 14,
	/* Unsigned 32-bit value to configure the number of unicast TX fail
	 * packet count. The peer is disconnected once this threshold is
	 * reached. */
	QCA_WLAN_VENDOR_ATTR_CONFIG_TX_FAIL_COUNT = 15,
	/* Attribute used to set scan default IEs to the driver.
	 *
	 * These IEs can be used by scan operations that will be initiated by
	 * the driver/firmware.
	 *
	 * For further scan requests coming to the driver, these IEs should be
	 * merged with the IEs received along with scan request coming to the
	 * driver. If a particular IE is present in the scan default IEs but not
	 * present in the scan request, then that IE should be added to the IEs
	 * sent in the Probe Request frames for that scan request. */
	QCA_WLAN_VENDOR_ATTR_CONFIG_SCAN_DEFAULT_IES = 16,
	/* Unsigned 32-bit attribute for generic commands */
	QCA_WLAN_VENDOR_ATTR_CONFIG_GENERIC_COMMAND = 17,
	/* Unsigned 32-bit value attribute for generic commands */
	QCA_WLAN_VENDOR_ATTR_CONFIG_GENERIC_VALUE = 18,
	/* Unsigned 32-bit data attribute for generic command response */
	QCA_WLAN_VENDOR_ATTR_CONFIG_GENERIC_DATA = 19,
	/* Unsigned 32-bit length attribute for
	 * QCA_WLAN_VENDOR_ATTR_CONFIG_GENERIC_DATA */
	QCA_WLAN_VENDOR_ATTR_CONFIG_GENERIC_LENGTH = 20,
	/* Unsigned 32-bit flags attribute for
	 * QCA_WLAN_VENDOR_ATTR_CONFIG_GENERIC_DATA */
	QCA_WLAN_VENDOR_ATTR_CONFIG_GENERIC_FLAGS = 21,
	/* Unsigned 32-bit, defining the access policy.
	 * See enum qca_access_policy. Used with
	 * QCA_WLAN_VENDOR_ATTR_CONFIG_ACCESS_POLICY_IE_LIST. */
	QCA_WLAN_VENDOR_ATTR_CONFIG_ACCESS_POLICY = 22,
	/* Sets the list of full set of IEs for which a specific access policy
	 * has to be applied. Used along with
	 * QCA_WLAN_VENDOR_ATTR_CONFIG_ACCESS_POLICY to control the access.
	 * Zero length payload can be used to clear this access constraint. */
	QCA_WLAN_VENDOR_ATTR_CONFIG_ACCESS_POLICY_IE_LIST = 23,
	/* Unsigned 32-bit, specifies the interface index (netdev) for which the
	 * corresponding configurations are applied. If the interface index is
	 * not specified, the configurations are attributed to the respective
	 * wiphy. */
	QCA_WLAN_VENDOR_ATTR_CONFIG_IFINDEX = 24,
	/* 8-bit unsigned value to trigger QPower: 1-Enable, 0-Disable */
	QCA_WLAN_VENDOR_ATTR_CONFIG_QPOWER = 25,
	/* 8-bit unsigned value to configure the driver and below layers to
	 * ignore the assoc disallowed set by APs while connecting
	 * 1-Ignore, 0-Don't ignore */
	QCA_WLAN_VENDOR_ATTR_CONFIG_IGNORE_ASSOC_DISALLOWED = 26,
	/* 32-bit unsigned value to trigger antenna diversity features:
	 * 1-Enable, 0-Disable */
	QCA_WLAN_VENDOR_ATTR_CONFIG_ANT_DIV_ENA = 27,
	/* 32-bit unsigned value to configure specific chain antenna */
	QCA_WLAN_VENDOR_ATTR_CONFIG_ANT_DIV_CHAIN = 28,
	/* 32-bit unsigned value to trigger cycle selftest
	 * 1-Enable, 0-Disable */
	QCA_WLAN_VENDOR_ATTR_CONFIG_ANT_DIV_SELFTEST = 29,
	/* 32-bit unsigned to configure the cycle time of selftest
	 * the unit is micro-second */
	QCA_WLAN_VENDOR_ATTR_CONFIG_ANT_DIV_SELFTEST_INTVL = 30,
	/* 32-bit unsigned value to set reorder timeout for AC_VO */
	QCA_WLAN_VENDOR_ATTR_CONFIG_RX_REORDER_TIMEOUT_VOICE = 31,
	/* 32-bit unsigned value to set reorder timeout for AC_VI */
	QCA_WLAN_VENDOR_ATTR_CONFIG_RX_REORDER_TIMEOUT_VIDEO = 32,
	/* 32-bit unsigned value to set reorder timeout for AC_BE */
	QCA_WLAN_VENDOR_ATTR_CONFIG_RX_REORDER_TIMEOUT_BESTEFFORT = 33,
	/* 32-bit unsigned value to set reorder timeout for AC_BK */
	QCA_WLAN_VENDOR_ATTR_CONFIG_RX_REORDER_TIMEOUT_BACKGROUND = 34,
	/* 6-byte MAC address to point out the specific peer */
	QCA_WLAN_VENDOR_ATTR_CONFIG_RX_BLOCKSIZE_PEER_MAC = 35,
	/* 32-bit unsigned value to set window size for specific peer */
	QCA_WLAN_VENDOR_ATTR_CONFIG_RX_BLOCKSIZE_WINLIMIT = 36,

	/* keep last */
	QCA_WLAN_VENDOR_ATTR_CONFIG_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_CONFIG_MAX =
	QCA_WLAN_VENDOR_ATTR_CONFIG_AFTER_LAST - 1,
};

/**
 * enum qca_wlan_vendor_attr_sap_config - Parameters for AP configuration
 */
enum qca_wlan_vendor_attr_sap_config {
	QCA_WLAN_VENDOR_ATTR_SAP_CONFIG_INVALID = 0,
	/* 1 - reserved for QCA */
	/* List of frequencies on which AP is expected to operate.
	 * This is irrespective of ACS configuration. This list is a priority
	 * based one and is looked for before the AP is created to ensure the
	 * best concurrency sessions (avoid MCC and use DBS/SCC) co-exist in
	 * the system.
	 */
	QCA_WLAN_VENDOR_ATTR_SAP_MANDATORY_FREQUENCY_LIST = 2,

	QCA_WLAN_VENDOR_ATTR_SAP_CONFIG_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_SAP_CONFIG_MAX =
	QCA_WLAN_VENDOR_ATTR_SAP_CONFIG_AFTER_LAST - 1,
};

/**
 * enum qca_wlan_vendor_attr_sap_conditional_chan_switch - Parameters for AP
 *					conditional channel switch
 */
enum qca_wlan_vendor_attr_sap_conditional_chan_switch {
	QCA_WLAN_VENDOR_ATTR_SAP_CONDITIONAL_CHAN_SWITCH_INVALID = 0,
	/* Priority based frequency list (an array of u32 values in host byte
	 * order) */
	QCA_WLAN_VENDOR_ATTR_SAP_CONDITIONAL_CHAN_SWITCH_FREQ_LIST = 1,
	/* Status of the conditional switch (u32).
	 * 0: Success, Non-zero: Failure
	 */
	QCA_WLAN_VENDOR_ATTR_SAP_CONDITIONAL_CHAN_SWITCH_STATUS = 2,

	QCA_WLAN_VENDOR_ATTR_SAP_CONDITIONAL_CHAN_SWITCH_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_SAP_CONDITIONAL_CHAN_SWITCH_MAX =
	QCA_WLAN_VENDOR_ATTR_SAP_CONDITIONAL_CHAN_SWITCH_AFTER_LAST - 1,
};

/**
 * enum qca_wlan_gpio_attr - Parameters for GPIO configuration
 */
enum qca_wlan_gpio_attr {
	QCA_WLAN_VENDOR_ATTR_GPIO_PARAM_INVALID = 0,
	/* Unsigned 32-bit attribute for GPIO command */
	QCA_WLAN_VENDOR_ATTR_GPIO_PARAM_COMMAND,
	/* Unsigned 32-bit attribute for GPIO PIN number to configure */
	QCA_WLAN_VENDOR_ATTR_GPIO_PARAM_PINNUM,
	/* Unsigned 32-bit attribute for GPIO value to configure */
	QCA_WLAN_VENDOR_ATTR_GPIO_PARAM_VALUE,
	/* Unsigned 32-bit attribute for GPIO pull type */
	QCA_WLAN_VENDOR_ATTR_GPIO_PARAM_PULL_TYPE,
	/* Unsigned 32-bit attribute for GPIO interrupt mode */
	QCA_WLAN_VENDOR_ATTR_GPIO_PARAM_INTR_MODE,

	/* keep last */
	QCA_WLAN_VENDOR_ATTR_GPIO_PARAM_LAST,
	QCA_WLAN_VENDOR_ATTR_GPIO_PARAM_MAX =
	QCA_WLAN_VENDOR_ATTR_GPIO_PARAM_LAST - 1
};

/**
 * enum qca_wlan_vendor_attr_get_hw_capability - Wi-Fi hardware capability
 */
enum qca_wlan_vendor_attr_get_hw_capability {
	QCA_WLAN_VENDOR_ATTR_HW_CAPABILITY_INVALID,
	/* Antenna isolation
	 * An attribute used in the response.
	 * The content of this attribute is encoded in a byte array. Each byte
	 * value is an antenna isolation value. The array length is the number
	 * of antennas.
	 */
	QCA_WLAN_VENDOR_ATTR_ANTENNA_ISOLATION,
	/* Request HW capability
	 * An attribute used in the request.
	 * The content of this attribute is a u32 array for one or more of
	 * hardware capabilities (attribute IDs) that are being requested. Each
	 * u32 value has a value from this
	 * enum qca_wlan_vendor_attr_get_hw_capability
	 * identifying which capabilities are requested.
	 */
	QCA_WLAN_VENDOR_ATTR_GET_HW_CAPABILITY,

	/* keep last */
	QCA_WLAN_VENDOR_ATTR_HW_CAPABILITY_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_HW_CAPABILITY_MAX =
	QCA_WLAN_VENDOR_ATTR_HW_CAPABILITY_AFTER_LAST - 1,
};

/**
 * enum qca_wlan_vendor_attr_ll_stats_ext - Attributes for MAC layer monitoring
 *    offload which is an extension for LL_STATS.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_CFG_PERIOD: Monitoring period. Unit in ms.
 *    If MAC counters do not exceed the threshold, FW will report monitored
 *    link layer counters periodically as this setting. The first report is
 *    always triggered by this timer.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_CFG_THRESHOLD: It is a percentage (1-99).
 *    For each MAC layer counter, FW holds two copies. One is the current value.
 *    The other is the last report. Once a current counter's increment is larger
 *    than the threshold, FW will indicate that counter to host even if the
 *    monitoring timer does not expire.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_PS_CHG: Peer STA power state change
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TID: TID of MSDU
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_NUM_MSDU: Count of MSDU with the same
 *    failure code.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_STATUS: TX failure code
 *    1: TX packet discarded
 *    2: No ACK
 *    3: Postpone
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_MAC_ADDRESS: peer MAC address
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_PS_STATE: Peer STA current state
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_GLOBAL: Global threshold.
 *    Threshold for all monitored parameters. If per counter dedicated threshold
 *    is not enabled, this threshold will take effect.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_EVENT_MODE: Indicate what triggers this
 *    event, PERORID_TIMEOUT == 1, THRESH_EXCEED == 0.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_IFACE_ID: interface ID
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_ID: peer ID
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_BITMAP: bitmap for TX counters
 *    Bit0: TX counter unit in MSDU
 *    Bit1: TX counter unit in MPDU
 *    Bit2: TX counter unit in PPDU
 *    Bit3: TX counter unit in byte
 *    Bit4: Dropped MSDUs
 *    Bit5: Dropped Bytes
 *    Bit6: MPDU retry counter
 *    Bit7: MPDU failure counter
 *    Bit8: PPDU failure counter
 *    Bit9: MPDU aggregation counter
 *    Bit10: MCS counter for ACKed MPDUs
 *    Bit11: MCS counter for Failed MPDUs
 *    Bit12: TX Delay counter
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_BITMAP: bitmap for RX counters
 *    Bit0: MAC RX counter unit in MPDU
 *    Bit1: MAC RX counter unit in byte
 *    Bit2: PHY RX counter unit in PPDU
 *    Bit3: PHY RX counter unit in byte
 *    Bit4: Disorder counter
 *    Bit5: Retry counter
 *    Bit6: Duplication counter
 *    Bit7: Discard counter
 *    Bit8: MPDU aggregation size counter
 *    Bit9: MCS counter
 *    Bit10: Peer STA power state change (wake to sleep) counter
 *    Bit11: Peer STA power save counter, total time in PS mode
 *    Bit12: Probe request counter
 *    Bit13: Other management frames counter
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_CCA_BSS_BITMAP: bitmap for CCA
 *    Bit0: Idle time
 *    Bit1: TX time
 *    Bit2: time RX in current bss
 *    Bit3: Out of current bss time
 *    Bit4: Wireless medium busy time
 *    Bit5: RX in bad condition time
 *    Bit6: TX in bad condition time
 *    Bit7: time wlan card not available
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_SIGNAL_BITMAP: bitmap for signal
 *    Bit0: Per channel SNR counter
 *    Bit1: Per channel noise floor counter
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_NUM: number of peers
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_CHANNEL_NUM: number of channels
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_AC_RX_NUM: number of RX stats
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_CCA_BSS: per channel BSS CCA stats
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER: container for per PEER stats
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_MSDU: Number of total TX MSDUs
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_MPDU: Number of total TX MPDUs
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_PPDU: Number of total TX PPDUs
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_BYTES: bytes of TX data
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_DROP: Number of dropped TX packets
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_DROP_BYTES: Bytes dropped
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_RETRY: waiting time without an ACK
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_NO_ACK: number of MPDU not-ACKed
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_NO_BACK: number of PPDU not-ACKed
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_AGGR_NUM:
 *    aggregation stats buffer length
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_SUCC_MCS_NUM: length of mcs stats
 *    buffer for ACKed MPDUs.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_FAIL_MCS_NUM: length of mcs stats
 *    buffer for failed MPDUs.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_DELAY_ARRAY_SIZE:
 *    length of delay stats array.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_AGGR: TX aggregation stats
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_SUCC_MCS: MCS stats for ACKed MPDUs
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_FAIL_MCS: MCS stats for failed MPDUs
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_DELAY: tx delay stats
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU: MPDUs received
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU_BYTES: bytes received
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_PPDU: PPDU received
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_PPDU_BYTES: PPDU bytes received
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU_LOST: packets lost
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU_RETRY: number of RX packets
 *    flagged as retransmissions
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU_DUP: number of RX packets
 *    flagged as duplicated
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU_DISCARD: number of RX
 *    packets discarded
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_AGGR_NUM: length of RX aggregation
 *    stats buffer.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MCS_NUM: length of RX mcs
 *    stats buffer.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MCS: RX mcs stats buffer
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_AGGR: aggregation stats buffer
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_PS_TIMES: times STAs go to sleep
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_PS_DURATION: STAs' total sleep time
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_PROBE_REQ: number of probe
 *    requests received
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MGMT: number of other mgmt
 *    frames received
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_IDLE_TIME: Percentage of idle time
 *    there is no TX, nor RX, nor interference.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_TIME: percentage of time
 *    transmitting packets.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_TIME: percentage of time
 *    for receiving.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_BUSY: percentage of time
 *    interference detected.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_BAD: percentage of time
 *    receiving packets with errors.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_BAD: percentage of time
 *    TX no-ACK.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_NO_AVAIL: percentage of time
 *    the chip is unable to work in normal conditions.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_IN_BSS_TIME: percentage of time
 *    receiving packets in current BSS.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_OUT_BSS_TIME: percentage of time
 *    receiving packets not in current BSS.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_ANT_NUM: number of antennas
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_SIGNAL:
 *    This is a container for per antenna signal stats.
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_ANT_SNR: per antenna SNR value
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_ANT_NF: per antenna NF value
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_IFACE_RSSI_BEACON: RSSI of beacon
 * @QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_IFACE_SNR_BEACON: SNR of beacon
 */
enum qca_wlan_vendor_attr_ll_stats_ext {
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_INVALID = 0,

	/* Attributes for configurations */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CFG_PERIOD,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CFG_THRESHOLD,

	/* Peer STA power state change */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_PS_CHG,

	/* TX failure event */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TID,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_NUM_MSDU,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_STATUS,

	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_PS_STATE,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_MAC_ADDRESS,

	/* MAC counters */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_GLOBAL,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_EVENT_MODE,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_IFACE_ID,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_ID,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_BITMAP,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_BITMAP,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_CCA_BSS_BITMAP,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_SIGNAL_BITMAP,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_NUM,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_CHANNEL_NUM,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_CCA_BSS,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER,

	/* Sub-attributes for PEER_AC_TX */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_MSDU,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_MPDU,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_PPDU,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_BYTES,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_DROP,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_DROP_BYTES,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_RETRY,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_NO_ACK,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_NO_BACK,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_AGGR_NUM,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_SUCC_MCS_NUM,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_FAIL_MCS_NUM,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_AGGR,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_SUCC_MCS,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_FAIL_MCS,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_DELAY_ARRAY_SIZE,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_DELAY,

	/* Sub-attributes for PEER_AC_RX */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU_BYTES,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_PPDU,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_PPDU_BYTES,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU_LOST,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU_RETRY,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU_DUP,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MPDU_DISCARD,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_AGGR_NUM,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MCS_NUM,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MCS,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_AGGR,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_PS_TIMES,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_PS_DURATION,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_PROBE_REQ,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_MGMT,

	/* Sub-attributes for CCA_BSS */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_IDLE_TIME,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_TIME,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_TIME,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_BUSY,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_RX_BAD,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_TX_BAD,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_NO_AVAIL,

	/* sub-attribute for BSS_RX_TIME */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_IN_BSS_TIME,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_OUT_BSS_TIME,

	/* Sub-attributes for PEER_SIGNAL */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_ANT_NUM,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_PEER_SIGNAL,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_ANT_SNR,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_ANT_NF,

	/* Sub-attributes for IFACE_BSS */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_IFACE_RSSI_BEACON,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_IFACE_SNR_BEACON,

	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_LAST,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_MAX =
		QCA_WLAN_VENDOR_ATTR_LL_STATS_EXT_LAST - 1
};

/* Attributes for FTM commands and events */

/**
 * enum qca_wlan_vendor_attr_loc_capa - Indoor location capabilities
 *
 * @QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAGS: Various flags. See
 *	enum qca_wlan_vendor_attr_loc_capa_flags.
 * @QCA_WLAN_VENDOR_ATTR_FTM_CAPA_MAX_NUM_SESSIONS: Maximum number
 *	of measurement sessions that can run concurrently.
 *	Default is one session (no session concurrency).
 * @QCA_WLAN_VENDOR_ATTR_FTM_CAPA_MAX_NUM_PEERS: The total number of unique
 *	peers that are supported in running sessions. For example,
 *	if the value is 8 and maximum number of sessions is 2, you can
 *	have one session with 8 unique peers, or 2 sessions with 4 unique
 *	peers each, and so on.
 * @QCA_WLAN_VENDOR_ATTR_FTM_CAPA_MAX_NUM_BURSTS_EXP: Maximum number
 *	of bursts per peer, as an exponent (2^value). Default is 0,
 *	meaning no multi-burst support.
 * @QCA_WLAN_VENDOR_ATTR_FTM_CAPA_MAX_MEAS_PER_BURST: Maximum number
 *	of measurement exchanges allowed in a single burst.
 * @QCA_WLAN_VENDOR_ATTR_AOA_CAPA_SUPPORTED_TYPES: Supported AOA measurement
 *	types. A bit mask (unsigned 32 bit value), each bit corresponds
 *	to an AOA type as defined by enum qca_vendor_attr_aoa_type.
 */
enum qca_wlan_vendor_attr_loc_capa {
	QCA_WLAN_VENDOR_ATTR_LOC_CAPA_INVALID,
	QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAGS,
	QCA_WLAN_VENDOR_ATTR_FTM_CAPA_MAX_NUM_SESSIONS,
	QCA_WLAN_VENDOR_ATTR_FTM_CAPA_MAX_NUM_PEERS,
	QCA_WLAN_VENDOR_ATTR_FTM_CAPA_MAX_NUM_BURSTS_EXP,
	QCA_WLAN_VENDOR_ATTR_FTM_CAPA_MAX_MEAS_PER_BURST,
	QCA_WLAN_VENDOR_ATTR_AOA_CAPA_SUPPORTED_TYPES,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_LOC_CAPA_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_LOC_CAPA_MAX =
	QCA_WLAN_VENDOR_ATTR_LOC_CAPA_AFTER_LAST - 1,
};

/**
 * enum qca_wlan_vendor_attr_loc_capa_flags: Indoor location capability flags
 *
 * @QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAG_FTM_RESPONDER: Set if driver
 *	can be configured as an FTM responder (for example, an AP that
 *	services FTM requests). QCA_NL80211_VENDOR_SUBCMD_FTM_CFG_RESPONDER
 *	will be supported if set.
 * @QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAG_FTM_INITIATOR: Set if driver
 *	can run FTM sessions. QCA_NL80211_VENDOR_SUBCMD_FTM_START_SESSION
 *	will be supported if set.
* @QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAG_ASAP: Set if FTM responder
 *	supports immediate (ASAP) response.
 * @QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAG_AOA: Set if driver supports standalone
 *	AOA measurement using QCA_NL80211_VENDOR_SUBCMD_AOA_MEAS.
 * @QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAG_AOA_IN_FTM: Set if driver supports
 *	requesting AOA measurements as part of an FTM session.
 */
enum qca_wlan_vendor_attr_loc_capa_flags {
	QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAG_FTM_RESPONDER = 1 << 0,
	QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAG_FTM_INITIATOR = 1 << 1,
	QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAG_ASAP = 1 << 2,
	QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAG_AOA = 1 << 3,
	QCA_WLAN_VENDOR_ATTR_LOC_CAPA_FLAG_AOA_IN_FTM = 1 << 4,
};

/**
 * enum qca_wlan_vendor_attr_ftm_peer_info: Information about
 *	a single peer in a measurement session.
 *
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_MAC_ADDR: The MAC address of the peer.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_FLAGS: Various flags related
 *	to measurement. See enum qca_wlan_vendor_attr_ftm_peer_meas_flags.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_PARAMS: Nested attribute of
 *	FTM measurement parameters, as specified by IEEE P802.11-REVmc/D7.0
 *	9.4.2.167. See enum qca_wlan_vendor_attr_ftm_meas_param for
 *	list of supported attributes.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_SECURE_TOKEN_ID: Initial token ID for
 *	secure measurement.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_AOA_BURST_PERIOD: Request AOA
 *	measurement every <value> bursts. If 0 or not specified,
 *	AOA measurements will be disabled for this peer.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_FREQ: Frequency in MHz where
 *	the measurement frames are exchanged. Optional; if not
 *	specified, try to locate the peer in the kernel scan
 *	results cache and use frequency from there.
 */
enum qca_wlan_vendor_attr_ftm_peer_info {
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_INVALID,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_MAC_ADDR,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_FLAGS,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_PARAMS,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_SECURE_TOKEN_ID,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_AOA_BURST_PERIOD,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_FREQ,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_MAX =
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_AFTER_LAST - 1,
};

/**
 * enum qca_wlan_vendor_attr_ftm_peer_meas_flags: Measurement request flags,
 *	per-peer
 *
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_FLAG_ASAP: If set, request
 *	immediate (ASAP) response from peer.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_FLAG_LCI: If set, request
 *	LCI report from peer. The LCI report includes the absolute
 *	location of the peer in "official" coordinates (similar to GPS).
 *	See IEEE P802.11-REVmc/D7.0, 11.24.6.7 for more information.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_FLAG_LCR: If set, request
 *	Location civic report from peer. The LCR includes the location
 *	of the peer in free-form format. See IEEE P802.11-REVmc/D7.0,
 *	11.24.6.7 for more information.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_FLAG_SECURE: If set,
 *	request a secure measurement.
 *	QCA_WLAN_VENDOR_ATTR_FTM_PEER_SECURE_TOKEN_ID must also be provided.
 */
enum qca_wlan_vendor_attr_ftm_peer_meas_flags {
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_FLAG_ASAP	= 1 << 0,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_FLAG_LCI	= 1 << 1,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_FLAG_LCR	= 1 << 2,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_MEAS_FLAG_SECURE	= 1 << 3,
};

/**
 * enum qca_wlan_vendor_attr_ftm_meas_param: Measurement parameters
 *
 * @QCA_WLAN_VENDOR_ATTR_FTM_PARAM_MEAS_PER_BURST: Number of measurements
 *	to perform in a single burst.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PARAM_NUM_BURSTS_EXP: Number of bursts to
 *	perform, specified as an exponent (2^value).
 * @QCA_WLAN_VENDOR_ATTR_FTM_PARAM_BURST_DURATION: Duration of burst
 *	instance, as specified in IEEE P802.11-REVmc/D7.0, 9.4.2.167.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PARAM_BURST_PERIOD: Time between bursts,
 *	as specified in IEEE P802.11-REVmc/D7.0, 9.4.2.167. Must
 *	be larger than QCA_WLAN_VENDOR_ATTR_FTM_PARAM_BURST_DURATION.
 */
enum qca_wlan_vendor_attr_ftm_meas_param {
	QCA_WLAN_VENDOR_ATTR_FTM_PARAM_INVALID,
	QCA_WLAN_VENDOR_ATTR_FTM_PARAM_MEAS_PER_BURST,
	QCA_WLAN_VENDOR_ATTR_FTM_PARAM_NUM_BURSTS_EXP,
	QCA_WLAN_VENDOR_ATTR_FTM_PARAM_BURST_DURATION,
	QCA_WLAN_VENDOR_ATTR_FTM_PARAM_BURST_PERIOD,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_FTM_PARAM_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_FTM_PARAM_MAX =
	QCA_WLAN_VENDOR_ATTR_FTM_PARAM_AFTER_LAST - 1,
};

/**
 * enum qca_wlan_vendor_attr_ftm_peer_result: Per-peer results
 *
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_MAC_ADDR: MAC address of the reported
 *	 peer.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_STATUS: Status of measurement
 *	request for this peer.
 *	See enum qca_wlan_vendor_attr_ftm_peer_result_status.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_FLAGS: Various flags related
 *	to measurement results for this peer.
 *	See enum qca_wlan_vendor_attr_ftm_peer_result_flags.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_VALUE_SECONDS: Specified when
 *	request failed and peer requested not to send an additional request
 *	for this number of seconds.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_LCI: LCI report when received
 *	from peer. In the format specified by IEEE P802.11-REVmc/D7.0,
 *	9.4.2.22.10.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_LCR: Location civic report when
 *	received from peer. In the format specified by IEEE P802.11-REVmc/D7.0,
 *	9.4.2.22.13.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_MEAS_PARAMS: Reported when peer
 *	overridden some measurement request parameters. See
 *	enum qca_wlan_vendor_attr_ftm_meas_param.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_AOA_MEAS: AOA measurement
 *	for this peer. Same contents as @QCA_WLAN_VENDOR_ATTR_AOA_MEAS_RESULT.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_MEAS: Array of measurement
 *	results. Each entry is a nested attribute defined
 *	by enum qca_wlan_vendor_attr_ftm_meas.
 */
enum qca_wlan_vendor_attr_ftm_peer_result {
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_INVALID,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_MAC_ADDR,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_STATUS,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_FLAGS,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_VALUE_SECONDS,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_LCI,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_LCR,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_MEAS_PARAMS,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_AOA_MEAS,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_MEAS,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_MAX =
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_AFTER_LAST - 1,
};

/**
 * enum qca_wlan_vendor_attr_ftm_peer_result_status
 *
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_STATUS_OK: Request sent ok and results
 *	will be provided. Peer may have overridden some measurement parameters,
 *	in which case overridden parameters will be report by
 *	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_MEAS_PARAM attribute.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_STATUS_INCAPABLE: Peer is incapable
 *	of performing the measurement request. No more results will be sent
 *	for this peer in this session.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_STATUS_FAILED: Peer reported request
 *	failed, and requested not to send an additional request for number
 *	of seconds specified by QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_VALUE_SECONDS
 *	attribute.
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_STATUS_INVALID: Request validation
 *	failed. Request was not sent over the air.
 */
enum qca_wlan_vendor_attr_ftm_peer_result_status {
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_STATUS_OK,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_STATUS_INCAPABLE,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_STATUS_FAILED,
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_STATUS_INVALID,
};

/**
 * enum qca_wlan_vendor_attr_ftm_peer_result_flags: Various flags
 *  for measurement result, per-peer
 *
 * @QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_FLAG_DONE: If set,
 *	measurement completed for this peer. No more results will be reported
 *	for this peer in this session.
 */
enum qca_wlan_vendor_attr_ftm_peer_result_flags {
	QCA_WLAN_VENDOR_ATTR_FTM_PEER_RES_FLAG_DONE = 1 << 0,
};

/**
 * enum qca_vendor_attr_loc_session_status: Session completion status code
 *
 * @QCA_WLAN_VENDOR_ATTR_LOC_SESSION_STATUS_OK: Session completed
 *	successfully.
 * @QCA_WLAN_VENDOR_ATTR_LOC_SESSION_STATUS_ABORTED: Session aborted
 *	by request.
 * @QCA_WLAN_VENDOR_ATTR_LOC_SESSION_STATUS_INVALID: Session request
 *	was invalid and was not started.
 * @QCA_WLAN_VENDOR_ATTR_LOC_SESSION_STATUS_FAILED: Session had an error
 *	and did not complete normally (for example out of resources).
 */
enum qca_vendor_attr_loc_session_status {
	QCA_WLAN_VENDOR_ATTR_LOC_SESSION_STATUS_OK,
	QCA_WLAN_VENDOR_ATTR_LOC_SESSION_STATUS_ABORTED,
	QCA_WLAN_VENDOR_ATTR_LOC_SESSION_STATUS_INVALID,
	QCA_WLAN_VENDOR_ATTR_LOC_SESSION_STATUS_FAILED,
};

/**
 * enum qca_wlan_vendor_attr_ftm_meas: Single measurement data
 *
 * @QCA_WLAN_VENDOR_ATTR_FTM_MEAS_T1: Time of departure (TOD) of FTM packet as
 *	recorded by responder, in picoseconds.
 *	See IEEE P802.11-REVmc/D7.0, 11.24.6.4 for more information.
 * @QCA_WLAN_VENDOR_ATTR_FTM_MEAS_T2: Time of arrival (TOA) of FTM packet at
 *	initiator, in picoseconds.
 *	See IEEE P802.11-REVmc/D7.0, 11.24.6.4 for more information.
 * @QCA_WLAN_VENDOR_ATTR_FTM_MEAS_T3: TOD of ACK packet as recorded by
 *	initiator, in picoseconds.
 *	See IEEE P802.11-REVmc/D7.0, 11.24.6.4 for more information.
 * @QCA_WLAN_VENDOR_ATTR_FTM_MEAS_T4: TOA of ACK packet at
 *	responder, in picoseconds.
 *	See IEEE P802.11-REVmc/D7.0, 11.24.6.4 for more information.
 * @QCA_WLAN_VENDOR_ATTR_FTM_MEAS_RSSI: RSSI (signal level) as recorded
 *	during this measurement exchange. Optional and will be provided if
 *	the hardware can measure it.
 * @QCA_WLAN_VENDOR_ATTR_FTM_MEAS_TOD_ERR: TOD error reported by
 *	responder. Not always provided.
 *	See IEEE P802.11-REVmc/D7.0, 9.6.8.33 for more information.
 * @QCA_WLAN_VENDOR_ATTR_FTM_MEAS_TOA_ERR: TOA error reported by
 *	responder. Not always provided.
 *	See IEEE P802.11-REVmc/D7.0, 9.6.8.33 for more information.
 * @QCA_WLAN_VENDOR_ATTR_FTM_MEAS_INITIATOR_TOD_ERR: TOD error measured by
 *	initiator. Not always provided.
 *	See IEEE P802.11-REVmc/D7.0, 9.6.8.33 for more information.
 * @QCA_WLAN_VENDOR_ATTR_FTM_MEAS_INITIATOR_TOA_ERR: TOA error measured by
 *	initiator. Not always provided.
 *	See IEEE P802.11-REVmc/D7.0, 9.6.8.33 for more information.
 * @QCA_WLAN_VENDOR_ATTR_FTM_MEAS_PAD: Dummy attribute for padding.
 */
enum qca_wlan_vendor_attr_ftm_meas {
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_INVALID,
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_T1,
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_T2,
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_T3,
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_T4,
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_RSSI,
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_TOD_ERR,
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_TOA_ERR,
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_INITIATOR_TOD_ERR,
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_INITIATOR_TOA_ERR,
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_PAD,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_MAX =
	QCA_WLAN_VENDOR_ATTR_FTM_MEAS_AFTER_LAST - 1,
};

/**
 * enum qca_wlan_vendor_attr_aoa_type - AOA measurement type
 *
 * @QCA_WLAN_VENDOR_ATTR_AOA_TYPE_TOP_CIR_PHASE: Phase of the strongest
 *	CIR (channel impulse response) path for each antenna.
 * @QCA_WLAN_VENDOR_ATTR_AOA_TYPE_TOP_CIR_PHASE_AMP: Phase and amplitude
 *	of the strongest CIR path for each antenna.
 */
enum qca_wlan_vendor_attr_aoa_type {
	QCA_WLAN_VENDOR_ATTR_AOA_TYPE_TOP_CIR_PHASE,
	QCA_WLAN_VENDOR_ATTR_AOA_TYPE_TOP_CIR_PHASE_AMP,
	QCA_WLAN_VENDOR_ATTR_AOA_TYPE_MAX
};

/**
 * enum qca_wlan_vendor_attr_encryption_test - Attributes to
 * validate encryption engine
 *
 * @QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_NEEDS_DECRYPTION: Flag attribute.
 *	This will be included if the request is for decryption; if not included,
 *	the request is treated as a request for encryption by default.
 * @QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_CIPHER: Unsigned 32-bit value
 *	indicating the key cipher suite. Takes same values as
 *	NL80211_ATTR_KEY_CIPHER.
 * @QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_KEYID: Unsigned 8-bit value
 *	Key Id to be used for encryption
 * @QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_TK: Array of 8-bit values.
 *	Key (TK) to be used for encryption/decryption
 * @QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_PN: Array of 8-bit values.
 *	Packet number to be specified for encryption/decryption
 *	6 bytes for TKIP/CCMP/GCMP.
 * @QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_DATA: Array of 8-bit values
 *	representing the 802.11 packet (header + payload + FCS) that
 *	needs to be encrypted/decrypted.
 *	Encrypted/decrypted response from the driver will also be sent
 *	to userspace with the same attribute.
 */
enum qca_wlan_vendor_attr_encryption_test {
	QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_INVALID = 0,
	QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_NEEDS_DECRYPTION,
	QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_CIPHER,
	QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_KEYID,
	QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_TK,
	QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_PN,
	QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_DATA,

	/* keep last */
	QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_MAX =
	QCA_WLAN_VENDOR_ATTR_ENCRYPTION_TEST_AFTER_LAST - 1
};

/**
 * enum qca_wlan_vendor_attr_dmg_rf_sector_type - Type of
 * sector for DMG RF sector operations.
 *
 * @QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_TYPE_RX: RX sector
 * @QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_TYPE_TX: TX sector
 */
enum qca_wlan_vendor_attr_dmg_rf_sector_type {
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_TYPE_RX,
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_TYPE_TX,
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_TYPE_MAX
};

/**
 * enum qca_wlan_vendor_attr_dmg_rf_sector_cfg - Attributes for
 * DMG RF sector configuration for a single RF module.
 * The values are defined in a compact way which closely matches
 * the way it is stored in HW registers.
 * The configuration provides values for 32 antennas and 8 distribution
 * amplifiers, and together describes the characteristics of the RF
 * sector - such as a beam in some direction with some gain.
 *
 * @QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_MODULE_INDEX: Index
 *	of RF module for this configuration.
 * @QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_ETYPE0: Bit 0 of edge
 *	amplifier gain index. Unsigned 32 bit number containing
 *	bits for all 32 antennas.
 * @QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_ETYPE1: Bit 1 of edge
 *	amplifier gain index. Unsigned 32 bit number containing
 *	bits for all 32 antennas.
 * @QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_ETYPE2: Bit 2 of edge
 *	amplifier gain index. Unsigned 32 bit number containing
 *	bits for all 32 antennas.
 * @QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_PSH_HI: Phase values
 *	for first 16 antennas, 2 bits per antenna.
 * @QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_PSH_LO: Phase values
 *	for last 16 antennas, 2 bits per antenna.
 * @QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_DTYPE_X16: Contains
 *	DTYPE values (3 bits) for each distribution amplifier, followed
 *	by X16 switch bits for each distribution amplifier. There are
 *	total of 8 distribution amplifiers.
 */
enum qca_wlan_vendor_attr_dmg_rf_sector_cfg {
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_INVALID = 0,
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_MODULE_INDEX = 1,
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_ETYPE0 = 2,
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_ETYPE1 = 3,
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_ETYPE2 = 4,
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_PSH_HI = 5,
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_PSH_LO = 6,
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_DTYPE_X16 = 7,

	/* keep last */
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_MAX =
	QCA_WLAN_VENDOR_ATTR_DMG_RF_SECTOR_CFG_AFTER_LAST - 1
};

enum qca_wlan_vendor_attr_ll_stats_set {
	QCA_WLAN_VENDOR_ATTR_LL_STATS_SET_INVALID = 0,
	/* Unsigned 32-bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_SET_CONFIG_MPDU_SIZE_THRESHOLD = 1,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_SET_CONFIG_AGGRESSIVE_STATS_GATHERING = 2,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_SET_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_SET_MAX =
	QCA_WLAN_VENDOR_ATTR_LL_STATS_SET_AFTER_LAST - 1,
};

enum qca_wlan_vendor_attr_ll_stats_clr {
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CLR_INVALID = 0,
	/* Unsigned 32bit bitmap for clearing statistics
	 * All radio statistics                     0x00000001
	 * cca_busy_time (within radio statistics)  0x00000002
	 * All channel stats (within radio statistics) 0x00000004
	 * All scan statistics (within radio statistics) 0x00000008
	 * All interface statistics                     0x00000010
	 * All tx rate statistics (within interface statistics) 0x00000020
	 * All ac statistics (with in interface statistics) 0x00000040
	 * All contention (min, max, avg) statistics (within ac statisctics)
	 * 0x00000080.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CLR_CONFIG_REQ_MASK = 1,
	/* Unsigned 8 bit value: Request to stop statistics collection */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CLR_CONFIG_STOP_REQ = 2,

	/* Unsigned 32 bit bitmap: Response from the driver
	 * for the cleared statistics
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CLR_CONFIG_RSP_MASK = 3,
	/* Unsigned 8 bit value: Response from driver/firmware
	 * for the stop request
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CLR_CONFIG_STOP_RSP = 4,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CLR_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CLR_MAX =
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CLR_AFTER_LAST - 1,
};

enum qca_wlan_vendor_attr_ll_stats_get {
	QCA_WLAN_VENDOR_ATTR_LL_STATS_GET_INVALID = 0,
	/* Unsigned 32 bit value provided by the caller issuing the GET stats
	 * command. When reporting the stats results, the driver uses the same
	 * value to indicate which GET request the results correspond to.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_GET_CONFIG_REQ_ID = 1,
	/* Unsigned 32 bit value - bit mask to identify what statistics are
	 * requested for retrieval.
	 * Radio Statistics 0x00000001
	 * Interface Statistics 0x00000020
	 * All Peer Statistics 0x00000040
	 * Peer Statistics     0x00000080
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_GET_CONFIG_REQ_MASK = 2,
	/* keep last */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_GET_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_GET_MAX =
	QCA_WLAN_VENDOR_ATTR_LL_STATS_GET_AFTER_LAST - 1,
};

enum qca_wlan_vendor_attr_ll_stats_results {
	QCA_WLAN_VENDOR_ATTR_LL_STATS_INVALID = 0,
	/* Unsigned 32bit value. Used by the driver; must match the request id
	 * provided with the QCA_NL80211_VENDOR_SUBCMD_LL_STATS_GET command.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RESULTS_REQ_ID = 1,

	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_BEACON_RX = 2,
	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_MGMT_RX = 3,
	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_MGMT_ACTION_RX = 4,
	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_MGMT_ACTION_TX = 5,
	/* Signed 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_RSSI_MGMT = 6,
	/* Signed 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_RSSI_DATA = 7,
	/* Signed 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_RSSI_ACK = 8,

	/* Attributes of type QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_INFO_* are
	 * nested within the interface stats.
	 */

	/* Interface mode, e.g., STA, SOFTAP, IBSS, etc.
	 * Type = enum wifi_interface_mode.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_INFO_MODE = 9,
	/* Interface MAC address. An array of 6 Unsigned int8 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_INFO_MAC_ADDR = 10,
	/* Type = enum wifi_connection_state, e.g., DISCONNECTED,
	 * AUTHENTICATING, etc. valid for STA, CLI only.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_INFO_STATE = 11,
	/* Type = enum wifi_roam_state. Roaming state, e.g., IDLE or ACTIVE
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_INFO_ROAMING = 12,
	/* Unsigned 32 bit value. WIFI_CAPABILITY_XXX */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_INFO_CAPABILITIES = 13,
	/* NULL terminated SSID. An array of 33 Unsigned 8bit values */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_INFO_SSID = 14,
	/* BSSID. An array of 6 unsigned 8 bit values */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_INFO_BSSID = 15,
	/* Country string advertised by AP. An array of 3 unsigned 8 bit
	 * values.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_INFO_AP_COUNTRY_STR = 16,
	/* Country string for this association. An array of 3 unsigned 8 bit
	 * values.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_INFO_COUNTRY_STR = 17,

	/* Attributes of type QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_* could
	 * be nested within the interface stats.
	 */

	/* Type = enum wifi_traffic_ac, e.g., V0, VI, BE and BK */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_AC = 18,
	/* Unsigned int 32 value corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_TX_MPDU = 19,
	/* Unsigned int 32 value corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_RX_MPDU = 20,
	/* Unsigned int 32 value corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_TX_MCAST = 21,
	/* Unsigned int 32 value corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_RX_MCAST = 22,
	/* Unsigned int 32 value corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_RX_AMPDU = 23,
	/* Unsigned int 32 value corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_TX_AMPDU = 24,
	/* Unsigned int 32 value corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_MPDU_LOST = 25,
	/* Unsigned int 32 value corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_RETRIES = 26,
	/* Unsigned int 32 value corresponding to respective AC  */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_RETRIES_SHORT = 27,
	/* Unsigned int 32 values corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_RETRIES_LONG = 28,
	/* Unsigned int 32 values corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_CONTENTION_TIME_MIN = 29,
	/* Unsigned int 32 values corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_CONTENTION_TIME_MAX = 30,
	/* Unsigned int 32 values corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_CONTENTION_TIME_AVG = 31,
	/* Unsigned int 32 values corresponding to respective AC */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_CONTENTION_NUM_SAMPLES = 32,
	/* Unsigned 32 bit value. Number of peers */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_NUM_PEERS = 33,

	/* Attributes of type QCA_WLAN_VENDOR_ATTR_LL_STATS_PEER_INFO_* are
	 * nested within the interface stats.
	 */

	/* Type = enum wifi_peer_type. Peer type, e.g., STA, AP, P2P GO etc. */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_PEER_INFO_TYPE = 34,
	/* MAC addr corresponding to respective peer. An array of 6 unsigned
	 * 8 bit values.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_PEER_INFO_MAC_ADDRESS = 35,
	/* Unsigned int 32 bit value representing capabilities corresponding
	 * to respective peer.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_PEER_INFO_CAPABILITIES = 36,
	/* Unsigned 32 bit value. Number of rates */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_PEER_INFO_NUM_RATES = 37,

	/* Attributes of type QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_*
	 * are nested within the rate stat.
	 */

	/* Wi-Fi Rate - separate attributes defined for individual fields */

	/* Unsigned int 8 bit value; 0: OFDM, 1:CCK, 2:HT 3:VHT 4..7 reserved */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_PREAMBLE = 38,
	/* Unsigned int 8 bit value; 0:1x1, 1:2x2, 3:3x3, 4:4x4 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_NSS = 39,
	/* Unsigned int 8 bit value; 0:20 MHz, 1:40 MHz, 2:80 MHz, 3:160 MHz */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_BW = 40,
	/* Unsigned int 8 bit value; OFDM/CCK rate code would be as per IEEE Std
	 * in the units of 0.5 Mbps HT/VHT it would be MCS index */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_MCS_INDEX = 41,

	/* Unsigned 32 bit value. Bit rate in units of 100 kbps */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_BIT_RATE = 42,


	/* Attributes of type QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_STAT_* could be
	 * nested within the peer info stats.
	 */

	/* Unsigned int 32 bit value. Number of successfully transmitted data
	 * packets, i.e., with ACK received corresponding to the respective
	 * rate.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_TX_MPDU = 43,
	/* Unsigned int 32 bit value. Number of received data packets
	 * corresponding to the respective rate.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_RX_MPDU = 44,
	/* Unsigned int 32 bit value. Number of data packet losses, i.e., no ACK
	 * received corresponding to the respective rate.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_MPDU_LOST = 45,
	/* Unsigned int 32 bit value. Total number of data packet retries for
	 * the respective rate.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_RETRIES = 46,
	/* Unsigned int 32 bit value. Total number of short data packet retries
	 * for the respective rate.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_RETRIES_SHORT = 47,
	/* Unsigned int 32 bit value. Total number of long data packet retries
	 * for the respective rate.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_RETRIES_LONG = 48,

	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_ID = 49,
	/* Unsigned 32 bit value. Total number of msecs the radio is awake
	 * accruing over time.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_ON_TIME = 50,
	/* Unsigned 32 bit value. Total number of msecs the radio is
	 * transmitting accruing over time.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_TX_TIME = 51,
	/* Unsigned 32 bit value. Total number of msecs the radio is in active
	 * receive accruing over time.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_RX_TIME = 52,
	/* Unsigned 32 bit value. Total number of msecs the radio is awake due
	 * to all scan accruing over time.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_ON_TIME_SCAN = 53,
	/* Unsigned 32 bit value. Total number of msecs the radio is awake due
	 * to NAN accruing over time.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_ON_TIME_NBD = 54,
	/* Unsigned 32 bit value. Total number of msecs the radio is awake due
	 * to GSCAN accruing over time.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_ON_TIME_GSCAN = 55,
	/* Unsigned 32 bit value. Total number of msecs the radio is awake due
	 * to roam scan accruing over time.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_ON_TIME_ROAM_SCAN = 56,
	/* Unsigned 32 bit value. Total number of msecs the radio is awake due
	 * to PNO scan accruing over time.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_ON_TIME_PNO_SCAN = 57,
	/* Unsigned 32 bit value. Total number of msecs the radio is awake due
	 * to Hotspot 2.0 scans and GAS exchange accruing over time.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_ON_TIME_HS20 = 58,
	/* Unsigned 32 bit value. Number of channels. */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_NUM_CHANNELS = 59,

	/* Attributes of type QCA_WLAN_VENDOR_ATTR_LL_STATS_CHANNEL_INFO_* could
	 * be nested within the channel stats.
	 */

	/* Type = enum wifi_channel_width. Channel width, e.g., 20, 40, 80 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CHANNEL_INFO_WIDTH = 60,
	/* Unsigned 32 bit value. Primary 20 MHz channel. */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CHANNEL_INFO_CENTER_FREQ = 61,
	/* Unsigned 32 bit value. Center frequency (MHz) first segment. */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CHANNEL_INFO_CENTER_FREQ0 = 62,
	/* Unsigned 32 bit value. Center frequency (MHz) second segment. */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CHANNEL_INFO_CENTER_FREQ1 = 63,

	/* Attributes of type QCA_WLAN_VENDOR_ATTR_LL_STATS_CHANNEL_* could be
	 * nested within the radio stats.
	 */

	/* Unsigned int 32 bit value representing total number of msecs the
	 * radio is awake on that channel accruing over time, corresponding to
	 * the respective channel.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CHANNEL_ON_TIME = 64,
	/* Unsigned int 32 bit value representing total number of msecs the CCA
	 * register is busy accruing over time corresponding to the respective
	 * channel.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CHANNEL_CCA_BUSY_TIME = 65,

	QCA_WLAN_VENDOR_ATTR_LL_STATS_NUM_RADIOS = 66,

	/* Signifies the nested list of channel attributes
	 * QCA_WLAN_VENDOR_ATTR_LL_STATS_CHANNEL_INFO_*
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_CH_INFO = 67,

	/* Signifies the nested list of peer info attributes
	 * QCA_WLAN_VENDOR_ATTR_LL_STATS_PEER_INFO_*
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_PEER_INFO = 68,

	/* Signifies the nested list of rate info attributes
	 * QCA_WLAN_VENDOR_ATTR_LL_STATS_RATE_*
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_PEER_INFO_RATE_INFO = 69,

	/* Signifies the nested list of wmm info attributes
	 * QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_AC_*
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_WMM_INFO = 70,

	/* Unsigned 8 bit value. Used by the driver; if set to 1, it indicates
	 * that more stats, e.g., peers or radio, are to follow in the next
	 * QCA_NL80211_VENDOR_SUBCMD_LL_STATS_*_RESULTS event.
	 * Otherwise, it is set to 0.
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RESULTS_MORE_DATA = 71,

	/* Unsigned 64 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_AVERAGE_TSF_OFFSET = 72,

	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_LEAKY_AP_DETECTED = 73,

	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_LEAKY_AP_AVG_NUM_FRAMES_LEAKED = 74,

	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_LEAKY_AP_GUARD_TIME = 75,

	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_TYPE = 76,

	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_NUM_TX_LEVELS = 77,

	/* Number of msecs the radio spent in transmitting for each power level
	 */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_RADIO_TX_TIME_PER_LEVEL = 78,

	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_RTS_SUCC_CNT = 79,
	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_RTS_FAIL_CNT = 80,
	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_PPDU_SUCC_CNT = 81,
	/* Unsigned 32 bit value */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_IFACE_PPDU_FAIL_CNT = 82,

	/* keep last */
	QCA_WLAN_VENDOR_ATTR_LL_STATS_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_LL_STATS_MAX =
	QCA_WLAN_VENDOR_ATTR_LL_STATS_AFTER_LAST - 1,
};

enum qca_wlan_vendor_attr_ll_stats_type
{
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_TYPE_INVALID = 0,
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_TYPE_RADIO = 1,
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_TYPE_IFACE = 2,
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_TYPE_PEERS = 3,

	/* keep last */
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_TYPE_AFTER_LAST,
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_TYPE_MAX =
	QCA_NL80211_VENDOR_SUBCMD_LL_STATS_TYPE_AFTER_LAST - 1,
};

/**
 * enum qca_wlan_vendor_attr_tdls_configuration - Attributes for
 * TDLS configuration to the host driver.
 *
 * @QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_TRIGGER_MODE: Configure the TDLS trigger
 *	mode in the host driver. enum qca_wlan_vendor_tdls_trigger_mode
 *	represents the different TDLS trigger modes.
 * @QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_TX_STATS_PERIOD: Duration (u32) within
 *      which QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_TX_THRESHOLD number
 *      of packets shall meet the criteria for implicit TDLS setup.
 * @QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_TX_THRESHOLD: Number (u32) of Tx/Rx packets
 *      within a duration QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_TX_STATS_PERIOD
 *      to initiate a TDLS setup.
 * @QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_DISCOVERY_PERIOD: Time (u32) to initiate
 *      a TDLS Discovery to the peer.
 * @QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_MAX_DISCOVERY_ATTEMPT: Max number (u32) of
 *      discovery attempts to know the TDLS capability of the peer. A peer is
 *      marked as TDLS not capable if there is no response for all the attempts.
 * @QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_IDLE_TIMEOUT: Represents a duration (u32)
 *      within which QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_IDLE_PACKET_THRESHOLD
 *      number of TX / RX frames meet the criteria for TDLS teardown.
 * @QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_IDLE_PACKET_THRESHOLD: Minimum number (u32)
 *      of Tx/Rx packets within a duration
 *      QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_IDLE_TIMEOUT to tear down a TDLS link.
 * @QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_SETUP_RSSI_THRESHOLD: Threshold
 *	corresponding to the RSSI of the peer below which a TDLS setup is
 *	triggered.
 * @QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_TEARDOWN_RSSI_THRESHOLD: Threshold
 *	corresponding to the RSSI of the peer above which a TDLS teardown is
 *	triggered.
 */
enum qca_wlan_vendor_attr_tdls_configuration {
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_INVALID = 0,
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_TRIGGER_MODE = 1,

	/* Attributes configuring the TDLS Implicit Trigger */
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_TX_STATS_PERIOD = 2,
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_TX_THRESHOLD = 3,
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_DISCOVERY_PERIOD = 4,
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_MAX_DISCOVERY_ATTEMPT = 5,
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_IDLE_TIMEOUT = 6,
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_IDLE_PACKET_THRESHOLD = 7,
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_SETUP_RSSI_THRESHOLD = 8,
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_TEARDOWN_RSSI_THRESHOLD = 9,

	/* keep last */
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_AFTER_LAST,
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_MAX =
	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_AFTER_LAST - 1
};

/**
 * enum qca_wlan_vendor_tdls_trigger_mode: Represents the TDLS trigger mode in
 *	the driver
 *
 * The following are the different values for
 *	QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_TRIGGER_MODE.
 *
 * @QCA_WLAN_VENDOR_TDLS_TRIGGER_MODE_EXPLICIT: The trigger to initiate/teardown
 *	the TDLS connection to a respective peer comes from the user space.
 *	wpa_supplicant provides the commands TDLS_SETUP, TDLS_TEARDOWN,
 *	TDLS_DISCOVER to do this.
 * @QCA_WLAN_VENDOR_TDLS_TRIGGER_MODE_IMPLICIT: Host driver triggers this TDLS
 *	setup/teardown to the eligible peer once the configured criteria
 *	(such as TX/RX threshold, RSSI) is met. The attributes
 *	in QCA_WLAN_VENDOR_ATTR_TDLS_CONFIG_IMPLICIT_PARAMS correspond to
 *	the different configuration criteria for the TDLS trigger from the
 *	host driver.
 * @QCA_WLAN_VENDOR_TDLS_TRIGGER_MODE_EXTERNAL: Enables the driver to trigger
 *	the TDLS setup / teardown through the implicit mode only to the
 *	configured MAC addresses (wpa_supplicant, with tdls_external_control=1,
 *	configures the MAC address through TDLS_SETUP / TDLS_TEARDOWN commands).
 *	External mode works on top of the implicit mode. Thus the host driver
 *	is expected to configure in TDLS Implicit mode too to operate in
 *	External mode.
 *	Configuring External mode alone without	Implicit mode is invalid.
 *
 * All the above implementations work as expected only when the host driver
 * advertises the capability WPA_DRIVER_FLAGS_TDLS_EXTERNAL_SETUP - representing
 * that the TDLS message exchange is not internal to the host driver, but
 * depends on wpa_supplicant to do the message exchange.
 */
enum qca_wlan_vendor_tdls_trigger_mode {
	QCA_WLAN_VENDOR_TDLS_TRIGGER_MODE_EXPLICIT = 1 << 0,
	QCA_WLAN_VENDOR_TDLS_TRIGGER_MODE_IMPLICIT = 1 << 1,
	QCA_WLAN_VENDOR_TDLS_TRIGGER_MODE_EXTERNAL = 1 << 2,
};

#endif /* QCA_VENDOR_H */
