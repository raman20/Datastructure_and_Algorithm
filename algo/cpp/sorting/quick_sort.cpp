#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int st, int end)
{ 
    int i = st-1;
    if(st <= end)
    {
        int pivot = arr[end];
        for(int j{st}; j <= end-1; ++j)
        {
            if(arr[j] < pivot)
            {
                ++i;
                std::swap(arr[j],arr[i]);
            }
        }
    }
    std::swap(arr[i+1],arr[end]);
    return (i+1);
}

void quick_sort(int arr[], int st, int end)
{
    if(st <= end)
    {
        int pivot = partition(arr,st,end);
        quick_sort(arr,pivot+1,end);
        quick_sort(arr,st,pivot-1);
    }
}

int main()
{
    int arr[] = {8,4,3,2,1,9,7,5};
    cout << "before sorting -> ";
    for(int i{0}; i < 8; ++i)
    {
        cout << arr[i] << " ";
    }
    quick_sort(arr,0,7);
    cout << "\nafter sorting -> ";
    for(int i{0}; i < 8; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
