#include <iostream>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int bad = 4;
bool isBadVersion(int n)
{
    return bad == n;
}

void setBad(int n)
{
    bad = n;
}

class Solution
{

    // recursive method
    int _firstBadVersion(int left, int right)
    {

        if (isBadVersion(left))
            return left;

        int mid = (left) + (right - left) / 2;

        if (isBadVersion(mid))
            return _firstBadVersion(left + 1, mid);
        else
            return _firstBadVersion(mid, right);
    }

    // interate method
    int __firstBadVersion(int left, int right)
    {

        int mid;
        while (true)
        {
            if (isBadVersion(left))
                return left;

            mid = (left) + ((right - left) / 2);
            if (isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
    }

public:
    int firstBadVersion(int n)
    {
        return _firstBadVersion(1, n);
    }
};

int main()
{
    Solution s;
    //  std::cout << s.firstBadVersion(5) << std::endl;

    setBad(3);
    std::cout << "n is :" << 2 << "    Bad is " << bad << std::endl;
    std::cout << s.firstBadVersion(7) << std::endl;

    system("pause");
    return 0;
}