#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
vector< int > topo;
void dfs( vector< vector<int> > v,vector < bool > &visited, int u ){ // thuat toan duyet dfs
    for ( int temp : v[ u ] ){
        if ( !visited[ temp ] ){
            visited[ temp ] = true;
            dfs( v, visited, temp );
        }
    }
    topo.push_back( u ); // sau khi khong the di duoc nua cung tuc la da duyet den cong viec cuoi ma ko con dieu kien => ta them vao list topo
}
int main(){
    ifstream infile;
    infile.open( "jobs.txt");
    int n, m;
    infile >> n >> m;
    vector < vector<int> > v( n + 1 ); // khoi tao danh sach canh
    vector < bool > visited( n + 1 , false ); // khoi tao mang danh dau 
    int x, y ;
    for ( int i = 0 ; i < m ; ++i ){ // nhap danh sach canh
        infile >> x >> y;
        v[ x ].push_back( y ); // do thi co huong
    }
    infile.close();
    for ( int i = 1 ; i <= n; ++i ){
        if ( !visited[ i ] ) dfs( v, visited, i ); // duyet cac dinh bang dfs
    }
    reverse( topo.begin(), topo.end() ); // dao nguoc topo
    ofstream outfile;
    outfile.open("jobs.out");
    for ( int i : topo ) outfile << i << " ";
    outfile.close();
    return 0;
}
