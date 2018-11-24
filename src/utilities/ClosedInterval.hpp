#ifndef UTILS_CLOSEDINTERVAL_H_
#define UTILS_CLOSEDINTERVAL_H_

#include <string>
#include "Console.hpp"

class ClosedInterval {
private:
	int _min;
	int _max;
private:
	ClosedInterval();
	bool include(int element);
public:
	static ClosedInterval& instance();
	ClosedInterval* min(int min);
	ClosedInterval* max(int max);
	int read(std::string title);
	virtual ~ClosedInterval();
};

#endif
