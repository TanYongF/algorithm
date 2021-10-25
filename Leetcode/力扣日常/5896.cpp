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
#include <bitset>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class StockPrice {
public:
	int curTime = INT_MIN;
	unordered_map<int,int> timePrice;
	map<int,int> priceTime;
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
    	curTime = max(curTime, timestamp);
    	int oldPrice;
    	if(timePrice.count(timestamp)){
			oldPrice = timePrice[timestamp];
			if(priceTime[price] >= 2) priceTime[oldPrice]--;
			else{
				auto it = priceTime.find(oldPrice);
				priceTime.erase(it);
			}
    	}
    	timePrice[timestamp] = price;
	 	priceTime[price]++;
    }
    
    int current() {
    	return timePrice[curTime];
    }
    
    int maximum() {
    	return  priceTime.rbegin()->first;

    }
    
    int minimum() {
    	return priceTime.begin()->first;

    }
};

int main(int argc, char * argv[]){

	// 
	map<int,int> tes;
	tes[1]= 1;
	tes[1]--;
	cout << tes[2];
	for(auto it : tes){
		cout << it.first << " " << it.second << endl;
	}
	/* code */


    return 0;
}