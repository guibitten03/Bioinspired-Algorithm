#include <stdio.h>

int main(){
    int x = (int)5 / 3;
    printf("%d\n", x);
}
./bioinsp lau15_dist.txt lau
valgrind --track-origins=yes ./bioinsp lau15_dist.txt lau