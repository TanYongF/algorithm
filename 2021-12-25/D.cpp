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

class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long long last = 1, two = 0, five = 0, D;
        bool flag = false;
        for(int i = left; i <= right; i++){
            int j = i;
            for(; j % 2 == 0; j /= 2) two++;
            for(; j % 5 == 0; j /= 5) five++;
        }
        D = two = five = min(two, five);
        // cout << two << five << endl;
        long double first = 1;
        for(int i = left; i <= right; i++){
            for(last *= i; last % 2 == 0 and two-- > 0; last /= 2);
            for(; last % 5 == 0 and five-- > 0; last /= 5);
            if(last > 10000000000L){
                flag = true;
                last %= 10000000000L;
            } 
            for(first *= i; first > 100000; first /= 10){}
        }

        // cout << last << endl;
        string lstr = to_string(last);
        string flstr = lstr;
        string tem = to_string(last % 100000);
        if(tem.size() < 5) flstr = string(5 - tem.size(), '0') + tem;
        else flstr = tem;
        // cout << lstr << endl;;
        // cout << first << endl;
        if(flag) return to_string((int)first) + "..." + flstr + "e" + to_string(D) ;
        else return lstr+ "e" + to_string(D);
    }
};


int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.abbreviateProduct(2,11) << endl;;
    ll ans = 1;
    for(int i = 2; i <= 11; i++) ans *= i;
        cout << ans << endl;;
	/* code */


    return 0;
}