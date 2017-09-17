/* Given two non-negative integers a, n
   return a^n modulo MOD, which is also given. O(log(n)) */

#include <cstdio> //#include <iostream>
#include <string>

long long int binaryExp(long long int a, char n[], long long int MOD) {
	long long int res = 1;
	int i=1000000;
	while (i>=0) {  // while (n != 0). In this case checking for n > 0 since n is non negative.
        //if(i<15)
          //printf("%c",n[i]);
		if (n[i]=='1') { // if (n%2 != 0). In this case 1 or 0.
			res = (res * a) % MOD;
            //printf("i:%d  n[i]:%c  a:%lld  ",i,n[i],a);
		}
		if(n[i]=='0')
            a = (a * a) % MOD;
        i--;
	}
	return res;
}


long long int a, MOD;
char sn[1000001]="";
int main() {
	scanf("%lld %lld ", &a, &MOD); // cin >> a >> n >> M;
	scanf("%s",&sn);
	//printf("Binary: %s ",sn);
	printf("%lld\n", binaryExp(a, sn, MOD)); // cout << binaryExp(a, n, MOD) << endl;
}
