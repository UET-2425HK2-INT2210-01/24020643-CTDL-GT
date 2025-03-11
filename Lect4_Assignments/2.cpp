#include <iostream>
#include <string>
using namespace std;
class node{
public:
    int data;
    int p;
    node* prev = nullptr;
    node* next = nullptr;
};
class Priqueue{
public :
    node* head;
    int sizeq = 0;
    void Enqueue (int x, int y){
        node* newnode =new node;
        newnode->data = x;
        newnode->p = y;
        if (sizeq == 0) head = newnode;
        else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        node* tmp = head;
        while (tmp->next != nullptr){
            if ( tmp->p < tmp->next->p ) {
                    swap( tmp->data ,tmp->next->data);
                    swap( tmp->p ,tmp->next->p);
                tmp = tmp->next;
            }
            else break;
        }
        sizeq++;
    }
    void Dequeue(){
        if(sizeq == 0 ) return ;
        node* tmp = head;
        head = head->next;
        if ( head) head->prev = nullptr;
        delete tmp;
        sizeq--;
    }
    void Print (){
        for (node* tmp = head ; tmp != nullptr; tmp = tmp->next){
            cout <<"("<<tmp->data<<","<<tmp->p<<");";
        }
        cout<<endl;
    }
};
int main(){
    Priqueue s;
    int n;
    cin>>n;
    cin.ignore();
    string a;
    for (int i = 0;i < n;i++){
        getline(cin,a);
        string b = a.substr(0,a.find(' '));
        if (b == "enqueue") {
            int c = a.find(' ');
            int d = a.find(' ',c+1);
           // cout<<m<<" "<<n<<endl;
            int x = stoi( a.substr(c+1,d-c));
            int y = stoi (a.substr(d+1));
            s.Enqueue(x,y);
        }
        else s.Dequeue();
    }
    s.Print();
    return 0;
}

