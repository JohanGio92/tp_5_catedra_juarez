#include "Command.hpp"

Command::Command(std::string title) {
	this->title = title;
}

void Command::showTitle(int position) {
	Console::instance().writeln(toString(position) + title);
}

Command::~Command() {
}

