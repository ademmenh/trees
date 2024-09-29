
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

