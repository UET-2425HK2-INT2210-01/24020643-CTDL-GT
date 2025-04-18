#include <iostream> 
using namespace std;
int sum( int n ){ // đệ quy tính tổng n số từ 1 -> n
    if ( n == 1 ) return 1;
    return n + sum( n - 1 ); // sau mỗi lần đệ quy giảm n đi 1 đơn vị 
}
int main(){ 
    int n ;
    cin >> n;
    cout << sum( n );
}