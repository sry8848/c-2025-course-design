
/*


#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include "person.h"
#include "alumni.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include "department.h"
#include "major.h"
#include "Class.h"
#include <algorithm>
#include "Utils.h"
#include "alumni_list.h"
#include "myList.h"
#include <fstream>
using namespace std;
template <typename T> class List;
class alumni_list;
class Department;//添加前向声明，避免循环依赖！！
class fileManager {
public:

	static void save_alumni_list(const string& fileName, const alumni_list& alumniList) {// 保存校友列表到文件 
		if (alumniList.empty()) {
			return; // 如果列表为空，直接返回
		}
		ofstream outfile(fileName);//不应使用"fileName"
		if (!outfile) { // 检查文件是否成功打开
			cerr << "无法打开文件: " << fileName << endl;
			return;
		}
		outfile << "账号,密码,姓名,姓名拼音,性别,年龄,毕业年份,系,专业,班级,地址,电话号码,QQ,电子邮箱\n"; // 写入表头（CSV格式,通用性强，可以用Excel打开(分隔符推荐，或\t））
		auto it = alumniList.begin();//
		while (it != alumniList.end()) {
			outfile << (*it).getUserName() << "," //自定义迭代器重载了'*'，*it即为alumni对象
				<< (*it).getPassword() << ","
				<< (*it).getName() << ","
				<< (*it).getPinyin() << ","
				<< (*it).getGender() << ","
				<< (*it).getAge() << ","
				<< (*it).getGraduationYear() << ","
				<< (*it).getDepartment() << ","
				<< (*it).getMajor() << ","
				<< (*it).getClass() << ","
				<< (*it).getAddress() << ","
				<< (*it).getPhoneNumber() << ","
				<< (*it).getQQ() << ","
				<< (*it).getEmail() << "\n";
			++it; // 移动到下一个元素
		}
		outfile.close(); // 关闭文件
	}
	static alumni_list load_alumni_list(const string& fileName) {
		ifstream infile(fileName);
		if (!infile) { // 检查文件是否成功打开
			cerr << "无法打开文件: " << fileName << endl;
			return alumni_list(); // 返回一个空的 alumni_list
		}
		alumni_list alumniList;
		string line;
		string userName_;
		string password_;
		string name;
		string pinyin;
		char gender;
		int age;
		int year_of_graduation;
		string department;
		string major;
		std::string Class;
		string address;
		string phoneNumber;
		string qq;
		string email;
		string tempInformation;
		getline(infile, line); // 读取表头
		while (getline(infile, userName_, ',')) {//遇到文件终止符结束
			getline(infile, password_, ',');
			getline(infile, name, ',');
			getline(infile, pinyin, ','); // 读取姓名拼音
			getline(infile, tempInformation, ',');
			gender = tempInformation[0]; // 假设性别是单个字符
			getline(infile, tempInformation, ',');
			age = stoi(tempInformation); // 将字符串转换为整数
			getline(infile, tempInformation, ',');
			year_of_graduation = stoi(tempInformation); // 将字符串转换为整数
			getline(infile, department, ',');
			getline(infile, major, ',');
			getline(infile, tempInformation, ',');
			Class = stoi(tempInformation); // 将字符串转换为整数
			getline(infile, address, ',');
			getline(infile, phoneNumber, ',');
			getline(infile, qq, ',');
			getline(infile, email); // 最后一行没有逗号
			alumni newAlumni(userName_, password_, name, pinyin, gender, age, year_of_graduation, department, major, Class, address, phoneNumber, qq, email); // 创建一个新的 alumni 对象
			alumniList.insert(newAlumni); // 将新对象插入到 alumniList 中
		}
		infile.close(); // 关闭文件
		return alumniList; // 返回加载的 alumni_list
	}
	template <typename T>
	static void save_T_list(const string& fileName, List<T>& TList) {
		if (TList.empty()) {
			return; // 如果列表为空，直接返回
		}
		ofstream outfile(fileName);//不应使用"fileName"
		if (!outfile) { // 检查文件是否成功打开
			cerr << "无法打开文件: " << fileName << endl;
			return;
		}
		outfile << "账号,密码\n"; // 写入表头（CSV格式,通用性强，可以用Excel打开(分隔符推荐，或\t））
		auto it = TList.begin();
		while (it != TList.end()) {
			outfile << (*it).getUserName() << "," //自定义迭代器重载了'*'，*it即为alumni对象
				<< (*it).getPassword() << "\n";
			++it; // 移动到下一个元素
		}
		outfile.close(); // 关闭文件
	}

	static vector<Department> load_department_list(const string& fileName) {
		vector<Department> departmentList;
		ifstream infile(fileName);
		if (!infile) { // 检查文件是否成功打开
			cerr << "无法打开文件: " << fileName << endl;
			return departmentList; // 返回一个空的部门列表
		}
		string departmentName;
		string pre_departmentName = ""; // 用于记录上一个部门名称
		string majorName;
		string pre_majorName = ""; // 用于记录上一个专业名称
		string className;
		string pre_className = ""; // 用于记录上一个班级名称
		string line;
		getline(infile, line);
		while (getline(infile, departmentName, ',')) {//遇到文件终止符结束
			if (!getline(infile, majorName, ',')) break;//防止意外错误
			if (!getline(infile, className)) break;
			if (departmentName != pre_departmentName) {
				pre_departmentName = departmentName; // 更新上一个部门名称
				Department newDepartment(departmentName); // 创建一个新的部门对象
				departmentList.push_back(newDepartment); // 将新部门添加到列表中
			}
			vector<Major>& majors = departmentList.back().getMajorList(); // 获取当前部门的专业列表
			if (majorName != pre_majorName) {
				pre_majorName = majorName;
				Major newmajor(majorName);
				majors.push_back(newmajor);
			}
			vector<Class>& classes = majors.back().getClassList(); // 获取当前专业的班级列表
			if (className != pre_className) {
				pre_className = className;
				Class newClass(className);
				classes.push_back(newClass);
			}
		}
		infile.close(); // 关闭文件
		return departmentList; // 返回加载的部门列表
	}
	template <typename T>
	static List<T> load_T_list(const std::string& fileName) {
		std::ifstream infile(fileName);
		if (!infile) { // 检查文件是否成功打开
			cerr << "无法打开文件: " << fileName << endl;
			return List<T>(); // 返回一个空的 List<T>
		}
		string line;
		string userName_;
		string password_;
		List<T> TList; // 创建一个通用列表
		getline(infile, line); // 读取表头
		while (getline(infile, userName_, ',')) {//遇到文件终止符结束
			getline(infile, password_);
			T item(userName_, password_);
			TList.insert(item);
		}
		infile.close(); // 关闭文件
		return TList; // 返回加载的通用列表
	}

}
;
class alumniFilter{
public:
	//已在定义中初始化成员变量，不需要构造函数来再次初始化，否则报错已有主体定义
	//析构函数不需要做什么，因为成员变量是值类型，自动释放
	//如果成员变量是指针类型，则需要手动释放内存


	void modify_alumniFilter() {
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
	void show() {
		cout << "筛选条件：\n";
		cout << "性别：";
		sort(gender.genders.begin(), gender.genders.end());
		for (auto it = gender.genders.begin(); it != gender.genders.end(); ++it) {
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
	bool filter(const alumni& falumni) const {
		if (gender.is_filtered == true) {
			for (size_t i = 0; i < gender.genders.size(); ++i) {
				if (falumni.getGender() == gender.genders[i]) {
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
	void clear_filter();//清除筛选条件
private:
	struct genders {
		bool is_filtered= false; // 是否筛选
		std::vector<char> genders;
	}gender;
	struct years_of_graduation {
		bool is_filtered = false; // 是否筛选
		std::vector<int> years_of_graduation;
	}year_of_graduation;
	struct departments {
		bool is_filtered = false; // 是否筛选
		std::vector<std::string> departments;
	}department;
	struct majors {
		bool is_filtered = false; // 是否筛选
		std::vector<std::string> majors;
	}major;
	struct Classes {
		bool is_filtered = false; // 是否筛选
		std::vector<std::string> Classes;
	}Class;
};


*/