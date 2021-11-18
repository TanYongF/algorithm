#include<iostream>
#include<map>
#include<climits>

#include<unordered_map>
#include<vector>
using namespace std;
typedef pair<int,int> P;
class Solution {
public:
	map<P, int> mp;
    bool isRectangleCover(vector<vector<int>>& rectangles) {
    	P MIN = {INT_MAX, INT_MAX}, MAX = {INT_MIN, INT_MIN};
    	long long area =0;
    	for(auto rectangle : rectangles){
    		P p1 = {rectangle[0],rectangle[1]};
    		P p2 = {rectangle[2],rectangle[3]};
    		P p3 = {rectangle[0],rectangle[3]};
    		P p4 = {rectangle[2],rectangle[1]};
    		mp[p1]++;
    		mp[p2]++;
    		mp[p3]++;
    		mp[p4]++;
    		MIN = min(MIN, p1);
    		MAX = max(MAX, p2);
    		area += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
    	}
    	// cout << area << endl;
    	// cout << MAX.first << " " << MAX.second << endl;
    	// cout << MIN.first << " " << MIN.second << endl;
    	if(1LL * (MAX.first - MIN.first) * (MAX.second - MIN.second) != area) return false;
    	int notEqul = 0;
    	if(mp[MAX] != 1 or mp[MIN] != 1) return false; 
		for(auto it : mp){
			if(it.second == 4 or it.second == 2) continue;
			cout << it.first.first << " " << it.first.second<< endl;
			notEqul++;
		}
		// cout << notEqul<< endl;
		return notEqul == 4;
    	return false;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> vs= 

 cout << s.isRectangleCover(vs);
	/* code */


    return 0;
}