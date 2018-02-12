#pragma once

#include "evpp/platform_config.h"

#ifdef __cplusplus

#ifdef EVPP_OPEN_LOG

#define LOG_TRACE std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_DEBUG std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_INFO  std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_WARN  std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_ERROR std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_FATAL std::cout << __FILE__ << ":" << __LINE__ << " "
#define DLOG_TRACE LOG_TRACE
#define DLOG_WARN LOG_WARN
#define CHECK_NOTnullptr(val) LOG_ERROR << "'" #val "' Must be non nullptr";

#else

#define LOG_TRACE if(false) std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_DEBUG if(false) std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_INFO  if(false) std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_WARN  if(false) std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_ERROR if(false) std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_FATAL if(false) std::cout << __FILE__ << ":" << __LINE__ << " "
#define DLOG_TRACE LOG_TRACE
#define DLOG_WARN LOG_WARN
#define CHECK_NOTnullptr(val) LOG_ERROR << "'" #val "' Must be non nullptr";

#endif

#endif