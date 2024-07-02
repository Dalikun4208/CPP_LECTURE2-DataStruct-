#include <iostream>

using namespace std;

template <typename T>
class BinarySearchTree
{
private:
    struct Node
    {
        T data;

        Node* left;
        Node* right;
    };

public:

    Node* root;

    BinarySearchTree()
    {
        root = nullptr;
    }

    Node* Root()
    {
        return root;
    }

    Node* CreateNode(T data)
    {
        Node* newNode = new Node();

        newNode->data = data;

        newNode->left = nullptr;

        newNode->right = nullptr;

        return newNode;
    }

    void Insert(T data)
    {
        if (root == nullptr)
        {
            root = CreateNode(data);
        }
        else
        {
            Node* currentNode = root;
            while (currentNode != nullptr)
            {
                if (currentNode->data == data)
                {
                    return;
                }
                else if (currentNode->data > data)
                {
                    if (currentNode->left == nullptr)
                    {
                        currentNode->left = CreateNode(data);
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
            }
        }
    }

    void Inorder(Node* root)
    {
        if (root != nullptr)
        {
            Inorder(root->left);
            cout << root->data << " ";
            Inorder(root->right);

        }
    }

    bool Find(T data)
    {
        Node* currentNode = root;

        if (currentNode->data == data)
        {
            return true;
        }
        else
        {
            while (currentNode != nullptr)
            {
                if (currentNode->data > data)
                {
                    currentNode = currentNode->left;
                }
                else
                {
                    currentNode = currentNode->right;
                }
            }
        }
        return false;
    }

    void Destroy(Node* root)
    {

    }

    ~BinarySearchTree()
    {
        Destroy(root);
    }

};

int main()
{
    BinarySearchTree<int> tree;

    tree.Insert(10);
    tree.Insert(7);
    tree.Insert(15);
    tree.Insert(5);

    tree.Inorder(tree.Root());

    return 0;
}