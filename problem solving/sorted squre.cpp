
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// solution from online
// nlog(n)
class Solution2
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            result.push_back(abs(nums[i] * nums[i]));
        }
        // nlog(n)
        sort(result.begin(), result.end());
        return result;
    }
};

/// O( n ) time
class Solution
{

private:
    int get_value_and_remove(list<int> &l)
    {
        int i = l.front();
        l.pop_front();
        return i;
    }

public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result;
        list<int> pos_value, neg_value;
        for (int num : nums)
        {
            if (num < 0)
            {
                neg_value.push_front(num * num);
            }
            else
            {
                pos_value.push_back(num * num);
            }
        }
        while (!pos_value.empty() && !neg_value.empty())
        {
            int nn = pos_value.front() <= neg_value.front() ? get_value_and_remove(pos_value) : get_value_and_remove(neg_value);
            result.push_back(nn);
        }
        while (!pos_value.empty())
        {
            result.push_back(get_value_and_remove(pos_value));
        }
        while (!neg_value.empty())
        {
            result.push_back(get_value_and_remove(neg_value));
        }
        return result;
    }
};

int main()
{

    vector<int> nums({-4, -1, 0, 3, 10});

    Solution s;
    vector<int> result = s.sortedSquares(nums);

    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}