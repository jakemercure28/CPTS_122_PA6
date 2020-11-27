#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

class BinaryTree
{
private:
    struct BSTnode
    {
        char value;   // letter in alphabet
        string morse; // morse code representation

        BSTnode* left;    // Pointer to left child node
        BSTnode* right;   // Pointer to right child node
    };

    BSTnode* root;       // Pointer to the root node
   
    // Private member functions
    void insert(BSTnode*&, BSTnode*&);
    void destroySubTree(BSTnode*);
    void displayInOrder(BSTnode*) const;
    
public:
    
    BinaryTree();  // Constructor

    ~BinaryTree() // Destructor
    {
        destroySubTree(root);
    }

    // Binary tree operations
    void insertNode(char, string);
    string searchNode(char);
    void displayInOrder() const
    {
        displayInOrder(root);
    }
};
