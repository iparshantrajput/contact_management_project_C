//Project Social Contacts Management System
//Authors: Parshant., Muhammad Faraz, Azib Tanveer
//Started: 20-12-2018
//Last modified: 28-12-2018

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000
void deleteLine(FILE *srcFile, FILE *tempFile, const int line);
void printFile(FILE *fptr);
void mainMenu();
void deleteAccount();
void editAccount();
void removeContact();
int accountDisplay();
void main()
{
	int set=0;
	mainMenu();
}
void mainMenu()
{
	int choice = 0;
	int ret=0;
	char name[20];
	char number[50];
	char email[20];
	int exist=0;
	int set=0;
	int i = 0;
	int delete_status=0;
	char contactList[100][3];
	char userName[30];
	char userContact[15];
	char userEmail[20];
	char editName[30];
	char editContact[15];
	char editEmail[20];
	FILE *fp;
	FILE *srcFile;
    FILE *tempFile;
    char path[100];
    int line;
	FILE *user;
	char record[1000][1000];
	char data;
	int k = 0;
	FILE *fTemp;
	int count = 0;
   	char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE];
	
	printf("\n\t\t     * Social Contacts Management System *\t\t");
	printf("\t\t\t\n\t\t===============================================\n\n");
	printf("\n\n\t\t\t    1. Sign In\n\n");
	printf("\t\t\t    2. Sign Up\n\n");
	printf("\t\t\t    3. Delete Account\n\n");
	printf("\t\t\t    4. Remove a Contact from your account\n\n");
	printf("\t\t\t    5. Edit Account\n\n");
	printf("\t\t\t    0. Exit\n\n\n\n");
	printf("\t\t===============================================\n");
	printf("\t\t\n\t\tEnter your choice: ");
	scanf("%d",&choice);
	
	while((choice != 1) && (choice != 2) && (choice != 0) && (choice != 3) && (choice != 4) && (choice != 5))		//Restriction For Validation
	{
		printf("\n\t\tInvalid choice!!! \n\t\tEnter choice again: ");
		scanf("%d",&choice);
	}
	
	if(choice == 0)												//Exit Part
	{
		system("cls");
		printf("\n\n\n");
		printf("\n\t\t===============================================\n\n");
		printf("\n\n\t\t\tThank you for using this app :) \n");	
		printf("\t\t\tPress any key to exit \n\n\n\n");
		printf("\t\t===============================================\n\n\n");
	}
	else if(choice == 3)										//Deleting Account
	{
		system("cls");
		printf("\n\t\t\t\t  * DELETING ACCOUNT *\t\t\n");
		printf("\n\t\t===============================================\n\n");
		deleteAccount();
	}
	else if(choice == 4)										//Deleting Account
	{
		system("cls");
		printf("\n\t\t\t\t  * REMOVE CONTACT *\t\t\n");
		printf("\n\t\t===============================================\n\n");
		removeContact();
	}
	else if(choice == 5)										//Editing Account
	{
		system("cls");
		printf("\n\t\t\t\t  * EDITING ACCOUNT *\t\t\n");
		printf("\n\t\t===============================================\n\n");
		editAccount();
	}
	else if(choice == 1)										//Sign In
	{
		system("cls");
		printf("\n\t\t\t\t  * SIGN IN *\t\t\n");
		printf("\n\t\t===============================================\n\n");
		printf("\n\n\t\t\t\tName: ");
		fflush(stdin);	
		fgets(name,20,stdin);
		printf("\n\t\t\t\tPhone Number: ");
		scanf("%s",number);
		sprintf(number,"%s.txt",number);
		while(NULL == fopen(number, "r"))						//Restriction For Validation of correct login
		{
    		printf("\n\t\t\tUser Name or Password Incorrect !!!");
        	printf("\n\n\t\t\t\tName: ");
			fflush(stdin);	
			fgets(name,20,stdin);
        	printf("\n\t\t\t\tPhone Number: ");
			scanf("%s",number);
			sprintf(number,"%s.txt",number);
    	}
    		choice = accountDisplay();
		
		if(choice==1)														//Contact Adding
		{
			system("cls");
			printf("\n\n\n\t\t\t\t* Add Account *");
			printf("\n\n\t\t===============================================\n");
			user = fopen(number,"a");
			while(choice != 0 && choice != 5)
			{
				printf("\n\n\t\tName: ");
				fflush(stdin);
				fgets(userName,30,stdin);
				
				printf("\n\n\t\tContact: ");
				fflush(stdin);
				fgets(userContact,15,stdin);
				
				printf("\n\n\t\tEmail-Id: ");
				fflush(stdin);
				fgets(userEmail,20,stdin);
	
				fprintf(user," \b%s %s %s",userName,userContact,userEmail);
				fprintf(user,"---------------------------------------------------\n");
				printf("\n\t\t\t\tContact Added\n");	
				printf("\n\n\t\t===============================================\n\n");
				printf("\t\tAdd another contact[6]");  
				printf("\t\tMain Menu[0]");
				printf("\t\t\t\t Exit [5]\n\n");
				printf("\t\t\tEnter your choice: ");
				scanf("%d",&choice);
			}
			if(choice == 0)											//For Main Menu
				accountDisplay();
			else if(choice == 5)									//Exit Part
			{
				system("cls");
				printf("\n\n\n");
				printf("\n\t\t===============================================\n\n");
				printf("\n\n\t\t\tThank you for using this app :) \n");	
				printf("\t\t\tPress any key to exit \n\n\n\n");
				printf("\t\t===============================================\n\n\n");
			}
			else
			{
				while((choice != 0) && (choice != 1))
				{
					printf("\n\t\tInvalid choice!!! \n\t\tEnter choice again: ");
					scanf("%d",&choice);
				}
			}
			
				fclose(user);
		}
		else if(choice==0)
		{
			system("cls");
			mainMenu();
		}
		else if(choice==6)
		{
			system("cls");
			printf("\n\n\n\t\t\t\t* Your All Contacts *");
			printf("\n\n\t\t===============================================\n");
			user = fopen(number,"r");
			while(fscanf(user, "%s%\ns\n%s\n",userName,userContact,userEmail) != EOF)
			{
				printf("%s",userName);
				printf("%s",userContact);
				printf("%s",userEmail);
			}
			fclose(user);
			if(choice == 0)											//For Main Menu
				accountDisplay();
	
			else if(choice == 5)									//Exit Part
			{
				system("cls");
				printf("\n\n\n");
				printf("\n\t\t===============================================\n\n");
				printf("\n\n\t\t\tThank you for using this app :) \n");	
				printf("\t\t\tPress any key to exit \n\n\n\n");
				printf("\t\t===============================================\n\n\n");
			}
			else
			{
				while((choice != 0) && (choice != 1))
				{
					printf("\n\t\tInvalid choice!!! \n\t\tEnter choice again: ");
					scanf("%d",&choice);
				}
			}
			
				
		}
		else if(choice==5)
		{
			system("cls");
			printf("\n\n\n");
			printf("\n\t\t===============================================\n\n");
			printf("\n\n\t\t\tThank you for using this app :) \n");	
			printf("\t\t\tPress any key to exit \n\n\n\n");
			printf("\t\t===============================================\n\n\n");
		}
		if(choice==2)														//List all contacts
		{
			system("cls");
			printf("\n\t\t\t\t* Your Contacts *");
			printf("\n\n\t\t====================================================\n");
			user = fopen(number,"r");
			
			if(user == NULL)
			{
				printf("\t\t\t\tNo Contacts Available");
			}
			else
			{

				printf("\tS.No\tName\n\n\t\tContact\n\n\t\tEmail\n\n");
   				printf("\t----------------------------------");
				
				for(i = 0; data != EOF; ++i)
   				{
   					fgets(record[i], 1000, user);
   					data = getc(user);
   					k++;
				}
   				
   				for(i = 0; i < k; ++i)
				{
					printf("\n\t[%d]\t",i);
   					puts(record[i]);
   					data = getc(user);
				} 
				
			}
				printf("\n\n\t\t===============================================\n\n");
				printf("\t\tMain Menu[0]");
				printf("\t\t\t\t Exit [5]\n\n");
				printf("\t\t\tEnter your choice: ");
				scanf("%d",&choice);
			
				if(choice == 0)											//For Main Menu
					accountDisplay();
				else if(choice == 5)									//Exit Part
				{
					system("cls");
					printf("\n\n\n");
					printf("\n\t\t===============================================\n\n");
					printf("\n\n\t\t\tThank you for using this app :) \n");	
					printf("\t\t\tPress any key to exit \n\n\n\n");
					printf("\t\t===============================================\n\n\n");
				}
				else
				{
					while((choice != 0) && (choice != 1))
					{
						printf("\n\t\tInvalid choice!!! \n\t\tEnter choice again: ");
						scanf("%d",&choice);
					}
				}
			
			fclose(user);
		}
		if(choice==3)														//Contact Adding
		{
			system("cls");
			printf("\n\n\n\t\t\t\t* Edit Contact *");
			printf("\n\n\t\t===============================================\n");
			user = fopen(number,"w+");
			printf("\n\n\t\tName to edit: ");
			fflush(stdin);
			fgets(editName,30,stdin);
			printf("\n\n\t\tContact to edit: ");
			fflush(stdin);
			fgets(editContact,15,stdin);
			printf("\n\n\t\tEmail-Id to edit: ");
			fflush(stdin);
			fgets(editEmail,20,stdin);
			fprintf(user,"%s %s %s",userName, userContact, userEmail);
			printf("\n");
			printf("\n\t\t\t\tContact Edited\n");	
			printf("\n\n\t\t===============================================\n\n");
			printf("\t\tMain Menu[0]");
			printf("\t\t\t\t Exit [5]\n\n");
			printf("\t\t\tEnter your choice: ");
			scanf("%d",&choice);
			
			if(choice == 0)									//For Main Menu
				accountDisplay();
			else if(choice == 5)									//Exit Part
			{
				system("cls");
				printf("\n\n\n");
				printf("\n\t\t===============================================\n\n");
				printf("\n\n\t\t\tThank you for using this app :) \n");	
				printf("\t\t\tPress any key to exit \n\n\n\n");
				printf("\t\t===============================================\n\n\n");
			}
			else
			{
				while((choice != 0) && (choice != 1))
				{
					printf("\n\t\tInvalid choice!!! \n\t\tEnter choice again: ");
					scanf("%d",&choice);
				}
			}
			
			fclose(user);
		}
	}
	else if(choice == 2)						//Sign Up Section
	{
		system("cls");
		printf("\n\t\t\t\t  * SIGN UP *\t\t\ns");
		printf("\n\t\t===============================================\n\n");
		printf("\t\t\tPhone Number: ");
		scanf("%s",number);
		sprintf(number,"%s.txt",number);
		user = fopen(number,"a");
		printf("\n\t\t\tName: ");
		fflush(stdin);	
		fgets(name,20,stdin);
		printf("\n\t\t\tEmail: ");
		fflush(stdin);
		fgets(email,20,stdin);
		printf("\n\n\t\t\tAccount Created Successfully");
		printf("\n\n\n\t\t===============================================\n\n\n");
		fclose(user);
	}
	return;
}
int accountDisplay()										//User Menu
{
	int choice = 0;
	system("cls");
	printf("\n\t\t\t\t* Your Account *");
	printf("\n\n\t\t===============================================\n");
	printf("\n\n\n\t\t\t1. Add A Contact ");
	printf("\n\n\n\t\t\t2. List All Contact");
	printf("\n\n\n\n\t\t===============================================\n\n");
	printf("\t\tLog Out [0]");
	printf("\t\t\t\t Exit [5]\n\n");
	printf("\t\tEnter your choice: ");
	scanf("%d",&choice);
	return choice;	
}

