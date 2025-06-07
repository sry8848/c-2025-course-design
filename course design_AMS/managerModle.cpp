/*


#include <iostream>
#include <cstdlib>
#include "managerModle.h"
#include "alumni.h"
using namespace std;
managerModle::managerModle(alumni_list current_alumni_list_, manager current_manager_) {
	current_alumni_list = current_alumni_list_;
	current_manager = current_manager_;

}
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
		int choice2 = Utils::getChoice(2);
		int account_type = Utils::getChoice(3);
		alumniFilter Filter;
		int choice1 = Utils::getChoice(4);
		int sort_choice = Utils::getChoice(4);
		int choice3 = Utils::getChoice(2);
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
				}
				break;
			case 2:
				Filter.modify_alumniFilter();
				Filter.show();//显示筛选条件
				current_alumni_list.filter_show_allowChange(Filter);//筛选并显示校友信息
				break;
			case 3:
				cout << "选项：\n"
					<< "1.按姓名升序\n"
					<< "2.按姓名降序\n"
					<< "3.按届级升序\n"
					<< "4.按届级降序\n"
					<< "-------------------------\n";

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
			if (account_type == 1) {
				cout << "请输入新校友账号信息：\n";
				cout << "用户名：";
				cin >> userName;
				cout << "密码：";
				cin >> password;
				alumni new_alumni(userName, password, "", "", '\0', 0, 0, "", "", "", "", "", "", "");
				new_alumni.create_information();
				current_alumni_list.insert(new_alumni); // 将新校友添加到校友列表
			}
			else if (account_type == 2) {
				cout << "请输入新管理员账号信息：\n";
				cout << "用户名：";
				cin >> userName;
				cout << "密码：";
				cin >> password;
				manager new_manager(userName, password);
				current_manager_list.insert(new_manager); 
			}
			else if (account_type == 3) {
				cout << "请输入新访客账号信息：\n";
				cout << "用户名：";
				cin >> userName;
				cout << "密码：";
				cin >> password;
				visitor new_visitor(userName, password);
				current_visitor_list.insert(new_visitor);
			}
			break;
		case 4:
			return;
		}
		}
	}


	*/