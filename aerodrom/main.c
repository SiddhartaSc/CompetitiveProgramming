#include <stdio.h>
#include <stdlib.h>

long long int search(long long int ti,long long int tf, long long int ndesks,long long tdesks[], long long int npersons){

    long long int t = ((tf-ti)/2)+ti;

    if(tf-ti==0)
        return t;

    int i=0;
    long long int clients=0;
    while(i<ndesks && clients<npersons){
        clients += t/tdesks[i];
        i++;
    }

    //printf("%d %d %d     %lld\n",ti,t,tf,clients);

    if(clients>=npersons)
        return search(ti,t,ndesks,tdesks,npersons);
    else
        return search(t+1,tf,ndesks,tdesks,npersons);

}

int main() {
    long long int ndesks;
    long long int npersons;

    #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif

    scanf("%lld%lld", &ndesks, &npersons);

    //printf("%d\n", ndesks);
    //printf("%d\n", npersons);

    long long int tdesks[ndesks];
    int i;

    for(i=0;i<ndesks;i++){
		scanf("%lld", &tdesks[i]);
		//printf("%lld\n", tdesks[i]);
    }

    int t = search(1,100000000000000000,ndesks,tdesks,npersons);
    printf("%lld",t);
    return t;
}
