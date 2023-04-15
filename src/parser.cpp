#include "parser.h"
#include "ai.h"
#include "chat_ai.h"
#include "draw_ai.h"
#include "math_ai.h"
#include <iostream>
#include <cstring>
#include <assert.h>

AI* Parser::parse(int argc, char** argv){
    /*for(int i=1;i<=argc;i++){

    }*/
    if (strcmp(argv[1],"--chat")==0){
        chat_AI* ai=new chat_AI;
        strcpy(ai->msg,argv[2]);
        if (argc==3)
            return ai;
        if (strcmp(argv[3],"-o")==0 || strcmp(argv[3],"--output")==0){
            ai->havefile=true;
            strcpy(ai->filename,argv[4]);
        }
        return ai;
    }
    else if (strcmp(argv[1],"--draw")==0){
        draw_AI* ai=new draw_AI();
        ai->msg=argv[2];
        ai->filename=argv[4];
        return ai;
    }
    else if (strcmp(argv[1],"--math")==0){
        math_AI* ai=new math_AI();
        ai->msg=argv[2];
        ai->filename=argv[4];
        return ai;
    }
    else{
        //abort();
    }
}

AI* Parser::doParse(){
    return nullptr;
}
Parser::Parser(int argc, char** argv){}