#include<bits/stdc++.h>
using namespace std;

//判断闰年
bool check(int year){
	if(year % 400 == 0) return true;
	else if(year % 4 == 0 and year % 100 != 0) return true;
	else return false;
}

// 1 --> "01"
string format(int num){
	if(num <= 9) return "0" + to_string(num);
	else return to_string(num);
}
vector<int> daysInMonth({-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}); 
int main(){
	int year, lastday;
	string ans;
	while(scanf("%d %d", &year, &lastday) != EOF){
		if(check(year)) daysInMonth[2] = 29;
		else daysInMonth[2] = 28;	
		int month = 1;
		while(lastday != 0){
			if(lastday <= daysInMonth[month]){
				ans = format(year) + "-" + format(month)  + "-" + format(lastday);
				break;
			}
			lastday -= daysInMonth[month];
			month++;
		}
		cout << ans << endl;
	}

	return 0;
}