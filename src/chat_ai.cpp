#include "chat_ai.h"
#include "../includes/rjsjai.h"
#include "utils.h"
#include <iostream>
#include <fstream>

chat_AI::chat_AI(){
    msg=new char[100];
    filename=new char[100];
    havefile=false;
    ai_ptr = ai_create(token);
}

chat_AI::chat_AI(const chat_AI* &ai){
    msg=ai->msg;
    std::cout<<msg<<std::endl;
    ai_ptr = ai_create(token);
}

void chat_AI::sendRequest(){
    ai_send(ai_ptr, AI_TYPE_CHAT, msg);
}

void chat_AI::showResponse(){
    if(ai_status(ai_ptr)==0){
        char* dest=nullptr;
        int temp=ai_result(ai_ptr, dest);
        dest=new char[temp];
        ai_result(ai_ptr, dest);
        if(havefile){
            std::ofstream file;
            file.open(filename);
            file<<dest;
            file.close();
        }
        else
            std::cout<<dest<<std::endl;
        delete[] dest;
    }
    else{
        ai_free(ai_ptr);
        std::cout<<"Error: "<<ai_status(ai_ptr)<<std::endl;
        throw std::runtime_error("Error!");
    }
    ai_free(ai_ptr);
}

chat_AI::~chat_AI(){
    delete[] msg;
    delete[] filename;
}