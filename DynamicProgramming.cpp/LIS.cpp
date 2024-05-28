#include <bits/stdc++.h>

using namespace std;

typedef struct lis
{
    int input;
    int length;
    int previous;
} custom_type;

int LIS(int a[], int n)
{

    custom_type Arr[n];

    for (int i = 0; i < n; i++)
    {
        Arr[i].input = a[i];
        Arr[i].length = 1;
        Arr[i].previous = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Arr[i].input > Arr[j].input)
            {
                Arr[i].length = max(Arr[i].length, (1 + Arr[j].length));

                if (Arr[i].length <= (1 + Arr[j].length))
                {
                    Arr[i].previous = j;
                }
            }
        }
    }

    int Max_Length = Arr[0].length;
    int Max_Position;

    for (int i = 0; i < n; i++)
    {
        if (Max_Length < Arr[i].length)
        {
            Max_Length = Arr[i].length;
            Max_Position = i;
        }
    }

    int Lis[Max_Length];
    int k = Max_Length - 1;
    int index = Max_Position;

    while (index >= 0)
    {
        Lis[k] = Arr[index].input;
        k--;
        index = Arr[index].previous;
    }

    cout << "The Lis is " << endl;
    for (int i = 0; i < Max_Length; i++)
    {
        cout << Lis[i] << " ";
        
    }

    cout<<endl;

    return Max_Length;
}

int main()
{
    int n;
    cout << "Input the number of elements in the array" << endl;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = LIS(arr, n);

    cout << "The Length of LIS is" << result << endl;
}