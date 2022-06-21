#include <iostream>

void move_zeros_to_end(int arr[], int len)
{
    // count how many zero '0' is in array
    int count = 0;

    // copy of array except zero '0'
    int copy[len];
    // tracker of the current index of copy array
    int tracker = 0;

    // iterate the arr
    for (int i = 0; i < len; i++)
    {
        // if zero if found.
        if (arr[i] == 0)
        {
            // count increase
            count++;
            continue;
        }

        // if not zero insert num in copy array
        copy[tracker] = arr[i];
        tracker++;
    }

    for (int i = 0; i < count; i++, tracker++)
        copy[tracker] = 0;

    for (int i = 0; i < len; i++)
        arr[i] = copy[i];
}

int main()
{

    int nums[6] = {0, 1, 0, 3, 0, 12};
    move_zeros_to_end(nums, 6);

    for (int i = 0; i < 6; i++)
        std::cout << nums[i] << ' ';
    std::cout << std::endl;

    system("pause");
    return 0;
}