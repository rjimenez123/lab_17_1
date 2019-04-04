#include <stdlib.h>
#include <stdio.h>
#include "my_lib.h"

#define MAX_NAME_CHARS 20

using namespace std;

int main()
{
    int items_read, day, month, year, hh, mm, ss, code;
    int image_counter, pixel_counter, name_char_counter;
    int rows, columns;
    char c;

    // IMPRIMIR CABECERA
    printf("REPORTE DE DIBUJOS\n");
    print_line(130, '=');

    while (1) {
        items_read = scanf("%d", &code);

        //LEO CODIGO DE LA PERSONA
        if (items_read == 1) {
            printf("ALUMNO %d: ", code);
            scanf("%*d");

            //LEO E IMPRIMO EL NOMBRE
            while (1) {
                c = getchar();
                if (c == ' ') continue;
                if (c == ':') break;
                putchar(c);
            }
            printf("\n");
            scanf("%*d");
        }

        //LEO EL BUCLE QUE COMIENZA EN EL NOMBRE DE ARCHIVO
        if (items_read == 0) {
            image_counter++;
            print_line(130, '-');
            printf("IMAGEN %02d%11c", image_counter, ' '); printf("EXT.%6c", image_counter, ' ');
            printf("%11cCREACION%11c", ' ', ' '); printf("%9cMODIFICACION%9c", ' ', ' '); printf("%11cETIQUETAS%20c\n", ' ', ' ');

            // LEO E IMPRIMO EL NOMBRE DEL ARCHIVO
            while (1) {
                c = getchar();
                if (c == '.') break;
                name_char_counter++;
                putchar(c);
            }

            for (int i = 0; i < MAX_NAME_CHARS - name_char_counter; i++)
                putchar(' ');
            name_char_counter = 0;

            // LEO E IMPRIMO LA EXTENSION
            while (1) {
                c = getchar();
                if (c == ' ') break;
                putchar(c);
            }
            printf("%7c", ' ');

            // LEO E IMPRIMO LA FECHA Y LA HORA x1
            scanf("%d/%d/%d", &day, &month, &year);
            printf("%02d/%02d/%4d ", day, month, year);
            scanf("%d/%d/%d", &hh, &mm, &ss);
            printf("%02d/%02d/%02d ", hh, mm, ss);
            printf("%11c", ' ');

            // LEO E IMPRIMO LAS ETIQUETAS
            while (1) {
                scanf("%*d");
                while (1) {
                    c = getchar();
                    if (c  == ' ') continue;
                    if ( c ==  ',') break;
                    if (c >= '0' || c <= '9') {
                        ungetc(c, stdin);
                        break;
                    }
                    putchar(c);
                }
            }

            scanf("%d*%d", &rows, &columns);
        }

    }
    return 0;
}
