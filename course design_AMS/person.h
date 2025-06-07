#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
class person {
public:
	std::string getUserName() const { return userName; }
	std::string getPassword() const { return password; }
	person(std::string userName_=0, std::string password_="123456");//默认密码
	void show();
	void modify_password();//修改密码
	bool operator==(const person& other) const;
protected:
	std::string userName;
	std::string password;
};