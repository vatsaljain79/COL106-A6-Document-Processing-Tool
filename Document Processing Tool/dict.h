// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class SymNode {
public:
    string key;
    int height;
    int count=0;
    
    SymNode* par;
    SymNode* left;
    SymNode* right;

    SymNode();
    SymNode(string k);

    SymNode* LeftLeftRotation(); // case 1
    SymNode* RightRightRotation(); // case 2
    SymNode* LeftRightRotation(); // case 3
    SymNode* RightLeftRotation(); // case 4

    ~SymNode();
    
};

class SymbolTable {
private:
    int size;
    SymNode* root;

public: 

    SymbolTable();
    ~SymbolTable();

    // Insert a key in the symbol table, there is no value now
    void insert(string k);

    // Remove a key (and it's memory address) in the symbol table
    void remove(string k);
 
    // Find the memory address corresponding to the variable in the symbol table
    SymNode* search(string k);

    // Assigns a memory address to the key in the symbol table
    void assign_address(string k,int idx);

    // Get size
    int get_size();

    // Get root 
    SymNode* get_root();
};

class Dict {
private:
    //SymbolTable* p;
    vector<SymbolTable*> dict_vector;
    // You can add attributes/helper functions here

public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};