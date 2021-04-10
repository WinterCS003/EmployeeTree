#ifndef BinaryTree_H
#define BinaryTree_H

#include <iostream>
#include <iomanip>

template <class T>
struct TreeNode
{
    T value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T val): value(val), left(nullptr), right(nullptr){};
};

template <class T>
class BinaryTree{
    private:
        TreeNode<T>* root;

        /*********************
         ** MUTATOR HELPERS **
         *********************/
        bool insert(TreeNode<T> *&, // IN - reference to the pointer of a
                                    //      node to insert
                    TreeNode<T> *&); // IN - reference to the pointer of a
                                     //      node to insert
        void destroySubTree(TreeNode<T> *); // IN - pointer to node to
                                            //      destroy
        bool deleteNode(T, TreeNode<T> *&); // IN - reference to the
                                            //      pointer of a node to
                                            //      destroy
        bool makeDeletion(TreeNode<T> *&); // IN - reference to the pointer
                                           //      of a node to destroy
        void assign(TreeNode<T> *);

        /**********************
         ** ACCESSOR HELPERS **
         **********************/
        void displayInOrder(TreeNode<T> *) const; // IN - pointer to node to print
        void displayPreOrder(TreeNode<T> *) const; // IN - pointer to node to print
        void displayPostOrder(TreeNode<T> *) const; // IN - pointer to node to print
        int size(TreeNode<T>*) const; // IN - pointer to node to count
        int leaf_count(TreeNode<T>*) const; // IN - pointer to node to count
    public:
        /********************************
         ** CONSTRUCTORS & DESTRUCTORS **
         ********************************/
        BinaryTree(){ root = nullptr;}
        BinaryTree(const BinaryTree&);
        ~BinaryTree(){destroySubTree(root);}
        
        /**************
         ** MUTATORS **
         ***************/
        bool insertNode(T);
        bool searchNode(T);
        bool remove(T);
        BinaryTree& operator=(const BinaryTree&);
        
        /***************
         ** ACCESSORS **
         ***************/
        T& frontNode() const{ return root->value; };
        void displayInOrder() const{ displayInOrder(root);}
        void displayPreOrder() const{ displayPreOrder(root);}
        void displayPostOrder() const{ displayPostOrder(root);}
        int size() const { return size(root); };
        int leaf_count() const { return leaf_count(root); };
        int non_leaf_count() const;
};

/****************************************************************
 * BinaryTree Class
 *   This class represents a templated Binary Search Tree.
 *   It is implemented using pointers and manages a root
 *   which is a pointer to the root node.
 ***************************************************************/

/**********************************************************
 *
 * CONSTRUCTOR BinaryTree
 *_________________________________________________________
 * This is a copy constructor that creates a new Binarytree
 * that is identical to the passed tree.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      tree: (const BinaryTree&) // IN - tree to copy from
 *
 * POST-CONDITIONS
 *   This Constructor creates a new BinaryTree
 ***********************************************************/
template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree& tree) // IN - tree to copy
{
    root = nullptr;
    assign(tree.root);
}

/**************
 ** MUTATORS **
 **************/

/**********************************************************
 *
 * FUNCTION insertNode
 *_________________________________________________________
 * This function receives a value to insert and it is
 * added to the tree unless the value already exists.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     val (T) // IN - value to insert
 *
 * POST-CONDITIONS
 *   This function returns true if the value is inserted
 *   false otherwise.
 ***********************************************************/
template <class T>
bool BinaryTree<T>::insertNode(T val) // IN - value to insert
{
    TreeNode<T> *newNode = new TreeNode<T>(val);
    
    //Insert the Node
    return insert(root, newNode);
}

/**********************************************************
 *
 * FUNCTION searchNode
 *_________________________________________________________
 * This function receives a value to search for and
 * traverses the tree to find the value.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     val(T) // IN - value to search for
 *
 * POST-CONDITIONS
 *   This function returns true if the node is found, false
 *   otherwise. The node is printed to the terminal if found
 *   and a warning is printed to the terminal otherwise.
 ***********************************************************/
