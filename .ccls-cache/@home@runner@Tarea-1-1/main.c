#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nombre[500];
  int edad;
  char sintoma[500];
  int horaIngreso;
  int minutosIngreso;
  char prioridad[500];
} Paciente;

int lower_than(void *p1, void *p2) {
  Paciente *paciente1 = (Paciente *)p1;
  Paciente *paciente2 = (Paciente *)p2;

  // Comparación por prioridad
  if (strcmp(paciente1->prioridad, paciente2->prioridad) < 0) {
    return -1;
  } else if (strcmp(paciente1->prioridad, paciente2->prioridad) > 0) {
    return 1;
  } else { // Si la prioridad es la misma, comparar por hora de registro
    if (paciente1->horaIngreso < paciente2->horaIngreso) {
      return -1;
    } else if (paciente1->horaIngreso > paciente2->horaIngreso) {
      return 1;
    } else {
      // Si la hora de registro es la misma, comparar por minutos de registro
      if (paciente1->minutosIngreso < paciente2->minutosIngreso) {
        return -1;
      } else if (paciente1->minutosIngreso > paciente2->minutosIngreso) {
        return 1;
      } else {
        return 0; // Los pacientes son iguales
      }
    }
  }
}
// Función para limpiar la pantalla
void limpiarPantalla() { system("clear"); }

void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Gestión Hospitalaria");
  puts("========================================");

  puts("1) Registrar paciente");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("6) Salir");
}

void registrar_paciente(List *pacientes) {
  Paciente *pacienteRegistrado = malloc(sizeof(Paciente));

  if (pacienteRegistrado == NULL) {
    printf("Error al asignar memoria para el paciente.\n");
    exit(EXIT_FAILURE);
  }

  printf("Ingrese el nombre completo del paciente: ");

  scanf("%[^\n]s", pacienteRegistrado->nombre);
  getchar();

  printf("Ingrese la edad del paciente: ");
  scanf("%d", &pacienteRegistrado->edad);
  getchar();

  printf("Ingrese el síntoma del paciente: ");
  scanf("%[^\n]s", pacienteRegistrado->sintoma);
  getchar();

  printf("Ingrese la hora y minutos de ingreso del paciente: ");
  scanf("%d %d", &pacienteRegistrado->horaIngreso,
        &pacienteRegistrado->minutosIngreso);
  getchar();

  printf("%s has sido ingresado con exito\n", pacienteRegistrado->nombre);

  strcpy(pacienteRegistrado->prioridad, "Baja");
  list_pushBack(pacientes, pacienteRegistrado);
}

void asignar_prioridad(List *pacientes) {
  char nombre[500];
  printf("Ingrese el nombre completo del paciente: ");
  scanf("%[^\n]s", nombre);

  Paciente *paciente_encontrado = NULL;
  list_first(pacientes);
  Paciente *paciente_actual = (Paciente *)list_first(pacientes);
  while (paciente_actual != NULL) {
    if (strcmp(paciente_actual->nombre, nombre) == 0) {
      paciente_encontrado = paciente_actual;
      list_popCurrent(pacientes);
      break;
    }
    paciente_actual = (Paciente *)list_next(pacientes);
  }

  if (paciente_encontrado == NULL) {
    printf("No se encontró al paciente con el nombre ingresado.\n");
    return;
  }

  printf("Paciente %s encontrado con exito!\n", paciente_encontrado->nombre);
  printf("Ingrese la nueva prioridad (Alta/Media/Baja): ");
  scanf("%s", paciente_encontrado->prioridad);
  getchar();
  printf("Prioridad %s asignada con exito!\n", paciente_encontrado->prioridad);

  list_sortedInsert(pacientes, paciente_encontrado, lower_than);
}

void mostrar_lista_pacientes(List *pacientes) {
  printf("Pacientes en espera: \n");
  list_first(pacientes);
  Paciente *paciente_actual = (Paciente *)list_first(pacientes);
  while (paciente_actual != NULL) {
    printf("Nombre: %s\n", paciente_actual->nombre);
    printf("Edad: %d\n", paciente_actual->edad);
    printf("Síntoma: %s\n", paciente_actual->sintoma);
    printf("Prioridad: %s\n", paciente_actual->prioridad);
    printf("Hora de ingreso: %d:%d\n", paciente_actual->horaIngreso,
           paciente_actual->minutosIngreso);
    printf("------------------------------\n");
    paciente_actual = (Paciente *)list_next(pacientes);
  }
}

void atender_siguiente_paciente(List *pacientes) {
  // Verificar si hay pacientes en espera
  if (pacientes == NULL) {
    printf("No hay pacientes en espera.\n");
    return;
  }

  // Obtener el próximo paciente a ser atendido (el primero de la lista)
  Paciente *paciente_siguiente = (Paciente *)list_popFront(pacientes);

  // Mostrar los datos del paciente atendido
  printf("Paciente atendido:\n");
  printf("Nombre: %s\n", paciente_siguiente->nombre);
  printf("Edad: %d\n", paciente_siguiente->edad);
  printf("Síntoma: %s\n", paciente_siguiente->sintoma);
  printf("Prioridad: %s\n", paciente_siguiente->prioridad);
  printf("Hora de ingreso: %d:%d\n", paciente_siguiente->horaIngreso, paciente_siguiente->minutosIngreso);

  // Liberar la memoria del paciente atendido
  free(paciente_siguiente);
}

void mostrar_pacientes_por_prioridad(List *pacientes) {
  char prioridad_deseada[500];
  printf("Ingrese la prioridad deseada (Alta/Media/Baja): \n");
  scanf(" %[^\n]s", prioridad_deseada);
  printf("Pacientes con prioridad %s:\n", prioridad_deseada);
  list_first(pacientes);
  Paciente *paciente_actual = (Paciente *)list_first(pacientes);
  while (paciente_actual != NULL) {
    if (strcmp(paciente_actual->prioridad, prioridad_deseada) == 0) {
      printf("Nombre: %s\n", paciente_actual->nombre);
      printf("Edad: %d\n", paciente_actual->edad);
      printf("Síntoma: %s\n", paciente_actual->sintoma);
      printf("Prioridad: %s\n", paciente_actual->prioridad);
      printf("Hora de ingreso: %d:%d\n", paciente_actual->horaIngreso, paciente_actual->minutosIngreso);
      printf("------------------------------\n");
    }
    paciente_actual = (Paciente *)list_next(pacientes);
  }
}

int main() {
  char opcion;
  List *pacientes =
      list_create(); // puedes usar una lista para gestionar los pacientes

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior
    getchar();

    switch (opcion) {
    case '1':
      registrar_paciente(pacientes);
      break;
    case '2':
      asignar_prioridad(pacientes);
      break;
    case '3':
      mostrar_lista_pacientes(pacientes);
      break;
    case '4':
      atender_siguiente_paciente(pacientes);
      break;
    case '5':
      mostrar_pacientes_por_prioridad(pacientes);
      break;
    case '6':
      puts("Saliendo del sistema de gestión hospitalaria...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  list_clean(pacientes);

  return 0;
}
