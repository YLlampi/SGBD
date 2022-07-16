# Sistema Gestor de Base de Datos

# Instrucciones de Uso - Compilacion

g++ --version = 9.4.0

version de c++:
c++11

# Pasos:

1. Compilar archivo: g++ -o eject main.cpp -std=c++11
2. Ejecutar archivo: time ./eject

3. Agregamos los campos que deseamos, ejemplo(nombre, apellido, edad) nota: campo id es por defecto autoincrementable
4. Insertamos valores (seleccionar opcion 1 del MENU) 
5. Llamada al Buffer Manager (opcion 4 del MENU)

# Explicacion

Como estructura de datos del Sistema de Base de Datos utilizamos una tabla HASH
En ahi se va almacenando todos los registros que ingresamos, una vez ingresados todos los
registros que deseamos, llamamos al Buffer Manager para que haga los reemplazos correspondientes
usamos el metodo CLOCK.

FRAMES utilizados: por defecto 3
On-Disk File: Escogemos valores aleatorios de la tabla HASH(valores previamente ingresados)
