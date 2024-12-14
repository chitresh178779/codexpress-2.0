#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int even_count = 0, odd_count = 0;
        int stamina;

        for (int i = 0; i < N; i++) {
            scanf("%d", &stamina);
            if (stamina % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }

        if (even_count > odd_count) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}