#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include <vector>
class Class {
public:
	Class(std::string classNumber_ = "0000") : ClassNumber(classNumber_) {} // 默认班级号为"0000"
	void setClassNumber(const std::string& num) {
		ClassNumber = num;
	}
	std::string getClassNumber() const { return ClassNumber; }
private:
	std::string ClassNumber;
};
