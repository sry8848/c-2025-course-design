#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include "visitor.h"
#include "list.h"
#include "alumni.h"
#include "Utils.h"
#include "alumni_list.h"
class VistorModle {
public:
	void run();
private:
	List<visitor>* visitor_list; // 访客列表
	alumni_list alumni_list; // 校友列表
	visitor current_visitor; // 当前访客
};