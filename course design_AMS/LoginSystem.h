#pragma once//头文件保护，防止重复包含
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "LoginSystem.h"
#include "visitor.h"
#include "myList.h"
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
//不建议头文件包含#include<iostream>，而是使用std::
class LoginSystem {
	public:
		void run() {
			while (true) {
				cout << "\n校友录管理系统V1.0\n"
					<< "------------------------------\n"
					<< "请输入选项前的序号选择登录身份\n"
					<< "1.我是学生\n"
					<< "2.我是校友\n"
					<< "3.我是访客\n"
					<< "4.我是管理员\n"
					<< "5.退出系统\n"
					<< "------------------------------\n";
				int choice = Utils::getChoice(5);
				if (choice == 5) {
					cout << "退出系统！\n";
					exit(0);
				}
				while (true) {
					cout << "请输入账号和密码：\n";
					string account, password;
					cout << "账号：";
					cin >> account;
					cout << "密码：";
					cin >> password;
					cin.clear(); // 清除错误标志
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
					std::string name = "";
					std::string pinyin = "";
					char gender = '\0';
					int age = 0;
					int year_of_graduation = 0;
					std::string department = "";
					std::string major = "";
					std::string Class = "";
					std::string address = "";
					std::string phoneNumber = "";
					std::string qq = "";
					std::string email = "";
					List<visitor> current_visitor_list;
					alumni_list current_alumni_list;
					List<manager> current_manager_list;
					current_alumni_list = fileManager::load_alumni_list("alumni.txt");
					current_visitor_list = fileManager::load_T_list<visitor>("visitor.txt");//需要指定返回值类型
					current_visitor_list = fileManager::load_T_list<visitor>("visitor.txt");
					current_manager_list = fileManager::load_T_list<manager>("manager.txt");
					visitor current_visitor(account, password);
					manager current_manager(account, password);
					bool lgout = 0;
					alumni current_alumni(account, password, "", "", '\0', 0, 0, "", "", "", "", "", "", "");
					switch (choice) {
					case 1:
	
						if (current_visitor_list.count(current_visitor)) {
							cout << "登录成功！\n";
							VisitorModle visitorModle(current_visitor_list,current_alumni_list, current_visitor);//创建VisitorModle对象
							visitorModle.run();
							lgout = 1;
						}
						else {
							cout << "用户名或密码错误！\n"
								<< "-------------------------\n"
								<< "选项：\n"
								<< "1.重新输入\n"
								<< "2.返回上一级\n"
								<< "-------------------------\n";
	
						}
						break;
					case 2:

						if (current_alumni_list.count(current_alumni)) {//只有person重载==，因此只比较账号密码
							current_alumni = current_alumni_list.find(current_alumni);
							cout << "登录成功！\n";
							alumniModle alumniModle(current_alumni_list, current_alumni);//创建alumniModle对象
							alumniModle.run();
							lgout = 1;
						}
						else {
							cout << "用户名或密码错误！\n"
								<< "-------------------------\n"
								<< "选项：\n"
								<< "1.重新输入\n"
								<< "2.返回上一级\n"
								<< "-------------------------\n";
	
						}
						break;
					case 3:
					
						if (current_visitor_list.count(current_visitor)) {
							cout << "登录成功！\n";
							VisitorModle visitorModle(current_visitor_list, current_alumni_list, current_visitor);//创建VisitorModle对象
							visitorModle.run();
							lgout = 1;
						}
						else {
							cout << "用户名或密码错误！\n"
								<< "-------------------------\n"
								<< "选项：\n"
								<< "1.重新输入\n"
								<< "2.返回上一级\n"
								<< "-------------------------\n";
	
						}
						break;
					case 4:
		
						if (current_manager_list.count(current_manager)) {
							cout << "登录成功！\n";
							managerModle managerModle(current_visitor_list, current_manager_list,current_alumni_list, current_manager);//创建managerModle对象
							managerModle.run();
							lgout = 1;
						}
						else {
							cout << "用户名或密码错误！\n"
								<< "-------------------------\n"
								<< "选项：\n"
								<< "1.重新输入\n"
								<< "2.返回上一级\n"
								<< "-------------------------\n";
							
						}
						break;
					}
					if (!lgout) {
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
		}

};