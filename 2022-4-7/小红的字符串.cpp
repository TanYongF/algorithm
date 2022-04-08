#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[1000][1000];
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @param k int整型 
     * @return int整型
     */
    void init(){
        int mod = 1e6;
 		memset(c, 0, sizeof(c));
 		c[1][1] = 1;
 		for(int i = 0; i < 1000; i++) c[i][0] = 1;
        for(int i = 1; i < 1000; i++){
            for(int j = 1; j <= i; j++){
               	c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
            }
        }
    }
    int numsOfStrings(int n, int k) {
        ll ans = 0;
        int mod = 1e6;
        init();
        if(k == 1) return 26;
        for(int i = 0; i < k; i++){
            if(i == 0) ans = 26;
            else ans = ans * 25 % mod;
        }
        int last = n - 2 * k;
        //可能有些问题.....
        if(last != 0) ans = ans * c[last+k-1][k-1] % mod;
        else return ans;
    }
};
int main(){
    Solution s = Solution();
 
    cout << s.numsOfStrings(6,2);
    // s.minMax();
}