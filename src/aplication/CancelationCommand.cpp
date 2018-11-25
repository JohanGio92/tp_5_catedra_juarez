#include "CancelationCommand.hpp"

CancelationCommand::CancelationCommand() : Command(". Cancelate the flight."){
}

void CancelationCommand::execute(AvlTree<Airport>& aiporTree) {
	Airport aiport;
	aiport.readCode("Please choose your code IATA for cancel the reservation: ");
	aiporTree.erase(aiport);
}

CancelationCommand::~CancelationCommand() {
}

