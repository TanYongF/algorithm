#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define ms(s, val) memset(a, val, sizeof(a))

int main(){
	int n;
	string from, to;
	cin >> n;
	string time,temp;
	std::vector<string> times;
	for(int i = 1; i <= 3 * n; i++){
		cin >> temp;;
		time += temp + " ";
		if(i % 3 == 0){
			// cout << time << endl;
			time.pop_back();
			times.push_back(time);
			time = "";
			continue;
		} 
	}
	times.push_back("23:59:59 - 23:59:59");
	sort(times.begin(), times.end());
	cout << endl;
	// for(auto time : times) cout << time << endl;
	int prea = 0, preb = 0, prec = 0;
	for(int i = 0; i < n+1;  i++){
		// cout << starta << startb << startc << endl;
		string start = times[i].substr(0, 8);
		string endti = times[i].substr(11);
		int starta = stoi(start.substr(0, 2)), startb =  stoi(start.substr(3, 2)), startc = stoi(start.substr(6, 2));
		int enda = stoi(endti.substr(0, 2)), endb =  stoi(endti.substr(3, 2)), endc = stoi(endti.substr(6, 2));
		if(not(prea == starta and preb == startb and prec == startc)){
			printf("%.2d:%.2d:%.2d - %.2d:%.2d:%.2d\n", prea, preb, prec, starta, startb, startc);
		}
		prea = enda, preb = endb, prec = endc;
	}

	return 0;
}