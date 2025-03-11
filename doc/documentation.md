# Documentación del Programa de Multiplicación en Campos de Galois

## Descripción General

Este programa realiza la multiplicación de dos bytes en campos de Galois específicos para los algoritmos AES y SNOW 3G. El usuario ingresa dos bytes y el algoritmo a utilizar, y el programa muestra el resultado de la multiplicación en formato binario.

## Funciones

### `uint8_t multiplyAES(uint8_t a, uint8_t b)`

Realiza la multiplicación de dos bytes en el campo de Galois utilizado en AES.

- **Parámetros**:
  - `a`: Primer byte.
  - `b`: Segundo byte.
- **Retorno**: Resultado de la multiplicación en AES.

### `uint8_t multiplySNOW3G(uint8_t a, uint8_t b)`

Realiza la multiplicación de dos bytes en el campo de Galois utilizado en SNOW 3G.

- **Parámetros**:
  - `a`: Primer byte.
  - `b`: Segundo byte.
- **Retorno**: Resultado de la multiplicación en SNOW 3G.

## Función Principal

### `int main()`

Función principal del programa.

- **Retorno**:
  - `0` si el programa termina correctamente.
  - `1` si el programa termina con errores.

### Flujo del Programa

1. Solicita al usuario que ingrese el primer byte en decimal.
2. Solicita al usuario que ingrese el segundo byte en decimal.
3. Solicita al usuario que ingrese el algoritmo a utilizar (`AES` o `SNOW3G`).
4. Convierte los enteros ingresados a `uint8_t`.
5. Selecciona la función de multiplicación adecuada según el algoritmo ingresado.
6. Muestra los bytes ingresados, el polinomio irreducible utilizado y el resultado de la multiplicación en formato binario.

## Ejemplo de Uso

```sh
Ingrese el primer byte en decimal: 87
Ingrese el segundo byte en decimal: 131
Ingrese el algoritmo (AES o SNOW3G): AES
Primer byte: 01010111
Segundo byte: 10000011
Byte Algoritmo: 00011011
Multiplicación: 11000001