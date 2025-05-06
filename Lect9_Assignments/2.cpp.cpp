#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n , S;
    cin >> n >> S;
    int v[ n ];
    for( int &y : v ) cin >> y;
    vector< int > dp( S + 1 , 0 );
    // dp[ i ] cho biết có thể tạo được vật thể có tổng bằng i hay ko 
    dp[ 0 ] = 1;
    for ( int i = 0 ; i < n ; i ++ ){
        for( int j = S ; j >= v[ i ] ; j-- ){
            if(  dp[ j - v[ i ] ] == 1 ) 
            // nếu tổng là j - [i]( tổng của các đồ trước đó ) là 1 thì khi kết hợp với đồ vật thứ i sẽ tạo được tổng bằng j => dp được gán là 1 
                dp [ j ] = 1;
        }
    }
    if( dp[ S ] == 1 ) cout << "YES" ;
    else cout << "NO";
    return 1;
}