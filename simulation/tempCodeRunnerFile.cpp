#include <stdio.h>
int main() {
float arrival_rate = 1.0;
float service_time_sec = 20.0;
float service_rate = 60.0 / service_time_sec;
float travel_to_seat_min = 1.5;
float arrival_before_kickoff = 2.0;
float time_in_system_min = 1.0 / (service_rate - arrival_rate);
float total_time_min = time_in_system_min + travel_to_seat_min;
printf("compiled by Aswin phuyal\n");
printf("Total time to reach seat: %.2f minutes\n", total_time_min);
if (total_time_min <= arrival_before_kickoff) {
printf("Result: Yes, the fan will be seated before kick-off.\n");
} else {
printf("Result: No, the fan will miss the start of the game.\n");
}
return 0;
}