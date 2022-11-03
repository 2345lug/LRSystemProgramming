#include <stdio.h>
 
int main()
{
  int m_number = 0;
  printf("Input number M ");
  //scanf("%d", m_number);
  m_number = 45;
  for (int i = 1; i < m_number; i++)
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