#ifndef MODELS_FILES_FLIGHTRECORD_HPP_
#define MODELS_FILES_FLIGHTRECORD_HPP_

#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "../../utilities/AvlTree.hpp"
#include "../Airport.hpp"

class FlightRecord {
private:
	static const std::string FILE_NAME;
	std::ifstream entryRoute;
public:
	FlightRecord();
	void toTree(AvlTree<Airport>& airportsTree);
	virtual ~FlightRecord();
};

#endif
