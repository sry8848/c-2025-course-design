/*

//alumni_list.h
#pragma once

// 先包含alumni的完整定义
#include "alumni.h"
#include "visitor.h"

// 再包含依赖alumni的模板
#include "myList.h"

// 最后包含其他依赖
#include "alumniFilter.h"
class alumni_list{
public:
	alumni_list(){}
	//alumni_list(List<alumni>& alumniList_) :alumniList(alumniList_) {}
	void sort(bool (*Compare)(const alumni& val1, const alumni& val2));//插入排序，在原链表中插入排序
	void show()const;//分页展示
	void filter_show(const alumniFilter& filter)const;//筛选展示
	void show_allowChange();//允许修改的展示
	void filter_show_allowChange(const alumniFilter& alumniFilter);//允许修改的筛选展示
	alumni_list search_form_line(const std::string& keyword) const;//搜索功能，返回一个新的alumni_list
private:
	List<int> alumniList;
};
*/


//alumni_list.h
#pragma once

// 先包含alumni的完整定义
#include "alumni.h"
//myList.h
#pragma once//头文件保护，防止重复包含
#include <cstdlib>
#include "fileManager.h"
// 最后包含其他依赖
#include "alumniFilter.h"
#include <string>//用到std::string就包含此头文件
#include "person.h"
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
#include "myList.h"
#include <fstream>
#include <utility>
#include <set>
#include <string>
#include "Utils.h"
#include "alumniFilter.h"
using namespace std;
template <typename T> class List;
class alumni_list;
class alumniFilter;
class Department;//添加前向声明，避免循环依赖！！

template<typename T>
class List {
public:
	struct Node {//Node结构体需定义在Iterator类之前，否则会报错
		T data;
		Node* next = NULL;
	};
	Node* head;
	//template<typename T>
	List() {
		head = NULL;
	}
	List(const List<T>& other) : head(NULL) {//拷贝构造函数
		Node* current = other.head;
		while (current != NULL) {
			insert(current->data);
			current = current->next;
		}
	}
	//template<typename T>
	void clear() {
		while (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	virtual ~List() {
		clear();
	}

	//template<typename T>
	void insert(const T& val) {
		Node* temp = head;
		head = new Node;//内存分配失败会系统自己崩溃，不用过多处理
		if (head != NULL) {
			head->data = val;
			head->next = temp;
		}
	}
	//template<typename T>
	void erase(int num) {
		if (num < 1) {
			std::cerr << "out of range\n";
			exit(1);
		}
		else if (num == 1) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else {
			Node* p1 = head;
			Node* p2 = head;
			for (int i = 2; i < num; ++i) {
				if (p1->next != NULL) {
					p1 = p1->next;//p1为删除结点前一个结点
				}
				else {
					std::cerr << "out of range\n";
					exit(1);
				}
			}
			p2 = p1->next;
			p1->next = p2->next;
			delete p2;
		}
	}
	//template<typename T>
	bool empty() const {
		return head == NULL;
	}
	//template<typename T>
	T operator[](int num) {
		if (num < 1) {
			std::cerr << "out of range\n";
			exit(1);
		}
		else {
			Node* p1 = head;
			for (int i = 1; i < num; ++i) {
				if (p1 != NULL) {
					p1 = p1->next;
				}
				else {
					std::cerr << "out of range\n";
					exit(1);
				}
			}
			return p1->data;
		}
	}
	//template<typename T>
	bool count(const T& val) {
		Node* p1 = head;
		while (p1 != NULL) {
			if (p1->data == val) {
				return true; // 找到元素，返回true
			}
			p1 = p1->next;
		}
		return false; // 没有找到元素，返回false
	}
	//template<typename T>
	List<T>& operator=(const List<T>& other) {
		if (!(this == &other)) { // 防止自赋值
			clear(); // 清空当前列表
			Node* current = other.head;
			while (current != NULL) {
				insert(current->data); // 逐个插入其他列表的元素
				current = current->next;
			}
		}
		return *this; // 返回当前对象的引用
	}



	//迭代器
	class Iterator {
	public:
		Iterator(Node* node) : current(node) {}
		T& operator* () { return current->data; }
		Iterator& operator++() { current = current->next; return (*this); }
		Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; }
		bool operator!=(const Iterator& other) { return this->current != other.current; }
	private:
		Node* current;
	};
	Iterator begin() const { return Iterator(head); }//需要定义在Iterator类外，否则会报错
	Iterator end() const { return Iterator(nullptr); }
};
//template class List<alumni>;



