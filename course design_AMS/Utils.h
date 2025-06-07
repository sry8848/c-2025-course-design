#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
class Utils {
public:
	//都设计为静态函数，不需要对象即可调用
	//选项控制
	static int getChoice(int numberOfChoices);//获取用户输入的选项
	//输入验证
	static std::string modifyPassword(std::string prePassword);//修改密码，输入新密码并验证,参数为原密码;
	static std::string onlyNumberInput();//只允许输入数字的输入
	static std::string pinyinInput();//拼音输入，只允许英文输入，自动转小写字母
	//字符转换
	//字段查找
	static int serach_return_weight(const std::string& str, const std::string& key);//在字符串中查找子串并返回权重值
};
