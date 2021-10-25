#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
bool Place[8][8];
std::vector<int> result;
int size = 0;
bool canPlace(int index, int deepth){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(Place[i][index])		return false;
			int dec = deepth - index;
			int add = deepth + index;
			if(i-j == dec && Place[i][j]) return false;
			if(i+j == add && Place[i][j]) return false;
		}
	}
	return true;
}
void print(){
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " " ;
	}
	cout << endl;
}
void breakTrace(int deep){
	if(deep == 8){
		size++;
		print();
		return;
	}
	for(int i = 0; i < 8; i++){
		if(canPlace(i, deep)){
			Place[deep][i] = true;
			result.push_back(i);
			breakTrace(deep + 1);
			Place[deep][i] = false;
			result.pop_back();
		}
	}
	return ;
}
int main(){
	system("chcp 65001");
	breakTrace(0);
	cout << "共有" << size << "种情况" << endl;
	return 0;

}