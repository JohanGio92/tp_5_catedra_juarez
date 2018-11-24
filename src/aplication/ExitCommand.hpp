#ifndef APLICATION_EXITCOMMAND_HPP_
#define APLICATION_EXITCOMMAND_HPP_

#include "Command.hpp"

class ExitCommand : public Command{
private:
	bool finished;
public:
	ExitCommand();
	virtual void execute(AvlTree<Airport>& aiporTree);
	bool isFinished();
	void leave();
	virtual ~ExitCommand();
};

#endif