template <class T>
bool BinaryTree<T>::searchNode(T val) // IN - value to search for
{
    TreeNode<T>* nodePtr = root;

    while(nodePtr){
        if (nodePtr->value == val){
            std::cout << nodePtr->value << std::endl;
            return true;
        }
        else if (val < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }

    std::cout << "Input Not found" << std::endl;
    return false;
}

/**********************************************************
 *
 * FUNCTION remove
 *_________________________________________________________
 * This function receives a value to remove and delete
 * the value if found.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     val(T) // IN - value to remove
 *
 * POST-CONDITIONS
 *   This function returns true and prints the value to the
 *   terminal if the node is found, false is returned and a
 *   warning message printed otherwise.
 ***********************************************************/
template <class T>
bool BinaryTree<T>::remove(T val) // IN - value to remove
{
    return deleteNode(val, root);
}

/**********************************************************
 *
 * FUNCTION operator=
 *_________________________________________________________
 * This function receives a binary tree and deletes the
 * calling function's binary tree and makes it identical
 * to the passed binary tree.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      tree: (const BinaryTree&) // IN - tree to copy from
 *
 * POST-CONDITIONS
 *   This function returns a reference to the updated tree
 ***********************************************************/
template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& tree) // IN - tree to copy
{
    destroySubTree(this->root);
    assign(tree.root);
}


/***************
 ** ACCESSORS **
 ***************/

/**********************************************************
 *
 * FUNCTION non_leaf_count
 *_________________________________________________________
 * This function receives nothing and returns the number
 * of non leaf nodes in the tree.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function returns the number of non leaf nodes in
 *   the tree.
 ***********************************************************/
template <class T>
int BinaryTree<T>::non_leaf_count() const{
    return size(root) - leaf_count(root);
}

/*********************
 ** MUTATOR HELPERS **
 *********************/

/**********************************************************
 *
 * FUNCTION insert
 *_________________________________________________________
 * This function receives a node to insert and the node
 * to begin insertion from. This is a helper function
 * for the insert function.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     nodePtr(TreeNode<T>*&) // IN - node to begin from
 *     newNode(TreeNode<T>*&) // IN - node to insert
 *
 * POST-CONDITIONS
 *   This function returns true if the value is inserted
 *   false otherwise.
 ***********************************************************/
template <class T>
bool BinaryTree<T>::insert(TreeNode<T>*&nodePtr, // IN - node to begin from
                           TreeNode<T> *&newNode) // IN - node to insert
{
    if (nodePtr == nullptr){
        std::cout << "Node inserted" << std::endl;
        nodePtr = newNode;
    }
    else if (newNode->value == nodePtr->value){
        std::cout << "Already exists" << std::endl;
        return false;
    }
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else 
        insert(nodePtr->right, newNode);

    return true;
}

/**********************************************************
 *
 * FUNCTION destroySubTree
 *_________________________________________________________
 * This is a helper function to delete all nodes in a tree.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     nodePtr(TreeNode<T>*&) // IN - node to begin delete
 *                            //      from
 *
 * POST-CONDITIONS
 *   This function deletes all nodes in the tree.
 ***********************************************************/
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode<T> *nodePtr) // IN - node to begin delete
                                                         //      from
{
    std::cout << "Node Destroyed\n";
    if(nodePtr == nullptr)
    {
        return;
    }
    if(nodePtr->left == nullptr && nodePtr->right == nullptr)
    {
        delete nodePtr;
        return;
    }
    if(nodePtr->left != nullptr){
        destroySubTree(nodePtr->left);
    }
    if(nodePtr->right != nullptr){
        destroySubTree(nodePtr->right);
    }
    delete nodePtr;
}

/**********************************************************
 *
 * FUNCTION deleteNode
 *_________________________________________________________
 * This is a helper function that receives a value to remove
 * and the node to begin searching from.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     val(T) // IN - value to remove
 *     nodePtr (TreeNode<T>*&) // IN - reference to a
 *                             //      pointer to begin
 *                             //      deleting from
 *
 * POST-CONDITIONS
 *   This function returns true and prints the value to the
 *   terminal if the node is found, false is returned and a
 *   warning message printed otherwise.
 ***********************************************************/
template <class T>
bool BinaryTree<T>::deleteNode(T val, // IN - value to remove
                               TreeNode<T> *&nodePtr) // IN - reference to a
                                                      //      pointer to begin
                                                      //      deleting from
{
    if (val < nodePtr->value)
        deleteNode(val, nodePtr->left);
    else if (val > nodePtr->value)
        deleteNode(val, nodePtr->right);
    else if(val == nodePtr->value){
        std::cout << nodePtr->value << std::endl;
        return makeDeletion(nodePtr);
    } else{
        std::cout << "Node not found" << std::endl;
        return false;
    }
}

