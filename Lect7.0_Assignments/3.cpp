// đệ quy nhớ tìm fibonaci
// #include <iostream> 
// #include <vector> 
// using namespace std;
// vector < long long > listfibo ;

// long long fibo( int n ){
//     if ( n < listfibo.size() ) return listfibo[ n ];
//     listfibo.push_back( fibo( n - 1 ) + fibo( n - 2 ) );
//     return listfibo[ n ];
// }
// int main(){
//     int n; 
//     cin >> n;
//     listfibo.push_back( 0 );
//     listfibo.push_back( 1 );
//     cout << fibo( n ) ; 
// }


// đệ quy ko nhớ tìm fibonaci
#include <iostream> 
using namespace std;
long long fibo( int n ){
    if ( n <= 1 ) return ( n == 0 ? 0 : 1 ); // đệ quy dừng và trả về 0 khi n = 0 , 1 khi n = 1
    return fibo( n - 1 ) + fibo( n - 2 ); // trả về công thức tính fibo tại n 
}
int main(){
    int n;
    cin >> n;
    cout << fibo( n );
}
