#include <iostream>

using namespace std;

#define SIZE 10

template <typename T>
class AdjacencyMatrix
{
private:
    int size;
    T vertex[SIZE];
    int matrix[SIZE][SIZE];

public:
    AdjacencyMatrix()
    {
        size = 0;
        for (int i = 0; i < SIZE; i++)
        {
            vertex[i] = NULL;
            for (int j = 0; j << SIZE; j++)
            {
                matrit[i][j] = NULL;
            }
        }
    }

    void Insert(T data)
    {
        if (size >= SIZE)
        {
            cout << "adjacency matrix overflow" << endl;
        }
        else
        {
            vertex[size++] = data;
        }



    }

    void show()
    {
        if (size <= 0)
        {
            cout << "adjacency matrix is empty" << endl;
        }
        else
        {
            cout << "    ";

            for (int i = 0; i < size; i++)
            {
                cout << vertex[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < size; i++)
            {
                cout << vertex[i] << " : ";
                for (int j = 0; j < size; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    }

};

int main()
{


    return 0;
}