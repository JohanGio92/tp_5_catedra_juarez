#ifndef CONSOLA_H_
#define CONSOLA_H_

#include <string>
#include <iostream>
#include <sstream>
#include <ostream>
#include <fstream>

class Console {
private:
	static int UNO;
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
	void writeLeftBranch();
	void writeRightBranch();
	void separate();
	void ignore();
	void clear();
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
