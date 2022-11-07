#include <stdio.h>
#include <math.h>
#include <malloc.h>

int* array_setup(long array_size);
void array_clear(int* array_pointer);
void average_dispersion_caclulate(int* array_pointer, int array_size);

int main()
{
  int input_array_size = 0;
  printf("Input array size: \r\n");
  scanf("%d", &input_array_size);
  
  printf("Array size is: %d\r\n", input_array_size);
  int* value_array = array_setup(input_array_size);  
  average_dispersion_caclulate(value_array, input_array_size);
  array_clear(value_array);
  
}

int* array_setup(long array_size)
{
  int uiFlags = 0;
  int* value_array = (int*)malloc(array_size * sizeof(int));

  for (int i = 0; i < array_size; i++)
  {
    int input_number = 0;
    printf ("Input number %d \r\n", i + 1);
    scanf("%d", &input_number);
    *(value_array + i) = input_number;
  }
  
  return value_array;
}

void array_clear(int* array_pointer)
{
  free(array_pointer);
}

void average_dispersion_caclulate(int* array_pointer, int array_size)
{
  int summ = 0;
  float average = 0;
  float variance = 0;
  float variance1 = 0;
  float variance2 = 0;
  for (int i = 0; i < array_size; i++)
  {
    summ = summ + *(array_pointer + i);
    variance2 += pow(*(array_pointer + i),2); 
    variance1 += *(array_pointer + i);
  }

  average = (float)summ / (float)array_size;
  variance = (variance2 - pow(variance1, 2) / array_size) / (array_size - 1);

  printf("Average is %lf \r\n", average);
  printf("Variance is %d \r\n", variance);  
}