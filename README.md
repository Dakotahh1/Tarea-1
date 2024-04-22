# Sistema de Gestión Hospitalaria

Este es un sistema de gestión hospitalaria desarrollado en C. Permite registrar pacientes, asignarles prioridades, mostrar la lista de espera, atender al siguiente paciente y mostrar pacientes por prioridad.

## ¿Cómo utilizarlo?

Para poder utilizar este programa debe seguir los siguientes pasos primero
1. Debe iniciar sesión en replit, si no tiene una sesión creada, deberá crearla.
2. Creara un nuevo repl y seleccionara la opción para importar desde github.
3. Copiar y pegar el link del repositorio https://github.com/Dakotahh1/Tarea-1.git
4. Se creara una copia del repositorio, para poder ejecutar el programa
5. Para poder usarlo deberá compilarlo en la terminal (Shell) con el siguiente comando:
```
gcc tdas/*.c main.c -Wno-unused-result -o tarea1
```
6. Una vez compilado, podrá ejecutar el programa en la terminal con el siguiente comando:
```
./tarea1
```
## Funciones del programa (RESPETAR EL FORMATO EN EL QUE SE PIDEN LOS DATOS)

El programa cuenta con un menú con 6 opciones, usted deberá ingresar un numero del 1 al 6 dependiendo de la función que desee utilizar.

- 1 : "Registrar Paciente". Debe ingresar el nombre completo del paciente a registrar, luego su edad (solo numeros), el síntoma y la hora de ingreso (Para la hora deberá ingresar la hora y minutos de ingreso en ese orden, en el siguiente rango de números: Hora: 00-23, Minutos: 00-59). El programa asignara automáticamente el nivel de prioridad "Bajo" para el paciente registrado, en lo posible tratar de no colocar un espacio al final de ingresar un nombre, sintoma o prioridad, ya que la información se guardara con ese espacio.

```c
"Opción 1: Registrar Paciente"
//ingrese el nombre del paciente
Javiera Martínez Pozo Andrea

//Ingrese la edad del paciente
19 

//Ingrese el síntoma del paciente
Hemorragia nasal

/Ingrese la hora de ingreso del paciente
16 35
"Paciente registrado con éxito!!"

```

- 2 : "Asignar Prioridad". Debe ingresar el nombre completo del paciente a buscar, si el nombre coincide con el registro, le mostrara el nombre del paciente, sino, le dirá que el nombre del paciente ingresado no se encontró y tendrá que volver a ingresar el nombre que se encuentre dentro del registro, luego le solicitara ingresar el nivel de prioridad para el paciente (Alto/Medio/Bajo), una vez ingresado, se le asignara esa prioridad al paciente ingresado.

```c
"Opción 2: Asignar Prioridad"
//Ingrese el nombre completo del paciente
Pedro Sanchez Gomez Antonio
"No se encontró al paciente con el nombre ingresado"
....
//Ingrese el nombre completo del paciente
Javiera Martínez Pozo Andrea
"Paciente Javiera Martínez Pozo Andrea encontrada con éxito!"
//Ingrese la nueva prioridad (Alta/Media/Baja)
Alta
"Prioridad Alta asignada con éxito!"
```

- 3 : "Mostrar lista de espera". El programa le mostrara la lista de pacientes esperando a ser atendidos en orden de prioridad (Alto a Bajo) y si son iguales, por hora de ingreso.

```c
"Opción 3: Mostrar lista de espera"

//Pacientes en lista de espera:
"Nombre: Javiera Martínez Pozo Andrea"
"Edad: 19 años"
"Síntoma: Hemorragia Nasal"
"Prioridad: Alta"
"Hora de ingreso: 16:35"
------------------------
```

- 4 : "Atender al siguiente paciente". El programa le mostrara el paciente a atender, según su prioridad y hora de ingreso, una vez mostrado los datos, el paciente se mostrara como atendido y se borrara del registro, si no hay pacientes en la lista de espera, el programa mostrara que no hay pacientes en lista de espera.
```c
"Opción 4: Atender al siguiente paciente"
//Paciente atendido:

"Nombre: Javiera Martínez Pozo Andrea"
"Edad: 19 años"
"Síntoma: Hemorragia Nasal"
"Prioridad: Alta"
"Hora de ingreso: 16:35"
......
"Opción 4: Atender al siguiente paciente"
"No hay pacientes en espera."
```

- 5 "Mostrar pacientes por prioridad". Debe ingresar una prioridad (Alta/Media/Baja), y el programa mostrara los pacientes según la prioridad seleccionada

```c
"Ingrese la prioridad deseada"
Alta
"Pacientes con prioridad Alta"
//Registro de pacientes con prioridad Alta....
```

## Problemas conocidos y cosas a mejorar

Se debe ingresar los datos en el formato solicitado, si no, el programa podría fallar en algunas funciones, como en la función "Registrar paciente".

Se puede mejorar la gestión de memoria.



## Contribuciones

Vicente Palma Lucero Antonio

Desarrollador del programa completo.
