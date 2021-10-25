#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
int T;
int n,q;
int m;

string s;
vector<pair<int,int>> v;
class Node{
    int val;
    int prem;
};
Node d[100000];
int sixtoten(string s){
    return stoi(s,nullptr,16);
};
stack<int> stack;
queue<int> queue;


int cal(int a, int b, int m){
    if(m == 1) return b;
    int a1 = (a%256);
    int b1 = (b%256);
    a /= 256;
    b /= 256;
    int a2 = (a%256);
    int b2 = (b%256);
    a /= 256;
    b /= 256;
    int a3 = (a);
    int b3 = (b);
    a1 = (a1 + b1) > 255 ? 255 : (a1+b1);
    a2 = (a1 + b1) > 255 ? 255 : (a2+b2);
    a3 = (a1 + b1) > 255 ? 255 : (a3+b3);
    return (((a3*256)+a2)*256)*256;  
}



// void build(int s, int t, int p) {
//   // 对 [s,t] 区间建立线段树,当前根的编号为 p
//   if (s == t) {
//     d[p] = a[s];
//     return;
//   }
//   int m = s + ((t - s) >> 1);
//   // 移位运算符的优先级小于加减法，所以加上括号
//   // 如果写成 (s + t) >> 1 可能会时间超限
//   build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
//   // 递归对左右区间建树
//   d[p] = d[p * 2] + d[(p * 2) + 1];
// }

int main(int argc, char * argv[]){
    // cout << sixtoten("1A");
    cin >> T;
    while(T--){
        cin >> n >> q;
        for (int i = 0; i < n; i++){
            cin >> m >> s;
            int num = sixtoten(s);
            pair<int,int > p(m,num);
            v.push_back(p);
        }

        



        
    }
	/* code */


    return 0;
}