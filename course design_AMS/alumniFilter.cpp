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
void alumniFilter::show() {
	cout << "ɸѡ������\n";
	cout<<"�Ա�";
	sort(gender.genders.begin(), gender.genders.end());
	for(auto it = gender.genders.begin(); it != gender.genders.end();++it) {
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
bool alumniFilter::filter(const alumni& falumni) const {
	if (gender.is_filtered == true) {
		for (size_t i = 0; i < gender.genders.size(); ++i) {
			if(falumni.getGender()==gender.genders[i]) {
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
