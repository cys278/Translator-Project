/*
 * Translator.cpp
 *
 * Description: Link-based implementation.
 *
 * Class invariant: It is always a BST.
 *
 * Author: Chowdhury Yasir
 * Date of last modification: March. 15 2024
 */
#include "Dictionary.h"
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int abruptProgramTerminate(Dictionary *&ptr)
{
    delete ptr;
    return 1;
}

void display(WordPair &anElement)
{
    cout << anElement;
}

int main(int argc, char *argv[])
{
    // cout << argc << endl;
    string filename = argv[1];

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Unable to open file: " << filename << endl;
        return 1;
    }

    Dictionary *testing = new Dictionary();
    if (!testing)
    {
        cerr << "Memory allocation failed!" << endl;
        return 1;
    }

    string line;
    if (file.is_open())
    {
        cout << "Reading from a file: " << filename << endl;

        while (getline(file, line))
        {
            size_t pos = line.find(":");
            if (pos == string::npos)
            {
                cerr << "Invalid data format in file." << endl;
                delete testing;
                return 1;
            }

            string englishWord = line.substr(0, pos);
            string translationWord = line.substr(pos + 1);

            WordPair wordPair(englishWord, translationWord);
            try
            {
                testing->get(wordPair);
            }

            catch (...)
            {
                try
                {
                    testing->put(wordPair);
                }

                catch (const UnableToInsertException &e)
                {
                    cerr << "Unable to insert WordPair: " << wordPair << endl;
                    return abruptProgramTerminate(testing);
                }
            }
        }
    }

    file.close();
    if (argc == 3)
    {
        string action = argv[2];
        if (action == "display")
        {
            testing->displayContent(display);
        }
    }
    else
    {
        string input;
        while (cin >> input)
        {
            WordPair txt(input);
            try
            {
                WordPair result = testing->get(txt);
                cout << input << ":" << result.getTranslation() << endl;
            }
            catch (const ElementDoesNotExistException &e)
            {
                cout << "***Not Found!***" << endl;
            }
            catch (const EmptyDataCollectionException &e)
            {
                cout << "Dictionary is empty." << endl;

                return abruptProgramTerminate(testing);
            }
        }
    }

    delete testing;
    return 0;
}
