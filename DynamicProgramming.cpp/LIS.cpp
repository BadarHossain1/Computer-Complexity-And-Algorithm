#include<bits/stdc++.h>

using namespace std;

typedef struct lis
{
    int input;
    int length;
    int previous;

} custom_type;

int LIS(int a[], int n)
{
    custom_type Arr[n] ;

    for(int i = 0 ; i < n ; i++)
    {
        Arr[i].input = a[i];
        Arr[i].length = 1;
        Arr[i].previous = -1;
    }

//*******************LIS logic building process***********************
    for(int i = 1 ; i < n ; i++ )
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(Arr[i].input > Arr[j].input)
            {

                Arr[i].length = max(Arr[i].length, (1 + Arr[j].length) );

                if(Arr[i].length <= (Arr[j].length + 1))
                {
                    Arr[i].previous = j ;
                }

            }
        }
    }

    //********for finding maximum length of LIS****************
    int Max_length = Arr[0].length ;
    int Max_position = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(Arr[i].length > Max_length)
        {
            Max_length = Arr[i].length;
            Max_position = i;
        }
    }

   // backtracking................................

    int Lis[Max_length];
    int k  = Max_length-1;
    int index = Max_position;

    while(index >= 0)
    {
        Lis[k] = Arr[index].input ;
        k--;
        index = Arr[index].previous;

    }

    cout<<" LIS is = ";
    for(int i = 0 ; i < Max_length ; i++)
    {
        cout<<" "<<Lis[i];
    }

    return Max_length;
}

int main()
{
    int n = 10;
    int arr[100] = {9 , 2 , 5 , 3 , 7 , 11 , 8 , 10 , 13 , 6};

    int result = LIS(arr,n);

    cout<< " \n LIS length is = "<<result;

    return 0;
}
