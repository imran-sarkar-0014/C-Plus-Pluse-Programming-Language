#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;
        int n = numbers.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1, k = n - i - 1; j < n && k >= 0; j++, k--)
            {
                if ((numbers[i] + numbers[j]) == target)
                {
                    result.push_back(i + 1);
                    result.push_back(j + 1);
                    return result;
                }
                if ((numbers[i] + numbers[k]) == target)
                {
                    result.push_back(i + 1);
                    result.push_back(k + 1);
                    return result;
                }
            }
        }

        return result;
    }
};

int main()
{

    vector<int> numbers({2, 3, 4});

    Solution s;
    vector<int> res = s.twoSum(numbers, 6);

    for (int i : res)
    {
        cout << i << " ";
    }

    system("pause");
    return 0;
}