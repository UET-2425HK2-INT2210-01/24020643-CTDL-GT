/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
struct node{
    int data;
    node* next=nullptr;
};
struct Queue{
    node *head=nullptr;
    int sizequeue=0;
    void Insert(int p){
        node *newnode=new node;
        newnode->data=p;
        if (sizequeue==0) head=newnode;
        else {
            node *tmp=head;
            for (;tmp->next!=nullptr;tmp=tmp->next);
            tmp->next=newnode;
        }
        sizequeue++;
    }
    void Delete(){
    node *tmp=head;
    if (tmp==nullptr) return ;
    else {
        head=head->next;
        delete tmp;
        sizequeue--;
        }
    }
    void Print(){
    for (node *tmp=head;tmp!=nullptr;tmp=tmp->next){
        cout<<tmp->data<<" ";
    }
    }
};
int main(){
    int n;
    cin>>n;
    cin.ignore();
    Queue head;
    for (int i=0;i<n;i++){
        string s;
        getline(cin,s);
        if (s.substr(0,7)=="enqueue"){
            int a=stoi(s.substr(8));
            head.Insert(a);
        }
        else head.Delete();
    }
    head.Print();
}
