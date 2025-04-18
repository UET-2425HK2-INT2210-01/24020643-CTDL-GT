#include <iostream> 
#include <vector>
#include <fstream>
using namespace std;
int main(){
    int m = 0, n = 0;
    ifstream infile;
    infile.open( "matrix.txt" );// thao tac mo file va lay du lieu
    if ( infile.is_open() ){ 
        infile >> m;
        infile >> n;
        vector < vector< int > > arr ( m , vector< int >( n ) );
        for ( int i = 0; i < m ;i ++ ){
            for ( int j = 0; j < n; j++ ){
                infile >> arr[ i ][ j ];
            }
        }
        infile.close();
        int prefixsum[ m + 1 ][ n+ 1 ]; // thao tac tao mang prefixsum 2 chiều
        for ( int i = 0; i < m + 1 ; i++ ) prefixsum[ i ][ 0 ] = 0;
        for ( int j = 0; j < n + 1 ; j++ ) prefixsum[ 0 ][ j ] = 0;
        for ( int i = 1; i < m + 1 ; i++ ){
            for ( int j = 1; j < n + 1; j++ ){
                prefixsum[ i ][ j ] = arr[ i -1 ][ j - 1 ] + prefixsum[ i ][ j - 1 ] + prefixsum[ i - 1 ][ j ] - prefixsum[ i - 1 ][ j - 1];
            }
        }
        int R1 = 0 ,R2 = 0 , C1 = 0, C2 = 0; // bien lưu vị trí hcn thoa mãn 
        long long summax = -10000;
        for ( int r1 = 0 ; r1 < m ; r1++ ){
            for ( int c1 = 0; c1 < n; c1++ ){
                for ( int r2 = r1 ; r2 < m ; r2++ ){
                    for ( int c2 = c1 ; c2 < n ; c2++ ){
                        // tính tổng phần tử hcn và so sánh 
                        long long sum = prefixsum[ r2 + 1 ][ c2 + 1 ] - prefixsum[ r2 + 1 ][ c1 ] - prefixsum[ r1 ][ c2 + 1 ] + prefixsum[ r1 ][ c1 ];
                        if ( summax < sum ){
                            summax = sum;
                            R1 = r1;
                            C1 = c1; 
                            R2 = r2;
                            C2 = c2;
                        }
                    }
                }
            }
        }
        ofstream outfile; // thao tac chep ket qua 
        outfile.open( "matrix_out.txt" );
        outfile << R1 + 1;
        outfile << " ";
        outfile << C1 + 1;
        outfile << " ";
        outfile << R2 + 1;
        outfile << " ";
        outfile << C2 + 1;
        outfile << " ";
        outfile << summax;
        outfile.close();
    }
    else cout << " file ko duoc mo ";
    return 0;
}