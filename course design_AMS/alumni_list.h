/*

//alumni_list.h
#pragma once

// �Ȱ���alumni����������
#include "alumni.h"
#include "visitor.h"

// �ٰ�������alumni��ģ��
#include "myList.h"

// ��������������
#include "alumniFilter.h"
class alumni_list{
public:
	alumni_list(){}
	//alumni_list(List<alumni>& alumniList_) :alumniList(alumniList_) {}
	void sort(bool (*Compare)(const alumni& val1, const alumni& val2));//����������ԭ�����в�������
	void show()const;//��ҳչʾ
	void filter_show(const alumniFilter& filter)const;//ɸѡչʾ
	void show_allowChange();//�����޸ĵ�չʾ
	void filter_show_allowChange(const alumniFilter& alumniFilter);//�����޸ĵ�ɸѡչʾ
	alumni_list search_form_line(const std::string& keyword) const;//�������ܣ�����һ���µ�alumni_list
private:
	List<int> alumniList;
};
*/


//alumni_list.h
#pragma once

// �Ȱ���alumni����������
#include "alumni.h"
//myList.h
#pragma once//ͷ�ļ���������ֹ�ظ�����
#include <cstdlib>
#include "fileManager.h"
// ��������������
#include "alumniFilter.h"
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
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
class Department;//���ǰ������������ѭ����������

