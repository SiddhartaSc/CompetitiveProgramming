#include <iostream>
#include <algorithm>

using namespace std;

long long rocas[1000000];
long long dp[1000000];
long long n,m,oro;

//long long exceso(long long nn){
  //  if(nn==1)
    //    return m-rocas[n];
    //else
      //  return max(m-(exceso(nn-1)+rocas[nn]),exceso(0));
//}

int main()
{
    cin >> n;
    cin >> m;

    for(long long i=0;i<n;i++){
        dp[i]=20000000;
    }

    for(long long i=0;i<n;i++){
        cin >> rocas[i];
    }

    sort(rocas,rocas+n);

    oro=0;
    int nn=n-1;
    while(oro<m){
        oro = oro + rocas[nn];
        nn--;
    }

    cout << oro-m;

    return 0;
}
