#include <iostream>
#include <cstdlib>
#include "managerModle.h"
#include "Utils.h"
#include "manager.h"
#include "visitor.h"
#include "alumni.h"
#include "list.h"
using namespace std;
void managerModle::run() {
	while (true) {
		cout << "校友录管理系统V1.0\n"
			<< "-------------------------\n"
			<< "选项：\n"
			<< "1.查找校友\n"
			<< "2.个人信息\n"
			<<"3.创建账号\n"
			<< "4.退出登录\n"
			<< "-------------------------\n";
		int choice = Utils::getChoice(4);
		string userName;
		string password;
		switch (choice) {
		case 1:
			manager_list->show();
			break;
		case 2:
			current_manager.show();
			cout << "-------------------------\n"
				<< "选项：\n"
				<< "1.修改密码\n"
				<< "2.返回上一级\n"
				<< "-------------------------\n";
			int choice2 = Utils::getChoice(2);
			switch (choice2) {
			case 1:
				current_manager.modify_password();
				break;
			case 2:
				break;
			}
		case 3:
			cout << "选择账号类型：\n";
			cout << "1.校友账号\n";
			cout << "2.管理员账号\n";
			cout << "3.访客账号\n";
			int account_type = Utils::getChoice(3);
			if (account_type == 1) {
				cout << "请输入新校友账号信息：\n";
				cout << "用户名：";
				cin >> userName;
				cout << "密码：";
				cin >> password;
				alumni new_alumni(userName, password);
				new_alumni.create_information();
			}
			else if (account_type == 2) {
				cout << "请输入新管理员账号信息：\n";
				cout << "用户名：";
				cin >> userName;
				cout << "密码：";
				cin >> password;
				manager new_manager(userName, password);
			}
			else if (account_type == 3) {
				cout << "请输入新访客账号信息：\n";
				cout << "用户名：";
				cin >> userName;
				cout << "密码：";
				cin >> password;
				visitor new_visitor(userName, password);
			}
			break;
		case 4:
			return;
		}
		}

	}
