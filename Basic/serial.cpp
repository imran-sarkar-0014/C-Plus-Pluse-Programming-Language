#include <iostream>

int main()
{
    int limit;
    std::cout << "Enter limit : ";
    std::cin >> limit;

    for (int i = 0; i < limit; i++)
    {
        std::cout << i << ' ';
    }

    std::cout << std::endl;
    system("pause");
    return 0;
}