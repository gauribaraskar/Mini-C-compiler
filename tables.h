#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

enum Identifier{
  ID = 1
};

struct table_entry{

    char *lexeme;
    int token;
    struct table_entry *next;
};

typedef struct table_entry entry;

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

int Search(entry** TablePointer, char *lexeme)
{
  int temp = hash(lexeme);
  entry *head = NULL;
  head = TablePointer[temp];

  while(head != NULL)
  {
    if(strcmp(head->lexeme,lexeme) == 0)
      return 1;
    else
      head = head->next;
  }
  if(head == NULL)
    return 0;
  return 0;
}

void InsertEntry(entry** TablePointer, char *lexeme,int Token )
{
  if(Search(TablePointer,lexeme) == 1)
    return;
  else
  {
    int temp = hash(lexeme);
    entry *head = NULL;

    head = TablePointer[temp];

    entry *tempPoint = NULL;
    tempPoint = malloc(sizeof(entry));
    tempPoint->lexeme = strdup(lexeme);
    tempPoint->token = Token;
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
}

void Display(entry** TablePointer)
{
  int i =0;
  entry *temp = NULL;

  printf("\n\n");

  printf("-----------------------------------------\n");

  printf("Printing Table:\n");
  printf("(lexeme, token)\n" );

  for(i=0;i<SIZE;i++)
  {

    temp = TablePointer[i];
    while(temp != NULL)
    {
      printf("(%s, %d)\n",temp->lexeme,temp->token);
      temp = temp->next;
    }

  }

  printf("-----------------------------------------\n");
}


int main()
{
  entry **table;
  table = CreateTable();

  InsertEntry(table,"ayush",ID);
  InsertEntry(table,"Kumar",ID);
  InsertEntry(table,"SING",ID);

  Display(table);
  return 0;
}
