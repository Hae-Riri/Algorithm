#include <stdio.h>
int main() {
    int x;
    int y;
    scanf("%d-%d", &x, &y);
    printf("%06d%07d", x, y);
    return 0;
}
