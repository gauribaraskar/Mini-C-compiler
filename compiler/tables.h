/*
  This File implements all functions required to implement Symbol Table and
  Constant Table.
  The functions here are used to Add entries to a hash table.

  Authors:
  Sanjana Krishnam
  Ayush Kumar
  Gauri Baraskar

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

extern int yyerror(char *msg);
extern int curr_nest_level;

struct table_entry{

    int line_number;
    char *lexeme;
    double value;
    char* data_type;
    int is_function;
    int nesting_level;
    char* parameter_list[10]; 
    int num_params;
    struct table_entry *next;
};

struct nested{
    int nesting_level;
    int line_end;
};

struct nested **Nester = NULL;

void nested_homekeeping()
{
  Nester = malloc(sizeof(struct nested*)*SIZE);

  int i;
  for(i = 0;i<SIZE;i++)
  {
    Nester[i] = NULL;
  }
}

void insertNest(int nesting_level,int line_end)
{
  struct nested *temp = NULL;
  temp = malloc(sizeof(struct nested));
  temp->nesting_level =  nesting_level;
  temp->line_end = line_end;

  Nester[nesting_level] = temp;
}


typedef struct table_entry entry;

void Display(entry** TablePointer);
int hash(char *lexeme)
{
  int hash = 0,i=0;

  for(i=0; i < strlen(lexeme); i++)
    hash += lexeme[i];

  return hash % SIZE;
}

entry** CreateTable()
{
  entry **TablePointer = NULL;

  TablePointer = malloc(sizeof(entry*)*SIZE);

  if(TablePointer == NULL)
    return NULL;

  int i;
  for(i=0;i<SIZE;i++)
    TablePointer[i] = NULL;

  return TablePointer;
}

entry* Search(entry** TablePointer, char *lexeme,int currScope)
{
  int temp = hash(lexeme);
  entry *head = NULL;
  head = TablePointer[temp];
  //Display(TablePointer);
  while(head != NULL)
  {
    if(strcmp(head->lexeme,lexeme) == 0 && currScope == head->nesting_level)
    {
      return head;
    }
    else
      head = head->next;
  }
  if(head == NULL)
    return NULL;
  return head;
}

void set_is_function(entry** TablePointer, char *lexeme)
{
	entry* Entry = Search(TablePointer,lexeme,curr_nest_level);
	if (Entry == NULL)
	return ;
	else
	Entry->is_function = 1;
}



entry* InsertEntry(entry** TablePointer, char *lexeme,double value,char* DataType,int line_number ,int nesting_level)
{
    int temp = hash(lexeme);
  if(Search(TablePointer,lexeme,curr_nest_level) != NULL)
    return TablePointer[temp];
  else
  {

    entry *head = NULL;

    head = TablePointer[temp];

    entry *tempPoint = NULL;
    tempPoint = malloc(sizeof(entry));
    tempPoint->lexeme = strdup(lexeme);
    tempPoint->value = value;
    tempPoint->data_type = strdup(DataType);
    tempPoint->line_number = line_number;
    tempPoint->nesting_level = nesting_level;
    tempPoint->next = NULL;

    if (head == NULL)
    {
      TablePointer[temp] = tempPoint;
    }
    else
    {
      tempPoint->next = TablePointer[temp];
      TablePointer[temp] = tempPoint;
    }

  }
  return TablePointer[temp];

}


void fill_parameter_list(entry* tableEntry, char **list, int n)
{
  printf("start");

   int i;
   for(i=0; i<n; i++)
   {
    tableEntry->parameter_list[i] = (char *)malloc(sizeof(char));
     strcpy(tableEntry->parameter_list[i],list[i]);
   }
   tableEntry->num_params = n;
}

int check_parameter_list(entry* tableEntry, char** list, int m)
{

	if(m != tableEntry->num_params)
	{
		yyerror("Number of parameters and arguments do not match");
	}

	int i;
	for(i=0; i<m; i++)
	{
		if(list[i] != tableEntry->parameter_list[i])
		yyerror("Parameter and argument types do not match");
	}

	printf("sdfghjk");

	return 1;
}


void Display(entry** TablePointer)
{
  int i =0;
  entry *temp = NULL;

  printf("\n\n");

  printf("-----------------------------------------\n");

  printf("\n\t(lexeme, value, Data type, Line Number, isFunction, Nesting Level, num_params, parameter_list)\n" );

  for(i=0;i<SIZE;i++)
  {
    temp = TablePointer[i];
    while(temp != NULL)
    {
      printf("\t(%5s, %f, %s, %d, %d, %d, %d)\n",temp->lexeme,temp->value,temp->data_type,temp->line_number,temp->is_function,temp->nesting_level, temp->num_params);
      int j;
      for(j=0; j < temp->num_params; j++)
      {
          printf("%s",temp->parameter_list[j]);
          printf("\n");
      }
      temp = temp->next;
    }

  }

  printf("-----------------------------------------\n");
}
