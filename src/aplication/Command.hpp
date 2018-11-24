#ifndef APLICATION_COMMAND_HPP_
#define APLICATION_COMMAND_HPP_

#include <string>
#include "../models/Airport.hpp"
#include "../utilities/AvlTree.hpp"

class Command {
private:
	std::string title;
public:
	Command(std::string title);
	void showTitle(int position);
	virtual void execute(AvlTree<Airport>& aiportTree) = 0;
	virtual ~Command();
};

#endif
