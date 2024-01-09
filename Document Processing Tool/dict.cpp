// Do NOT add any other includes
#include "dict.h"
// # include <iostream>
// using namespace std;

int hashi(string s){
    int len=1001;
    int ans=0;
    for (char j:s){
        ans= (ans*37) + int(j)*53;
        ans=ans%len;
    }
    return ans;
}

SymNode::SymNode()
{
    key = "";
    height = 0;
    left = NULL;
    right = NULL;
    par = NULL;
    count=0;
}

SymNode::~SymNode()
{
    if (left != NULL)
    {
        delete left;
        left = NULL;
    }
    if (right != NULL)
    {
        delete right;
        right = NULL;
    }
}

SymNode::SymNode(string k)
{
    key = k;
    height = 0;
    left = NULL;
    right = NULL;
    par = NULL;
    count=0;
}

SymNode *SymNode::LeftLeftRotation()
{
    SymNode *b = new SymNode(this->key);
    SymNode *a = new SymNode(this->left->key);
    b->count=this->count;
    a->count=this->left->count;
    b->right = this->right;
    b->left = this->left->right;
    b->par = a;
    a->right = b;
    a->left = this->left->left;
    // cout<<"vh";
    if (this->par != NULL)
    {
        if (this->par->left == this)
        {
            par->left = a;
        }
        else
        {
            par->right = a;
        }
    }

    // height balancing
    if (b->left == NULL)
    {
        if (b->right == NULL)
        {
            b->height = 0;
        }
        else
        {
            b->height = b->right->height + 1;
        }
    }
    else
    {
        if (b->right == NULL)
        {
            b->height = b->left->height + 1;
        }
        else
        {
            b->height = max(b->right->height, b->left->height) + 1;
        }
    }
    if (a->left == NULL)
    {
        if (a->right == NULL)
        {
            a->height = 0;
        }
        else
        {
            a->height = a->right->height + 1;
        }
    }
    else
    {
        if (a->right == NULL)
        {
            a->height = a->left->height + 1;
        }
        else
        {
            a->height = max(a->right->height, a->left->height) + 1;
        }
    }

    SymNode *pa = a->par;
    while (pa != NULL)
    {
        if (pa->left == NULL)
        {
            if (pa->right == NULL)
            {
                pa->height = 0;
            }
            else
            {
                pa->height = pa->right->height + 1;
            }
        }
        else
        {
            if (pa->right == NULL)
            {
                pa->height = pa->left->height + 1;
            }
            else
            {
                pa->height = max(pa->right->height, pa->left->height) + 1;
            }
        }
        pa = pa->par;
    }
    return a;
}

SymNode *SymNode::RightRightRotation()
{
    SymNode *b = new SymNode(this->key);
    SymNode *a = new SymNode(this->right->key);
    b->count=this->count;
    a->count=this->right->count;
    b->left = this->left;
    b->right = this->right->left;
    b->par = a;
    a->left = b;
    a->right = this->right->right;
    if (this->par != NULL)
    {
        if (this->par->right == this)
        {
            par->right = a;
        }
        else
        {
            par->left = a;
        }
    }
    // cout<<"till here";
    // height balance
    if (b->left == NULL)
    {
        if (b->right == NULL)
        {
            b->height = 0;
        }
        else
        {
            b->height = b->right->height + 1;
        }
    }
    else
    {
        if (b->right == NULL)
        {
            b->height = b->left->height + 1;
        }
        else
        {
            b->height = max(b->right->height, b->left->height) + 1;
        }
    }
    if (a->left == NULL)
    {
        if (a->right == NULL)
        {
            a->height = 0;
        }
        else
        {
            a->height = a->right->height + 1;
        }
    }
    else
    {
        if (a->right == NULL)
        {
            a->height = a->left->height + 1;
        }
        else
        {
            a->height = max(a->right->height, a->left->height) + 1;
        }
    }

    SymNode *pa = a->par;
    while (pa != NULL)
    {
        if (pa->left == NULL)
        {
            if (pa->right == NULL)
            {
                pa->height = 0;
            }
            else
            {
                pa->height = pa->right->height + 1;
            }
        }
        else
        {
            if (pa->right == NULL)
            {
                pa->height = pa->left->height + 1;
            }
            else
            {
                pa->height = max(pa->right->height, pa->left->height) + 1;
            }
        }
        pa = pa->par;
    }
    return a;
}

