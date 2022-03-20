#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct
{
    int day;
    int month;
    int year;
} DOB; //contact dob

typedef struct
{
    char Fname[35];
    char Lname[35];
    char address[100];
    char number[15];
    char email[100];
    int age;
    DOB dob;
} contact; //one contact data

int count=0,load=0,autosave=0,saved=0,edit=0;
contact c[200]; //struct array of 200 contacts
char OrigFileName[25]; //stores opened file name for any further use

int EmailErrors(char s[])
{
    int i,x=0,periodcounter=0,Atcounter=0,index[15];
    char temp[strlen(s)],*tok;
    for(i=0; i<strlen(s); i++) //@ checker
    {
        if( s[i]=='@')
            Atcounter++;
    }
    if (Atcounter != 1) return 1;
    for(i=0; i<strlen(s); i++) //space checker
    {
        if( s[i]==' ')
            return 2;
    }
    strcpy(temp,s);
    strtok(temp,"@");
    //prefix
    //checking length
    if ((strlen(temp) > 64)) return 3;
    //checking first char
    if ((temp[0] != 'a') && (temp[0] != 'b') && (temp[0] != 'c') && (temp[0] != 'd') && (temp[0] != 'e') && (temp[0] != 'f') && (temp[0] != 'g') && (temp[0] != 'h') && (temp[0] != 'i') && (temp[0] != 'j')
            && (temp[0] != 'k') && (temp[0] != 'l') && (temp[0] != 'm') && (temp[0] != 'n') && (temp[0] != 'o') && (temp[0] != 'p') && (temp[0] != 'q') && (temp[0] != 'r') && (temp[0] != 's') && (temp[0] != 't')
            && (temp[0] != 'u') && (temp[0] != 'v') && (temp[0] != 'w') && (temp[0] != 'x') && (temp[0] != 'y') && (temp[0] != 'z') && (temp[0] != '0') && (temp[0] != '1') && (temp[0] != '2') && (temp[0] != '3')
            && (temp[0] != '4') && (temp[0] != '5') && (temp[0] != '6') && (temp[0] != '7') && (temp[0] != '8') && (temp[0] != '9'))
        return 4;
    for (i=1; i<strlen(temp); i++)
    {
        //checking for 2 consecutive periods, dashes or underscores
        if((temp[i] == '.') || (temp[i] == '-') || (temp[i] == '_'))
        {
            if((temp[i+1] == '.') || (temp[i+1] == '-') || (temp[i+1] == '_'))
                return 5;
        }
        //checking entire prefix
        else if ((temp[i] != 'a') && (temp[i] != 'b') && (temp[i] != 'c') && (temp[i] != 'd') && (temp[i] != 'e') && (temp[i] != 'f') && (temp[i] != 'g') && (temp[i] != 'h') && (temp[i] != 'i') && (temp[i] != 'j')
                 && (temp[i] != 'k') && (temp[i] != 'l') && (temp[i] != 'm') && (temp[i] != 'n') && (temp[i] != 'o') && (temp[i] != 'p') && (temp[i] != 'q') && (temp[i] != 'r') && (temp[i] != 's') && (temp[i] != 't')
                 && (temp[i] != 'u') && (temp[i] != 'v') && (temp[i] != 'w') && (temp[i] != 'x') && (temp[i] != 'y') && (temp[i] != 'z') && (temp[i] != '0') && (temp[i] != '1') && (temp[i] != '2') && (temp[i] != '3')
                 && (temp[i] != '4') && (temp[i] != '5') && (temp[i] != '6') && (temp[i] != '7') && (temp[i] != '8') && (temp[i] != '9') && (temp[i] != '_') && (temp[i] != '.') && (temp[i] != '-')) return 6;
    }
    //checking last char
    if ((temp[strlen(temp)-1] != 'a') && (temp[strlen(temp)-1] != 'b') && (temp[strlen(temp)-1] != 'c') && (temp[strlen(temp)-1] != 'd') && (temp[strlen(temp)-1] != 'e') && (temp[strlen(temp)-1] != 'f') && (temp[strlen(temp)-1] != 'g') && (temp[strlen(temp)-1] != 'h') && (temp[strlen(temp)-1] != 'i') && (temp[strlen(temp)-1] != 'j')
            && (temp[strlen(temp)-1] != 'k') && (temp[strlen(temp)-1] != 'l') && (temp[strlen(temp)-1] != 'm') && (temp[strlen(temp)-1] != 'n') && (temp[strlen(temp)-1] != 'o') && (temp[strlen(temp)-1] != 'p') && (temp[strlen(temp)-1] != 'q') && (temp[strlen(temp)-1] != 'r') && (temp[strlen(temp)-1] != 's') && (temp[strlen(temp)-1] != 't')
            && (temp[strlen(temp)-1] != 'u') && (temp[strlen(temp)-1] != 'v') && (temp[strlen(temp)-1] != 'w') && (temp[strlen(temp)-1] != 'x') && (temp[strlen(temp)-1] != 'y') && (temp[strlen(temp)-1] != 'z') && (temp[strlen(temp)-1] != '0') && (temp[strlen(temp)-1] != '1') && (temp[strlen(temp)-1] != '2') && (temp[strlen(temp)-1] != '3')
            && (temp[strlen(temp)-1] != '4') && (temp[strlen(temp)-1] != '5') && (temp[strlen(temp)-1] != '6') && (temp[strlen(temp)-1] != '7') && (temp[strlen(temp)-1] != '8') && (temp[strlen(temp)-1] != '9')) return 7;
    strcpy(temp,s);
    tok=strtok(temp,"@");
    tok=strtok(NULL,"");
    strcpy(temp,tok);
    //domain
    //checking length
    if ((strlen(temp) > 253)) return 8;
    //checking first char
    if ((temp[0] != 'a') && (temp[0] != 'b') && (temp[0] != 'c') && (temp[0] != 'd') && (temp[0] != 'e') && (temp[0] != 'f') && (temp[0] != 'g') && (temp[0] != 'h') && (temp[0] != 'i') && (temp[0] != 'j')
            && (temp[0] != 'k') && (temp[0] != 'l') && (temp[0] != 'm') && (temp[0] != 'n') && (temp[0] != 'o') && (temp[0] != 'p') && (temp[0] != 'q') && (temp[0] != 'r') && (temp[0] != 's') && (temp[0] != 't')
            && (temp[0] != 'u') && (temp[0] != 'v') && (temp[0] != 'w') && (temp[0] != 'x') && (temp[0] != 'y') && (temp[0] != 'z') && (temp[0] != '0') && (temp[0] != '1') && (temp[0] != '2') && (temp[0] != '3')
            && (temp[0] != '4') && (temp[0] != '5') && (temp[0] != '6') && (temp[0] != '7') && (temp[0] != '8') && (temp[0] != '9'))
        return 9;
    for(i=0; i<strlen(temp); i++)
    {
        //checking that domain contains at least one period
        if ((temp[i]=='.'))
        {
            periodcounter++;
            index[x]=i;
            x++;
        }
    }
    if(!periodcounter) return 10;
    for (i=1; i<strlen(temp); i++)
    {
        //checking for 2 consecutive periods, dashes or underscores
        if((temp[i] == '.') || (temp[i] == '-'))
        {
            if((temp[i+1] == '.') || (temp[i+1] == '-'))
                return 11;
        }
        //checking entire domain
        else if ((temp[i] != 'a') && (temp[i] != 'b') && (temp[i] != 'c') && (temp[i] != 'd') && (temp[i] != 'e') && (temp[i] != 'f') && (temp[i] != 'g') && (temp[i] != 'h') && (temp[i] != 'i') && (temp[i] != 'j')
                 && (temp[i] != 'k') && (temp[i] != 'l') && (temp[i] != 'm') && (temp[i] != 'n') && (temp[i] != 'o') && (temp[i] != 'p') && (temp[i] != 'q') && (temp[i] != 'r') && (temp[i] != 's') && (temp[i] != 't')
                 && (temp[i] != 'u') && (temp[i] != 'v') && (temp[i] != 'w') && (temp[i] != 'x') && (temp[i] != 'y') && (temp[i] != 'z') && (temp[i] != '0') && (temp[i] != '1') && (temp[i] != '2') && (temp[i] != '3')
                 && (temp[i] != '4') && (temp[i] != '5') && (temp[i] != '6') && (temp[i] != '7') && (temp[i] != '8') && (temp[i] != '9') && (temp[i] != '.') && (temp[i] != '-')) return 12;
    }
    //checking the top-level domain
    if (strlen(temp)>(index[periodcounter-1]+4)) return 13;
    if ((temp[index[periodcounter-1]+1] == 'c'))
    {
        if ((temp[index[periodcounter-1]+2] != 'o')) return 14;
        else if ((temp[index[periodcounter-1]+3] != 'm')) return 14;
    }
    else if ((temp[index[periodcounter-1]+1] == 'o'))
    {
        if ((temp[index[periodcounter-1]+2] != 'r')) return 14;
        else if ((temp[index[periodcounter-1]+3] != 'g')) return 14;
    }
    else if ((temp[index[periodcounter-1]+1] == 'n'))
    {
        if ((temp[index[periodcounter-1]+2] != 'e')) return 14;
        else if ((temp[index[periodcounter-1]+3] != 't')) return 14;
    }
    else if ( (temp[index[periodcounter-1]+1] != 'c') && (temp[index[periodcounter-1]+1] != 'o') && (temp[index[periodcounter-1]+1] != 'n')) return 14;
    return 0;
}

