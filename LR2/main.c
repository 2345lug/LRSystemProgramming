#include <stdio.h>
#include <malloc.h>
 
void simple_seek(int max_number, int* value_array_pointer);

int main()
{
  int m_number = 0;
  printf("Input number M ");
  scanf("%d", m_number);
  int* value_array = (int*)malloc(m_number * sizeof(int));

  simple_seek(m_number, value_array);
  
}

void simple_seek(int max_number, int* value_array_pointer)
{
  int simple_number_count = 0;
  *(value_array_pointer) = 2; //2 is simple
  simple_number_count++;
  
  for (int i = 3; i < max_number; i+=2)
  {
    int current_number = 0;

    for (int j = 1; j <= i; j++)
    {
      if (i%j == 0)
      {
        current_number = current_number + j;
      }
    }
    if (current_number - 1 == i)
    {
      *(value_array_pointer + simple_number_count) = i;
      simple_number_count++;
    }
  }

  for (int i = 0; i < simple_number_count; i++)
  {
    printf("%d ", *(value_array_pointer + i));
  }
  
}