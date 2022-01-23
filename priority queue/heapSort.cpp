//inplace heapsort
#include <iostream>
using namespace std;

void inplaceHeapSort(int input[], int n)
{
    //build the heap of input array
    for (int i = 1; i < n; i++)
    {
        //up heapify
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (input[parentIndex] < input[childIndex])
            {
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    //remove elements
    int size = n;
    while (size > 1)
    {
        int temp = input[0];
        input[0] = input[n - 1];
        input[n - 1] = temp;
        size--;

        //down heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * (parentIndex) + 1;
        int rightChildIndex = 2 * (parentIndex) + 2;
        while (leftChildIndex < size)
        {
            int minIndex = parentIndex;
            if (input[minIndex] > input[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < size && input[minIndex] > input[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex)
                break;
            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;
            parentIndex = minIndex;
            leftChildIndex = 2 * (parentIndex) + 1;
            rightChildIndex = 2 * (parentIndex) + 2;
        }
    }
}
int main()
{

    return 0;
}