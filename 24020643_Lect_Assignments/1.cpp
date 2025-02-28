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
