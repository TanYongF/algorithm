#include <iostream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
int main()
{
    // const long double pi = std::acos(-1.L);
    std::cout << "default precision (6): " << std::fixed  << 3333.1111111111111 << '\n'
              << "std::setprecision(10): " << std::setprecision(10) << 32321.1111111111 << '\n'
              << "max precision:         "
              << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
              ;
}