#ifndef APLICATION_QUERYCOMMAND_H_
#define APLICATION_QUERYCOMMAND_H_

#include "Command.hpp"

class QueryCommand : public Command {
public:
	QueryCommand();
	virtual void execute(AvlTree<Airport>& aiportTree) override;
	virtual ~QueryCommand();
};

#endif
