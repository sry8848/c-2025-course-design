#include <iostream>
#include <cstdlib>
#include "VistorModle.h"
#include "Utils.h"
#include "alumni.h"
#include "list.h"
#include "alumniFilter.h"
using namespace std;
void VistorModle::run() {
	while (true) {
		cout << "校友录管理系统V1.0\n"
			<< "-------------------------\n"
			<< "选项：\n"
			<< "1.查找校友\n"
			<< "2.个人信息\n"
			<< "3.退出登录\n"
			<< "-------------------------\n";
		int choice = Utils::getChoice(3);
		alumniFilter Filter;
		int choice1 = Utils::getChoice(4);
		int choice2 = Utils::getChoice(4);
		int choice3 = Utils::getChoice(2);
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
				//alumni_list->search();
				break;
			case 2:
				Filter.modify_alumniFilter();
				Filter.show();
				alumni_list.filter_show(Filter);
				break;
			case 3:
				cout << "选项：\n"
					<< "1.按姓名升序\n"
					<< "2.按姓名降序\n"
					<< "3.按届级升序\n"
					<< "4.按届级降序\n"
					<< "-------------------------\n";

				switch (choice2) {
				case 1:
					alumni_list.sort(alumni::Compare_by_name_up);
					break;
				case 2:
					alumni_list.sort(alumni::Compare_by_name_down);
					break;
				case 3:
					alumni_list.sort(alumni::Compare_by_year_up);
					break;
				case 4:
					alumni_list.sort(alumni::Compare_by_year_down);
					break;
				}
				Filter.show();
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