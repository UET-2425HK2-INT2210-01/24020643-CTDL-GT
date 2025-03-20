/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
struct Sinhvien {
    long long ID;
    string Name;
    string Class;
};
struct Node {
    Sinhvien data;
    Node* next = nullptr;
};
struct List{
    Node* head = nullptr;
    int sizel = 0;
    void insert1 ( Node* newnode ){
        if (sizel == 0 ) head = newnode;
        else {
            newnode->next = head;
            head = newnode;
        }
        sizel++;
    }
    string infor( long long id ){
        if ( sizel == 0 ) return "NA,NA";
        else {
            Node* tmp = head;
            while( tmp != nullptr ){
                if ( tmp->data.ID == id ) {
                    return tmp->data.Name + "," + tmp->data.Class;
                }
                tmp = tmp->next;
            }
            return "NA,NA";
        }
    }
    void delete1( long long id ){
        if ( sizel == 0 ) return ;
        else if ( sizel == 1 ) {
            Node* tmp = head;
            head = nullptr;
            delete tmp;
            sizel--;
        }
        else {
            Node* tmp = head;
            while ( tmp != nullptr ) {
                if ( tmp->next != nullptr && tmp->next->data.ID == id ){
                    Node* tmp1 = tmp->next;
                    tmp->next = tmp1->next;
                    delete tmp1;
                    sizel--;
                }
                tmp = tmp->next;
            }
        }
    }
};
long long hashfunction (long long id){
    return (id*12 + id*id) % 1001;
}
void Insert ( List ht[], long long  id, string name , string clas){
    long long Index = hashfunction( id );
    Node* newnode = new Node;
    newnode->data.ID = id;
    newnode->data.Name = name;
    newnode->data.Class = clas;
    ht[Index].insert1( newnode );

}
string Infor( List ht[], long long id ){
    long long Index = hashfunction( id ) ;
    return ht[Index].infor( id ) ;
}
void Delete ( List ht[], long long id ){
    long long Index = hashfunction ( id );
    ht[Index].delete1( id ) ;
}
int main(){
    int n;
    cin >> n;
    List* ht = new List[1001];
    string s;
    cin.ignore();
    for (int i = 0;i < n;i++) {
        getline(cin,s);
        string a = s.substr(0 , 6 );
        if ( a == "Insert") {
            long long id = stoi (s.substr( 7 , s.find(",")-7 ));
            s[s.find(",")] = '.';
            string name = s.substr(s.find(".")+1,s.find(",")-s.find(".")-1);
            string clas = s.substr(s.find(",")+1,s.find(')')-s.find(",")-1);
            Insert( ht , id , name ,clas );
        }
        else if ( a == "Infor(" ){
            long long id = stoi(s.substr(6,s.find(")")-6));
            cout<<Infor( ht , id )<<"\n";
        }
        else {
            long long id = stoi(s.substr(7,s.find(")")-7));
            Delete( ht , id );
        }
    }
    delete[] ht;
}
