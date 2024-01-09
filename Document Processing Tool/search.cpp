// Do NOT add any other includes
#include "search.h"
// #include "Node.cpp




Star::Star(){}

Star::~Star(){}

Star::Star(int b_code, int pg, int para, int s_no, string k){
    book_code = b_code;
    page = pg;
    paragraph = para;
    sentence_no = s_no;
    key = k;
}

vector<int> prefix(string needle){
    vector<int> ans(needle.length(),0);
    if(needle==""){
        return ans;
    }
    int i=1;
    int prev=0;
    while(i<needle.length()){
        if(needle[i]==needle[prev]){
            ans[i]=prev+1;
            prev+=1;
            i++;
        }else if(prev==0){
            ans[i]=0;
            i++;
        }else{
            prev=ans[prev-1];
        }
    }
    return ans;
}

vector<int> searchh(string needle, string haystack){
    vector<int> prf=prefix(needle);
    //cout<<prf.size()<<endl;
    vector<int> ans;
    int i=0;
    int j=0;
    while(i<haystack.length()){
        if(haystack[i]==needle[j]){
            j++;
            i++;
        }else{
            if(j==0){
                i++;
            }else{
                j=prf[j-1];
            }
        }
        if(j==needle.length()){
            ans.push_back(i-needle.length());
            j=prf[j-1];
        }
    }
    // cout<<ans.size()<<endl;
    // cout<<ans[0]<<endl;
    return ans;
}


void Linkedlist::insertNode(Node *d)
{
    if (head == NULL)
    {
        head = d;
        
        tail = d;
        return;
    }
    tail->right = d;
    tail=tail->right;
}

SearchEngine::SearchEngine()
{
    // store = {};
    List = new Linkedlist();
    // Implement your function here
}

SearchEngine::~SearchEngine()
{
    while (store.size()>0){
        delete store.back();
        store.pop_back();
    }
    // Implement your function here
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    for(int i=0; i<sentence.length(); i++){
        if(sentence[i]>='A' && sentence[i]<='Z'){
            sentence[i]+='a'-'A';
        }
    }
    Star *sen = new Star(book_code, page, paragraph, sentence_no, sentence);
    store.push_back(sen);
    return;
}


Node *SearchEngine::search(string pattern, int &n_matches)
{ 
    for(int i=0; i<pattern.length(); i++){
        if(pattern[i]>='A' && pattern[i]<='Z'){
            pattern[i]+='a'-'A';
        }
    }
    int cnt=0;
    //cout<<store.size()<<endl;
    for (int j=0;j<store.size();j++){
        string s1=store[j]->key;
        vector<int> p=searchh(pattern,s1);
        cnt+=p.size();
        for (int k=0;k<p.size();k++){
            Node* n1=new Node();
            n1->book_code=store[j]->book_code;
            //cout<<"tillhere"<<endl;
            n1->page=store[j]->page;
            n1->paragraph=store[j]->paragraph;
            n1->sentence_no=store[j]->sentence_no; 
            n1->offset=p[k];  
            // cout<<p[k]<<endl;
            List->insertNode(n1);
        }
    }
    n_matches=cnt;
    
    return List->head;
}

// int main(){
//     SearchEngine *S=new SearchEngine();
//     S->insert_sentence(1,1,1,1,"hello vatslloal");
//     int b=4;
    
//     Node* n=S->search("llfhgo",b);
//     //cout<<"herehj";
//     cout<<n->offset<<endl;
//     // cout<<n->next->offset;
//     //cout<<6;
// }