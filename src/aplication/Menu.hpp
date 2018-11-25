#ifndef APLICATION_MENU_HPP_
#define APLICATION_MENU_HPP_

#include "ExitCommand.hpp"
#include "../models/files/FlightRecord.hpp"

class Menu {
private:
	std::vector<Command*> commands;
	ExitCommand* exitCommand;
	AvlTree<Airport> airportTree;
public:
	Menu();
	void insert(Command* command);
	void exit();
	bool isFinished();
	void showTitle();
	unsigned size();
	void execute(int position);
	virtual ~Menu();
};

#endif
