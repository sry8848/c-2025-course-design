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
	cout<<"ɸѡ������\n 1.�Ա�\n 2.��ҵ���\n 3.ϵ/רҵ/�༶\n 4.������һ��\n";
	int choice = Utils::getChoice(4);
	string choices;
	switch (choice) {
	case 1:
		cout << "�Ա�ɸѡ(������ţ��ɶ�ѡ��ѡ�����س�ȷ��)��\n 1.��\n 2.Ů\n";
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
		if (current_month >= 7) {//�����ǰ�·ݴ��ڵ���7�£����ҵ���Ϊ��ǰ���
			current_year = now->tm_year + 1900;
		}
		else {
			current_year = now->tm_year + 1900 - 1;
		}
		cout << "��ҵ���ɸѡ(�����ҵ��ݣ�ʾ�����룺2011 2012)��\n";
		int year;
		while (cin >> year) {
			if (year >= 2010 && year <= current_year) {
				year_of_graduation.years_of_graduation.push_back(year);
			}
			else {
				cout << "������������������ҵ��ݣ�ʾ�����룺2011 2012��\n" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		break;
	case 3:
		cout << "ϵ/רҵ/�༶ɸѡ(������ţ��ɶ�ѡ��ѡ�����س�ȷ��ѡ��)��\n 1.ϵ\n 2.רҵ\n 3.�༶\n";
		break;
	}

	//������ϵ��רҵ���Ͱ༶
}
void alumniFilter::show() {
	cout << "ɸѡ������\n";
	cout<<"�Ա�";
	sort(gender.genders.begin(), gender.genders.end());
	for(auto it = gender.genders.begin(); it != gender.genders.end();++it) {
		if (*it == 'M') {
			cout << "�� ";
		}
		else if (*it == 'W') {
			cout << "Ů ";
		}
	}
	cout << endl;
	cout << "��ҵ��ݣ�\n";
	sort(year_of_graduation.years_of_graduation.begin(), year_of_graduation.years_of_graduation.end());
	for (auto it = year_of_graduation.years_of_graduation.begin(); it != year_of_graduation.years_of_graduation.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	//������ϵ��רҵ���Ͱ༶

}