#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "alumniFilter.h"
#include "Utils.h"
using namespace std;
alumniFilter::alumniFilter() {
	gender.is_filtered = false;
	year_of_graduation.is_filtered = false;
	department.is_filtered = false;
	major.is_filtered = false;
	Class.is_filtered = false;
}
void alumniFilter::modify_alumniFilter() {
	cout<<"筛选条件：\n 1.性别\n 2.毕业年份\n 3.系/专业/班级\n 4.返回上一级\n";
	int choice = Utils::getChoice(4);
	string choices;
	switch (choice) {
	case 1:
		cout << "性别筛选(输入序号，可多选或不选，按回车确认)：\n 1.男\n 2.女\n";
		getline(cin, choices);
		if (choices.find('1')) {
			gender.genders.push_back('M');
		}
		if (choices.find('2')) {
			gender.genders.push_back('W');
		}
		break;
	case 2:
		time_t t = time(0);
		tm* now = localtime(&t);
		int current_year;
		int current_month = now->tm_mon + 1;
		if (current_month >= 7) {//如果当前月份大于等于7月，则毕业年份为当前年份
			current_year = now->tm_year + 1900;
		}
		else {
			current_year = now->tm_year + 1900 - 1;
		}
		cout << "毕业年份筛选(输入毕业年份，示例输入：2011 2012)：\n";
		int year;
		while (cin >> year) {
			if (year >= 2010 && year <= current_year) {
				year_of_graduation.years_of_graduation.push_back(year);
			}
			else {
				cout << "输入错误！请重新输入毕业年份（示例输入：2011 2012）\n" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		break;
	case 3:
		cout << "系/专业/班级筛选(输入序号，可多选或不选，按回车确认选择)：\n 1.系\n 2.专业\n 3.班级\n";
		break;
	}

	//待补充系，专业，和班级
}
void alumniFilter::show() {
	cout << "筛选条件：\n";
	cout<<"性别：";
	sort(gender.genders.begin(), gender.genders.end());
	for(auto it = gender.genders.begin(); it != gender.genders.end();++it) {
		if (*it == 'M') {
			cout << "男 ";
		}
		else if (*it == 'W') {
			cout << "女 ";
		}
	}
	cout << endl;
	cout << "毕业年份：\n";
	sort(year_of_graduation.years_of_graduation.begin(), year_of_graduation.years_of_graduation.end());
	for (auto it = year_of_graduation.years_of_graduation.begin(); it != year_of_graduation.years_of_graduation.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	//待补充系，专业，和班级

}