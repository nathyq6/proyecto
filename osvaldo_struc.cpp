#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    int id;
    char name[50];
    char phone[15];
} Contact;

void createContact(Contact contacts[], int *count, int id, const char *name, const char *phone) {
    if (*count < MAX_CONTACTS) {
        contacts[*count].id = id;
        strcpy(contacts[*count].name, name);
        strcpy(contacts[*count].phone, phone);
        (*count)++;
    } else {
        printf("No se pueden añadir más contactos. La libreta de direcciones está llena.\n");
    }
}

void readContacts(const Contact contacts[], int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Nombre: %s, Teléfono: %s\n", contacts[i].id, contacts[i].name, contacts[i].phone);
    }
}

void updateContact(Contact contacts[], int count, int id, const char *newName, const char *newPhone) {
    for (int i = 0; i < count; i++) {
        if (contacts[i].id == id) {
            strcpy(contacts[i].name, newName);
            strcpy(contacts[i].phone, newPhone);
            printf("Contacto actualizado.\n");
            return;
        }
    }
    printf("Contacto con ID %d no encontrado.\n", id);
}

void deleteContact(Contact contacts[], int *count, int id) {
    for (int i = 0; i < *count; i++) {
        if (contacts[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contacto borrado.\n");
            return;
        }
    }
    printf("Contacto con ID %d no encontrado.\n", id);
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;

    // Crear contactos
    createContact(contacts, &count, 1, "Juan Perez", "123456789");
    createContact(contacts, &count, 2, "Maria Lopez", "987654321");

    // Leer contactos
    printf("Lista de contactos:\n");
    readContacts(contacts, count);

    // Actualizar un contacto
    updateContact(contacts, count, 1, "Juan Pérez García", "1234567890");
    printf("Lista de contactos después de la actualización:\n");
    readContacts(contacts, count);

    // Borrar un contacto
    deleteContact(contacts, &count, 2);
    printf("Lista de contactos después de borrar:\n");
    readContacts(contacts, count);

    return 0;
}
