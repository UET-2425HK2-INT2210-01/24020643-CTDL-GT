#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n , S;
    cin >> n >> S;
    int v[ n ];
    int w[ n ];
    int dp[ n + 1 ][ S + 1 ];
    // dp[ i ][ j ] cho biết tổng value lớn nhất mà túi có thẻ chứa được tạo từ các đồ vật từ 1,2,3,...i với trọng số nhỏ hơn hoặc bằng j
    for ( int i = 0 ; i < n ; i++ ) cin >> w[ i ] >> v[ i ];
    for ( int i = 0 ; i <= n ; i++ ){
        for ( int j = 0 ; j <= S ; j++ ){
            if ( i == 0 || j == 0 ) dp[ i ][ j ] = 0;  // trường hợp cơ sở 
            else {
                dp[ i ][ j ] = dp[ i-1 ][ j ];
                if ( w[ i-1 ] <= j ) 
                // khi túi đã chứa được vật thể thứ i ta thực hiện so sánh xem trường hợp túi ko lấy vật thứ i và có lấy vật thứ i thì trường hợp nào sẽ cho tổng max
                    dp[ i ][ j ] = max( dp[ i-1 ][ j ],dp[ i-1 ][ j - w[ i-1 ] ] + v[ i-1 ] );
            }
        }
    } 
    cout << dp[ n ][ S ] << endl; // tổng lớn nhất cần tìm 
    // tìm ra các vật thể được chọn 
    int i = n ; 
    int j = S ;
    cout << " Chon vat the thu : ";
    while( i != 0 ){
        if ( dp[ i ][ j ] == dp[ i - 1 ][ j ] ) i--;
        else{
            cout << i << " ";
            i--;
            j -= w[ i ];
        }
    }
    
   
}