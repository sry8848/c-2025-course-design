#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include "manager.h"
#include "list.h"
#include "Utils.h"
class managerModle {
public:
	void run();
private:
	List<manager>* manager_list; 
	manager current_manager; 
};