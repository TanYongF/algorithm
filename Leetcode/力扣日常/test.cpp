#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
int main (){
  vector<int> st;
  st.push_back(1);
  st.push_back(2);
  // for(int i = 0; 
  auto it = upper_bound(st.begin(), st.end(), 1);
  // cout << distance();
  it--;

  return 0;
}