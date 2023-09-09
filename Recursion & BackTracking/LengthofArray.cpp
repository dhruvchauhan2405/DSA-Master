#include <bits/stdc++.h>
using namespace std;
int lengtharray(int index , int*
 arr,int n){
    if(index>=n) return 0;
    return 1+lengtharray(index+1,arr,n);
}
int main() {
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<lengtharray(0,arr,n);
   
   return 0;
}