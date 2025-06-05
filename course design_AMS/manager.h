#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include "person.h"
class manager :public person {
public:
	manager(std::string userName_="", std::string password_="123456") :person::person(userName_, password_) {}
};
