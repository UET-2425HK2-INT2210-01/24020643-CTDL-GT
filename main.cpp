/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class node{
public :
    int data;
    node* next;
node(int x){
    data=x;
    next=nullptr;
    }
};
class Linklist{
    public:
        node* head;
        int sizelist;
    Linklist(){
        sizelist=0;
        head=nullptr;
        }
    void Insert(int k,int p){
        if ( k < 0||k > sizelist) return ;
        else if (k==0){
            node*newnode=new node(p);
            newnode ->next = head;
            head = newnode;
        }
        else {
                node *newnode =new node(p);
                int i = 0;
                node* tmp = head;
                while(++i!=k){
                    tmp=tmp->next;
                    }
                newnode->next = tmp->next;
                tmp->next=newnode;
        }
        sizelist++;
        }
    void Delete(int k){
        if(k < 0 ||k > sizelist - 1) return ;
        else if(k == 0){
        node *tmp = head;
        head = head->next;
        delete tmp;
        }
        else {
            node *tmp1 = head;
            int i = 0;
            while(++i != k){
                tmp1 = tmp1->next;
            }
            node *tmp = tmp1->next;
            tmp1->next = (tmp1->next)->next;
            delete tmp;
        }
        sizelist--;
        }
    void Printlist(){
        node *tmp = head;
        while(tmp !=nullptr){
                cout << tmp->data<<" ";
                tmp = tmp->next;
        }
        cout<<endl;
        }
};
int main(){
     Linklist head;
     int n;
     cin>>n; 
     getline(cin,s);
     for (int i=0;i<n;i++){
        string s;
        cin.ignore();
        if(s.substr(0,6) == "insert"){
                int a = stoi(s.substr(7,s.find(' ',7)  - 7));
                int b = stoi(s.substr(s.find(' ',7 )+ 1));
           head.Insert(a, b);
        }
        else {
                int a=stoi(s.substr(s.find(' ',7)+1));
                head.Delete(a);
        }
     }
     head.Printlist();
     }
