#pragma once

#include "evpp/platform_config.h"

#ifdef __cplusplus

#define LOG_TRACE std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_DEBUG std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_INFO  std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_WARN  std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_ERROR std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_FATAL std::cout << __FILE__ << ":" << __LINE__ << " "
#define CHECK_NOTnullptr(val) LOG_ERROR << "'" #val "' Must be non nullptr";
#ifdef _DEBUG
#define DLOG_TRACE LOG_TRACE
#define DLOG_WARN LOG_WARN
#else
#define DLOG_TRACE if (false) LOG_TRACE
#define DLOG_WARN if (false) LOG_WARN
#endif

#endif