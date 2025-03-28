#include<iostream>
using namespace std;
long long maxsize = 1001;
struct Node{
    int data = 0 ;
    Node* firstchild = nullptr;
    Node* nextsibling = nullptr;
    Node( int x ) : data( x ) {}
};
class Tree{
    public :
    Node* root = nullptr;
    Node** nodeList = new Node*[ maxsize ];
    bool* isChild = new bool[ maxsize ];
    Tree (){
        for ( int i = 0;i < maxsize ;i++){ // Gán giá trị nullptr và false cho 2 mảng
            nodeList[ i ] = nullptr ;
            isChild[i] = false ;
        }
    }
    void updateroot(){ // Cập nhật lại gốc node nào thỏa mãn khác nullptr và ko phải con thì sẽ cập nhật làm gốc
        for ( int i = 0;i < maxsize ;i++){
            if ( nodeList[i] != nullptr && isChild[i] == false ){
                root = nodeList[i];
                break;
            }
        }
    }
    void addNode( int x , int y ){
        if ( nodeList[ x ] == nullptr ) nodeList[ x ] = new Node( x ); // kiểm tra xem node x đã đc khai báo chưa nếu chưa thì khai báo
        if ( nodeList[ y ] == nullptr ) nodeList[ y ] = new Node( y ); // kiểm tra xem node y đã đc khai báo chưa nếu chưa thì khai báo
        isChild [ y ] = true; // cập nhật y là con 
        if (nodeList[ x ]->firstchild == nullptr ){ // trường hợp khi x chưa có con thì firstchild sẽ là node y
            nodeList[ x ]->firstchild = nodeList[ y ];
        }
        else {  // Trường hợp x đã có con ta cần duyệt đến con cuối cùng của x sau đó kết nối với con y 
            Node* tmp = nodeList[ x ]->firstchild; 
            while ( tmp->nextsibling != nullptr ){ // vòng lặp duyệt đến con cuối cùng của x
                tmp = tmp->nextsibling;
            }
            tmp->nextsibling = nodeList[ y ]; // kết nối hay liên kết y với con cuối của x 
        }
        updateroot(); // sau mỗi bước thêm ta cần cập nhật lại root 
    }
    int getHeight(Node* Root){
        if ( root == nullptr ) return 0; // trường hợp nếu root = nullptr thì trả về Height là 0 ;
        if ( Root == nullptr ) return -1; // điều kiện dừng đệ quy và trả về -1
        int heightchild = getHeight( Root->firstchild ); // đệ quy tính height của nhánh firstchild
        int heightsibling = getHeight( Root->nextsibling ); // đệ quy tính height của nhánh nextsibling
        return ( heightchild + 1 >= heightsibling ? heightchild : heightsibling ) + 1; // so sánh trả về chiều cao của nhánh lớn hơn (chú ý duyệt nhánh sibling height ko tăng)
    }
    void Preorder( Node* Root ){
        if ( Root == nullptr) return ; // điều kiện dừng đệ quy 
        cout << Root->data << " "; // in ra giá trị node gốc
        Preorder( Root->firstchild ); // duyệt nhánh firstchild bằng đệ quy 
        Preorder( Root->nextsibling ); // duyệt nhánh nextsibling bằng đệ quy 
    }
    void Postorder(Node* Root){
        if ( Root == nullptr ) return ; // điều kiện dừng 
        Postorder( Root->firstchild ); // duyệt nhánh first bằng đệ quy 
        cout<< Root->data<< " ";  // in ra giá trị node gốc 
        Postorder( Root->nextsibling ); // duyệt nhánh nextsibling bằng đệ quy
    }
    bool subcheck( Node* tmp ){ // kiểm tra xem node tmp có thỏa mãn có nhiều nhất 1 sibling ko 
        if ( tmp ) tmp = tmp->nextsibling ;
        if ( tmp ) tmp = tmp->nextsibling ;
        return tmp == nullptr;
    }
    bool checkBt(Node* Root ){
        if ( Root == nullptr ){
            return true ; // điều kiện dừng vòng đệ quy 
        }
        Node* tmp = Root->firstchild;
        while ( tmp != nullptr ){
            bool a = subcheck( tmp ); // kiểm tra tmp bằng subcheck()
            if ( !a || !checkBt( tmp )) return false ; // nếu tmp ko thỏa mãn hoặc tmp->firstchild ko thỏa mãn thì trả về false

            tmp = tmp->nextsibling ;
        }
        return true ;
    }
    void Inorder ( Node* Root ){
        if ( Root == nullptr ) return ; // điều kiện dừng đệ quy 
        if( Root->firstchild != nullptr ) Inorder( Root->firstchild ); // check xem Root có first ko 
        cout << Root->data << " "; // in ra data của Root
        if ( Root->firstchild != nullptr && Root->firstchild->nextsibling ) Inorder( Root->firstchild->nextsibling ); // check xem firstchild của Root có sibling ko 
    }
};
int main(){
    Tree chamomile;
    int n,m;
    cin >> n >> m;
    int x = 0, y = 0;
    for ( int i = 0 ; i < m ; i++){
        cin >> x >> y;
        chamomile.addNode( x , y);
    }
    cout << chamomile.getHeight( chamomile.root ) << endl;
    chamomile.Preorder( chamomile.root );
    cout<< endl;
    chamomile.Postorder( chamomile.root );
    cout << endl;
    if ( chamomile.checkBt( chamomile.root ) ){
            chamomile.Inorder(chamomile.root);
            cout << endl;
    }
    else cout << "NOT BINARY TREE " ;
    return 0;
}