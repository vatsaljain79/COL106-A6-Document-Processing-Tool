// Do NOT add any other includes
#include <string>
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class Linkedlist
{

public:
    Node *head;
    Node *tail;
    Linkedlist()
    {
        head = NULL;
        tail = NULL;
    }
    void insertNode(Node *);
};

class Star {
public: 

    int book_code;
    int page;
    int paragraph;
    int sentence_no;
    // int offset;
    string key;

    Star();
    Star(int b_code, int pg, int para, int s_no, string ke);
    ~Star();
};

class SearchEngine
{
private:
    vector<Star* > store;
    Linkedlist *List;
    // You can add attributes/helper functions here

public:
    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node *search(string pattern, int &n_matches);

    /* -----------------------------------------*/
};