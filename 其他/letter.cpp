#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100001];
int getmin(int a,int b)
{if(a<b)return a;else return b;}

int main(){
	scanf("%s",s);
	int length = strlen(s);
	int preB = 0, curB = 0;
	int preL = 0, curL = 0;
	for (int i = 0; i < length; ++i)
	{
		if(s[i] <= 'Z' && s[i] >= 'A'){
			curB = preB;
			curL = getmin(preB, preL) + 1;
		}else{
			curB = preB + 1;
			curL = getmin(preB, preL);
		}
		preB = curB;
		preL = curL;
	}
	cout << getmin(preB, preL);
}