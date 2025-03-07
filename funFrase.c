#include "defFrase.h"
/**
 * @file funFrase.c
 * @brief Archivo de funciones de revisarFrase.c
 * @date 07/marzo/2025
 * @author Mario Ureña García
 */

// Funciones ----------------------------------------------------------------------------
/**
 * @brief Función que cuenta cuantas palabras en la frase tienen consonantes.
 * @date 07/marzo/2025
 * @author Mario Ureña García
 * @param nombreArchivo Nombre del archivo que contiene la frase.
 * @return Cantidad de palabras que tienen consonantes.
 */
int contarConsonantes(char nombreArchivo[])
{
    int consonantes = 0;
    char palabra[50];
    FILE *archivo;

    // Abrir archivo de la frase
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo %s" RESET, nombreArchivo);
        exit(1);
    }
    while (fscanf(archivo, "%s", palabra) != EOF)
    {
        if (palabra[0] == 'a' || palabra[0] == 'e' || palabra[0] == 'i' || palabra[0] == 'o' || palabra[0] == 'u' || palabra[0] == 'A' || palabra[0] == 'E' || palabra[0] == 'I' || palabra[0] == 'O' || palabra[0] == 'U')
        {
            consonantes++;
        }
    }
    fclose(archivo);

    return consonantes;
}

/**
 * @brief Función que cuenta cuantas palabras en la frase tienen vocales.
 * @date 07/marzo/2025
 * @author Mario Ureña García
 * @param nombreArchivo Nombre del archivo que contiene la frase.
 * @return Cantidad de palabras que tienen vocales.
 */
int contarVocales(char nombreArchivo[])
{
    int vocales = 0;
    char palabra[50];
    FILE *archivo;

    // Abrir archivo de la frase
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo %s" RESET, nombreArchivo);
        exit(1);
    }
    while (fscanf(archivo, "%s", palabra) != EOF)
    {
        if (palabra[0] == 'a' || palabra[0] == 'e' || palabra[0] == 'i' || palabra[0] == 'o' || palabra[0] == 'u' || palabra[0] == 'A' || palabra[0] == 'E' || palabra[0] == 'I' || palabra[0] == 'O' || palabra[0] == 'U')
        {
            vocales++;
        }
    }
    fclose(archivo);

    return vocales;
}
/**
 * @brief Función que imprime las palabras que tienen un tamaño menor o igual al ingresado por el usuario en la línea de comandos.
 * @date 07/marzo/2025
 * @author Mario Ureña García
 * @param arregloPalabras Arreglo de palabras que se van a imprimir.
 * @param totalPalabras Cantidad de palabras en el arreglo.
 * @param tamanioPalabra Tamaño de palabra ingresado por el usuario.
 */
void imprimirArreglo(tipoPalabra arregloPalabras[], int totalPalabras, int tamanioPalabra)
{
    printf(YELLOW "\n\n\tImpresión de las palabras en frase.txt que tienen un tamaño de palabra <= %d:\n" RESET, tamanioPalabra);
    for (int i = 0; i < totalPalabras; i++)
    {
        printf("\n%s\t%d", arregloPalabras[i].palabra, arregloPalabras[i].tamanio);
    }
    printf("\n\n");
    return;
}

/**
 * @brief Función que divide una frase en dos archivos de texto: Vocal.txt y Consonante.txt.
 * @date 07/marzo/2025
 * @author Mario Ureña García
 * @param nombreArchivo Nombre del archivo que contiene la frase.
 */
