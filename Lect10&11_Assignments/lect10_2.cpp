

// Dung DFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
vector < int > parent( 1001, 0 );
void bfs( int x , vector< vector<int> > v ){
    queue < int > q;
    vector < bool > visited( n + 1 , false );
    q.push( x ); // khoi tao co so de duyet bfs
    visited[ x ] = true;
    while( !q.empty() ){
        int temp = q.front();
        q.pop();
        for ( int y : v[ temp ] ){ // tham cac dinh anh chi em va them vao queue
            if ( !visited[ y ] ){
                q.push( y );
                visited[ y ] = true;
                parent[ y ] = temp;
            }
        }
    }
}
int main(){
    int h, k;
    cin >> n >> m >> h >> k;
    vector < vector<int> > v( n + 1 ); // do ta xet dinh thu 1,2,...
    int x, y;
    for ( int i = 0 ; i < m ; ++i ){
        cin >> x >> y;
        v[ x ].push_back( y ); // ta xét với đồ thị có hướng
        //v[ y ].push_back( x );
    }
    bfs( h, v );
    int t = k;
    vector < int > path; // path luu duong di tu h den k
    while( t != h ){ // truy vet duong di va them vao path
        path.push_back( t );
        t = parent[ t ];
    }
    path.push_back( h ); // thêm đỉnh h vào đường đi 
    reverse( path.begin(), path.end() ); // đảo ngược xâu trả về đường đi ngắn nhất từ h -> k 
    cout << path.size() - 1 << endl;
    cout << " Duong di ngan nhat tu " << h << " den " << k << " : " ;
    for ( int y : path ) cout << y << " " ;
    return 0;
}
