/**
 * @file defFrase.h
 * @brief Header File de revisarFrase.c
 * @date 07/marzo/2025
 * @author Mario Ureña García
 */

// Bibliotecas --------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definiciones -------------------------------------------------------------------------
#define RED "\x1b[31m"
#define WHITE "\x1B[37m"
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"
#define CYAN "\x1b[36m"

// Declaración de estructuras -------------------------------------------------------------
struct palabra
{
    char palabra[50];
    int tamanio;
};
typedef struct palabra tipoPalabra;