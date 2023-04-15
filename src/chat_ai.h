#include "ai.h"
#include "../includes/rjsjai.h"
#ifndef CHAT_AI_H
#define CHAT_AI_H

class chat_AI:public AI {
public:
    char* msg;
    RJSJAI* ai_ptr;
    bool havefile;
    char* filename;
    chat_AI();
    chat_AI(const chat_AI* &ai);
    void sendRequest();
    void showResponse();
    ~chat_AI();
};

#endif