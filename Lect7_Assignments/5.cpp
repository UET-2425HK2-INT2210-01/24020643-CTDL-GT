#include <iostream> 
using namespace std;
bool check[ 10001 ] = { false };
// dùng thuật toán quay lui để tìm hoán vị các sô từ 1 -> n 
void permutation( string s , int n ){
    if ( n == s.size() ) { // khi đã tìm được s in ra màn hình
        cout << s << endl;
        return ;
    }
    for ( int i = 1 ; i <= n ; i ++ ){
        if ( !check [ i ] ){ // kiểm tra nếu chưa xuất hiện thì thêm 
            check[ i ] = true ; // đánh dấu đã thăm 
            permutation( s + to_string( i ), n ); // thêm số vào string 
            check[ i ] = false ; // đánh dấu lại chưa thăm để chuẩn bị cho in xâu mới
        }
    }
}
int main(){ 
    int n ; 
    cin >> n;
    string s;
    permutation( s , n );
}