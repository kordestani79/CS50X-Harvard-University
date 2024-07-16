#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#define Employee struct emp
void add(FILE *fp);             // adding to list
FILE *del(FILE *fp);            // deleteing from list
void modify(FILE *fp);          // modifying a record
void displaylist(FILE *fp);     // displaying whole list
void searchrecord(FILE *fp);    // finding a particular record
void printChar(char ch, int n); // printing of a character n times
void printHead();
void displaybasic(FILE *fp);
void contact(FILE *fp);
void male_emp(FILE *fp);
void female_emp(FILE *fp);
void frmodis(FILE *fp);
void mainbranch(FILE *fp);
void otherbranch(FILE *fp);

struct emp
{
    int id;
    char name[100];
    char desgn[100];
    float sal;
    char jdate[8];
    char gender[100];
    char branch[100];
    char psaddr[200];
    char prtaddr[200];
    char phone[15];
    char mail[100];
};

int main()
{
    FILE *fp;
    Employee e;
    int option;
    char another;

    if ((fp = fopen("employeeInfo.txt", "rb+")) == NULL)
    {
        if ((fp = fopen("employeeInfo.txt", "wb+")) == NULL)
        {
            printf("can't open file");
            return 0;
        }
    }

    char username[100], password[100];
    printHead();
    printf("\n\t\t\t\t   Login Screen");
    printf("\n\t\t\t      Enter Your Credentials");
    printf("\n\n\n\t\tUsername: ");
    scanf("%s", username);
    printf("\n\t\tPassword: ");

    int i;
    i = 0;
    do
    {
        password[i] = getch();
        if (password[i] == 13)
        {
            break;
        }
        else if (password[i] == 8 && i > 0)
        {
            printf("%c%c%c", 8, 32, 8);
            i--;
        }
        else
        {
            printf("*");
            i++;
        }
    } while (password[i] != 13);
    password[i] = '\0';

    if (((strcasecmp(username, "admin")) == 0) && ((strcasecmp(password, "pass") == 0)))
    {
        while (1)
        {
            printHead();
            printf("\n\t\t\t\tMain Menu");
            printf("\n\n\n");

            printf("\n\n\t\t\t1. Add Employee");
            printf("\n\n\t\t\t2. Delete Employee");
            printf("\n\n\t\t\t3. Modify Employee Details");
            printf("\n\n\t\t\t4. Display Employee List");
            printf("\n\n\t\t\t5. Search Record");
            printf("\n\n\t\t\t6. Display Basic Information");
            printf("\n\n\t\t\t7. Display Basic Contact Information");
            printf("\n\n\t\t\t8. List of Male Employee");
            printf("\n\n\t\t\t9. List of Female Employee");
            printf("\n\n\t\t\t10.Employee list");
            printf("\n\n\t\t\t11.Employee list of Main Branch");
            printf("\n\n\t\t\t12.Employee list of Other Branch");
            printf("\n\n\t\t\t0. EXIT");

            printf("\n\n\t\tEnter your choice in number format:--> ");
            scanf("%d", &option);

            switch (option)
            {
            case 0:
                return 1;
                break;
            case 1:
                add(fp);
                break;
            case 2:
                fp = del(fp);
                break;
            case 3:
                modify(fp);
                break;
            case 4:
                displaylist(fp);
                break;
            case 5:
                searchrecord(fp);
                break;
            case 6:
                displaybasic(fp);
                break;
            case 7:
                contact(fp);
                break;
            case 8:
                male_emp(fp);
                break;
            case 9:
                female_emp(fp);
                break;
            case 10:
                frmodis(fp);
                break;
            case 11:
                mainbranch(fp);
                break;
            case 12:
                otherbranch(fp);
                break;
            default:
                printf("\n\t\tOops something wrong entered from your side..........");
                printf("\n\t\tProgram Ended :(.........");
                getch();
                exit(0);
            }
        }
    }
    else
    {
        printf("\n\t\tLogin Failed :(");
    }

    return 1;
}

//----printing character ch at n times ------

void printChar(char ch, int n)
{
    while (n--)
    {
        putchar(ch);
    }
}

