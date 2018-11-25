#include "AvlTree.hpp"

template <class T>
AvlTree<T>::AvlTree(){
    root = nullptr;
    _size = 0;
}

template<class T>
AvlTree<T>::AvlTree(const AvlTree<T>& avlTree) {
	root = avlTree.root;
	_size = avlTree._size;
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
            AvlNode<T> *temporal = *path.back(), *_successor = *successor;
            
            temporal->left = (*successor)->right;
            _successor->left = (*indirect)->left;
            _successor->right = (*indirect)->right;
            
            delete *indirect;
            *indirect = _successor;
            path[index] = &(_successor->right);
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
        
        if ((*indirect)->balanceFactor() >= 2 and (*indirect)->left->balanceFactor() >= 0)
            *indirect = (*indirect)->rightRotate();
        
        else if ((*indirect)->balanceFactor() >= 2){
            *indirect = (*indirect)->rightLeftRotate();
        }
        
        else if ((*indirect)->balanceFactor() <= -2 and (*indirect)->right->balanceFactor() <= 0)
            *indirect = (*indirect)->leftRotate();
        
        else if ((*indirect)->balanceFactor() <= -2){
            *indirect = (*indirect)->leftRightRotate();
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
    int position = 0;
    
    while (direct != nullptr and direct->value != value){
        if (direct->value > value)
            direct = direct->left;
        else{
            position += (direct->left ? direct->left->count : 0) + 1;
            direct = direct->right;
        }
    }
    return (direct == nullptr) ? -1 : position + (direct->left ? direct->left->count : 0);
}

template <class T>
int AvlTree<T>::upperBound(T value) const{
    AvlNode<T> *direct = root;
    int position = 0;
    
    while (direct != nullptr){
        if (direct->value > value)
            direct = direct->left;
        else{
            position += (direct->left ? direct->left->count : 0) + 1;
            direct = direct->right;
        }
    }
    return position;
}

template <class T>
int AvlTree<T>::lowerBound(T value) const{
    AvlNode<T> *direct = root;
    int position = 0;
    
    while (direct != nullptr){
        if (direct->value >= value)
            direct = direct->left;
        else{
            position += (direct->left ? direct->left->count : 0) + 1;
            direct = direct->right;
        }
    }
    return position;
}

template <class T>
const T& AvlTree<T>::findMin() const{
    AvlNode<T> *iterator = root;
    
    while (iterator->left != nullptr)
        iterator = iterator->left;
    
    return iterator->value;
}

template <class T>
const T& AvlTree<T>::findMax() const{
    AvlNode<T> *iterator = root;
    
    while (iterator->right != nullptr)
        iterator = iterator->right;
    
    return iterator->value;
}

template <class T>
const T& AvlTree<T>::operator[](int position) const{
    AvlNode<T> *iterator = root;
    int left = iterator->left != nullptr ? iterator->left->count : 0;
    
    while (left != position) {
		if (left < position) {
			position -= left + 1;
			iterator = iterator->right;
			left = iterator->left != nullptr ? iterator->left->count : 0;
		} else {
			iterator = iterator->left;
			left = iterator->left != nullptr ? iterator->left->count : 0;
		}
    }
    
    return iterator->value;
}

template <class T>
void AvlTree<T>::display(){
    Console::instance().writeln();
    if (root != nullptr)
        display(root);
    else
    	Console::instance().writeln("Empty");
    Console::instance().writeln();
}

template <class T>
void AvlTree<T>::display(AvlNode<T> *iterator, int depth, int state){
    if (iterator->left)
        display(iterator->left, depth + 1, 1);
    
    for (int i=0; i < depth; i++)
    	Console::instance().write("     ");

    if (state == 1)
    	Console::instance().writeRightBranch();
    else if (state == 2)
        Console::instance().writeLeftBranch();
    
    std::cout << "{" << iterator->value << "} " << std::endl;
    //optional - (" << iterator->count << ", " << iterator->height << ")"

    if (iterator->right)
        display(iterator->right, depth + 1, 2);
}

template class AvlTree<int>;
template class AvlTree<short>;
template class AvlTree<long>;
template class AvlTree<long long>;
template class AvlTree<std::string>;
template class AvlTree<Airport>;
template class AvlTree<Airport*>;
