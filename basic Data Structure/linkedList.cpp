#include <iostream>

class ListNode
{
private:
    ListNode *previous_node = nullptr;
    ListNode *next_node = nullptr;
    int data = 0;

public:
    ListNode(int initial_data, ListNode *init_prev, ListNode *init_next)
    {
        this->data = initial_data;
        this->previous_node = init_prev;
        this->next_node = init_next;
    }
    void setPrevious(ListNode *new_prev)
    {
        this->previous_node = new_prev;
    }
    void setNext(ListNode *new_next)
    {
        this->next_node = new_next;
    }
    void setData(int new_data)
    {
        this->data = new_data;
    }

    ListNode *get_previous() { return this->previous_node; }
    ListNode *get_next() { return this->next_node; }
    int get_data() { return this->data; }
    void show()
    {
        std::cout << this->data << " ";
    }
};

class LinkedList
{
private:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

public:
    void show()
    {
        ListNode *curr = this->head;
        while (curr != nullptr)
        {
            curr->show();
            curr = curr->get_next();
        }
        std::cout << std::endl;
    }

    void showFromBack()
    {
        ListNode *curr = this->tail;
        while (curr != nullptr)
        {
            curr->show();
            curr = curr->get_previous();
        }
        std::cout << std::endl;
    }

    void insert(int n)
    {
        ListNode *new_node = new ListNode(n, this->tail, nullptr);
        if (!head)
        {
            head = new_node;
            tail = new_node;
        }
        this->tail->setNext(new_node);
        this->tail = new_node;
    }
};

int main()
{

    LinkedList myList;
    myList.insert(10);
    myList.insert(13);
    myList.insert(16);
    myList.insert(12);

    myList.show();
    myList.showFromBack();

    system("pause");
    return 0;
}