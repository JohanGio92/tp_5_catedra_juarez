#ifndef APLICATION_AIRLINE_HPP_
#define APLICATION_AIRLINE_HPP_

#include "../models/Airport.hpp"
#include "../utilities/AvlTree.hpp"
#include "Menu.hpp"

class Airline {
private:
	Menu menu;
public:
	Airline();
	void sellPackages();
	virtual ~Airline();
};

#endif
