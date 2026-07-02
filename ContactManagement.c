/*
    Project     : Contact Management System
    Description : A simple command-line contact book that lets you
                   add, view, search, update, and delete contacts.
                   Contacts are stored in a plain text file (data.txt)
                   using comma-separated values.
    Author      : Md. Rony Ahmmed Shah
    GitHub      : github.com/Rony7s

    Note: To keep this beginner-friendly, contact fields (name, phone,
    address) should NOT contain commas, since commas are used to
    separate the fields in the data file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "data.txt"
#define MAX_LINE 300

typedef struct
{
    char name[100];
    char phone[30];
    char address[100];
} Contact;

// Creates data.txt with a header row if it doesn't already exist.
void createFile()
{
    FILE *fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        fp = fopen(FILE_NAME, "w");
        if (fp == NULL)
        {
            printf("Error: could not create %s\n", FILE_NAME);
            return;
        }
        fprintf(fp, "Name,Phone,Address\n");
    }

    fclose(fp);
}

// Reads one line of user input safely and removes the trailing newline.
void readLine(char *buffer, int size)
{
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void addContact()
{
    Contact c;

    printf("Name    : ");
    readLine(c.name, sizeof(c.name));

    printf("Phone   : ");
    readLine(c.phone, sizeof(c.phone));

    printf("Address : ");
    readLine(c.address, sizeof(c.address));

    FILE *fp = fopen(FILE_NAME, "a");
    if (fp == NULL)
    {
        printf("Error: could not open %s\n", FILE_NAME);
        return;
    }

    fprintf(fp, "%s,%s,%s\n", c.name, c.phone, c.address);
    fclose(fp);

    printf("\nContact Added Successfully!\n\n");
}

void showContacts()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf("Error: could not open %s\n", FILE_NAME);
        return;
    }

    char line[MAX_LINE];
    fgets(line, sizeof(line), fp); // skip header row

    printf("\n========== CONTACT LIST ==========\n\n");

    int found = 0;

    while (fgets(line, sizeof(line), fp))
    {
        Contact c;
        sscanf(line, "%99[^,],%29[^,],%99[^\n]", c.name, c.phone, c.address);

        printf("Name    : %s\n", c.name);
        printf("Phone   : %s\n", c.phone);
        printf("Address : %s\n", c.address);
        printf("-------------------------------\n");

        found = 1;
    }

    if (!found)
        printf("No contacts found.\n");

    printf("\n");
    fclose(fp);
}

void searchContact()
{
    char phone[30];
    printf("Enter Phone Number: ");
    readLine(phone, sizeof(phone));

    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf("Error: could not open %s\n", FILE_NAME);
        return;
    }

    char line[MAX_LINE];
    fgets(line, sizeof(line), fp); // skip header row

    while (fgets(line, sizeof(line), fp))
    {
        Contact c;
        sscanf(line, "%99[^,],%29[^,],%99[^\n]", c.name, c.phone, c.address);

        if (strcmp(c.phone, phone) == 0)
        {
            printf("\nContact Found\n");
            printf("-----------------\n");
            printf("Name    : %s\n", c.name);
            printf("Phone   : %s\n", c.phone);
            printf("Address : %s\n\n", c.address);

            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("\nContact Not Found!\n\n");
}

void updateContact()
{
    char phone[30];
    printf("Enter Phone Number to Update: ");
    readLine(phone, sizeof(phone));

    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (fp == NULL || temp == NULL)
    {
        printf("Error: could not open file.\n");
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        return;
    }

    char line[MAX_LINE];
    int found = 0;

    fgets(line, sizeof(line), fp);
    fputs(line, temp); // keep header row

    while (fgets(line, sizeof(line), fp))
    {
        Contact c;
        sscanf(line, "%99[^,],%29[^,],%99[^\n]", c.name, c.phone, c.address);

        if (strcmp(c.phone, phone) == 0)
        {
            found = 1;

            printf("\nEnter New Information\n");

            printf("Name    : ");
            readLine(c.name, sizeof(c.name));

            printf("Phone   : ");
            readLine(c.phone, sizeof(c.phone));

            printf("Address : ");
            readLine(c.address, sizeof(c.address));
        }

        fprintf(temp, "%s,%s,%s\n", c.name, c.phone, c.address);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("\nContact Updated Successfully!\n\n");
    else
        printf("\nContact Not Found!\n\n");
}

void deleteContact()
{
    char phone[30];
    printf("Enter Phone Number to Delete: ");
    readLine(phone, sizeof(phone));

    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (fp == NULL || temp == NULL)
    {
        printf("Error: could not open file.\n");
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        return;
    }

    char line[MAX_LINE];
    int found = 0;

    fgets(line, sizeof(line), fp);
    fputs(line, temp); // keep header row

    while (fgets(line, sizeof(line), fp))
    {
        Contact c;
        sscanf(line, "%99[^,],%29[^,],%99[^\n]", c.name, c.phone, c.address);

        if (strcmp(c.phone, phone) == 0)
        {
            found = 1;
            continue; // skip writing this contact = delete it
        }

        fprintf(temp, "%s,%s,%s\n", c.name, c.phone, c.address);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("\nContact Deleted Successfully!\n\n");
    else
        printf("\nContact Not Found!\n\n");
}

void showMenu()
{
    printf("========== CONTACT MANAGEMENT ==========\n");
    printf("1. Add Contact\n");
    printf("2. Show All Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Update Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Exit\n");
    printf("\nEnter Choice: ");
}

int main()
{
    createFile();

    int choice;

    while (1)
    {
        showMenu();
        scanf("%d", &choice);
        getchar(); // clear the leftover newline left behind by scanf

        switch (choice)
        {
        case 1: addContact(); break;
        case 2: showContacts(); break;
        case 3: searchContact(); break;
        case 4: updateContact(); break;
        case 5: deleteContact(); break;
        case 6:
            printf("\nThank You!\n");
            return 0;
        default:
            printf("\nInvalid Choice!\n\n");
        }
    }

    return 0;
}
