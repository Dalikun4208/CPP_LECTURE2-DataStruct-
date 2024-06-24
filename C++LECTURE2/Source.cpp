﻿#include <iostream>

using namespace std;

#define SIZE 6

template<typename KEY, typename VALUE>
class HashTable
{
private:
    struct Node
    {
        KEY key;
        VALUE value;

        Node* next;
    };

    struct Bucket
    {
        int count;
        Node* head;
    };

    Bucket bucket[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            bucket[i].count = 0;
            bucket[i].head = nullptr;
        }
    }

    template <typename T>
    int HashFunction(T key)
    {
        unsigned int hashIndex = (int)key % SIZE;

        return hashIndex;
    }

    template<>
    int HashFunction(std::string key)
    {
        int result = 0;

        for (const char& element : key)
        {
            result += element;
        }

        int hashIndex = result % SIZE;

        return hashIndex;
    }

    Node* CreateNode(KEY key, VALUE value)
    {
        Node* newNode = new Node();
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;

        return newNode;
    }

    void Insert(KEY key, VALUE value)
    {
        // 해시 함수를 통해서 값을 받는 임시변수
        int hashIndex = HashFunction(key);
        //새로운 노드를 생성합니다.
        Node* newNode = CreateNode(key, value);
        //노드가 1개라도 존재하지 않는다면
        if (bucket[hashIndex].head == nullptr)
        {
            bucket[hashIndex].head = newNode;
        }
        else 
        {

        }

        bucket[hashIndex].count++;
    }

};

int main()
{
    HashTable<std::string, std::string>    hashTable;

    cout << hashTable.HashFunction("Kim");


    return 0;
}