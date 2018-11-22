#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "AvlNode.hpp"

template <class T>
class AvlTree {
    int _size;
    AvlNode<T> *root;
    
    void balance(std::vector<AvlNode<T>**> path);
    void display(AvlNode<T>* cur, int depth=0, int state=0);
    
public:
    AvlTree();
    ~AvlTree();
    
    void insert(T value);
    void erase(T value);
    
    void clear();
    bool empty() const;
    int size() const;
    
    int find(T value) const;
    int lower_bound(T value) const;
    int upper_bound(T value) const;
    
    const T& find_min() const;
    const T& find_max() const;
    const T& operator[](int idx) const;
    
    void display();
};

#endif
