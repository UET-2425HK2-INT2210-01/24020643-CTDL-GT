

// // Dung DFS
// #include <iostream>
// #include <vector>
// using namespace std;
// int n, m;
// void dfs( int x , vector< vector<int> > v , vector< bool > &visited){
//     for ( int y : v[ x ] ){
//         if ( !visited[ y ] ){
//             visited[ y ] = true;
//             dfs( y, v, visited );
//         }
//     }
// }
// int main(){
//     cin >> n >> m;
//     vector < vector<int> > v( n + 1 ); // do ta xet dinh thu 1,2,...
//     vector < bool > visited( n + 1, false );
//     int x, y;
//     for ( int i = 0 ; i < m ; ++i ){
//         cin >> x >> y;
//         v[ x ].push_back( y );
//         v[ y ].push_back( x );
//     }
//     int s = 0;
//     for ( int i = 1 ; i <= n ; ++i ){ // chu y ta chi xet tu dinh 1 neu xet tu 0 se sai ket qua do
//         if ( !visited[ i ] ){
//             dfs( i, v, visited );
//             s++;
//         }
//     }
//     cout << s;
//     return 0;
// }


// BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs( int x , vector< vector<int> > v , vector< bool > &visited ){
    queue < int > q;
    q.push( x );
    visited[ x ] = true;
    while( !q.empty() ){
         int temp = q.front();
         q.pop();
        for( int y : v[ temp ] ){
            if ( !visited[ y ] ){
                q.push( y );
                visited[ y ] = true;
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector< vector<int> > v ( n + 1 );
    vector< bool > visited( n + 1 , false );
    int x, y;
    for ( int i = 0 ; i < m ; ++i ){
        cin >> x >> y;
        v[ x ].push_back( y );
        v[ y ].push_back( x );
    }
    int s = 0;
    for( int i = 1 ; i <= n ; ++i ){
        if( !visited[ i ] ){
            bfs( i, v, visited );
            s++;
        }
    }
    cout << s;
    return 0;
}
