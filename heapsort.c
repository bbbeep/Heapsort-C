// Jeremy McCormick
// CS201 University Of Alabama
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "heap.h"



int ProcessOptions(int a , char** b);
void Fatal(char *fmt, ...);
void printOptionV();

int isAscending=1;


int main (int argc, char **argv)
{
	
    int numToSort=0;
    int argIndex;

    if (argc == 1)
        Fatal("%d arguments!\n",argc-1);

    argIndex = ProcessOptions(argc,argv);

    Heap* heap = newHeap(isAscending);

    char* filename = argv[argIndex];
    FILE* file = fopen(filename,"r");

    if(file == NULL)
    {
        Fatal("%s, file not found",filename);
    }

    int val;
    while(fscanf(file,"%d ",&val)>0)
    {
        add(heap, val);
        numToSort++;
    }
    fclose(file);


    if(numToSort>0)
	makeHeap(heap);

    while(numToSort>0)
    {
        int value = extractTop(heap);
        printf("%d ",value);
        numToSort--;
    }
    printf("\n");
    return 0;
}


int ProcessOptions(int argc, char **argv)
{
    int argIndex;
    int argUsed;
    int separateArg;
    //char *arg;

    argIndex = 1;

    while (argIndex < argc && *argv[argIndex] == '-')
        {
        /* check if stdin, represented by "-" is an argument */
        /* if so, the end of options has been reached */
        if (argv[argIndex][1] == '\0') return argIndex;

        separateArg = 0;
        argUsed = 0;

        if (argv[argIndex][2] == '\0')
            {
            //arg = argv[argIndex+1];
            separateArg = 1;
            }
        //else
            //arg = argv[argIndex]+2;

        switch (argv[argIndex][1])
            {
            /*
             * when option has an argument, do this
             *
             *     examples are -m4096 or -m 4096
             *
             *     case 'm':
             *         MemorySize = atol(arg);
             *         argUsed = 1;
             *         break;
             *
             *
             * when option does not have an argument, do this
             *
             *     example is -a
             *
             *     case 'a':
             *         PrintActions = 1;
             *         break;
             */

            case 'v':
            case 'V':
                printOptionV();
                exit(42);
            case 'd':
            case 'D':
                isAscending = 0;
                break;
            default:
                Fatal("option %s not understood\n",argv[argIndex]);
            }

        if (separateArg && argUsed)
            ++argIndex;

        ++argIndex;
        }

    return argIndex;
}

void Fatal(char *fmt, ...)
{
    va_list ap;

    fprintf(stderr,"An error occured: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    exit(-1);
}

/* only -oXXX  or -o XXX options */

void printOptionV()
{
    printf("Jeremy McCormick  CS201\n\n"
"This program implements heapsort using a non-array based implentation\n"	
"while maintaining \u0398(nlog(n)) time\n"
"It builds the unordered heap using a queue to create a complete tree,\n"
"then it builds the heap using a bottom up approach\n"
"The adding to create an unordered heap takes \u0398(n) and the build-heap\n" 
"operation also takes \u0398(n), yielding\n"
"\u0398(2n)=\u0398(n)\n"
"Then we run the extraction process. Being based on a non-array based tree, I\n"
"needed a stack of the level order of the tree\n"
"to keep track of leaf nodes for the extraction process. This level order\n"
"traversal takes \u0398(n) time. Each extraction takes \u0398(log(n))\n"
"and must be done a total of n times, yeilding \u0398(n)+\u0398(nlog(n))=\u0398(nlog(n))\n"
"for the whole process. Then for the whole sort we have\n"
"\u0398(n)+\u0398(nlog(n))=\u0398(nlog(n))\n\n");

printf( "   n  |Time(usec)\n "
	"    10|28\n"
	"   100|63\n"
	"  1000|450\n"
	" 10000|5338\n"
	"100000|84846\n");
}
