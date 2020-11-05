#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC       27
#define SPACE     32
#define BACKS     8
#define COMMA     44
#define PUNTO     46
#define PunDouble 58
#define PunYComma 59
#define ENTER     13

void leer_texto_archivo(char *nombre);

int main()
{
    int Tecla, TeclaPrev = ENTER;
    char nombreFILE[] = "Archivo.txt";
    FILE *archivo = fopen(nombreFILE, "w");
    fprintf(archivo,nombreFILE);
    if (archivo==NULL)
    {
        printf("Error de acceso a fichero.\n");
        exit(0);
    };
    fputc(SPACE,archivo);
    fputc(SPACE,archivo);
    printf("%c",SPACE);
    printf("%c",SPACE);
    while(Tecla != ESC && !ferror(archivo)){
        TeclaPrev = Tecla;
        Tecla = getch(); //se escribe la tecla para ver si esta se cambie
        if((Tecla == COMMA && TeclaPrev != SPACE) || (Tecla == PUNTO && TeclaPrev != SPACE) ||
           (Tecla == PunYComma && TeclaPrev != SPACE) || (Tecla == PunDouble && TeclaPrev != SPACE)){
            fputc(Tecla,archivo);//poner en el archivo
            fputc(SPACE,archivo);
            printf("%c%c",Tecla, SPACE); // la tecla esta exactamente donde deve de estar y se le pone un espacio al final
        }
        else{
            if((Tecla == COMMA && TeclaPrev == SPACE) || (Tecla == PUNTO && TeclaPrev == SPACE) ||
               (Tecla == PunYComma && TeclaPrev == SPACE) || (Tecla == PunDouble && TeclaPrev == SPACE)){
                fputc(BACKS,archivo);//backspace
                fputc(Tecla,archivo);//poner en archivo
                fputc(SPACE,archivo);
                printf("%c", BACKS);// la tecla esta uno mas para adelante, se hecha para atras y espacio
                printf("%c%c",Tecla, SPACE);
            }
            else{
                fputc(Tecla,archivo);
                printf("%c",Tecla); //todo esta correcto
            }
        }
        if(Tecla == ENTER){
            printf("\n");
        }
    }

    if (ferror(archivo))
    {
        printf("Error al grabar el archivo.\n");
        fclose(archivo);
    }

    printf("\nLa cadena de caracteres ingresada es: %s\n-->",Tecla);

    fclose(archivo);
    return 0;
}

void leer_texto_archivo(char *nombre){
    FILE *archivo = fopen(nombre, "r");
    printf("======= Información del archivo =========\n");
    char caracter;
    while ((caracter = fgetc(archivo)) != EOF){
        fputc(caracter, stdout);
    }
    printf("======= Fin Información del archivo =========\n");
    fclose(archivo);
}
