#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int test2[5]; //全局
int *test1 = new int[5]; //堆

int main(int argc, char * argv[]){

    system("chcp 65001");

    int *test1 = new int[5](); //堆
    int test3[5];//栈

    cout << "堆区："; for(int i = 0; i < 5; i++)  cout << test1[i] << " ";
    cout << endl;
    cout << "栈区："; for(int i = 0; i < 5; i++)  cout << test3[i] << " " ;
    cout << endl;
    cout << "全局："; for(int i = 0; i < 5; i++)  cout << test2[i] << " " ;
    return 0;
}