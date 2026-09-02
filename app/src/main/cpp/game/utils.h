#ifndef UTILS_H
#define UTILS_H

#include "raylib.h"

struct Animation{
    Texture2D *frames; 
    int numberOfFrames; 
};
typedef struct Animation *Animation;

#ifdef __cplusplus
extern "C" {
#endif

extern Animation loadAnimation(char *path, int numberOfFrames);
extern Texture2D *loadTexturesFromDirectory(char *path, int numberOfTexs);
extern void loadDirectory();
extern void closeDirectory();

#ifdef __cplusplus
}
#endif

#endif