void CorrectLettersCase(char s[]) //function to change letter cases of names
{
    strlwr(s);
    s[0]=toupper(s[0]);
}

void ErrorsOfContact()
{

    int i,j;
    //DOB
    for(i=0; i<count; i++)
    {
        while (c[i].dob.day < 1 || c[i].dob.day > 31)
        {
            printf("\nContact %s %s with birth day \"%d\", has wrong birth day, birth day must be between 1 and 31.\nEnter the correct birth day: ",c[i].Fname,c[i].Lname,c[i].dob.day);
            scanf("%d",&c[i].dob.day);
            getchar();
        }
        while (c[i].dob.month < 1 || c[i].dob.month > 12)
        {
            printf("\nContact %s %s with birth month \"%d\", has wrong birth day, birth month must be between 1 and 12.\nEnter the correct birth month: ",c[i].Fname,c[i].Lname,c[i].dob.month);
            scanf("%d",&c[i].dob.month);
            getchar();
        }
        while (c[i].dob.year > 2021 || c[i].dob.year < 1903)
        {
            printf("\nContact %s %s with birth year \"%d\", has wrong birth year, birth year must be between 1903 and 2021.\nEnter the correct birth year: ",c[i].Fname,c[i].Lname,c[i].dob.year);
            scanf("%d",&c[i].dob.year);
            getchar();
        }
    }
    //Number
    for(i=0; i<count; i++)
    {
        while (1)
        {
            for(j=0; j<strlen(c[i].number); j++)
            {
                while(c[i].number[j] != '0' && c[i].number[j] != '1' && c[i].number[j] != '2' && c[i].number[j] != '3' && c[i].number[j] != '4' && c[i].number[j] != '5' && c[i].number[j] != '6' && c[i].number[j] != '7' && c[i].number[j] != '8' && c[i].number[j] != '9')
                {
                    printf("\nContact %s %s with phone number \"%s\", has wrong number, phone number must contain only numbers.\nEnter the correct number: ",c[i].Fname,c[i].Lname,c[i].number);
                    gets(c[i].number);
                    j=0;
                }
                if(c[i].number[j]==' ')
                {
                    printf("\nContact %s %s with phone number \"%s\", has wrong number, phone number must not contain spaces.\nEnter the correct number: ",c[i].Fname,c[i].Lname,c[i].number);
                    gets(c[i].number);
                }
            }
            break;
        }
    }
    //Email
    int emailerror;
    for(i=0; i<count; i++)
    {
        emailerror=EmailErrors(c[i].email);
        while(emailerror)
        {
            switch (emailerror)
            {
            case 1:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, email must contain exactly one \"@\".\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 2:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, e-mail must not contain spaces.\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 3:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, prefix's length must not exceed 64 characters.\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 4:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, prefix's first character must be an ascii letter (a-z) or number (0-9).\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 5:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, prefix must not contain consecutive periods (.), dashes (-) or underscores (_).\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 6:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, only letters (a-z), numbers(0-9), periods (.), dashes(-), and underscores (_) are allowed in the prefix.\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 7:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, prefix's last character must be an ascii letter (a-z) or number (0-9).\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 8:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, domain's length must exceed 253 characters.\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 9:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, domain's first character must be an ascii letter (a-z) or number (0-9).\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 10:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, domain must contains at least one period (.).\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 11:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, domain must not contain consecutive periods (.) or dashes (-).\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 12:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, only letters (a-z), numbers(0-9), periods (.), and dashes(-) are allowed in the domain.\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 13:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, top-level domain must be one of (.com - .org - .net).\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            case 14:
                printf("\nContact %s %s with e-mail \"%s\", has wrong e-mail, top-level domain must be one of (.com - .org - .net).\n\nEnter the correct e-mail: ",c[i].Fname,c[i].Lname,c[i].email);
                break;
            }
            if(!emailerror) break;
            gets(c[i].email);
            strlwr(c[i].email);
            emailerror=EmailErrors(c[i].email);
        }
    }
}

