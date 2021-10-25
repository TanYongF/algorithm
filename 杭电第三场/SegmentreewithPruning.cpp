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
int k;
int num1 = 0; 
int num2= 0;
struct Node{
    Node * lchild;
    Node * rchild;
};
Node* build1(long long l, long long r) {
    Node* x = new(Node);
    num1++;
    if (l == r) return x;
    long long mid = (l + r) / 2;
    x -> lchild = build1(l, mid);
    x -> rchild = build1(mid + 1, r);
    return x;
}

Node* build2(long long l, long long r) {
    Node* x = new(Node);
    num2++;
    if (r - l + 1 <= k) return x;
    long long mid = (l + r) / 2;
    x -> lchild = build2(l, mid);
    x -> rchild = build2(mid + 1, r);
    return x  ;
}
 
int main(int argc, char * argv[]){
    for (int i = 1; i <= 50; i++)
    {
        k = i;
        num1 = 0;
        num2 = 0;
        build1(1,50);
        build2(1,50);
        cout << i <<":"<< (num1+1)/2 <<" " << (num2+1)/2 << " " << num1 - num2 << endl;
    }
    
    // k = 50;
    // build(1,100000);
	/* code */
    cout << num1;
    return 0;
}