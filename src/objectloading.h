#ifndef OBJECTLOADING_H
#define OBJECTLOADING_H

#include "objects.h"
#include "lights.h"
#include <stdlib.h>

void loadObject(ObjectNode **, ObjectNode);
void unloadObjects(ObjectNode **);
void loadLight(LightNode **, LightNode);
void unloadLights(LightNode **);

#endif
