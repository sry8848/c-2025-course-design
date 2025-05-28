#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
class Utils {
public:
	//都设计为静态函数，不需要对象即可调用
	//选项控制
	static int getChoice(int numberOfChoices);//获取用户输入的选项
	//输入验证
};
