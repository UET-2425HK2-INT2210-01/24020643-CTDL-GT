/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
    node(){
    next=nullptr;
    prev=nullptr;
    }
};
void Insert(node*&head,int x){
    node*newnode=new  node;
    newnode->data=x;
    newnode->next=head;
    if (head!=nullptr){
        head->prev=newnode;
    }
    head=newnode;
}
int check(node*&head,int n){
     int dem=0;
    if(n<3) return 0;
    else {
        head=head->next;
        while(head->next!=nullptr){
            if (head->data+head->next->data+head->prev->data==0) dem++;
        head=head->next;
        }
    }
    return dem;
}
int main(){
    int n;
    cin>>n;
    node*head=nullptr;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        Insert(head,x);
    }
    cout<<check(head,n);
}
