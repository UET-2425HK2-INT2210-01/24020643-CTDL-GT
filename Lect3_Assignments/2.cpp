#include <iostream>
#include <math.h>
using namespace std;
double  value1 (int n){
    long long s=1;
    for (int i = 0; i < abs(n) ; i++) s*=2;
    if (n>0) return s;
    else return 1.0 / s;
}
// Algorithm 1
// BEGIN 
// input n
// long long value=1;
// for i=0 to abs(n) 
//     value*=2 
// end for 
// if n>0 then 
// output value 
// else 
// output 1.0/value 
// end if 
// END
//   Thuật toán 1 dùng vòng lặp với độ phức tạp O(n)
  
  
  double value2 (int n ){
      long long s = 1;
      s = s << abs(n);
      if (n > 0) return s;
      else return 1.0 / s;
  }
// Algorithm 2 
// BEGIN 
// input n
// long long s=1 
// s = s << abs(n)
// if n>0 then 
//     output s 
// else 
//     output 1.0/s 
// end if
// END
// Thuật toán 2 dùng bitwise với độ phức tạp O(1)
int main(){
    int n;
    cin>>n;
    cout<<value1( n )<< "   "<<value2(n)<<endl;
    return 0;
}