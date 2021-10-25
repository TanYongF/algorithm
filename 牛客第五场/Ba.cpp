#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

double w[100005];
double ans = 0, C, sum;
int n;
int main(int argc, char * argv[]){
	cin >> n >> C;
	for(unsigned i = 1; i <= n; ++i) {
		scanf("%lf", &w[i]);
		sum += w[i];
	}
	sort(w+1, w + 1+ n);
	for(unsigned i = 1; i <= n; ++i) {
		ans = ans / 2 + w[i];
	}
	printf("%.12lf\n", sum - max(ans - C , 0.0));
	// cout << sum - max() << endl;

}
