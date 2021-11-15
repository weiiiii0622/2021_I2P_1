#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char A[1010], B[1010];
        scanf("%s %s", A, B);
        // get length of A, B
        int n = strlen(A), m = strlen(B), L;
        if (n < m) L = n;
        else L = m;
        // compare strings
        int match_len = 0;
        for (int len = 1; len <= L; len++) {
            int good = 1;
            // check each character
            for (int i = 0; i < len; i++) {
                if (A[(n-len)+i] != B[i]) {
                    good = 0;
                    break;
                }
            }
            if (good == 1) match_len = len;
        }
        // output
        for (int i = 0; i < n-match_len; i++)
            printf("%c", A[i]);
        for (int i = 0; i < m; i++)
            printf("%c", B[i]);
        printf("\n");
    }
    return 0;
}
