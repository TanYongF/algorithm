#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;


bool cmp(pair<double, int>& a, pair<double,int>& b){
	if(a.first == b.first) return a.second < b.second;
	else return a.first > b.first;

}
int main(int argc, char * argv[]){
	int N, M, K;
	cin >> N >> M;
	vector<int> P(N+1, 0);
	// vector<int> Q(K, 0);
	vector<vector<int>> T(N+1, vector<int>(M+1, 0));
	for(int i = 1; i <= N; i++) cin >> P[i];
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++) cin >> T[i][j];
	}
	cin >> K;
	unordered_set<int> st, maybe;
	for(int i = 0; i < K; i++){
		int temp;
		cin >> temp;
		st.insert(temp);
	}
	for(int i = 1; i <= N; i++){
		bool can = true;
		for(int j = 1; j <= M; j++){
			if(T[i][j] == 0 and st.count(j)){
				can = false;
				break;
			}
		}
		if(can) maybe.insert(i);
	}
	vector<pair<double,int>> v;
	double sum = 0;
	for(int i = 1; i <= N; i++){
		if(maybe.count(i) == 0) v.push_back({0, i});
		else{
			double item = 1.0 * P[i] / 10;
			for(int j = 1; j <= M; j++){
				if(not st.count(j)){
					item *= 1.0 * (100 - T[i][j]) / 10;
				}else{
					item *= 1.0 * T[i][j] / 10;
				}
			}
			sum += item;
			v.push_back({item, i});
		}
	}
	for(int i = 0; i < N; i++){
		v[i].first /= sum;
	}
	sort(v.begin(), v.end(), cmp);
	for(auto it : v){
		printf("%d %0.2lf\n", it.second, it.first*100.0);
	}
    return 0;	
}