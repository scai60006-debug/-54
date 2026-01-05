#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PART 500
#define MAX_NAME 128

int main(void) {
    int n, i, k;
    printf("請輸入參與人數: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    if (n > MAX_PART) n = MAX_PART;
    getchar();
    static char names[MAX_PART][MAX_NAME];
    for (i = 0; i < n; ++i) {
        printf("參與者 %d 名字: ", i + 1);
        if (!fgets(names[i], MAX_NAME, stdin)) names[i][0] = '\0';
        names[i][strcspn(names[i], "\r\n")] = '\0';
    }
    printf("要抽出幾位得獎者? ");
    if (scanf("%d", &k) != 1 || k <= 0) return 0;
    if (k > n) k = n;
    srand((unsigned)time(NULL));
    for (i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        char tmp[MAX_NAME];
        strcpy(tmp, names[i]);
        strcpy(names[i], names[j]);
        strcpy(names[j], tmp);
    }
    printf("\n得獎者：\n");
    for (i = 0; i < k; ++i) printf("%d. %s\n", i + 1, names[i]);
    return 0;
}
