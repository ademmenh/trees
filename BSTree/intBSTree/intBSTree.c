
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





typedef struct intBSTree
{
    int Value;
    struct intBSTree *LC;
    struct intBSTree *RC;
} intBSTree;




void funcintBSTreeInit (intBSTree *pBSTree)
{
    pBSTree->Value = 0;
    pBSTree->LC = NULL;
    pBSTree->RC = NULL;
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