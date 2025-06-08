#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include "manager.h"
#include "alumni.h"
#include "myList.h"
#include "Utils.h"
#include "visitor.h"
#include "alumni_list.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class managerModle {
public:
	managerModle(List<visitor> current_visitor_list_,List<manager> current_manager_list, alumni_list current_alumni_list_, manager current_manager_) {
		current_visitor_list = current_visitor_list_;
		current_manager_list = current_manager_list;
		current_alumni_list = current_alumni_list_;
		current_manager = current_manager_;
	}
	void run() {
		while (true) {
			cout << "\n校友录管理系统V1.0\n"
				<< "-------------------------\n"
				<< "选项：\n"
				<< "1.查找校友\n"
				<< "2.个人信息\n"
				<< "3.创建账号\n"
				<< "4.退出登录\n"
				<< "-------------------------\n";
			int choice = Utils::getChoice(4);
			string userName;
			string password;
			int choice2;
			int account_type;
			alumniFilter Filter(fileManager::load_department_list("department.txt"));
			int choice1;
			int sort_choice;
			//int choice3 = Utils::getChoice(2);找不到choice3的定义，可能是之前的代码片段没有包含
			string keyword;
			alumni_list search_list;
			switch (choice) {
			case 1:
				cout << "选项：\n"
					<< "1.搜索查找\n"
					<< "2.筛选\n"
					<< "3.排序方式\n"
					<< "4.返回上一级\n"
					<< "-------------------------\n";
				choice1 = Utils::getChoice(4);
				switch (choice1) {
				case 1:
					cout << "搜索：";
					getline(cin, keyword);
					search_list = current_alumni_list.search_form_line(keyword);
					if (search_list.empty()) {
						cout << "没有找到相关校友信息！\n";
					}
					else {
						search_list.show_allowChange();
						fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					}
					break;
				case 2:
					Filter.modify_alumniFilter();
					Filter.show();//显示筛选条件
					current_alumni_list.filter_show_allowChange(Filter);//筛选并显示校友信息
					fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					break;
				case 3:
					cout << "选项：\n"
						<< "1.按姓名升序\n"
						<< "2.按姓名降序\n"
						<< "3.按届级升序\n"
						<< "4.按届级降序\n"
						<< "-------------------------\n";
					sort_choice = Utils::getChoice(4);
					switch (sort_choice) {
					case 1:
						current_alumni_list.sort(alumni::Compare_by_name_up);
						break;
					case 2:
						current_alumni_list.sort(alumni::Compare_by_name_down);
						break;
					case 3:
						current_alumni_list.sort(alumni::Compare_by_year_up);
						break;
					case 4:
						current_alumni_list.sort(alumni::Compare_by_year_down);
						break;
					}
					current_alumni_list.show_allowChange();
					fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					break;
				case 4:
					break;
				}
				break;
			case 2:
				current_manager.show();
				cout << "-------------------------\n"
					<< "选项：\n"
					<< "1.修改密码\n"
					<< "2.返回上一级\n"
					<< "-------------------------\n";
				choice2 = Utils::getChoice(2);
				switch (choice2) {
				case 1:
					current_manager.modify_password();
					for (auto& manager : current_manager_list) {
						if (manager.getUserName() == current_manager.getUserName()) {
							manager = current_manager;  // 更新列表中的对象
							break;
						}
					}
					fileManager::save_T_list("manager.txt", current_manager_list);
					break;
				case 2:
					break;
				}
				break;
			case 3:
				cout << "选择账号类型：\n";
				cout << endl;
				cout << "-------------------------\n";
				cout << "选项：\n";
				cout << "1.校友账号\n";
				cout << "2.管理员账号\n";
				cout << "3.访客账号\n";
				cout << "4.返回上一级\n";
				cout << "-------------------------\n";
				account_type = Utils::getChoice(4);
				cout << "(注意：新账号的初始密码为123456)\n";
				if (account_type == 1) {
					cout << "请输入新校友账号信息：\n";
					cout << "用户名：";
					cin >> userName;
					cin.clear(); // 清除输入缓冲区中的换行符
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区中的换行符
					password = Utils::modifyPassword("123456");
					alumni new_alumni(userName, password, "", "", '\0', 0, 0, "", "", "", "", "", "", "");
					new_alumni.create_information();
					current_alumni_list.insert(new_alumni); // 将新校友添加到校友列表
					fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					cout << "创建成功！\n";
				}
				else if (account_type == 2) {
					cout << "请输入新管理员账号信息：\n";
					cout << "用户名：";
					cin >> userName;
					cin.clear(); // 清除错误标志
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
					password = Utils::modifyPassword("123456");
					manager new_manager(userName, password);
					current_manager_list.insert(new_manager);
					fileManager::save_T_list("manager.txt", current_manager_list);
					cout << "创建成功！\n";
				}
				else if (account_type == 3) {
					cout << "请输入新访客账号信息：\n";
					cout << "用户名：";
					cin >> userName;
					cin.clear(); // 清除错误标志
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
					password = Utils::modifyPassword("123456");
					visitor new_visitor(userName, password);
					current_visitor_list.insert(new_visitor);
					fileManager::save_T_list("visitor.txt", current_visitor_list);
					cout<< "创建成功！\n";
				}
				break;
			case 4:
				fileManager::save_T_list("visitor.txt", current_visitor_list);
				fileManager::save_T_list("manager.txt", current_manager_list);
				fileManager::save_alumni_list("alumni.txt", current_alumni_list);
				cout << "信息已保存！\n";
				cout << "退出登录成功！\n";
				return;
			}
		}
	}
private:
	List<visitor> current_visitor_list;
	List<manager> current_manager_list;
	alumni_list current_alumni_list; // 校友列表,注意对象一定不要和类型同名！
	manager current_manager; // 当前访客
};