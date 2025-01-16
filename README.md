# Translator Project

## Overview

The Translator Project is a text-based dictionary application implemented using a Binary Search Tree (BST). It translates English words into their corresponding translations (e.g., Spanish or another language). This project demonstrates how to use BSTs for efficient storage and retrieval of key-value pairs (English words and their translations) and showcases exception handling and modular design.

---

## Features

1. **Dictionary Implementation**:
   - Words and their translations are stored as key-value pairs in a BST.
   - Efficient insertion, retrieval, and traversal of dictionary entries.

2. **Translation**:
   - Allows users to input English words and retrieves the corresponding translation.

3. **File Input**:
   - Loads dictionary data from a file where each line contains an English word and its translation in the format `key:value`.

4. **In-Order Traversal**:
   - Provides an option to display all dictionary entries in sorted order by English words.

5. **Error Handling**:
   - Handles various exceptions, such as duplicate entries, missing elements, or an empty dictionary.

---

## Components

### 1. `BST.h` and `BST.cpp`
- Implements a Binary Search Tree (BST) to store and manage the dictionary entries.
- **Key Methods**:
  - `insert`: Adds a new word-translation pair to the BST.
  - `retrieve`: Retrieves the translation of a given word.
  - `traverseInOrder`: Performs an in-order traversal of the BST to display entries.
  - Handles exceptions like `ElementAlreadyExistsException`, `ElementDoesNotExistException`, and `EmptyDataCollectionException`.

### 2. `Dictionary.h` and `Dictionary.cpp`
- Acts as a wrapper for the BST to provide higher-level dictionary operations.
- **Key Methods**:
  - `put`: Adds a word-translation pair to the dictionary.
  - `get`: Retrieves the translation of a word from the dictionary.
  - `displayContent`: Displays all entries in the dictionary in sorted order.

### 3. `Translator.cpp`
- The main program that interacts with the user and manages the dictionary.
- **Key Features**:
  - Reads data from a file (`myDataFile.txt`) to populate the dictionary.
  - Allows users to input English words to get their translations.
  - Supports a `display` mode to list all dictionary entries in sorted order.

### 4. `myDataFile.txt`
- Contains the word-translation pairs in the format `key:value` (e.g., `cat:gato`).

---

## File Structure

```
TranslatorProject/
|
|-- BST.h                # Header file for Binary Search Tree
|-- BST.cpp              # Implementation of Binary Search Tree
|-- Dictionary.h         # Header file for Dictionary
|-- Dictionary.cpp       # Implementation of Dictionary
|-- Translator.cpp       # Main program
|-- myDataFile.txt       # Input file with word-translation pairs
```

---

## How to Run the Project

1. **Compile the Program**:
   Use a C++ compiler (e.g., g++) to compile the source files:
   ```bash
   g++ Translator.cpp BST.cpp Dictionary.cpp -o Translator
   ```

2. **Run the Program**:
   Provide the dictionary file (`myDataFile.txt`) as an argument:
   ```bash
   ./Translator myDataFile.txt
   ```

   Optionally, add the `display` argument to print all entries:
   ```bash
   ./Translator myDataFile.txt display
   ```

3. **Interactive Mode**:
   If no `display` argument is provided, the program allows interactive translation:
   - Input an English word to get its translation.
   - If the word is not found, the program will print `***Not Found!***`.

---

## Example Input and Output

### Example Input File (`myDataFile.txt`):
```
cat:gato
dog:perro
house:casa
tree:árbol
water:agua
```

### Command:
```bash
./Translator myDataFile.txt
```

### Output:
```
Enter a word: cat
cat:gato
Enter a word: dog
dog:perro
Enter a word: flower
***Not Found!***
```

---

## Exception Handling

1. **ElementAlreadyExistsException**:
   - Thrown when attempting to add a duplicate word to the dictionary.
2. **ElementDoesNotExistException**:
   - Thrown when trying to retrieve a word that is not in the dictionary.
3. **EmptyDataCollectionException**:
   - Thrown when attempting operations on an empty dictionary.

---


## Author

Chowdhury Yasir.

