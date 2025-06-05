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
#include "VisitorModle.h"
#include "alumniModle.h"
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
			List<visitor> current_visitor_list;
			alumni_list current_alumni_list;
			List<manager> current_manager_list;
			visitor current_visitor(account, password);
			manager current_manager(account, password);
			alumni current_alumni(account, password);
			switch (choice) {
			case 1:
				current_visitor_list = fileManager::load_T_list<visitor>("visitor.txt");//需要指定返回值类型
				cout << "学生登录\n";
				if (current_visitor_list.count(current_visitor)) {
					cout<<"登录成功！\n";
					VisitorModle visitorModle(current_alumni_list, current_visitor);//创建VisitorModle对象
					visitorModle.run();
				}
				break;
			case 2:
				current_alumni_list = fileManager::load_alumni_list("alumni.txt");
				cout << "校友登录\n";
				if (current_alumni_list.count(current_alumni)) {
					cout<<"登录成功！\n";
					alumniModle alumniModle(current_alumni_list, current_alumni);//创建alumniModle对象
					alumniModle.run();
				}
				break;
			case 3:
				current_visitor_list = fileManager::load_T_list<visitor>("visitor.txt");
				cout << "访客登录\n";
				if (current_visitor_list.count(current_visitor)) {
					cout<<"登录成功！\n";
					VisitorModle visitorModle(current_alumni_list, current_visitor);//创建VisitorModle对象
					visitorModle.run();
				}
				break;
			case 4:
				current_manager_list = fileManager::load_T_list<manager>("manager.txt");
				cout << "管理员登录\n";
				if (current_manager_list.count(current_manager)) {
					cout<<"登录成功！\n";
					managerModle managerModle(current_alumni_list, current_manager);//创建managerModle对象
					managerModle.run();
				}
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
