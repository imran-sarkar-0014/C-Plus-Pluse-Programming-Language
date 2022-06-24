#include <iostream>
#include <vector>

using namespace std;

class Solution
{

private:
    void boundary_index(int &index, int &boundary)
    {
        index = index < 0 ? boundary + index : index % boundary;
    }

public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        int index = 0 - k;
        boundary_index(index, n);
        boundary_index(index, n);
        boundary_index(index, n);
        boundary_index(index, n);
        vector<int> output(n);

        for (int i = 0; i < n; i++)
        {
            output[i] = nums[index];
            index++;
            boundary_index(index, n);
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = output[i];
        }
    }
};

int main()
{

    // vector<int> nums({1, 2, 3, 4, 5, 6, 7});
    // vector<int> nums({-1});
    vector<int> nums({1, 2});
    Solution s;

    s.rotate(nums, 5);

    for (int i : nums)
        cout << i << ' ';
    cout << endl;
    system("pause");
    return 0;
}