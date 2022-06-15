#include <iostream>

#define LIMITE 100
#define AREA(a, b) (a * b)

void printZeroToLimit()
{
    for (int i = 0; i < LIMITE; i++)
    {
        std::cout << "i = " << i << " ";

        if (!(i % 5))
            std::cout << std::endl;
    }
}

void printArea()
{
    std::cout << "Area of 10 and 5 = " << AREA(10, 5) << std::endl;
}

class Mango
{
public:
    Mango()
    {
        std::cout << "Mongo's constructor is called." << std::endl;
    }
    void get()
    {
        std::cout << "I send 30kg mango to you." << std::endl;
    }
    void put(int n)
    {
        std::cout << "I have received " << n << "kg mango from you " << std::endl;
    }
};

int main()
{
    printZeroToLimit();
    printArea();
    std::cout << "hello" << std::endl;

    Mango m;
    m.get();
    m.put(1000);

    system("pause");
    return 0;
}