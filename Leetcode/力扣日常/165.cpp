//https://leetcode-cn.com/problems/compare-version-numbers/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

vector<string> splitString(const string& str,const string& pattern)
{
	vector<string> result;
	//string::size_type型別，left：左邊界位置  right：右邊界位置 
	string::size_type left, right;
	right = str.find(pattern);
	left = 0;
	
	while(right != string::npos)
  	{
  		//以免字串首部就是分割依據，壓入長度為0的字串 
  		if(right-left)
  		{
  			//壓入起始位置為left，長度為（right-left）的字串 
    		result.push_back(str.substr(left, right-left)); 
  		}	
    	left = right + pattern.size();   //右邊界右移分割依據的長度，作為新的左邊界 
    	right = str.find(pattern, left);   //從left這個位置開始find 
  	}
  	
  	//退出迴圈時，左邊界不是最後一個元素 
  	if(left != str.length())
  	{
  		result.push_back(str.substr(left));
  	}
  	return result;    	
}

//所有修订号不能存放则32位整数中
class Solution {
public:
	int check(string s){
		for(auto c : s)
			if(c!='0') return false;
		return true;
	}
	int cmp(string version1,string version2){
		int idx1= 0, idx2 = 0, idy1 = version1.length()-1, idy2 = version2.length()-1;
		while(version1[idx1]=='0') idx1++;
		while(version2[idx2]=='0') idx2++;
		if(idy1-idx1+1 !=  idy2-idx2+1) return idy1-idx1 > idy2-idx2 ? 1 : -1;
		while(idx1 <= idy1){
			if(version1[idx1] > version2[idx2]) return 1;
			else if(version1[idx1] < version2[idx2]) return -1;
			idx1++, idx2++;
		}
		return 0;
	}
    int compareVersion(string version1, string version2) {
    	vector<string> v1 = splitString(version1, ".");
    	vector<string> v2 = splitString(version2, ".");
    	int i , len1 = v1.size() , len2 = v2.size();;
    	for(i = 0; i < min(v1.size(), v2.size()); i++)
    		if(cmp(v1[i], v2[i]) == 1) return 1;
    		else if(cmp(v1[i], v2[i])==-1) return -1;
    	if(len1 > len2) for(; i < len1; i++) if(!check(v1[i])) return 1;
    	else if(len1 < len2) for(; i < len2; i++) if(!check(v2[i])) return -1;
    	return 0;
    }
};

//可以存放进32位
class Solution {
public:
    int compareVersion(string version1, string version2) {
    	int i = 0 , j = 0, m = version1.length(), n = version2.length();
    	while(i < m || j < n){
    		int x = 0, y = 0;
    		for(; i < m && version1[i] != '.'; i++) x += x * 10 + (version1[i] - '0');
    		i++;
    		for(; j < n && version2[j] != '.'; j++) y += y * 10 + (version2[j] - '0');
    		j++;
    		if(x != y) return x > y ? 1 : -1;
    	}
    	return 0;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	// cout << s.compareVersion("124.11", "111.11");
	// cout << s.cmp("11", "111");
	// cout << s.cmp("001", "001");
	// cout << s.cmp("1", "2");
	// cout << s.compareVersion("0.0000","0");
	cout << s.compareVersion("1", "1.0.1");
	/* code */


    return 0;
}