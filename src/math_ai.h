#include "ai.h"
#include "../includes/rjsjai.h"
#ifndef MATH_AI_H
#define MATH_AI_H

class math_AI:public AI {
public:
    char* msg;
    char* filename;
    RJSJAI* ai_ptr;
    math_AI();
    math_AI(const math_AI* &ai);
    void sendRequest();
    void showResponse();
    ~math_AI();
};

#endif