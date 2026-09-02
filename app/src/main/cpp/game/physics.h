#ifndef PHYSICS_H
#define PHYSICS_H

#include "raylib.h"
#include "hash.h"


struct entity{
  Vector2 pos; 
  Rectangle rect; 
};
typedef struct entity *entity;

#ifdef __cplusplus
extern "C" {
#endif

extern entity entityCreate(float startX, float startY, int width, int height);
extern bool update(entity e, hash map, Vector2 newPos);

#ifdef __cplusplus
}
#endif

#endif