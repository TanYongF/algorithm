#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	vector<int> vs = vector<int>(100, 2);
	

	for(auto  v : vs )
		cout << v << endl;
  return 0;
}