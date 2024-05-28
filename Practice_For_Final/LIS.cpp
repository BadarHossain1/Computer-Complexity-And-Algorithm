#include <bits/stdc++.h>

using namespace std;



typedef struct lis{
    int input;
    int length;
    int previous;
} custom_type;


int LIS(int arr[], int n){

    custom_type Array[n];

    for(int i = 0; i<n ;i++){
        Array[i].input = arr[i];
        Array[i].length = 1;
        Array[i].previous = -1;


    }

    for(int i=1; i<n ; i++){
        for(int j=0 ; j<i; j++){
            if(Array[i].input> Array[j].input){
                Array[i].length = max(Array[i].length, (1 + Array[j].length));

                if(Array[i].length<= (1+Array[j].length)){
                    Array[i].previous = j;
                }


            }
        }
    }

    int MaxLength = Array[0].length;
    int MaxPosition = 0;

    for(int i=0; i<n; i++){
        if(MaxLength < Array[i].length){
            MaxLength = Array[i].length;
            MaxPosition = i;
        }
    }

    int lis[MaxLength];
    int k = MaxLength-1;
    int index = MaxPosition;


    while(index>=0){
        lis[k] = Array[index].input;
        k--;
        index = Array[index].previous;


    }

    for(int i=0; i<MaxLength; i++){
        cout<<lis[i]<<" ";

    }



    return MaxPosition;
}

int main(){
    int n;
    cout<<"The size of array is.............???"<<endl;

    cin>>n;

    int arr[n];

    cout<<"The Array elements are..."<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int result = LIS(arr, n);

    cout<<"The length of LIS is"<<result<<endl;

    



}