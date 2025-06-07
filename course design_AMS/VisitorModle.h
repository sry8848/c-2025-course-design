#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include "visitor.h"
#include "myList.h"
#include "alumni.h"
#include "Utils.h"
#include "alumni_list.h"
#include <iostream>
#include <cstdlib>
#include "VisitorModle.h"
#include "alumniFilter.h"
#include "department.h"
using namespace std;
class VisitorModle {
public:
	VisitorModle(alumni_list current_alumni_list_, visitor current_visitor_) {
		current_alumni_list = current_alumni_list_;
		current_visitor = current_visitor_;
	}
	void run() {
		while (true) {
			cout << "\n校友录管理系统V1.0\n"
				<< "-------------------------\n"
				<< "选项：\n"
				<< "1.查找校友\n"
				<< "2.个人信息\n"
				<< "3.退出登录\n"
				<< "-------------------------\n";
			int choice = Utils::getChoice(3);
			vector<Department> current_department_vector = fileManager::load_department_list("department.txt");
			alumniFilter Filter(current_department_vector);
			int choice1;
			int choice2;
			int choice3;
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
				current_visitor.show();
				cout << "-------------------------\n"
					<< "选项：\n"
					<< "1.修改密码\n"
					<< "2.返回上一级\n"
					<< "-------------------------\n";
				choice3 = Utils::getChoice(2);
				switch (choice3) {
				case 1:
					current_visitor.modify_password();
					break;
				case 2:
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
	visitor current_visitor; // 当前访客
};