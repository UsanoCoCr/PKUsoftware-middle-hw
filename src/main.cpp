#include <memory>
#include "./ai.h"
#include "./parser.h"
#include "./chat_ai.h"
#include <iostream>

int main(int argc, char** argv) {
    //std::cout<<"Hello World!";
    AI* ai(Parser::parse(argc, argv));
    ai->sendRequest();
    ai->showResponse();
    delete ai;
}
