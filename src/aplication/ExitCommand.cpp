#include "ExitCommand.hpp"

ExitCommand::ExitCommand() : Command(". Exit"){
	finished = false;
}

void ExitCommand::execute(AvlTree<Airport>& aiporTree) {
	finished = true;
	this->leave();
	aiporTree.clear();
}

bool ExitCommand::isFinished() {
	return finished;
}

void ExitCommand::leave() {
	Console::instance().writeln("Thank you for visiting us, bye.");
}

ExitCommand::~ExitCommand() {
}