int CheckAnswerYes_No(char s[]) //function to get error of yes/no questions
{
    if(strlen(s) == 1)
    {
        if(!strcmpi(s,"y"))
            return 1;
        else if (!strcmpi(s,"n"))
            return 0;
        else
        {
            printf("\a\nWrong input, Please enter a correct answer: ");
            gets(s);
            CheckAnswerYes_No(s);
        }
    }
    else
    {
        if (!strcmpi(s,"yes"))
            return 1;
        else if (!strcmpi(s,"no"))
            return 0;
        else
        {
            printf("\a\nWrong input, Please enter a correct answer: ");
            gets(s);
            CheckAnswerYes_No(s);
        }
    }
}

void ReadContactsFromFile() //constructor function for a single contact in a file
{
    count=0;
    char *Filename = (char *)malloc(25);
    FILE *f;
    printf("\nEnter file path (txt files only): ");
    gets(Filename);
    f=fopen(Filename,"r");
    while(f==NULL) //loop operates while the user enters incorrect path
    {
        printf("\n\aFile not found, Please enter the correct path for the file: ");
        gets(Filename);
        f=fopen(Filename,"r");
    }
    while (!feof(f)) //scan data of a contact and adding it in the struct array
    {
        fscanf(f,"%[^,],",c[count].Lname);
        CorrectLettersCase(c[count].Lname);
        fscanf(f,"%[^,],",c[count].Fname);
        CorrectLettersCase(c[count].Fname);
        fscanf(f,"%d-%d-%d,",&c[count].dob.day,&c[count].dob.month,&c[count].dob.year);
        fscanf(f,"%[^,],",c[count].address);
        fscanf(f,"%[^,],",c[count].number);
        fscanf(f,"%[^\n]\n",c[count].email);
        strlwr(c[count].email);
        count ++;
    }
    fclose(f);
    strcpy(OrigFileName,Filename);
    free(Filename);
    printf("\nChecking for errors contact by contact:\n");
    ErrorsOfContact();
    printf("\nNo errors or no errors remaining!\n");
    printf("\n\aFile read successfully!\n");
    load=1; //variable detecting that a file has been loaded
}

