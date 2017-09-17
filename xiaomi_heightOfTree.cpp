#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;

    explicit Node(int v, Node* lt = nullptr, Node* rt = nullptr) : value { v }, left { lt }, right { rt } {};
};

Node* find(Node* t, int val)
{
    if (t == nullptr)
        return nullptr;
    if (t->value == val)
        return t;
    else
    {
        if (find(t->left, val) != nullptr)
            return find(t->left, val);
        else
            return find(t->right, val);
    }
}

void print(Node* t, ostream& out = cout)
{
    if (t != nullptr)
    {
        out << t->value << endl;
        print(t->left);
        print(t->right);
    }
}

void remove(Node* &t)
{
    if (t != nullptr)
    {
        remove(t->left);
        remove(t->right);
        delete t;
    }
    t = nullptr;
}

int deepth(Node* t)
{
    int left_deep = 0, right_deep = 0;
    if (t == nullptr)
        return -1;

    left_deep = 1 + deepth(t->left);
    right_deep = 1 + deepth(t->right);

    return (left_deep > right_deep) ? left_deep : right_deep;

}

int main()
{
    int father, child;
    Node* root = nullptr;
    while (cin >> father >> child) {
        if (root == nullptr)
            root = new Node{ father };

        Node* x = find(root, father);

        if (x->left == nullptr)
            x->left = new Node { child };
        else if (x->right == nullptr)
            x->right = new Node { child };
    }

    // print(root);

    cout << deepth(root);

    remove(root);

    return 0;
}
