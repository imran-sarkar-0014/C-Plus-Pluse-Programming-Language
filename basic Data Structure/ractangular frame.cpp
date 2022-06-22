#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

void printStart(int n)
{
    for (int i = 0; i < n; i++)
        std::cout << "*";
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> list;
    list.push_back("    hello world");
    list.push_back("    Hello World this is text nise3");
    list.push_back("    in");
    list.push_back("    I am a crazy programmer. ");
    list.push_back("    I print the output in a frame.");

    int max_len = 0;

    for (std::string s : list)
    {
        if (max_len < s.length())
            max_len = s.length();
    }

    printStart(max_len + 2);
    for (std::string s : list)
    {
        std::cout << "*" << std::left << std::setw(max_len) << s << std::setw(max_len) << "*" << std::endl;
    }
    printStart(max_len + 2);

    system("pause");
    return 0;
}