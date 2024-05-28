#include <bits/stdc++.h>

using namespace std;


int Minimum_Edit_Distance(string s1, string s2, int n, int m){
    int Edit_Distance[n+1][m+1];

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            Edit_Distance[0][0] = 0;
            Edit_Distance[0][j] = j;
            Edit_Distance[i][0] = i;

            if(s1[i-1]==s2[j-1]){
                Edit_Distance[i][j] =  Edit_Distance[i-1][j-1];

            }
            else{
                Edit_Distance[i][j] = 1+ min(Edit_Distance[i-1][j], min(Edit_Distance[i-1][j-1], Edit_Distance[i][j-1]));
            }
        }
    }

     for (int i = 0 ; i< n+1; i++)
    {
        for(int j = 0 ; j < m+1 ; j++)
        {
            printf(" %d ", Edit_Distance[i][j] ) ;
        }
        printf("\n");

    }

    printf("\n");

    int i = n; 
    int j = m;

    string string = s1;

    while(i > 0 && j>0){
        if(s1[i-1] == s2[j-1]){
            i--; 
            j--;
        }

        else{
            if(Edit_Distance[i-1][j] <=  Edit_Distance[i-1][j-1] && Edit_Distance[i-1][j] <= Edit_Distance[i][j-1]){
                cout<<"From String 1  " <<s1[i-1]<<" is removed";
                string.erase(i-1, 1);
                i--;

            }
            else if(Edit_Distance[i-1][j-1] <= Edit_Distance[i][j-1] && Edit_Distance[i-1][j-1] <=  Edit_Distance[i-1][j]){
                cout<<s1[i-1] <<"is replaced by "<< s2[j-1]<<endl;

                string[i-1] = s2[j-1];
                i--;
                j--;
                
            }

            else{
                cout<<s2[j-1]<<"String  is inserted in "<<endl;
                string.insert(i, 1, s2[j-1]);
                j--;
            }
        }
    }

    cout << "Transformed string: " << string << endl;
    return Edit_Distance[n][m];




}

int main(){
    string str1;
    string str2;
    cout<<"Enter string 1"<<endl;
    cin>>str1;
    cout<<"Enter string 2"<<endl;
    cin>>str2;


    int n= str1.size();
    int m = str2.size();


    int result = Minimum_Edit_Distance(str1, str2, n,m);

    cout<<"The Minimum Edit Distance "<<result<<endl;




}