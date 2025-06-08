/*
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include "department.h"
#include "major.h"
#include "Class.h"
#include <algorithm>
#include "fileManager.h"
#include "alumniFilter.h"
#include "Utils.h"
using namespace std;

void alumniFilter::modify_alumniFilter() {
	while (true) {
		cout << "筛选条件：\n 1.性别\n 2.毕业年份\n 3.系/专业/班级\n 4.返回上一级\n";
		int choice = Utils::getChoice(4);
		string choices;
		vector<int> years;
		vector<Department> department_list;//小心department与alumni.department冲突
		int gender_choice;
		time_t t = time(0);
		tm now;  // 定义本地变量存储时间信息
		// 使用线程安全的 localtime_s 替代 localtime
		if (localtime_s(&now, &t) == 0) {
			// 成功获取本地时间，可操作 now 结构体
		}
		else {
			// 处理错误
		}
		int current_year;
		int current_month = now.tm_mon + 1;
		int year = 2010;
		int count = 1;
		int year_choice;
		int department_choice = Utils::getChoice(3);
		int dep_choice;
		int maj_choice;
		int class_choice;
		int continue_choice = Utils::getChoice(2);
		switch (choice) {
		case 1:
			cout << "性别筛选(输入序号，可多选或不选，输入回车确认，示例输入：1 2)：\n 1.男\n 2.女\n";
			while (gender_choice = Utils::getChoice(2)) {
				if (gender_choice == 0) break; // 如果输入0则退出选择
				else if (gender_choice == 1) {
					gender.genders.push_back('M'); // 将选择的性别添加到筛选条件中
				}
				else if (gender_choice == 2) {
					gender.genders.push_back('W'); // 将选择的性别添加到筛选条件中
				}
			}
			if (gender.genders.size() == 0) {
				gender.is_filtered = false;
			}
			else {
				gender.is_filtered = true;
			}
			break;
		case 2:
			if (current_month >= 7) {//如果当前月份大于等于7月，则毕业年份为当前年份
				current_year = now.tm_year + 1900;
			}
			else {
				current_year = now.tm_year + 1900 - 1;
			}
			while (year <= current_year) {
				years.push_back(year);
				cout << setfill('0') << setw(2) << count << " " << year << endl;
				year++;
				count++;
			}
			cout << "毕业年份筛选(输入序号，可多选或不选，输入0确认，示例输入：1 2)：\n";
			while (year_choice = Utils::getChoice(years.size())) {//应该会报错，因为getChoice会清除缓冲区
				if (year_choice == 0) break; // 如果输入0则退出选择
				year_of_graduation.years_of_graduation.push_back(years[year_choice - 1]);// 将选择的年份添加到筛选条件中
			}
			if (year_of_graduation.years_of_graduation.size() == 0) {
				year_of_graduation.is_filtered = false;
			}
			else {
				year_of_graduation.is_filtered = true;
			}
			break;
		case 3:
			department_list = fileManager::load_department_list("department.txt");
			cout << "系/专业/班级筛选(输入序号，可多选或不选，按回车确认选择)：\n 1.系\n 2.专业\n 3.班级\n";

			if (department_choice == 1) {
				cout << "请选择系：\n";
				for (size_t i = 0; i < department_list.size(); ++i) {//打印系列表，使用size_t是因为department_list.size()返回的是size_t类型，避免用int导致警告
					cout << setfill('0') << setw(2) << i + 1 << " " << department_list[i].getDepartmentName() << endl;
				}
				while (dep_choice = Utils::getChoice(department_list.size())) {//获取用户选择的系
					department.departments.push_back(department_list[dep_choice - 1].getDepartmentName());
				}
				if (department.departments.size() == 0) {
					department.is_filtered = false;
				}
				else {
					department.is_filtered = true;
				}
			}
			else if (department_choice == 2) {
				cout << "请选择系(单选)：\n";//先选择系，然后展开专业
				for (size_t i = 0; i < department_list.size(); ++i) {
					cout << setfill('0') << setw(2) << i + 1 << " " << department_list[i].getDepartmentName() << endl;
				}
				dep_choice = Utils::getChoice(department_list.size());
				Department curDept = department_list[dep_choice - 1];
				cout << "请选择专业：\n";
				for (size_t i = 0; i < curDept.getMajorList().size(); ++i) {
					cout << setfill('0') << setw(2) << i + 1 << " " << curDept.getMajorList()[i].getMajorName() << endl;
				}

				while (maj_choice = Utils::getChoice(department_list.size())) {
					major.majors.push_back(curDept.getMajorList()[maj_choice - 1].getMajorName());
				}
				if (major.majors.size() == 0) {
					major.is_filtered = false;
				}
				else {
					major.is_filtered = true;
				}
			}
			else if (department_choice == 3) {
				cout << "请选择系(单选)：\n";//先选择系，然后展开专业
				for (size_t i = 0; i < department_list.size(); ++i) {
					cout << setfill('0') << setw(2) << i + 1 << " " << department_list[i].getDepartmentName() << endl;
				}

				dep_choice = Utils::getChoice(department_list.size());
				Department curDept = department_list[dep_choice - 1];
				cout << "请选择专业：\n";
				for (size_t i = 0; i < curDept.getMajorList().size(); ++i) {
					cout << setfill('0') << setw(2) << i + 1 << " " << curDept.getMajorList()[i].getMajorName() << endl;
				}

				maj_choice = Utils::getChoice(curDept.getMajorList().size());
				Major curMajor = curDept.getMajorList()[maj_choice - 1];
				cout << "请选择班级：\n";
				for (size_t i = 0; i < curMajor.getClassList().size(); ++i) {//打印班级列表
					cout << setfill('0') << setw(2) << i + 1 << " " << curMajor.getClassList()[i].getClassNumber() << endl;
				}

				while (class_choice = Utils::getChoice(department_list.size())) {//
					Class.Classes.push_back(curMajor.getClassList()[class_choice - 1].getClassNumber());
				}
				if (Class.Classes.size() == 0) {
					Class.is_filtered = false;
				}
				else {
					Class.is_filtered = true;
				}
			}
			break;
		}
		cout << "是否继续筛选？\n 1.是\n 2.否\n";

		if (continue_choice == 2) {
			break;
		}
		//待补充系，专业，和班级
	}
}
void alumniFilter::show() {
	cout << "筛选条件：\n";
	cout<<"性别：";
	sort(gender.genders.begin(), gender.genders.end());
	for(auto it = gender.genders.begin(); it != gender.genders.end();++it) {
		if (*it == 'M') {
			cout << "男\n";
		}
		else if (*it == 'W') {
			cout << "女\n";
		}
	}
	cout << endl;
	cout << "毕业年份：\n";
	sort(year_of_graduation.years_of_graduation.begin(), year_of_graduation.years_of_graduation.end());
	for (auto it = year_of_graduation.years_of_graduation.begin(); it != year_of_graduation.years_of_graduation.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}
bool alumniFilter::filter(const alumni& falumni) const {
	if (gender.is_filtered == true) {
		for (size_t i = 0; i < gender.genders.size(); ++i) {
			if(falumni.getGender()==gender.genders[i]) {
				break;
			}
			if (gender.genders.size() - 1) {
				return false; //如果没有匹配到，则返回false
			}
		}
	}
	if (year_of_graduation.is_filtered == true) {
		for (size_t i = 0; i < year_of_graduation.years_of_graduation.size(); ++i) {
			if (falumni.getGraduationYear() == year_of_graduation.years_of_graduation[i]) {
				break;
			}
			if (year_of_graduation.years_of_graduation.size() - 1) {
				return false; //如果没有匹配到，则返回false
			}
		}
	}
	if (department.is_filtered == true) {
		for (size_t i = 0; i < department.departments.size(); ++i) {
			if (falumni.getDepartment() == department.departments[i]) {
				break;
			}
			if (department.departments.size() - 1) {
				return false; //如果没有匹配到，则返回false
			}
		}
	}
	if (major.is_filtered == true) {
		for (size_t i = 0; i < major.majors.size(); ++i) {
			if (falumni.getMajor() == major.majors[i]) {
				break;
			}
			if (major.majors.size() - 1) {
				return false; //如果没有匹配到，则返回false
			}
		}
	}
	if (Class.is_filtered == true) {
		for (size_t i = 0; i < Class.Classes.size(); ++i) {
			if (falumni.getClass() == Class.Classes[i]) {
				break;
			}
			if (Class.Classes.size() - 1) {
				return false; //如果没有匹配到，则返回false
			}
		}
	}
	return true;
}
void alumniFilter::clear_filter() {
	gender.is_filtered = false;
	year_of_graduation.is_filtered = false;
	department.is_filtered = false;
	major.is_filtered = false;
	Class.is_filtered = false;
	gender.genders.clear();
	year_of_graduation.years_of_graduation.clear();
	department.departments.clear();
	major.majors.clear();
	Class.Classes.clear();

}
*/
