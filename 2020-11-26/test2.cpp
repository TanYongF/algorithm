#include<bits/stdc++.h>
using namespace std;

//


class solution{
public:
	vector<int> ans;
}

struct Node{
	Node *left, *right;
	int val;
	Node(){}

};
int getAns(string s){
	int len = s.size();
	int ans = 0;
	for(int k = 0; k < len; k++){
		//奇数长度
		//左右两端
		int i = k , j = k;
		while(i >= 0 and j < len){
			if(j - i + 1 > 1) ans++;
			if(s[i] == s[j]){
				 i--, j++;
			}else break;
		}
	}
	//偶数长度
	for(int k1 = 0; k1 < len - 1; k1++){
		int k2 = k1 + 1, i = k1 , j = k2;
		if(s[k2] != s[k1]) continue;
		while(i >= 0 and j < len){
			if(j - i + 1 > 1) ans++;
			if(s[i] == s[j]){
				i--, j++;
			}else break;
		}
	}
	cout << "ans: " << ans << endl;
	return ans;
}


int main(){
	string s = "AAAA";
	getAns(s);
}