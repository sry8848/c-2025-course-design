#pragma once//ͷ�ļ���������ֹ�ظ�����
//������ͷ�ļ�����#include<iostream>������ʹ��std::
#include <string>//�õ�std::string�Ͱ�����ͷ�ļ�
#include <vector>
#include "list.h"
#include "alumni_list.h"
#include "department.h"
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
	static List<T> load_T_list(const std::string& fileName); // ����ͨ���б��ļ�
	static std::vector<Department> load_department_list(const std::string& fileName); // ��ָ���ļ�����ϵ�б�
}
;