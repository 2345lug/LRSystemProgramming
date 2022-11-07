#include <stdio.h>
#include <math.h>
#include <malloc.h>

#define MAX_STRING_SIZE 20

typedef struct list
{
	char * data;	//указатель на данные
	struct list * next;	//указатель на следующий элемент
}list;

void add(list* list, int i); // добавление нового элемента в список после i-го элемента;
void print_list(list *current_list); // вывод содержимого списка на экран;
void delete(list* list, int i); // удалить i-й элемент из списка.
void add_element(list *current_list, char* data);
void print_list_elements(list *current_list);

int main()
{
  int list_size = 6;
  list* head = NULL; //Указатель на первый элемент
  list** work_list = &head;

  //Инициализация первого элемента
  head = (list*)malloc(sizeof(list));
  head -> data = "Element 0";
  head -> next = NULL;

  for (int i = 0; i < list_size; i++)
  {
    char* current_string = (char*)malloc(MAX_STRING_SIZE);
    sprintf(current_string, " Element %d", i);
    add_element(head, current_string);
  }
  
  print_list(head);
  delete(head, 2);
  printf("After deletion: \r\n");
  print_list(head);
  printf("After insertion: \r\n");
  add(head, 2);
  print_list(head);
 
}

void add_element(list *current_list, char* data)
{
  list *temp, *previous_pointer;
  temp = (struct list*)malloc(sizeof(list));
  previous_pointer = current_list -> next; // сохранение указателя на следующий узел
  current_list -> next = temp; // предыдущий узел указывает на создаваемый
  temp -> data = data; // сохранение поля данных добавляемого узла
  temp -> next = previous_pointer; // созданный узел указывает на следующий элемент
}

void print_list(list *current_list)
{
  struct list *current_element;
  current_element = current_list;
  do {
    printf("%s ", current_element -> data); // вывод значения элемента p
    current_element = current_element-> next; // переход к следующему узлу
  } while (current_element != NULL);
  printf ("\r\n");
}

void delete(list *current_list, int position)
{
  int current_position = 1;
  struct list *previous_element;
  struct list *next_element = current_list;
    
  do {
    if (current_position == position && previous_element != NULL)
    {      
      previous_element -> next = next_element -> next;
      free(next_element);
      break;
    }
    current_position++;
    previous_element = current_list;
    next_element = current_list ->next;
  } while (next_element != NULL);
}

void add(list *current_list, int position)
{
  int current_position = 1;
  struct list *previous_element;
  struct list *next_element = current_list;
    
  do {
    if (current_position == position && previous_element != NULL)
    {      
      static char* new_element_data = "Insterted element ";
      list *temp, *previous_pointer;
      temp = (struct list*)malloc(sizeof(list));
      previous_pointer = next_element -> next; // сохранение указателя на следующий узел
      next_element -> next = temp; // предыдущий узел указывает на создаваемый
      temp -> data = new_element_data; // сохранение поля данных добавляемого узла
      temp -> next = previous_pointer; // созданный узел указывает на следующий элемент      
      break;
    }
    current_position++;
    previous_element = current_list;
    next_element = current_list ->next;
  } while (next_element != NULL);
}
