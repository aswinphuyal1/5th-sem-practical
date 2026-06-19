#include <stdio.h>
#define SIZE 100
int main() {
long x[SIZE];
long m = 1000 , a = 15, c = 7;
int i;
x[0] = 13;
for (i = 0; i < SIZE - 1; i++) {
x[i + 1] = (a * x[i] + c) % m;
}
printf("compiled by Aswin phuyal\n");
printf("Generated 100 random numbers:\n\n");
for (i = 0; i < SIZE; i++) {
printf("%ld ", x[i]);
}
return 0;
}