#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;

vector<int> split(string &s){
	vector<int> ans;
	int i = 0, j = 0, len = s.size();
	while(j < len){
		while(i < len and s[i] == ',') i++;
		j = i;
		while(j < len and s[j] != ',') j++;
		if(i < len) ans.push_back(stoi(s.substr(i, j-i)));
		i = j;
	}
	return ans;

}

int main(int argc, char * argv[]){
	string keys;
	cin >> keys;
	int from, to;

	vector<vector<int>> nums;
	for(int i = 2,  j = 0; j < keys.size()-1; j++){
		if(keys[j] == ']'){
			string item = keys.substr(i, j -i);
			// vs.push_back(keys.substr(i , j - i));
			// cout << item << endl;
			i = j + 3;
			nums.push_back(split(item));
		} 
	}
	int len = nums.size();
	// for(auto it : nums){
	// 	for(auto ff : it) cout << ff  << " ";
	// 		cout << endl;
	// }
	cin >> from >> to;
	if(from >= to) {
		cout << "[]";
		return 0;
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	vector<int> indexs(len, 0);
	for(int i = 0; i < len; i++){
		int j = distance(nums[i].begin(), lower_bound(nums[i].begin(), nums[i].end(), from));
		indexs[i] = j;
		if(j < nums[i].size()) pq.push({nums[i][j], i});
	}
	string ans;
	while(not pq.empty()){
		auto [val, idx] = pq.top();
		pq.pop();
		if(val >= to) break;
		ans += to_string(val) + ",";
		indexs[idx]++;
		if(indexs[idx] < nums[idx].size() and nums[idx][indexs[idx]] < to){
			pq.push({nums[idx][indexs[idx]], idx});
		}
	}
	ans.pop_back();
	cout << "[" << ans << "]";
    return 0;
}