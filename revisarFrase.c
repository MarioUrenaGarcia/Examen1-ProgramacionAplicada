/**
 *
 * @file revisarFrase.c
 * @brief Programa que analiza una frase de texto.
 * @details Haga un programa que analiza una frase de texto y obtenga datos de las palabras que la
 *          construyen. Utilice la línea de comandos para ingresar datos del archivo y opciones de ejecución.
 *          A) Haga un módulo/función dividirFrase que separa las palabras de la frase y las guatde en dos archivos.
 *             Se tiene una frase escrita en un archivo de texto, la frase tiene n palabras y está en el archivo
 *             "frases.txt". Separe la frase en dos archivos de texto: con Vocal.txt y con Consonante.txt.
 *             En Vocal.txt deberán estar las palabras que empiezan con vocal y en Consonante.txt las palabras
 *             que empiezan con consonante.
 *          B) Haga un módulo/función seleccionarPalabras que revise la frase y seleccione las palabras que sean iguales
 *             o menores al tamaño de la palabra ingresado por línea de comando. Recorra el arreglo e imprima en pantalla
 *             la información contenida en cada indice para comprobar que el arreglo fue creado correctamente.
 * @date 07/marzo/2025
 * @author Mario Ureña García
 * @lineaComandos $./revisarFrase.exe <nombre del archivo> <tamaño de la palabra>
 */

#include "defFrase.h"

// Declaración de funciones --------------------------------------------------------------
void dividirFrase(char nombreArchivo[]);
void seleccionaPalabras(char nombreArchivo[], int tamanioPalabra);
void imprimirArchivo(char nombreArchivo[]);
// Main ---------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    // Inicio Personalizado Alfa-----------------------------------------------------------
    printf("Presione ENTER para continuar\n");
    getchar();
    system("clear");
    printf("\n\n\tEste código fue creado por Mario Ureña García\n\n");
    //-------------------------------------------------------------------------------------
    // Variables
    int tamanioPalabra;
    // Procesos
    // Verificar que se ingresaron los argumentos necesarios
    if (argc != 3)
    {
        printf(RED "\n\n\tERROR: Número de Argumentos Incorrecto" RESET);
        printf("\n\tEjemplo de ejecución: $./revisarFrase.exe <nombre del archivo> <tamaño de la palabra>\n\n");
        return 1;
    }

    // Dividir frase
    dividirFrase(argv[1]);
    printf(GREEN "\n\n\tFrase dividida en Vocales.txt y Consonante.txt\n\n" RESET);
    imprimirArchivo("Vocal.txt");
    imprimirArchivo("Consonante.txt");
    // Seleccionar palabras
    if (sscanf(argv[2], "%d", &tamanioPalabra) != 1)
    {
        printf(RED "\n\n\tERROR: El tamaño de la palabra debe ser un número entero" RESET);
        return 1;
    }
    seleccionaPalabras(argv[1], tamanioPalabra);

    // FINALIZACIÓN DEL PROGRAMA
    printf("\n\n\tPrograma Finalizado con " GREEN "ÉXITO\n\n" RESET);
    return 0;
}