
/*


#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
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
class Department;//���ǰ������������ѭ����������
class fileManager {
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
class alumniFilter{
public:
	//���ڶ����г�ʼ����Ա����������Ҫ���캯�����ٴγ�ʼ�������򱨴��������嶨��
	//������������Ҫ��ʲô����Ϊ��Ա������ֵ���ͣ��Զ��ͷ�
	//�����Ա������ָ�����ͣ�����Ҫ�ֶ��ͷ��ڴ�


	void modify_alumniFilter() {
		while (true) {
			cout << "ɸѡ������\n 1.�Ա�\n 2.��ҵ���\n 3.ϵ/רҵ/�༶\n 4.������һ��\n";
			int choice = Utils::getChoice(4);
			string choices;
			vector<int> years;
			vector<Department> department_list;//С��department��alumni.department��ͻ
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
				department_list = fileManager::load_department_list("department.txt");
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
		sort(gender.genders.begin(), gender.genders.end());
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
	void clear_filter();//���ɸѡ����
private:
	struct genders {
		bool is_filtered= false; // �Ƿ�ɸѡ
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
};


*/