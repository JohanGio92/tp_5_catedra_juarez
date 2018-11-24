#include "ClosedInterval.hpp"

ClosedInterval::ClosedInterval() :
		_min(0), _max(0) {
}

ClosedInterval* ClosedInterval::min(int min) {
	_min = min;
	return this;
}

ClosedInterval* ClosedInterval::max(int max) {
	_max = max;
	return this;
}

ClosedInterval& ClosedInterval::instance() {
	static ClosedInterval _instance;
	return _instance;
}

bool ClosedInterval::include(int element){
	return _min <= element && element <= _max;
}

int ClosedInterval::read(std::string title) {
	int input;
	do {
		input = Console::instance().readInt(title);
		if(!this->include(input)) Console::instance().writeln("¡¡Try again!!");
	} while (!this->include(input));

	return input-1;
}

ClosedInterval::~ClosedInterval() {
}