template<typename T>
class List {
public:
	struct Node {//Node�ṹ���趨����Iterator��֮ǰ������ᱨ��
		T data;
		Node* next = NULL;
	};
	Node* head;
	//template<typename T>
	List() {
		head = NULL;
	}
	List(const List<T>& other) : head(NULL) {//�������캯��
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
		head = new Node;//�ڴ����ʧ�ܻ�ϵͳ�Լ����������ù��ദ��
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
					p1 = p1->next;//p1Ϊɾ�����ǰһ�����
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
				return true; // �ҵ�Ԫ�أ�����true
			}
			p1 = p1->next;
		}
		return false; // û���ҵ�Ԫ�أ�����false
	}
	//template<typename T>
	List<T>& operator=(const List<T>& other) {
		if (!(this == &other)) { // ��ֹ�Ը�ֵ
			clear(); // ��յ�ǰ�б�
			Node* current = other.head;
			while (current != NULL) {
				insert(current->data); // ������������б��Ԫ��
				current = current->next;
			}
		}
		return *this; // ���ص�ǰ���������
	}



	//������
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
	Iterator begin() const { return Iterator(head); }//��Ҫ������Iterator���⣬����ᱨ��
	Iterator end() const { return Iterator(nullptr); }
};
//template class List<alumni>;



	///////////////////////////////	///////////////////////////////	///////////////////////////////



	class alumniFilter {//��filemanager��alumni
	public:
		//���ڶ����г�ʼ����Ա����������Ҫ���캯�����ٴγ�ʼ�������򱨴��������嶨��
		//������������Ҫ��ʲô����Ϊ��Ա������ֵ���ͣ��Զ��ͷ�
		//�����Ա������ָ�����ͣ�����Ҫ�ֶ��ͷ��ڴ�
		alumniFilter(const vector<Department>& department_list_):department_list(department_list_){}//�����ý���ֵ
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
				cout << "ɸѡ������\n 1.�Ա�\n 2.��ҵ���\n 3.ϵ/רҵ/�༶\n 4.������һ��\n";
				int choice = Utils::getChoice(4);
				string choices;
				vector<int> years;
				//vector<Department> department_list;//С��department��alumni.department��ͻ//�޸�Ϊ���Ա
				int gender_choice;
				time_t t = time(0);
				tm now;  // ���屾�ر����洢ʱ����Ϣ
				// ʹ���̰߳�ȫ�� localtime_s ��� localtime
				if (localtime_s(&now, &t) == 0) {
					// �ɹ���ȡ����ʱ�䣬�ɲ��� now �ṹ��
				}
				else {
					// �������
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
					cout << "�Ա�ɸѡ(������ţ��ɶ�ѡ��ѡ������س�ȷ�ϣ�ʾ�����룺1 2)��\n 1.��\n 2.Ů\n";
					while (gender_choice = Utils::getChoice(2)) {
						if (gender_choice == 0) break; // �������0���˳�ѡ��
						else if (gender_choice == 1) {
							gender.genders.push_back('M'); // ��ѡ����Ա���ӵ�ɸѡ������
						}
						else if (gender_choice == 2) {
							gender.genders.push_back('W'); // ��ѡ����Ա���ӵ�ɸѡ������
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
					if (current_month >= 7) {//�����ǰ�·ݴ��ڵ���7�£����ҵ���Ϊ��ǰ���
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
					cout << "��ҵ���ɸѡ(������ţ��ɶ�ѡ��ѡ������0ȷ�ϣ�ʾ�����룺1 2)��\n";
					while (year_choice = Utils::getChoice(years.size())) {//Ӧ�ûᱨ����ΪgetChoice�����������
						if (year_choice == 0) break; // �������0���˳�ѡ��
						year_of_graduation.years_of_graduation.push_back(years[year_choice - 1]);// ��ѡ��������ӵ�ɸѡ������
					}
					if (year_of_graduation.years_of_graduation.size() == 0) {
						year_of_graduation.is_filtered = false;
					}
					else {
						year_of_graduation.is_filtered = true;
					}
					break;
				case 3:
					//department_list = fileManager::load_department_list("department.txt");����filemanager��ԭ��
					cout << "ϵ/רҵ/�༶ɸѡ(������ţ��ɶ�ѡ��ѡ�����س�ȷ��ѡ��)��\n 1.ϵ\n 2.רҵ\n 3.�༶\n";

					if (department_choice == 1) {
						cout << "��ѡ��ϵ��\n";
						for (size_t i = 0; i < department_list.size(); ++i) {//��ӡϵ�б�ʹ��size_t����Ϊdepartment_list.size()���ص���size_t���ͣ�������int���¾���
							cout << setfill('0') << setw(2) << i + 1 << " " << department_list[i].getDepartmentName() << endl;
						}
						while (dep_choice = Utils::getChoice(department_list.size())) {//��ȡ�û�ѡ���ϵ
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
						cout << "��ѡ��ϵ(��ѡ)��\n";//��ѡ��ϵ��Ȼ��չ��רҵ
						for (size_t i = 0; i < department_list.size(); ++i) {
							cout << setfill('0') << setw(2) << i + 1 << " " << department_list[i].getDepartmentName() << endl;
						}
						dep_choice = Utils::getChoice(department_list.size());
						Department curDept = department_list[dep_choice - 1];
						cout << "��ѡ��רҵ��\n";
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
						cout << "��ѡ��ϵ(��ѡ)��\n";//��ѡ��ϵ��Ȼ��չ��רҵ
						for (size_t i = 0; i < department_list.size(); ++i) {
							cout << setfill('0') << setw(2) << i + 1 << " " << department_list[i].getDepartmentName() << endl;
						}

						dep_choice = Utils::getChoice(department_list.size());
						Department curDept = department_list[dep_choice - 1];
						cout << "��ѡ��רҵ��\n";
						for (size_t i = 0; i < curDept.getMajorList().size(); ++i) {
							cout << setfill('0') << setw(2) << i + 1 << " " << curDept.getMajorList()[i].getMajorName() << endl;
						}

						maj_choice = Utils::getChoice(curDept.getMajorList().size());
						Major curMajor = curDept.getMajorList()[maj_choice - 1];
						cout << "��ѡ��༶��\n";
						for (size_t i = 0; i < curMajor.getClassList().size(); ++i) {//��ӡ�༶�б�
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
				cout << "�Ƿ����ɸѡ��\n 1.��\n 2.��\n";

				if (continue_choice == 2) {
					break;
				}
				//������ϵ��רҵ���Ͱ༶
			}
		}
		void show() {
			cout << "ɸѡ������\n";
			cout << "�Ա�";
			std::sort(gender.genders.begin(), gender.genders.end());
			for (auto it = gender.genders.begin(); it != gender.genders.end(); ++it) {
				if (*it == 'M') {
					cout << "��\n";
				}
				else if (*it == 'W') {
					cout << "Ů\n";
				}
			}
			cout << endl;
			cout << "��ҵ��ݣ�\n";
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
						return false; //���û��ƥ�䵽���򷵻�false
					}
				}
			}
			if (year_of_graduation.is_filtered == true) {
				for (size_t i = 0; i < year_of_graduation.years_of_graduation.size(); ++i) {
					if (falumni.getGraduationYear() == year_of_graduation.years_of_graduation[i]) {
						break;
					}
					if (year_of_graduation.years_of_graduation.size() - 1) {
						return false; //���û��ƥ�䵽���򷵻�false
					}
				}
			}
			if (department.is_filtered == true) {
				for (size_t i = 0; i < department.departments.size(); ++i) {
					if (falumni.getDepartment() == department.departments[i]) {
						break;
					}
					if (department.departments.size() - 1) {
						return false; //���û��ƥ�䵽���򷵻�false
					}
				}
			}
			if (major.is_filtered == true) {
				for (size_t i = 0; i < major.majors.size(); ++i) {
					if (falumni.getMajor() == major.majors[i]) {
						break;
					}
					if (major.majors.size() - 1) {
						return false; //���û��ƥ�䵽���򷵻�false
					}
				}
			}
			if (Class.is_filtered == true) {
				for (size_t i = 0; i < Class.Classes.size(); ++i) {
					if (falumni.getClass() == Class.Classes[i]) {
						break;
					}
					if (Class.Classes.size() - 1) {
						return false; //���û��ƥ�䵽���򷵻�false
					}
				}
			}
			return true;
		}
	private:
		struct genders {
			bool is_filtered = false; // �Ƿ�ɸѡ
			std::vector<char> genders;
		}gender;
		struct years_of_graduation {
			bool is_filtered = false; // �Ƿ�ɸѡ
			std::vector<int> years_of_graduation;
		}year_of_graduation;
		struct departments {
			bool is_filtered = false; // �Ƿ�ɸѡ
			std::vector<std::string> departments;
		}department;
		struct majors {
			bool is_filtered = false; // �Ƿ�ɸѡ
			std::vector<std::string> majors;
		}major;
		struct Classes {
			bool is_filtered = false; // �Ƿ�ɸѡ
			std::vector<std::string> Classes;
		}Class;
		vector<Department> department_list;
	};
	



	//////////////////////////////////////////////////////////////////////////




	class alumni_list {//����List<T>��alumniFilter
	public:
		alumni_list() {}
		//alumni_list(List<alumni>& alumniList_) :alumniList(alumniList_) {}
		void sort(bool (*Compare)(const alumni& val1, const alumni& val2)) {
			//List newList;
			auto p1 = alumniList.head;
			auto p2 = alumniList.head;//p1,p2��ΪĿ����ǰһ�����
			//alumniList.head = new Node;//�ڴ����ʧ�ܻ�ϵͳ�Լ����������ù��ദ��
			while ((p2->next) != NULL) {//
				if (Compare(alumniList.head->data, (p2->next)->data)) {//ͷ������⴦��
					auto aim = (p2->next);
					p2->next = aim->next;
					aim->next = alumniList.head;
					alumniList.head = aim;
				}
				p1 = alumniList.head;
				while ((p1->next) != (p2->next)) {//����
					if (Compare((p1->next)->data, (p2->next)->data)) {//ͷ������⴦��
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
					cout << "ѡ�\n 1.��һҳ\n 2.������һ��\n";
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
					cout << "ѡ�\n 1.��һҳ\n 2.������һ��\n";
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
					cout << "ѡ�\n 1.��һҳ\n 2.�޸�\n 3.ɾ��\n 4.������һ��\n ";
					choice = Utils::getChoice(4);
					if (choice == 2) {
						int num;
						cout << "������Ҫ�޸ĵ�У����Ϣǰ����ţ�";
						num = Utils::getChoice(i);
						p1->data.modify_information();
					}
					else if (choice == 3) {
						int num;
						while (1) {
							cout << "������Ҫɾ����У����Ϣǰ����ţ�����0�������룩��";
							num = Utils::getChoice(i);
							alumniList.erase(num);
							if (choice == 0) {
								break;
							}
							else {
								cout << "ɾ���ɹ���\n";
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
				if (Filter.filter(p1->data)) {//ɸѡ�������
					cout << setw(4) << setfill('0') << i << " ";
					p1->data.show();
					i++;
				}
				p1 = p1->next;
				if (i % 10 == 0) {
					int choice;
					cout << "ѡ�\n 1.��һҳ\n 2.�޸�\n 3.ɾ��\n 4.������һ��\n ";
					choice = Utils::getChoice(4);
					if (choice == 2) {
						int num;
						cout << "������Ҫ�޸ĵ�У����Ϣǰ����ţ�";
						num = Utils::getChoice(i);
						p1->data.modify_information();
					}
					else if (choice == 3) {
						int num;
						while (1) {
							cout << "������Ҫɾ����У����Ϣǰ����ţ�����0�������룩��";
							num = Utils::getChoice(i);
							alumniList.erase(num);
							if (choice == 0) {
								break;
							}
							else {
								cout << "ɾ���ɹ���\n";
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
		set<pair<int, List<alumni>::Node*>, greater<pair<int, List<alumni>::Node*>>> myset;//�洢ƥ�䵽�Ľ���Ȩֵ������Ȩֵ����,greater<T>��ʾ��������
		while (p1 != NULL) {
			string gen;//�Ա�
			if (p1->data.getGender() == 'M') {
				gen = "��";
			}
			else if (p1->data.getGender() == 'W') {
				gen = "Ů";
			}
			weight += Utils::serach_return_weight(p1->data.getName(), keyword)
				+ Utils::serach_return_weight(to_string(p1->data.getGraduationYear()), keyword)
				+ Utils::serach_return_weight(to_string(p1->data.getAge()), keyword)
				+ Utils::serach_return_weight(gen, keyword)
				+ Utils::serach_return_weight(p1->data.getMajor(), keyword)
				+ Utils::serach_return_weight(p1->data.getClass(), keyword)
				+ Utils::serach_return_weight(p1->data.getDepartment(), keyword);
			if (weight != 0) {//���û��ƥ�䵽�κ��ֶΣ��򲻼�����
				myset.insert(make_pair(weight, p1));//���ƥ�䵽0�������ֶΣ�����Ȩֵ���뼯��set
			}
			p1 = p1->next;
		}
		for (const auto& item : myset) {//һ�ֱ��������ķ�����const��ʾitem���ܱ��޸ģ�item��pair���Ͷ���firstΪȨֵ��secondΪָ��Node��ָ�룬myset��һ������
			result.alumniList.insert(item.second->data);//��ƥ�䵽�Ľ�������
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



class fileManager {//��alumnilist
public:
	static void save_alumni_list(const string& fileName, const alumni_list& alumniList) {// ����У���б��ļ� 
		if (alumniList.empty()) {
			return; // ����б�Ϊ�գ�ֱ�ӷ���
		}
		ofstream outfile(fileName);//��Ӧʹ��"fileName"
		if (!outfile) { // ����ļ��Ƿ�ɹ���
			cerr << "�޷����ļ�: " << fileName << endl;
			return;
		}
		outfile << "�˺�,����,����,����ƴ��,�Ա�,����,��ҵ���,ϵ,רҵ,�༶,��ַ,�绰����,QQ,��������\n"; // д���ͷ��CSV��ʽ,ͨ����ǿ��������Excel��(�ָ����Ƽ�����\t����
		auto it = alumniList.begin();//
		while (it != alumniList.end()) {
			outfile << (*it).getUserName() << "," //�Զ��������������'*'��*it��Ϊalumni����
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
			++it; // �ƶ�����һ��Ԫ��
		}
		outfile.close(); // �ر��ļ�
	}
	static alumni_list load_alumni_list(const string& fileName) {
		ifstream infile(fileName);
		if (!infile) { // ����ļ��Ƿ�ɹ���
			cerr << "�޷����ļ�: " << fileName << endl;
			return alumni_list(); // ����һ���յ� alumni_list
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
		getline(infile, line); // ��ȡ��ͷ
		while (getline(infile, userName_, ',')) {//�����ļ���ֹ������
			getline(infile, password_, ',');
			getline(infile, name, ',');
			getline(infile, pinyin, ','); // ��ȡ����ƴ��
			getline(infile, tempInformation, ',');
			gender = tempInformation[0]; // �����Ա��ǵ����ַ�
			getline(infile, tempInformation, ',');
			age = stoi(tempInformation); // ���ַ���ת��Ϊ����
			getline(infile, tempInformation, ',');
			year_of_graduation = stoi(tempInformation); // ���ַ���ת��Ϊ����
			getline(infile, department, ',');
			getline(infile, major, ',');
			getline(infile, tempInformation, ',');
			Class = stoi(tempInformation); // ���ַ���ת��Ϊ����
			getline(infile, address, ',');
			getline(infile, phoneNumber, ',');
			getline(infile, qq, ',');
			getline(infile, email); // ���һ��û�ж���
			alumni newAlumni(userName_, password_, name, pinyin, gender, age, year_of_graduation, department, major, Class, address, phoneNumber, qq, email); // ����һ���µ� alumni ����
			alumniList.insert(newAlumni); // ���¶�����뵽 alumniList ��
		}
		infile.close(); // �ر��ļ�
		return alumniList; // ���ؼ��ص� alumni_list
	}
	template <typename T>
	static void save_T_list(const string& fileName, List<T>& TList) {
		if (TList.empty()) {
			return; // ����б�Ϊ�գ�ֱ�ӷ���
		}
		ofstream outfile(fileName);//��Ӧʹ��"fileName"
		if (!outfile) { // ����ļ��Ƿ�ɹ���
			cerr << "�޷����ļ�: " << fileName << endl;
			return;
		}
		outfile << "�˺�,����\n"; // д���ͷ��CSV��ʽ,ͨ����ǿ��������Excel��(�ָ����Ƽ�����\t����
		auto it = TList.begin();
		while (it != TList.end()) {
			outfile << (*it).getUserName() << "," //�Զ��������������'*'��*it��Ϊalumni����
				<< (*it).getPassword() << "\n";
			++it; // �ƶ�����һ��Ԫ��
		}
		outfile.close(); // �ر��ļ�
	}

	static vector<Department> load_department_list(const string& fileName) {
		vector<Department> departmentList;
		ifstream infile(fileName);
		if (!infile) { // ����ļ��Ƿ�ɹ���
			cerr << "�޷����ļ�: " << fileName << endl;
			return departmentList; // ����һ���յĲ����б�
		}
		string departmentName;
		string pre_departmentName = ""; // ���ڼ�¼��һ����������
		string majorName;
		string pre_majorName = ""; // ���ڼ�¼��һ��רҵ����
		string className;
		string pre_className = ""; // ���ڼ�¼��һ���༶����
		string line;
		getline(infile, line);
		while (getline(infile, departmentName, ',')) {//�����ļ���ֹ������
			if (!getline(infile, majorName, ',')) break;//��ֹ�������
			if (!getline(infile, className)) break;
			if (departmentName != pre_departmentName) {
				pre_departmentName = departmentName; // ������һ����������
				Department newDepartment(departmentName); // ����һ���µĲ��Ŷ���
				departmentList.push_back(newDepartment); // ���²�����ӵ��б���
			}
			vector<Major>& majors = departmentList.back().getMajorList(); // ��ȡ��ǰ���ŵ�רҵ�б�
			if (majorName != pre_majorName) {
				pre_majorName = majorName;
				Major newmajor(majorName);
				majors.push_back(newmajor);
			}
			vector<Class>& classes = majors.back().getClassList(); // ��ȡ��ǰרҵ�İ༶�б�
			if (className != pre_className) {
				pre_className = className;
				Class newClass(className);
				classes.push_back(newClass);
			}
		}
		infile.close(); // �ر��ļ�
		return departmentList; // ���ؼ��صĲ����б�
	}
	template <typename T>
	static List<T> load_T_list(const std::string& fileName) {
		std::ifstream infile(fileName);
		if (!infile) { // ����ļ��Ƿ�ɹ���
			cerr << "�޷����ļ�: " << fileName << endl;
			return List<T>(); // ����һ���յ� List<T>
		}
		string line;
		string userName_;
		string password_;
		List<T> TList; // ����һ��ͨ���б�
		getline(infile, line); // ��ȡ��ͷ
		while (getline(infile, userName_, ',')) {//�����ļ���ֹ������
			getline(infile, password_);
			T item(userName_, password_);
			TList.insert(item);
		}
		infile.close(); // �ر��ļ�
		return TList; // ���ؼ��ص�ͨ���б�
	}

}
;
