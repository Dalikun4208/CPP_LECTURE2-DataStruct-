#include <iostream>
#pragma warnings(disable: 4996)

using namespace std;

//template <typename T>
class Str
{
private:
    char* container;
    int size;
public:
    Str()
    {
        container = nullptr;
        size = 0;
    }
    void operator = (const char* content)
    {
        int length = strlen(content) + 1;
        size = strlen(content);
        if (container == nullptr)
        {
            container = new char[length];
            for (int i = 0; i < length - 1; i++)
            {
                container[i] = content[i];
            }
        }
        else
        {
            char* newContainer = new char[length];
            for (int i = 0; i < length - 1; i++)
            {
                newContainer[i] = content[i];
            }
            delete container;
            container = newContainer;
        }
    }

    char& operator [] (const int& index)
    {
        return container[index];
    }

    int compare(const char* content)
    {
        for (int i = 0; i < size; i++)
        {
            if (container[i] != content[i])
            {
                if (container[i] > content[i])
                {
                    return 1;
                }
                else if (container[i] < content[i])
                {
                    return -1;
                }
            }
        }
        return 0;
    }

    int& Size()
    {
        return size;
    }

    void Append(const char* content)
    {
        int newSize = strlen(container) + strlen(content);
        char* newContainer = new char[newSize];
        for (int i = 0; i < strlen(container); i++)
        {
            newContainer[i] = container[i];
        }
        for (int i = 0; i < strlen(content); i++)
        {
            newContainer[strlen(container) + i] = content[i];
        }
        size = newSize;
        delete[] container;
        container = newContainer;
    }

    ~Str()
    {
        if (container != nullptr)
        {
            delete[] container;
        }
    }

};

int main()
{
    Str a;

    a = "abcdefg";

    cout << "Size : " << a.Size() << endl;
    cout << "Size : " << a[3] << endl;
    for (int i = 0; i < a.Size(); i++)
    {
        cout << a[i];
    }

    cout << "값은 : " << a.compare("abcdef") << endl;

    a.Append("123");

    for (int i = 0; i < a.Size(); i++)
    {
        cout << a[i];
    }
    return 0;
}