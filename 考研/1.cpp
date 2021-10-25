#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;
int main(){
    unsigned int num;
    while(scanf("%d", &num) != EOF){
        string str = bitset<60>(num).to_string();
        str.erase(0, str.find_first_not_of('0')); //"10000000"]
        cout << str << endl;
    }
    return 0;

}