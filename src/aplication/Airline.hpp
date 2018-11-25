#ifndef APLICATION_AIRLINE_HPP_
#define APLICATION_AIRLINE_HPP_

#include "Menu.hpp"
#include "../utilities/ClosedInterval.hpp"

class Airline {
private:
	Menu menu;
public:
	Airline();
	void sellPackages();
	virtual ~Airline();
};

#endif
