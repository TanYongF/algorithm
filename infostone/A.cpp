#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;


class MountainArray{
	private:
		vector<int> v;
	public:
		
		int get(int index){	
			return v[index];
		}
		int length(){
			return v.size();
		}
		MountainArray(vector<int> &v){
			this->v = v;
		}
};	
int T;
int FindInMountainArray(int target, MountainArray &arr){
	unordered_map<int, int> mp;
	int len = arr.length();
	for(int i = 0; i < len; i++){
		if(not mp.count(arr.get(i))){
			mp[arr.get(i)] = i;
		}
	}
	if(mp.count(target)) return mp[target];
	else return -1;
}
vector<int> split(string s, char tag){
	int i = 0, j = 0, len = s.size();
	vector<int> ans;
	while(j < len){
		i = j;
		while(i < len and (s[i] > '9' or s[i] < '0')) i++;
		j = i;
		while(j < len and s[j] <= '9' and s[j] >= '0')j++;
		if(j - i > 0) ans.push_back(stoi(s.substr(i, j - i)));

	}
	return ans;

}
int main(int argc, char * argv[]){
	string s;
	int nums;
	cin >> s >> nums;
	vector<int> ans = split(s, ',');

	MountainArray arr = MountainArray(ans);
	cout << FindInMountainArray(nums, arr);

    return 0;
}