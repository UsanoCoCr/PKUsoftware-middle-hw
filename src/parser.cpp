#include "parser.h"
#include "ai.h"
#include "chat_ai.h"
#include "draw_ai.h"
#include "math_ai.h"
#include <iostream>
#include <cstring>
#include <assert.h>

AI* Parser::parse(int argc, char** argv){
    if (argc==1){
        throw std::runtime_error("No parameter input");
        return nullptr;
    }

    else if (argc==3){//--chat without -o or --output
        if (strcmp(argv[1],"--chat")==0){
            if (argv[2][0]=='-'){
                throw std::runtime_error("Parameter input error");
                return nullptr;
            }
            chat_AI* ai=new chat_AI;
            strcpy(ai->msg,argv[2]);
            return ai;
        }
        else{
            throw std::runtime_error("Parameter input error");
            return nullptr;
        }
    }

    else if (argc==5){
        if (strcmp(argv[1],"--chat")==0){
            chat_AI* ai=new chat_AI;
            strcpy(ai->msg,argv[2]);
            if (strcmp(argv[3],"-o")==0 || strcmp(argv[3],"--output")==0){
                ai->havefile=true;
                strcpy(ai->filename,argv[4]);
            }
            else{
                throw std::runtime_error("Parameter input error");
                return nullptr;
            }
            return ai;
        }
        else if (strcmp(argv[3],"--chat")==0){
            chat_AI* ai=new chat_AI;
            strcpy(ai->msg,argv[4]);
            if (strcmp(argv[1],"-o")==0 || strcmp(argv[1],"--output")==0){
                ai->havefile=true;
                strcpy(ai->filename,argv[2]);
            }
            else{
                throw std::runtime_error("Parameter input error");
                return nullptr;
            }
            return ai;
        }
        else if (strcmp(argv[1],"--draw")==0){
            draw_AI* ai=new draw_AI;
            strcpy(ai->msg,argv[2]);
            if (strcmp(argv[3],"-o")==0 || strcmp(argv[3],"--output")==0)
                strcpy(ai->filename,argv[4]);
            else{
                throw std::runtime_error("Parameter input error");
                return nullptr;
            }
            return ai;
        }
        else if (strcmp(argv[3],"--draw")==0){
            draw_AI* ai=new draw_AI;
            strcpy(ai->msg,argv[4]);
            if (strcmp(argv[1],"-o")==0 || strcmp(argv[1],"--output")==0)
                strcpy(ai->filename,argv[2]);
            else{
                throw std::runtime_error("Parameter input error");
                return nullptr;
            }
            return ai;
        }
        else if (strcmp(argv[1],"--math")==0){
            math_AI* ai=new math_AI;
            strcpy(ai->msg,argv[2]);
            if (strcmp(argv[3],"-o")==0 || strcmp(argv[3],"--output")==0)
                strcpy(ai->filename,argv[4]);
            else{
                throw std::runtime_error("Parameter input error");
                return nullptr;
            }
            return ai;
        }
        else if (strcmp(argv[3],"--math")==0){
            math_AI* ai=new math_AI;
            strcpy(ai->msg,argv[4]);
            if (strcmp(argv[1],"-o")==0 || strcmp(argv[1],"--output")==0)
                strcpy(ai->filename,argv[2]);
            else{
                throw std::runtime_error("Parameter input error");
                return nullptr;
            }
            return ai;
        }
        else{
            throw std::runtime_error("Parameter input error");
            return nullptr;
        }
    }
    else{
        throw std::runtime_error("Parameter count error");
        return nullptr;
    }
}

AI* Parser::doParse(){
    return nullptr;
}
Parser::Parser(int argc, char** argv){}