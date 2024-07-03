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

    void Remove(T data)
    {
        if (root == nullptr)
        {
            cout << "No node in here " << endl;
        }
        else
        {
            Node* currentNode = root;
            Node* parentNode = nullptr;
            while (currentNode != nullptr && currentNode->data != data)
            {
                if (currentNode->data > data)
                {
                    parentNode = currentNode;
                    currentNode = currentNode->left;
                }
                else if(currentNode->data < data)
                {
                    parentNode = currentNode;
                    currentNode = currentNode->right;
                }
            }
            // 값이 같게 되었을 경우
            if (currentNode == nullptr)
            {
                cout << "Data Nor found in the Binary tree" << endl;
            }
            else if(currentNode->left == nullptr && currentNode->right == nullptr)
            {
                if (parentNode != nullptr)
                {
                    if (parentNode->left == currentNode)
                    {
                        parentNode->left = nullptr;
                    }
                    else
                    {
                        parentNode->right = nullptr;
                    }
                }
                else
                {
                    root = nullptr;
                }
            }
            else if (currentNode->left == nullptr || currentNode->right == nullptr)
            {
                Node* childNode = nullptr;
                if (currentNode->left != nullptr)
                {
                    childNode = currentNode->left;
                }
                else
                {
                    childNode = currentNode->right;
                }

                if (parentNode != nullptr)
                {
                    if (parentNode->left == currentNode)
                    {
                        parentNode->left = childNode;
                    }
                    else
                    {
                        parentNode->right = childNode;
                    }
                }

            }
            else
            {
                Node* childNode = currentNode->right;
                Node* traceNode = childNode;

                while (childNode->left != nullptr)
                {
                    traceNode = childNode;
                    childNode = childNode->left;
                }

                currentNode->data = childNode->data;
                traceNode->left = childNode->right;
                delete childNode;
                return;

            }
            delete currentNode;
        }
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

    tree.Remove(6);

    return 0;
}