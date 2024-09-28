
#ifndef _intTREE_C
    #define _intTREE_C
#endif

#ifndef _STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif





typedef struct intTNode
{
    int value;
    struct intTNode *LC;
    struct intTNode *RC;
} intTNode;





