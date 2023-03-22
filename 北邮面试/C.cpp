#include<bits/stdc++.h>
using namespace std;
string temp;
vector<bool> hasV;
void dfs(string s){
	if(temp.size() == s.size()){
		cout << temp << endl;
		return;
	}
	for(int i = 0; i < s.size(); i++){
		if(hasV[i])	continue;
		
		// add
		temp.push_back(s[i]);
		hasV[i] = true;
		dfs(s);
		temp.pop_back();
		hasV[i] = false;

	}
}
int main(){
	string s; 	
	cin >> s;
	int n = s.size();
	hasV = vector<bool>(n, false);
	dfs(s);
	return 0;
}