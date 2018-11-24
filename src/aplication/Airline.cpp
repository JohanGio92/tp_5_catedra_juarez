#include "Airline.hpp"

#include "../utilities/ClosedInterval.hpp"
#include "CancelationCommand.hpp"
#include "DisplayerCommand.hpp"
#include "RegistrationCommand.hpp"

Airline::Airline() {
	menu.insert(new DisplayerCommand());
	menu.insert(new RegistrationCommand());
	menu.insert(new CancelationCommand());
	menu.exit();
}

void Airline::sellPackages() {
	do{
		menu.showTitle();
		int position = ClosedInterval::instance().min(1)->max(menu.size())->read("which option? ");
		menu.execute(position);
	}while(!menu.isFinished());
}

Airline::~Airline() {
}

