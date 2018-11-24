#include "Airport.hpp"

Airport::Airport(){
}

Airport::Airport(std::string IATACode) : IATACode(IATACode){
}

void Airport::readCode() {
	IATACode = Console::instance().readString("IATA: ");
}

void Airport::read() {
	readCode();
	std::string name = Console::instance().readString("Name: ");
	std::string city = Console::instance().readString("City: ");
	std::string country = Console::instance().readString("Country: ");
	double surface = Console::instance().readDouble("Surface: ");
	int cantOfTerminal = Console::instance().readInt("Cant of Terminal: ");
	int nationalDestiny = Console::instance().readInt("National Destiny: ");
	int internationalDestiny = Console::instance().readInt("International Destiny: ");
//	std::cin.ignore();

	information = std::make_tuple(name, city, country, surface, cantOfTerminal,
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
	output << airport.IATACode;
	return output;
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
	information = std::make_tuple(name, city, country, surface, cantOfTerminal,
			nationalDestiny, internationalDestiny);
}


Airport::~Airport() {
}

