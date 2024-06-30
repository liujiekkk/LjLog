#include <LjLogger.h>
#include <iostream>

void test(int num) {

	ljLog::LjLogger logger("app", std::cout);
	for (int i = 0; i < num; ++i) {
		std::string msg = "test log performance. {}";
		logger.debug(msg, std::to_string(i));
	}
}

int main() {

	// 设置错误等级.
	ljLog::LjLogger::setLevel(ljLog::E_ALL);
	ljLog::LjLogger log("lj", std::cout);

	test(1000);

	std::string msg;
	
	msg = "this is a error test: {} {}.";
	log.emergency(msg, "123", "456");

	msg = "this is a error test: {} {}.";
	log.critical(msg, "123", "456");

	msg = "this is a error test: {} {}.";
	log.alert(msg, "123", "456");

	msg = "this is a error test: {} {}.";
	log.error(msg, "123", "456");

	msg = "this is a error test: {} {}.";
	log.warning(msg, "123", "456");

	msg = "this is a error test: {} {}.";
	log.notice(msg, "123", "456");
	
	msg = "this is a error test: {} {}.";
	log.info(msg, "123", "456");

	msg = "this is a error test: {} {}.";
	log.debug(msg, "123", "456");

	return 0;
}
