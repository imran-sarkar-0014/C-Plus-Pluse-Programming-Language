#include <iostream>
#include <string>

int repeated_string_n_count(std::string s, int n, char match)
{

    int count = 0;
    int iter_count = 0;
    while (true)
    {
        for (char c : s)
        {
            if (iter_count >= n)
                return count;
            if (c == match)
                count++;
            iter_count++;
        }
    }
}

int main()
{

    int result = repeated_string_n_count("aba", 8969600, 'a');
    std::cout << "Result is :" << result << std::endl;

    system("pause");
    return 0;
}