# <license_header>
#
# Copyright (c) 2015-2016 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# </license_header>
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(ipmb)
add_subdirectory(command)
add_subdirectory(status)
add_subdirectory(loader)

add_library(chassis-commands STATIC
    $<TARGET_OBJECTS:chassis-command-sdv>
)

add_library(chassis-utils
    $<TARGET_OBJECTS:chassis-status-impl>
    $<TARGET_OBJECTS:chassis-loader>
)

add_library(chassis-ipmb
    $<TARGET_OBJECTS:ipmb-service>
    $<TARGET_OBJECTS:ipmb-service-command>
)

add_executable(psme-chassis
    main.cpp
)

target_link_libraries(psme-chassis
    ${AGENT_CHASSIS_LIBRARIES}
    chassis-utils
    chassis-ipmb
    ${AGENT_FRAMEWORK_LIBRARIES}
    ${UUID_LIBRARIES}
    ${LOGGER_LIBRARIES}
    ${PCA95XX_LIBRARIES}
    ${SAFESTRING_LIBRARIES}
    ${CONFIGURATION_LIBRARIES}
    ${JSONCXX_LIBRARIES}
    ipmi
    ${BASE64_LIBRARIES}
    ipmicmd
    pthread
    jsonrpccpp-server
    jsonrpccpp-client
    jsonrpccpp-common
    jsoncpp
    ${MICROHTTPD_LIBRARIES}
    ${CURL_LIBRARIES}
    ${CY_USB_SERIAL_LIBRARIES}
    md5
)
