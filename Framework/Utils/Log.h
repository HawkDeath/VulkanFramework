#ifndef _LOG_H
#define _LOG_H

#include <spdlog/spdlog.h>
#include <exception>

#define UNUSE(x) (void)x

// TODO: add more information like file; line and condition
#define RT_THROW(...)  throw std::runtime_error(__VA_ARGS__)

#define LOG(...) spdlog::info(__VA_ARGS__)
#define WLOG(...) spdlog::warn(__VA_ARGS__)
#define ELOG(...) spdlog::error(__VA_ARGS__)

#endif // !_LOG_H
