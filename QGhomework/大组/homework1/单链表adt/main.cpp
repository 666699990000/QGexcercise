#include"allin.h"

Slist* head;//ͷ���

int main() {
	head = NULL;//ͷ���
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
	printf("\n-------��������ADT-------\n");       //�˵�����
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
		printf("���ĸ�λ�ú��������\n");
		int pos;
		scanf_s("%d", &pos);
		printf("���������Ϊ\n");
		int num;
		scanf_s("%d", &num);
		head = insert(head, pos, num);
		break;
	case 4:
		printf("4.ɾ������ָ��λ�õ�����\n");
		printf("���ĸ�λ�ú�ɾ������\n");
		int pos1;
		scanf_s("%d", &pos1);
		head = deletelist(head, pos1);
		break;
	case 5:
		printf("5.�޸�����ָ��λ�õ�����\n");
		printf("���ĸ�λ���޸�����\n");
		int pos2;
		scanf_s("%d", &pos2);
		printf("�޸�Ϊ\n");
		int num1;
		scanf_s("%d", &num1);
		head = revise(head, pos2, num1);
		break;
	case 6:
		printf("6.��ѯ�����Ƿ���ָ��ֵ������\n");
		printf("��Ҫ���ҵ�ֵΪ");
		int num3;
		scanf_s("%d", &num3);
		search(head, num3);
		break;
	case 7:
		printf("7.�˳�\n");
		exit(0);
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
	printf("���������֣�������0����ֹ������");
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
		printf("��Ϊ�ձ����ɲ�������");
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
		printf("��Ϊ�ձ��ֻ��һ�����ݣ�����ɾ������");
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
		printf("��Ϊ�ձ������޸�����");
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
		printf("���ҵ�������ֵ�ڵ�%d��λ��\n", n);
	}else {
		printf("�����ڴ�ֵ\n");
		printf("�����ڴ�ֵ\n");
	}
	return 0;
}