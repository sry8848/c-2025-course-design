#include <iostream>
#include <cstdlib>
#include "person.h"
#include "Utils.h"
using namespace std;
person::person(std::string userName_, std::string password_) {
	userName = userName_;
	password = password_;
}
void person::show() {
	cout << "-------------------------\n";
	cout<< "用户信息：\n";
	cout << "用户名： " << userName << endl;
}
void person::modify_password() {
	cout<< "请输入新密码：";
	string new_password;
	getline(cin, new_password);//防止空格后残留字符
	if (new_password == password) {
		cout << "新密码不能与原密码相同！\n" << endl;
		cout<<"选项：\n 1.重新输入\n 2.返回上一级\n";
		int choice = Utils::getChoice(2);
		if (choice == 1) {
			modify_password();
		}
		else if (choice == 2) {
			return;
		}
	}
	else if (new_password.length() < 6) {
		cout << "密码长度不能小于6位！\n" << endl;
		cout<<"选项：\n 1.重新输入\n 2.返回上一级\n";
		int choice = Utils::getChoice(2);
		if (choice == 1) {
			modify_password();
		}
		else if (choice == 2) {
			return;
		}
	}
	else if (new_password.length() > 20) {
		cout << "密码长度不能大于20位！\n" << endl;
		cout<<"选项：\n 1.重新输入\n 2.返回上一级\n";
		int choice = Utils::getChoice(2);
		if (choice == 1) {
			modify_password();
		}
		else if (choice == 2) {
			return;
		}
	}
	else if (new_password.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos|| new_password.find_first_of("0123456789") == string::npos) {
		cout << "密码必须为字母和数字的组合！\n" << endl;
		cout<<"选项：\n 1.重新输入\n 2.返回上一级\n";
		int choice = Utils::getChoice(2);
		if (choice == 1) {
			modify_password();
		}
		else if (choice == 2) {
			return;
		}
	}
	else {
		password = new_password;
		cout << "修改成功！\n" << endl;
	}
}