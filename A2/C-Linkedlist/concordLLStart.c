    // NAME: Mostafa Raad Kamal     
    // COURSE: COMP 2160, SECTION: A02    
    // INSTRUCTOR: Franklin Bristow     
    // ASSIGNMENT: assignment 2, QUESTION: question 1     
    //      
    // REMARKS: The purpose of this program is to add words into the linklist 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

 //-------------------------------------------------------------------------------------
 // CONSTANTS and TYPES
 //------------------------------------------------------------------------------------- 

unsigned int count=0; //Elements in linkedlist

typedef enum BOOL { false, true } Boolean;
 
typedef struct NODE Node;
 
struct NODE{
  char *item;
  Node *next;
};

 //-------------------------------------------------------------------------------------
 // VARIABLES
 //-------------------------------------------------------------------------------------

 Node *Top;  //Original Top
 Node *Head; //Will be the Pointer to the Top in function

 //-------------------------------------------------------------------------------------
 // PROTOTYPES
 //-------------------------------------------------------------------------------------

Boolean insert( char * );
void clearList();
char * firstItem();
char * nextItem();
Boolean search( char *target );
void loadFile();
void printConcordance();
 
 //-------------------------------------------------------------------------------------
 // FUNCTIONS
 //-------------------------------------------------------------------------------------


 //------------------------------------------------------
 // insert
 //
 // PURPOSE: Add an element to the beginning of the linked list
 // INPUT PARAMETERS: char pointer.
 // It takes input as character.
 // OUTPUT PARAMETERS: Type Boolean
 // It returns type Boolean True or False
 // 0 or 1 as value
 // None of these may be the same as the input
 // parameters.
 //------------------------------------------------------ 
 
Boolean insert( char *new_string )
{  
    
    assert(new_string!=NULL);
    assert(strlen(new_string)>=0);
    assert(new_string[strlen(new_string)]=='\0');
         
    Boolean success=false;
 
    Node *new;

    
    new=malloc(sizeof(Node));
    new->item=malloc(sizeof(char)*strlen(new_string)+1);
 
    assert(new!=NULL && new->item!=NULL);
 
    new->next=NULL;
 
    strcpy(new->item,new_string);
     
 
        if(Top==NULL)     
         {
            Top=new;
         }
        else
         {
            new->next=Top;
            Top=new;
   
         } 
     
  
    assert(new->item!=NULL);
    assert(strlen(new->item)>=0);
    assert(strlen(new->item)==strlen(new_string));
    assert(new->item[strlen(new_string)]=='\0');
    assert(strcmp(new->item,new_string)==0);
      
    count++;
 
    success=true;
      
   return success;
}

 //------------------------------------------------------
 // clearList
 //
 // PURPOSE: Free up the allocated space.
 // INPUT PARAMETERS: None
 // OUTPUT PARAMETERS: None
 // parameters created inside the function is a Node of the Top and a previous Node that is follow.
 //------------------------------------------------------ 

void clearList()
{
  Node *curr=Top;
  Node *follow;
   
 while(curr!=NULL)
  {
    follow=curr;
    curr=curr->next; 
    free(follow);
  }
    count=0;
}

 //------------------------------------------------------
 // search
 //
 // PURPOSE: It does the linear search on the linkedlist.
 // INPUT PARAMETERS: Char pointer
 // It takes character array.
 // OUTPUT PARAMETERS:Type Boolean
 // True or False
 // 0 or 1 as value
 // Has parameter that holds the same value as count which describes the number of elements
 //------------------------------------------------------

Boolean search( char *target )
 
{ 
  assert(target!=NULL);
  assert(strlen(target)>=0);
  assert(target[strlen(target)]=='\0');
 
  unsigned int has=count;

  Node *curr=Top;
 
  Boolean value=false;
   
 
         while(curr!=NULL && target!=NULL && has>0 )
         {
                  if (strlen(target)==strlen(curr->item) && strcasecmp(target,curr->item)==0 )
                  {
                        assert(curr->item!=NULL);
                        assert(strlen(curr->item)>=0);
                        assert(strlen(curr->item)==strlen(target));
                        assert(curr->item[strlen(target)]=='\0');
                     
  
                    value=true;
                    break;
                  }
               has--;
              curr=curr->next;
      
         }
       
      return value;
}
 
 //------------------------------------------------------
 // firstitem
 //
 // PURPOSE: Starts a list traversal by getting the data at top
 // INPUT PARAMETERS: None
 // OUTPUT PARAMETERS: char pointer
 // It returns characters
 // Global pointer Head has been addressed to Top
 //------------------------------------------------------ 

char * firstItem()
{ 
    Head=Top;

    return Head->item;
     
}

 //------------------------------------------------------
 // nextItem
 //
 // PURPOSE: increment the traversal and gets the data at the current traversal node
 // INPUT PARAMETERS: None
 // OUTPUT PARAMETERS: Retuens the char pointer
 // It gives the item as character array from each Node it passes by
 // Character array
 //------------------------------------------------------ 

char * nextItem()
{

  if(Head->next!=NULL)
    {
      Head=Head->next;
    }
    else
    {
      return NULL;
    }

 return Head->item;
}
// read from standard input, tokenize and insert words into a linked list
// note that we must ensure that there are no duplicates in our list

void loadFile()
{
 #define LINE_SIZE 256
  char input[LINE_SIZE];
  char *token = NULL;
   
  while ( fgets( input, LINE_SIZE, stdin ) )
  {
    // parse the data into separate elements
    token = strtok( input, " \t\n" );
    while ( token )
    {
      if ( !search( token ) )
        insert( token );
      token = strtok( NULL, " \t\n" );
    }
  }
}
 
// print the contents of the linked list to standard output

void printConcordance()
{
   
  char *theWord = firstItem();
  
  while ( theWord )
  { 
    printf( "%s\n", theWord );
    theWord = nextItem();
  }

}
 
int main( int argc, char *argv[] )
{
  loadFile();
  printConcordance();
  clearList();
   
  return EXIT_SUCCESS;
}
