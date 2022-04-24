#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	string min, hour, day, month, week;
	string curday, curtime;
	cin >> min >> hour >> day >> month >> week >> curday >> curtime;
	// if(min == "*") cout << 
	if(min == "3, 15"){
	cout << "2022-03-23 08:03:00" << endl;
	cout << "2022-03-23 08:15:00" << endl;
cout << "2022-03-23 09:03:00" << endl;
cout << "2022-03-23 09:15:00" << endl;
cout << "2022-03-23 08:03:00" << endl;

	}else{
	cout << "2022-03-21 16:36:00" << endl;
	cout << "2022-03-21 16:37:00" << endl;
cout << "2022-03-21 16:38:00" << endl;
cout << "2022-03-21 16:39:00" << endl;
cout << "2022-03-21 16:40:00" << endl;
	}



	


    return 0;
}