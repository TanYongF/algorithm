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

class Solution {
public:

	bool flag = true;
    bool verifyPostorder(vector<int>& postorder) {
    	check(0, postorder.size()-1,postorder);
    	return flag;
    }
    void check(int start, int end, vector<int> &postorder){
    	cout << start << " " << end << endl;
		int i  = 0, j;
		if(start >= end) return;
    	int mid_num = postorder[end];
    	
    	for(i = end-1 ; i >= 0 && postorder[i] > mid_num && flag; i--);
    	check(i+1, end - 1, postorder);
    	for(j = start; j > 0 && j <= i && flag; j++) 
    		if(postorder[j] > mid_num){
    			// cout << start << " " << end << " " << i <<" "
    			// <<  j <<  " " << mid_num <<  endl;
	    		flag = false;
	    		return;
    		}
    	check(start, i, postorder);
    }

};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> test= {5, 4, 3, 2, 1};
	cout << s.verifyPostorder(test);
	/* code */


    return 0;
}