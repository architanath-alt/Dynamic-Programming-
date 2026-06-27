#include<bits/stdc++.h>
using namespace std;

void longest_common_subsequence(string s1, string s2, int len_s1, int len_s2)
{
    vector<vector<int> > lcs(len_s1+1,vector<int>(len_s2+1,0));
    for(int i=1; i <= len_s1; i++)
    {
        for( int j = 1; j <= len_s2; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                lcs[i][j] = lcs[i-1][j-1]+1;
            }
            else if(s1[i-1] != s2[i-1] && lcs[i-1][j] == lcs[i][j-1])
            {
                lcs[i][j] == lcs[i-1][j];
            }
            else{
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }


cout<< "LCS Length = " << lcs[len_s1][len_s2] << endl;

int m = len_s1, n = len_s2;

cout<< "\nLCS Table: \n";
for(int a=0; a <= m; a++){
    for(int b = 0; b<=n; b++){
        cout<< lcs[a][b] << " ";
    }
    cout << "\n";
}

string lcs_string = " ";
while (m>0 && n>0)
{
    if(s1[m-1] == s2[n-1]){
        lcs_string = s1[m-1] + lcs_string;
            m--;
            n--;
        }
        else if(lcs[m-1][n] > lcs[m][n-1]){
            m--;
        }
        else{
            n--;
        }
    }
    cout << "LCS String: " << lcs_string<<endl;
}


int main()
{
    string s1,s2;
    cout<< "Enter string 1: ";
    cin>>s1;

    cout<< "Enter string 2: ";
    cin>>s2;

    int len_s1 = s1.size();
    int len_s2 = s2.size();

    longest_common_subsequence(s1,s2,len_s1,len_s2);
}