SymNode *SymNode::LeftRightRotation()
{
    SymNode *a = this->left;
    SymNode *b = this->left->right;
    a->right = b->left;
    b->left = a;
    this->left = b;
    b->par = this;

    // height balance
    if (a->left == NULL)
    {
        if (a->right == NULL)
        {
            a->height = 0;
        }
        else
        {
            a->height = a->right->height + 1;
        }
    }
    else
    {
        if (a->right == NULL)
        {
            a->height = a->left->height + 1;
        }
        else
        {
            a->height = max(a->right->height, a->left->height) + 1;
        }
    }

    if (b->left == NULL)
    {
        if (b->right == NULL)
        {
            b->height = 0;
        }
        else
        {
            b->height = b->right->height + 1;
        }
    }
    else
    {
        if (b->right == NULL)
        {
            b->height = b->left->height + 1;
        }
        else
        {
            b->height = max(b->right->height, b->left->height) + 1;
        }
    }
    // cout<<"her";
    return this->LeftLeftRotation();
}

SymNode *SymNode::RightLeftRotation()
{
    SymNode *a = this->right;
    SymNode *b = this->right->left;
    a->left = b->right;
    b->right = a;
    this->right = b;
    b->par = this;
    // height balance
    if (a->left == NULL)
    {
        if (a->right == NULL)
        {
            a->height = 0;
        }
        else
        {
            a->height = a->right->height + 1;
        }
    }
    else
    {
        if (a->right == NULL)
        {
            a->height = a->left->height + 1;
        }
        else
        {
            a->height = max(a->right->height, a->left->height) + 1;
        }
    }

    if (b->left == NULL)
    {
        if (b->right == NULL)
        {
            b->height = 0;
        }
        else
        {
            b->height = b->right->height + 1;
        }
    }
    else
    {
        if (b->right == NULL)
        {
            b->height = b->left->height + 1;
        }
        else
        {
            b->height = max(b->right->height, b->left->height) + 1;
        }
    }
    return this->RightRightRotation();
}

SymbolTable::SymbolTable()
{
    size=0;
    root=NULL;
    // cout<<"yeee";
    // if (root==NULL){
    //     cout<<"yeee";
    // }
}

int h(SymNode *node)
{
    if (node == NULL)
    {
        return -1;
    }
    else
    {
        return node->height;
    }
}

int hd(SymNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return h(node->left) - h(node->right);
    }
}

SymNode *helperinsert(string k, SymNode *node, SymNode *root)
{
    
    if (node == NULL)
    {
        // cout<<"ye";
        SymNode *s = new SymNode();
        s->key = k;
        s->count=1;
        node = s;
        return node;
    }
    else
    {
        if (k > node->key)
        {
            node->right = helperinsert(k, node->right, root);
            node->right->par=node;
        }
        else if (k<node->key)
        {
            node->left = helperinsert(k, node->left, root);
            node->left->par=node;
        }
        else{
            node->count+=1;
        }
        node->height = max(h(node->left), h(node->right)) + 1;
        // cout<<node->key<<" "<<node->height<<endl;
        // if (node->key=="as" and node->height==2){
        //     cout<<node->left->key<<endl;
        //     cout<<node->right->key<<endl;
        //     cout<<"enter"<<endl;
        // }
        int diff = hd(node);
        // cout<<diff<<" "<<node->key<<endl;
        
        if (diff > 1 and k < node->left->key)
        {
            // cout<<"case1"<<endl;
            return node->LeftLeftRotation();
        }
        if (diff < -1 and k > node->right->key)
        {
            // cout<<"case2"<<endl;
            // cout<<node->key<<endl;
            // cout<<"hkh"<<node->par->key;
            return node->RightRightRotation();
        }
        if (diff > 1 and k > node->left->key)
        {
            // cout<<"case3"<<endl;
            return node->LeftRightRotation();
        }
        if (diff < -1 and k < node->right->key)
        {
            // cout<<"case4"<<endl;
            return node->RightLeftRotation();
        }
        // cout<<"here";
        return node;
    }
}

SymNode* SymbolTable::search(string k)
{
    bool found = false;
    // string s="";
    // for(int i=0; i<k.size(); i++){
    //     if(k[i]>='A' && k[i]<='Z'){
    //         k[i]+='a'-'A';
    //     }
    //     s+=k[i];
    // }
    // k=s;
    
    SymNode *Node = root;
    // cout<<Node->key;
    SymNode *p1=new SymNode(); 
    while (!found)
    {
        if (Node == NULL)
        {
            found = false;
            break;
        }
        if (Node->key == k)
        {
            found = true;
            p1 = Node;
            break;
        }
        else
        {
            if (Node->key > k)
            {
                Node = Node->left;
            }
            else
            {
                Node = Node->right;
            }
        }
    }
    if (found == false)
    {
        // cout<<"yess";
        return p1;
    }
    // cout<<Node->key<<"      "<<Node->address<<endl;
    return Node;
}