//-----Printing Head Line of the program -----

void printHead()
{
    system("cls");
    printf("\t");
    printChar('=', 65);
    printf("\n\t");
    printChar('=', 16);
    printf("[EMPLOYEE] [MANAGEMENT] [SYSTEM]");
    printChar('=', 16);
    printf("\n\t");
    printChar('=', 65);
}

// ==========ADDING NEW RECORD==========================

void add(FILE *fp)
{
    printHead();

    printf("\n\t\t\tAdd Employee");
    char another = 'y';
    Employee e;

    fseek(fp, 0, SEEK_END);
    while (another == 'y' || another == 'Y')
    {
        printf("\n\n\t\tID number: ");
        scanf("%d", &e.id);

        printf("\n\n\t\tName of Employee: ");
        fflush(stdin);

        fgets(e.name, 100, stdin); // fgets takes an extra \n character as input
        e.name[strlen(e.name) - 1] = '\0';

        printf("\n\n\t\tDesignation: ");
        fflush(stdin);
        fgets(e.desgn, 100, stdin); // fgets takes an extra \n character as input
        e.desgn[strlen(e.desgn) - 1] = '\0';

        printf("\n\n\t\tGender: ");
        fflush(stdin);
        fgets(e.gender, 100, stdin); // fgets takes an extra \n character as input
        e.gender[strlen(e.gender) - 1] = '\0';

        printf("\n\n\t\tBranch: ");
        fflush(stdin);
        fgets(e.branch, 100, stdin);
        e.branch[strlen(e.branch) - 1] = '\0';

        printf("\n\n\t\tSalary: ");
        scanf("%f", &e.sal);

        printf("\n\n\t\tPresent Address: ");
        fflush(stdin);
        fgets(e.psaddr, 200, stdin);
        e.psaddr[strlen(e.psaddr) - 1] = '\0';

        printf("\n\n\t\tPermanant Address: ");
        fflush(stdin);
        fgets(e.prtaddr, 200, stdin);
        e.prtaddr[strlen(e.prtaddr) - 1] = '\0';

        printf("\n\n\t\tPhone: ");
        fflush(stdin);
        fgets(e.phone, 100, stdin);
        e.phone[strlen(e.phone) - 1] = '\0';

        printf("\n\n\t\tE-mail: ");
        fflush(stdin);
        fgets(e.mail, 100, stdin);
        e.mail[strlen(e.mail) - 1] = '\0';

        fwrite(&e, sizeof(e), 1, fp);

        printf("\n\n\t\tWant to enter another employee information (Y/N)\t");
        fflush(stdin);
        another = getchar();
    }
}

//===================DELETING A RECORD FROM LIST ============
FILE *del(FILE *fp)
{
    printHead();
    printf("\n\t\t\tDelete Employee");
    Employee e;
    int flag = 0, tempid, siz = sizeof(e);
    FILE *ft;

    if ((ft = fopen("temp.txt", "wb+")) == NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tEnter ID of employee to delete the record");
    printf("\n\n\t\t\tID No : ");
    scanf("%d", &tempid);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if (e.id == tempid)
        {
            flag = 1;
            printf("\n\tRecord deleted for");
            printf("\n\n\t\tNAME : %s\n\n\t\tBRANCH : %s\n\n\t\tID : %d\n\t", e.name, e.branch, e.id);
            continue;
        }

        fwrite(&e, siz, 1, ft);
    }

    fclose(fp);
    fclose(ft);

    remove("employeeInfo.txt");
    rename("temp.txt", "employeeInfo.txt");

    if ((fp = fopen("employeeInfo.txt", "rb+")) == NULL)
    {
        printf("ERROR");
        return NULL;
    }

    if (flag == 0)
        printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");

    printChar('-', 65);
    printf("\n\t");
    system("pause");
    return fp;
}

//===========MODIFY A RECORD ===========================

