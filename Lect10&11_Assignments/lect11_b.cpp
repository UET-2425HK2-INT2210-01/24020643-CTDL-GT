#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
long long INF = 100000000001;
struct node{
    int u,v;
    int w;
    node ( int x , int y , int z ){
        u = x;
        v = y;
        w = z;
    }
};
void floyd( vector < vector < long long > > &D , int n ){
    for (int k = 1 ; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1 ; v <= n; v++) {
                if (D[u][v] > D[u][k] + D[k][v]) { // neu duong di tu u den v lon hon tu u den k den v thi cap nhat
                    D[u][v] = D[u][k] + D[k][v];
                }
            }
        }
    }
}
int main(){
    int  n, m, h, k;
    cin >> n >> m >> h >> k;
    vector < node > e; // mang luu danh sach canh
    vector < vector < long long > > w ( n + 1 , vector< long long >( n + 1 , INF ));
    int x,y,z;
    for ( int i = 0 ; i < m ; ++i ){ // buoc nhap danh sach canh
        cin >> x >> y >> z;
        node temp( x, y , z );
        e.push_back( temp );
    }
    for( auto temp : e ){ // chuyen danh sach canh thanh ma tran ke 
        x = temp.u;
        y = temp.v;
        z = temp.w;
        w[ x ][ y ] = z;
    }
    for ( int i = 0 ; i <= n ; ++i ) w[ i ][ i ] = 0;
    floyd( w, n );
    for( int i = 1; i <= n; i ++ ){ // in ra sau khi dung thuat toan floyd
        for ( int j = 1; j <= n; j++ ){
            cout << w[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}