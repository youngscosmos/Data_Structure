#include "CircularDoublyLinkedList.h"

// Create Node
Node* CDLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

// Destroy Node
void CDLL_DestroyNode(Node* Node)
{
    free(Node);
}

// Append Node
void CDLL_AppendNode(Node** Head, Node* NewNode)
{
    if(*Head == NULL)
    {
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else
    {
        Node* Tail = (*Head)->PrevNode;

        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;

        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail;
    }
}

// Insert Node
void CDLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if(Current->NextNode != NULL)
    {
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}

// Destroy Node
void CDLL_RemoveNode(Node** Head, Node* Remove)
{
    if(*Head == Remove)
    {
        (*Head)->PrevNode->NextNode = Remove->NextNode;
        (*Head)->NextNode->PrevNode = Remove->PrevNode;
        
        *Head = Remove->NextNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else
    {
        Remove->PrevNode->NextNode = Remove->NextNode;
        Remove->NextNode->PrevNode = Remove->PrevNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

// Search Node
Node* CDLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while(Current != NULL && (--Location) >= 0)
        Current = Current->NextNode;

    return Current;
}

// Count Number of Nodes
int CDLL_GetNodeCount(Node* Head)
{
    unsigned int Count = 0;
    Node* Current = Head;

    while(Current != NULL)
    {
        Current = Current->NextNode;
        Count++;

        if(Current == Head)
            break;
    }

    return Count;
}

// Print Node
void PrintNode(Node* Node)
{
    if(Node->PrevNode == NULL)
        printf("Prev: NULL");
    else
        printf("Prev: %d", Node->PrevNode->Data);

    printf("Current: %d", Node->Data);

    if(Node->NextNode == NULL)
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", Node->NextNode->Data);
}