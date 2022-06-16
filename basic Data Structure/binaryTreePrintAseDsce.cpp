#include <iostream>

class Node
{
private:
    Node *left = nullptr;
    Node *right = nullptr;
    int data = 0;

public:
    Node(int new_data, Node *new_left = nullptr, Node *new_right = nullptr)
    {
        this->data = new_data;
        this->left = new_left;
        this->right = new_right;
    }

    void set_left(Node *new_left)
    {
        this->left = new_left;
    }
    Node *get_left() const { return this->left; }

    void set_right(Node *new_right)
    {
        this->right = new_right;
    }

    void set_data(int new_data)
    {
        this->data = new_data;
    }

    int get_data() const { return this->data; }

    Node *get_right() const { return this->right; }
};

class BinaryTree
{
private:
    Node *root = nullptr;

    void insert(Node *root_node, Node *new_node)
    {
        if (root_node->get_data() > new_node->get_data())
        {
            if (!root_node->get_left())
            {
                root_node->set_left(new_node);
            }
            else
                insert(root_node->get_left(), new_node);
        }
        else
        {
            if (!root_node->get_right())
            {
                root_node->set_right(new_node);
            }
            else
                insert(root_node->get_right(), new_node);
        }
    }

    void print(Node *n)
    {
        if (!n)
            return;
        std::cout << n->get_data() << " ";
        print(n->get_left());
        print(n->get_right());
    }

    void printAssending(Node *n)
    {
        if (!n)
            return;

        printAssending(n->get_left());
        std::cout << n->get_data() << " ";
        printAssending(n->get_right());
    }

    void printDescending(Node *n)
    {
        if (!n)
            return;
        printDescending(n->get_right());
        std::cout << n->get_data() << " ";
        printDescending(n->get_left());
    }

public:
    void add(int n)
    {
        Node *new_node = new Node(n);
        if (!this->root)
        {
            this->root = new_node;
            return;
        }
        insert(this->root, new_node);
    }

    void show()
    {
        print(this->root);
        std::cout << std::endl;
    }
    void showAssending()
    {
        printAssending(this->root);
        std::cout << std::endl;
    }

    void showDescending()
    {
        printDescending(this->root);
        std::cout << std::endl;
    }
};

int main()
{

    BinaryTree bt;
    bt.add(10);
    bt.add(5);
    bt.add(15);
    bt.add(1);
    bt.add(5);
    bt.add(18);
    bt.add(12);
    bt.add(53);
    bt.add(16);
    bt.add(14);
    bt.add(74);
    bt.add(34);
    bt.add(63);
    bt.add(5);
    bt.add(133);

    std::cout << "Show in order :" << std::endl;
    bt.show();

    std::cout << "Show Assending order :" << std::endl;
    bt.showAssending();

    std::cout << "Show Descending order : " << std::endl;
    bt.showDescending();

    system("pause");
    return 0;
}