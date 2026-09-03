#ifndef COMPUTER_H
#define COMPUTER_H

#include "physics.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Computer{
    entity e; 
    bool hacked; 
    int amountLeftToHack; // 100 when inited
};
typedef struct Computer *Computer; 

#ifdef __cplusplus
}
#endif

#endif