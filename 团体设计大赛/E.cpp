#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define ms(s, val) memset(a, val, sizeof(a))
int main(){
	// int a, b, m , n;
	int temp, n;
	int a[6][7];
	ms(a, 0);
	for(int i = 0; i < 6; i++){
		cin >> temp;
		a[i][temp] = 1;
	} 
	std::vector<int> v;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			for(int k = 6; k >= 1; k--){
				if(a[j][k] == 0){	
				   	if(i == n-1) v.push_back(k);
					 a[j][k] = 1;
					 break;
				}
			}
		}
	}
	string ans = "";
	for(auto it : v) ans = ans + to_string(it) + " ";
	cout << ans;
	return 0;
}