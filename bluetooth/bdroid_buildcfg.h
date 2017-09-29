/*
 *
 *  Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *  Not a Contribution, Apache license notifications and license are retained
 *  for attribution purposes only.
 *
 * Copyright (C) 2012 The Android Open Source Project
 * Copyright (C) 2017 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H
#include <cutils/properties.h>
#include <string.h>

static inline const char* BtmGetDefaultName()
{
	char product_model[PROPERTY_VALUE_MAX];
	property_get("ro.product.model", product_model, "");

	if (strstr(product_model, "Y635-L01"))
		return "HUAWEI Y635-L01";
	if (strstr(product_model, "Y635-L02"))
		return "HUAWEI Y635-L02";
	if (strstr(product_model, "Y635-L03"))
		return "HUAWEI Y635-L01";
	if (strstr(product_model, "Y635-L11"))
		return "HUAWEI Y635-L11";
	if (strstr(product_model, "Y635-L21"))
		return "HUAWEI Y635-L21";

	return "";
}

#define BTM_DEF_LOCAL_NAME BtmGetDefaultName()
#define BLUETOOTH_QTI_SW TRUE
#define BLE_VND_INCLUDED   TRUE
#endif
