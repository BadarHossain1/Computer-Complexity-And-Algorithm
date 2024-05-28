
#include<bits/stdc++.h>

using namespace std;

int Min_Edit_Distance(string s1 ,string s2 , int n , int m)
{
    int EDIT_DISTANCE[n+1][m+1];



    for (int i = 1; i< n+1 ; i++)
    {
        for(int j = 1 ; j < m+1 ; j++)
        {
            EDIT_DISTANCE[0][0] = 0;

            EDIT_DISTANCE[0][j]= j;
            EDIT_DISTANCE[i][0]= i;


            if (i > 0 && j> 0) //we are checking in this condition if the strings are not empty.
            {
                if (s1[i-1]== s2[j-1]) //i-1 because we are starting from 1 and the string starts from 0.
                {
                    EDIT_DISTANCE[i][j] = EDIT_DISTANCE[i-1][j-1]; 
                }
                else
                {
                    EDIT_DISTANCE[i][j] = 1 +  min(EDIT_DISTANCE[i-1][j], ( min(EDIT_DISTANCE[i-1][j-1],EDIT_DISTANCE[i][j-1])) );
                }
            }
        }
    }

    for (int i = 0 ; i< n+1; i++)
    {
        for(int j = 0 ; j < m+1 ; j++)
        {
            printf(" %d ", EDIT_DISTANCE[i][j] ) ;
        }
        printf("\n");

    }

    printf("\n");

    //*******backtracking..........................................................................

    int i = n;
    int j = m;

    while(EDIT_DISTANCE[i][j] > 0) //while condition says that we will keep on moving until we reach the 0th row or column.
    {
        if(s1[i-1] == s2[j-1]) //if the characters are same then we will move diagonally
        {
            i--;
            j--;
        }
        else
        {
            if(  EDIT_DISTANCE[i-1][j] <= EDIT_DISTANCE[i-1][j-1]  &&  EDIT_DISTANCE[i-1][j] <= EDIT_DISTANCE[i][j-1] ) //if the characters are not same then we will move to the minimum of the three. the way we get minimum is by comparing the three values and moving to the minimum value.
            {
                cout<< s1[i-1] << " removed from string 1"<<endl ;
                
                i--; //the string which gets removed is the string which is not present in the other string. So we will move to the next character of the string which is present in the other string.
            }
            else if(EDIT_DISTANCE[i-1][j-1] <= EDIT_DISTANCE[i-1][j]  &&  EDIT_DISTANCE[i-1][j-1] <= EDIT_DISTANCE[i][j-1])
            {
                cout<<"string 1's "<< s1[i-1] << " is replaced with "<< s2[j-1]<<endl;
                i--;
                j--;   
            }
            else
            {
                cout<< s2[j-1] << " inserted into string 1"<<endl ;
                j--;

            }
        }
    }



    return EDIT_DISTANCE[n][m];


}

int main()
{
    string str1 = "abcdef";
    string str2 = "ayced";

    int n = str1.size();
    int m = str2.size();

    int result = Min_Edit_Distance(str1, str2 , n, m);

    cout<<" Minimum Edit Distance = "<<result <<endl;

    return 0;


}
