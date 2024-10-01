
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


void funcfloatBSTNodeInit (floatBSTNode *pBSTNode)
{
    pBSTNode->Value = 0.0;
    pBSTNode->LC = NULL;
    pBSTNode->RC = NULL;
}


floatBSTNode* funcfloatBSTNodeCreate (float value)
{

    floatBSTNode *vpNew = (floatBSTNode *) malloc(sizeof(floatBSTNode));
    if ( vpNew==NULL )
    {
        printf ("The Allocation has failled !!!");
        exit (1);
    }


    funcintBSTNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}


void funcfloatBSTNodeFree (floatBSTNode *pBSTNode)
{
    pBSTNode->Value = 0;
    pBSTNode->LC = NULL;
    pBSTNode->RC = NULL;
    free (pBSTNode);
}


