#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <conio.h>

#define COMMON_MAX 59
#define HOUR_MAX 23

short seconds;
short minutes;
short hours;
bool run = true;

short getValue()
{
    short number;
    scanf("%d", &number);
    return number;
}

void setTime()
{

InputSecond:
    printf("Second: ");
    seconds = getValue();
    if (seconds > COMMON_MAX)
    {
        goto InputSecond;
    }

InputMinute:
    printf("Minute: ");
    minutes = getValue();
    if (minutes > COMMON_MAX)
    {
        goto InputMinute;
    }

InputHour:
    printf("Hour: ");
    hours = getValue();
    if (hours > HOUR_MAX)
    {
        goto InputHour;
    }
}

void displayTime()
{
    char *greeting = hours > 6 ? "Good Day\n-------------\n" : "Good Morning\n-------------\n";
    printf("%s", greeting);
Display:
    while (run)
    {

        if (seconds >= COMMON_MAX)
        {
            seconds = -1;
            minutes += 1;
        }

        if (minutes > COMMON_MAX)
        {
            hours += 1;
            minutes = 0;
        }

        if (hours > HOUR_MAX)
        {
            hours = 0;
            minutes = 0;
            seconds = -1;
        }

        seconds += 1;

        sleep(1);
        printf("%02d : %02d : %02d \n", hours, minutes, seconds);

        goto Display;
    }
}

int main()
{
    printf("Digital Clock\n-------------\n");
    setTime();
    printf("Digital Clock\n-------------\n");
    printf("-------------\n");
    displayTime();
    return 0;
}