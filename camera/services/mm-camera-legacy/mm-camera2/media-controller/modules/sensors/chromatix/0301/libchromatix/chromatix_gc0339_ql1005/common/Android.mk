GC0339_QL1005_CHROMATIX_COMMON_PATH := $(call my-dir)

# ---------------------------------------------------------------------------
#                      Make the shared library (libchromatix_gc0339_ql1005_common)
# ---------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_PATH := $(GC0339_QL1005_CHROMATIX_COMMON_PATH)
LOCAL_MODULE_TAGS := optional

LOCAL_CFLAGS:= -DAMSS_VERSION=$(AMSS_VERSION) \
        $(mmcamera_debug_defines) \
        $(mmcamera_debug_cflags) \
        -include camera_defs_i.h

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../../../../common/
LOCAL_C_INCLUDES += chromatix_gc0339_ql1005_common.h

LOCAL_SRC_FILES:= chromatix_gc0339_ql1005_common.c

LOCAL_MODULE           := libchromatix_gc0339_ql1005_common
LOCAL_SHARED_LIBRARIES := libcutils liblog
include $(LOCAL_PATH)/../../../../../../../../../local_additional_dependency.mk

ifeq ($(MM_DEBUG),true)
LOCAL_SHARED_LIBRARIES += liblog
endif
LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)
