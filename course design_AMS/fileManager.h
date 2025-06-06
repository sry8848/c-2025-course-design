#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include <vector>
#include "alumni_list.h"
#include "myList.h"
#include "department.h"
#include <fstream>
#include <iostream>
#include "Class.h"
#include "major.h"
#include "fileManager.h"


using namespace std;

template <typename T> class List;
class alumni_list;
class Department;//���ǰ������������ѭ����������
class fileManager {
public:
	static void save_alumni_list(const std::string& fileName,const alumni_list& alumniList); // ����У���б��ļ�                                                                                             
	static alumni_list load_alumni_list(const std::string& fileName); // ��ָ���ļ�����У���б�(AlumniList ���� FileManager������������)
	template <typename T>
	static void save_T_list(const std::string& fileName, List<T>& TList); // ��ָ���ļ�����ͨ���б�
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
	static std::vector<Department> load_department_list(const std::string& fileName); // ��ָ���ļ�����ϵ�б�
}
;