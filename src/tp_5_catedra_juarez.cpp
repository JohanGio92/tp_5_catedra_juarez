#include "utilities/AvlTree.hpp"
#include "utilities/Console.hpp"
#include "models/Airport.hpp"
#include <tuple>

using namespace std;

int main() {

	AvlTree<Airport> avlTree;

	for (int i = 0; i < 8; ++i) {
		Airport airport;
		airport.read();
		avlTree.insert(airport);
	}

	avlTree.display();

//	for (int i = 0; i < 5; ++i) {
//		avlTree.erase(i*2);
//	}

	for (int i = 0; i < avlTree.size(); ++i) {
		Console::instance().writeln(avlTree[i]);
	}

	return 0;
}
