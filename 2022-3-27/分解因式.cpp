#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T,n;
vector<int> ans = {-1,1,2,4,6,16,12,64,24,36,48,1024,60,4096,192,144,120,-1,180,-1,240,576,3072,-1,360,1296,12288,900,960,-1,720,-1,840,9216,-1,5184,1260,-1,-1,-1,1680,-1,2880,-1,15360,3600,-1,-1,2520,-1,6480,-1,-1,-1,6300,-1,6720,-1,-1,-1,5040,-1,-1,14400,7560,-1,-1,-1,-1,-1,-1,-1,10080,-1,-1,-1,-1,-1,-1,-1,15120};
int main(int argc, char * argv[]){
	cin >> n;
	if(ans[n] == -1) cout << "NO SOLUTION";
	else cout << ans[n];

	


    return 0;
}

void getLock(){
	String uuid = new UUID();
	if(set nx key uuid ex 100){
		//lock sucess
		//相应逻辑
	}else{
		//以下两行再lua脚本实现
		if((get key) != uuid) continue;
		else del(key);
	}
}