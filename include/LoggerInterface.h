#pragma once

#include <string>
#include <unordered_map>
#include <chrono>

namespace ljLog {

	// 设置日志错误等级
	enum LogLevel {
		E_NONE = 0B00000000,
		E_DEBUG = 0B00000001,
		E_INFO = 0B00000010,
		E_NOTICE = 0B00000100,
		E_WARNING = 0B00001000,
		E_ERROR = 0B00010000,
		E_CRITICAL = 0B00100000,
		E_ALERT = 0B01000000,
		E_EMERGENCY = 0B10000000,
		E_ALL = 0B11111111
	};

	class LoggerInterface {

	public:

		virtual ~LoggerInterface() {}

		static void setLevel(unsigned);

		// 记录指定的日志参数到输出流.只针对std::string/const char*
		template <typename First, typename ...Args>
		void log(LogLevel, std::string&, First&&, Args&&...);


	protected:

		typedef std::chrono::system_clock::time_point TimePoint;

		LoggerInterface(const std::string&, std::ostream&);

		const std::string& getStr(LogLevel);

		// 获取当前的时间点.
		TimePoint getTimePointNow();

		// 格式化时间点.
		std::string formatTimePoint(const TimePoint&, const std::string&);

	private:

		// 当前错误等级.
		static unsigned m_level;

		// 输出流对象引用.
		std::ostream& m_output;

		std::string m_appName;

		std::string m_placeholderLevel = "{level}";

		std::string m_placeholderAppName = "{app}";

		std::string m_placeholderTime = "{time}";

		std::string m_placeholderArgs = "{}";

		std::string m_template = "[" + m_placeholderLevel + "] " + m_placeholderAppName + " " + m_placeholderTime + " > ";

		std::unordered_map<LogLevel, std::string> m_levelInfo;
	
		// 递归结束函数.
		void log(LogLevel, std::string&);
		
	};

	template<typename First, typename ...Args>
	inline void LoggerInterface::log(LogLevel level, std::string& format, First&& first, Args && ... args)
	{
		// 判断是否符合错误等级.
		if (!(level & m_level)) {
			return;
		}
		// 查找占位符的位置.
		size_t pos = format.find(m_placeholderArgs);
		// 如果找不到替换占位符直接结束.
		if (pos == std::string::npos) {
			return;
		}
		// 替换占位符为参数内容.
		format.replace(pos, m_placeholderArgs.size(), first);
		// 递归替换各个参数.
		log(level, format, std::forward<Args>(args)...);
	}
}
