#include "utilities/AvlTree.hpp"
#include "utilities/Console.hpp"


using namespace std;

int main() {

	AvlTree<int> avlTree;

	for (int i = 0; i < 15; ++i) {
		avlTree.insert(i);
	}

	avlTree.display();

	for (int i = 0; i < 5; ++i) {
		avlTree.erase(i*2);
	}

	for (int i = 0; i < avlTree.size(); ++i) {
		Console::instance().write(avlTree[i]);
	}

	return 0;
}
