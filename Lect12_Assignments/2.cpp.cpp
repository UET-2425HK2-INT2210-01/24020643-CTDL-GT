#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge{ // cau truc cua mot canh
    int u,v,w;
    Edge( int _u, int _v, int _w ){ // khoi tao gia tri cho canh
        u = _u;
        v = _v;
        w = _w;
    }
};
int n, m;
vector < Edge > adj; // ADJ BAT DAU TRUY CAP TU CHI SO 0 
vector < int > parent( 1001, 0 ); // mang luu dai dien cua cac dinh trong thao tac find, union
vector < int > size( 1001, 0 ); //  mang luu kich thuoc cua tap hop 
void inp(){ // thao tac doc du lieu tu file 
   ifstream infile;
   infile.open("connection.txt");
   if ( infile.is_open() ){
       infile >> n >> m;
       int x, y ,z;
       for ( int i = 1; i <= m ; ++i ){
           infile >> x >> y >> z;
           Edge temp( x, y ,z );
           adj.push_back( temp );
       }
   }
   else cout << " ko mo duoc file ";
   infile.close();
}
void make_set ( int n ){ // khoi tao cac tap hop
    for( int i = 1; i <= n ; ++i ){
        parent[ i ] = i;
        size[ i ] = 1;
    }
}
int find( int u ){ // thao tac tim dai dien cua dinh u
    if( u == parent[ u ] ) return u;
    return parent[ u ] = find( parent[ u ] );
}
void Union( int u, int v ){ // thao tac hop hai tap hop
    int a = find( u );
    int b = find( v );
    if ( a != b ){ // khi a va b ko cung dai dien ( tuc la giao nhau = rong ) ta thuc hien hop chung
        if ( size[ a ] > size[ b ] ) swap( a, b ); // kiem tra de tim ra cach hop toi uu, tap be se thay doi 
        parent[ a ] = b;
        size[ b ] += size[ a ];
    }
}

void kruskal(){
    vector < Edge > mst; // mang luu cac canh cua cay khung MST
    int totalw = 0;
    sort( adj.begin() , adj.end(), []( Edge &a, Edge &b ){ // sap xep lai danh sach canh theo thu tu tang dan ve trong so
        return a.w < b.w;
    });
    while( mst.size() != n - 1 && !adj.empty() ){ // khi da tim du n-1 canh cua cay khung dung lai, hoac khi ta da duyet het danh sach canh
        Edge temp = adj[ 0 ]; // lay ta canh co w min
        adj.erase( adj.begin() ); // xoa canh do khoi danh sach canh
        if ( find( temp.u ) != find( temp.v ) ){ // kiem tra xem canh vua lay ra co tao thanh chu trinh hay ko 
            Union( temp.u , temp.v ); // hop 2 tap hop 
            mst.push_back( temp ); // them canh vao mst
            totalw += temp.w; // tang tong w len 
        }
    }
    // thao tac ghi du lieu ra file 
    ofstream outfile;
    outfile.open("connection.out");
    if( outfile.is_open() ){
        if ( mst.size() != n - 1 ) outfile << " Do thi ko lien thong " << endl;
        else {
            outfile << totalw << endl;
            for ( auto x : mst ) outfile << x.u <<  " " << x.v << " " << x.w << endl;
        }
    }
    else cout << " ko mo duoc file "<< endl;
    outfile.close();
}

int main(){
    inp();
    make_set( n );
    kruskal();
    return 0;
}