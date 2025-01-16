/*
 * BST.cpp
 *
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 *
 * Author: Chowdhury Yasir (cya127)
 * Date of last modification: March. 15 2024
 */

#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include <iostream>
#include <stdexcept> // For standard exceptions

using std::cout;
using std::endl;
using std::nothrow;

// You cannot change the prototype of the public methods of this class.
// Remember, if you add public methods to this class, our test driver
// - the one with which we will mark this assignment -
// will not know about them since, in order to create it, we will have
// used only the public method prototypes below.

/* Constructors and destructor */

// Default constructor
BST::BST() {}

// Copy constructor
BST::BST(const BST &aBST)
{

    // to do
    // Implementing a deep copy of the binary search tree
    root = nullptr;                   // Ensure the new tree is initially empty
    elementCount = aBST.elementCount; // Copy the element count

    // Recursively copy the nodes from the other tree
    if (aBST.root != nullptr)
    {
        root = new BSTNode(*(aBST.root)); // Call the copy constructor of BSTNode
    }
}

// Destructor
BST::~BST()
{

    // to do

    // Call a private recursive function to deallocate memory
    // This function will traverse the tree and delete each node
    // starting from the root
    if (root != nullptr)
    {
        deleteTR(root);
        root = nullptr;
        elementCount = 0;
    }
}

//Deleting the binary tree recursively
void BST::deleteTR(BSTNode *node)
{
    if (node != nullptr)
    {
        deleteTR(node->left);
        deleteTR(node->right);
        delete node;
    }
}

/* Getters and setters */

// Description: Returns the number of elements currently stored in the binary search tree.
// Postcondition: This method does not change the binary search tree.
// Time efficiency: O(1)
unsigned int BST::getElementCount() const
{

    return this->elementCount;
}

/* BST Operations */

// Description: Inserts an element into the binary search tree.
//              This is a wrapper method which calls the recursive insertR( ).
// Precondition: "newElement" does not already exist in the binary search tree.
// Exception: Throws the exception "UnableToInsertException" when newElement
//            cannot be inserted because the "new" operator failed.
// Exception: Throws the exception "ElementAlreadyExistsException"
//            if "newElement" already exists in the binary search tree.
// Time efficiency: O(log2 n)
void BST::insert(WordPair &newElement)
{

    // to do
    BSTNode *newNode = new BSTNode(newElement);
    if (newNode == nullptr)
    {
        throw UnableToInsertException(); // Failed to allocate memory
    }
    if (root == nullptr)
    {
        root = newNode;
        elementCount++;
        return;
    }
    else
    {
        if (!insertR(newNode, root))
        {
            delete newNode;
            // cout << "Trying to add an element that already exists! NOT ALLOWED" << endl;
            throw ElementAlreadyExistsException(); // Element already exists in the tree
        }
    }
    elementCount++;
}

// Description: Recursive insertion into a binary search tree.
//              Returns true when "anElement" has been successfully inserted into the
//              binary search tree. Otherwise, returns false.
bool BST::insertR(BSTNode *newBSTNode, BSTNode *current)
{

    // to do
    if (newBSTNode->element == current->element)
    {
        return false;
    }
    else if (newBSTNode->element < current->element)
    {
        if (current->hasLeft())
        {
            return insertR(newBSTNode, current->left);
        }
        else
        {
            current->left = newBSTNode;
            return true;
        }
    }
    else
    {
        if (current->hasRight())
        {
            return insertR(newBSTNode, current->right);
        }
        else
        {
            current->right = newBSTNode;
            return true;
        }
    }
}

// Description: Retrieves "targetElement" from the binary search tree.
//              This is a wrapper method which calls the recursive retrieveR( ).
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException"
//            if the binary search tree is empty.
// Exception: Propagates the exception "ElementDoesNotExistException"
//            thrown from the retrieveR(...)
//            if "targetElement" is not found in the binary search tree.
// Postcondition: This method does not change the binary search tree.
// Time efficiency: O(log2 n)
WordPair &BST::retrieve(WordPair &targetElement) const
{

    if (elementCount == 0)
        throw EmptyDataCollectionException("Binary search tree is empty.");

    WordPair &translated = retrieveR(targetElement, root);

    return translated;
}

// Description: Recursive retrieval from a binary search tree.
// Exception: Throws the exception "ElementDoesNotExistException"
//            if "targetElement" is not found in the binary search tree.
// Postcondition: This method does not change the binary search tree.
WordPair &BST::retrieveR(WordPair &targetElement, BSTNode *current) const
{

    // to do
    if (current == nullptr)
    {
        throw ElementDoesNotExistException(); // Element not found in the tree
    }
    else if (targetElement == current->element)
    {
        return current->element;
    }
    else if (targetElement < current->element)
    {
        return retrieveR(targetElement, current->left);
    }
    else
    {
        return retrieveR(targetElement, current->right);
    }
}

// Description: Traverses the binary search tree in order.
//              This is a wrapper method which calls the recursive traverseInOrderR( ).
//              The action to be done on each element during the traverse is the function "visit".
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException"
//            if the binary search tree is empty.
// Postcondition: This method does not change the binary search tree.
// Time efficiency: O(n)
void BST::traverseInOrder(void visit(WordPair &)) const
{

    if (elementCount == 0)
        throw EmptyDataCollectionException("Binary search tree is empty.");

    traverseInOrderR(visit, root);

    return;
}

// Description: Recursive in order traversal of a binary search tree.
// Postcondition: This method does not change the binary search tree.
void BST::traverseInOrderR(void visit(WordPair &), BSTNode *current) const
{

    // to do
    if (current != nullptr)
    {
        traverseInOrderR(visit, current->left);
        visit(current->element);
        traverseInOrderR(visit, current->right);
    }
}