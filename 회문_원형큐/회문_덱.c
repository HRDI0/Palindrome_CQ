#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_SIZE];
	int  front, rear;
} DequeType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 
void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType * q)
{
	return ((q->rear + 1) % MAX_SIZE == q->front);
}

// 원형큐 출력 함수
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

// 삽입 함수
void add_front(DequeType * q, element val)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
}


// 삭제 함수
element delete_front(DequeType * q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

//확인함수
element get_front(DequeType * q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_SIZE];
}


// 삽입 함수
void add_rear(DequeType * q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element delete_rear(DequeType * q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
	return q->data[prev];
}

//확인함수
element get_rear(DequeType * q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
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
	printf("영어 단어를 입력하세요.\n");
	scanf_s("%s",&a, MAX_SIZE);
	if (check(a) == 1) {
		printf("회문입니다.");
	}
	else printf("회문이아닙니다.");
}