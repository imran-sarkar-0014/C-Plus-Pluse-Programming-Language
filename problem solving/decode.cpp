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
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> output;
        bool is_pos = k > 0 ? true : false;
        k = is_pos ? k : -k;
        int sum;
        int index;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            index = is_pos ? i + 1 : i - k;
            boundary_index(index, n);
            for (int j = 0; j < k; j++)
            {
                sum += code[index];
                index++;
                boundary_index(index, n);
            }
            output.push_back(sum);
        }

        return output;
    }
};

int main()
{
    std::vector<int> input({5, 7, 1, 4});
    Solution s;
    vector<int> output = s.decrypt(input, -2);

    std::cout << -12 % 6 << std::endl;

    std::cout << endl
              << "[";
    for (int i : output)
    {
        std::cout << i << " ,";
    }
    std::cout << "]" << endl;
    system("pause");
    return 0;
}