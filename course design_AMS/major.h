#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include "Class.h"//包含专业类的头文件
class major {
public:
private:
	std::string majorName;
	Class* ClassList;
};
