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
bool cmp(string num1, string num2){
	if(num1.length()!=num2.length()) return num1.length() > num2.length();
	else{
		for(int i = 0; i < num1.length(); i++){
			if(num1[i] != num2[i]) return num1[i] > num2[i];
		}
	}
	return false;
}
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
    	sort(nums.begin(), nums.end(),cmp);
    	cout << nums.size();
    	// cout << nums[nums.size()-k];
    	return nums[k-1];
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<string> v;
	// v.push_back("2");
	// v.push_back("21");
	// v.push_back("12");
	// v.push_back("1");
	// v.push_back("0");
	v.push_back("0");
	v.push_back("110");
	v.push_back("10");
	v.push_back("0");
	v.push_back("110");
	v.push_back("0");
	v.push_back("0");
	v.push_back("0");

	// sort(v.begin(), v.end(), cmp);
	// for(auto t : v) cout << t << " ";
	cout << s.kthLargestNumber(v,3);
	// s.kthLargestNumber(v, 10);
	/* code */


    return 0;
}