void modify(FILE *fp)
{
    printHead();
    printf("\n\t\t\tModify Employee Details");
    Employee e;
    int i, flag = 0, tempid, siz = sizeof(e);
    float sal;

    printf("\n\n\tEnter ID of Employee to modify the record : ");
    scanf("%d", &tempid);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if (e.id == tempid)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        fseek(fp, -siz, SEEK_CUR);
        printf("\n\n\t\tRecord Found");
        printf("\n\n\t\tEnter new data for the record");

        printf("\n\n\t\tEnter ID : ");
        scanf("%d", &e.id);

        printf("\n\n\t\tEnter Full Name of employee: ");
        fflush(stdin);
        fgets(e.name, 100, stdin); // fgets takes an extra \n character as input
        e.name[strlen(e.name) - 1] = '\0';

        printf("\n\n\t\tEnter Designation: ");
        fflush(stdin);
        fgets(e.desgn, 100, stdin); // fgets takes an extra \n character as input
        e.desgn[strlen(e.desgn) - 1] = '\0';

        printf("\n\n\t\tEnter Gender: ");
        fflush(stdin);
        fgets(e.gender, 100, stdin); // fgets takes an extra \n character as input
        e.gender[strlen(e.gender) - 1] = '\0';

        printf("\n\n\t\tEnter Branch: ");
        fflush(stdin);
        fgets(e.branch, 100, stdin);
        e.branch[strlen(e.branch) - 1] = '\0';

        printf("\n\n\t\tEnter Salary: ");
        scanf("%f", &e.sal);

        printf("\n\n\t\tEnter Present Address: ");
        fflush(stdin);
        fgets(e.psaddr, 200, stdin);
        e.psaddr[strlen(e.psaddr) - 1] = '\0';

        printf("\n\n\t\tEnter Permanant Address: ");
        fflush(stdin);
        fgets(e.prtaddr, 200, stdin);
        e.prtaddr[strlen(e.prtaddr) - 1] = '\0';

        printf("\n\n\t\tPhone number: ");
        fflush(stdin);
        fgets(e.phone, 100, stdin);
        e.phone[strlen(e.phone) - 1] = '\0';

        printf("\n\n\t\tE-mail: ");
        fflush(stdin);
        fgets(e.mail, 100, stdin);
        e.mail[strlen(e.mail) - 1] = '\0';

        fwrite(&e, sizeof(e), 1, fp);
    }

    else
        printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

    printf("\n\n\t");
    system("pause");
}

