#include "Console.hpp"

Console::Console() {
}

Console& Console::instance() {
	static Console _instance;
	return _instance;
}

int Console::readInt(std::string message) {
	int input;
	this->write(message);
	std:: cin >> input;
	return input;
}

std::string Console::readString(std::string message) {
	std::string input;
	this->write(message);
	std::getline(std::cin, input);
	return input;
}


double Console::readDouble(std::string message) {
	double input;
	this->write(message);
	std::cin >> input;
	return input;
}

Console::~Console() {
}

void Console::separate() {
	this->write("-----------------------------------------");
}

