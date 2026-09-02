#pragma once

#include "raylib.h"

class Entity {
public:
    Entity(float x, float y, float w, float h) {
        pos = { x, y };
        rect = { x, y, w, h };
    }
    virtual ~Entity() {}

    virtual void Update(float dt) = 0;
    virtual void Draw() = 0;

    Vector2 pos;
    Rectangle rect;
};
