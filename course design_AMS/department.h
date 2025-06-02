#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include <vector>
#include "major.h"//包含专业类的头文件
class Department {
public:
	//构造函数，初始化系名和专业列表
	Department(const std::string& name) 
		: departmentName(name){}

	//获取系名
	std::string getDepartmentName() const {
		return departmentName;
	}

	//获取专业列表
	std::vector<Major>& getMajorList() {
		return majorList;
	}

	//设置系名
	void setDepartmentName(const std::string& name) {
		departmentName = name;
	}

private:
	std::string departmentName;
	std::vector<Major> majorList;
}; 
