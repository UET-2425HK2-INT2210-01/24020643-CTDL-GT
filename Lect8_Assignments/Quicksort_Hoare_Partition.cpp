
// Hoare Partition
#include <iostream>
#include <vector>
using namespace std;
int HoarePartition ( vector < int > &v , int left , int right ){
    int p = v[ left ];
    // tất cả phần tử từ left -> i sẽ nhỏ hơn hoặc bằng p ( bằng tại i )
    // tất cả phần tử từ j  đến right sẽ lớn hơn hoặc bằng pivot ( bằng tại j )
    int i = left - 1; // lay vi du khi tang i sau khi so sanh de hieu tai sao phai tang i trc ( truong hop full 2 )
    int j = right + 1;
    while ( true ){
        while( v[ ++i ] < p ); // bước đầu tiên i sẽ dừng ở left 
        // lay vi du mang full 2 de hieu tai sao ko lay dấu bằng
        while( v[ --j ] > p );
        if ( i >= j ) return j; // tra ve j là vị trí chia mảng thành 2 phần phần sau j và trước -> j
        swap( v[ i ] , v[ j ] );
    }
}
void Quicksort( vector < int > &v , int left , int right ){
    if ( left < right ){
        int pivot = HoarePartition ( v , left , right );
        Quicksort ( v , left , pivot ); 
        // sự khác biệt giữa Hoare và Lomoto là Hoare chia mảng thành 2 phần , Lomoto chia 3 phần với pivot đã được sx
        Quicksort ( v , pivot + 1 , right );
    }
}
int main(){
    int n;
    cin >> n;
    vector < int > v ( n );
    for ( int &y : v ) cin >> y;
    Quicksort( v , 0 , n - 1 );
    for ( int y : v ) cout << y << " ";
    return 1;
}