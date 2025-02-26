/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node{
    int data;
    node* next=nullptr;
};
struct Stack{
    node *head=nullptr;
    int sizestack=0;
    void Insert(int p){
        node *newnode=new node;
        newnode->data=p;
        if (sizestack==0) head=newnode;
        else {
            newnode->next=head;
            head=newnode;
        }
        sizestack++;
    }
    void Delete(){
    node *tmp=head;
    if (tmp==nullptr) return ;
    else {
        head=head->next;
        delete tmp;
        sizestack--;
        }
    }
    void Print(){
         vector<int> s;
    for (node *tmp=head;tmp!=nullptr;tmp=tmp->next){
        s.insert(s.begin(),tmp->data);
    }
    for(int i=0;i<s.size();i++) cout<<s[i]<<" ";
    }
};
int main(){
    int n;
    cin>>n;
    cin.ignore();
    Stack head;
    for (int i=0;i<n;i++){
        string s;
        getline(cin,s);
        if (s.substr(0,4)=="push"){
            int a=stoi(s.substr(5));
            head.Insert(a);
        }
        else head.Delete();
    }
    head.Print();

}
