#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include "visitor.h"
#include "myList.h"
#include "alumni.h"
#include "Utils.h"
#include "alumni_list.h"
class VisitorModle {
public:
	VisitorModle(alumni_list current_alumni_list_,visitor current_visitor_);
	void run();
private:
	alumni_list current_alumni_list; // 校友列表,注意对象一定不要和类型同名！
	visitor current_visitor; // 当前访客
};