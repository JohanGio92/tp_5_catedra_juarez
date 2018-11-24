#ifndef APLICATION_DISPLAYERCOMMAND_HPP_
#define APLICATION_DISPLAYERCOMMAND_HPP_

#include "Command.hpp"

class DisplayerCommand : public Command{
public:
	DisplayerCommand();
	virtual void execute(AvlTree<Airport>& aiportTree) override;
	virtual ~DisplayerCommand();
};

#endif
