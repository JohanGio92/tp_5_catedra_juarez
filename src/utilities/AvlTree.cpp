#include "AvlTree.hpp"
#include "../models/Airport.hpp"

template <class T>
AvlTree<T>::AvlTree(){
    root = nullptr;
    _size = 0;
}

template <class T>
AvlTree<T>::~AvlTree(){
    clear();
}

template <class T>
void AvlTree<T>::clear(){
    std::vector<AvlNode<T>*> stack;
    
    if (root != nullptr)
        stack.push_back(root);
    
    while (!stack.empty()){
        AvlNode<T> *node = stack.back();
        stack.pop_back();
        
        if (node->left != nullptr)
            stack.push_back(node->left);
        
        if (node->right != nullptr)
            stack.push_back(node->right);
        
        _size--;
        delete node;
    }
    
    root = nullptr;
}

template <class T>
void AvlTree<T>::insert(T value){
    AvlNode<T> **indirect = &root;
    std::vector<AvlNode<T>**> path;
    
    while (*indirect != nullptr){
        path.push_back(indirect);
        
        if ((*indirect)->value > value)
            indirect = &((*indirect)->left);
        else if ((*indirect)->value < value)
            indirect = &((*indirect)->right);
        else
        	return ;
    }
    
    *indirect = new AvlNode<T>(value);
    path.push_back(indirect);
    
    balance(path);
    _size++;
}

template <class T>
void AvlTree<T>::erase(T value){
    AvlNode<T> **indirect = &root;
    std::vector<AvlNode<T>**> path;
    
    while (*indirect != nullptr and (*indirect)->value != value){
        path.push_back(indirect);
        
        if ((*indirect)->value > value)
            indirect = &((*indirect)->left);
        else
            indirect = &((*indirect)->right);
    }
    
    if (*indirect == nullptr)
        return;
    
    else
        path.push_back(indirect);
    
    std::size_t index = path.size();
    
    if ((*indirect)->left == nullptr and (*indirect)->right == nullptr){  // the node is leaf
        delete *indirect;  // just delete node
        *indirect = nullptr;
        path.pop_back();  // pop the deleted node from path
    }
    
    else if ((*indirect)->right == nullptr){  // only left child exists
        AvlNode<T> *toRemove = *indirect;
        
        (*indirect) = (*indirect)->left;
        delete toRemove;
        
        path.pop_back();
    }
    
    else{  // right child exists
        AvlNode<T> **successor = &((*indirect)->right);
        
        while ((*successor)->left != nullptr){
            path.push_back(successor);
            successor = &((*successor)->left);
        }
        
        if (*successor == (*indirect)->right){
            (*successor)->left = (*indirect)->left;
            
            AvlNode<T> *toRemove = *indirect;
            *indirect = *successor;
            delete toRemove;
        }
        
        else{
            AvlNode<T> *tmp = *path.back(), *suc = *successor;
            
            tmp->left = (*successor)->right;
            suc->left = (*indirect)->left;
            suc->right = (*indirect)->right;
            
            delete *indirect;
            *indirect = suc;
            path[index] = &(suc->right);
        }
    }
    
    balance(path);
    _size--;
}

template <class T>
void AvlTree<T>::balance(std::vector<AvlNode<T> **> path){  // starting from root
    std::reverse(path.begin(), path.end());
    
    for (auto indirect: path){
        (*indirect)->updateValues();
        
        if ((*indirect)->balanceFactor() >= 2 and (*indirect)->left->balanceFactor() >= 0)   // left - left
            *indirect = (*indirect)->right_rotate();
        
        else if ((*indirect)->balanceFactor() >= 2){  // left - right
            (*indirect)->left = (*indirect)->left->left_rotate();
            *indirect = (*indirect)->right_rotate();
        }
        
        else if ((*indirect)->balanceFactor() <= -2 and (*indirect)->right->balanceFactor() <= 0)  // right - right
            *indirect = (*indirect)->left_rotate();
        
        else if ((*indirect)->balanceFactor() <= -2){  // right - left
            (*indirect)->right = ((*indirect)->right)->right_rotate();
            *indirect = (*indirect)->left_rotate();
        }
    }
}

template <class T>
bool AvlTree<T>::empty() const{
    return _size == 0;
}

template <class T>
int AvlTree<T>::size() const{
    return _size;
}

template <class T>
int AvlTree<T>::find(T value) const{
    AvlNode<T> *direct = root;
    int idx = 0;
    
    while (direct != nullptr and direct->value != value){
        if (direct->value > value)
            direct = direct->left;
        else{
            idx += (direct->left ? direct->left->count : 0) + 1;
            direct = direct->right;
        }
    }
    
    if (direct == nullptr)
        return -1;
    
    else
        return idx + (direct->left ? direct->left->count : 0);
}

template <class T>
int AvlTree<T>::upper_bound(T value) const{
    AvlNode<T> *direct = root;
    int idx = 0;
    
    while (direct != nullptr){
        if (direct->value > value)
            direct = direct->left;
        else{
            idx += (direct->left ? direct->left->count : 0) + 1;
            direct = direct->right;
        }
    }
    
    return idx;
}

template <class T>
int AvlTree<T>::lower_bound(T value) const{
    AvlNode<T> *direct = root;
    int idx = 0;
    
    while (direct != nullptr){
        if (direct->value >= value)
            direct = direct->left;
        else{
            idx += (direct->left ? direct->left->count : 0) + 1;
            direct = direct->right;
        }
    }
    
    return idx;
}

template <class T>
const T& AvlTree<T>::find_min() const{
    AvlNode<T> *cur = root;
    
    while (cur->left != nullptr)
        cur = cur->left;
    
    return cur->value;
}

template <class T>
const T& AvlTree<T>::find_max() const{
    AvlNode<T> *cur = root;
    
    while (cur->right != nullptr)
        cur = cur->right;
    
    return cur->value;
}

template <class T>
const T& AvlTree<T>::operator[](int idx) const{
    AvlNode<T> *cur = root;
    int left = cur->left != nullptr ? cur->left->count : 0;
    
    while (left != idx){
        if (left < idx){
            idx -= left + 1;
            
            cur = cur->right;
            left = cur->left != nullptr ? cur->left->count : 0;
        }
        
        else{
            cur = cur->left;
            left = cur->left != nullptr ? cur->left->count : 0;
        }
    }
    
    return cur->value;
}

template <class T>
void AvlTree<T>::display(){
    printf("\n");
    if (root != nullptr)
        display(root);
    else
        printf("Empty");
    printf("\n");
}

template <class T>
void AvlTree<T>::display(AvlNode<T> *cur, int depth, int state){  // state: 1 -> left, 2 -> right , 0 -> root
    if (cur->left)
        display(cur->left, depth + 1, 1);
    
    for (int i=0; i < depth; i++)
        printf("     ");
    
    if (state == 1) // left
        printf("┌───");
    else if (state == 2)  // right
        printf("└───");
    
    std::cout << "[" << cur->value << "] - (" << cur->count << ", " << cur->height << ")" << std::endl;
    
    if (cur->right)
        display(cur->right, depth + 1, 2);
}

template class AvlTree<int>;
template class AvlTree<short>;
template class AvlTree<long>;
template class AvlTree<long long>;
template class AvlTree<std::string>;
template class AvlTree<Airport>;
