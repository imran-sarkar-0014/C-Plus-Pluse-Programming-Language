#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{

    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while (left < right)
    {
        mid = (left) + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return nums[left] < target ? left + 1 : left;
}

int main()
{

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    // nums.push_back(5);
    // nums.push_back(6);

    //[1,3,5,6]
    // 1
    //[1,3,5,6]
    // 0

    cout << "" << searchInsert(nums, 0) << std::endl;
    system("pause");
    return 0;
}