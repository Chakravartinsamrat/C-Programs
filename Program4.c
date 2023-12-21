//Doubly Linked lIST AND oPERATIOns

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to Hold Student DATA
struct Student
{
    char SRN[20];
    char Name[50];
    char Branch[50];
    int sem;
    struct Student* prev;
    struct Student* next;
};
//Structure for header Node
struct Header
{
    int numStudents;
    struct Student* first;
};

//to create a new student node
struct Student* createStudentNode()
{
    struct Student* newStudent =malloc(sizeof(struct Student));
    newStudent->prev = NULL;
    newStudent->next = NULL;
    return newStudent; 
}
//function to get student data
struct Student* getStudentData()
{
    struct Student* newStudent = createStudentNode();
    printf("Enter SRN :");
    scanf("%s", newStudent->SRN); 
    printf("Enter the name :");
    scanf(" %[^\n]s", newStudent->Name);
    printf("Enter the branch: ");
    scanf(" %[^\n]s", newStudent->Branch);
    printf("Enter the semester: ");
    scanf("%d",&newStudent->sem);
    return newStudent;
}

//fUCNTION TO INSERT A STUDENT AT THE FRONT OF DOUBLY ILINKED LIST
void insertAtFront(struct Header* header){
    struct Student* newStudent = getStudentData();
    if(header->first==NULL){
        header->first= newStudent;
    }
    else{
        newStudent->next=header->first;
        header->first->prev=newStudent;
        header->first=newStudent;
    }
    header->numStudents++;
    printf("Student inserted at the front.\n");
}

//fucntion to d-play The DDL
void display(struct Header* header)
{
    if(header->first==NULL)
    {
        printf("The DDL IS EMPTY\n");
        return;
    }
    printf("Numaber of Students: %d\n", header->numStudents);
    printf("SRN\tBranch\tSemester\tName\n");
    struct Student* current =header->first;
    while(current!=NULL)
    {
        printf("%s\t%s\t%d\t\t%s\n", current->SRN,current->Branch,current->sem,current->Name);
        current=current->next;
    }
}

//Fuction to insert the student at the end of the ddl
void insertAtEnd(struct Header* header)
{
    struct Student* newStudent = getStudentData();
    if(header->first==NULL){
        header->first= newStudent;
    }
    else{
        struct Student* current =header->first;
        while(current->next!=NULL){
            current =current->next;
        }
        current->next=newStudent;
        newStudent->prev=current;
    }
    header->numStudents++;
    printf("Student inserted at the end.\n");
}

//function to insert a student at a given position in ddl
void insertAtPosition(struct Header* header, int position)
{
    if(position<1||position>header->numStudents+1)
    {
        printf("Invalid Position.\n");
        return;
    }
    if(position==1){
        insertAtFront(header);
        return;
    }
    if(position == header->numStudents+1){
        insertAtEnd(header);
        return;
    }
    struct Student* newStudent = getStudentData();
    struct Student* current = header->first;
    for(int i=1; i<position-1;i++){
        current =current->next;
    }
    newStudent->prev=current;
    newStudent->next=current->next;
    current->next->prev= newStudent;
    header->numStudents++;
    printf("Student Inserted at positon %d\n", position);
}
//fucntion to delete a student from the front of DLL
void deleteFromFront(struct Header* header){
    if(header->first==NULL){
        printf("DLL is empty.\n");
        return;
    }
    if(header->first->next==NULL){
        free(header->first);
        header->first=NULL;
    }
    else{
        struct Student* current =header->first;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->prev->next=NULL;
        free(current);
    }
    header->numStudents--;
    printf("Student deleted from the end.\n");
}
// Function to delete a student based on SRN
void deleteBySRN(struct Header* header, const char* srn) {
    if (header->first == NULL) {
    printf("DLL is empty.\n");
    return;
    }
    struct Student* current = header->first;
    while (current != NULL) {
        if (strcmp(current->SRN, srn) == 0){
            if (current->prev == NULL) {
            header->first = current->next; 
        }else{
        current->prev->next=current->next;
        }
        if(current->next!=NULL){
            current->next->prev=current->prev;
        }
        free(current);
        header->numStudents--;
        printf("Student with Srn %s deleted \n",srn);
        return;
        }   
        current=current->next;
    }
    printf("Student with SRN %s not found .\n", srn);
}

//main fun
int main() {
    struct Header header;
    header.numStudents = 0;
    header.first = NULL;
    int choice;
    char srnToDelete[20];
    do{
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Display DLL\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Front\n");
        printf("6. Delete from End\n");
        printf("7. Delete by SRN\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            insertAtFront(&header);
            break;
            case 2:
            display(&header);
            break;
            case 3:
            insertAtEnd(&header);
            break;
            case 4:
            {
            int position;
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&header, position);
            }
            break;
            case 5:
            deleteFromFront(&header);
            break;
            case 6:
            deleteFromEnd(&header);
            break;
            case 7:
            printf("Enter SRN to delete: ");
            scanf("%s", srnToDelete);
            deleteBySRN(&header, srnToDelete);
            break;
            case 8:
            printf("Exiting...\n");
            break;
            default:
            printf("Invalid choice. Please try again.\n");
        }
    }while (choice != 8);
// Free allocated memory before exiting
    struct Student* current = header.first;
    while (current != NULL) {
    struct Student* temp = current;
    current = current->next;
    free(temp);
    }
    return 0;
}