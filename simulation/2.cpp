#include <stdio.h>
int main() {
float l, m, e;
float p, et;
printf("compiled by Aswin phuyal\n");
printf("Enter Inter arrival time of customers per hour: ");
scanf("%f", &l);
printf("Enter The average time spent by customers per hour (service rate): ");
scanf("%f", &m);
// M/M/1 Queuing formulas
p = 1 - (l / m);
e = l / (m - l);
et = (1 / (m - l)) * 60;
printf("\nThe probability that a customer won't have to wait atcounter: %f\n", p);
printf("\nExpected number of customers in the bank: %f\n", e);
printf("\nExpected time to be spent in bank: %f minutes\n", et);
return 0;
}