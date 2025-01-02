#include "SinglyLinkedList.h"

int main(void)
{
    int     i = 0;
    int     Count = 0;
    Node*   List = NULL;
    Node*   Current = NULL;
    Node*   NewNode = NULL;

    // Add Five Nodes
    for(i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }
    
    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);
   
   // Print List
   Count = SLL_GetNodeCount(List);
   for(i = 0; i < Count; i++)
   {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
   }

   // Insert List
   Current = SLL_GetNodeAt(List, 2);
   NewNode = SLL_CreateNode(3000);

   SLL_InsertAfter(Current, NewNode);

   // Print List
   Count = SLL_GetNodeCount(List);
   for(i = 0; i < Count; i++)
   {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
   }

   //Destroy All Nodes
   for(i = 0; i < Count; i++)
   {
        Current = SLL_GetNodeAt(List, 0);

        if(Current != NULL)
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
   }

   return 0;
}