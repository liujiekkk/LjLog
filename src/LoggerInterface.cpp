#include "LoggerInterface.h"
#include <sstream>
#include <ctime>
#include <iomanip>
#include <iostream>

// 设置默认报错等级.
unsigned ljLog::LoggerInterface::m_level = LogLevel::E_ALL;

ljLog::LoggerInterface::LoggerInterface(const std::string& appName, std::ostream& out)
	: m_output(out), m_appName(appName), m_levelInfo{ {E_DEBUG, "DEBUG"}, {E_INFO, "INFO"}, {E_NOTICE, "NOTICE"},
		{E_WARNING, "WARNING"}, {E_ERROR, "ERROR"}, {E_CRITICAL, "CRITICAL"}, {E_ALERT, "ALERT"}, {E_EMERGENCY, "EMERGENCY"}}
{
}

void ljLog::LoggerInterface::setLevel(unsigned level)
{
	m_level = level;
}

const std::string& ljLog::LoggerInterface::getStr(LogLevel level)
{
	return m_levelInfo[level];
}

ljLog::LoggerInterface::TimePoint ljLog::LoggerInterface::getTimePointNow()
{
	// 计算当前时间.
	return std::chrono::system_clock::now();
}

std::string ljLog::LoggerInterface::formatTimePoint(const TimePoint& tp, const std::string& format)
{
	// 转换为 time_t 类型.
	std::time_t now_c = std::chrono::system_clock::to_time_t(tp);
	// 获取毫秒部分.
	auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count() % 1000;
	std::stringstream ss;
	// 格式化时间格式.
	struct tm timeInfo;
	localtime_s(&timeInfo, &now_c);
	ss << std::put_time(&timeInfo, format.c_str()) << std::setfill('0') << std::setw(3) << milliseconds;
	return ss.str();
}

void ljLog::LoggerInterface::log(LogLevel level, std::string& format)
{
	// 递归结束函数，将记录的日志记录到输出流.
	std::string tmp(m_template);
	tmp.replace(tmp.find(m_placeholderLevel), m_placeholderLevel.size(), getStr(level));
	tmp.replace(tmp.find(m_placeholderAppName), m_placeholderAppName.size(), m_appName);
	tmp.replace(tmp.find(m_placeholderTime), m_placeholderTime.size(), formatTimePoint(getTimePointNow(), "%Y-%m-%d %H:%M:%S."));
	m_output << tmp << format << std::endl;
}
