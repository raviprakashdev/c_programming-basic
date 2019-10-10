#include <stdio.h>
int main() {
  int date, month, year, p_year = 2019;
  printf("Enter date=");
  scanf("%d", &date);
  printf("Enter month=");
  scanf("%d", &month);
  printf("Enter year=");
  scanf("%d", &year);
  printf("Date entered=%d/%d/%d\n", date, month, year);
  if (year <= p_year && year > 1800 && month >= 1 && month <= 12 && date >= 1 &&
      date <= 31) {
    if (year <= p_year && year % 4 == 0 && month == 2) {
      if (date < 29) {
        printf("Valid\n");
        date = date + 1;
      } else if (date == 29 && year % 400 == 0) {
        printf("Valid\n");
        date = 1;
        month = 3;
      } else {
        printf("Invalid\n");
        return 0;
      }
    }

    else if (year <= p_year && year % 4 != 0 && month == 2) {
      if (date < 28) {
        printf("Valid\n");
        date += 1;
      } else if (date == 28 && year % 100 == 0) {
        printf("Valid\n");
        date = 1;
        month = 3;
      } else {
        printf("Invalid\n");
        return 0;
      }
    }

    else if (1) {
      if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
           month == 10 || month == 12) &&
          date < 31) {
        printf("Valid\n");
        date += 1;
      } else if ((month == 1 || month == 3 || month == 5 || month == 7 ||
                  month == 8 || month == 10) &&
                 date == 31) {
        printf("Valid\n");
        date = 1;
        month += 1;
      } else if ((month == 4 || month == 6 || month == 9 || month == 11) &&
                 date < 30) {
        printf("Valid\n");
        date += 1;
      } else if ((month == 4 || month == 6 || month == 9 || month == 11) &&
                 date == 30) {
        printf("Valid\n");
        date = 1;
        month += 1;
      } else if ((month == 12) && date == 31) {
        printf("Valid\n");
        date = 1;
        month = 1;
        year += 1;
      }
    }

    printf("Date=%d/%d/%d\n", date, month, year);

  }

  else
    printf("Invalid\n");
}
