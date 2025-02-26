/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
   int n,dem=0;
   cin>>n;
   int arr[n];
   for (int i=0;i<n;i++) cin>>arr[i];
   for (int i=0;i<n-1;i++) {
       for (int k=i+1;k<n;k++){
           if (arr[i]==arr[k]) dem++;
   }
   }
cout<<dem;
    return 0;
}