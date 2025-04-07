#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

int P[MAXN], q[MAXN];
char input[MAXN * 10];
int k, n;

void parseCoefficients() {
    n = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        P[n++] = atoi(token);
        token = strtok(NULL, " ");
    }
}

int main() {
    while (fgets(input, sizeof(input), stdin)) {
        k = atoi(input);

        if (!fgets(input, sizeof(input), stdin))
            break;

        parseCoefficients();

        if (n <= 2) {
            int r = P[0] * (-k);
            r = P[1] - r;
            printf("%d\n", P[0]);
            printf("r = %d\n\n", r);
        } else {
            q[0] = P[0];
            for (int i = 1; i + 1 < n; i++) {
                q[i] = P[i] - q[i - 1] * (-k);
            }
            int r = P[n - 1] - q[n - 2] * (-k);

            printf("q(x):");
            for (int i = 0; i < n - 1; i++)
                printf(" %d", q[i]);
            printf("\n");
            printf("r = %d\n\n", r);
        }
    }
    return 0;
}
