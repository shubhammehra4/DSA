#include <bits/stdc++.h>
using namespace std;
// Open Adressing Quadratic Probing
class QP_Hash
{
    int N;
    int curr_size;
    vector<int> hash_table;

public:
    QP_Hash(int V);

    void insertItem(int x);
    void deleteItem(int key);
    bool searchItem(int key);
    int hashFunction(int x)
    {
        return (x % N);
    }
    void displayQP_Hash();
};

QP_Hash::QP_Hash(int b)
{
    this->N = b;
    curr_size = 0;
    hash_table.resize(N, -1);
}

void QP_Hash::insertItem(int key)
{
    if (curr_size == N)
    {
        cout << "Table is Full" << endl;
        return;
    }

    int index = hashFunction(key);
    int i = 1;
    while (hash_table[index] != -1)
        index = (index + i * i) % N, i++;

    hash_table[index] = key;
    curr_size++;
}

void QP_Hash::deleteItem(int key)
{
    int index = hashFunction(key);
    int curr = 0; // Prevent from cycles if key not Present and Table is full
    int i = 1;
    while (hash_table[index] != -1 && curr < N)
    {
        if (hash_table[index] == key)
            hash_table[index] = -1, curr_size--;
        else
            index = (index + i * i) % N, i++;
        curr++;
    }
}

bool QP_Hash::searchItem(int key)
{
    int index = hashFunction(key);
    int curr = 0; // Prevent from cycles if key not Present and Table is full
    int i = 1;
    while (hash_table[index] != -1 && curr < N)
    {
        if (hash_table[index] == key)
            return true;
        else
            index = (index + i * i) % N, i++;
        curr++;
    }
    return false;
}

void QP_Hash::displayQP_Hash()
{
    for (int i = 0; i < N; i++)
    {
        cout << i << " -> " << hash_table[i];
        cout << endl;
    }
    cout << "Size: " << curr_size;
}

int main()
{
    int a[] = {15, 11, 25, 5, 12};
    int n = sizeof(a) / sizeof(a[0]);

    QP_Hash h(10);
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    h.deleteItem(12);
    h.displayQP_Hash();

    return 0;
}
