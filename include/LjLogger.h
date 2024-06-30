#pragma once

#include "LoggerInterface.h"

namespace ljLog {

	class LjLogger : public LoggerInterface {

	public:

		LjLogger(const std::string&, std::ostream&);

		template<typename ...Args>
		void emergency(std::string&, Args&&...);

		template<typename ...Args>
		void alert(std::string&, Args&&...);

		template<typename ...Args>
		void critical(std::string&, Args&&...);

		template<typename ...Args>
		void error(std::string&, Args&&...);

		template<typename ...Args>
		void warning(std::string&, Args&&...);

		template<typename ...Args>
		void notice(std::string&, Args&&...);

		template<typename ...Args>
		void info(std::string&, Args&&...);

		template<typename ...Args>
		void debug(std::string&, Args&&...);

	private:

		typedef LoggerInterface super;

	};

	template<typename ...Args>
	inline void LjLogger::emergency(std::string& str, Args&&... args) {
		super::log(ljLog::E_EMERGENCY, str, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	inline void LjLogger::alert(std::string& str, Args&&... args) {
		super::log(ljLog::E_ALERT, str, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	inline void LjLogger::critical(std::string& str, Args&&... args) {
		super::log(ljLog::E_CRITICAL, str, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	inline void LjLogger::error(std::string& str, Args&&... args) {
		super::log(ljLog::E_ERROR, str, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	inline void LjLogger::warning(std::string& str, Args&&... args) {
		super::log(ljLog::E_WARNING, str, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	inline void LjLogger::notice(std::string& str, Args&&... args) {
		super::log(ljLog::E_NOTICE, str, std::forward<Args>(args)...);
	}


	template<typename ...Args>
	inline void LjLogger::info(std::string& str, Args&&... args) {
		super::log(ljLog::E_INFO, str, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	inline void LjLogger::debug(std::string& str, Args&&... args) {
		super::log(ljLog::E_DEBUG, str, std::forward<Args>(args)...);
	}
}
