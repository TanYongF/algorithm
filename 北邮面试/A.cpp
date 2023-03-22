#include<bits/stdc++.h>
using namespace std;

// 1 --> "01"
string format(int num){
	if(num <= 9) return "0" + to_string(num);
	else return to_string(num);
}
int main(){
	// system("chcp 65003");
	int T;
	cin >> T;
	unordered_map<int,int> mp;
	int id, age;
	string name, sex;
	vector<int> ids, ages;
	vector<string> names, sexs;
	int idx = 0;
	while(T--){
		cin >> id >> name >> sex >> age;
		ids.push_back(id);
		names.push_back(name); 
		sexs.push_back(sex);
		ages.push_back(age);
		mp[id] = ids.size() - 1;
	}

	//query
	cin >> T;
	while(T--){
		cin >> id;
		idx = mp[id];
		// printf("%d %s %s %d\n", ids[idx], names[idx], sexs[idx], ages[idx]);
		cout << format(ids[idx]) << " " << names[idx]  << " " << sexs[idx]  << "  " << format(ages[idx]) << endl; 
	}
	return 0;
}