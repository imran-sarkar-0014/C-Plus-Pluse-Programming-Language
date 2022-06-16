#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

int global_counter = 0;

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

    ~ListNode()
    {
        global_counter++;
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
        while (curr)
        {
            curr->show();
            curr = curr->get_next();
        }
        std::cout << std::endl;
    }

    void showFromBack()
    {
        ListNode *curr = this->tail;
        while (curr)
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

    int pop()
    {
        ListNode *last = this->tail;
        if (!last)
            return 0;

        this->tail = last->get_previous();
        const int num = last->get_data();

        if (this->tail)
        {
            this->tail->setNext(nullptr);
        }
        else
        {
            this->head = nullptr;
        }

        delete last;

        return num;
    }

    int pop(int n)
    {
        ListNode *first = this->head;
        if (!first)
            return 0;

        this->head = first->get_next();
        const int num = first->get_data();

        if (this->head)
        {
            this->head->setPrevious(nullptr);
        }
        else
        {
            this->tail = nullptr;
        }

        delete first;

        return num;
    }
};

int main()
{
    std::cout << "Wait, it's working...." << std::endl;
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    LinkedList myList;
    for (int i = 0; i < 200000; i++)
        myList.insert(i);

    for (int i = 0; i < 200000 - 100; i++)
        myList.pop(1);
    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::cout << global_counter << " times free " << std::endl;
    std::cout << "Duration  :" << (std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count()) << "s" << std::endl;

    std::cout << "Printing from beggining : ";
    myList.show();

    std::cout << "\nPrinting from end : ";
    myList.showFromBack();

    system("pause");
    return 0;
}