#include <iostream>
using namespace std;
void binary ( int n , string s ){
    if ( n <= 0 ) {
        cout << s << endl;
        return ;
    }
    // trong de quy can chu y co thay doi n hay ko neu la n-- se thay doi n va ko dc ( tg tu voi chuoi s nha )
    binary( n-1 , s + "0" ); // them kí tự '0' vào string 
    binary( n-1 , s + "1" ); // them kí tự '1' vào string
}
int main(){
    int n;
    cin >> n;
    string s;
    binary( n , s );
    return 0;
}