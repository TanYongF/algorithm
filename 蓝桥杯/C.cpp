#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+10;
int mod = 1000000007;
// int ma[MAXN], mb[MAXN], mm[MAXN];
vector<int> ma, mb;
int mm[MAXN];
int main(){
	int N, numa, numb;
	ll ra = 0, rb =0, temp;
	cin >> N >> numa;
	for(int i = 0; i < numa; i++){
		cin >> temp;
		ma.push_back(temp);
	}
	cin >> numb;
	for(int i= 0; i < numb; i++){
		cin >> temp;
		mb.push_back(temp);
	}
	reverse(ma.begin(), ma.end());
	reverse(ma.begin(), ma.end());

	int k = 0;
	for(int i = 0; i < max(numa, numb); i++){
		if(i < numa) mm[i] = max(2, ma[i] + 1);
		if(i < numb) mm[i] = max(mb[i]+1, mm[i]);
		mm[k++] = min(N, mm[i]);
	}

	reverse(ma.begin(), ma.end());
	reverse(mb.begin(), mb.end());
	ra = ma[0], rb = mb[0];	
	for(int i = numa-1; i >= 0; i--){
		ra = (ra * mm[(numa - i  - 1)] % mod + ma[i]) % mod; 
	}
	for(int i = numb-1; i >= 0; i--){
		rb = (rb * mm[(numb - i  - 1)] % mod + mb[i]) % mod; 
	}
	cout << (ra - rb)% mod << endl;
	return 0;
}