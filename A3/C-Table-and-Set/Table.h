#ifndef _TABLE_H
#define _TABLE_H


typedef enum BOOL 
{
false,true
}Boolean ;
typedef struct TABLE Table;

  
Boolean insert( char * ,Table *);
Boolean delete( char * ,Table *);
void clearTable(Table *);
Boolean search( char * ,Table *);
void destroyTable(Table * );
Table * createTable();
void printConcordance(Table * );
void loadFile(Table *);


#endif
