#include <iostream>     // 1123543 negatives in k
#include <vector>
#include <queue>

using namespace std;

vector <int> firstNegativeInWindow(const vector<int>& arr, int k) 
{
    vector<int> result;
    queue<int> q; 

    for (int i = 0; i < arr.size(); ++i) 
    {
        if (!q.empty() && q.front() < i - k + 1) 
        {
            q.pop();
        }

        if (arr[i] < 0) 
        {
            q.push(i);
        }

        if (i >= k - 1) 
        {
            if (!q.empty()) 
            {
                result.push_back(arr[q.front()]); 
            }
            else 
            {
                result.push_back(0); 
            }
        }
    }

    return result;
}

int main() 
{
    int size, num, k;
    cout << "Enter the amount of integers: ";
    cin >> size; 
    cout << "Enter the k: ";
    cin >> k;
    cout << "Enter the integers: ";
    vector<int> arr;
    for (int i = 0; i < size; ++i)
    {
        cin >> num;
        arr.push_back(num);
    }

    vector<int> result = firstNegativeInWindow(arr, k);

    cout << "Output " << ": ";
    for (int neg : result) 
    {
        cout << neg << " ";
    }
    cout << endl;

    return 0;
}
