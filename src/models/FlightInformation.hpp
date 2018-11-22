#ifndef MODELS_FLIGHTINFORMATION_HPP_
#define MODELS_FLIGHTINFORMATION_HPP_

#include <string>

class FlightInformation {
private:
	std::string name;
	std::string city;
	std::string country;
	double surface;
	int cantOfTerminal;
	int nationalDestiny;
	int internationalDestiny;
public:
	FlightInformation(std::string name, std::string city, std::string country,
			double surface, int cantOfTerminal, int nationalDestiny,
			int internationalDestiny);
	int getCantOfTerminal() const;
	const std::string& getCity() const;
	const std::string& getCountry() const;
	int getInternationalDestiny() const;
	const std::string& getName() const;
	int getNationalDestiny() const;
	double getSurface() const;
	virtual ~FlightInformation();
};

#endif
