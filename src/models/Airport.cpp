#include "Airport.hpp"

Airport::Airport(){
}

Airport::Airport(std::string IATACode) : IATACode(IATACode){
}

void Airport::readCode(std::string message) {
	IATACode = Console::instance().readString(message);
}

void Airport::read() {
	std::string IATACode, name, city, country;
	double surface;
	int cantOfTerminal, nationalDestiny, internationalDestiny;

	readCode("Code IATA: ");
	name = Console::instance().readString("Name: ");
	city = Console::instance().readString("City: ");
	country = Console::instance().readString("Country: ");
	surface = Console::instance().readDouble("Surface: ");
	cantOfTerminal = Console::instance().readInt("Cant of Terminal: ");
	nationalDestiny = Console::instance().readInt("National Destiny: ");
	internationalDestiny = Console::instance().readInt("International Destiny: ");

	flightInformation = std::make_tuple(name, city, country, surface, cantOfTerminal,
			nationalDestiny, internationalDestiny);
}

void Airport::read(std::ifstream& entryRoute) {
	std::string IATACode, name, city, country;
	double surface;
	int cantOfTerminal, nationalDestiny, internationalDestiny;

	entryRoute >> IATACode;
	if (!entryRoute.eof()) {
		entryRoute >> name >> city >> country >> surface >> cantOfTerminal
				>> nationalDestiny >> internationalDestiny;
	}

	this->IATACode = IATACode;
	flightInformation = std::make_tuple(name, city, country, surface, cantOfTerminal,
			nationalDestiny, internationalDestiny);
}

bool Airport::operator <(Airport& airport) {
	return this->IATACode < airport.IATACode;
}

bool Airport::operator >(Airport& airport) {
	return airport < *this;
}

bool Airport::operator >=(Airport& airport) {
	return !(airport < *this);
}

bool Airport::operator <=(Airport& airport) {
	return !(*this < airport);
}

bool Airport::operator ==(Airport& airport) {
	return this->IATACode == airport.IATACode;
}

bool Airport::operator !=(Airport& airport) {
	return !(*this == airport);
}

std::ostream& operator<<(std::ostream& output, Airport& airport){
	output << airport.IATACode << ":[" << std::get<0>(airport.flightInformation)
			<< ", " << std::get<1>(airport.flightInformation) << ", "
			<< std::get<2>(airport.flightInformation) << ", " << std::get<3>(airport.flightInformation)
			<< ", " << std::get<4>(airport.flightInformation) << ", "
			<< std::get<5>(airport.flightInformation) << ", " << std::get<6>(airport.flightInformation)
			<< "]";
	return output;
}

Airport::~Airport() {
}

