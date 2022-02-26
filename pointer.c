#include <stdio.h>

void trans(int *pHour, int *pMin){
    *pHour = *pMin / 60;
    *pMin  = *pMin % 60;
}

int main(){
    int hour = 0;
    int min = 70;

    trans(&hour, &min);
    printf("%d : %d ", hour, min);

    return 0;
}
