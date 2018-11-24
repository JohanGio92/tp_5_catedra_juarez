#ifndef APLICATION_CANCELATIONCOMMAND_HPP_
#define APLICATION_CANCELATIONCOMMAND_HPP_

#include "Command.hpp"

class CancelationCommand : public Command{
public:
	CancelationCommand();
	virtual void execute(AvlTree<Airport>& aiporTree) override;
	virtual ~CancelationCommand();
};

#endif
