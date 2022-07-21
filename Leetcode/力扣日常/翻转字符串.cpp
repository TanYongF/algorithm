#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	int N, K;
	string s;
	int len = s.size();
	cin >> N >> K;
	cin >> s;
	int invTimes = N - K + 1;
	if(invTimes & 1){
		string prefix = s.substr(N - K); 
		string suffix = s.substr(0, N - K);
		reverse(suffix.begin(), suffix.end());
		cout << prefix << suffix << endl;	
	}else{
		int start = 0, cur = 0;
		string suffix = s.substr(0, N - invTimes);
		string prefix = s.substr(N - invTimes);
		cout << prefix << suffix << endl;

	}
    return 0;
}