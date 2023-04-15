#include "ai.h"
#include "../includes/rjsjai.h"
#ifndef DRAW_AI_H
#define DRAW_AI_H

class draw_AI:public AI {
public:
    char* msg;
    char* filename;
    RJSJAI* ai_ptr;
    draw_AI();
    draw_AI(const draw_AI* &ai);
    void sendRequest();
    void showResponse();
    ~draw_AI();
};

#endif