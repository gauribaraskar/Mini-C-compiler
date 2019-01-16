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


struct table_entry{

    char *lexeme;
    char  *token;
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

void InsertEntry(entry** TablePointer, char *lexeme,char *Token )
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
    tempPoint->token = strdup(Token);
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

  printf("\n\t(lexeme, token)\n" );

  for(i=0;i<SIZE;i++)
  {
    temp = TablePointer[i];
    while(temp != NULL)
    {
      printf("\t(%5s, %s)\n",temp->lexeme,temp->token);
      temp = temp->next;
    }

  }

  printf("-----------------------------------------\n");
}