void editAccount()
{
	/* File pointer to hold reference of input file */
    FILE * fPtr;
    FILE * fTemp;
    char ch;
    char path[100];
    
    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE];
    int line, count;


    printf("\n\n\t\tEnter your Account number here: ");
    scanf("%s", path);
	sprintf(path,"%s.txt",path);
	
	/* Try to open file */
    fPtr  = fopen(path, "r");
    /* Exit if file not opened successfully */
    	if (fPtr == NULL)
    	{
        	while(fPtr == NULL)	
   		 	{
   		 		printf("\n\t\tUnable to open file !!!\n");
        		printf("\t\tPlease check you have put the correct account number.\n");
    			printf("\n\n\t\tEnter your Account number here: ");
    			scanf("%s", path);
				sprintf(path,"%s.txt",path);
				/* Try to open file */
    			fPtr  = fopen(path, "r");
			}
    	}
	printf("\nFile contents before editing anything.\n");
	while((ch = fgetc(fPtr)) != EOF)
    {
        putchar(ch);
    }
    fclose(fPtr);
    printf("\n\nDear user please count the dashed line(---) also while counting the lines.");
    printf("\nEnter line number to edit it: ");
    scanf("%d", &line);
	
    /* Remove extra new line character from stdin */
    fflush(stdin);
	
    printf("\nReplace '%d' line with: ", line);
    fgets(newline, BUFFER_SIZE, stdin);


    /*  Open all required files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after replacing given line.
     */
    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

        /* If current line is line to replace */
        if (count == line)
            fputs(newline, fTemp);
        else
            fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(path);

    /* Rename temporary file as original file */
    rename("replace.tmp", path);
	 printf("\n\n\nFile contents after replacing line No.%d data:\n\n", line);

    // Open source file and print its contents
    fPtr = fopen(path, "r");
    
    while((ch = fgetc(fPtr)) != EOF)
    {
        putchar(ch);
    }
    fclose(fPtr);
    
    printf("\nSuccessfully replaced line '%d' with '%s'.", line, newline);
}
void removeContact()
{
	FILE *srcFile;
    FILE *tempFile;

    char path[100];

    int line;


    /* Input file path and line number */
    printf("\t\tEnter your Account number here: ");
    scanf("%s", path);
	sprintf(path,"%s.txt",path);
	/* Try to open file */
    srcFile  = fopen(path, "r");
    /* Exit if file not opened successfully */
    	if (srcFile == NULL || tempFile == NULL)
    	{
        	while(srcFile == NULL)	
   		 	{
   		 		printf("\n\t\tUnable to open file !!!\n");
        		printf("\t\tPlease check you have put the correct account number.\n");
    			printf("\n\n\t\tEnter your Account number here: ");
    			scanf("%s", path);
				sprintf(path,"%s.txt",path);
				/* Try to open file */
    			srcFile  = fopen(path, "r");
			}
    	}
    
    tempFile = fopen("delete-line.tmp", "w");
	printf("\nFile contents before removing anything.\n");
    printFile(srcFile);
	
		// Move src file pointer to beginning
    	rewind(srcFile);
    	
		printf("\n\nDear user please count the dashed line(---) also while counting the lines.");
    	printf("\n\nEnter line number to remove that data: ");
    	scanf("%d", &line);
    
    	// Delete given line from file.
    	deleteLine(srcFile, tempFile, line);


    	/* Close all open files */
    	fclose(srcFile);
    	fclose(tempFile);


    	/* Delete src file and rename temp file as src */
    	remove(path);
    	rename("delete-line.tmp", path);


    	printf("\n\n\nFile contents after removing line No.%d data:\n\n", line);

    	// Open source file and print its contents
    	srcFile = fopen(path, "r");
    	printFile(srcFile);
    	fclose(srcFile);

}
/**
 * Print contents of a file.
 */
