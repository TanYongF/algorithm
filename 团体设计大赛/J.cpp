#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define ms(s, val) memset(a, val, sizeof(a))

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	stack<int> st;
	std::vector<int> v(n);	
	for(unsigned i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int curIdx = 0;
	while(not (st.empty() and curIdx == n)){
		vector<int> cur;
		int pre = INT_MAX;
		while(not st.empty() and st.top() <= pre and cur.size() < k){
			cur.push_back(st.top());
			pre = st.top();
			st.pop();
		}

		while(curIdx < n and cur.size() < k){
			if(v[curIdx] <= pre){
				cur.push_back(v[curIdx]);
				pre = v[curIdx];
			}else if(st.size() < m){
				st.push(v[curIdx]);
			}else{
				break;
			}
			curIdx++;
		}
		for(unsigned i = 0; i < cur.size(); ++i) {
			if(i != cur.size()-1) cout << cur[i] << " ";
			else cout << cur[i];
		}
		cout << endl;
	}
	return 0;
}