void SearchDirectory() //function to search a contact in the directory by last name
{
    int i,j,k=1,counter=0;
    char *Lname = (char*)malloc(35),*Lname1 = (char*)malloc(35);
    printf("\nEnter last name of the contact: ");
    gets(Lname);
    while(Lname[0]=='\0')
    {
        printf("\nNo name entered, please enter a name: ");
        gets(Lname);
    }
    CorrectLettersCase(Lname);
    strcpy(Lname1,Lname);
    strlwr(Lname1);
    if (strlen(Lname) == 1)
    {
        for (i=0; i<count; i++)
        {
            for (j=0; j<(strlen(c[i].Lname)) ; j++)
            {
                if ((strstr(c[i].Lname,Lname)) || (strstr(c[i].Lname,Lname1)))
                {
                    if (k==1)
                        printf("\nContacts found :\n");
                    printf("\n#%d\n",k);
                    printf("First name: %s\n",c[i].Fname);
                    printf("Last name: %s\n",c[i].Lname);
                    printf("Address: %s\n",c[i].address);
                    printf("E-mail: %s\n",c[i].email);
                    printf("Number: %s\n",c[i].number);
                    printf("DOB: %d/%d/%d\n\n",c[i].dob.day,c[i].dob.month,c[i].dob.year);
                    k++;
                    counter ++;
                    break;
                }
            }
        }
    }

    else
    {
        for(i=0; i<count; i++)
        {
            if ((strstr(c[i].Lname,Lname)) || (strstr(c[i].Lname,Lname1)))
            {
                if (k==1)
                    printf("\nContacts found :\n");
                printf("\n#%d\n",k);
                printf("First name: %s\n",c[i].Fname);
                printf("Last name: %s\n",c[i].Lname);
                printf("Address: %s\n",c[i].address);
                printf("E-mail: %s\n",c[i].email);
                printf("Number: %s\n",c[i].number);
                printf("DOB: %d/%d/%d\n\n",c[i].dob.day,c[i].dob.month,c[i].dob.year);
                k++;
                counter ++;
            }
        }
    }
    if(!counter) printf("\a\nNo contacts found.\n");
    free(Lname);
    free(Lname1);
}

