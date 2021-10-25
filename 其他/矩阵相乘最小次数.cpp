#include <iostream>
#include <climits>
#include <cstdio>
#include<bits/stdc++.h>
using namespace std;
int size;//定义矩阵的个数
int main(){
	cin >> size;
	int a[size + 2]; //定义Ai矩阵的行数
	for(int i = 1; i <= size + 1; i++){
		cin >> a[i];
	}
	int m[size + 1][size + 1];//这里我们定义数组m表示 Ai * .... * Aj的最小相乘次数；
	fill(m[0],m[0]+(size+1)*(size+1),INT_MAX);
	for(int i = 1; i <= size; i++){
		m[i][i] = 0;
	}
	for(int l = 1; l < size; l++){
		for(int i = 1; i <= size - l; i++){
			int j = i + l;
			for(int k = i; k < j; k++){
				int min = m[i][k] + m[k+1][j] + a[i] * a[k+1] * a[j+1];
				if(min < m[i][j]){
					m[i][j] = min;
				}
			}
		}
	}
	cout << m[1][size];
	return m[1][size];
}