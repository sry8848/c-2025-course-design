#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include <vector>
#include "Class.h"//包含专业类的头文件
class Major {
public:
	// 构造函数，初始化专业名和班级列表
	Major(const std::string& name) 
		: majorName(name){}

	// 获取专业名
	std::string getMajorName() const {
		return majorName;
	}

	// 获取班级列表
	std::vector<Class>& getClassList() {//返回引用，允许修改
		return ClassList;
	}

	// 设置专业名
	void setMajorName(const std::string& name) {
		majorName = name;
	}


private:
	std::string majorName;
	std::vector<Class> ClassList;
};
