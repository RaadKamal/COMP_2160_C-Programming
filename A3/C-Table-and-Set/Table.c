#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "Table.h"


typedef struct NODE Node;

struct NODE
{
  char *item;
  Node *next;
};


struct TABLE
{
  Node *head;
  Node *traverseNode;
  int numNodes; 
  int numTraversals;
};

char * firstItem(Table *);
char * nextItem(Table *);

Table * createTable()
{ 
  Table *new_table=malloc(sizeof(Table));
  new_table->head=NULL;
  new_table->traverseNode=NULL;
  new_table->numNodes=0;
  new_table->numTraversals=0;

  return new_table;

}


void loadFile(Table *New_Table)
{
#define LINE_SIZE 256
  char input[LINE_SIZE];
  char *token = NULL;
  
  while ( fgets( input, LINE_SIZE, stdin ) ) 
  { 
    token = strtok( input, " \t\n" );
    while ( token )
    {
      if ( !search( token,New_Table ) )
        insert( token,New_Table );
      
      token = strtok( NULL, " \t\n" );
    }
  }

}


void printConcordance(Table * new_Table)
{
  char *theWord = firstItem(new_Table);
  while ( theWord )  
  {
    printf( "%s\n", theWord );
    theWord = nextItem(new_Table);
  }
}



void validateTable(Table *new_Table)

{
  if ( new_Table->numNodes == 0 )
    assert( new_Table->head == NULL );
  else if ( new_Table->numNodes == 1 )
    assert( new_Table->head->next == NULL );
  else 
    assert( new_Table->head != NULL && new_Table->head->next != NULL );
  
}

Boolean insert( char *new_string, Table *new_Table )
{
  Boolean rc = false;
  Node *newNode = NULL;
  
  assert( new_string != NULL );
  if ( new_string )
  {
    newNode = (Node *)malloc( sizeof( Node ) );
    assert( newNode != NULL );
    
    if ( newNode )
    {
      newNode->item = strdup(new_string);
      assert( newNode->item != NULL );
      
      if ( newNode->item )
      {        
        newNode->next = new_Table->head;
        new_Table->head = newNode;        
        new_Table->numNodes++;
        
        rc = true;
        
        validateTable(new_Table);
      } 
      else 
      {
        free( newNode );
      }
    }
  }
  
  return rc;
}

Boolean delete( char * string,Table *new_table)
{ 
  assert(string!=NULL);
  Boolean check=false;
  if(new_table->head==NULL)
  	{
         return check;
        }
 
  Node *temp=new_table->head;
  Node *prev;
  
   if(search(string,new_table)==true)//if the given item is in the list
   {
    if(temp->next==NULL)

	{
        printf("Only one item in the Table");

	return check;
	}

   else{
        for(;temp->next!=NULL;temp=temp->next)
                {
			 if(strcmp(temp->item,string)==0)
       				 {
      				  break;
       		                 }
                 prev=temp;            //the previous node of the prospective deleted node
                }
      
       if(temp!=NULL)
       {
        	if(temp==new_table->head)
          	{	
         		 new_table->head=temp->next;
			       check=true;       //if the string is in  head
          	}
        	else
         	{
          	 prev->next=temp->next;
             check=true;      //if it is not the head
         	}

              free(temp);
              new_table->numNodes--;        
       }

     }

     validateTable(new_table);        
   }
   return check; 
}

void clearTable(Table * new_Table)
{
  Node *curr = new_Table->head;
  
  while ( new_Table->head != NULL )
  {
    new_Table->head = new_Table->head->next;
    free( curr->item );
    free( curr );
    curr = new_Table->head;  
    new_Table->numNodes--;
  }
  
  validateTable(new_Table);
}

void destroyTable(Table * new_Table)
{

  clearTable(new_Table);

}

Boolean search( char *target,Table * new_Table )
{
  Boolean found = false;
  char *curr = firstItem(new_Table);
  int search_count = 0;     // how far in the list do we go?
  
  assert( target != NULL );
  if ( target != NULL ) {
    while ( curr != NULL && !found ){
      if ( strcmp( target, curr ) == 0 ){
        found = true;

        assert( search_count <= new_Table->numNodes );
      } else {
        curr = nextItem(new_Table);
        search_count++;
      }// else
    }// while
  }

  assert( found || (search_count == new_Table->numNodes) );
  
  return found;
}

char * firstItem(Table * new_Table){
  char *the_item = NULL;
  
  new_Table->traverseNode = new_Table->head;
  if ( new_Table->traverseNode != NULL ) {
    the_item = new_Table->traverseNode->item;
    assert( the_item != NULL );
    
    new_Table->numTraversals = 1;
   
    assert( new_Table->numTraversals <= new_Table->numNodes );
  }
  return the_item;
}

char * nextItem(Table *new_Table){
  char *the_item = NULL;
  
  // try to advance the traversal first
  if ( new_Table->traverseNode != NULL ) 
  {
    new_Table->traverseNode = new_Table->traverseNode->next;
    new_Table->numTraversals++;
  }
 
  if ( new_Table->traverseNode != NULL ) 
  {
    the_item = new_Table->traverseNode->item;
    assert( the_item != NULL );

		assert( new_Table->numTraversals <= new_Table->numNodes );
  }

  return the_item;
}// nextItem
