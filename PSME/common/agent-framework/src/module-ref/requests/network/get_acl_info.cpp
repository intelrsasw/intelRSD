/*!
 * @section LICENSE
 *
 * @copyright
 * Copyright (c) 2016 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @section DESCRIPTION
 *
 * @file requests/network/get_acl_info.cpp
 *
 * @brief Network request GetAclInfo implementation
 * */

#include "agent-framework/module-ref/requests/network/get_acl_info.hpp"
#include "agent-framework/module-ref/constants/common.hpp"
#include "agent-framework/module-ref/constants/command.hpp"

#include <json/json.h>

using namespace agent_framework::model::requests;
using namespace agent_framework::model::literals;
using namespace agent_framework::model;

GetAclInfo::GetAclInfo(const std::string& acl): m_acl(acl) {}

Json::Value GetAclInfo::to_json() const {
    Json::Value value;
    value[Acl::ACL] = m_acl;
    return value;
}

GetAclInfo GetAclInfo::from_json(const Json::Value& json) {
    return GetAclInfo{json[Acl::ACL].asString()};
}