void SymbolTable::insert(string k)
{
    size++;
    if(k==""){
        return;
    }
    SymNode *Node = root;
    // if (root!=NULL){
    //     // cout<<root->key<<endl;
    //     cout<<"hj";
    // }
    // cout<<"heu"<<endl;
    
    
    // string m="";
    // for(int i=0; i<k.size(); i++){
    //     if(k[i]>='A'&&k[i]<='Z'){
    //         k[i]+='a'-'A';
    //     }
    //     m+=k[i];
    // }
    // SymNode* s=search(k);
    // if(s->key==""){
    root = helperinsert(k, Node, root);
    // cout<<"f";
    // }else{
    //     s->count++;
    // }
}

SymNode* SymbolTable::get_root()
{
    return root;
}

void deete(SymNode *node)
{
    if (node != NULL)
    {
        if (node->left != NULL)
        {
            deete(node->left);
        }
        if (node->right != NULL)
        {
            deete(node->right);
        }
        delete node;
        node = NULL;
    }
}

SymbolTable::~SymbolTable()
{
    deete(root);
    size = 0;
}

Dict::Dict(){
    //p =new SymbolTable;
    dict_vector.resize(1001,NULL);
    // Implement your function here    
}

Dict::~Dict(){
    //p->~SymbolTable;
    // Implement your function here    
}

vector<char> charact={'.',',', '-', ':', '!', '"', '(', ')', '?', '[' ,']' ,';', '@',' '};

bool present(vector<char> charact,char h){
    for (int j=0;j<charact.size();j++){
        if (charact[j]==h){
            return true;
        }
    }
    return false;
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    for(int i=0; i<sentence.length(); i++){
        if(sentence[i]>='A' && sentence[i]<='Z'){
            sentence[i]+='a'-'A';
        }
    }
    string s="";
    for(int i=0; i<sentence.size(); i++){
        char h=sentence[i];
        
        if(int(h)==39 or present(charact,h) ){
            //p->insert(s);
            int ind=hashi(s);
            if(dict_vector[ind]==NULL){
                dict_vector[ind]=new SymbolTable();
            }
            dict_vector[ind]->insert(s);
            s="";
        }else{
            s+=sentence[i];
            if (i==sentence.size()-1){
                // cout<<s<<endl;
                //p->insert(s);
                int ind=hashi(s);
                if(dict_vector[ind]==NULL){
                    dict_vector[ind]=new SymbolTable();
                }
                dict_vector[ind]->insert(s);
                s="";
            }
        }
    }
    // Implement your function here  
    return;
}

int Dict::get_word_count(string word){
    // Implement your function here
    //SymNode* arb=p->search(word);
    for(int i=0; i<word.length(); i++){
        if(word[i]>='A' && word[i]<='Z'){
            word[i]+='a'-'A';
        }
    }
    int ind=hashi(word);
    SymNode* arb;
    if(dict_vector[ind]==NULL){
        return 0;
    }else{
        arb=dict_vector[ind]->search(word);
    }
    // cout<<"reached";
    if(arb->key==""){
        return 0;
    }  
    return arb->count;
}

void command(SymNode* node,vector<string> &commands){
    if (node==NULL){
        return;
    }else{
        int cnt=node->count;
        string s=node->key+", "+to_string(cnt);
        commands.push_back(s);
        command(node->left,commands);
        command(node->right,commands);
    }

}

void iterate(vector<SymbolTable*> dict_vector, vector<string> &commands){
    for(int i=0; i<1001; i++){
        if(dict_vector[i]!=NULL){
            SymNode* p=dict_vector[i]->get_root();
            command(p,commands);
        }
    }
    return;
}

void Dict::dump_dictionary(string filename){
    //SymNode *root=p->get_root();
    ofstream outcfile(filename, ios::app);
    vector <string> comm;
    //command(root,comm);
    iterate(dict_vector,comm);
    int i = 0;
    while (i < comm.size())
    {
        outcfile<< comm[i] << std::endl;
        i++;
    }
    outcfile.close(); 
    return;
}

// int main(){
//     Dict *p1=new Dict();
//     string out="hello.txt";
//     p1->insert_sentence(1,2,1,1,"helllo");
//     //cout<<"this1"<<endl;
//     p1->insert_sentence(1,2,1,1,"helLlo.helllo");
//     //cout<<"this2"<<endl;
//     p1->insert_sentence(1,2,1,1,"hElllo");
//     //cout<<"this3"<<endl;
//     p1->insert_sentence(1,2,1,1,"hello");
//     //cout<<"this4"<<endl;
//     p1->insert_sentence(1,2,1,1,"helo");
//     //cout<<"this5"<<endl;
//     cout<<p1->get_word_count("helllo")<<endl;
//     cout<<p1->get_word_count("hlo")<<endl;
//     // p1->dump_dictionary(out);
//     cout<<"Y";
// }