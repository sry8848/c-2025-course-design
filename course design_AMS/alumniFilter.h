#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include <vector>
#include "person.h"
#include "alumni.h"
class alumniFilter{
public:
	//已在定义中初始化成员变量，不需要构造函数来再次初始化，否则报错已有主体定义
	//析构函数不需要做什么，因为成员变量是值类型，自动释放
	//如果成员变量是指针类型，则需要手动释放内存
	void modify_alumniFilter();
	void show();
	bool filter(const alumni& falumni) const;//未实现
	void clear_filter();//清除筛选条件
private:
	struct genders {
		bool is_filtered= false; // 是否筛选
		std::vector<char> genders;
	}gender;
	struct years_of_graduation {
		bool is_filtered = false; // 是否筛选
		std::vector<int> years_of_graduation;
	}year_of_graduation;
	struct departments {
		bool is_filtered = false; // 是否筛选
		std::vector<std::string> departments;
	}department;
	struct majors {
		bool is_filtered = false; // 是否筛选
		std::vector<std::string> majors;
	}major;
	struct Classes {
		bool is_filtered = false; // 是否筛选
		std::vector<std::string> Classes;
	}Class;
};
