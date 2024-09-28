
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
    int Value;
    struct intTNode *LC;
    struct intTNode *RC;
} intTNode;



void funcintTNodeInit (intTNode *pTNode)
{
    pTNode->Value = 0;
    pTNode->LC = NULL;
    pTNode->RC = NULL;
}

intTNode* funcintTNodeCreate (int value)
{

    intTNode *vpNew = (intTNode*) malloc (sizeof(intTNode));
    if ( vpNew == NULL )
    {
        printf ("the allocation has failled !\n");
        exit (1);
    }

    funcintTNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}

void funcintTNodeFree (intTNode *pTNode)
{
    pTNode->Value = 0;
    pTNode->LC = NULL;
    pTNode->RC = NULL;
    free (pTNode);
}




