#include <iostream>
using namespace std;

long long climbStairsIter(int n){
    if(n==0 || n==1){
          return 1;
    }
    long long pre1 = 1;
    long long pre2 = 1;
    long long current = 0; 
//用三个值即可完成运算, 每计算一次保留前两个数据并交换给后两个变量来迭代
    for(int i=2; i <= n;i++){           
      current = pre1 + pre2;
      pre2 = pre1;
      pre1 = current;
    }
      return current;
}      
long long climbStairsRecur(int n){
  if(n==0 || n==1){
      return 1;
  }
  return climbStairsRecur(n-1) + climbStairsRecur(n-2);
    
}
int main(){
   int n;
   cin >> n;
   if(n<0 || n>40){
     cout << "Invalid input" << endl;
     return 0;
   }
   long long result1 = climbStairsIter(n);
   long long result2 = climbStairsRecur(n);
   cout << result1 << endl;
   cout << result2 << endl;
   if(result1==result2){
    cout << "same" << endl;
   }
   else{
    cout << "different" << endl;
   }
   return 0;
}