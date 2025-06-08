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
				cout << "筛选条件(未主动选择条件的类别默认全选)：\n 1.性别\n 2.毕业年份\n 3.系/专业/班级\n 4.确认选择\n";
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
				int department_choice;
				int dep_choice;
				int maj_choice;
				int class_choice;
				int continue_choice;
				bool isM = 0, isW = 0;
				std::set<int> selected_years_set;
				switch (choice) {
				case 1:
					cout << "性别筛选(输入序号，切换选择状态，输入0结束输入，示例输入：1)：\n 1.男\n 2.女\n";
					while (gender_choice = Utils::getChoice_0stop(2)) {
						if (gender_choice == 1) {
							auto it = find(gender.genders.begin(), gender.genders.end(), 'M');
							if (it == gender.genders.end()) {
								gender.genders.push_back('M'); // 添加
								cout << "选中：男\n";
							}
							else {
								gender.genders.erase(it);      // 移除
								cout << "取消选中：男\n";
							}
						}
						else if (gender_choice == 2) {
							auto it = find(gender.genders.begin(), gender.genders.end(), 'W');
							if (it == gender.genders.end()) {
								gender.genders.push_back('W'); // 添加
								cout << "选中：女\n";
							}
							else {
								gender.genders.erase(it);      // 移除
								cout << "取消选中：女\n";
							}
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
					cout << "毕业年份筛选(输入序号,切换选择状态,输入0结束输入，示例输入：1)：\n";
					while (true) {
						year_choice = Utils::getChoice_0stop(years.size()); // 获取用户输入
						if (year_choice == 0) break;                 // 输入0退出

						int selected_year = years[year_choice - 1];   // 获取实际年份
						auto it = selected_years_set.find(selected_year);//set是集合

						// 切换选中状态
						if (it == selected_years_set.end()) {
							selected_years_set.insert(selected_year); // 未选中 → 添加
							cout << "已选中年份: " << selected_year << endl;
						}
						else {
							selected_years_set.erase(it);            // 已选中 → 移除
							cout << "已取消年份: " << selected_year << endl;
						}

						// 实时显示当前已选年份
						cout << "当前已选: ";
						for (int year : selected_years_set) {
							cout << year << " ";
						}
						cout << endl;
					}

					// 将最终结果保存到 year_of_graduation
					year_of_graduation.years_of_graduation.assign(
						selected_years_set.begin(),
						selected_years_set.end()
					);

					if (year_of_graduation.years_of_graduation.size() == 0) {
						year_of_graduation.is_filtered = false;
					}
					else {
						year_of_graduation.is_filtered = true;
					}
					break;
				case 3:
					//department_list = fileManager::load_department_list("department.txt");以作为成员存在
					cout << "系/专业/班级筛选(输入序号,选择筛选条件)：\n 1.系\n 2.专业\n 3.班级\n";
					department_choice = Utils::getChoice(3);
					switch (department_choice) {
					case 1: { // 系筛选
						cout << "请选择系（输入序号切换选择状态，输入0结束）：\n";
						for (size_t i = 0; i < department_list.size(); ++i) {
							cout << setfill('0') << setw(2) << i + 1 << " "
								<< department_list[i].getDepartmentName() << endl;
						}

						while (true) {
							dep_choice = Utils::getChoice_0stop(department_list.size());
							if (dep_choice == 0) break;

							const string& dept = department_list[dep_choice - 1].getDepartmentName();//相当于define字符替换
							auto it = find(department.departments.begin(), department.departments.end(), dept);

							if (it == department.departments.end()) {
								department.departments.push_back(dept);
								cout << "已选中系: " << dept << endl;
							}
							else {
								department.departments.erase(it);
								cout << "已取消系: " << dept << endl;
							}

							cout << "当前已选: ";
							for (const auto& d : department.departments) cout << d << " ";
							cout << endl;
						}
						department.is_filtered = !department.departments.empty();
						break;
					}
					case 2: { // 专业筛选
						cout << "请先选择系（单选）：\n";
						for (size_t i = 0; i < department_list.size(); ++i) {
							cout << setfill('0') << setw(2) << i + 1 << " "
								<< department_list[i].getDepartmentName() << endl;
						}

						dep_choice = Utils::getChoice(department_list.size());
						Department& curDept = department_list[dep_choice - 1];

						cout << "请选择专业（输入序号切换选择状态，输入0结束）：\n";
						for (size_t i = 0; i < curDept.getMajorList().size(); ++i) {
							cout << setfill('0') << setw(2) << i + 1 << " "
								<< curDept.getMajorList()[i].getMajorName() << endl;
						}

						while (true) {
							maj_choice = Utils::getChoice_0stop(curDept.getMajorList().size());
							if (maj_choice == 0) break;

							const string& maj = curDept.getMajorList()[maj_choice - 1].getMajorName();
							auto it = find(major.majors.begin(), major.majors.end(), maj);

							if (it == major.majors.end()) {
								major.majors.push_back(maj);
								cout << "已选中专业: " << maj << endl;
							}
							else {
								major.majors.erase(it);
								cout << "已取消专业: " << maj << endl;
							}

							cout << "当前已选: ";
							for (const auto& m : major.majors) cout << m << " ";
							cout << endl;
						}
						major.is_filtered = !major.majors.empty();
						break;
					}
					case 3: { // 班级筛选
						cout << "请先选择系（单选）：\n";
						for (size_t i = 0; i < department_list.size(); ++i) {
							cout << setfill('0') << setw(2) << i + 1 << " "
								<< department_list[i].getDepartmentName() << endl;
						}

						dep_choice = Utils::getChoice(department_list.size());
						Department& curDept = department_list[dep_choice - 1];

						cout << "请选择专业（单选）：\n";
						for (size_t i = 0; i < curDept.getMajorList().size(); ++i) {
							cout << setfill('0') << setw(2) << i + 1 << " "
								<< curDept.getMajorList()[i].getMajorName() << endl;
						}
						maj_choice = Utils::getChoice(curDept.getMajorList().size());
						Major& curMajor = curDept.getMajorList()[maj_choice - 1];

						cout << "请选择班级（输入序号切换选择状态，输入0结束）：\n";
						for (size_t i = 0; i < curMajor.getClassList().size(); ++i) {
							cout << setfill('0') << setw(2) << i + 1 << " "
								<< curMajor.getClassList()[i].getClassNumber() << endl;
						}

						while (true) {
							class_choice = Utils::getChoice_0stop(curMajor.getClassList().size());
							if (class_choice == 0) break;

							const string& cls = curMajor.getClassList()[class_choice - 1].getClassNumber();
							auto it = find(Class.Classes.begin(), Class.Classes.end(), cls);

							if (it == Class.Classes.end()) {
								Class.Classes.push_back(cls);
								cout << "已选中班级: " << cls << endl;
							}
							else {
								Class.Classes.erase(it);
								cout << "已取消班级: " << cls << endl;
							}

							cout << "当前已选: ";
							for (const auto& c : Class.Classes) cout << c << " ";
							cout << endl;
						}
						Class.is_filtered = !Class.Classes.empty();
						break;
					}
					}
						case 4:
							return;
				}
			}
		}
		void show() {
			cout << "筛选条件：\n";
			cout << "性别：";
			if (gender.genders.empty()) {
				cout << "未设置";
			}
			else {
				std::sort(gender.genders.begin(), gender.genders.end());
				bool first = true;
				for (char g : gender.genders) {
					if (!first) cout << "、";
					cout << (g == 'M' ? "男" : "女");
					first = false;
				}
			}
			cout << endl;

			// 2. 毕业年份筛选条件
			cout << "毕业年份：";
			if (year_of_graduation.years_of_graduation.empty()) {
				cout << "未设置";
			}
			else {
				std::sort(year_of_graduation.years_of_graduation.begin(),
					year_of_graduation.years_of_graduation.end());
				bool first = true;
				for (int year : year_of_graduation.years_of_graduation) {
					if (!first) cout << "、";
					cout << year;
					first = false;
				}
			}
			cout << endl;

			// 3. 系筛选条件
			cout << "系：";
			if (department.departments.empty()) {
				cout << "未设置";
			}
			else {
				std::sort(department.departments.begin(), department.departments.end());
				bool first = true;
				for (const auto& dept : department.departments) {
					if (!first) cout << "、";
					cout << dept;
					first = false;
				}
			}
			cout << endl;

			// 4. 专业筛选条件
			cout << "专业：";
			if (major.majors.empty()) {
				cout << "未设置";
			}
			else {
				std::sort(major.majors.begin(), major.majors.end());
				bool first = true;
				for (const auto& maj : major.majors) {
					if (!first) cout << "、";
					cout << maj;
					first = false;
				}
			}
			cout << endl;

			// 5. 班级筛选条件
			cout << "班级：";
			if (Class.Classes.empty()) {
				cout << "未设置";
			}
			else {
				std::sort(Class.Classes.begin(), Class.Classes.end());
				bool first = true;
				for (const auto& cls : Class.Classes) {
					if (!first) cout << "、";
					cout << cls;
					first = false;
				}
			}
			cout << endl;
			cout << endl;
		}
		bool filter(const alumni& falumni) const {
			if (gender.is_filtered == true) {
				for (size_t i = 0; i < gender.genders.size(); ++i) {
					if (falumni.getGender() == gender.genders[i]) {
						break;
					}
					if (i == gender.genders.size() - 1) {
						return false; //如果没有匹配到，则返回false
					}
				}
			}
			if (year_of_graduation.is_filtered == true) {
				for (size_t i = 0; i < year_of_graduation.years_of_graduation.size(); ++i) {
					if (falumni.getGraduationYear() == year_of_graduation.years_of_graduation[i]) {
						break;
					}
					if (i==year_of_graduation.years_of_graduation.size() - 1) {
						return false; //如果没有匹配到，则返回false
					}
				}
			}
			if (department.is_filtered == true) {
				for (size_t i = 0; i < department.departments.size(); ++i) {
					if (falumni.getDepartment() == department.departments[i]) {
						break;
					}
					if (i == department.departments.size() - 1) {
						return false; //如果没有匹配到，则返回false
					}
				}
			}
			if (major.is_filtered == true) {
				for (size_t i = 0; i < major.majors.size(); ++i) {
					if (falumni.getMajor() == major.majors[i]) {
						break;
					}
					if (i == major.majors.size() - 1) {
						return false; //如果没有匹配到，则返回false
					}
				}
			}
			if (Class.is_filtered == true) {
				for (size_t i = 0; i < Class.Classes.size(); ++i) {
					if (falumni.getClass() == Class.Classes[i]) {
						break;
					}
					if (i == Class.Classes.size() - 1) {
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
			// 处理边界情况
			if (alumniList.head == nullptr || alumniList.head->next == nullptr) {
				return;
			}

			// 使用auto但正确初始化
			auto sorted = decltype(alumniList.head)(nullptr);
		    auto curr = alumniList.head;  // 当前待排序节点

			while (curr != nullptr) {
				auto next = curr->next;  // 保存下一个待处理节点

				// 在已排序部分中找到插入位置
				if (sorted == nullptr || Compare(curr->data, sorted->data)) {
					// 插入到已排序部分的头部
					curr->next = sorted;
					sorted = curr;
				}
				else {
					// 在已排序部分中寻找插入点
					auto pos = sorted;
					while (pos->next != nullptr && !Compare(curr->data, pos->next->data)) {
						pos = pos->next;
					}
					// 执行插入
					curr->next = pos->next;
					pos->next = curr;
				}

				curr = next;  // 处理下一个节点
			}

			alumniList.head = sorted;  // 更新链表头
			/*
			//List newList;
			auto p1 = alumniList.head;
			auto p2 = alumniList.head;//p1,p2都为目标结点前一个结点
			bool ist = false;//p2下一个结点是否与前面结点交换
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
						ist = true;//如果交换了，则标志位为true
						break;
					}
					p1 = p1->next;
				}
				if (!ist) {//如果交换了，p2下个结点自然是上次比较结点的后一个结点，没交换则需要后移p2
				p2 = p2->next;
				}
			}
			*/
		}

		void show() const {
			int i = 1;
			auto p1 = alumniList.head;
			while (p1 != NULL) {
				cout << setw(4) << setfill('0') << i << " ";
				p1->data.show();
				p1 = p1->next;
				i++;
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
			}
		}

		void show_allowChange() {
			int i = 1;
			auto p1 = alumniList.head;
			int choice;
			int count = 0;
			while (p1 != NULL) {
				cout << setw(4) << setfill('0') << i << " ";
				p1->data.show();
				p1 = p1->next;
				i++;
			}
			cout << "-------------------------\n";
			cout << "选项：\n1.修改\n2.删除\n3.返回上一级\n ";
			cout << "-------------------------\n";
			choice = Utils::getChoice(4);
			if (choice == 1) {
				int num;
				cout << "请输入要修改的校友信息前的序号：";
				num = Utils::getChoice(i-1);
				int c = 1;
				p1 = alumniList.head;
				while (c < num) {
					p1 = p1->next;
					c++;
				}
				p1->data.modify_information();
				cout << "修改成功！\n";
			}
			else if (choice == 2) {
				int num;
				cout << "请输入要删除的校友信息前的序号：";
				num = Utils::getChoice(i-1);
				alumniList.erase(num);
				cout << "删除成功！\n";
			}
			else if (choice == 3) {
				return;
			}
		}

		void filter_show_allowChange(const alumniFilter& Filter) {
			int i = 1;
			int choice;
			auto p1 = alumniList.head;
			while (p1 != NULL) {
				if (Filter.filter(p1->data)) {//筛选并标序号
					cout << setw(4) << setfill('0') << i << " ";
					p1->data.show();
					i++;
				}
				p1 = p1->next;
			}
			cout << "-------------------------\n";
			cout << "选项：\n1.修改\n2.删除\n3.返回上一级\n ";
			cout << "-------------------------\n";
			choice = Utils::getChoice(3);
			if (choice == 1) {
				int num;
				cout << "请输入要修改的校友信息前的序号：";
				num = Utils::getChoice(i-1);
				int c = 1;
				p1 = alumniList.head;
				while (c < num) {
					if (Filter.filter(p1->data)) {//筛选并标序号
						c++;
					}
					p1 = p1->next;
				}
				p1->data.modify_information();
				cout << "修改成功！\n";
			}
			else if (choice == 2) {
				int num;
				cout << "请输入要删除的校友信息前的序号：";
				num = Utils::getChoice(i-1);
				alumniList.erase(num);
				cout << "删除成功！\n";
			}
			else if (choice == 3) {
				return;
			}
		}

	alumni_list search_form_line(const std::string& keyword) const {
		alumni_list result;
		if (keyword.empty()) return result;

		auto p1 = alumniList.head;
		std::set<std::pair<int, List<alumni>::Node*>, std::greater<>> matches;

		while (p1 != nullptr) {
			int weight = 0;  // 每次循环重置权重

			// 统一使用字符串形式比较
			std::string gender_str = (p1->data.getGender() == 'M') ?"男" : "女";
			std::string year_str = std::to_string(p1->data.getGraduationYear());
			std::string age_str = std::to_string(p1->data.getAge());

			// 计算各字段权重
			weight += Utils::search_return_weight(p1->data.getName(), keyword) * 5;       // 姓名权重最高
			weight += Utils::search_return_weight(gender_str, keyword) * 2;
			weight += Utils::search_return_weight(year_str, keyword) * 3;
			weight += Utils::search_return_weight(age_str, keyword);
			weight += Utils::search_return_weight(p1->data.getDepartment(), keyword) * 4;
			weight += Utils::search_return_weight(p1->data.getMajor(), keyword) * 3;
			weight += Utils::search_return_weight(p1->data.getClass(), keyword)*2;

			if (weight > 0) {
				matches.emplace(weight, p1); //使用 emplace 替代 make_pair,​​避免临时对象的构造和拷贝，直接原地构造元素，提升性能​​。


			}
			p1 = p1->next;
		}

		// 按权重降序插入结果
		for (const auto& match : matches) {
			int w = match.first;
			auto* node = match.second;
			result.alumniList.insert(node->data);
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
	alumni_list& operator=(const alumni_list& other) {
		this->alumniList = other.alumniList;
		return (*this);
	}
	/*List<T>& operator=(const List<T>& other) {
		if (!(this == &other)) { // 防止自赋值
			clear(); // 清空当前列表
			Node* current = other.head;
			while (current != NULL) {
				insert(current->data); // 逐个插入其他列表的元素
				current = current->next;
			}
		}
		return *this; // 返回当前对象的引用
	}*/
	bool count(const alumni& val) {
		return alumniList.count(val);
	}
	alumni find(const alumni& val) {
		auto p1 = alumniList.head;
		while (p1 != NULL) {
			if (p1->data == val) {
				return p1->data; // 找到元素，返回true
			}
			p1 = p1->next;
		}
		return val; // 没有找到元素，返回false
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
		char gender=0;
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
			if (tempInformation == "男") {
				gender='M'; // 将字符串转换为字符
			}
			else if (tempInformation == "女") {
				gender = 'W'; // 将字符串转换为字符
			}
			getline(infile, tempInformation, ',');
			age = stoi(tempInformation); // 将字符串转换为整数
			getline(infile, tempInformation, ',');
			year_of_graduation = stoi(tempInformation); // 将字符串转换为整数
			getline(infile, department, ',');
			getline(infile, major, ',');
			getline(infile, Class, ',');
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
