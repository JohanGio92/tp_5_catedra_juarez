#ifndef AVLTreeNode_hpp
#define AVLTreeNode_hpp

template <class T>
struct AvlNode {
    AvlNode *left;
    AvlNode *right;
    
    T value;
    int count;
    int height;
    
    AvlNode(T value);
    void updateValues();
    int balanceFactor();

	//pre: violation for right - right
	//post: rotation left
    AvlNode* leftRotate();

    //pre: violation for left - left
    //post: rotation right
    AvlNode* rightRotate();

    //pre: violation for right - left
	//post: rotation left - right
    AvlNode* leftRightRotate();

    //pre: violation for right - left
	//post: rotation right - left
    AvlNode* rightLeftRotate();

};

#endif
