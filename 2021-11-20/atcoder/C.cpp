#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e5+10;
int K , N;
int p[MAXN];
int main(int argc, char * argv[]){
	cin >> N >> K;
	vector<int> vs;
	for(int i = 0; i < N; i++){
		int scores = 0, s1, s2, s3;
		scanf("%d %d %d", &s1, &s2, &s3);
		scores = s1 + s2 + s3;
		p[i]= scores;
		vs.push_back(scores);
		// minn.insert(scores);
	}
	sort(vs.begin(), vs.end(), greater<int>());
	for(int i = 0; i < N; i++){
		cout << ((p[i] + 300 >= vs[K-1]) ? "Yes" : "No") << endl;
	}
    return 0;
}