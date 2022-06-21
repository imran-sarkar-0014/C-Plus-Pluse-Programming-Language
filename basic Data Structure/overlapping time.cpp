#include <iostream>
#include <vector>

#define MAX(a, b) (a > b ? a : b)

struct Time
{
    int start;
    int end;
    Time(int _start, int _end)
    {
        start = _start;
        end = _end;
    }
};

void printTimes(std::vector<Time> &times)
{
    for (Time t : times)
    {
        std::cout << "[" << t.start << ", " << t.end << "]"
                  << ", ";
    }

    std::cout << std::endl;
}

void merge_overlap(std::vector<Time> &list, Time &time)
{
    if (!list.size())
    {
        list.push_back(time);
        return;
    }

    if (time.start <= list.front().end)
    {
        list.front().end = MAX(list.front().end, time.end);
    }
    else
        list.push_back(time);
}

int main()
{
    std::vector<Time> times;
    times.push_back(Time(1, 3));
    times.push_back(Time(2, 6));
    times.push_back(Time(8, 10));
    times.push_back(Time(15, 18));

    std::vector<Time> result;

    std::cout << "input values :" << std::endl;
    printTimes(times);

    for (Time t : times)
        merge_overlap(result, t);

    std::cout << "output values :" << std::endl;
    printTimes(result);

    system("pause");
    return 0;
}