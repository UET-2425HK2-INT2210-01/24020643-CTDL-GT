#include <iostream>
using namespace std;
struct Node{
    int data ;
    Node* leftchild ;
    Node* rightchild ;
    Node( int val ) : data( val ), leftchild( nullptr ), rightchild( nullptr ){}; // Khởi tạo giá trị cho Node
};
class BST{
    public :
    Node* root = nullptr ;
    Node* Insert ( Node* Root , int k ){
        if ( Root == nullptr ) return new Node( k ); // Điều kiện dừng vòng đệ quy và nối newnode vào cây
        if ( Root->data >= k ) Root->leftchild = Insert( Root->leftchild, k); // Nếu k nhỏ hơn giá trị gốc thì duyệt sang trái ( ở đây ta xét TH bằng duyệt trái)
        else Root->rightchild = Insert( Root->rightchild, k ); // k lớn hơn gốc duyệt sang phải 
        return Root; 
    }
    Node* findmin( Node* Root ){ // tìm min nhánh bên phải của cây con 
        while( Root->leftchild != nullptr ){ // duyệt tới khi ko còn con trái nữa 
            Root = Root->leftchild;
        }
        return Root;
    }
    Node* Delete( Node* Root , int k ){
        // tìm node cần xóa 
        if ( Root == nullptr ) return nullptr; // điều kiện dừng đệ quy ( ở đây đã xử lý TH ko tìm thấy giá trị cần xóa )
        if ( Root->data > k ) Root->leftchild = Delete ( Root->leftchild, k); // duyệt sang trái khi k < gốc
        else if ( Root->data < k ) Root->rightchild = Delete( Root->rightchild, k); // duyệt sang phải nếu k > gốc
        // khi tìm thấy node cần xóa thực hiện thao tác xóa
        else {
            // trường hợp node có 1 con và ko có con nào
            if ( Root->leftchild == nullptr ) { // xét TH node có con phải hoặc ko có con
                Node* tmp = Root->rightchild ; // lưu con phải vào tmp
                delete Root ; // xóa node 
                return tmp ; // trả về tmp và sẽ đc nối vào cây
            }
            else if ( Root->rightchild == nullptr ){  // trường hợp có con trái hoặc ko có con
                Node* tmp = Root->leftchild ;
                delete Root ;
                return tmp;
            }
            // trường hợp có 2 con ( ở đây ta đi tìm giá trị min của nhánh phải để thay thế )
            else {
                Node* tmp = findmin( Root->rightchild ); // tìm đến giá trị min nhánh phải
                swap( Root->data , tmp->data ); // đổi chỗ 2 node
                Root->rightchild = Delete( Root->rightchild, tmp->data ); // xóa node sau khi swap ( node cần xóa ở lá )
            }
        }
        return Root;
    }
    void Inorder ( Node* Root){ // duyệt cây theo Inorder
        if ( !Root ) return ;
        Inorder ( Root->leftchild );
        cout << Root->data << ' ';
        Inorder ( Root->rightchild );
    }
};
int main(){
    BST sunflower;
    int i = 0, j = 0;
    while ( true ){
        cout << "Cac Thao Tac "<< endl;
        cout << "Nhap 1 de Insert"<< endl;
        cout << "Nhap 2 de Delete"<< endl;
        cout << "Nhap 3 de duyet"<< endl;
        cout << "Nhap 4 de thoat"<< endl;
        cin >> i;
        if ( i == 1 ){
            cout << " Nhap so muon them "<< endl;
            cin>> j;
            sunflower.root = sunflower.Insert( sunflower.root, j );
        }
        else if ( i == 2 ){
            cout << " Nhap phan tu muon xoa "<< endl;
            cin>> j;
            sunflower.root = sunflower.Delete( sunflower.root, j );
        }
        else if ( i == 3 ) {
            sunflower.Inorder( sunflower.root );
        cout << endl;
        }
        else if ( i == 4 ) break;
        else cout << "Lua chon khong hop le, vui long chon lai ";
    }
    return 0;
}