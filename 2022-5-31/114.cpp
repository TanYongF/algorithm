#include <bits/stdc++.h>
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



class Solution {
public:
    unordered_map<char, vector<char>> edges;
    unordered_map<char, int> inDegree;
    bool valid = true;
    string order;
    string alienOrder(vector<string>& words) {
        int len = words.size();
        for(auto &word : words)	// int wordLen = words.size();
        	for(char ch : word) 
        		edges[ch] = vector<char>();

        //init the edges
        for(int i = 1; i < len; i++){
        	addEdges(words[i-1], words[i]);
        } 

		if(not valid) return "";

		queue<char> q;
		//add the node which indgree = 0 
		for(auto [ch, _] : edges){
			if(not inDegree.count(ch)) q.push(ch);
		}
		//tuopu
		while(!q.empty()){
			char top = q.front();
			q.pop();
			order.push_back(top);
			for(auto next : edges[top]){
				inDegree[next]--;
				if(inDegree[next] == 0){
					q.push(next);
				}
			}
		}
		return order.size() == edges.size() ? order : "";
      
    }
    //add edge
    void addEdges(const string &before, const string &after){
        int length1 = before.size(), length2 = after.size();
        int length = min(length1, length2);
        int index = 0;
        while (index < length) {
            char c1 = before[index], c2 = after[index];
            if (c1 != c2) {
                edges[c1].emplace_back(c2);
               	inDegree[c2]++;
                break;
            }
            index++;
        }
        // the minLen equal but before's len > end.len
        if (index == length && length1 > length2) {
            valid = false;
        }
    }

};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}