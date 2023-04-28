    // NAME: Mostafa Raad Kamal       
    // COURSE: COMP 2160, SECTION: A02    
    // INSTRUCTOR: Franklin Bristow     
    // ASSIGNMENT: Assignment 3, QUESTION: Question 2     
    //      
    // REMARKS: The purpose of this program to create a test suit for different sets program.

#include <stdio.h>
#include "set.h"

int  main()
{


printf("   **********************************************************************************************************\n");


Set *First=newSet();
deleteSet(First);
Boolean check=0;
check=validateMemUse();
if(check==1){printf("                                           No sets currently exist  \n\n");}
else{printf("      		                     There is an memory issue or problem in a function\n\n");}



Set *newA = newSet();
Set *newB = newSet();
Set *newC = newSet();
Set *newD = newSet();
Set *newE = newSet();
Set *newF = newSet();
Set *newG = newSet();
Set *newH = newSet();
Set *newK = newSet();
Set *newP = newSet();

int pass=0;
int fail=0;

Boolean value;

insertItem(newA,10);
insertItem(newA,20);
insertItem(newA,30);
insertItem(newA,40);
insertItem(newA,50);

removeItem(newA,50);

insertItem(newB,40);
insertItem(newB,50);
insertItem(newB,60);
insertItem(newB,70);
insertItem(newB,80);

insertItem(newC,40);
insertItem(newC,50);
insertItem(newC,60);
insertItem(newC,70);
insertItem(newC,80);

char *string="PASSED";

printf("\n");
printf("	                  Correct Expectation | Function Provided Value | Status\n");     


   
printf("EQUALITY TEST\n");

value=equals(newA,newB);
if(value!=0)
 {string="FAILED !";fail++;}
else
 {pass++;} 
printf("A and B equality. It should be    False 		%u                 %s\n",value,string);
string="PASSED";


value=equals(newB,newC);
if(value!=1)
 {string="FAILED !";fail++;}
else
 {pass++;}
printf("B and C equality. It should be    True 		        %u                 %s\n\n",value,string);
string="PASSED";




printf("REMOVE AND INSERTATION TEST\n");


removeItem(newC,70);
value=equals(newB,newC);
printf("One element is removed from C\n");
if(value>0)
	{string="FAILED !";fail++;}
else
	{pass++;}
printf("B and C equality. Now it is       False		        %u                 %s\n",value,string);
string="PASSED";


insertItem(newA,50);
removeItem(newB,80);
removeItem(newB,70);
removeItem(newB,60);
removeItem(newA,10);
removeItem(newA,20);
removeItem(newA,30);
value=equals(newA,newB);
if(value==0)
	{string="FAILED !";fail++;}
else
	{pass++;}
printf("A and B has been edited and made\nthem similiar by using removing and \ninsertaion\n");
printf("Now A and B equality should be    True		       	%u                 %s\n\n",value,string);
string="PASSED";





printf("UNION TEST\n");


newD=unionOf(newH,newB);
value=equals(newD,newB);
if(value==0)
	{string="FAILED !";fail++;}
else
	{pass++;}
printf("First H is an emptied set then H\nhas unioned with B and created \nthe new set D\n");
printf("D and B equality                  True		        %u                 %s\n",value,string);
string="PASSED";

value=equals(newD,newH);
if(value!=0)
	{string="FAILED !";fail++;}
else
	{pass++;}
printf("D and H equality  	          False 	        %u                 %s\n\n",value,string);
string="PASSED";




printf("INTERSECTION TEST\n");


insertItem(newD,40);
insertItem(newD,50);
printf("D has been edited and now contain\nthe same elements of A \ninsectioned B\n");
value=equals(intersectionOf(newA,newB),newD);
if(value==0)
	{string="FAILED !";fail++;}
else
	{pass++;}
printf("Intersec A & B and D equality     True 		        %u                 %s\n\n",value,string);
string="PASSED";





printf("DIFFERENCE TEST\n");


insertItem(newE,40);
insertItem(newE,50);
insertItem(newK,50);
insertItem(newP,40);
value=equals(differenceOf(newE,newK),newP);
printf("Difference of E and K then new P\nset is created and made it simliar \nto their Difference\n");
if(value==0)
	{string="FAILED !";fail++;}
else
	{pass++;}
printf("Differ of E & K equals to P       True 		        %u                 %s\n",value,string);
string="PASSED";

value=equals(differenceOf(newA,newC),newB);
if(value>0)
	{string="FAILED !";fail++;}
else
	{pass++;}
printf("Differ of E & K equals to B       False                 %u                 %s\n\n",value,string);
string="PASSED";





printf("EMPTY SET AND DUPLICATE TEST\n");


value=equals(newF,newF);
if(value==0)
	{string="FAILED !";fail++;}
else
	{pass++;}
printf("F is a new set\n");
printf("F equals F                        True                  %u                 %s\n",value,string);
string="PASSED";


insertItem(newF,100);
insertItem(newF,100);
insertItem(newF,0);
insertItem(newF,0);
insertItem(newG,100);
insertItem(newG,0);
value=equals(newF,newG);
if(value==0)
	{string="FAILED !";fail++;}
else
	{pass++;}
printf("F has now duplicate items, Double\n100 and Double 0 but G has non \nduplicate 100 and 0 \n");
printf("F equals G                        True                  %u                 %s\n\n",value,string);
string="PASSED";

                       



printf("DELETION TEST\n");



deleteSet(newC);
deleteSet(newB);
deleteSet(newD);
deleteSet(newE);
deleteSet(newF);
deleteSet(newG);
deleteSet(newP);
deleteSet(newK);
deleteSet(newA);
deleteSet(newH);
check=validateMemUse();
if(check!=0)
	{string="FAILED !";fail++;}
else
	{pass++;}
printf("Set exists that can't be deleted  False   	        %u                 %s\n\n",check,string);

printf("Test passes %d , Test fails %d\n\n",pass,fail);


return 0;

}
