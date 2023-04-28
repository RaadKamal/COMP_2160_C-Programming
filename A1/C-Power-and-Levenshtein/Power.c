    // NAME: Mostafa Raad Kamal     
    // COURSE: COMP 2160, SECTION: A02    
    // INSTRUCTOR: Franklin Bristow     
    // ASSIGNMENT: assignment 1, QUESTION: question 1     
    //      
    // REMARKS: The purpose of this program is to generate Power algorithm in C language.


#include <stdio.h>
#include <string.h>

int COUNT=0;

double power1(double base, int index);
double power2(double base, int index);

int main(void)
{
      { 
        double base []  = { 1.4, 1.3, 1.2, 1.1 };
        int index [] = { 5, 20, 63, 73 };
        double value;
        
       

        printf( "\nTest two algorithms for powering\n\n" );
    
        
        for( int i=0 ; i<(sizeof(base)/sizeof(base[0])) ; i++ )
        {
        COUNT=0;
        value = power1( base[i], index[i] );
        printf( "1: %.2f ^ %d = %lf, used  %d multiples\n" ,base[i], index[i], value, COUNT );
       
        COUNT=0;
        value = power2( base[i], index[i] );
        printf( "2: %.2f ^ %d = %lf, used  %d multiples\n" ,base[i], index[i], value, COUNT );
        printf("\n");
        }

        printf( "\nEnd of processing" );
      }
    
     return 0;

}

double power1(double base, int index)
{
      double retValue;

        if( index == 0 )
        {
            retValue = 1;
        }
        else
        {
            retValue = base * power1( base, index-1 );
            COUNT++;
        }

        return retValue;
}

double power2(double base, int index)
 {
        double retValue;
        double temp;

        if( index == 0 )
        {
            retValue = 1;
        }
        else if( index%2 == 1 )
        {
            retValue = base * power2( base, index-1 );
            COUNT++;
        }
        else
        {
            temp = power2( base, index/2 );
            retValue = temp*temp;
            COUNT++;
        }

        return retValue;
    }


