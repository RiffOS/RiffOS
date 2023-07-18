#include <iostream>
#include "Math.h"

int main()
{
    int a, b;

    std::cout << "Enter the value of a and b: ";
    std::cin >> a >> b;
    std::cout << "\n" << add(a, b) << std::endl;
    std::cout << subr(a, b) << std::endl;
    std::cout << multp(a, b) << std::endl;
    std::cout << divn(a, b) << std::endl;
    return 0;
}
