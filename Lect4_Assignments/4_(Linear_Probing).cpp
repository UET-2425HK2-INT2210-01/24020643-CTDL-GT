#include <iostream>
#include <string>
using namespace std;
struct Sinhvien {
    long long ID;
    string Name;
    string Class;
    int check = 0;
};
long long hashfunction (long long id){
    return (id*12 + id*id) % 1001;
}
void Insert ( Sinhvien ht[], long long  id, string name , string clas){
    long long Index = hashfunction( id );
    Sinhvien newsv;
    newsv.ID = id;
    newsv.Name = name;
    newsv.Class = clas;
    newsv.check ++;
    if ( ht[ Index ].check == 0 ) ht[ Index ] = newsv;
    else for (int i = Index + 1; i != Index ;(++i)/1001 ){
        if ( ht [ Index ].check != 1 ){
            ht[ Index ] = newsv;
            break;
        }
}
}
string Infor( Sinhvien ht[], long long id ){
    long long Index = hashfunction( id ) ;
    if (( ht[Index].check == 1 ) && ( ht[Index].ID == id )) return ht[Index].Name + "," + ht[Index].Class;
    else {
        for (int i = Index + 1 ; i != Index;(++i) / 1001){
            if ( ht[Index].check == 1 && ht[ Index ].ID == id ) return ht[Index].Name + "," + ht[Index].Class;
        }
        return "NA,NA";
    }
}
void Delete ( Sinhvien ht[], long long id ){
    long long Index = hashfunction ( id );
    if ( (ht[Index].check == 1) && (ht[ Index ].ID == id )) ht[Index].check = 0;
    else {
        for (int i = Index + 1;i != Index;(++i) / 1001){
            if (( ht[Index].check == 1) && (ht[ Index ].ID == id )) ht[Index].check = 0;
        }
    }
}
int main(){
    int n;
    cin >> n;
    Sinhvien* ht = new Sinhvien[1001];
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

