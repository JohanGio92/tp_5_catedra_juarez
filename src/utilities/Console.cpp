#include "Console.hpp"

int Console::UNO = 1;

Console::Console() {
}

Console& Console::instance() {
	static Console _instance;
	return _instance;
}

int Console::readInt(std::string message) {
	int input;
	this->write(message);
	std::cin >> input;
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

void Console::separate() {
	this->write("-----------------------------------------");
}

void Console::writeln(){
	std::cout << std::endl;
}

void Console::writeRightBranch() {
	std::cout << "┌───";
}

void Console::writeLeftBranch() {
	std::cout << "└───";
}

void Console::ignore() {
	std::cin.ignore();
}

void Console::clear() {
	std::cin.clear();
}

Console::~Console() {
}

