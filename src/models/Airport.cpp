#include "Airport.hpp"

Airport::Airport(){
	IATACode = " ";
}

void Airport::read() {
	IATACode = Console::instance().readString("IATA: ");

//	std::string name = Console::instance().readString("Name: ");
//	std::string city = Console::instance().readString("City: ");
//	std::string country = Console::instance().readString("Country: ");
//	double surface = Console::instance().readDouble("Surface: ");
//	int cantOfTerminal = Console::instance().readInt("Cant of Terminal: ");
//	int nationalDestiny = Console::instance().readInt("National Destiny: ");
//	int internationalDestiny = Console::instance().readInt("International Destiny: ");
//
//	information = std::make_tuple(name, city, country, surface, cantOfTerminal,
//			nationalDestiny, internationalDestiny);
}

bool Airport::operator <(Airport& airport) {
	return this->IATACode < airport.IATACode;
}

bool Airport::operator >(Airport& airport) {
	return airport < *this;
}

bool Airport::operator >=(Airport& airport) {
	return !(*this < airport);
}

bool Airport::operator ==(Airport& airport) {
	return this->IATACode == airport.IATACode;
}

bool Airport::operator !=(Airport& airport) {
	return !(*this == airport);
}

std::ostream& operator<<(std::ostream& output, Airport& airport){
	output << airport.IATACode;
	return output;
}


Airport::~Airport() {
}

