#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
typedef int element;
typedef struct { // ť Ÿ��
	element  data[MAX_SIZE];
	int  front, rear;
} DequeType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ 
void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(DequeType * q)
{
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

// ����ť ��� �Լ�
void deque_print(DequeType * q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// ���� �Լ�
void add_front(DequeType * q, element val)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
}


// ���� �Լ�
element delete_front(DequeType * q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

//Ȯ���Լ�
element get_front(DequeType * q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_SIZE];
}


// ���� �Լ�
void add_rear(DequeType * q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element delete_rear(DequeType * q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
	return q->data[prev];
}

//Ȯ���Լ�
element get_rear(DequeType * q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[q->rear];
}

int check(char str[]) {
	DequeType q;
	init_deque(&q);
	char ch_in, ch_out;
	int i = 0;
	int length = strlen(str);
	for (i = 0; i < length; i++) {
		ch_in = str[i];
		if (ch_in == ' ' || ch_in == ',') continue;
		ch_in = tolower(ch_in);
		add_rear(&q, ch_in);
	}
	for (i = 0; i < (length / 2); i++) {
		ch_in = delete_front(&q);
		ch_out = delete_rear(&q);
		if (ch_in != ch_out) return 0;
	}
	return 1;
}

int main(void)
{
	char a[MAX_SIZE];
	printf("���� �ܾ �Է��ϼ���.\n");
	scanf_s("%s",&a, MAX_SIZE);
	if (check(a) == 1) {
		printf("ȸ���Դϴ�.");
	}
	else printf("ȸ���̾ƴմϴ�.");
}