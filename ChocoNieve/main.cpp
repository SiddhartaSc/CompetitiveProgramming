#include <iostream>

using namespace std;

long long dp[1000];
long long n,m,total;

int main()
{
    cin >> n;
    m=1;

    for(long long i=0;i<n;i++){
        cin >> dp[i];
    }

    total=0;
    long long i=0;
    long long j=n-1;
    for(long long t=0;t<n;t++){
        if(dp[i]<dp[j]){
            total = total + dp[i]*m;
            i++;
        }else{
            total = total + dp[j]*m;
            j--;
        }
        m++;
    }


    cout << total;
    return 0;
}
