#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 4

typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;



float aplicarAumento(float precio);
int reemplazarCaracteres(char cadena[], char caracter1, char caracter2);
int ordenarVacunas(eVacuna aVacunas[], int tam, int criterio);

int main()
{
    float precioProducto = 150.50;
    float precioProdConAumento;

    precioProdConAumento = aplicarAumento(precioProducto);

    if(precioProdConAumento>0)
    {
        printf("El precio con aumento es %.2f\n",precioProdConAumento);
    }
    else
    {
        printf("El precio con aumento no se pudo calcular\n");
    }





    eVacuna listaVacunas[TAM] =
    {
        {1234, "AstraZeneca", 'a', 30},
        {2345, "Covished", 'c', 40},
        {3456, "Sputnik", 's',60},
        {3457, "Sputnik", 's',50},
    };

    ordenarVacunas(listaVacunas,TAM, 1);


   for(int i= 0; i<TAM; i++)
    {

       printf("%4d    %-20s   %c  %.2f \n",listaVacunas[i].id,listaVacunas[i].nombre,listaVacunas[i].tipo,listaVacunas[i].efectividad);
    }


    reemplazarCaracteres("Almohada", 'a','z');

    return 0;
}


float aplicarAumento(float precio)
{
    float retorno = 0;

    retorno = precio * 1.05;

    return retorno;
}

int reemplazarCaracteres(char cadena[], char caracter1, char caracter2)
{
    int contCantidad = -1;
    int tamCadena;


    if(cadena != NULL)
    {
        contCantidad = 0;
        tamCadena = strlen(cadena);

        for(int i = 0; i < tamCadena; i++)
        {
            if(cadena[i] == caracter1)
            {
              cadena[i] = caracter2;
              contCantidad++;
            }
        }
    }

    return contCantidad;
}


int ordenarVacunas(eVacuna aVacunas[], int tam, int criterio)
{
    int retorno = -1;
    int flagSwap;
    eVacuna auxVacuna;
    int nuevoTam;


    if(aVacunas!= NULL && tam > 0 && (criterio == 0 || criterio ==1))
    {
        nuevoTam = tam -1;

        do
        {
            flagSwap = 0;

            for(int i=0; i < nuevoTam; i++)
            {
                if(
                    (aVacunas[i].tipo > aVacunas[i+1].tipo && criterio ==1) ||
                     (aVacunas[i].tipo < aVacunas[i+1].tipo && criterio ==0) ||
                      ((aVacunas[i].tipo == aVacunas[i+1].tipo) &&
                     ((aVacunas[i].efectividad > aVacunas[i+1].efectividad && criterio ==1) ||
                      (aVacunas[i].efectividad < aVacunas[i+1].efectividad && criterio ==0))))
                {
                    flagSwap = 1;
                    auxVacuna = aVacunas[i];
                    aVacunas[i] = aVacunas[i+1];
                    aVacunas[i+1] = auxVacuna;
                }
            }

            nuevoTam--;
        }
        while(flagSwap);

        retorno = 1;
    }

    return retorno;
}