void printFile(FILE *fptr)
{
    char ch;

    while((ch = fgetc(fptr)) != EOF)
    {
        putchar(ch);
    }
   
}



/**
 * Function to delete a given line from file.
 */
void deleteLine(FILE *srcFile, FILE *tempFile, const int line)
{
    char buffer[BUFFER_SIZE];
    int count = 1;

    while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)
    {
        /* If current line is not the line user wanted to remove */
        if (line != count)
            fputs(buffer, tempFile);

         count++;
    }
}
void deleteAccount()
{
	FILE *fp;
	int choice=0;
    int delete_status;
    char path[100],order[]="del ";//del for delete file, if change del to rd is delete folder
    system("cls");
	printf("\n\t\t\t\t  * DELETING ACCOUNT *\t\t\ns");
	printf("\n\t\t===============================================\n\n");
    printf("\t\tEnter your Account number here: ");
    fflush(stdin);
    gets( path);
    sprintf(path,"%s.txt",path);
    fp = fopen(path,"r");
    /* Exit if file not opened successfully */
    	if (fp == NULL)
    	{
        	while(fp == NULL)	
   		 	{
   		 		printf("\n\t\tUnable to open file !!!\n");
        		printf("\t\tPlease check you have put the correct account number.\n");
    			printf("\n\n\t\tEnter your Account number here: ");
    			fflush(stdin);
    			gets( path);
				sprintf(path,"%s.txt",path);
				fp = fopen(path,"r");
				fclose(fp);
			}
    	}
    printf("\n\t\tAre you sure you want to delete your Account ?");
    printf("\n\t\tEnter 1 to delete and 0 TO leave.");
    printf("\n\t\tYour choice: ");
    scanf("%d",&choice);
    while(!(choice==1 || choice==0))
    {
    	printf("\n\t\tInvalid Choice !!!\n");
    	printf("\n\t\tEnter your choice again: ");
    	scanf("%d",&choice);
	}
    if(choice==1)
    {
    	strcat(order,path);
    	fp = fopen(path,"r");
    	if(fp != NULL)
		{//Check file whether or not exist
       		fclose(fp);
       		system(order);//Del file
       		printf("\t\tAccount Deletet successfully");
    	}
		else
		{
       		perror(" \t\tERROR");
       		fclose(fp);
    	}
    	printf("\n\n\n\t\t===============================================\n\n\n");
	}
	else if(choice == 0)									//Exit Part
			{
				system("cls");
				printf("\n\n\n");
				printf("\n\t\t===============================================\n\n");
				printf("\n\n\t\t\tThank you for using this app :) \n");	
				printf("\t\t\tPress any key to exit \n\n\n\n");
				printf("\t\t===============================================\n\n\n");
			}
}
