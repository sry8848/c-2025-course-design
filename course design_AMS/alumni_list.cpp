#include <iostream>
#include <iomanip>
#include <utility>
#include <set>
#include <string>
#include <cstdlib>
#include "alumni_list.h"//重要重要非常重要，必须先包含此头文件！！！！！
#include "Utils.h"
#include "alumniFilter.h"
using namespace std;
template class List<alumni>;
void alumni_list::sort(bool (*Compare)(const alumni& val1, const alumni& val2)) {
	//List newList;
	auto p1 = head;
	auto p2 = head;//p1,p2都为目标结点前一个结点
	//head = new Node;//内存分配失败会系统自己崩溃，不用过多处理
	/*if (head != NULL) {
		head->data = val;
		head->next = temp;
	}*/
	while ((p2->next) != NULL) {//
		if (Compare(head->data, (p2->next)->data)) {//头结点特殊处理
			auto aim = (p2->next);
			p2->next = aim->next;
			aim->next = head;
			head = aim;
		}
		p1 = head;
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
			cout << "选项：\n 1.下一页\n 2.返回上一级\n";
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
			cout << "选项：\n 1.下一页\n 2.返回上一级\n";
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
					erase(num);
					if (choice == 0) {
						break;
					}
					else {
						cout << "删除成功！\n";
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
		if (alumniFilter.filter(p1->data)) {//筛选并标序号
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
					erase(num);
					if (choice == 0) {
						break;
					}
					else {
						cout << "删除成功！\n";
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
		result.insert(item.second->data);//将匹配到的结点加入结果
	}
	return result;
}