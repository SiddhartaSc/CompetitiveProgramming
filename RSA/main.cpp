#include <iostream>
#include <cstdio>

typedef long long ll;

using namespace std;

void ExtendedEuclidAlgorithm(ll a, ll b, long long & x, long long  & y, long long & d) {
	ll q, aux;
	ll r0 = a;
	ll r1 = b;
	ll s0 = 1;
	ll s1 = 0;
	ll t0 = 0;
	ll t1 = 1;

	while (r1) {
		q = r0/r1;
		aux = r1;
		r1 = r0 - q*r1;
		r0 = aux;
		aux = s1;
		s1 = s0 - q*s1;
		s0 = aux;
		aux = t1;
		t1 = t0 - q*t1;
		t0 = aux;
	}
	d = r0;
	x = s0;
	y = t0;
}

/* Given two non-negative integers a, n
   return a^n modulo MOD, which is also given. O(log(n)) */

//#include <iostream>

long long binaryExp(long long a, long long n, long long MOD) {
	long long res = 1;
	while (n) {  // while (n != 0). In this case checking for n > 0 since n is non negative.
		if (n%2) { // if (n%2 != 0). In this case 1 or 0.
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		n = n/2; // n = n >> 1. Shift bit "1101" ---> "110".
	}
	return res;
}


int main() {
	ll n, e, c, x, y, d;
	scanf("%lld %lld %lld", &n, &e, &c);
	ExtendedEuclidAlgorithm(e, n, x, y, d);
	//printf("(%lld)x(%lld) + (%lld)x(%lld) = %lld\n", a, x, b, y, d);

	printf("Entrada n:%lld e:%lld c:%lld de donde el inverso que existe porque d:%lld el inverso de e mod n salio x:%lld \n", n,e,c,d,x);
	if(d==1){
        printf("%lld\n", binaryExp(c, x, n)); // cout << binaryExp(a, n, MOD) << endl;
    }
    else
        printf("-1\n");

    return 0;
}
