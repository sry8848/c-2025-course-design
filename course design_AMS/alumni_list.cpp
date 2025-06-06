#include <iostream>
#include <iomanip>
#include <utility>
#include <set>
#include <string>
#include <cstdlib>
#include "alumni_list.h"//��Ҫ��Ҫ�ǳ���Ҫ�������Ȱ�����ͷ�ļ�����������
#include "Utils.h"
#include "alumniFilter.h"
using namespace std;
template class List<alumni>;
void alumni_list::sort(bool (*Compare)(const alumni& val1, const alumni& val2)) {
	//List newList;
	auto p1 = head;
	auto p2 = head;//p1,p2��ΪĿ����ǰһ�����
	//head = new Node;//�ڴ����ʧ�ܻ�ϵͳ�Լ����������ù��ദ��
	/*if (head != NULL) {
		head->data = val;
		head->next = temp;
	}*/
	while ((p2->next) != NULL) {//
		if (Compare(head->data, (p2->next)->data)) {//ͷ������⴦��
			auto aim = (p2->next);
			p2->next = aim->next;
			aim->next = head;
			head = aim;
		}
		p1 = head;
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

void alumni_list::show() const {
	int i = 1;
	auto p1 = head;
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

void alumni_list::filter_show(const alumniFilter& myAlumniFilter) const {
	int i = 1;
	auto p1 = head;
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

void alumni_list::show_allowChange() {
	int i = 1;
	auto p1 = head;
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
					erase(num);
					if (choice == 0) {
						break;
					}
					else {
						cout << "ɾ���ɹ���\n";
					}
				}
				return;
			}
			else if(choice == 4) {
				break;
			}
		}
	}
}

void alumni_list::filter_show_allowChange(const alumniFilter& alumniFilter) {
	int i = 1;
	auto p1 = head;
	while (p1 != NULL) {
		if (alumniFilter.filter(p1->data)) {//ɸѡ�������
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
					erase(num);
					if (choice == 0) {
						break;
					}
					else {
						cout << "ɾ���ɹ���\n";
					}
				}
				return;
			}
			else if(choice == 4) {
				break;
			}
		}
	}
}
alumni_list alumni_list::search_form_line(const std::string& keyword) const {
	alumni_list result;
	auto p1 = head;
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
		result.insert(item.second->data);//��ƥ�䵽�Ľ�������
	}
	return result;
}