#include <iostream>
#include "binarytree.h"

BinaryTree::BinaryTree() // constructor member function
{
    root = nullptr; // set root node to null

    char letter; // used to store letter temp data
    string line; // used to store morse code temp data
    
    ifstream input; // MorseTable input file stream

    input.open("MorseTable.txt", ios::in); //open input file stream

    while (input)
    {
        getline(input, line, '\n'); // get first line
        letter = line[0];           // convert to char

        getline(input, line, '\n'); // get second line

        insertNode(letter, line);   //insert the data into a BST node
    }
    input.close(); // close MorseTable.txt input file stream
}

void BinaryTree::insert(BSTnode*& nodePtr, BSTnode*& newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;                  // insert the node
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);     // search the left branch
    else
        insert(nodePtr->right, newNode);    // search the right branch
}


void BinaryTree::insertNode(char letter, string morseCode)
{
    BSTnode* newNode = nullptr;	// pointer to a new node

    // create a new node and store letter in it
    newNode = new BSTnode;
    newNode->value = letter;
    newNode->morse = morseCode;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode); // insert the node into the BST
}

void BinaryTree::destroySubTree(BSTnode* nodePtr)
{
    if (nodePtr)
    {   // delete each node of the tree
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

void BinaryTree::displayInOrder(BSTnode* nodePtr) const
{
    if (nodePtr)
    {   // recursive call for each branch of tree
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        cout << nodePtr->morse << endl;
        displayInOrder(nodePtr->right);
    }
}

string BinaryTree::searchNode(char letter)
{
    BSTnode* nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == letter) // search finds letter in tree
            return nodePtr->morse;
        else if (letter < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return "ERROR!"; // search cant find letter in tree
}