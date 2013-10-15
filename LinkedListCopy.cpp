#include<iostream>
#include<stdlib.h>

using std::cin;
using std::cout;

struct Node
{
    int value;
    struct Node* next;
    struct Node* random;
};

void PrintLinkedList(Node* header)
{
    Node* pt = header;
    while(pt != NULL)
    {
        cout << pt->value;
        Node* prd = pt->random;
        if(prd != NULL)
        cout << "  " << prd->value << std::endl;
        pt = pt->next;
    }
}

Node* LinkedListDeepCopy(Node* linkList)
{
    if(linkList == NULL)
        return NULL;

    Node* pt = linkList;
    while(pt != NULL)
    {
        Node* node = (Node*)malloc(sizeof(Node));
        node->value = pt->value;
        node->next = pt->next;
        pt->next = node;
        pt = node->next;
    }
    
    Node* pOld = linkList;
    Node* pNew = pOld->next;
    while(pOld != NULL)
    {
        pNew = pOld->next;
        pNew->random = pOld->random->next;
        pOld = pNew->next;
    }
    
    pOld = linkList;
    pNew = pOld->next;
    Node* newLinkList = linkList->next;
    while(pOld != NULL)
    {
        pNew = pOld->next;
        pOld->next = pNew->next;
        pNew->next = pOld->next;
        pOld = pOld->next;
    }
    
    return newLinkList;
}

int main()
{
    Node* n = (Node*)malloc(5 * sizeof(Node));
    
    n[0].value = 0;
    n[0].next = &n[1];
    n[0].random = &n[3];
    
    n[1].value = 1;
    n[1].next = &n[2];
    n[1].random = &n[2];
    
    n[2].value = 2;
    n[2].next = &n[3];
    n[2].random = &n[1];
    
    n[3].value = 3;
    n[3].next = &n[4];
    n[3].random = &n[2];
    
    n[4].value = 4;
    n[4].next = NULL;
    n[4].random = &n[3];
    
    Node* newLinkedList = LinkedListDeepCopy(n);
    PrintLinkedList(newLinkedList);
    
    cin.get();
    return 0;
}