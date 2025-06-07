#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include "alumni.h"
#include "myList.h"
#include "Utils.h"
#include "alumni_list.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class alumniModle {
public:
	alumniModle(alumni_list current_alumni_list_, alumni current_alumni_) {
		current_alumni_list = current_alumni_list_;
		current_alumni = current_alumni_;

	}
	void run() {
		while (true) {
			cout << "校友录管理系统V1.0\n"
				<< "-------------------------\n"
				<< "选项：\n"
				<< "1.查找校友\n"
				<< "2.个人信息\n"
				<< "3.退出登录\n"
				<< "-------------------------\n";
			int choice = Utils::getChoice(3);
			int choice2 = Utils::getChoice(2);
			switch (choice) {
			case 1:
				current_alumni_list.show();
				break;
			case 2:
				current_alumni.show();
				cout << "-------------------------\n"
					<< "选项：\n"
					<< "1.修改密码\n"
					<< "2.修改校友信息\n"
					<< "3.返回上一级\n"
					<< "-------------------------\n";
				switch (choice2) {
				case 1:
					current_alumni.modify_password();
					break;
				case 2:
					current_alumni.modify_information();
					break;
				case 3:
					break;
				}
				break;
			case 3:
				return;
			}

		}
	}

private:
	alumni_list current_alumni_list; // 校友列表,注意对象一定不要和类型同名！
	alumni current_alumni; // 当前访客
};