/**
Define a structure data type named date containing three integer members day, month
and year. Develop an interactive modular program to perform the following tasks:
               To read data into structure members by a function
               To validate the date entered by an another function
               To print the date in the format
                               October 22, 2010
               by a third function.
The input data should be three integers like 22, 4, and 2010 corresponding to day,
month and year. Examples of invalid date:
31, 4, 2010 – April has only 30 days
29, 2, 2002 – 2002 is not a leap year
**/

#include <stdio.h>
#include <stdlib.h>

struct date
{
  int day;
  int month;
  int year;
};

struct date input_date;  /** global instance **/

/** string array to be used in displaying month names **/
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

/** Function to get input **/
void get_input()
{
  printf("Enter day: ");
  scanf("%d", &input_date.day);
  printf("Enter month: ");
  scanf("%d", &input_date.month);
  printf("Enter year: ");
  scanf("%d", &input_date.year);
}

/** Function to validate input **/
int validate_date()  /** function return 0 if invalid **/
{
  if(input_date.day < 1 || input_date.day > 31)  /** Day out of range **/
  {
    printf("Input date out of range\n");
    return 0;
  }
  if(input_date.month < 1 || input_date.month > 12) /** month out of range **/
  {
    printf("Input month out of range\n");
    return 0;
  }
  if(input_date.month == 2 && input_date.day > 29) /** February wont have more than 29 days at the max **/
  {
    printf("February cannot have %d days\n", input_date.day);
    return 0;
  }
  if(input_date.day == 31 && (input_date.month == 2 || input_date.month == 4 || input_date.month == 6 || \
     input_date.month == 9 || input_date.month == 11)) /** these months do not have 31 days **/
  {
    printf("%s doesnt not have 31 days\n", months[input_date.month - 1]);  
    return 0;
  }
  if(input_date.day == 29 && input_date.month == 2 && (input_date.year % 4 != 0)) /** 29 feb in non-leap year **/
  {
    printf("%d is not a leap year. It cannot have 29 days in february\n", input_date.year);
    return 0;
  }
  return 1;
}

/** Function to print date **/
void print_date()
{
  printf("Your date is : %s %d, %d\n", months[input_date.month - 1], input_date.day, input_date.year);
}

/* main program */
int main()
{
  int go_on;
  do
  {
    get_input(input_date);
    if(validate_date() == 1)
      print_date();
    printf("Do you want to continue?(Press 1 for yes, and 0 for no): ");
    scanf("%d", &go_on);
  }while(go_on == 1);
  return 0;
}
