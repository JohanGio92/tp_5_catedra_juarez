#ifndef APLICATION_REGISTRATIONCOMMAND_HPP_
#define APLICATION_REGISTRATIONCOMMAND_HPP_

#include "Command.hpp"

class RegistrationCommand : public Command{
public:
	RegistrationCommand();
	virtual void execute(AvlTree<Airport>& aiporTree);
	virtual ~RegistrationCommand();
};

#endif
