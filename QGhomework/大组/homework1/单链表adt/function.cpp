#include "linkedList.h"

void menu() {
	printf("-------��������ADT-------\n");       //�˵�����
	printf("1.create\n");
	printf("2.print\n");
	printf("3.insert\n");
	printf("4.delete\n");
	printf("5.revise\n");
	printf("6.search\n");
	printf("7.exit\n");
	printf("���������ѡ����Ϊ1-7֮������֣�\n");
}


int choice() {
	//��Ҫ����ж�
	int choi;
	scanf_s("%d", &choi);
	getchar();
	system("cls");
	switch (choi) {
	case 1:
		printf("1.����һ����������\n");
		head = create();
		break;
	case 2:
		printf("2.��ӡ����\n");
		print(head);
		break;
	case 3:
		printf("3.������ָ��λ���������\n");
		break;
	case 4:
		printf("4.ɾ������ָ��λ�õ�����\n");
		break;
	case 5:
		printf("5.�޸�����ָ��λ�õ�����\n");
		break;
	case 6:
		printf("6.��ѯ����ָ��λ�õ�����\n");
		break;
	case 7:
		printf("7.�˳�\n");
		break;
	default:
		printf("����������ֲ���ȷ������������\n");
		break;
	}
	return 0;
}

Slist* create() {
	Slist* p1;
	Slist* p2;
	head = (Slist*)malloc(LEN);
	p1 = head;
	p2 = NULL;
	scanf_s("%d", &head->num);
	while (p1->num != 0)
	{
		p2 = (Slist*)malloc(LEN);
		scanf_s("%d", &p2->num);
		p1->next = p2;
		p1 = p2;
	}
	p2->next = NULL;
	return head;
}

void print(Slist* head) {
	Slist* p;
	p = head;
	if (head != NULL) {
		do {
			printf("%d ", p->num);
			p = p->next;
		} while (p != NULL);
	}
}
