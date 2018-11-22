#ifndef CONSOLA_H_
#define CONSOLA_H_

#include <string>
#include <iostream>
#include <sstream>

class Console {
public:
	Console();
	static Console& instance();
	int readInt(std::string message);
	std::string readString(std::string message);
	double readDouble(std::string message);
	template <typename T>
	void write(T message);
	template <typename T>
	void writeln(T message);
	void writeln();
	void separate();
	virtual ~Console();
};

template<typename T>
void Console::write(T message) {
	std::cout << message;
}

template<typename T>
void Console::writeln(T message) {
	std::cout << message << std::endl;
}

template<typename T>
std::string toString(const T &value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

#endif
