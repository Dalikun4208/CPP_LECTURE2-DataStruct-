#include <iostream>
#pragma warnings(disable: 4996)

using namespace std;

template <typename Key, typename Value>
class HashTable
{
private:
    int size;
    struct Node
    {
        Key key;
        Value Value;
        Node* Next;
    };
    struct Bucket
    {
        Node* head;
        int count;
    };

    Bucket bucket[size];



public:
    HashTable()
    {
        size = 0;
        Node = nullptr;
        Bucket = nullptr;
    }
};

int main()
{
    


    return 0;
}