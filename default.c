#include"shopconstruction.h"
#include<string.h>
#include<stdbool.h>
extern struct goods;
typedef struct goods note;
extern struct goods* head, * tear;
extern double Nconsumer;
extern double Consume;



void linksort() {
	note * p, * p0, * r, * r0=NULL, * q;
	p0 = NULL;
	p = head;
	while (p != NULL) {
		r = head; 
		while (strcmp(r->name , p->name)>0 && (r != p)) {
			r0 = r;
			r = r->next;
		}
		if (r != p) {
			q = p;
			p0->next = p->next;
			p = p0;
			if (r == head) {
				q->next = head;
				head = q;
			}
			else {
				q->next = r;
				r0->next = q;
			}
		}
		p0 = p;
		p = p->next;
	}
}

void informationback() {
	FILE* fp;
	note* p = head;
	fp = fopen("resources.txt", "w");
	while (p != NULL) {
		Nconsumer += p->count * p->price;
		fprintf(fp, " %s %d %lf %d %d  %lf\n", p->name, p->category, p->price, p->Exp, p->level, p->count);
		p = p->next;
	}
	fclose(fp);
	fp = fopen("customer.txt", "r");
	double mn;
	fscanf(fp, "%lf", &mn);
	fp = fopen("customer.txt", "w");
	fprintf(fp, "%lf\n", Consume - Nconsumer + mn);
	fclose(fp);
}




bool passwordcheck() {
	FILE* fp;
	fp = fopen("password.txt", "r");
	char passwords[30];
	fscanf(fp, "%s", passwords);
	char passwords1[30];
	printf("«Î ‰»Î√‹¬Î£∫\n__________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", passwords1);
	if (strcmp(passwords, passwords1) == 0) {
		return true;
	}
	else {
		return false;
	}
}