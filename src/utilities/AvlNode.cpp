#include "AvlNode.hpp"
#include "../models/Airport.hpp"

template <class T>
AvlNode<T>::AvlNode(T value): value(value){
    count = 1;
    height = 1;
    
    left = nullptr;
    right = nullptr;
}

template <class T>
void AvlNode<T>::updateValues(){
    count = (left != nullptr ? left->count : 0) + (right != nullptr ? right->count : 0) + 1;
    
    height = std::max(left != nullptr ? left->height : 0,
                      right != nullptr ? right->height : 0) + 1;
}

template <class T>
int AvlNode<T>::balanceFactor(){
    return (left != nullptr ? left->height : 0) - (right != nullptr ? right->height: 0);
}

template <class T>
AvlNode<T>* AvlNode<T>::left_rotate(){
    AvlNode* R = right;
    right = right->left;
    R->left = this;
    
    this->updateValues();  // the order is important
    R->updateValues();
    
    return R;
}

template <class T>
AvlNode<T>* AvlNode<T>::right_rotate(){
    AvlNode* L = left;
    left = left->right;
    L->right = this;
    
    this->updateValues();  // the order is important
    L->updateValues();
    
    return L;
}

template class AvlNode<int>;
template class AvlNode<short>;
template class AvlNode<long>;
template class AvlNode<long long>;
template class AvlNode<std::string>;
template class AvlNode<Airport>;
