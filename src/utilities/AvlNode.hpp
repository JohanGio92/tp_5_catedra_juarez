#ifndef AVLTreeNode_hpp
#define AVLTreeNode_hpp

#include <string>
#include <algorithm>

template <class T>
struct AvlNode {
    AvlNode *left;
    AvlNode *right;
    
    const T value;
    int count;
    int height;
    
    AvlNode(T value);
    void updateValues();
    int balanceFactor();
    
    AvlNode* left_rotate();
    AvlNode* right_rotate();
};

#endif
