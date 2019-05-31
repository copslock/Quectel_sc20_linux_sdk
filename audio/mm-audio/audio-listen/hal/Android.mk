ifeq ($(strip $(AUDIO_FEATURE_ENABLED_LISTEN)),true)

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS := -DPLATFORM_DEFAULT

ifneq ($(filter msm8974,$(TARGET_BOARD_PLATFORM)),)
    LOCAL_CFLAGS := -DPLATFORM_MSM8974
endif

ifneq ($(filter apq8084 msm8994 msm8992 msm8996 msm8998 msm8953 msm8937 apq8098_latv sdm845 msmnile $(MSMSTEPPE),$(TARGET_BOARD_PLATFORM)),)
    LOCAL_CFLAGS := -DPLATFORM_APQ8084
endif

LOCAL_SRC_FILES := \
    src/listen_hw.c \
    src/listen_platform.c

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    liblog \
    libdl \
    libtinyalsa \
    libaudioroute \
    libexpat

LOCAL_C_INCLUDES += \
    $(LOCAL_PATH)/inc \
    external/tinyalsa/include \
    external/expat/lib \
    $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include \
    $(call include-path-for, audio-route)
LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/techpack/audio/include
LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr
ifeq ($(strip $(AUDIO_FEATURE_ENABLED_DLKM)),true)
  LOCAL_HEADER_LIBRARIES := audio_kernel_headers
  LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/vendor/qcom/opensource/audio-kernel/include
  LOCAL_ADDITIONAL_DEPENDENCIES += $(BOARD_VENDOR_KERNEL_MODULES)
endif

LOCAL_COPY_HEADERS_TO   := mm-audio/audio-listen
LOCAL_COPY_HEADERS      := inc/listen_types.h

LOCAL_MODULE := liblistenhardware
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_SHARED_LIBRARY)

endif
