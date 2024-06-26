#include "objectloading.h"
#include "objects.h"
#include "lights.h"
#include <stdlib.h>

void loadObject(ObjectNode **prevHead, ObjectNode object)
{
    ObjectNode *head = malloc(sizeof(ObjectNode));
    *head = object;
    head->next = *prevHead;
    *prevHead = head;
}

void unloadObjects(ObjectNode **head)
{
    ObjectNode *next;
    while (*head != NULL)
    {
        next = (*head)->next;
        free(*head);
        *head = next;
    }
}

void loadLight(LightNode **prevHead, LightNode light)
{
    LightNode *head = malloc(sizeof(LightNode));
    *head = light;
    head->next = *prevHead;
    *prevHead = head;
}

void unloadLights(LightNode **head)
{
    LightNode *next;
    while (*head != NULL)
    {
        next = (*head)->next;
        free(*head);
        *head = next;
    }
}
