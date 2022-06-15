#include <iostream>
#include <string>
#include <cstdio>

int main()
{
    int a = 10;
    char c = 'a';
    double d = 12.32;
    long ll = 4345;
    float f = 3.1416;

    std::cout << " size of int : " << sizeof(a) << std::endl;
    std::cout << " size of char : " << sizeof(c) << std::endl;
    std::cout << " size of douoble : " << sizeof(d) << std::endl;
    std::cout << " size of long : " << sizeof(ll) << std::endl;
    std::cout << " size of float : " << sizeof(f) << std::endl;

    system("pause");
    return 0;
}
