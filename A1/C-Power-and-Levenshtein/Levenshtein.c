    // NAME: Mostafa Raad Kamal       
    // COURSE: COMP 2160, SECTION: A02    
    // INSTRUCTOR: Franklin Bristow     
    // ASSIGNMENT: assignment 1, QUESTION: question 2     
    //      
    // REMARKS: The purpose of this program is to perform Levenshtein algorithm in C language.


#include <stdio.h>
#include <assert.h>
#include <string.h>

int testsFailed=0;
int testsExecuted=0;

void testDistance( char [], char [], int  );
int levenshtein( char [], char [] );
int mfunc( int [], int);
int main (void)

{
    {   
        printf( "Testing typical cases.\n\n" );
        testDistance( "kitten", "kitten", 0 );
        testDistance( "kitten", "sitting", 3 );
        testDistance( "kitten", "mittens", 2 );
        testDistance( "balloon", "saloon", 2 );
        testDistance( "hello", "doggo", 4 );
        testDistance( "\t\thi", "\t\t\t\thi", 2 );

        printf( "\n\nTesting empty/edge cases.\n\n" );
        testDistance( "", "", 0 );
        testDistance( "hello", "", 5 );
        testDistance( "", "doggo", 5 );
        testDistance( "a", "b", 1 );
        testDistance( "b", "b", 0 );
        testDistance( " ", " ", 0 );

        printf( "\nThis might take a while...\n\n" );
        testDistance( "12345678901", "123456789012", 1 );   // how many chars are we looking at?

        printf( "\nThese tests will not succeed in the C version\n\n" );
        testDistance( "kitten", "mitten\0s", 3 );           // ????
        testDistance( "\0totally", "\0different", 9 );

        printf( "\nTotal number of tests executed: %d\n", testsExecuted );
        printf( "Number of tests passed: %d\n", (testsExecuted - testsFailed) );
        printf( "Number of tests failed: %d\n", testsFailed );
    }
    return 0;

}
void testDistance( char s[], char t[], int expected )
    {   
    
    
        int distance = levenshtein( s, t );

        if ( distance == expected )
        {
            printf( "Passed! You can get from %s to %s in %d  moves.\n",s,t,expected);
        }
        else
        {
            printf( "FAILED: I thought it would take %d moves, but apparently it takes %d  moves to get from  %s to %s\n" ,expected,distance,s,t);
            testsFailed++;
        }

        testsExecuted++;
    }
        


    int levenshtein( char iNs[], char iNt[] )
    
         {
        int cost;
        int distance;

        char deleteS [20]="\0"; 
        char deleteT [20]="\0";
        
        

        
        assert( iNs != NULL );
        assert( iNt != NULL );

        if(strlen(iNs) == 0)
        {
            distance=strlen(iNt);
        }
        else if(strlen(iNt) == 0)
        {
            distance=strlen(iNs);
        }
        else
        {  
            if (iNs[0] == iNt[0])
            { 
                cost = 0;
            }
            else
            {
        
                cost = 1;

            }
            
            strncpy(deleteS, ((iNs)+1),strlen(iNs+1));
            strncpy(deleteT, ((iNt)+1),strlen(iNt+1));
            
            
           /* printf("%s Real\n",iNs);
            printf("%s Copy\n",deleteS);
            printf("%d CopyLen and %d RealLen\n",strlen(deleteS),strlen(iNs)-1); */
                   
            assert(strlen(deleteS)==strlen(iNs)-1);
            assert(strlen(deleteT)==strlen(iNt)-1);

         //   printf("This is %s and %s\n",(strstr(iNs,iNs[strlen(iNs)-strlen(deleteS)])),deleteS);
            assert(strstr(iNs,deleteS)!=NULL);
            assert(strstr(iNt,deleteT)!=NULL);

           

int mini[3]={ levenshtein(deleteS, iNt) + 1,
                               levenshtein(iNs, deleteT) + 1,
                                       levenshtein(deleteS, deleteT) + cost };
                   
                    distance = mfunc(mini,sizeof(mini)/sizeof(mini[0]));
        }

        return distance;
    }

    int  mfunc(int minimum[],int size)
    {   
        int min = 0;
        assert( size > 0 );
        if ( size > 0 )
        {
            min = minimum[0];

            int i=0;
            for (i=1;i<size;i++)
            {
                if ( minimum[i] < min )
                {
                   min = minimum[i];
                }
            }
        }

        return min;
    }

    
