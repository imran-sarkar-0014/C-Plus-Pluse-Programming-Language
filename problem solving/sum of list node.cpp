#include <iostream>
#include <string>
#include <algorithm>

std::string string_sum(std::string s1, std::string s2)
{
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    std::string result = "";
    int carry = 0;
    int sum = 0;
    int small_len = s1.size() < s2.size() ? s1.size() : s2.size();
    int max_len = s1.size() > s2.size() ? s1.size() : s2.size();

    for (int i = 0; i < small_len; i++)
    {
        int a = s1[i] - '0';
        int b = s2[i] - '0';
        sum = a + b + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    std::string &long_str = s1.size() > s2.size() ? s1 : s2;
    for (int i = small_len; i < max_len; i++)
    {
        int a = long_str[i] - '0';
        int sum = a + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry)
        result += (carry) + '0';

    std::reverse(result.begin(), result.end());
    return result;
}

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

    std::string string_sum(std::string s1, std::string s2)
    {
        std::reverse(s1.begin(), s1.end());
        std::reverse(s2.begin(), s2.end());
        std::string result = "";
        int carry = 0;
        int sum = 0;
        int small_len = s1.size() < s2.size() ? s1.size() : s2.size();
        int max_len = s1.size() > s2.size() ? s1.size() : s2.size();

        for (int i = 0; i < small_len; i++)
        {
            int a = s1[i] - '0';
            int b = s2[i] - '0';
            sum = a + b + carry;
            carry = sum / 10;
            result += (sum % 10) + '0';
        }

        std::string &long_str = s1.size() > s2.size() ? s1 : s2;
        for (int i = small_len; i < max_len; i++)
        {
            int a = long_str[i] - '0';
            int sum = a + carry;
            result += (sum % 10) + '0';
            carry = sum / 10;
        }
        if (carry)
            result += (carry) + '0';

        std::reverse(result.begin(), result.end());
        return result;
    }

private:
    void getSum(ListNode *list, std::string &sum)
    {
        if (list->next == nullptr)
            sum += list->val + '0';
        else
        {
            getSum(list->next, sum);
            sum += list->val + '0';
        }
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        std::string sum_l1 = "";
        std::string sum_l2 = "";

        getSum(l1, sum_l1);
        getSum(l2, sum_l2);
        std::string s = string_sum(sum_l1, sum_l2);
        ListNode *result = nullptr;
        for (char c : s)
        {
            ListNode *n = new ListNode(c - '0');
            n->next = result;
            result = n;
        }
        return result;
    }
};

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution
// {

// private:
//     int getSum(ListNode *list)
//     {
//         if (list->next == nullptr)
//             return list->val;
//         return (10 * getSum(list->next)) + list->val;
//     }

// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//     {
//         int sum_l1 = getSum(l1);
//         int sum_l2 = getSum(l2);
//         int sum = sum_l1 + sum_l2;
//         std::string s = std::to_string(sum);

//         ListNode *result = nullptr;

//         for (char c : s)
//         {
//             ListNode *n = new ListNode(c - '0');
//             n->next = result;
//             result = n;
//         }

//         return result;
//     }
// };

ListNode *add(int n, ListNode *next)
{
    ListNode *new_node = new ListNode(n, next);
    return new_node;
}

void print(ListNode *list)
{
    std::cout << list->val << " ";
    if (list->next != nullptr)
        print(list->next);
}

int main()
{

    std::cout << "1000" << std::to_string(1000) << std::endl;

    Solution s;
    ListNode *l1 = nullptr,
             *l2 = nullptr;

    //     [2,4,3]
    // [5,6,4]

    l1 = add(2, l1);
    l1 = add(4, l1);
    l1 = add(3, l1);
    print(l1);
    std::cout << std::endl;

    l2 = add(5, l2);
    l2 = add(6, l2);
    l2 = add(4, l2);
    print(l2);
    std::cout << std::endl;

    ListNode *res = s.addTwoNumbers(l1, l2);
    print(res);
    std::cout << std::endl;

    string_sum("30", "150");

    system("pause");
    return 0;
}