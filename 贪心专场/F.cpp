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
// string s;





// 通过字符串hash方法来多次求回文串，只需要O(n+q)时间复杂度，暴力解法为O(n*q) //
const unsigned long long int base = 2333; //base表示进制，用一个大质数作为进制减少hash碰撞
const int N = 1010;
int Hash[N], Hash_reverse[N], power[N];
char s[N];
int main()
{
    int q, l, r;
    scanf("%s", s + 1);
    int slen = strlen(s + 1);

    // 初始化hash和逆hash数组， 以及表示base进制位数的power数组
    // 数组从1开始存储字符串和哈希值，Hash[0]为功能位，方便计算
    Hash[0] = 0;
    Hash_reverse[0] = 0;
    power[0] = 1;
    // power存放的是进制位数，方便计算。以十进制为例power[3]即为10^3.
    // 此题我们选的进制是质数2333,power[3]即为2333^3
    for (int i = 1; i < slen + 1; i++)
    {
        power[i] = power[i - 1] * base;
    }
    // 计算字符串的hash值，时间复杂度只需O(n)
    for (int i = 1; i < slen + 1; i++)
    {
        Hash[i] = Hash[i - 1] * base + s[i] - 'a' + 1; // 加1是为了让hash值不为0，如果前面某位hash值为0，将会影响后面hash值的计算

        Hash_reverse[i] = Hash_reverse[i - 1] * base + s[slen - i + 1] - 'a' + 1;
    }
    l = 1;
    r = strlen(s+1);
    if ((Hash[r] - Hash[l - 1] * power[r - l + 1]) == (Hash_reverse[slen - l + 1] - Hash_reverse[slen - r] * power[r - l + 1])){
    	cout << "First";
    	return 0;
    }else{
		if(strlen(s+1) % 2 == 0){
			cout << "Second";
		}else{
			cout << "First";
		}
    }
    // 下面通过哈希值来判断回文串，每次判断只需要O(1)时间复杂度
    return 0;
}

