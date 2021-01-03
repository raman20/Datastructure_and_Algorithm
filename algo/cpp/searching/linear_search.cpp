#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int elem = 4;
        
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
    {
        if(elem == arr[i])
        {
            cout << "found at index " << i << endl;
            break;
        }
    }

    return 0;
}
