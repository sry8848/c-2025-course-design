#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include "person.h"
class manager :public person {
public:
	manager(std::string userName_, std::string password_) :person::person(userName_, password_) {}
	void add_account(std::string userName_, std::string password_) {}//添加账号
	void add_alumni() {}//添加校友
};
