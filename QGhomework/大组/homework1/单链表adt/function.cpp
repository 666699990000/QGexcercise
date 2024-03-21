#include "linkedList.h"

void menu() {
	printf("-------单向链表ADT-------\n");       //菜单界面
	printf("1.create\n");
	printf("2.print\n");
	printf("3.insert\n");
	printf("4.delete\n");
	printf("5.revise\n");
	printf("6.search\n");
	printf("7.exit\n");
	printf("请输入你的选择（需为1-7之间的数字）\n");
}


int choice() {
	//还要添加判断
	int choi;
	scanf_s("%d", &choi);
	getchar();
	system("cls");
	switch (choi) {
	case 1:
		printf("1.构建一个单向链表\n");
		head = create();
		break;
	case 2:
		printf("2.打印链表\n");
		print(head);
		break;
	case 3:
		printf("3.在链表指定位置添加数据\n");
		break;
	case 4:
		printf("4.删除链表指定位置的数据\n");
		break;
	case 5:
		printf("5.修改链表指定位置的数据\n");
		break;
	case 6:
		printf("6.查询链表指定位置的数据\n");
		break;
	case 7:
		printf("7.退出\n");
		break;
	default:
		printf("你输入的数字不正确，请重新输入\n");
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
