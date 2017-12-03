#include <string>
#include <iostream>


using namespace std;

string s,t;
long long ans = 0;
int dp[5001][5001];


int main()
{
    cin >> s;
    cin >> t;

    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            //cout << i << ":" << s.at(i-1) << " " << j << ":" << t.at(j-1) << endl;
            dp[i][j] = dp[i][j-1];
            if(s.at(i-1)==t.at(j-1))
                dp[i][j]=dp[i][j] + dp[i-1][j-1] + 1;
        }
    }
    //for(int i=1;i<=s.size();i++)
      //  for(int j=1;j<=t.size();j++)
        //    cout << "dp " << i << "," << j << ":" <<dp[i][j] << endl;

    for(int i=1;i<=s.size();i++)
        ans = ans + dp[i][t.size()];

    cout << ans;

    return 0;
}
