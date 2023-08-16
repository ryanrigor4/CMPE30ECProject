222#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define NAME_SIZE 50
#define CUSTOMER_SIZE 10

//--------------------------------------------------------------------------------------------------------------------------
//Student Name: Ryan Rigor
//Course: CMPE 30
//Term/Year: Spring 2023
//Date: 5/12/2023
//Project Number: Extra Credit Project
//--------------------------------------------------------------------------------------------------------------------------

struct person {
    char name[NAME_SIZE];
    int id;
    double balance;
};

/*
 ------------------------------------
 Description: This method allows the user to view a certain contact, searching by name
 Name: view
 Paramaters: array(array to parse through)
 Return: prints data of desired user if found
 ------------------------------------
 */

void view (struct person array[]) {
    
    int i;
    printf("Number:");
    scanf("%i",&i);
    
    if(i < 1) {
        printf("Number needs to be higher than 1, please reenter");
    } else {
        printf("%s, %i, $%f\n", array[i-1].name, array[i-1].id,array[i-1].balance);
    }
}

/*
 ------------------------------------
 Description: This method allows the user to view all contacts
 Name: list
 Paramaters: array(array of users to look through)
 Return: printed data of all users that are in the paramater of array
 ------------------------------------
 */

void list(struct person array[]) {
    for(int i = 0; i < CUSTOMER_SIZE; i++) {
        if(strlen(array[i].name) != 0) {
            printf("%i. %s, %i, $%f\n", i+1,array[i].name,array[i].id,array[i].balance);
        }
    }
}

/*
 ------------------------------------
 Description: This method allows the user to see all methods
 Name: display_menu
 Return: printed data of all avaliable methods
 ------------------------------------
 */

void display_menu() {
    printf("\nCOMMAND MENU");
    printf("\nlist - Display all contacts");
    printf("\nview - View a contact");
    printf("\nadd - Add a new contact");
    printf("\ndelete - Remove a contact");
    printf("\nexit - Exit program\n");
}

/*
 ------------------------------------
 Description: This method allows the user to append another Person
 Name: add
 Return: status of if user was successfully added
 ------------------------------------
 */

void add(struct person array[]) {
    
    struct person newContact;
    printf("Name: ");
    scanf(" %[^\n]s", newContact.name);
    printf("Id: ");
    scanf("%d", &newContact.id);
    printf("Balance: ");
    scanf("%lf", &newContact.balance);
    
    for(int i = 0; i < CUSTOMER_SIZE;i++) {
        if(strlen(array[i].name) == 0) {
            array[i] = newContact;
            printf("%s has been added\n", newContact.name);
            break;
        }
    }
    
}
/*
 ------------------------------------
 Description: This method allows the user delete a contact
 Name: delete
 Paramaters: array(array of users to look through)
 Return:
 ------------------------------------
 */

void delete(struct person array[]) {
    int input;
    printf("\nNumber:");
    scanf("%i", &input);
    
    struct person emptyPerson = {"",0,0};
    
    if(strlen(array[input].name) == 0) {
        printf("User does not exist, please reinput");
    } else {
        printf("User %s has been deleted.\n", array[input].name);
        array[input-1] = emptyPerson;
    }
    
}

/*
 ------------------------------------
 Description: This method allows the user delete a contact
 Name: display_title
 Return: title of this program
 ------------------------------------
 */

void display_title() {
    printf("Contact Management System\n");
}

int main()
{
    struct person storage[CUSTOMER_SIZE] = { // initalizes array of struct
        {"Betty Johnson",3333,400.98},
        {"Mark Arlington",4444,678.56},
    };
    
    int decider = 0; // allows for input to be ended
    
    display_title(); // initally prints title of project
    display_menu();// initally prints all methods avaliable to user
    
    do {
        char command[] = "";
        printf("\nCommand:");
        scanf("%s",&command);
        
        //determines if a command has been entered, and executes it if done correctly
        if(strcmp(command, "list") == 0) {
            list(storage);
        } else if (strcmp(command, "view") == 0) {
            view(storage);
        }else if (strcmp(command, "add") == 0) {
            add(storage);
        }else if (strcmp(command, "delete") == 0) {
            delete(storage);
        }else if (strcmp(command, "exit") == 0) {
            break;
        }else if (strcmp(command, "menu") == 0) {
            display_menu();
        }else if (strcmp(command, "title") == 0) {
            display_title();
        } else {
            printf("\n Command not detected. refer to COMMAND MENU");
        }
                
    } while(decider != 0);
    
    printf("thanks for using my app\n");
    
};
