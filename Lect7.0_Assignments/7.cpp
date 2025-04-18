#include <iostream>
#include <iomanip>
using namespace std;
long long reversenumber( long long revNum , long long n ){ 
    // đệ quy qua công thức revNum = revNum * 10 + n % 10
    if ( n == 0 ) return revNum;
    return reversenumber( revNum * 10 + n % 10, n / 10 );
}
int num( long long n ){
    if ( n == 0 ) return 0;
    return 1 + num( n / 10 );
}
int main(){
    long long n;
    cin >> n;
    // dùng setx để xử lý trường hợp 1200 sẽ in ra 0021
    cout << setw( num( n ) ) << setfill( '0' ) << reversenumber(  0 , n );
}