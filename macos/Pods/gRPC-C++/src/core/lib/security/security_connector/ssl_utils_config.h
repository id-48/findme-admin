/*
 *
 * Copyright 2019 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GRPC_CORE_LIB_SECURITY_SECURITY_CONNECTOR_SSL_UTILS_CONFIG_H
#define GRPC_CORE_LIB_SECURITY_SECURITY_CONNECTOR_SSL_UTILS_CONFIG_H

#include <grpc/support/port_platform.h>

#include "src/core/lib/gprpp/global_config.h"
#include "src/core/lib/gprpp/memory.h"

GPR_GLOBAL_CONFIG_DECLARE_STRING(grpc_default_ssl_roots_file_path);
GPR_GLOBAL_CONFIG_DECLARE_BOOL(grpc_not_use_system_ssl_roots);

#endif /* GRPC_CORE_LIB_SECURITY_SECURITY_CONNECTOR_SSL_UTILS_CONFIG_H \
        */
