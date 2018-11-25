#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <vector>
#include <algorithm>
#include "../models/Airport.hpp"

#include "AvlNode.hpp"

template <class T>
class AvlTree {
private:
    int _size;
    AvlNode<T> *root;
    
    void balance(std::vector<AvlNode<T>**> path);
    void display(AvlNode<T>* cur, int depth=0, int state=0);
    
public:
    AvlTree();
    AvlTree(const AvlTree<T>& avlTree);
    ~AvlTree();
    
    void insert(T value);
    void erase(T value);
    
    void clear();
    bool empty() const;
    int size() const;
    
    int find(T value) const;
    int lowerBound(T value) const;
    int upperBound(T value) const;
    
    const T& findMin() const;
    const T& findMax() const;
    const T& operator[](int idx) const;
    void display();
};

#endif

