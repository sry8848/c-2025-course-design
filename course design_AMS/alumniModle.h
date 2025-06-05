#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include "alumni.h"
#include "list.h"
#include "Utils.h"
#include "alumni_list.h"
class alumniModle {
public:
	alumniModle(alumni_list current_alumni_list_, alumni current_alumni_);
	void run();
private:
	alumni_list current_alumni_list; // 校友列表,注意对象一定不要和类型同名！
	alumni current_alumni; // 当前访客
};