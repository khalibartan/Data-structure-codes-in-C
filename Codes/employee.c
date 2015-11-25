/*Objective: Create a employee database using fiel handling
 * Author: Khalibartan
 * Reg.n: 20142027
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 200
struct emp

{

    int id;
    int age;
    char *firstname;
    char *middlename;
    char *lastname;

}*emp1, *emp3;

void display();
void create();
void update();

FILE *fp, *fp1;
int count = 0;

void main(int argc, char **argv)

{

    int i, n, ch;



    printf("1] Create a Record\n");

    printf("2] Display Records\n");

    printf("3] Update Records\n");

    printf("4] Exit");

    while (1)

    {

        printf("\nEnter your choice : ");

        scanf("%d", &ch);

        switch (ch)

        {

            case 1:

                fp = fopen(argv[1], "a");

                create();

                break;

            case 2:

                fp1 = fopen(argv[1],"r+");

                display();

                break;

            case 3:

                fp1 = fopen(argv[1], "r+");

                update();

                break;

            case 4: 

                exit(0);

        }

    }

}



/* To create an employee record */

void create()

{

    int i;

    char *p;



    emp1 = (struct emp *)malloc(sizeof(struct emp));

    emp1->firstname = (char *)malloc((size)*(sizeof(char)));
    emp1->middlename = (char *)malloc((size)*(sizeof(char)));
    emp1->lastname = (char *)malloc((size)*(sizeof(char)));

    printf("Enter first name of employee : ");

    scanf(" %[^\n]s", emp1->firstname);

    printf("Enter middle name of employee : ");

    scanf(" %[^\n]s", emp1->middlename);

    printf("Enter last name of employee : ");

    scanf(" %[^\n]s", emp1->lastname);

    printf("Enter emp id : ");

    scanf(" %d", &emp1->id);

    printf("Enter emp age : ");

    scanf(" %d", &emp1->age);

    fwrite(&emp1->id, sizeof(emp1->id), 1, fp);

    fwrite(&emp1->age, sizeof(emp1->age), 1, fp);

    fwrite(emp1->firstname, size, 1, fp);

    fwrite(emp1->middlename, size, 1, fp);

    fwrite(emp1->lastname, size, 1, fp);

    count++;   // count to number of entries of records

    fclose(fp);

}



/* Display the records in the file */

void display()

{    

    emp3=(struct emp *)malloc(1*sizeof(struct emp));    

    emp3->firstname = (char *)malloc((size)*(sizeof(char)));
    emp3->middlename = (char *)malloc((size)*(sizeof(char)));
    emp3->lastname = (char *)malloc((size)*(sizeof(char)));

    int i = 1;



    if (fp1 == NULL)    

        printf("\nFile not opened for reading");

    while (i <= count)

    {

        fread(&emp3->id, sizeof(emp3->id), 1, fp1);

        fread(&emp3->age, sizeof(emp3->age), 1, fp1);

        fread(&emp3->firstname, size, 1, fp1);

        fread(&emp3->middlename, size, 1, fp1);

        fread(&emp3->lastname, size, 1, fp1);

        printf("\n%d %d %s %s %s",emp3->id,emp3->age,emp3->firstname,emp3->middlename,emp3->lastname);

        i++;

    }

    fclose(fp1);

    free(emp3->firstname);
    free(emp3->middlename);
    free(emp3->lastname);

    free(emp3); 

}



void update()

{

    int id,age, flag = 0, i = 1;

    char sf[size],sm[size],sl[size];



    if (fp1 == NULL)

    {

        printf("File cant be opened");

        return;

    }

    printf("Enter employee id to update : ");

    scanf("%d", &id);

    printf("Enter employee age to update : ");

    scanf("%d", &age);

    emp3 = (struct emp *)malloc(1*sizeof(struct emp));

    emp3->firstname=(char *)malloc(size*sizeof(char));
    emp3->middlename=(char *)malloc(size*sizeof(char));
    emp3->lastname=(char *)malloc(size*sizeof(char));

    while(i<=count)

    {    

        fread(&emp3->id, sizeof(emp3->id), 1, fp1);
        fread(&emp3->age, sizeof(emp3->age), 1, fp1);

        fread(emp3->firstname,size,1,fp1) ;
        fread(emp3->middlename,size,1,fp1) ;
        fread(emp3->lastname,size,1,fp1) ;

        if (id == emp3->id)

        {

            printf("Enter new firstname of emplyee to update : ");    

            scanf(" %[^\n]s", sf);

            printf("Enter new middlename of emplyee to update : ");    

            scanf(" %[^\n]s", sm);

            printf("Enter new lastname of emplyee to update : ");    

            scanf(" %[^\n]s", sl);

            fseek(fp1, -204L, SEEK_CUR);

            fwrite(&emp3->id, sizeof(emp3->id), 1, fp1);

            fwrite(&emp3->age, sizeof(emp3->age), 1, fp1);

            fwrite(sf, size, 1, fp1);
            fwrite(sm, size, 1, fp1);
            fwrite(sl, size, 1, fp1);

            flag = 1;

            break;

        }

        i++;

    }

    if (flag != 1)

    {

        printf("No employee record found");

        flag = 0;

    }

    fclose(fp1);

    free(emp3->firstname);
    free(emp3->middlename);
    free(emp3->lastname);        /* to free allocated memory */

    free(emp3);

}
