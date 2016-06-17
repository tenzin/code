#include <stdio.h>
#include <stdlib.h>

/*function to check if input number is already entered or not */
int already_entered(int arr[], int index, int number)
{
  int i;
  for(i = 0; i <= index; i++)
  {
    if(number == arr[i])
      return 1; /* number already entered before,  returns 1 */
  }
  return 0; /* number not enterd, i.e. number is unique, returns 0 */
}

int main()
{
  int numbers[20], index = -1, i, input_number;
  for(i = 0; i < 20; i++)
  {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &input_number);
    if(input_number >= 10 && input_number <= 100) /* checks if the entered number is within range */
    {
      if(already_entered(numbers, index, input_number) == 0) /* checks if the numbers has already been enterd or not */
      {
        index = index + 1;
        numbers[index] = input_number; /* copy number to array */
      }
      else  printf("Number already entered\n");
    }
    else  printf("Number out of range\n");
  }
  /* print out the content of array */
  printf("Output numbers\n");
  for(i = 0; i <= index; i++)
    printf("%d\n", numbers[i]);
  exit(0);
}
