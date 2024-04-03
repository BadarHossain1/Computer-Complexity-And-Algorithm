#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {52, 12, 14, 9, 8, 47, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The array before sorting" << endl;

    for (int i = 0; i < n; i++)
    {
         cout<<arr[i]<<endl;
    }

    // sorting starts here

    int temp, j;

    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && temp <= arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }

    cout << "Array After Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
         cout<<arr[i]<<endl;
    }


}