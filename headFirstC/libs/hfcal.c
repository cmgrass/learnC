#include <stdio.h>
#include <hfcal.h>

void display_calories(float weight, float distance, float coeff)
{
  printf("Weight: %3.2f lbs\n", weight);
  printf("Distance: %3.2f miles\n", distance);
  printf("Calories Burned: %4.2f cal\n", (coeff*distance*weight));
}
