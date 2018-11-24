#include "DisplayerCommand.hpp"

DisplayerCommand::DisplayerCommand() : Command(". Display available flight."){
}

void DisplayerCommand::execute(AvlTree<Airport>& aiportTree) {
	aiportTree.display();
}

DisplayerCommand::~DisplayerCommand() {
}

