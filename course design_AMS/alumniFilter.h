#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include <vector>
#include "person.h"
#include "alumni.h"
class alumniFilter{
public:
	//���ڶ����г�ʼ����Ա����������Ҫ���캯�����ٴγ�ʼ�������򱨴��������嶨��
	//������������Ҫ��ʲô����Ϊ��Ա������ֵ���ͣ��Զ��ͷ�
	//�����Ա������ָ�����ͣ�����Ҫ�ֶ��ͷ��ڴ�
	void modify_alumniFilter();
	void show();
	bool filter(const alumni& falumni) const;//δʵ��
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
