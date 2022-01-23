
#include <iostream>
using namespace std;
#include <queue>

//k smallest elements
vector<int> kSmallest(int arr[], int n, int k)
{
    // Write your code here
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        int s = pq.top();
        if (s > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
//complexity (n+k)logk
//k<<<n then O(n)

void kSortedArray(int input[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }
    //index at which element will go in sorted array
    int j = 0;
    for (int i = k; i < n; i++)
    {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while (!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}
int main()
{
    int input[] = {10, 23, 54, 6};
    int k = 2;
    kSortedArray(input, 4, k);
    for (int i = 0; i < 4; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}