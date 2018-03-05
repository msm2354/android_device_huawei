#
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit from these products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit device configuration
$(call inherit-product, device/huawei/hwY635/device.mk)

# Inherit some common LineageOS stuff.
$(call inherit-product, vendor/dot/config/common.mk)

PRODUCT_DEVICE := hwY635
PRODUCT_NAME := dot_hwY635
PRODUCT_BRAND := Huawei
PRODUCT_MODEL := hwY635
PRODUCT_MANUFACTURER := HUAWEI

PRODUCT_GMS_CLIENTID_BASE := android-huawei

#Dot

WITH_MAGISK := true
