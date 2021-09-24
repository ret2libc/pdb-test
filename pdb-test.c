#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
	char *name;
	char *surname;
	int age;
};

struct book {
	char *title;
	int year;
	struct person *author;
};

struct book *create_book(char *title, struct person *a) {
	struct book *res = (struct book *)malloc(sizeof(struct book));
	res->author = a;
	res->title = strdup(title);
	return res;
}

void print_person(struct person *p) {
	printf("\tName: %s\n", p->name);
	printf("\tSurname: %s\n", p->surname);
	printf("\tAge: %d\n", p->age);
}

void print_book(struct book *b) {
	printf("Title: %s\n", b->title);
	printf("Year: %d\n", b->year);
	printf("Author:\n");
	print_person(b->author);
}

int main(int argc, char **argv) {
	struct person *a1 = malloc(sizeof(struct person));
	a1->name = "ret2libc";
	a1->surname = "ret2surname";
	a1->age = 30;

	struct person *a2 = malloc(sizeof(struct person));
	a2->name = "tonia";
	a2->surname = "cartonia";
	a2->age = 29;

	struct book *b = create_book("MyTitle", a1);
	b->year = 2021;
	print_book(b);

	return 0;
}
