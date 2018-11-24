#include "Menu.hpp"

#include "../models/files/FlightRecord.hpp"

Menu::Menu() {
	exitCommand = nullptr;
	FlightRecord flighRecord;
	flighRecord.toTree(airportTree);
}

void Menu::insert(Command* command) {
	commands.push_back(command);
}

void Menu::exit() {
	exitCommand = new ExitCommand();
	commands.push_back(exitCommand);
}

bool Menu::isFinished() {
	return exitCommand->isFinished();
}

void Menu::showTitle() {
	Console::instance().separate();
	Console::instance().writeln();
	for (unsigned i = 0; i < commands.size(); ++i) {
		commands[i]->showTitle(i + 1);
	}
	Console::instance().separate();
	Console::instance().writeln();
}

unsigned Menu::size() {
	return commands.size();
}

Menu::~Menu() {
	for (unsigned i = 0; i < commands.size(); ++i) {
		delete commands[i];
	}
}

void Menu::execute(int position) {
	commands[position]->execute(airportTree);
}
