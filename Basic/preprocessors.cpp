#include <iostream>

#define LIMITE 100
#define AREA(a, b) (a * b)

void printZeroToLimit()
{
    for (int i = 0; i < LIMITE; i++)
    {
        std::cout << "I = " << i << std::endl;
    }
}

void printArea()
{
    std::cout << "Area of 10 and 5 = " << AREA(10, 5) << std::endl;
}

int main()
{
    // printZeroToLimit();
    printArea();

    system("pause");
    return 0;
}