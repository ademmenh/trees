
#ifndef _intBSTREE_C
    #define _intBSTREE_C
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





typedef struct intBSTNode
{
    int Value;
    struct intBSTNode *LC;
    struct intBSTNode *RC;
} intBSTNode;

typedef intBSTNode* intBSTree;




void funcintBSTNodeInit (intBSTNode *pBSTNode)
{
    pBSTNode->Value = 0;
    pBSTNode->LC = NULL;
    pBSTNode->RC = NULL;
}

intBSTNode* funcintBSTNodeCreate (int value)
{
    intBSTNode *vpNew = (intBSTNode *) malloc(sizeof(intBSTNode));
    if ( vpNew==NULL )
    {
        printf ("The Allocation has failled !!!");
        exit (1);
    }

    funcintDNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}

bool funcintBSTNodeLeaf (intBSTNode *pBSTNode)
{
    if ( pBSTNode->LC==NULL && pBSTNode->RC==NULL )
    {
        return true;
    }
    // else
    return false;
}



void funcintBSTreeInit (intBSTree *pBSTree)
{
    pBSTree = NULL;
}

bool funcintBSTreeEmpty (intBSTree *pBSTree)
{
    if ( pBSTree==NULL )
    {
        return true;
    }
    // else
    return false;
}