void AddContacts() //function to add new contact in the directory but not saved in file
{
    int i,n,j=1;
    printf("\nEnter the number of the contacts you want to add: ");
    scanf("%d",&n);
    getchar();
    i=count;
    count+=n;
    for(i; i<count; i++)
    {
        printf("\nEnter the data for contact #%d\n",j);
        printf("First Name: ");
        gets(c[i].Fname);
        CorrectLettersCase(c[i].Fname);
        printf("Last Name: ");
        gets(c[i].Lname);
        CorrectLettersCase(c[i].Lname);
        printf("Address: ");
        gets(c[i].address);
        printf("Email: ");
        gets(c[i].email);
        strlwr(c[i].email);
        printf("Number: ");
        gets(c[i].number);
        printf("DOB (DD MM YEAR): ");
        scanf("%d %d %d",&c[i].dob.day,&c[i].dob.month,&c[i].dob.year);
        getchar();
        j++;
    }
    if (n==1) printf("\nChecking for errors of new contact:\n");
    else printf("\nChecking for errors of new contacts contact by contact:\n");
    ErrorsOfContact();
    printf("\nNo errors or no errors remaining!\n");
    if(autosave) SaveDirectoryInFile(2);
    edit=1;
    if(n==1) printf("\n\aContact added successfully!\n");
    else printf("\n\aContacts added successfully!\n");
}

void DeleteContact() //function to delete a contact in the directory
{
    int i,x,j=1,counter=0,index[count];
    char *Lname = (char *)malloc(35),*Fname = (char *)malloc(35),*answer;
    printf("\nEnter first name of the contact: ");
    gets(Fname);
    while(Fname[0]=='\0')
    {
        printf("\nNo name entered, please enter a name: ");
        gets(Fname);
    }
    printf("\nEnter last name of the contact: ");
    gets(Lname);
    while(Lname[0]=='\0')
    {
        printf("\nNo name entered, please enter a name: ");
        gets(Lname);
    }
    for (i=0; i<count; i++)
    {
        if ( (!strcmpi(c[i].Lname,Lname)) && (!strcmpi(c[i].Fname,Fname)) )
        {
            if (j==1)
                printf("\nContacts found :\n");
            printf("\n#%d\n",j);
            printf("First name: %s\n",c[i].Fname);
            printf("Last name: %s\n",c[i].Lname);
            printf("Address: %s\n",c[i].address);
            printf("E-mail: %s\n",c[i].email);
            printf("Number: %s\n",c[i].number);
            printf("DOB: %d/%d/%d\n\n",c[i].dob.day,c[i].dob.month,c[i].dob.year);
            index[counter]=i;
            j++;
            counter ++;
        }
    }
    if(!counter) printf("\a\nNo contacts found.\n");
    else if (counter==1)
    {
        answer = (char *)malloc(10);
        printf("\nDo you want to delete this contact?(y/n) >> ");
        gets(answer);
        if(CheckAnswerYes_No(answer))
        {
            for(i=index[0]; i<count; i++)
            {
                c[i]=c[i+1];
            }
            count=count-1;
            if(autosave) SaveDirectoryInFile(2);
            edit=1;
            printf("\n\aDeleted!\n");
        }
        free(answer);
    }
    else
    {
        answer = (char *)malloc(10);
        printf("\nDo you want to delete any of these contacts?(y/n) >> ");
        gets(answer);
        if(CheckAnswerYes_No(answer))
        {
            printf("\nWhich one you want to delete? >> ");
            scanf("%d",&x);
            getchar();
            while (x>counter)
            {
                printf("\n\aWrong input, Please Enter a correct answer: ");
                scanf("%d",&x);
                getchar();
                if (x <= counter) break;
            }
            for(i=index[x-1]; i<count; i++)
            {
                c[i]=c[i+1];
            }
            count=count-1;
            if(autosave) SaveDirectoryInFile(2);
            edit=1;
            printf("\n\aDeleted!\n");
        }
        free(answer);
    }
    free(Lname);
    free(Fname);
}

