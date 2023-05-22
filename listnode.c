#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listnode {
	element data;
	struct listnode* link;
}listnode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

listnode* insert_first(listnode* head, int value) {
	listnode* p = (listnode*)malloc(sizeof(listnode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

listnode* insert(listnode* head, listnode* pre, element value) {
	listnode* p = (listnode*)malloc(sizeof(listnode));
	p->data = value;
	p->link = pre->link;
	pre -> link = p;
	return head;
}

listnode* delete_first(listnode* head) {
	listnode* removed;
		if(head == NULL) return NULL;
		removed = head;
		head = removed->link;
		free(removed);
		return head;

}

listnode* delete(listnode* head, listnode* pre) {

	listnode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(listnode* head) {
	for (listnode* p = head; p != NULL; p = p->link)
		printf("%d -> ",p->data);
	printf("NULL\n");
}


int main(void) {
	listnode* head = NULL;
	int num, item, pos;

	while (1) {
		printf("*** MENU ****\n");
		printf("1. INSERT\n");
		printf("2. DELETE\n");
		printf("3. PRINT\n");
		printf("0. EXIT\n\n");
		printf("Enter the menu: ");
		scanf("%d", &num);

		switch (num) {
		case 1:
			printf("Enter the number and position: ");
			scanf("%d %d", &item, &pos);
			int count = 0;
			if (pos == 0) {
				head = insert_first(head, item);
				count++;
			}
			else {
			
				listnode* pre = head;
				for (int i = 0; i < pos - 1; i++) {
					pre = pre->link;
					if (pre == NULL) {
						printf("Invalid position\n");
						break;
					}
					count++;
				}
				if (pre != NULL) {
					head = insert(head, pre, item);
					count++;
				}
			}
			printf("Moves: %d\n", count);
			break;
		case 2:
			printf("Enter the position: ");
			scanf("%d", &pos);
			count = 0;
			if (pos == 0) {
				head = delete_first(head);
				count++;
			}
			else {
				
				listnode* pre = head;
				for (int i = 0; i < pos - 1; i++) {
					pre = pre->link;
					if (pre == NULL) {
						printf("Invalid position\n");
						break;
					}
					count++;
				}
				if (pre != NULL) {
					head = delete(head, pre);
					count++;
				}
			}
			printf("Moves: %d\n", count);
			break;
		case 3:
			print_list(head);
			break;
		case 0:
			printf("Exit the program\n");
			exit(0);
		}
	}
}












