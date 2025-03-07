#include "defFrase.h"
/**
 * @file funFrase.c
 * @brief Archivo de funciones de revisarFrase.c
 * @date 07/marzo/2025
 * @author Mario Ureña García
 */

// Funciones ----------------------------------------------------------------------------

void dividirFrase(char nombreArchivo[])
{
    FILE *archivo;
    FILE *vocales;
    FILE *consonantes;
    char palabra[50];

    // Buscar vocales--------------------------------------------------------------------
    vocales = fopen("Vocal.txt", "w");
    if (vocales == NULL)
    {
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo Vocal.txt" RESET);
        exit(1);
    }
    // Abrir archivo de la frase
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        fclose(vocales);
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo %s" RESET, nombreArchivo);
        exit(1);
    }
    // Leer archivo y buscar vocales
    while (fscanf(archivo, "%s", palabra) != EOF)
    {
        if (palabra[0] == 'a' || palabra[0] == 'e' || palabra[0] == 'i' || palabra[0] == 'o' || palabra[0] == 'u' || palabra[0] == 'A' || palabra[0] == 'E' || palabra[0] == 'I' || palabra[0] == 'O' || palabra[0] == 'U')
        {
            fprintf(vocales, "%s ", palabra);
        }
    }
    fclose(archivo);
    fclose(vocales);

    // Buscar consonantes----------------------------------------------------------------
    consonantes = fopen("Consonante.txt", "w");
    if (consonantes == NULL)
    {
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo Consonante.txt" RESET);
        exit(1);
    }
    // Abrir archivo de la frase
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        fclose(consonantes);
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo %s" RESET, nombreArchivo);
        exit(1);
    }
    // Leer archivo y buscar consonantes
    while (fscanf(archivo, "%s", palabra) != EOF)
    {
        if (palabra[0] != 'a' && palabra[0] != 'e' && palabra[0] != 'i' && palabra[0] != 'o' && palabra[0] != 'u' && palabra[0] != 'A' && palabra[0] != 'E' && palabra[0] != 'I' && palabra[0] != 'O' && palabra[0] != 'U')
        {
            fprintf(consonantes, "%s ", palabra);
        }
    }
    fclose(archivo);
    fclose(consonantes);

    return;
}

/**
 * @brief
 * @date
 * @author
 * @param
 * @return
 * @Ejemplo
 */
