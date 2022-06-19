#include <iostream>
#include <map>
#include <unordered_map>

void orderMap()
{
    std::map<std::string, int> my_map = std::map<std::string, int>();
    std::pair<std::string, int>("imran", 21);
    my_map.insert(std::make_pair<std::string, int>("imran", 21));

    std::cout << "My age is :" << my_map.find("imran")->second << std::endl;
}

void unorderMap()
{
    std::unordered_map<std::string, int> my_unordered_map = std::unordered_map<std::string, int>();
    std::pair<std::string, int>("imran", 21);
    my_unordered_map.insert(std::make_pair<std::string, int>("imran", 21));

    std::cout << "My age is :" << my_unordered_map.find("imran")->second << std::endl;
}

int main()
{
    orderMap();
    unorderMap();

    system("pause");
    return 0;
}