//====================DISPLAY THE LIST =================
void displaylist(FILE *fp)
{
    printHead();
    printf("\n\t\t\tList of employees");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        printf("\n\n\t\tID : %d", e.id);
        printf("\n\n\t\tNAME : %s", e.name);
        printf("\n\n\t\tDESIGNATION : %s", e.desgn);
        printf("\n\n\t\tGENDER : %s", e.gender);
        printf("\n\n\t\tBRANCH : %s", e.branch);
        printf("\n\n\t\tSALARY : %.2f", e.sal);
        printf("\n\n\t\tPRESENT ADDRESS : %s", e.psaddr);
        printf("\n\n\t\tPERMANANT ADDRESS : %s", e.prtaddr);
        printf("\n\n\t\tPHONE : %s", e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t", e.mail);
        printf("\n\t");
        printChar('=', 65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//================SEARCH EMPLOYEE================
void searchrecord(FILE *fp)
{
    printHead();
    printf("\n\t\t\tSearch Employee");
    int tempid, flag, siz, i;
    Employee e;
    char another = 'y';

    siz = sizeof(e);

    while (another == 'y' || another == 'Y')
    {
        printf("\n\n\tEnter ID of employee to search the record : ");
        scanf("%d", &tempid);

        rewind(fp);

        while ((fread(&e, siz, 1, fp)) == 1)
        {
            if (e.id == tempid)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            printf("\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tBRANCH : %s", e.branch);
            printf("\n\n\t\tSALARY: %.2f", e.sal);
            printf("\n\n\t\tPRESENT ADDRESS : %s", e.psaddr);
            printf("\n\n\t\tPERMANANT ADDRESS : %s", e.prtaddr);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printf("\n\n\t\tE-MAIL : %s", e.mail);
            printf("\n");
            printf("\t");
            printChar('=', 65);
        }
        else
            printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");

        printf("\n\n\t\tWant to enter another search (Y/N)");
        fflush(stdin);
        another = getchar();
    }
}

//========================LIST OF MALE EMPLOYEE====================
void male_emp(FILE *fp)
{
    printHead();
    printf("\n\t\t\tList of Male Employee");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if ((strcmp(e.gender, "Male") == 0) || (strcmp(e.gender, "male") == 0))
        {

            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printf("\n\t");
            printChar('-', 65);
        }
    }
    printf("\n\n\n\t");
    printChar('*', 65);
    printf("\n\n\t");
    system("pause");
}

//========================LIST OF FEMALE EMPLOYEE=================================

void female_emp(FILE *fp)
{
    printHead();
    printf("\n\t\t\tList of Female Employee");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if ((strcmp(e.gender, "Female") == 0) || (strcmp(e.gender, "female") == 0))
        {
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printf("\n\t");
            printChar('-', 65);
        }
    }
    printf("\n\n\n\t");
    printChar('*', 65);
    printf("\n\n\t");
    system("pause");
}

//========================LIST OF EMPLOYEE (except from Delhi)===================================

void frmodis(FILE *fp)
{
    printHead();
    printf("\n\t\t\tList of Employee (except from Delhi)");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if ((strstr(e.prtaddr, "Delhi") == 0) && (strstr(e.prtaddr, "delhi") == 0) && (strstr(e.prtaddr, "DELHI") == 0))
        {
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printf("\n\n\t\tE-MAIL : %s", e.mail);
            printf("\n\t");
            printChar('=', 65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//==============DISPLAY BASIC INFORMATION LIST==================================

void displaybasic(FILE *fp)
{
    printHead();
    printf("\n\t\t\tDisplay Basic Information");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        printf("\n\n\t\tID : %d", e.id);
        printf("\n\n\t\tNAME : %s", e.name);
        printf("\n\n\t\tDESIGNATION : %s", e.desgn);
        printf("\n\n\t\tGENDER : %s", e.gender);
        printf("\n\n\t\tBRANCH : %s", e.branch);
        printf("\n\n\t\tPHONE : %s", e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t", e.mail);
        printf("\n\t");
        printChar('=', 65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//==========================BASIC CONTACT INFO LIST=================================

void contact(FILE *fp)
{
    printHead();
    printf("\n\t\t\tBasic Contact Information");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        printf("\n\n\t\tID : %d", e.id);
        printf("\n\n\t\tNAME : %s", e.name);
        printf("\n\n\t\tDESIGNATION : %s", e.desgn);
        printf("\n\n\t\tPHONE : %s", e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t", e.mail);
        printf("\n\t");
        printChar('=', 65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//==========================LIST OF EMPLOYEE FROM MAIN BRANCH=============================

void mainbranch(FILE *fp)
{
    printHead();
    printf("\n\t\t\tList of Employee of Main Branch");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if ((strcmp(e.branch, "Main") == 0) || (strcmp(e.prtaddr, "main") == 0) || (strcmp(e.prtaddr, "MAIN") == 0))
        {
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printf("\n\n\t\tE-MAIL : %s\n\t", e.mail);
            printf("\n\t");
            printChar('=', 65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

//========================LIST OF EMPLOYEE From OTHRES BRANCH============================

void otherbranch(FILE *fp)
{
    printHead();
    printf("\n\t\t\tList of Employee of Other Branch");
    Employee e;
    int i, siz = sizeof(e);

    rewind(fp);

    while ((fread(&e, siz, 1, fp)) == 1)
    {
        if ((strcmp(e.branch, "Main") != 0) && (strcmp(e.prtaddr, "main") != 0) && (strcmp(e.prtaddr, "MAIN") != 0))
        {
            printf("\n\n\t\tID : %d", e.id);
            printf("\n\n\t\tNAME : %s", e.name);
            printf("\n\n\t\tDESIGNATION : %s", e.desgn);
            printf("\n\n\t\tPHONE : %s", e.phone);
            printf("\n\n\t\tE-MAIL : %s\n\n\t", e.mail);
            printf("\n\t");
            printChar('=', 65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}