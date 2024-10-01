
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

void funcfloatBSTreeDelete (floatBSTree *pBSTree, float value)
{

    if ( !funcfloatBSTreeEmpty(*pBSTree) )
    {

        if ( (*pBSTree)->Value == value )
        {

            if ( funcfloatBSTNodeLeaf (*pBSTree) )
            {

                floatBSTNode *vpTemp = (*pBSTree);
                (*pBSTree) = NULL;
                funcfloatBSTNodeFree (vpTemp);

            }
            else if ( (*pBSTree)->LC==NULL || (*pBSTree)->RC==NULL )
            {

                floatBSTNode *vpTemp;
                if ((*pBSTree)->LC==NULL)
                {
                    vpTemp = (*pBSTree);
                    (*pBSTree) = (*pBSTree)->RC;
                    funcfloatBSTNodeFree (vpTemp);
                }
                else
                {
                    vpTemp = (*pBSTree);
                    (*pBSTree) = (*pBSTree)->LC;
                    funcfloatBSTNodeFree (vpTemp);
                }

            }
            else
            {
                // searching for the max of mins

                // in this case the BSTNode has two childs
                // we use two pointers two pointers, one for swaping values and one for seting the BSTNode pointer
                floatBSTNode *vpCnBefore, *vpCn;
                vpCnBefore = (*pBSTree);
                vpCn = (*pBSTree)->LC;

                while ( vpCn->RC!=NULL )
                {
                    vpCnBefore = vpCn;
                    vpCn = vpCn->RC;
                }



                // spwaping
                (*pBSTree)->Value = vpCn->Value;
                // handling the case where the vpCnBefore is the head of the tree
                if ( vpCnBefore == (*pBSTree) )
                {
                    vpCnBefore->LC = vpCn->LC;
                }
                else
                {
                    vpCnBefore->RC = NULL;
                }
                // free space after permutation
                funcfloatBSTNodeFree (vpCn);

            }
            
            
            return ;
        }





        if ( value < (*pBSTree)->Value )
        {
            funcfloatBSTreeDelete (&((*pBSTree)->LC), value);
        }
        else
        {
            funcfloatBSTreeDelete (&((*pBSTree)->RC), value);
        }
    }
}


int funcfloatInput ()
{
    float vfInput;
    printf ("Enter your value: ");
    scanf ("%f", &vfInput);
    
    return vfInput;
}

void funcfloatBSTreeCreate (floatBSTree *pBSTree, int TreeSize)
{
    int viCn;
    float vfInput;
    for ( viCn=0; viCn<TreeSize; viCn++ )
    {
        vfInput = funcfloatInput ();
        funcfloatBSTreeInsert (pBSTree, vfInput);
    }
}

void funcfloatBSTreeDisplay (floatBSTree BSTree)
{
    if ( !funcfloatBSTreeEmpty(BSTree) )
    {
        printf ("%f ", BSTree->Value);
        funcintBSTreeDisplay (BSTree->LC);
        funcintBSTreeDisplay (BSTree->RC);
    }

}


