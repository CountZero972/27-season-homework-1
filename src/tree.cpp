#include <iostream>
using namespace std;

void buildTestTree(int *tree, int n){
   int data[7] = {1,3,4,7,8,-1,-1};
   for(int i=0;i<n ; i++){
      tree[i] = data[i];
   }
}
//前序
void preorderTraversal(const int*tree, int n, int i){
   if(i>=n || tree[i]==-1){
    return;
   }
    cout << tree[i] << " ";
    preorderTraversal(tree, n, 2*i+1);
    preorderTraversal(tree, n, 2*i+2);
}
//中序
void inorderTraversal(const int*tree, int n, int i){
   if(i>=n || tree[i]==-1){
    return;
   }
    inorderTraversal(tree, n, 2*i+1);
    cout << tree[i] << " ";
    inorderTraversal(tree, n, 2*i+2);
}
//后序
void postorderTraversal(const int*tree, int n, int i){
   if(i>=n || tree[i]==-1){
    return;
   }
    postorderTraversal(tree, n, 2*i+1);
    postorderTraversal(tree, n, 2*i+2);
    cout << tree[i] << " ";
}
int main(){
   int n = 7;
   int tree[7];
   buildTestTree(tree, n);
   preorderTraversal(tree, n, 0);
   cout << endl;
   inorderTraversal(tree, n, 0);
   cout << endl;
   postorderTraversal(tree, n, 0);
   cout << endl;
   return 0;
}