	///////////////////////////////	///////////////////////////////	///////////////////////////////



	class alumniFilter {//需filemanager和alumni
	public:
		//已在定义中初始化成员变量，不需要构造函数来再次初始化，否则报错已有主体定义
		//析构函数不需要做什么，因为成员变量是值类型，自动释放
		//如果成员变量是指针类型，则需要手动释放内存
		alumniFilter(const vector<Department>& department_list_):department_list(department_list_){}//常引用仅传值
		alumniFilter(const alumniFilter& other)
			: gender(other.gender),
			year_of_graduation(other.year_of_graduation),
			department(other.department),
			major(other.major),
			Class(other.Class),
			department_list(other.department_list) {}
		void clear_filter() {
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
		void modify_alumniFilter() {
			while (true) {
				cout << "筛选条件：\n 1.性别\n 2.毕业年份\n 3.系/专业/班级\n 4.返回上一级\n";
				int choice = Utils::getChoice(4);
				string choices;
				vector<int> years;
				//vector<Department> department_list;//小心department与alumni.department冲突//修改为类成员
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
					//department_list = fileManager::load_department_list("department.txt");刚需filemanager的原因
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
			std::sort(gender.genders.begin(), gender.genders.end());
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
			std::sort(year_of_graduation.years_of_graduation.begin(), year_of_graduation.years_of_graduation.end());
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
	private:
		struct genders {
			bool is_filtered = false; // 是否筛选
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
		vector<Department> department_list;
	};
	



	//////////////////////////////////////////////////////////////////////////




	class alumni_list {//刚需List<T>和alumniFilter
	public:
		alumni_list() {}
		//alumni_list(List<alumni>& alumniList_) :alumniList(alumniList_) {}
		void sort(bool (*Compare)(const alumni& val1, const alumni& val2)) {
			//List newList;
			auto p1 = alumniList.head;
			auto p2 = alumniList.head;//p1,p2都为目标结点前一个结点
			//alumniList.head = new Node;//内存分配失败会系统自己崩溃，不用过多处理
			while ((p2->next) != NULL) {//
				if (Compare(alumniList.head->data, (p2->next)->data)) {//头结点特殊处理
					auto aim = (p2->next);
					p2->next = aim->next;
					aim->next = alumniList.head;
					alumniList.head = aim;
				}
				p1 = alumniList.head;
				while ((p1->next) != (p2->next)) {//交换
					if (Compare((p1->next)->data, (p2->next)->data)) {//头结点特殊处理
						auto aim = (p2->next);
						p2->next = aim->next;
						aim->next = (p1->next);
						p1->next = aim;
						break;
					}
					p1 = p1->next;
				}
				p2 = p2->next;
			}
		}

		void show() const {
			int i = 1;
			auto p1 = alumniList.head;
			while (p1 != NULL) {
				cout << setw(4) << setfill('0') << i << " ";
				p1->data.show();
				p1 = p1->next;
				i++;
				if (i % 10 == 0) {
					int choice;
					cout << "选项：\n 1.下一页\n 2.返回上一级\n";
					choice = Utils::getChoice(2);
					if (choice == 2) {
						return;
					}
				}
			}
		}

		void filter_show(const alumniFilter& myAlumniFilter) const {
			int i = 1;
			auto p1 = alumniList.head;
			while (p1 != NULL) {
				if (myAlumniFilter.filter(p1->data)) {
					cout << setw(4) << setfill('0') << i << " ";
					p1->data.show();
					i++;
				}
				p1 = p1->next;
				if (i % 10 == 0) {
					int choice;
					cout << "选项：\n 1.下一页\n 2.返回上一级\n";
					choice = Utils::getChoice(2);
					if (choice == 2) {
						break;
					}
				}
			}
		}

		void show_allowChange() {
			int i = 1;
			auto p1 = alumniList.head;
			while (p1 != NULL) {
				cout << setw(4) << setfill('0') << i << " ";
				p1->data.show();
				p1 = p1->next;
				i++;
				if (i % 10 == 0) {
					int choice;
					cout << "选项：\n 1.下一页\n 2.修改\n 3.删除\n 4.返回上一级\n ";
					choice = Utils::getChoice(4);
					if (choice == 2) {
						int num;
						cout << "请输入要修改的校友信息前的序号：";
						num = Utils::getChoice(i);
						p1->data.modify_information();
					}
					else if (choice == 3) {
						int num;
						while (1) {
							cout << "请输入要删除的校友信息前的序号（输入0结束输入）：";
							num = Utils::getChoice(i);
							alumniList.erase(num);
							if (choice == 0) {
								break;
							}
							else {
								cout << "删除成功！\n";
							}
						}
						return;
					}
					else if (choice == 4) {
						break;
					}
				}
			}
		}

		void filter_show_allowChange(const alumniFilter& Filter) {
			int i = 1;
			auto p1 = alumniList.head;
			while (p1 != NULL) {
				if (Filter.filter(p1->data)) {//筛选并标序号
					cout << setw(4) << setfill('0') << i << " ";
					p1->data.show();
					i++;
				}
				p1 = p1->next;
				if (i % 10 == 0) {
					int choice;
					cout << "选项：\n 1.下一页\n 2.修改\n 3.删除\n 4.返回上一级\n ";
					choice = Utils::getChoice(4);
					if (choice == 2) {
						int num;
						cout << "请输入要修改的校友信息前的序号：";
						num = Utils::getChoice(i);
						p1->data.modify_information();
					}
					else if (choice == 3) {
						int num;
						while (1) {
							cout << "请输入要删除的校友信息前的序号（输入0结束输入）：";
							num = Utils::getChoice(i);
							alumniList.erase(num);
							if (choice == 0) {
								break;
							}
							else {
								cout << "删除成功！\n";
							}
						}
						return;
					}
					else if (choice == 4) {
						break;
					}
				}
			}
		}

	alumni_list search_form_line(const std::string& keyword) const {
		alumni_list result;
		auto p1 = alumniList.head;
		int weight = 0;
		set<pair<int, List<alumni>::Node*>, greater<pair<int, List<alumni>::Node*>>> myset;//存储匹配到的结点和权值，按照权值排序,greater<T>表示降序排列
		while (p1 != NULL) {
			string gen;//性别
			if (p1->data.getGender() == 'M') {
				gen = "男";
			}
			else if (p1->data.getGender() == 'W') {
				gen = "女";
			}
			weight += Utils::serach_return_weight(p1->data.getName(), keyword)
				+ Utils::serach_return_weight(to_string(p1->data.getGraduationYear()), keyword)
				+ Utils::serach_return_weight(to_string(p1->data.getAge()), keyword)
				+ Utils::serach_return_weight(gen, keyword)
				+ Utils::serach_return_weight(p1->data.getMajor(), keyword)
				+ Utils::serach_return_weight(p1->data.getClass(), keyword)
				+ Utils::serach_return_weight(p1->data.getDepartment(), keyword);
			if (weight != 0) {//如果没有匹配到任何字段，则不加入结果
				myset.insert(make_pair(weight, p1));//如果匹配到0个以上字段，连带权值加入集合set
			}
			p1 = p1->next;
		}
		for (const auto& item : myset) {//一种遍历容器的方法，const表示item不能被修改，item是pair类型对象，first为权值，second为指向Node的指针，myset是一个容器
			result.alumniList.insert(item.second->data);//将匹配到的结点加入结果
		}
		return result;
	}

	bool empty() const {
		return alumniList.empty();
	}
	void insert(const alumni& val) {
		alumniList.insert(val);
	}
	void erase(int num) {
		alumniList.erase(num);
	}
	alumni operator[](int num) {
		return alumniList[num];
	}
	bool count(const alumni& val) {
		return alumniList.count(val);
	}
	auto begin() const { return  alumniList.begin(); }
	auto end() const { return alumniList.end(); }
private:
	List<alumni> alumniList;
};




///////////////////////////////	///////////////////////////////	///////////////////////////////



class fileManager {//需alumnilist
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
