#include <iostream>

int main()
{
    bool arr[10];
    for (int i = 0; i < 10; i++)
        arr[i] = false;

    std::string ss = "8347266382380";
    for (char c : ss)
    {
        int digit = c - '0';
        if (!(digit % 2))
        {
            arr[digit] = true;
        }
    }

    for (int i = 0; i < 9; i += 2)
    {
        if (arr[i])
            std::cout << i;
    }

    std::cout << std::endl;
    system("pause");
    return 0;
}