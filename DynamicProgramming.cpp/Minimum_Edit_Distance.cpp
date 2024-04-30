
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


            if (i > 0 && j> 0)
            {
                if (s1[i-1]== s2[j-1])
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

    while(EDIT_DISTANCE[i][j] > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            i--;
            j--;
        }
        else
        {
            if(  EDIT_DISTANCE[i-1][j] <= EDIT_DISTANCE[i-1][j-1]  &&  EDIT_DISTANCE[i-1][j] <= EDIT_DISTANCE[i][j-1] )
            {
                cout<< s1[i-1] << " removed from string 1"<<endl ;
                i--;
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
