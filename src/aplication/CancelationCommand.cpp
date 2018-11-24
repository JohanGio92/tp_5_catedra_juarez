#include "CancelationCommand.hpp"

CancelationCommand::CancelationCommand() : Command(". Cancelate the flight."){
}

void CancelationCommand::execute(AvlTree<Airport>& aiporTree) {
	Airport aiport;
	aiport.readCode();
	aiporTree.erase(aiport);
}

CancelationCommand::~CancelationCommand() {
}

