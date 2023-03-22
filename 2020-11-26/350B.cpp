#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int get(string &s){
	for(int i = 0; i < s.size(); i++) if(s[i] == '=') return i;
	return 0;
}
int cal(string &s){
	vector<long long> nums;
	int n = s.size();
	long long cur = 0LL;
	char sign = '+';
	for(int i = 0; i < n; i++){
		if(isdigit(s[i])) cur = cur * 10 + (s[i] - '0');
		if(not isdigit(s[i]) or i == n-1){
			if(sign == '+')	nums.push_back(cur);
			else nums.back() *= cur;
			if(nums.back() > 1e9) return -1;
			sign = s[i];
			cur = 0;
		}
	}
	long long ans = 0;
	for(auto &num : nums){
		ans += num;
		if(ans > 1e9) return -1;
	}
	return ans;
}

int main(int argc, char * argv[]){

	cin >> T;
	while(T--){
		string equal;	
		cin >> equal;
		int idx = get(equal);
		string left = equal.substr(0, idx), right = equal.substr(idx + 1);
		// cout << left << right << endl;
		bool can = false;
		int leftVal = cal(left), rightVal = cal(right);
		if(cal(left) == cal(right)){
			cout << "Yes" << endl;
			continue;
		}
		
		for(int i = 0; i <= (int)left.size() and not can; i++){
			for(int j = 0; j < 10; j++){
				string temp = left;
				temp.insert(i, to_string(j));
				// cerr << temp << endl;
				if(cal(temp) >= 0 and cal(temp) == rightVal){
					can = true;
					break;
				} 
			}
		}
		for(int i = 0; i <= (int)right.size() and not can; i++){
			for(int j = 0; j < 10; j++){
				string temp = right;
				temp.insert(i, to_string(j));
				// cout << temp << endl;
				if(cal(temp) >= 0 and cal(temp) == leftVal){
					can = true;
					break;
				} 
			}
		}
		
		if(can) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
    return 0;
}