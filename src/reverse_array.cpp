#include <iostream>
using namespace std;

void reverseArray(int *arr , int n){
   if(n==0){
     return;
   }
   if(n>0){
     int* left = arr;
     int* right = arr+n-1;
     while(left < right ){   // 确保交换到中间时停止, 避免重复交换
        int temp = *(left);
        *(left) = *(right);
        *(right) = temp;
        left++;
        right--;
     }
   }
}
int main(){
   int n=0;
   cin >> n;
   int arr[100];
   for(int i=0 ; i<n ; i++){
     cin >> *(arr+i);
   }
   reverseArray(arr , n); 
   for(int i=0; i<n; i++){
      cout << *(arr+i);
      if(i<n-1){
        cout << " ";
      }
   }
   return 0;
}