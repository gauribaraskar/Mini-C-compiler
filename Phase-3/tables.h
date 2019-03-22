
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
extern int is_function;
extern int yylineno;

struct table_entry{

    int line_number;
    char *lexeme;
    double value;
    char* data_type;
    int is_function;
    int is_array;
    int nesting_level;
    int array_dim;
    char* parameter_list[10]; 
    int num_params;
    struct table_entry *next;
};

struct nested{
    int nesting_level;
    int line_start;
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
  struct nested *temp = NULL;
  temp = malloc(sizeof(struct nested));
  temp->nesting_level = 1;
  temp->line_start = 0;
  temp->line_end = 999999;
}

void insertNestStart(int nesting_level,int line_start)
{
  struct nested *temp = NULL;
  temp = malloc(sizeof(struct nested));
  temp->nesting_level =  nesting_level;
  temp->line_start = line_start;
  temp->line_end = 999999;

  Nester[nesting_level] = temp;
}


void insertNestEnd(int nesting_level,int line_end)
{
  if(Nester[nesting_level] != NULL)
  {
    Nester[nesting_level]->line_end=line_end ;
  }
  else
  {
    return;
  }
  
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

entry* searchFunc(entry** TablePointer,char *lexeme)
{
  int temp = hash(lexeme);
  entry *head = NULL;
  head = TablePointer[temp];
  //Display(TablePointer);
  while(head != NULL)
  {
    if(strcmp(head->lexeme,lexeme) == 0 && head->is_function == 1)
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

entry* Search(entry** TablePointer, char *lexeme)
{
  int temp = hash(lexeme);
  entry *head = NULL;
  head = TablePointer[temp];
  //Display(TablePointer);
  while(head != NULL)
  {
    if(strcmp(head->lexeme,lexeme) == 0)
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

entry* InsertSearch(entry** TablePointer, char *lexeme,int currScope)
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

entry* ScopeSearch(entry** TablePointer, char *lexeme,int currScope)
{
  int temp = hash(lexeme);
  entry *head = NULL;
  head = TablePointer[temp];

  while(head != NULL)
  {
    if(strcmp(head->lexeme,lexeme) == 0)
    {
      if(Nester[head->nesting_level]->line_end < yylineno)
      {
        head = head->next;
        continue;
      }
      else
      {
        return head;
      }
    }
    else
    {
      head = head->next;
    }
    
  }
  return NULL;
}

int funcSearch(entry** TablePointer,char *lexeme,int currLine)
{
  int temp = hash(lexeme);
  entry *head = NULL;
  entry **array = NULL;
  int raiseFlag = 0;

  array = malloc(sizeof(entry*)*SIZE);

  if(array == NULL)
    return 0;

  int i;
  for(i=0;i<SIZE;i++)
    array[i] = NULL;
  i = 0;
  head = TablePointer[temp];
  //Display(TablePointer);
  while(head != NULL)
  {
    if(strcmp(head->lexeme,lexeme) == 0 )
    {
      array[i] = head;
      head=head->next;
    }
    else
      head = head->next;
  }
  for(i=0;i<SIZE;i++)
  {

    entry* tempPoint = array[i];
    if(tempPoint == NULL)
      continue;
    else if(tempPoint->is_function == 1)
    {
      raiseFlag = 1;
      break;
    }
  }
  if(raiseFlag == 1)
  {
    head = TablePointer[temp];
    entry* prev = NULL;

    while(head != NULL)
    {
      
      if(strcmp(head->lexeme,lexeme) == 0 && head->line_number == currLine)
      {
        if(prev != NULL)
        {
          prev->next = head->next;
          free(head);
        } 
        else
        {
          TablePointer[temp] = NULL;
          free(head);
        }
        
        return 0; 
      }
      else
      {
        prev = head;
        head = head->next;
      }
      
    }
    return 0;
  }
  else
  {
    return 1;
  }
  
  
}

int set_is_function(entry** TablePointer, char *lexeme)
{
	if(funcSearch(TablePointer,lexeme,yylineno))
  {
    entry* Entry = Search(TablePointer,lexeme);
	  if (Entry == NULL)
	    return 0;
	  else
	    Entry->is_function = 1;
    return 1;
  }
  else
  {
    yyerror("Duplicate Functions Not allowed\n");
    return 0;
  }
  

  
}



entry* InsertEntry(entry** TablePointer, char *lexeme,double value,char* DataType,int line_number ,int nesting_level)
{
  int temp = hash(lexeme);  
  if(InsertSearch(TablePointer,lexeme,curr_nest_level) != NULL)
  {
    yyerror("Duplicate Variable Declaration not allowed\n");
    return TablePointer[temp];
  }  
    
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

   int i;
   for(i=0; i<n; i++)
   {
    tableEntry->parameter_list[i] = (char *)malloc(sizeof(char));
    if(strcmp(list[i],"VOID") == 0)
    {
      yyerror("Parameters of type void not allowed\n");
      return;
    }
     strcpy(tableEntry->parameter_list[i],list[i]);
   }
   tableEntry->num_params = n;
}

int check_parameter_list(entry* tableEntry, char** list, int m)
{

	if(m != tableEntry->num_params)
	{
		yyerror("Number of parameters and arguments do not match");
    exit(0);
	}

	int i;
	for(i=0; i<m; i++)
	{
		if( strcmp(list[i],tableEntry->parameter_list[i]) !=0 ){
		yyerror("Parameter and argument types do not match");
    exit(0);
  }

	}

	return 1;
}


void Display(entry** TablePointer)
{
  int i =0;
  entry *temp = NULL;

  printf("\n\n");

  printf("-----------------------------------------\n");

  printf("\n\t(lexeme, \t    value, Data type, Line Number, isArray, ArrayDimensions, isFunction, Nesting Level, num_params\n");

  for(i=0;i<SIZE;i++)
  {
    temp = TablePointer[i];
    while(temp != NULL)
    {
      printf("\t(%6s, %-5f, %9s, %11d, %7d, %15d, %10d, %13d, %10d)\n",temp->lexeme,temp->value,temp->data_type,temp->line_number,temp->is_array,temp->array_dim,temp->is_function,temp->nesting_level, temp->num_params);
      int j;
      if(temp->num_params > 0)
      {
        printf("\tParameter List for %s\n",temp->lexeme);
        printf("\t( ");
        for(j=0; j < temp->num_params; j++)
        {
            printf("%s",temp->parameter_list[j]);
            printf("\t");
        }
        printf(" )\n");
      }
      
      temp = temp->next;
    }

  }

  printf("-----------------------------------------\n");
}

void DisplayConstant(entry** TablePointer)
{
  int i =0;
  entry *temp = NULL;

  printf("\n\n");

  printf("-----------------------------------------\n");

  printf("\n\t(lexeme,   value, Data type, Line Number\n");

  for(i=0;i<SIZE;i++)
  {
    temp = TablePointer[i];
    while(temp != NULL)
    {
      printf("\t(%5s, %5f, %9s, %11d)\n",temp->lexeme,temp->value,temp->data_type,temp->line_number);
      temp = temp->next;
    }

  }

  printf("-----------------------------------------\n");
}
