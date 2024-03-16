#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct
{
    char first_name[50];
    char last_name[50];
    char phone_number[20];
} Contact;

void addContact(Contact contacts[], int *numContacts)
{
    if (*numContacts >= MAX_CONTACTS)
    {
        printf("Ksiazka adresowa jest pelna.\n");
        return;
    }

    Contact newContact;
    printf("Podaj imie: ");
    scanf("%s", newContact.first_name);
    printf("Podaj nazwisko: ");
    scanf("%s", newContact.last_name);
    printf("Podaj numer telefonu: ");
    scanf("%s", newContact.phone_number);

    contacts[*numContacts] = newContact;
    (*numContacts)++;

    printf("Kontakt zostal dodany.\n");
}

void searchContact(Contact contacts[], int numContacts, char *last_name)
{
    int found = 0;

    for (int i = 0; i < numContacts; i++)
    {
        if (strcmp(contacts[i].last_name, last_name) == 0)
        {
            printf("Znaleziono kontakt:\n");
            printf("Imie: %s\n", contacts[i].first_name);
            printf("Nazwisko: %s\n", contacts[i].last_name);
            printf("Numer telefonu: %s\n", contacts[i].phone_number);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Nie znaleziono kontaktu o podanym nazwisku.\n");
    }
}

void deleteContact(Contact contacts[], int *numContacts, char *last_name)
{
    int found = 0;

    for (int i = 0; i < *numContacts; i++)
    {
        if (strcmp(contacts[i].last_name, last_name) == 0)
        {
            for (int j = i; j < *numContacts - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }
            (*numContacts)--;
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("Kontakt zostal usuniety.\n");
    }
    else
    {
        printf("Nie znaleziono kontaktu o podanym nazwisku.\n");
    }
}

void displayContacts(Contact contacts[], int numContacts)
{
    if (numContacts == 0)
    {
        printf("Ksiazka adresowa jest pusta.\n");
        return;
    }

    printf("Ksiazka adresowa:\n");
    for (int i = 0; i < numContacts; i++)
    {
        printf("Kontakt %d:\n", i + 1);
        printf("Imie: %s\n", contacts[i].first_name);
        printf("Nazwisko: %s\n", contacts[i].last_name);
        printf("Numer telefonu: %s\n", contacts[i].phone_number);
    }
}

int main()
{
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;
    char last_name[50];

    do
    {
        printf("\nMenu:\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt\n");
        printf("3. Usun kontakt\n");
        printf("4. Wyswietl wszystkie kontakty\n");
        printf("0. Wyjdz\n");
        printf("Wybierz opcje: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact(contacts, &numContacts);
            break;
        case 2:
            printf("Podaj nazwisko kontaktu do wyszukania: ");
            scanf("%s", last_name);
            searchContact(contacts, numContacts, last_name);
            break;
        case 3:
            printf("Podaj nazwisko kontaktu do usuniecia: ");
            scanf("%s", last_name);
            deleteContact(contacts, &numContacts, last_name);
            break;
        case 4:
            displayContacts(contacts, numContacts);
            break;
        case 0:
            printf("Koniec programu.\n");
            break;
        default:
            printf("Nieprawidlowa opcja. Wybierz ponownie.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}