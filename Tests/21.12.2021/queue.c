#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int key;
    int value;
    int count;
    struct Node* parent;
    struct Children* children;
} Node;

typedef struct Nodes
{
    Node* root;
    struct Nodes* next;
} Nodes;

typedef struct Children
{
    Node* child;
    struct Children* next;
} Children;

typedef struct Queue
{
    Nodes* nodes;
} Queue;

typedef enum ErrorCode{
    SUCCESFULLY,
    QUEUE_IS_NULL,
    MEMORY_ALLOCATION_ERROR,
    ADD_ROOT_FAILED,
}ErrorCode;

Queue* createQueue(void)
{
    return calloc(1, sizeof(Queue));
}

Node* createNode(const int key, const int value)
{
    Node* node = calloc(1, sizeof(node));
    if (node != NULL)
    {
        node->value = value;
        node->key = key;
        node->count = 1;
    }
    return node;
}

Nodes* createNodes()
{
    return calloc(1, sizeof(Nodes));
}

ErrorCode addRoot(Queue* queue,Node* node)
{
    if (queue == NULL)
    {
        return;
    }
    if (queue->nodes == NULL)
    {
        queue->nodes = createNodes();
        queue->nodes->root = node;
        return SUCCESFULLY;
    }
    for (Nodes* i = queue->nodes; i->next != NULL; i = i->next)
    {
        if (i->next == NULL)
        {
            i->next = createNodes();
            i->next->root = node;
            return SUCCESFULLY;
        }
    }
    return ADD_ROOT_FAILED;
}

void merge(Queue* queue, Nodes* firstNodes, Nodes* SecondNodes)
{
    Nodes* previousNodes = NULL;
    if (queue->nodes != firstNodes)
    {
        Nodes* previousNodes = queue->nodes;
        while (previousNodes->next != firstNodes)
        {
            previousNodes = previousNodes->next;
        }
    }

}

ErrorCode convertNodes(Queue* queue)
{
    if (queue == NULL)
    {
        return QUEUE_IS_NULL;
    }
    if (queue->nodes == NULL || queue->nodes->next == NULL)
    {
        return SUCCESFULLY;
    }
    Nodes* firstNodes = queue->nodes;
    Nodes* secondNodes = queue->nodes->next;
    while (secondNodes != NULL)
    {
        if (firstNodes->root->count == secondNodes->root->count)
        {
            merge(queue, firstNodes, secondNodes);
            firstNodes = queue->nodes;
            secondNodes = queue->nodes->next;
            continue;
        }
        firstNodes = secondNodes;
        secondNodes = secondNodes->next;
    }
    return SUCCESFULLY;
}

ErrorCode enqueue(Queue* queue, const int key, const int value)
{
    if (queue == NULL)
    {
        return QUEUE_IS_NULL;
    }
    Node* node = createNode(key, value);
    if (node == NULL)
    {
        return MEMORY_ALLOCATION_ERROR;
    }
    addRoot(queue, node);
    
}