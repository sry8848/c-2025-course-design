#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
class person {
public:
	person(std::string userName_, std::string password_);
	void show();
	void modify_password();//修改密码
protected:
	std::string userName;
	std::string password;
};