void ModifyContact() //function to modify a contact in the directory
{
    int i,x,j=1,counter=0,index[count];
    char *Lname = (char *)malloc(35),*Lname1 = (char *)malloc(35),*answer;
    printf("\nEnter last name of the contact: ");
    gets(Lname);
    while(Lname[0]=='\0')
    {
        printf("\nNo name entered, please enter a name: ");
        gets(Lname);
    }
    CorrectLettersCase(Lname);
    strcpy(Lname1,Lname);
    strlwr(Lname1);
    if (strlen(Lname) == 1)
    {
        for (i=0; i<count; i++)
        {
            for (j=0; j<(strlen(c[i].Lname)) ; j++)
            {
                if ((strstr(c[i].Lname,Lname)) || (strstr(c[i].Lname,Lname1)))
                {
                    if (j==1)
                        printf("\nContacts found :\n");
                    printf("\n#%d\n",j);
                    printf("First name: %s\n",c[i].Fname);
                    printf("Last name: %s\n",c[i].Lname);
                    printf("Address: %s\n",c[i].address);
                    printf("E-mail: %s\n",c[i].email);
                    printf("Number: %s\n",c[i].number);
                    printf("DOB: %d/%d/%d\n\n",c[i].dob.day,c[i].dob.month,c[i].dob.year);
                    index[counter]=i;
                    j++;
                    counter ++;
                    break;
                }
            }
        }
    }

    else
    {
        for(i=0; i<count; i++)
        {
            if ((strstr(c[i].Lname,Lname)|| (strstr(c[i].Lname,Lname1))))
            {
                if (j==1)
                    printf("\nContacts found :\n");
                printf("\n#%d\n",j);
                printf("First name: %s\n",c[i].Fname);
                printf("Last name: %s\n",c[i].Lname);
                printf("Address: %s\n",c[i].address);
                printf("E-mail: %s\n",c[i].email);
                printf("Number: %s\n",c[i].number);
                printf("DOB: %d/%d/%d\n\n",c[i].dob.day,c[i].dob.month,c[i].dob.year);
                index[counter]=i;
                j++;
                counter ++;
            }
        }
    }
    j=1;
    if(!counter) printf("\a\nNo contacts found.\n");
    else if (counter==1)
    {
        answer = (char *)malloc(10);
        printf("Do you want to modify this contact?(y/n) >> ");
        gets(answer);
        if(CheckAnswerYes_No(answer))
        {
            if (j==1)
                printf("\nEnter modified data for the contact:\n");
            printf("First Name: ");
            gets(c[index[0]].Fname);
            CorrectLettersCase(c[index[0]].Fname);
            printf("Last Name: ");
            gets(c[index[0]].Lname);
            CorrectLettersCase(c[index[0]].Lname);
            printf("Address: ");
            gets(c[index[0]].address);
            printf("Email: ");
            gets(c[index[0]].email);
            strlwr(c[index[0]].email);
            printf("Number: ");
            gets(c[index[0]].number);
            printf("DOB (DD MM YEAR): ");
            scanf("%d %d %d",&c[index[0]].dob.day,&c[index[0]].dob.month,&c[index[0]].dob.year);
            getchar();
            printf("\nChecking for errors of the modified contact:\n");
            ErrorsOfContact();
            printf("\nNo errors or no errors remaining!\n");
            if(autosave) SaveDirectoryInFile(2);
            edit=1;
            printf("\n\aModified!\n");
        }
        free(answer);
    }
    else
    {
        answer = (char *)malloc(10);
        printf("\nDo you want to modify any of these contacts?(y/n) >> ");
        gets(answer);
        if(CheckAnswerYes_No(answer))
        {
            printf("\nWhich one you want to modify? ");
            scanf("%d",&x);
            getchar();
            while (x>counter)
            {
                printf("\n\aWrong input, Please Enter a correct answer: ");
                scanf("%d",&x);
                getchar();
                if (x <= counter) break;
            }
            if (j==1)
                printf("\nEnter modified data for contact #%d:\n",x);
            printf("First Name: ");
            gets(c[index[x-1]].Fname);
            CorrectLettersCase(c[index[x-1]].Fname);
            printf("Last Name: ");
            gets(c[index[x-1]].Lname);
            CorrectLettersCase(c[index[x-1]].Lname);
            printf("Address: ");
            gets(c[index[x-1]].address);
            printf("Email: ");
            gets(c[index[x-1]].email);
            strlwr(c[index[x-1]].email);
            printf("Number: ");
            gets(c[index[x-1]].number);
            printf("DOB (DD MM YEAR): ");
            scanf("%d %d %d",&c[index[x-1]].dob.day,&c[index[x-1]].dob.month,&c[index[x-1]].dob.year);
            getchar();
            printf("\nChecking for errors of the modified contact:\n");
            ErrorsOfContact();
            printf("\nNo errors or no errors remaining!\n");
            if(autosave) SaveDirectoryInFile(2);
            edit=1;
            printf("\n\aModified!\n");
        }
        free(answer);
    }
    free(Lname1);
    free(Lname);
}

void SortContactsByLname() //function to sort directory according to Lname
{
    contact temp;
    int i,j;
    for (i=1; i<count; i++)
    {
        for (j=0; j<count-i; j++)
        {
            if (strcmpi(c[j].Lname,c[j+1].Lname) > 0)
            {
                temp = c[j];
                c[j]=c[j + 1];
                c[j+1]=temp;
            }
        }
    }
}

void SortContactsByDOB() //function to sort directory according to DOB
{
    int i,j;
    contact temp;
    for (i=1; i<count; i++)
    {
        for (j=0; j<count-i; j++)
        {
            if (c[j].dob.year == c[j+1].dob.year)
            {
                if( c[j].dob.month == c[j+1].dob.month)
                {
                    if(c[j].dob.day < c[j+1].dob.day)
                    {
                        temp = c[j];
                        c[j]=c[j + 1];
                        c[j+1]=temp;
                    }
                }
                else if ( c[j].dob.month < c[j+1].dob.month)
                {
                    temp = c[j];
                    c[j]=c[j + 1];
                    c[j+1]=temp;
                }
            }
            else if (c[j].dob.year < c[j+1].dob.year )
            {
                temp = c[j];
                c[j]=c[j + 1];
                c[j+1]=temp;
            }
        }
    }
}

