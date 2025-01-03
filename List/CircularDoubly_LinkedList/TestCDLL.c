#include "CircularDoublyLinkedList.h"

int main(void)
{
    int     i = 0;
    int     Count = 0;
    Node*   List = NULL;
    Node*   NewNode = NULL;
    Node*   Current = NULL;

    // Append 5 Nodes
    for(i = 0; i < 5; i++)
    {
        NewNode = CDLL_CreateNode(i);
        CDLL_AppendNode(&List, NewNode);
    }    

    // Print List
    Count = CDLL_GetNodeCount(List);
    for(i = 0; i < Count; i++)
    {
        Current = CDLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    // Insert Node
    Current = CDLL_GetNodeAt(List, 2);
    NewNode = CDLL_CreateNode(3000);
    CDLL_InsertAfter(Current, NewNode);

    // Remove Node  
    Current = CDLL_GetNodeAt(List, 2);
    CDLL_RemoveNode(&List, Current);
    CDLL_DestroyNode(Current);

    // Print List
    Count = CDLL_GetNodeCount(List);
    for(i = 0; i < Count*2; i++)
    {
        if(i == 0)
            Current = List;
        else
            Current = Current->NextNode;

        printf("List[%d] : %d\n", i, Current->Data);
    }

    // Remove All Nodes
    Count = CDLL_GetNodeCount(List);

    for(i = 0; i < Count; i++)
    {
        Current = CDLL_GetNodeAt(List, 0);

        if(Current != NULL)
        {
            CDLL_RemoveNode(&List, Current);
            CDLL_DestroyNode(Current);
        }
    }

    return 0;
}