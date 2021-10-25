#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
    string add(string s1, string s2){
    	string ans = "";
    	int size1 = s1.size(), size2 = s2.size();
    	if(size1 < size2) for(int i = size1+1 ; i <= size2; i++) s1.insert(s1.begin(), '0');
    	if(size1 > size2) for(int i = size2+1 ; i <= size1; i++) s2.insert(s2.begin(), '0');
    	// cout << s1 << " "<< s2;    	
    	int Msize = max(size2, size1);
    	int index = Msize-1; 
    	// cout << index ;
    	int sign = 0;
    	while(index >= 0){
			int curbit;
			int bit1 = (int)(s1[index] - '0');
			int bit2 = (int)(s2[index] - '0');
			// cout << bit1 << " " << bit2;
			curbit = bit2 + bit1 + sign;
			if(curbit >= 10){
			 	curbit = curbit % 10; 
			 	sign = 1;
			}else{
				sign = 0;
			}
			ans.insert(ans.begin(), (char)(curbit+'0'));
			// cout << ans << endl;
			index--;
    	}
    	if(sign == 1) ans.insert(ans.begin(), '1');
    	return ans;
    }
    string slove(string Sstr, string Lstr){
    	string ans = "";
    	int s1 =Sstr.size();
    	string ss[11];
    	ss[1] = Lstr;
    	for(int i = 2 ; i<=10 ; i++) ss[i] = add(ss[i-1], Lstr);
    	for(int i = s1-1; i >= 0; i--){
    		string mowei = "";
    		int j = s1-i-1, curbit = (int)(Sstr[i] - '0');
    		// cout << curbit << endl;
    		// cout << j << endl;
    		while(j--) mowei.push_back('0');
    		// cout << temp << endl;
    		ans = add(ans,  ss[curbit] + mowei);
    		// cout << ans << " " << endl;
    	}
    	return ans;
    }
    string multiply(string num1, string num2) {
    	if(num1 == "0" || num2 == "0") return "0";
    	if(num1.size() > num2.size()) return slove(num2, num1);
    	else return slove(num1, num2);
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.add("0", "0");
	/* code */


    return 0;
}