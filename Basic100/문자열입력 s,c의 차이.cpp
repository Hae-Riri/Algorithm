//%s와 %c의 차이, 배열에서는 &안씀.
#include <stdio.h>
int main() {
    char word[21];
    scanf("%s", word); //배열명 자체가 주솟값이라 &필요없음
    int i = 0;
    while (word[i] != '\0') {
        printf("\'%c\'\n", word[i]);
        //%c는 실제 문자를 받아서 그 문자열을 출력,
        //%s는 주솟값을 받아서 그 주솟값에 저장된 문자를 시작으로 \0이 나올 때까지 문자열을 출력
        i++;
    }
    return 0;
}
