#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include "person.h"
class alumni :public person {
public:
	alumni(
		std::string userName_, 
		std::string password_,
		std::string name,
		std::string pinyin, // 姓名拼音
		char gender,
		int age,
		int year_of_graduation,
		std::string department,
		std::string major,
		std::string Class,
		std::string address,
		std::string phoneNumber,
		std::string qq,
		std::string email
	);
	alumni() = default; // 默认构造函数
	std::string getUserName() const { return userName; }
	std::string getPassword() const { return password; }
	std::string getName() const { return name; }
	std::string getPinyin() const { return pinyin; } // 获取姓名拼音
	std::string getDepartment() const { return department; }
	std::string getMajor() const { return major; }
	std::string getClass() const { return Class; }
	int getAge() const { return age; }
	int getGraduationYear() const { return year_of_graduation; }
	std::string getAddress() const { return address; }
	std::string getPhoneNumber() const { return phoneNumber; }
	std::string getQQ() const { return qq; }
	std::string getEmail() const { return email; }
	int getGender() const { return gender; }
	void modify_information();
	void create_information();
	void show();
	static bool Compare_by_year_up(const alumni& left,const alumni& right);
	static bool Compare_by_year_down(const alumni& left, const alumni& right);
	static bool Compare_by_name_up(const alumni& left, const alumni& right);
	static bool Compare_by_name_down(const alumni& left, const alumni& right);
private:
	std::string name;
	std::string pinyin; // 姓名拼音
	char gender='\0';//非string,要设置初始值,否则编译器会报错
	int age=0;
	int year_of_graduation=0;
	std::string department;//系
	std::string major;//专业
	std::string Class;//班级
	std::string address;
	std::string phoneNumber;
	std::string qq;
	std::string email;
};
