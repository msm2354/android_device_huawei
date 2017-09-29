/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <fstream>
#include <string>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm8916.h"

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void init_target_properties()
{
    std::ifstream fin;
    std::string buf;

    fin.open("/proc/app_info");
    while (getline(fin, buf))
        if (buf.find("huawei_fac_product_name") != std::string::npos)
            break;
    fin.close();

    /* Y635-L01 */
    if (buf.find("Y635-L01") != std::string::npos) {
        property_override("ro.product.model", "Y635-L01");
        property_override("ro.product.name", "Y635-L01");
        property_override("ro.product.device", "Y635-L01");
        property_override("ro.build.product", "Y635-L01");
        property_set("ro.build.description", "Y635-L01-user 4.4.4 GRJ90 C21B131 release-keys");
        property_set("ro.build.fingerprint", "Huawei/Y635-L01/hwY635:4.4.4/HuaweiY635-L01/C21B131:user/release-keys");
	}
    /* Y635-L02 */
    else if (buf.find("Y635-L02") != std::string::npos) {
        property_override("ro.product.model", "Y635-L02");
        property_override("ro.product.name", "Y635-L02");
        property_override("ro.product.device", "Y635-L02");
        property_override("ro.build.product", "Y635-L02");
	}
    /* Y635-L03 */
    else if (buf.find("Y635-L03") != std::string::npos) {
        property_override("ro.product.model", "Y635-L03");
        property_override("ro.product.name", "Y635-L03");
        property_override("ro.product.device", "Y635-L03");
        property_override("ro.build.product", "Y635-L03");
        property_set("ro.build.description", "Y635-L03-user 4.4.4 GRJ90 C69B003 release-keys");
        property_set("ro.build.fingerprint", "Huawei/Y635-L03/hwY635:4.4.4/HuaweiY635-L03/C69B003:user/release-keys");
	}
    /* Y635-L11 */
    else if (buf.find("Y635-L11") != std::string::npos) {
        property_override("ro.product.model", "Y635-L11");
        property_override("ro.product.name", "Y635-L11");
        property_override("ro.product.device", "Y635-L11");
        property_override("ro.build.product", "Y635-L11");
	}
    /* Y635-L21 */
    else if (buf.find("Y635-L21") != std::string::npos) {
        property_override("ro.product.model", "Y635-L21");
        property_override("ro.product.name", "Y635-L21");
        property_override("ro.product.device", "Y635-L21");
        property_override("ro.build.product", "Y635-L21");
	}
}
