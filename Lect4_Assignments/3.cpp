#include <iostream>
using namespace std;
class Node{
    public:
    char data;
    Node *next=nullptr;

};
class Stack{
public:
    Node* head;
    int sizes = 0;
    void Insert(char s){
        Node *newnode = new Node;
        newnode->data = s;
        if (sizes == 0) head = newnode;
        else {
            newnode->next = head;
            head = newnode;
    }
    sizes++;
    }
    void Delete(){
        if (sizes == 0) return ;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        sizes--;
    }
    char Get(){
        return head->data;

    }
};
string check(string s){
    Stack st;
    for (int i = 0;i < s.size();i ++){
        if (s[i] == '('||(s[i] == '[')||(s[i] == '{')) st.Insert( s[i] );

        else {
            if (st.sizes == 0) return "NO";
            else if (st.Get() == '('&& s[i] == ')' ) st.Delete();
            else if (st.Get() == '['&& s[i] == ']' ) st.Delete();
            else if (st.Get() == '{'&& s[i] == '}' ) st.Delete();
            else st.Insert(s[i]);
        }
    }
    if (st.sizes == 0 ) return "YES";
    else return "NO";
}
int main(){
    int n;
    cin>>n;
    for (int i = 0;i < n; i++){
    string s;
    cin>>s;
    cout<<check(s)<<endl;
    }
}
