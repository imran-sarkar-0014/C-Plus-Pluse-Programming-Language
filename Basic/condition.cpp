
#include <iostream>

int main()
{
    int n = 10;

    if (n < 10)
    {
        std::cout << "n is less then 10" << std::endl;
    }
    else if (n == 10)
    {
        std::cout << "n is equal 10" << std::endl;
    }
    else
    {
        std::cout << "n is grather then 10" << std::endl;
    }

    system("pause");
    return 0;
}