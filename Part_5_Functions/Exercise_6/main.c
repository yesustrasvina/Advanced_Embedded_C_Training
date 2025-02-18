/*
Write a function that takes the time as three integer arguments (for hours, minutes, and seconds)
 and returns the number of seconds since the last time the clock “struck 12.”
  Use this function to calculate the amount of time in seconds between two times, both of which are within one 12-hour cycle of the clock.
*/

#include <stdio.h>

unsigned int TimeSince12h(unsigned int hour, unsigned int minutes, unsigned int seconds);

int main( void )
{
  unsigned int hour, minutes, seconds;

  printf("Enter the hour: ");
  scanf("%u", &hour);
  printf("Enter the minutes: ");
  scanf("%u", &minutes);
  printf("Enter the seconds: ");
  scanf("%u", &seconds);

  TimeSince12h(hour,minutes,seconds);
    
}

unsigned int TimeSince12h(unsigned int hour, unsigned int minutes, unsigned int seconds)
{
  int hourToSeconds, minutesToSeconds,totalseconds;

  hourToSeconds = hour * 60 * 60;
  minutesToSeconds = minutes * 60;
  totalseconds = hourToSeconds + minutesToSeconds + seconds;

  printf("%d seconds since the las time the clock struck 12\n",totalseconds);
}