#include <iostream> 
using namespace std; 
long long power( int x , int n ){ 
    // đệ quy tính x ^ n cho trường hợp n >= 1 qua công thức x^n = a*a*x nếu n lẻ , = a*a nếu n chắn với a = x^( n/2 )
    if ( n == 1 ) return x;
    //if ( n == 0 ) return 1; // cho trường hợp n >= 0 
    long long tmp = power ( x , n / 2); 
    return ( n % 2 == 0 ? tmp * tmp : tmp * tmp * x );
}
int main(){
    int x , n ;
    cin >> x >> n;
    cout <<  power( x , n );
}