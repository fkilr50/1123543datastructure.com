#include <iostream>     // 1123543 interleaving queues
#include <queue>
using namespace std;

queue<int> interleaveQueues(queue<int> q1, queue<int> q2) 
{
    queue<int> result;

    int size1 = q1.size();
    int size2 = q2.size();
    
    int minSize = min(size1, size2);

    for (int i = 0; i < minSize; ++i) 
    {
        result.push(q1.front());
        q1.pop();
        result.push(q2.front());
        q2.pop();
    }

    while (!q1.empty()) 
    {
        result.push(q1.front());
        q1.pop();
    }

    while (!q2.empty()) 
    {
        result.push(q2.front());
        q2.pop();
    }

    return result;
}

int main() 
{
    queue<int> q1;
    queue<int> q2;
    int num, size;

    cout << "Enter the amount of integers: ";
    cin >> size;
    cout << "Enter the integers: ";
    for (int i = 0; i < size /2; i++)
    {
        cin >> num;
        q1.push(num);
    }

    for (int i = 0; i < size /2; i++)
    {
        cin >> num;
        q2.push(num);
    }

    queue<int> interleavedQueue = interleaveQueues(q1, q2);

    cout << "Interleaved Queue: ";
    while (!interleavedQueue.empty()) 
    {
        cout << interleavedQueue.front() << " ";
        interleavedQueue.pop();
    }
    cout << endl;

    return 0;
}
