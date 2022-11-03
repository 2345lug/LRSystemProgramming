#include <stdio.h>
 
int main()
{
  int m_number = 0;
  printf("Input number M ");
  scanf("%d", m_number);
  
  printf("%d ", 2);
  for (int i = 3; i < m_number; i+=2)
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
      printf("%d ", i);
    }
  }

}