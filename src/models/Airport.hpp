#ifndef MODELS_AIRPORT_HPP_
#define MODELS_AIRPORT_HPP_

#include <tuple>
#include "../utilities/Console.hpp"

typedef std::tuple<std::string,
		std::string, std::string,
		double, int, int, int> FlightInformation;

class Airport {
private:
	std::string IATACode;
	FlightInformation flightInformation;
public:
	Airport();
	Airport(std::string IATACode);
	void readCode(std::string message);
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