extern void dividirFrase(char nombreArchivo[])
{
    FILE *archivo;
    FILE *vocales;
    FILE *consonantes;
    char palabra[50];
    int totalVocales = 0;
    int totalConsonantes = 0;
    int i;

    // Buscar vocales--------------------------------------------------------------------
    vocales = fopen("Vocal.txt", "w");
    if (vocales == NULL)
    {
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo Vocal.txt" RESET);
        exit(1);
    }

    // Contar cuantas palabras con vocales hay
    totalVocales = contarVocales(nombreArchivo);

    // Abrir archivo de la frase
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        fclose(vocales);
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo %s" RESET, nombreArchivo);
        exit(1);
    }

    //  Leer archivo y buscar vocales
    // Abrir archivo de la frase
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        fclose(vocales);
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo %s" RESET, nombreArchivo);
        exit(1);
    }

    i = 1; // Contador de palabras para evitar imprimir espacio al final

    while (fscanf(archivo, "%s", palabra) != EOF)
    {
        if (palabra[0] == 'a' || palabra[0] == 'e' || palabra[0] == 'i' || palabra[0] == 'o' || palabra[0] == 'u' || palabra[0] == 'A' || palabra[0] == 'E' || palabra[0] == 'I' || palabra[0] == 'O' || palabra[0] == 'U')
        {
            if (i == totalVocales)
            {
                fprintf(vocales, "%s", palabra);
            }
            else
            {
                fprintf(vocales, "%s ", palabra);
            }
            i++;
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

    // Contar cuantas palabras con consonantes hay
    totalConsonantes = contarConsonantes(nombreArchivo);

    // Abrir archivo de la frase
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        fclose(consonantes);
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo %s" RESET, nombreArchivo);
        exit(1);
    }

    i = 1; // Contador de palabras para evitar imprimir espacio al final

    while (fscanf(archivo, "%s", palabra) != EOF)
    {
        if (palabra[0] != 'a' && palabra[0] != 'e' && palabra[0] != 'i' && palabra[0] != 'o' && palabra[0] != 'u' && palabra[0] != 'A' && palabra[0] != 'E' && palabra[0] != 'I' && palabra[0] != 'O' && palabra[0] != 'U')
        {
            if (i == totalConsonantes)
            {
                fprintf(consonantes, "%s", palabra);
            }
            else
            {
                fprintf(consonantes, "%s ", palabra);
            }
            i++;
        }
    }
    fclose(archivo);
    fclose(consonantes);

    return;
}

/**
 * @brief Función que selecciona las palabras que tienen un tamaño menor o igual al ingresado por el usuario en la línea de comandos.
 * @date 07/marzo/2025
 * @author Mario Ureña García
 * @param nombreArchivo Nombre del archivo que contiene la frase.
 * @param tamanioPalabra Tamaño de palabra ingresado por el usuario.
 */
extern void seleccionaPalabras(char nombreArchivo[], int tamanioPalabra)
{
    FILE *archivo;

    int totalPalabras = 0;
    int i = 0;

    char palabra[50];
    tipoPalabra *arregloPalabras;

    // Abrir archivo de la frase
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo %s" RESET, nombreArchivo);
        exit(1);
    }

    // Leer cuantas palabras tienen longitud igual o menor a la ingresada en tamanioPalabra
    while (fscanf(archivo, "%s", palabra) != EOF)
    {
        if (strlen(palabra) <= tamanioPalabra)
        {
            totalPalabras++;
        }
    }
    fclose(archivo);

    // Reservar memoria para el arreglo de palabras
    arregloPalabras = (tipoPalabra *)malloc(totalPalabras * sizeof(tipoPalabra));
    if (arregloPalabras == NULL)
    {
        printf(RED "\n\n\tERROR: No se pudo reservar memoria para el arreglo de palabras\n\n" RESET);
        exit(1);
    }

    // Guardar palabras en el arreglo
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        printf(RED "\n\n\tERROR: No se pudo abrir el archivo %s" RESET, nombreArchivo);
        exit(1);
    }

    while (fscanf(archivo, "%s", palabra) != EOF)
    {
        if (strlen(palabra) <= tamanioPalabra)
        {
            strcpy(arregloPalabras[i].palabra, palabra);
            arregloPalabras[i].tamanio = strlen(palabra);
            i++;
        }
    }
    // Imprimir palabras del arreglo
    imprimirArreglo(arregloPalabras, totalPalabras, tamanioPalabra);
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
