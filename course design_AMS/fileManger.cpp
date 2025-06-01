#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include <fstream>
#include <iostream>
#include "list.h"
#include "alumni_list.h"	
#include "fileManager.h"
using namespace std;
void fileManager::save_alumni_list(const std::string& fileName, const alumni_list& alumniList){// ����У���б��ļ� 
	if (alumniList.empty()) {
		return; // ����б�Ϊ�գ�ֱ�ӷ���
	}
	ofstream outfile(fileName);//��Ӧʹ��"fileName"
	if(!outfile) { // ����ļ��Ƿ�ɹ���
		cerr << "�޷����ļ�: " << fileName << endl;
		return;
	}
	outfile << "�˺�,����,����,����ƴ��,�Ա�,����,��ҵ���,ϵ,רҵ,�༶,��ַ,�绰����,QQ,��������\n"; // д���ͷ��CSV��ʽ,ͨ����ǿ��������Excel��(�ָ����Ƽ�����\t����
	auto it= alumniList.begin();//
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
alumni_list fileManager::load_alumni_list(const std::string& fileName) {
	ifstream infile(fileName);
	if (!infile) { // ����ļ��Ƿ�ɹ���
		cerr << "�޷����ļ�: " << fileName << endl;
		return alumni_list(); // ����һ���յ� alumni_list
	}
	alumni_list alumniList;
	string line;
	std::string userName_;
	std::string password_;
	std::string name;
	std::string pinyin;
	char gender;
	int age;
	int year_of_graduation;
	std::string department;
	std::string major;
	int Class;
	std::string address;
	std::string phoneNumber;
	std::string qq;
	std::string email;
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
		alumni newAlumni(userName_,password_,name,pinyin,gender,age,year_of_graduation,department,major,Class,address,phoneNumber,qq,email); // ����һ���µ� alumni ����
		alumniList.insert(newAlumni); // ���¶�����뵽 alumniList ��
	}
	infile.close(); // �ر��ļ�
	return alumniList; // ���ؼ��ص� alumni_list
}
template <typename T>
static void fileManager::save_T_list(const std::string& fileName, List<T>& TList) {
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
template <typename T>
List<T> fileManager::load_T_list(const std::string& fileName){
	ifstream infile(fileName);
	if (!infile) { // ����ļ��Ƿ�ɹ���
		cerr << "�޷����ļ�: " << fileName << endl;
		return List<T>(); // ����һ���յ� List<T>
	}
	string line;
	std::string userName_;
	std::string password_;
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
