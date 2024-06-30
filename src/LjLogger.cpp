#include "LjLogger.h"
#include <string>


ljLog::LjLogger::LjLogger(const std::string& appName, std::ostream& out): LoggerInterface(appName, out)
{
}