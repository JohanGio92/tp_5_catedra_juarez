#include "RegistrationCommand.hpp"

RegistrationCommand::RegistrationCommand() : Command(". register to the flight.") {
}

void RegistrationCommand::execute(AvlTree<Airport>& aiporTree) {
	Airport airport;
	airport.read();
	aiporTree.insert(airport);
}

RegistrationCommand::~RegistrationCommand() {
}

