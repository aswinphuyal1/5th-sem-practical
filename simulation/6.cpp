#include <stdio.h>
#define SIZE 100
int main() {
int x[SIZE];
int m = 100, a = 5, c = 13;
int i;
x[0] = 11;
for (i = 0; i < SIZE - 1; i++) {
x[i + 1] = (a * x[i] + c) % m;
}
printf("compiled by Aswin phuyal\n");
printf("Generation of random numbers using linear congruential method:\n");
for (i = 0; i < SIZE; i++) {
printf("%d\t", x[i]);
}
return 0;
}