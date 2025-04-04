#include <iostream>
using namespace std;
class minheap{
    public :
    int listnode[ 1001 ]; // biểu diễn minheap qua mảng 
    int sizel; // số lg node trong cây 
    minheap (){ // gán giá trị đầu 
        sizel = 0;
        for ( int i = 0; i < 1001 ; i++ ) listnode[ i ] = 0;
    }
    int leftchild ( int i ) { // chỉ số con trái
        return 2 * i + 1 ;
    }
    int rightchild ( int i ) { // chỉ sô con phải 
        return 2 * i + 2 ;
    }
    int root ( int i ) { // chỉ số gốc ( hay cha )
        return ( i - 1 )/ 2 ;
    }
    void HeapifyUp( int i ){ // ham heapifyup 
        if ( i == 0 ) return ;
        if ( listnode[ i ] < listnode[ root( i ) ] ){ // nếu nhỏ hơn gốc thì đẩy lên 
            swap( listnode[ i ], listnode[ root( i ) ]); 
            HeapifyUp ( root( i ) );
        }
    }
    void HeapifyDown( int i ){ // ham heapifydown
        int smallest = i ; // lưu chỉ số phần tử min 
        int left = leftchild( i );
        int right = rightchild( i );
        if (( left < sizel ) && ( listnode[ left ] < listnode[ smallest ] )) 
        smallest = leftchild( i );
        if ( ( right < sizel ) && ( listnode[ right ] < listnode[ smallest ] ) ) // so sanh tim ra min 
        smallest = right;
        if ( smallest != i ) { // nếu tìm đc min thì thực hiện 
            swap ( listnode[ i ], listnode[ smallest ] ); // đẩy node xuống cuối 
            HeapifyDown( smallest ); // Đệ quy lập lại thao tác 
        }
    }
    void Insert( int k ){
        if ( sizel > 1001 ){ // kiểm tra xem đầy chưa 
            cout << " mang day rui ko them nua nhen"<< endl;
            return ;
        }
        listnode[ sizel ] = k ; // thêm node
        sizel ++; // tăng số lg ptu 
        HeapifyUp( sizel - 1 ); // sắp xếp lại cây 
    }
    void Delete( int k ){
        int i = 0;
        while( i < sizel ){ // kiểm tra xem mảng có k ko và nếu có trả về chỉ số
            if ( listnode[ i ] == k ) break;
            i++;
        }
        if ( i != sizel ){ // nếu k có trong mảng thao tác
            swap( listnode[ i ] , listnode[ sizel - 1 ] );
            sizel -- ;
            if ( listnode[ i ] < listnode[ root( i ) ] ) HeapifyUp( i ); // nếu node nhỏ hơn gốc dùng heapifyup cập nhật lại cây
            else HeapifyDown( i ); // ngược lại ta cập nhật cây qua thao tác heapifydown 
            return ;
        }
        cout << " ko tim thay gia tri xoa nhoa ";
    }
    void print(){
        for ( int i = 0; i < sizel ; i++ ) cout << listnode[ i ] << "  ";
    }
};
int main(){
    minheap Durian;
    int i = 0, j = 0;
    while ( true ){
        cout << " Nhap thao tac : "<< endl;
        cout << " Nhap 1 de them "<< endl;
        cout << " Nhap 2 de xoa "<< endl;
        cout << " Nhap 3 de in "<< endl;
        cout << " Nhap 4 de thoat "<< endl;
        cin >> i ;
        switch( i ){
            case 1 : 
            cout << " Nhap so ban muon them "<< endl;
            cin >> j ;
            Durian.Insert( j );
            break ;
            case 2 : 
            cout << " Nhap so ban muon xoa "<< endl;
            cin >> j ;
            Durian.Delete( j );
            break;
            case 3 : 
            Durian.print();
            cout << endl;
            break;
            case 4 : return 0;
            default :
                cout << " Thao tac ko hop le , vui long nhap lai "<< endl;
        }
    }
    return 0;
}
