/* Given two non-negative integers a, n
   return a^n modulo MOD, which is also given. O(log(n)) */

#include <cstdio> //#include <iostream>
#include <string>
#include <iostream>

using namespace std;

long long int a, MOD;
string sn;

long long int binaryExp(long long int a, string sn, long long int MOD) {
	long long int res = 1;
	int i=sn.size()-1;
	while (i>=0) {  // while (n != 0). In this case checking for n > 0 since n is non negative.
        //if(i<15)
          //printf("%c",n[i]);
		if (sn.at(i)=='1') { // if (n%2 != 0). In this case 1 or 0.
			res = (res * a) % MOD;
            //printf("i:%d  n[i]:%c  a:%lld  ",i,n[i],a);
		}
		if(sn.at(i)=='0')
            a = (a * a) % MOD;
        i--;
	}
	return res;
}

int main() {
	cin >> a >> MOD;
    cin >> sn;
	//printf("Binary: %s ",sn);
	cout << binaryExp(a, sn, MOD) << endl;
	return 0;
}


