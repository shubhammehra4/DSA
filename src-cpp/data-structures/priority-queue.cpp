#include <bits/stdc++.h>
#include <bits/stl_algo.h>
using namespace std;

// Naive
class PriorityQueue
{
private:
    list<int> items;
    std::function<bool(int, int)> comparator;

public:
    PriorityQueue(std::function<bool(int, int)> comp) : comparator(comp){};
    int front()
    {
        return this->items.front();
    }

    int back()
    {
        return this->items.back();
    }

    int size()
    {
        return this->items.size();
    }

    bool isEmpty()
    {
        return this->items.size() == 0;
    }

    void enqueue(int data)
    {
        this->items.push_back(data);
        this->items.sort(comparator);
    }

    int dequeue()
    {
        if (this->items.size() == 0)
            return -1;

        int data = this->items.front();
        this->items.pop_front();
        return data;
    }
};

int main()
{
    auto spq = PriorityQueue([](int a, int b)
                             { return a > b; });

    spq.enqueue(1);
    spq.enqueue(5);
    spq.enqueue(4);
    spq.enqueue(2);
    spq.enqueue(8);
    spq.enqueue(-7);
    spq.enqueue(10);
    spq.dequeue();

    cout << spq.size() << endl;
    cout << spq.front() << endl;
    cout << spq.back() << endl;
}