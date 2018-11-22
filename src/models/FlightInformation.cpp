#include "FlightInformation.hpp"

FlightInformation::FlightInformation(std::string name, std::string city,
		std::string country, double surface, int cantOfTerminal,
		int nationalDestiny, int internationalDestiny) :
		name(name), city(city), country(country), surface(surface), cantOfTerminal(
				cantOfTerminal), nationalDestiny(nationalDestiny), internationalDestiny(
				internationalDestiny) {
}

int FlightInformation::getCantOfTerminal() const {
	return cantOfTerminal;
}

const std::string& FlightInformation::getCity() const {
	return city;
}

const std::string& FlightInformation::getCountry() const {
	return country;
}

int FlightInformation::getInternationalDestiny() const {
	return internationalDestiny;
}

const std::string& FlightInformation::getName() const {
	return name;
}

int FlightInformation::getNationalDestiny() const {
	return nationalDestiny;
}

double FlightInformation::getSurface() const {
	return surface;
}

FlightInformation::~FlightInformation() {
}

