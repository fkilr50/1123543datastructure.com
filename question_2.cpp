#include <iostream>     // 1123543 nge
#include <stack>
#include <vector>

using namespace std;

vector<int> findNGE(stack<int> stock) 
{
    stack<int> tempStack;
    vector<int> nge;
    int n = stock.size();

    nge.resize(n, -1);

    while (!stock.empty()) 
    {
        int current = stock.top();
        stock.pop();

        while (!tempStack.empty() && tempStack.top() <= current) 
        {
            tempStack.pop();
        }

        if (!tempStack.empty()) 
        {
            nge[n - stock.size() - 1] = tempStack.top();
        }

        tempStack.push(current);
    }

    return nge;
}

int main() 
{
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
        stock.push(num);
    }

    cout << "Original Stack: ";
    for (auto i : queue)
    {
        cout << i << " ";
    }

    vector<int> nge = findNGE(stock);

    cout << endl << "Next Greater Elements: ";
    for (int i = nge.size()- 1; i >= 0; i--) 
    {
        cout << nge[i] << " ";
    }
    cout << endl;

    return 0;
}
