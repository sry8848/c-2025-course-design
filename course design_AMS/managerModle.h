#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include "manager.h"
#include "myList.h"
#include "Utils.h"
#include "visitor.h"
#include "alumni_list.h"
class managerModle {
public:
	managerModle(alumni_list current_alumni_list_, manager current_manager_);
	void run();
private:
	List<visitor> current_visitor_list;
	List<manager> current_manager_list;
	alumni_list current_alumni_list; // 校友列表,注意对象一定不要和类型同名！
	manager current_manager; // 当前访客
};