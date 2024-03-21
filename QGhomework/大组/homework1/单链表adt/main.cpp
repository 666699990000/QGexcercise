#include"allin.h"

Slist* head;//头结点

int main() {
	head = NULL;//头结点
	int flag = 1;
	do
	{
		menu();
		choice();
		//flag = 0;
	} while (flag);

	return 0;
}

void menu() {
	printf("\n-------单向链表ADT-------\n");       //菜单界面
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
		printf("在哪个位置后插入数据\n");
		int pos;
		scanf_s("%d", &pos);
		printf("插入的数据为\n");
		int num;
		scanf_s("%d", &num);
		head = insert(head, pos, num);
		break;
	case 4:
		printf("4.删除链表指定位置的数据\n");
		printf("在哪个位置后删除数据\n");
		int pos1;
		scanf_s("%d", &pos1);
		head = deletelist(head, pos1);
		break;
	case 5:
		printf("5.修改链表指定位置的数据\n");
		printf("在哪个位置修改数据\n");
		int pos2;
		scanf_s("%d", &pos2);
		printf("修改为\n");
		int num1;
		scanf_s("%d", &num1);
		head = revise(head, pos2, num1);
		break;
	case 6:
		printf("6.查询链表是否有指定值的数据\n");
		printf("想要查找的值为");
		int num3;
		scanf_s("%d", &num3);
		search(head, num3);
		break;
	case 7:
		printf("7.退出\n");
		exit(0);
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
	printf("请输入数字（若输入0，终止创建）");
	scanf_s("%d", &p1->num);
	while (p1->num!= 0)
	{
			p2 = (Slist*)malloc(LEN);
			scanf_s("%d", &p2->num);
			if (p2->num != 0) {
				p1->next = p2;
				p1 = p2;
			}
			else {
				free(p2);
				break;
			}
	}
	p1->next = NULL;
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

Slist* insert(Slist* head, int pos,int num) {
	if (head == NULL){
		printf("此为空表，不可插入数据");
	}
	Slist* p = head;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	Slist* q = (Slist*)malloc(LEN);
	q->num = num;
	q->next = p->next;
	p->next = q;
	return head;
}

Slist* deletelist(Slist* head, int pos) {
	if (head == NULL || head->next == NULL) {
		printf("此为空表或只有一个数据，不可删除数据");
	}
	Slist* p = head;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	p = (p->next)->next;
	free(p->next);
	return head;
}

Slist* revise(Slist* head,int pos, int num) {
	if (head == NULL) {
		printf("此为空表，不可修改数据");
	}
	Slist* p = head;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	p->num = num;
	return head;
}

int search(Slist* head, int num) {
	Slist* p = head;
	int n = 1;
	while (p->num != num && p != NULL){
		p = p->next;
		n++;
	} 
	if (p->num == num) {
		printf("已找到，所找值在第%d个位置\n", n);
	}else {
		printf("不存在此值\n");
		printf("不存在此值\n");
	}
	return 0;
}