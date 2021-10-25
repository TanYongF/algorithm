#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
int T, N, M;
const int MaxN = 2001, MaxM = 2001;
int m[MaxN][MaxM];
int s[MaxN][MaxM];
int res = 0;
std::stack<int> st;
int main(){
	cin >> T;
	while(T--){
		res = 0;
		st = stack<int>();
		cin >> N;
		cin >> M;
		//预处理
		for(unsigned i = 0; i < MaxN; ++i) {
			memset(s[i], 0, sizeof(s[i]));
			memset(m[i], 0, sizeof(m[i]));
		}
		for (int i = 0; i < N; ++i){
			for (int j = 1; j <= M; ++j){
				// cin >> m[i][j];
				scanf("%d", &m[i][j]);
				if(i == 0){
					s[i][j] = 1;
				}else{
					if(m[i][j] >= m[i-1][j]){
						s[i][j] = s[i-1][j] + 1;
					}else{
						s[i][j] = 1;
					}
				}
			}
		}

		//计算
		for(unsigned i = 0; i < N; ++i) {
			st = stack<int>();
			int area = 0;
			//最后一个为0，相当于增加一个哨兵
			for(unsigned j = 0; j <= M+1; ++j) {
				while(!st.empty() && s[i][j] < s[i][st.top()]){
					int pop_index = st.top();
					st.pop();
					int pre_index = st.top();
					area = (j - pre_index - 1) *  s[i][pop_index];
					// cout << " ----------" << area << endl;
					res = max(res, area);
				}
				st.push(j);	
			}
		}
		cout << res << endl;
	}
	return 0;
}