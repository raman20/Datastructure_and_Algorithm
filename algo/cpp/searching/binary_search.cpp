#include <bits/stdc++.h>
using namespace std;

int binary_search(int* arr, int elem, int st, int end)
{
    if(st <= end)
    {
        int mid = (st+(end-st))/2;

        if(elem == arr[mid])
        {
            return mid;
        }
        else if(elem > arr[mid])
        {
            return binary_search(arr, elem, mid+1, end);
        }
        else
        {
            return binary_search(arr, elem, st, mid-1);
        }
    }
    return -1;
}

int main()
{
    int size,elem;
    cin >> size;
    cin >> elem;
    int arr[size];

    for(int i{0}; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << "found at " << binary_search(arr,elem,0,size-1) << endl;

    return 0;
}
