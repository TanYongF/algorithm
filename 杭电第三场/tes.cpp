#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
	int a[100] = {0};
	int t;
	scanf("%d", &t);
	int mini=100, maxi=0;
	while (t--)
	{
		string s;
		for (int i = 0; i < 30; ++i)
		{
			getchar();
			for (int j = 0; j < 100; ++j)
			{
				char c = getchar();
				if (c == '#')
					a[j] = 1;
			}
		}
		int j = 0;
		for(unsigned i = 0; i < 100; i=j) {
			if(a[i] == 0) continue;
			for(j = i+1; j<100; ++j) {
				if(a[j] == 0){
					cout << i <<" "<< j-1 << endl;;
					break;
				}	
			}
		}
	}
	return 0;
}
