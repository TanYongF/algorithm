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
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int len = hand.size();
        if(len % groupSize == 0) return false;
        map<int,int> mp;
        for(auto it : hand) mp[it]++;
        int size = len / groupSize;
        while(size--){
            auto cur = mp.begin()->first;
            for(int i = 0; i < groupSize; i++){
                if(mp.find(i + cur) == mp.end()) return false;
                else{
                    mp[i+cur]--;
                    // if(mp[i+cur] == 0) mp.erase(mp.begin() + i);
                }
            }
        }
        return true;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	set<int, greater<int>> st;
	st.erase(st.rbegin());
	st.insert(1);
	st.insert(2);
	cout << *st.begin() ;
	cout << pq.top();

	/* code */


    return 0;
}