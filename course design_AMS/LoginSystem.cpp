#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "LoginSystem.h"
#include "visitor.h"
#include "List.h"
#include "alumni.h"
#include "alumni_list.h"
#include "manager.h"
#include "managerModle.h"
#include "alumniModle.h"
#include "fileManager.h"
#include "Utils.h"
using namespace std;
void LoginSystem::run() {
	while (true) {
		cout << "校友录管理系统V1.0\n"
			<< "-------------------------\n"
			<< "请输入选项前的序号选择登录身份\n"
			<< "1.我是学生\n"
			<< "2.我是校友\n"
			<< "3.我是访客\n"
			<< "4.我是管理员\n"
			<< "-1.退出系统\n"
			<< "-------------------------\n";
		int choice = Utils::getChoice(4);
		while (true) {
			cout << "请输入账号和密码：\n";
			string account, password;
			cout << "账号：";
			cin >> account;
			cout << "密码：";
			cin >> password;
			cin.clear(); // 清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
			List<visitor> visitor_list;
			switch (choice) {
			case 1:
				visitor_list=fileManager::load_T_list<visitor>("visitor.txt");//需要指定返回值类型
				cout << "学生登录\n";
				break;
			case 2:
				cout << "校友登录\n";
				break;
			case 3:
				cout << "访客登录\n";
				break;
			case 4:
				cout << "管理员登录\n";
				break;
			}
			cout << "用户名或密码错误！\n"
				<< "-------------------------\n"
				<< "选项：\n"
				<< "1.重新输入\n"
				<< "2.返回上一级\n"
				<< "-------------------------\n";
			int choice2 = Utils::getChoice(2);
			if (choice2 == 1) {
				continue;
			}
			else if (choice2 == 2) {
				break;
			}
		}
	}
}
