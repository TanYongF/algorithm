#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int mod = 1e9+7;
	unordered_map<int,long long> nmp, omp;
	for(auto &ch : s){
		nmp = omp;
		for(auto it : omp){
       
			int carry = (it.first + ch - '0') % 9;
			nmp[carry] = (it.second + nmp[carry]) % mod;
		}
		nmp[(ch-'0')%9]++;
		omp = nmp;
     }
	cout << nmp[0] % mod;
	return 0;
}