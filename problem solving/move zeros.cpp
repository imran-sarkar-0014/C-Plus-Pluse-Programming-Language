#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        std::vector<int> n;
        int counter = 0;

        for (int num : nums)
        {
            if (num == 0)
            {
                counter++;
                continue;
            }
            n.push_back(num);
        }

        for (int i = 0; i < counter; i++)
        {
            n.push_back(0);
        }
        nums = n;
    }

    void _moveZeroes(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                count++;
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        for (int i = 0; i < count; i++)
        {
            nums.push_back(0);
        }
    }
};

int main()
{

    vector<int> nums({0, 0, 1});
    Solution s;
    s.moveZeroes(nums);

    for (int i : nums)
    {
        std::cout << i << " ";
    }

    system("pause");
    return 0;
}