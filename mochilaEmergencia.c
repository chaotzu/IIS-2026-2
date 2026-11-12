#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define ARCHIVO "agenda.txt"

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
} Persona;

typedef struct {
    Persona *contactos; /* Arreglo dinámico de personas */
    int cantidad;
    int capacidad;
} Agenda;

/* Reserva memoria inicial para la agenda usando malloc */
Agenda *agenda_crear(int capacidad_inicial) {
    Agenda *a = malloc(sizeof(Agenda));
    if (a == NULL) return NULL;

    a->contactos = malloc(capacidad_inicial * sizeof(Persona));
    if (a->contactos == NULL) {
        free(a);
        return NULL;
    }

    a->cantidad = 0;
    a->capacidad = capacidad_inicial;
    return a;
}

/* Redimensiona el arreglo dinámico con realloc cuando se llena */
int agenda_agregar(Agenda *a, Persona p) {
    if (a->cantidad == a->capacidad) {
        int nueva_capacidad = a->capacidad * 2;
        Persona *tmp = realloc(a->contactos, nueva_capacidad * sizeof(Persona));
        if (tmp == NULL) return 0; /* No se pudo expandir la memoria */

        a->contactos = tmp;
        a->capacidad = nueva_capacidad;
    }

    a->contactos[a->cantidad] = p;
    a->cantidad++;
    return 1;
}

/* Libera la memoria asignada con malloc y realloc mediante free */
void agenda_destruir(Agenda *a) {
    if (a != NULL) {
        free(a->contactos);
        free(a);
    }
}

/* Carga contactos existentes desde el archivo */
void agenda_cargar(Agenda *a) {
    FILE *f = fopen(ARCHIVO, "r");
    if (f == NULL) return;

    Persona p;
    while (fscanf(f, "%d;%49[^\n]\n", &p.edad, p.nombre) == 2) {
        agenda_agregar(a, p);
    }

    fclose(f);
}

/* Guarda los contactos en el archivo */
void agenda_guardar(const Agenda *a) {
    FILE *f = fopen(ARCHIVO, "w");
    if (f == NULL) {
        printf("Error al abrir archivo para guardar.\n");
        return;
    }

    for (int i = 0; i < a->cantidad; i++) {
        fprintf(f, "%d;%s\n", a->contactos[i].edad, a->contactos[i].nombre);
    }

    fclose(f);
    printf("Agenda guardada correctamente.\n");
}

void accion_listar(const Agenda *a) {
    if (a->cantidad == 0) {
        printf("La agenda esta vacia.\n");
        return;
    }

    for (int i = 0; i < a->cantidad; i++) {
        printf("%d. %s (%d anos)\n", i + 1, a->contactos[i].nombre, a->contactos[i].edad);
    }
}

void accion_agregar(Agenda *a) {
    Persona p;

    printf("Nombre: ");
    getchar(); /* Consume el '\n' pendiente del buffer */
    fgets(p.nombre, MAX_NOMBRE, stdin);
    p.nombre[strcspn(p.nombre, "\n")] = '\0'; /* Elimina el salto de linea */

    printf("Edad: ");
    scanf("%d", &p.edad);

    if (agenda_agregar(a, p)) {
        printf("Contacto agregado exitosamente.\n");
    } else {
        printf("Error: Memoria insuficiente.\n");
    }
}

void accion_buscar(const Agenda *a) {
    char texto[MAX_NOMBRE];

    printf("Buscar nombre: ");
    getchar();
    fgets(texto, MAX_NOMBRE, stdin);
    texto[strcspn(texto, "\n")] = '\0';

    int hallados = 0;
    for (int i = 0; i < a->cantidad; i++) {
        if (strstr(a->contactos[i].nombre, texto) != NULL) {
            printf("%d. %s (%d anos)\n", i + 1, a->contactos[i].nombre, a->contactos[i].edad);
            hallados++;
        }
    }

    if (hallados == 0) printf("Sin coincidencias.\n");
}

void accion_eliminar(Agenda *a) {
    accion_listar(a);
    if (a->cantidad == 0) return;

    int pos;
    printf("Numero a eliminar: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > a->cantidad) {
        printf("Numero invalido.\n");
        return;
    }

    for (int i = pos - 1; i < a->cantidad - 1; i++) {
        a->contactos[i] = a->contactos[i + 1];
    }
    a->cantidad--;
    printf("Contacto eliminado.\n");
}

int main(void) {
    /* Iniciamos con una capacidad pequena de 2 */
    Agenda *agenda = agenda_crear(2);
    if (agenda == NULL) {
        printf("Error al reservar memoria inicial.\n");
        return 1;
    }

    agenda_cargar(agenda);

    int opcion = -1;
    while (opcion != 0) {
        printf("\n1) Listar  2) Agregar  3) Buscar  4) Eliminar  0) Guardar y salir\n> ");
        if (scanf("%d", &opcion) != 1) break;

        switch (opcion) {
            case 1: accion_listar(agenda); break;
            case 2: accion_agregar(agenda); break;
            case 3: accion_buscar(agenda); break;
            case 4: accion_eliminar(agenda); break;
            case 0: agenda_guardar(agenda); break;
            default: printf("Opcion no valida.\n");
        }
    }

    /* Liberacion final de memoria */
    agenda_destruir(agenda);
    return 0;
}