void AskSorting()
{
    int x;
    printf("\nHow do you want to sort the directory?\n1.By Last name\t2.By DOB   >> ");
    scanf("%d",&x);
    getchar();
    while((x!=1) && (x!=2))
    {
        printf("\aWrong input, Please Enter a correct answer: ");
        scanf("%d",&x);
        getchar();
        if ((x==1)||(x==2)) break;
    }
    switch (x)
    {
    case 1:
        SortContactsByLname();
        break;
    case 2:
        SortContactsByLname();
        SortContactsByDOB();
        break;
    }
}

void PrintDirectory()
{
    int i,by;
    AskSorting();
    printf("\n\nTHE PHONE DIRECTORY\n");
    printf("===================\n");
    printf("\nFirst name\tLast name\tNumber\t\tE-Mail\t\t\t\tAddress\t\t\t\t  DOB\n");
    printf("____________________________________________________________________________________________________________________________\n\n");
    for(i=0; i<count; i++)
    {
        if(c[i].dob.year >= 2000) by = c[i].dob.year-2000;
        if(c[i].dob.year < 2000) by = c[i].dob.year-1900;
        printf("%-15s\t%-15s\t%-11s\t%-25s\t%-25s\t  %02d/%02d/%02d\n",c[i].Fname,c[i].Lname,c[i].number,c[i].email,c[i].address,c[i].dob.day,c[i].dob.month,by);
        printf("____________________________________________________________________________________________________________________________\n\n");
    }
}

void SaveDirectoryInFile(int mode)
{
    char *Filename,*answer;
    FILE *f;
    int i;
    switch (mode)
    {
    case 1:
        answer = (char *)malloc(10);
        printf("\nDo you want to save in the same file?(y/n) >> ");
        gets(answer);
        if (CheckAnswerYes_No(answer))
        {
            f=fopen(OrigFileName,"w");
            for(i=0; i<count; i++)
            {
                fprintf(f,"%s,",c[i].Lname);
                fprintf(f,"%s,",c[i].Fname);
                fprintf(f,"%d-%d-%d,",c[i].dob.day,c[i].dob.month,c[i].dob.year);
                fprintf(f,"%s,",c[i].address);
                fprintf(f,"%s,",c[i].number);
                fprintf(f,"%s\n",c[i].email);
            }
            fclose(f);
            printf("\a\nSaved!");
        }
        else
        {
            Filename=(char *)malloc(25);
            printf("\nEnter the new file name: ");
            gets(Filename);
            strcat(Filename,".txt");
            f=fopen(Filename,"w");
            for(i=0; i<count; i++)
            {
                fprintf(f,"%s,",c[i].Lname);
                fprintf(f,"%s,",c[i].Fname);
                fprintf(f,"%d-%d-%d,",c[i].dob.day,c[i].dob.month,c[i].dob.year);
                fprintf(f,"%s,",c[i].address);
                fprintf(f,"%s,",c[i].number);
                fprintf(f,"%s\n",c[i].email);
            }
            fclose(f);
            free(Filename);
            printf("\a\nSaved!");
        }
        free(answer);
        break;
    case 2:
        f=fopen(OrigFileName,"w");
        for(i=0; i<count; i++)
        {
            fprintf(f,"%s,",c[i].Lname);
            fprintf(f,"%s,",c[i].Fname);
            fprintf(f,"%d-%d-%d,",c[i].dob.day,c[i].dob.month,c[i].dob.year);
            fprintf(f,"%s,",c[i].address);
            fprintf(f,"%s,",c[i].number);
            fprintf(f,"%s\n",c[i].email);
        }
        fclose(f);
        break;
    }
}

void QuitProgram(int mode)
{
    char *answer;
    switch(mode)
    {
    case 1:
        exit(0);
    case 2:
        answer = (char *)malloc(10);
        printf("\a\nCurrently opened file \"%s\" is not saved, Do you want to save it?(y/n) >> ",OrigFileName);
        gets(answer);
        CorrectLettersCase(answer);
        if(CheckAnswerYes_No(answer))
        {
            SaveDirectoryInFile(1);
            free(answer);
            exit(0);
        }

        else
        {
            free(answer);
            exit(0);
        }
    }
}

