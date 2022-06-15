#include <iostream>

void charRange()
{
    for (int i = 0; i < 255; i++)
    {
        std::cout << char(i) << ' ';
    }
    std::cout << std::endl;
}

int main()
{

    charRange();

    system("pause");
    return 0;
}