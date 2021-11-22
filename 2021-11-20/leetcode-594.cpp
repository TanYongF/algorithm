#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
    	unordered_map<int,int> mp;
    	int ans = INT_MIN;
    	for(auto num : nums) mp[num]++;
    	for(auto num : nums){
    		if(mp.find(num + 1) != mp.end()) ans = max(ans, mp[num+1] + mp[num]);
    	}
    	return ans;
    	// for(auto it = mp.begin(); mp != mp.end() - 1)
    } 
};
int main(int argc, char const *argv[])
{
	
	return 0;
}