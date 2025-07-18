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
			vector<Department> current_department_vector = fileManager::load_department_list("department.txt");
			alumniFilter Filter(current_department_vector);
			int choice = Utils::getChoice(3);
			int choice1;
			int choice2;
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
						search_list.show();
					}
					break;
				case 2:
					Filter.modify_alumniFilter();
					Filter.show();//显示筛选条件
					current_alumni_list.filter_show(Filter);//筛选并显示校友信息
					break;
				case 3:
					cout << "选项：\n"
						<< "1.按姓名升序\n"
						<< "2.按姓名降序\n"
						<< "3.按届级升序\n"
						<< "4.按届级降序\n"
						<< "-------------------------\n";
					choice2 = Utils::getChoice(4);
					switch (choice2) {
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
					current_alumni_list.show();
					break;
				case 4:
					break;
				}
				break;
			case 2:
				current_alumni.show();
				cout << "-------------------------\n"
					<< "选项：\n"
					<< "1.修改密码\n"
					<< "2.修改校友信息\n"
					<< "3.返回上一级\n"
					<< "-------------------------\n";
				choice2 = Utils::getChoice(3);
				switch (choice2) {
				case 1:
					current_alumni.modify_password();
					for (auto& alumni : current_alumni_list) {
						if (alumni.getUserName() == current_alumni.getUserName()) {
							alumni = current_alumni;  // 更新列表中的对象
							break;
						}
					}
					fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					break;
				case 2:
					current_alumni.modify_information();
					for (auto& alumni : current_alumni_list) {
						if (alumni.getUserName() == current_alumni.getUserName()) {
							alumni = current_alumni;  // 更新列表中的对象
							break;
						}
					}
					fileManager::save_alumni_list("alumni.txt", current_alumni_list);
					break;
				case 3:
					break;
				}
				break;
			case 3:
				fileManager::save_alumni_list("alumni.txt", current_alumni_list);
				cout << "信息已保存！\n";
				cout << "退出登录成功！\n";
				cout << endl;
				return;
			}

		}
	}

private:
	alumni_list current_alumni_list; // 校友列表,注意对象一定不要和类型同名！
	alumni current_alumni; // 当前访客
};