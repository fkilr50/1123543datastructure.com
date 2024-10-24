#include <iostream>     // 1123543 reversing stack
#include <stack>
#include <vector>

using namespace std;

void insertAtBottom(stack<int>& stock, int item) 
{
    if (stock.empty()) 
    {
        stock.push(item);
        return;
    }

    int top = stock.top();
    stock.pop();

    insertAtBottom(stock, item);

    stock.push(top);
}

void reverseStack(stack<int>& stock) 
{
    if (stock.empty()) 
    {
        return;
    }

    int top = stock.top();
    stock.pop();

    reverseStack(stock);

    insertAtBottom(stock, top);
}

int main() {
    stack<int> stock;
    int num, size;
    vector <int> queue;

    cout << "Enter the amount of integers: ";
    cin >> size; 
    cout << "Enter the integers: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> num;
        queue.push_back(num);
    }

    for (int i = size -1; i >= 0; --i)
    {
        stock.push(queue[i]);
    }
    
    cout << endl << "Original Stack: ";
    stack<int> temp = stock; 
    while (!temp.empty()) 
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(stock);

    cout << "Reversed Stack: ";
    while (!stock.empty()) 
    {
        cout << stock.top() << " ";
        stock.pop();
    }
    cout << endl;

    return 0;
}
