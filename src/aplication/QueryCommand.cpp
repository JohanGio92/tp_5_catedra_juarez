#include "QueryCommand.h"

QueryCommand::QueryCommand() : Command(". Query the flight."){
}

void QueryCommand::execute(AvlTree<Airport>& aiportTree) {
	Airport airport;
	airport.readCode("Please look for your code: ");
	int position = aiportTree.find(airport);
	Console::instance().writeln(aiportTree[position]);
}

QueryCommand::~QueryCommand() {
}

