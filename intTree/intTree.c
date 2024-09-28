
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

typedef struct intTree
{
    intTNode *H;
} intTree;





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

bool funcintTNodeLeaf (intTNode TNode)
{
    if ( TNode.LC==NULL && TNode.RC==NULL )
    {
        return true;
    }
    // else
    return false;
}

void funcintTNodeFree (intTNode *pTNode)
{
    pTNode->Value = 0;
    pTNode->LC = NULL;
    pTNode->RC = NULL;
    free (pTNode);
}



void funcintTreeInit (intTree *pTree)
{
    pTree->H = NULL;
}

bool funcintTreeEmpty (intTree pTree)
{
    if (pTree.H == NULL)
    {
        return true;
    }
    // else
    return false;
}

void funcintTreeInsert (intTNode *pTNode, int value)
{

    if ( funcintNodeLeaf(*pTNode) )
    {
        intTNode *vpNew = funcintTNodeCreate (value);
        pTNode = vpNew;
    }
    else
    {
        if ( pTNode->Value <= value )
        {
            funcintTreeInsert (pTNode->RC, value);
        }
        else
        {
            funcintTreeInsert (pTNode->LC, value);
        }
    }
}
