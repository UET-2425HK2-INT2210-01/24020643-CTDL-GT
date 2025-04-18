#include <iostream> 
using namespace std;
int dem( long long n ){
    if ( n == 0 ) return 0;
    return 1 + dem( n / 10 ); // sau mỗi lẫn số chữ số cần tìm tăng lên 1 và đệ quy tính số chữ số n / 10
}
int main(){
    long long n;
    cin >> n;
    cout << dem( n );
}