#ifndef MODELS_AIRPORT_HPP_
#define MODELS_AIRPORT_HPP_

#include <string>
#include "FlightInformation.hpp"
#include <tuple>
#include "../utilities/Console.hpp"
#include <fstream>
#include <iostream>
#include <ostream>

typedef std::tuple<std::string,
		std::string, std::string,
		double, int, int, int> Information;

class Airport {
private:
	std::string IATACode;
	Information information;
public:
	Airport();
	Airport(std::string IATACode);
	void readCode();
	void read();
	void read(std::ifstream& entryRoute);
	bool operator<(Airport& airport);
	bool operator>(Airport& airport);
	bool operator>=(Airport& airport);
	bool operator<=(Airport& airport);
	bool operator==(Airport& airport);
	bool operator!=(Airport& airport);
	friend std::ostream& operator<<(std::ostream& output, Airport& airport);
	virtual ~Airport();
};

#endif
