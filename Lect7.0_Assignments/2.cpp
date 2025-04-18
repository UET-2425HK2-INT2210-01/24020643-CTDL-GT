#include <iostream> 
using namespace std;
long long factorial( int n ){ // đệ quy tính giai thừa của n
    if ( n == 2 ) return 2;
    return n * factorial( n - 1 ); // sau mỗi lần giảm n đi 1 
}
int main(){
    int n;
    cin >> n;
    cout << factorial( n );
}