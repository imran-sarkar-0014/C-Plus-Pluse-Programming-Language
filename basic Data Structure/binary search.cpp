#include <iostream>

// this is binary search function's entry point.
// it takes 4 parameters
// arr will contain the sorted array,
// left will be the index of the first position of array
// right will be the index of the end position of array
// key is the value which we will search for.
int binarySearch(int arr[], int left, int right, int key)
{
    // calculate the middle of the boudary
    int mid = (left + right) / 2;

    // if start position exceed the end possition will will return -1
    if (left > right)
        return -1;

    // if we find the value we return the index of the value.
    if (arr[mid] == key)
        return mid;

    // if mid position is grather then the value we will search for the value
    // from left to mid-1
    if (arr[mid] > key)
        return binarySearch(arr, left, mid - 1, key);

    // if mid position is less then the value we will search for the value
    // from mid+1 to right
    else
        return binarySearch(arr, mid + 1, right, key);
}

int main()
{

    // array have to be sorted.
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20};

    // call the binary search function.
    std::cout << "index of item : " << binarySearch(arr, 0, 9, 7) << std::endl;

    system("pause");
    return 0;
}