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

const int MAXN = 1e5+10;
int prime[MAXN+1];
void getPrime(){
	memset(prime, 0, sizeof(prime));
	for(int i = 2; i <= MAXN; i++){
		if(!prime[i]) prime[++prime[0]] = i;
		for(int j = 1; j <= prime[0] and prime[j] <= MAXN /i; j++){
			prime[prime[j]*i] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
class Solution {
public:
    int getNumber(vector<int>& a) {
    	cout << "牛成本" <<endl;
    	getPrime();
    	// cout << 1;
    	unordered_set<int> st;
    	for(int i = 1; i <= prime[0]; i++) st.insert(prime[i]);
    	// cout << st.size() << " " << prime[0];  
    	vector<int> old = a, neww;
    	while(neww.size() != 1){
    		neww.clear();
    		for(int i = 1; i <= old.size(); i++){
    			if(st.count(i)){
    				neww.push_back(old[i-1]);
    			}
    		}
    		old = neww;
    	}
    	cout << neww[0];
        return neww[0];
    }
};
int main(int argc, char * argv[]){
	vector<int> a  = {1,2,3,4};
	Solution s = Solution();
	s.getNumber(a);	/* code */


    return 0;
}