void CommandsMenu()
{
    printf("Commands Menu\n");
    printf("=============\n");
    printf("Command Name\tFunction\n");
    printf("============\t========\n");
    printf("LOAD        \tRead data from a file\n");
    printf("QUERY       \tSearch the directory\n");
    printf("ADD         \tAdd new contacts to the directory\n");
    printf("DELETE      \tDelete a certain contact from the directory\n");
    printf("MODIFY      \tModify a certain contact into the directory\n");
    printf("PRINT       \tPrint the entire directory (sorted)\n");
    printf("SAVE        \tSave the directory into a text file (.txt)\n");
    printf("MENU        \tPrint the commands menu\n");
    printf("AUTOSAVE    \tAutosave all commands executed in the original opened file\n");
    printf("SORTF       \tSort currently opened file\n");
    printf("PRINTO      \tPrint currently opened file name\n");
    printf("LOADN       \tRead date from a new file\n");
    printf("QUIT        \tExit the program\n\n");
}

void CommandsOperators(char s[])
{
    char *answer;
    if((!strcmpi(s,"quit")) && !load)
        QuitProgram(1);
    if ((strcmpi(s,"load")) && (strcmpi(s,"query")) && (strcmpi(s,"add")) && (strcmpi(s,"delete")) && (strcmpi(s,"modify")) && (strcmpi(s,"print")) && (strcmpi(s,"save")) && (strcmpi(s,"menu")) && (strcmpi(s,"autosave")) && (strcmpi(s,"sortf")) && (strcmpi(s,"printo")) && (strcmpi(s,"loadn"))
            && (strcmpi(s,"quit")))
    {
        printf("\n\aWrong command or command not found!");
        return;
    }
    if ((!strcmpi(s,"load")) && load)
    {
        printf("\n\aA file is already open.");
        return;
    }
    else if (!strcmpi(s,"LOAD"))
    {
        ReadContactsFromFile();
        return;
    }
    while (load)
    {
        if ( (!strcmpi(s,"autosave")) && load )
        {
            autosave=1;
            printf("\n\aAutosave activated!");
            return;
        }
        else if ( (!strcmpi(s,"query")) && load )
        {
            SearchDirectory();
            return;
        }
        else if ( (!strcmpi(s,"add")) && load )
        {
            AddContacts();
            return;
        }
        else if ( (!strcmpi(s,"delete")) && load )
        {
            DeleteContact();
            return;
        }
        else if ( (!strcmpi(s,"modify")) && load )
        {
            ModifyContact();
            return;
        }
        else if ( (!strcmpi(s,"sortf")) && load )
        {
            AskSorting();
            printf("\a\nSorted!");
            SaveDirectoryInFile(2);
            return;
        }
        else if ( (!strcmpi(s,"print")) && load )
        {
            PrintDirectory();
            return;
        }
        else if ( (!strcmpi(s,"printo")) && load )
        {
            printf("\nCurrently opened file's name is \"%s\".",OrigFileName);
            return;
        }
        else if ( (!strcmpi(s,"save")) && load )
        {
            SaveDirectoryInFile(1);
            saved=1;
            return;
        }
        else if ( (!strcmpi(s,"menu")) && load )
        {
            printf("\n\n");
            CommandsMenu();
            return;
        }
        else if ( (!strcmpi(s,"quit")) && load )
        {
            if (autosave || saved || !edit) QuitProgram(1);
            else QuitProgram(2);
        }
        else if ( (!strcmpi(s,"loadn")) && load )
        {
            if (edit && !autosave && !saved)
            {
                answer = (char *)malloc(10);
                printf("\a\nCurrently opened file \"%s\" is not saved, Do you want to save it?(y/n) >> ",OrigFileName);
                gets(answer);
                CorrectLettersCase(answer);
                if(CheckAnswerYes_No(answer))
                {
                    SaveDirectoryInFile(1);
                    printf("\n");
                    load=0;
                    autosave=0;
                    saved=0;
                    edit=0;
                    ReadContactsFromFile();
                }
                else ReadContactsFromFile();
                free(answer);
            }
            else if(!edit)
            {
                load=0;
                autosave=0;
                saved=0;
                edit=0;
                ReadContactsFromFile();
            }
            else if ((autosave || saved) && edit)
            {
                load=0;
                autosave=0;
                saved=0;
                edit=0;
                ReadContactsFromFile();
            }
            return;
        }
    }
    if (!load) printf("\a\nNo file opened!");
}

int main()
{
    char*answer;
    CommandsMenu();
    while(1)
    {
        answer=(char *)malloc(35);
        printf("Type a command >> ");
        gets(answer);
        CommandsOperators(answer);
        free(answer);
        printf("\n\n");
    }
    return 0;
}