/**********************************************************
 *
 * FUNCTION makeDeletion
 *_________________________________________________________
 * This is a helper function that receives a node to
 * delete and deletes. The branch is properly updated.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     nodePtr (TreeNode<T>*&) // IN - reference to a
 *                             //      pointer to begin
 *                             //      deleting from
 *
 * POST-CONDITIONS
 *   This function returns true and prints the value to the
 *   terminal if the node is found, false is returned and a
 *   warning message printed otherwise.
 ***********************************************************/
template <class T>
bool BinaryTree<T>::makeDeletion(TreeNode<T> *&nodePtr) // IN - reference to a
                                                        //      pointer to begin
                                                        //      deleting from
{
    TreeNode<T> *tempNodePtr;
    
    if (nodePtr == nullptr){
        std::cout << "Cannot delete empty node\n";
        return false;
    }
    else if(nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if(nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    //If the node has two Children
    else
    {
        //Move one node to the right
        tempNodePtr = nodePtr->right;
        //Go to the end left node
        while(tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        //Reattach the left subtree
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        //Reattach the right subtree
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    return true;
}

/**********************************************************
 *
 * FUNCTION assign
 *_________________________________________________________
 * This function receives a node to a tree and inserts all
 * values of the tree to the calling tree.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      node: (TreeNode<T>*&) // IN - node to begin copy from
 *
 * POST-CONDITIONS
 *   This function returns nothing.
 ***********************************************************/
template <class T>
void BinaryTree<T>::assign(TreeNode<T>* node) // IN - node to begin copy from
{
    if(node == nullptr){
        return;
    }
    this->insertNode(node->value);
    assign(node->left);
    assign(node->right);
}


/**********************
 ** ACCESSOR HELPERS **
 **********************/

/**********************************************************
 *
 * FUNCTION displayInOrder
 *_________________________________________________________
 * This function receives a node to start printing from and
 * displays all nodes in  InOrder sequence. This is a
 * helper function
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     nodePtr(TreeNode<T>*&) // IN - node to begin printing
 *                            //      from
 *
 * POST-CONDITIONS
 *   This function prints the nodes in inOrder sequence.
 ***********************************************************/
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode<T> *nodePtr) const // IN - node to begin printing
                                                               //      from
{
    if(nodePtr){
        displayInOrder(nodePtr->left);
        std::cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

/**********************************************************
 *
 * FUNCTION displayInOrder
 *_________________________________________________________
 * This function receives a node to start printing from and
 * displays all nodes in  preOrder sequence. This is a
 * helper function
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     nodePtr(TreeNode<T>*&) // IN - node to begin printing
 *                            //      from
 *
 * POST-CONDITIONS
 *   This function prints the nodes in preOrder sequence.
 ***********************************************************/
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode<T> *nodePtr) const // IN - node to begin printing
                                                                //      from
{
    if(nodePtr){
        std::cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

/**********************************************************
 *
 * FUNCTION displayInOrder
 *_________________________________________________________
 * This function receives a node to start printing from and
 * displays all nodes in postOrder sequence. This is a
 * helper function
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     nodePtr(TreeNode<T>*&) // IN - node to begin printing
 *                            //      from
 *
 * POST-CONDITIONS
 *   This function prints the nodes in postOrder sequence.
 ***********************************************************/
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode<T> *nodePtr) const // IN - node to begin printing
                                                                 //      from
{
    if(nodePtr){
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        std::cout << nodePtr->value << " ";
    }
}
/**********************************************************
 *
 * FUNCTION size
 *_________________________________________________________
 * This is a helper function that receives a node to begin
 * counting from
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     node (TreeNode<T>*) // IN - node to begin count from
 *
 * POST-CONDITIONS
 *   This function returns the number of nodes in the tree.
 ***********************************************************/
template <class T>
int BinaryTree<T>::size(TreeNode<T>* node) const // IN - node to begin count from
{
   if(node == nullptr)
        return 0;
   if(node->left == nullptr && node->right == nullptr)
        return 1;
   return 1 + size(node->left) + size(node->right);
}

/**********************************************************
 *
 * FUNCTION leaf_count
 *_________________________________________________________
 * This is a helper function that receives a node to begin
 * counting from.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     node (TreeNode<T>*) // IN - node to begin count from
 *
 * POST-CONDITIONS
 *   This function returns the number of leaf nodes in the
 *   tree.
 ***********************************************************/
template <class T>
int BinaryTree<T>::leaf_count(TreeNode<T>* node) const // IN - node to begin count from
{
    if(node == nullptr)
        return 0;
    if(node->left == nullptr && node->right == nullptr)
        return 1;
    return leaf_count(node->left) + leaf_count(node->right);
}

#endif
