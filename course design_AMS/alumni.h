#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include "person.h"
class alumni :public person {
public:
	alumni(std::string userName_, std::string password_);
	void modify_information();
	void create_information();
	void show();
	static bool Compare_by_year_up(const alumni& left,const alumni& right);
	static bool Compare_by_year_down(const alumni& left, const alumni& right);
	static bool Compare_by_name_up(const alumni& left, const alumni& right);
	static bool Compare_by_name_down(const alumni& left, const alumni& right);
private:
	std::string name;
	std::string pinyin;//拼音
	char gender;
	int age;
	int year_of_graduation;
	std::string department;//系
	std::string major;//专业
	int Class;//班级
	std::string address;
	std::string phoneNumber;
	std::string qq;
	std::string email;
};
