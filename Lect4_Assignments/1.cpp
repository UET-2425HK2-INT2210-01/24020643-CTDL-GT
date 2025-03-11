#include <iostream>
#include <string>
using namespace std;
class node{
public:
    int data;
    node* next =nullptr;
};
class llist{
public :
    node* head =nullptr;
    int sizel=0;
    void Append(int p){
        node *newnode = new node;
        newnode->data = p;
        if (sizel == 0) {
            head = newnode;
        }
        else {
            node *tmp = head;
            while ( tmp ->next!=nullptr){
                tmp = tmp-> next;
            }
            tmp->next = newnode;
        }
        sizel++;
    }
    void Search(int x){
        node* tmp=head;
        int positision=0;
        while (tmp!=nullptr){
            if (tmp->data == x){
                    cout<< positision<<endl;
                return ;
            }
            tmp = tmp->next;
            positision ++;
        }
        cout << "NO"<<endl;
        return ;
    }
    void Insert( int p){
        node *newnode = new node;
        newnode ->data = p;
        if ( sizel==0 ) head = newnode ;
        else {
            newnode ->next =head;
            head = newnode ;
        }
        sizel++;
    }

    void Print(){
        node *tmp = head ;
        while (tmp!= nullptr) {
            cout <<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
    void  Reverse(){
        llist s;
        node* tmp=head;
        while (tmp != nullptr) {
            s.Insert (tmp -> data);
            tmp =tmp->next;
        }
        head = s.head;
        s.Print();
    }
};

int main(){
    llist s;
    int n;
    cin>>n;
    cin.ignore();
    for (int i=0;i<n;i++){
        string a;
        getline(cin,a);
        string b=a.substr(0,a.find(' '));
        if (b=="append") {
            int x = stoi( a.substr(a.find(' ')+1));
            s.Append(x);
        }
        else if(b == "search") {
             int x = stoi( a.substr(a.find(' ')+1));
             s.Search(x);
        }
        else s.Reverse();
    }
    return 0;
}