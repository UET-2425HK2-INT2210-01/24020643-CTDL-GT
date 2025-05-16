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
void bellman_ford( int n, int h, vector < node > e, vector < long long > &D , vector < int > &trace ){
    D[ h ] = 0; // khoi tao truong hop co so do dai duong di tu h den h la 0
    for ( int i = 1; i < n ; ++i ){ // duyet n - 1 lan de tim ra duong di ngan nhat
        for ( auto tmp : e ){
            int u = tmp.u;
            int v = tmp.v;
            int w = tmp.w;
            if ( D[ u ] != INF && D[ v ] > D[ u ] + w ){
                // neu da co duong di ngan nhat tu h den u thi se so sanh de tim ra duong di ngan nhat tu h den v 
                D[ v ] = D[ u ] + w; // gan lai gia tri cho D[ v ]
                trace[ v ] = u; // danh dau lai duong di ngan nhat tu h den v
            }
        }
    }
    
}
void trace_path( int h , int k , vector < int > trace, vector< long long > D ){
    if ( trace[ k ] == -1 ){ // kiem tra xem co duong di hay ko
        cout << " Khong co duong di ngan nhat tu " << h << " den " << k << endl;
        return;
    }
    cout << D[ k ] << endl;
    vector < int > path;
    int t = k;
    while( t != h ){
        path.push_back( t );
        t = trace[ t ];
    }
    path.push_back( h );
    reverse( path.begin(), path.end() );
    for ( int x : path ) cout << x << " ";
}
int main(){
    int  n, m, h, k;
    cin >> n >> m >> h >> k;
    vector < node > e; // mang luu danh sach canh
    vector < long long > D( n + 1 , INF ); // mang luu duong di ngan nhat tu h den cac dinh con lai, ban dau ko co duong di thi se la infinity 
    vector < int > trace( n + 1 , -1 ); // mang de truy vet duong di
    int u, v, w;
    for ( int i = 0 ; i < m ; ++i ){ // buoc nhap danh sach canh
        cin >> u >> v >> w;
        node temp( u, v, w );
        e.push_back( temp );
    }
    bellman_ford( n, h, e, D ,trace );
    trace_path( h , k , trace , D);
    return 0;
}