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
AvlNode<T>* AvlNode<T>::leftRotate(){
    AvlNode* _right = right;
    right = right->left;
    _right->left = this;
    
    this->updateValues();
    _right->updateValues();
    
    return _right;
}

template <class T>
AvlNode<T>* AvlNode<T>::rightRotate(){
    AvlNode* _left = left;
    left = left->right;
    _left->right = this;
    
    this->updateValues();
    _left->updateValues();
    
    return _left;
}

template<class T>
AvlNode<T>* AvlNode<T>::leftRightRotate() {
	right = right->rightRotate();
	return this->leftRotate();
}

template<class T>
AvlNode<T>* AvlNode<T>::rightLeftRotate() {
	left = left->leftRotate();
	return this->rightRotate();
}

template class AvlNode<int>;
template class AvlNode<short>;
template class AvlNode<long>;
template class AvlNode<long long>;
template class AvlNode<std::string>;
template class AvlNode<Airport>;
template class AvlNode<Airport*>;
