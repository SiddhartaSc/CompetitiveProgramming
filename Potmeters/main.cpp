#include <stdio.h>
int BIT[(1<<18)+1], A[1<<18];
int query(int idx) {
    static int sum;
    sum = 0;
    while(idx) {
        sum += BIT[idx];
        idx -= idx&(-idx);
    }
    return sum;
}
void modify(int idx, int L, int v) {
    while(idx <= L) {
        BIT[idx] += v;
        idx += idx&(-idx);
    }
}
int main() {
    int n, x, y, i;
    int cases = 0;
    char op[10], cmd[50];

    scanf("%d", &n);
    while(n == 1 && n) {
        for(i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            BIT[i] = 0;
        }
        for(i = 1; i <= n; i++)
            modify(i, n, A[i]);
        while(getchar() != '\n');
        if(cases)   puts("");
        printf("Case %d:\n", ++cases);
        while(gets(cmd)) {
            if(cmd[0] == 'E')
                break;
            sscanf(cmd, "%s %d %d", op, &x, &y);
            if(op[0] == 'M')
                printf("%d\n", query(y) - query(x-1));
            else {
                modify(x, n, y-A[x]);
                A[x] = y;
            }
        }
    }
    return 0;
}
