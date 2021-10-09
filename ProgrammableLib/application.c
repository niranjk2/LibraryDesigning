#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"

/*Application specific data structures*/
typedef struct student_{
    char name[32];
    int age;
    int weight;
    unsigned int rollno;
}student_t;

static void
print_student_details(student_t *student){
    printf("Name = %s\n",   student->name);
    printf("Age = %d\n",    student->age);
    printf("weight = %d\n", student->weight);
    printf("rollno = %u\n", student->rollno); 
}

static void 
print_student_db(dll_t *student_db){
    if(!student_db || !student_db->head) return;
    dll_node_t *head = student_db->head;
    student_t* data = NULL;

    while(head){
        data = head->data;
        print_student_details(data);
        head = head->right;
    }
}

int 
main(int argc, char **argv){
    /*Student database*/
    student_t* student1 = calloc(1, sizeof(student_t));
    strncpy(student1->name, "Niranjan", strlen("Niranjan"));
    student1->age = 30;
    student1->weight = 70;
    student1->rollno = 20190518;

    student_t* student2 = calloc(1, sizeof(student_t));
    strncpy(student2->name, "Deepak", strlen("Deepak"));
    student2->age = 28;
    student2->weight = 75;
    student2->rollno = 3456;

    student_t* student3 = calloc(1, sizeof(student_t));
    strncpy(student3->name, "Rupa", strlen("Rupa"));
    student3->age = 31;
    student3->weight = 60;
    student3->rollno = 456789;

    /*Create a new Linked List*/
    dll_t *student_db = get_new_dll();
    add_data_to_dll(student_db, student1);
    add_data_to_dll(student_db, student2);
    add_data_to_dll(student_db, student3);

    print_student_db(student_db); 

}
