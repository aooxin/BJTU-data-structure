//ĳ�����˾��Լ��30��Ա����ÿ��Ա�������������š�ְ������ԣ�
//ÿ�궼��Ա����ְ����ְ��������Ա������һ�����Ա�������ְ����ְ������
//����Ա����ְ����ְʱ���޸����Ա�������ʾ���µ�Ա��������
//Ҫ��: ����˳�����ʽ�洢���ֽṹ�洢��ʵ��˳��������������������û���������ɡ�
//assignment1ʵ��˳���
#include "list.h"
int main()
{
	SqList StaffList;
	InitList(StaffList);
	Staff s1;
	strcpy_s(s1.name, "zhangsan");
	s1.ID = 1888888;
	strcpy_s(s1.job, "attorney");
	Staff s2,s3;
	strcpy_s(s2.name, "list");
	s2.ID = 1888889;
	strcpy_s(s2.job, "lawyer");
	InsertList(StaffList, 1, s1);
	InsertList(StaffList, 1, s2);
	DisplayAll(StaffList);
	DeleteStaff(StaffList, 1, s3);
	printf("%d",ExtendList(StaffList));
	return 0;
}