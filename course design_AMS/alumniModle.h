#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include "alumni.h"
#include "list.h"
#include "Utils.h"
class alumniModle {
public:
	void run();
private:
	List<alumni>* alumni_list; // 校友列表
	alumni current_alumni; // 当前校友
};