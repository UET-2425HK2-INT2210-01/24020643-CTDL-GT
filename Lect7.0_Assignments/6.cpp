#include <iostream>
using namespace std;
int sum( long long n ){
    if ( n == 0 ) return 0;
    // tổng của số hàng đơn vị của n và chữ số đơn vị của n / 10
    return n % 10 + sum( n / 10 ); 
}
int main(){
    long long n;
    cin >> n;
    cout << sum( n );
}