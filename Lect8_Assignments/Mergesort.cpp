#include <iostream>
#include <vector>
using namespace std;
void Merge ( vector < int > &v , int left , int right ){ // cần chuyền tham chiếu để trực tiếp thay đổi mảng
    int mid = ( left + right ) / 2;
    int i = left; // biến chạy mảng phụ trái 
    int j = mid + 1; // biến chạy mảng phụ phải 
    int k = 0; // biến chạy mảng temp
    int* temp = new int[ right - left + 1 ];
    while( i <= mid && j <= right ){ // kỹ thuật duyệt đồng thời 2 mảng và sẽ dừng lại khi một trong 2 biến i và j ko hợp lệ 
        if ( v[ i ] < v [ j ] ){ // vẽ hình ra cho dễ quan sát nha 
            temp[ k++ ] = v[ i++ ]; // gán cho mảng temp tại k = giá trị tại i mảng v , sau đó tăng i và k lên 1 
        }
        else temp[ k++ ] = v[ j++ ];
    }
    while( i <= mid ) temp[ k++ ] = v[ i++ ]; // do i , k đã ở vị trí sẵn sàng cho gán (chú ý điều kiện dừng mảng -> gtri i, k ) nên sẽ tăng i và k sau 
    while ( j <= right ) temp[ k++ ] = v[ j++ ];
    for( int t = 0 ; t < k ; ++t ) v[ t + left ] = temp[ t ]; // chép mảng đã sao chép vào v 
    delete []temp;
}
void Mergesort( vector < int > &v ,int  left ,int right ){
    if ( left < right ){ // mảng dừng khi còn 1 phần tử 
        int mid = ( right + left ) / 2; // dấu trừ nha 
        Mergesort( v , left , mid ); // mảng phụ trái 
        Mergesort( v , mid + 1 , right ); // mảng phụ phải 
        Merge ( v , left , right ); // sau khi chia mảng ta sẽ trộn 2 mảng 
    }
}
int main(){
    int n;
    cin >> n;
    vector < int > v ( n );
    for ( int &y : v ) cin >> y;
    Mergesort( v , 0 , n - 1 );
    for ( int y : v ) cout << y << " " ;
    return 0;
}