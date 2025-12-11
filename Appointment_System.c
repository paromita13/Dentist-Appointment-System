#include <stdio.h>
#include <string.h>
#define USERNAME "Paromita"
#define PASSWORD "1234"

typedef struct
{
    char name[50];
    char date[20];
    char time[10];
    char doctor[200];
} Appointment;

Appointment list[100];
int count = 0;

char *doctors[] =
{
    "Dr. Rahman - General Dentist (Checkups, Scaling, Fillings) (10am - 10pm)",
    "Dr. Karim - Oral Surgeon (Extraction, Surgery, Implants) (3pm - 8pm)"
};

void swap(Appointment *a, Appointment *b)
{
    Appointment temp = *a;
    *a = *b;
    *b = temp;
}

void saveToFile()
{
    FILE *fp = fopen("clinic_data.txt", "w");
    if (fp == NULL)
    {
        printf("Error saving to file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s|%s|%s|%s\n",
                list[i].name, list[i].date, list[i].time, list[i].doctor);
    }
    fclose(fp);
}

void loadFromFile()
{
    FILE *fp = fopen("clinic_data.txt", "r");
    count = 0;

    if (fp == NULL)
    {
        return;
    }

    while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^\n]\n",
                  list[count].name, list[count].date,
                  list[count].time, list[count].doctor) == 4)
    {
        count++;
        if (count >= 100) break;
    }

    fclose(fp);
}

int isConflict(char date[], char time[], int skipIndex)
{
    for (int i = 0; i < count; i++)
    {
        if (i == skipIndex) continue;

        if (strcmp(list[i].date, date) == 0 &&
            strcmp(list[i].time, time) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int addAppointment(Appointment arr[], int index)
{
    printf("Enter patient name: ");
    scanf(" %[^\n]", arr[index].name);

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", arr[index].date);

    printf("\nSelect doctor:\n");
    printf("1. %s\n", doctors[0]);
    printf("2. %s\n", doctors[1]);

    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 2)
    {
        printf("Invalid choice.\n");
        return 0;
    }

    strcpy(arr[index].doctor, doctors[choice - 1]);

    printf("Enter time (HH:MM): ");
    scanf("%s", arr[index].time);

    if (isConflict(arr[index].date, arr[index].time, -1))
    {
        printf("\nTime slot already booked.\n");
        return 0;
    }

    printf("\nAppointment added!\n");
    return 1;
}

void viewAppointments()
{
    if (count == 0)
    {
        printf("No appointments.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("\nAppointment %d\n", i + 1);
        printf("Name: %s\n", list[i].name);
        printf("Date: %s\n", list[i].date);
        printf("Time: %s\n", list[i].time);
        printf("Doctor: %s\n", list[i].doctor);
    }
}

int searchAppointment(int *index)
{
    char target[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", target);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(list[i].name, target) == 0)
        {
            printf("\nAppointment Found\n");
            printf("Name: %s\n", list[i].name);
            printf("Date: %s\n", list[i].date);
            printf("Time: %s\n", list[i].time);
            printf("Doctor: %s\n", list[i].doctor);
            *index = i;
            return 1;
        }
    }

    printf("\nAppointment not found.\n");
    *index = -1;
    return 0;
}

void sortAppointments()
{
    Appointment temp;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(list[i].date, list[j].date) > 0)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    saveToFile();
    printf("\nSorted by date.\n");
}

void editAppointment()
{
    int index = 0;
    if (!searchAppointment(&index))
    {
        return;
    }

    Appointment temp;

    printf("\nEnter new details:\n");
    printf("Enter patient name: ");
    scanf(" %[^\n]", temp.name);

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", temp.date);

    printf("\nSelect doctor:\n");
    printf("1. %s\n", doctors[0]);
    printf("2. %s\n", doctors[1]);

    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 2)
    {
        printf("Invalid choice.\n");
        return;
    }

    strcpy(temp.doctor, doctors[choice - 1]);

    printf("Enter time (HH:MM): ");
    scanf("%s", temp.time);

    if (isConflict(temp.date, temp.time, index))
    {
        printf("\nTime slot already booked.\n");
        return;
    }

    strcpy(list[index].name, temp.name);
    strcpy(list[index].date, temp.date);
    strcpy(list[index].time, temp.time);
    strcpy(list[index].doctor, temp.doctor);

    saveToFile();
    printf("Appointment updated.\n");
}

void deleteAppointment()
{
    int index = 0;
    if (!searchAppointment(&index))
    {
        return;
    }

    printf("Delete this appointment? (Y/N): ");
    char confirm;
    scanf(" %c", &confirm);

    if (confirm != 'Y' && confirm != 'y')
    {
        printf("Deletion cancelled.\n");
        return;
    }

    for (int i = index; i < count - 1; i++)
    {
        list[i] = list[i + 1];
    }
    count--;

    saveToFile();
    printf("Appointment deleted.\n");
}

int main()
{
    loadFromFile();

    printf("NSU Dental Clinic Appointmet Login !\n");
    printf("Name: ");
    char name[50];
    scanf("%s", name);
    printf("Password: ");
    char password[12];
    scanf("%s", password);

    if (strcmp(name, USERNAME) != 0 || strcmp(password, PASSWORD) != 0)
    {
        printf("Login failed.\n");
        return 0;
    }

    printf("Login successful!\n");
    printf("Welcome to NSU Dental Clinic\n");

    int temp;
    int choice;

    while (1)
    {
        printf("\n------------------------------\n");
        printf("DENTAL APPOINTMENT SYSTEM\n");
        printf("------------------------------\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Search Appointment\n");
        printf("4. Sort by Date\n");
        printf("5. Edit Appointment\n");
        printf("6. Delete Appointment\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count >= 100)
            {
                printf("Appointment list full.\n");
                break;
            }

            if (addAppointment(list, count))
            {
                printf("Save? (Y/N): ");
                char save;
                scanf(" %c", &save);

                if (save == 'Y' || save == 'y')
                {
                    count++;
                    saveToFile();
                    printf("Saved.\n");
                }
                else
                {
                    printf("Not saved.\n");
                }
            }
            break;

        case 2:
            viewAppointments();
            break;

        case 3:
            searchAppointment(&temp);
            break;

        case 4:
            sortAppointments();
            break;

        case 5:
            editAppointment();
            break;

        case 6:
            deleteAppointment();
            break;

        case 7:
            printf("Goodbye.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}
