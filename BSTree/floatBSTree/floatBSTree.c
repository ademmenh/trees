
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

bool funcfloatBSTNodeLeaf (floatBSTNode *pBSTNode)
{
    if ( pBSTNode->LC==NULL && pBSTNode->RC==NULL )
    {
        return true;
    }
    // else
    return false;
}

void funcfloatBSTNodeFree (floatBSTNode *pBSTNode)
{
    pBSTNode->Value = 0;
    pBSTNode->LC = NULL;
    pBSTNode->RC = NULL;
    free (pBSTNode);
}




void funcfloatBSTreeInit (floatBSTree *pBSTree)
{
    (*pBSTree) = NULL;
}

bool funcfloatBSTreeEmpty (floatBSTree BSTree)
{
    if ( BSTree==NULL )
    {
        return true;
    }
    // else
    return false;
}

void funcfloatBSTreeInsert (floatBSTree *pBSTree, float value)
{

    if ( funcintBSTreeEmpty((*pBSTree)) )
    {
        (*pBSTree) = funcfloatBSTNodeCreate(value);
        return ;
    }

    if ( (*pBSTree)->Value <= value )
    {
        funcfloatBSTreeInsert (&((*pBSTree)->RC), value);
    }
    else
    {
        funcfloatBSTreeInsert (&((*pBSTree)->LC), value);
    }
}
