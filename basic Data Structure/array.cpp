#include <iostream>

int main()
{

    int my_arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    for (int i = 0; i < 11; i++)
    {
        std::cout << my_arr[i] * 2 << ' ';
    }

    std::cout << std::endl;
    system("pause");
    return 0;
}