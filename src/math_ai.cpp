#include "math_ai.h"
#include "rjsjai.h"
#include "utils.h"
#include <iostream>
#include <fstream>

math_AI::math_AI(){
    msg=new char[100];
    filename=new char[100];
    ai_ptr = ai_create(token);
}

math_AI::math_AI(const math_AI* &ai){
    msg=ai->msg;
    filename=ai->filename;
    ai_ptr = ai_create(token);
}

void math_AI::sendRequest(){
    ai_send(ai_ptr, AI_TYPE_WOLFRAM, msg);
}

void math_AI::showResponse(){
    if(ai_status(ai_ptr)==0){
        char* dest=nullptr;
        int temp=ai_result(ai_ptr, dest);
        dest=new char[temp];
        ai_result(ai_ptr, dest);
        std::ofstream file;
        file.open(filename, std::ios::binary);
        file.write(dest, temp);
        file.close();
        delete[] dest;
    }
    else{
        ai_free(ai_ptr);
        std::cout<<"Error: "<<ai_status(ai_ptr)<<std::endl;
        throw std::runtime_error("Error!");
    }
    ai_free(ai_ptr);
}

math_AI::~math_AI(){
    delete[] msg;
    delete[] filename;
}