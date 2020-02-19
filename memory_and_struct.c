#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct
struct student{
	int id;
	char name[20];
	float percentage;
}; // remember the ;

//protype of the function
void pass_by_value(int i);
void pass_by_pointer(int* i);
void print_student(struct student st);
void increase_percentage_pass_by_value(struct student st);
void increase_percentage_pass_by_pointer(struct student *st);
void swap_student(struct student *a, struct student *b);

int main(int argc, char const *argv[]){
	//recap
	int i = 0;
	pass_by_value(i);
	printf("%d\n", i);
	//& means the address of the variable
	pass_by_pointer(&i);
	printf("%d\n", i);

	//struct demo
	struct student kobe;
	kobe.id = 1; // use dot (.) to access the attribute
	strcpy(kobe.name, "Kobe Bryant"); //copy string
	kobe.percentage = 99.9;
	print_student(kobe);

	printf("increase the percentage of Kobe, pass by value\n");
	increase_percentage_pass_by_value(kobe);
	print_student(kobe);
	printf("increase the percentage of Kobe, pass by pointer(address)\n");
	increase_percentage_pass_by_pointer(&kobe);
	print_student(kobe);

	//Another way to declare a struct
	struct student james = {2, "james", 99.5};
	//a pointer to a struct
	struct student *paul = (struct student*) malloc(sizeof(struct student));
	paul->id = 3;
	strcpy(paul->name, "chris");
	paul->percentage = 99.5;
	//ways to copy a struct
	struct student james2;
	james2 = james;
	//copy memory
	struct student *ptr_paul = (struct student*) malloc(sizeof(struct student));
	memcpy(ptr_paul, paul, sizeof(struct student));
	printf("\nprint ptr_paul...\n");
	print_student(*ptr_paul); // * here is dereferencing the pointer

	printf("swap student using pointers\n");
	struct student *ptr_james = &james;
	print_student(*ptr_james);
	swap_student(ptr_james, ptr_paul);
	printf("now print *ptr_james\n");
	print_student(*ptr_james);

	//free the memory, important!
	free(ptr_paul);

	return 0;
}

//actual function (the prototype is defined at the beginning of the file)
void pass_by_value(int i){
	i++;
}

void pass_by_pointer(int* i){
	(*i)++;
}

//pass by value
void print_student(struct student st){
	printf("ID: %d\n", st.id);
	printf("Name: %s\n", st.name);
	printf("percentage: %f\n", st.percentage);
}

void increase_percentage_pass_by_value(struct student st){
	st.percentage += 0.1;
}

void increase_percentage_pass_by_pointer(struct student *st){
	st->percentage += 0.1;
}

void swap_student(struct student *a, struct student *b){
	struct student temp = *a;
	*a = *b;
	*b = temp;
}
