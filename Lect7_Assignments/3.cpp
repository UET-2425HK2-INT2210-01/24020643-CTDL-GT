#include <iostream>
using namespace std;
int gcd( int a ,int b ){ 
    // đệ quy tính UCNN qua công thức gcd ( a , b ) = gcd ( b , a %b )
    if ( b == 0 ){
        return a;
    }
    return gcd( b, a % b );
}
int main(){
    int n, m;
    cin >> n >> m;
    cout << gcd( n , m );
}