
#include <iostream>
#include "MyServer.hpp"


MyServer::MyServer() {
    std::cout << "init my server" << std::endl;
}

MyServer::~MyServer() {

}

int MyServer::getId() {
    return this->_id;
}