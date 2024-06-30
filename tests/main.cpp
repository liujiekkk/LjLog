#include <LjLogger.h>
#include <iostream>


int main() {

	// 设置错误等级.
	ljLog::LjLogger::setLevel(ljLog::E_NOTICE ^ ljLog::E_WARNING);
	ljLog::LjLogger log("lj", std::cout);
	std::string msg = "test {} {} {} msg.";
	log.log(ljLog::E_WARNING, msg, "arg", "arg1");
	return 0;
}