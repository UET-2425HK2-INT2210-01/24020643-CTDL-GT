
// Lomoto Partition
#include <iostream>
#include <vector>
using namespace std;
int Partition( vector< int > &v ,int l ,int r ){
    int p = v[ r ]; // chọn giá trị cho pivot là giá trị ngoài cùng mảng
    int i = l - 1; // i là biến để lưu vị trí pivot
    for ( int j = l ;j <= r ;j++ ){
        if ( v[ j ] <= p ){ 
            i++; // nếu thóa mãn ta tăng i lên sau đó hoán đổi vị trí 2 phần tử chỉ số i và j 
            swap( v[j], v[i] );
        }
    }
    return i;
}
void Quicksort( vector< int > &v ,int l ,int r ){
    if ( l < r ){ // dừng lại khi còn một phần tử 
        int pivot = Partition ( v, l, r ); // tìm pivot qua thao tác Particion()
        Quicksort( v, l, pivot - 1 ); // đệ quy với mảng con trái 
        Quicksort( v , pivot + 1, r ); // đệ quy với mảng con phải 
    }
}
int main(){
    int n;
    cin>>n;
    vector < int > v;
    for ( int i = 0 ; i < n ; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    Quicksort( v , 0 , n-1);
    for ( int i = 0;i < n;i++){
        cout<<v[i]<<" ";
    }
}
