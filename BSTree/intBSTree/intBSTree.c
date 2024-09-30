
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


    funcintBSTNodeInit (vpNew);
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

void funcintBSTNodeFree (intBSTNode *pBSTNode)
{
    pBSTNode->Value = 0;
    pBSTNode->LC = NULL;
    pBSTNode->RC = NULL;
}



void funcintBSTreeInit (intBSTree *pBSTree)
{
    (*pBSTree) = NULL;
}

bool funcintBSTreeEmpty (intBSTree BSTree)
{
    if ( BSTree==NULL )
    {
        return true;
    }
    // else
    return false;
}



int funcintInput ()
{
    int viInput;
    printf ("Enter your value: ");
    scanf ("%d", &viInput);
    
    return viInput;
}

void funcintBSTreeInsert (intBSTree *pBSTree, int value)
{

    if ( funcintBSTreeEmpty((*pBSTree)) )
    {
        (*pBSTree) = funcintBSTNodeCreate(value);
        return ;
    }

    if ( (*pBSTree)->Value <= value )
    {
        funcintBSTreeInsert (&((*pBSTree)->RC), value);
    }
    else
    {
        funcintBSTreeInsert (&((*pBSTree)->LC), value);
    }
}

void funcintBSTreeCreate (intBSTree *pBSTree, int TreeSize)
{
    int viCn;
    int viInput;
    for ( viCn=0; viCn<TreeSize; viCn++ )
    {
        viInput = funcintInput ();
        funcintBSTreeInsert (pBSTree, viInput);
    }
}

void funcintBSTreeDisplay (intBSTree BSTree)
{
    if ( !funcintBSTreeEmpty(BSTree) )
    {
        printf ("%d ", BSTree->Value);
        funcintBSTreeDisplay (BSTree->LC);
        funcintBSTreeDisplay (BSTree->RC);
    }

}

void funcintBSTreeDelete (intBSTree *pBSTree, int value)
{

    if ( !funcintBSTreeEmpty(*pBSTree) )
    {

        if ( (*pBSTree)->Value == value )
        {

            if ( funcintBSTNodeLeaf (*pBSTree) )
            {

                intBSTNode *vpTemp = (*pBSTree);
                (*pBSTree) = NULL;
                funcintBSTNodeFree (vpTemp);

            }
            else if ( (*pBSTree)->LC==NULL || (*pBSTree)->RC==NULL )
            {

                intBSTNode *vpTemp;
                if ((*pBSTree)->LC==NULL)
                {
                    vpTemp = (*pBSTree);
                    (*pBSTree) = (*pBSTree)->RC;
                    funcintBSTNodeFree (vpTemp);
                }
                else
                {
                    vpTemp = (*pBSTree);
                    (*pBSTree) = (*pBSTree)->LC;
                    funcintBSTNodeFree (vpTemp);
                }

            }
            else
            {
                // searching for the max of mins
                intBSTNode *vpCn = (*pBSTree)->LC;
                while ( vpCn->RC!=NULL )
                {
                    vpCn = vpCn->RC;
                }

                (*pBSTree)->Value = vpCn->RC->Value;
                funcintBSTNodeFree (vpCn->RC);
                vpCn->RC = NULL;
            }
            
            return ;
        }



        if ( value < (*pBSTree)->Value )
        {
            funcintBSTreeDelete (&((*pBSTree)->LC), value);
        }
        else
        {
            funcintBSTreeDelete (&((*pBSTree)->RC), value);
        }
    }
}



int main ()
{
    intBSTree vtIntigers;
    funcintBSTreeInit (&vtIntigers);

    funcintBSTreeCreate (&vtIntigers, 5);
    funcintBSTreeDisplay (vtIntigers);
    printf ("\n");
    funcintBSTreeDelete (&vtIntigers, 10);
    funcintBSTreeDisplay (vtIntigers);
    return 0;
}
