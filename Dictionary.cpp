/*
 * Dictionary.cpp
 *
 * Description: Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 *
 * Author: Chowdhury Yasir 
 * Date of last modification: March. 15 2024
 */


#include "Dictionary.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::nothrow;

using std::cout;
using std::endl;
using std::nothrow;

// Constructor and destructor:

Dictionary::Dictionary()
{
    keyValuePairs = new (nothrow) BST();
}

Dictionary::~Dictionary()
{
    delete keyValuePairs;
    keyValuePairs = nullptr;
}


// Dictionary operations

unsigned int Dictionary::getElementCount() const
{
    return keyValuePairs->getElementCount();
}

void Dictionary::put(WordPair &newElement)
{
    // cout << "Nothing" << endl;

    keyValuePairs->insert(newElement);
}

WordPair &Dictionary::get(WordPair &targetElement) const
{
    return keyValuePairs->retrieve(targetElement);
}

void Dictionary::displayContent(void visit(WordPair &)) const
{
    keyValuePairs->traverseInOrder(visit);
}