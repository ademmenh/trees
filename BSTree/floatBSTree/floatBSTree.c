
#define _floatBSTREE_C

#ifndef _STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif





typedef struct floatBSTNode
{
    float Value;
    struct floatBSTNode *LC;
    struct floatBSTNode *RC;
} floatBSTNode;

typedef floatBSTNode* floatBSTree;



