#pragma once

#include "LoggerInterface.h"

namespace ljLog {

	class LjLogger : public LoggerInterface {

	public:

		LjLogger(const std::string&, std::ostream&);
	};
}