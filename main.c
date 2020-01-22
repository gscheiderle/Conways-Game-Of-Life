
#include <stdio.h>
#include <stdlib.h>

#define BUF 1024
#define ZEILENLAENGE
#define NUMLETTERS 100
#define ACTIVE 1
#define INACTIVE 0
#define ACTIVE_SYMBOL '*'
#define INACTIVE_SYMBOL ' '


int main(void) {


   int i, i_3, j, zeile, spalte;

   int y, yy, yx, x, xx, xy; // zur Definition rund um die aktiven  Zellen
   int *nw, *n, *no, *w, *o, *so, *s, *sw; // Bezeichnung (Kompass) für jene als Gedächtnishilfe

   int zaehler_1;
   zaehler_1=0;

   /* Matrix ist Zeiger auf int-Zeiger. */
   int ** matrix;
   int ZEILENLAENGE;

    int count_generation;
        count_generation=0;

    int generation;
        generation=0;

    int ggg, gg, g, pggg, pgg, hhh, hh, h, phhh, phh ;  // zur Definition rund um die inaktiven  Zellen

    int temp;
        temp=0;


    // Anlegen der Matrix ( Spielfeld, die Welt )

    printf("Wie viele Zeilen:\nHow many rows: ");
    scanf("%d", &zeile);

    printf("\n");

    printf("Wie viele Spalten:\nHow many columns: ");
    scanf("%d", &spalte);

    printf("\n");

    printf("Wie viele Generationen:\nHow many generations: ");
    scanf("%d", &generation);

    printf("\n");



   /* Speicher reservieren für die int-Zeiger (=zeile) */

   matrix = malloc(zeile * sizeof(int *));
   if(NULL == matrix) {
      printf("Kein virtueller RAM mehr vorhanden ... !");
      return EXIT_FAILURE;
   }

   /* Speicher reservieren für die einzelnen Spalten */
   /* der i-ten Reihe */

   for(i = 0; i < zeile; i++) {
      matrix[i] = malloc(spalte * sizeof(int));
         if(NULL == matrix[i]) {
            printf("Kein Speicher mehr fuer Zeile %d\n",i);
            return EXIT_FAILURE;
         }
   }

   /* mit beliebigen Werten initialisieren */

   for (i = 0; i < zeile; i++) {
      for (j = 0; j < spalte; j++)
         matrix[i][j] = INACTIVE + INACTIVE;      /* matrix[zeile][spalte] */
   }


// Wenn die Datei "generation.csv" leer ist,
// sollte dieser Gleiter aufgerufen werden
// Ansonsten /* ... */ kommentieren

// Andere Start-Konfigurationen werden in die Datei "generation.csv" kopiert.
// Wie der anliegende PULSAR

// If the file "generation.csv" is empty,
// should this glider be called
// Otherwise /* ... */ comment

// Other startup configurations are copied to the file "generation.csv".
// Like the attached PULSAR

       matrix[4][4]=ACTIVE;
       matrix[5][5]=ACTIVE;
       matrix[6][3]=ACTIVE;
       matrix[6][4]=ACTIVE;
       matrix[6][5]=ACTIVE;


for ( count_generation = 0; count_generation < generation; count_generation++ ) {


    typedef struct { int number_2; int number; }
    record_t;


    FILE *fp;
    record_t zeilen_i[NUMLETTERS], spalten_j[NUMLETTERS];
    size_t count = 0;
    fp = fopen(("generation.csv"), "r+");
    if (fp == NULL) { fprintf(stderr, "Fehler beim Oeffnen der Datei\n");
    return 1;
    }

    while (fscanf(fp, " %d,%d", &zeilen_i[count].number_2, &spalten_j[count].number) == 2) {
           count++;
    }

int ii=0;
int jj=0;

   for (size_t i = 0; i < count; i++) {

            ii=zeilen_i[i].number_2;
            jj=spalten_j[i].number;

            matrix[ii][jj] = ACTIVE ;
   }

// Ohne Ausgabe auf der Konsole (nur das letzte Bild)
// z.B. Geschwigkeit messen mit riesigen Matrix'

if ( count_generation == generation-1 ) {

        printf("\n\n");

   // Inhalt der Matrix entsprechend ausgeben
   for (i = 0; i < zeile; i++) {
      for (j = 0; j < spalte; j++)
         // printf("%d ", matrix[i][j]);

          if (matrix[i][j] == INACTIVE)
              printf("%c ", INACTIVE_SYMBOL);
          else
              printf("%c ", ACTIVE_SYMBOL);


          printf("\n");

   }

}


/********************************************************************************************************/


fp = fopen("generation.csv", "w+");

if(fp == NULL) {
	printf("Datei konnte nicht geoeffnet werden.\n");
    }

if(fp != NULL) {

/********************************************************************************************************/



    for (i = 0; i < zeile; i++) {

        for (j = 0 ; j < spalte; j++) {

            if ( matrix[i][j] == ACTIVE ) {

     yy= i+1; // zeile ausgehend vom aktuellen Point (c)
     y=i-1;   // minus 1 Zeile ...
     xx=j+1;  // plus eine Spalte ...
     x=j-1;   // minus eine Spalte ...

    nw=&matrix[y][x];
    n =&matrix[y][j];
    no=&matrix[y][xx];
    w =&matrix[i][x];
    o =&matrix[i][xx];
    sw=&matrix[yy][x];
    s =&matrix[yy][j];
    so=&matrix[yy][xx];



if ( *nw == ACTIVE ) {zaehler_1++ ; }
if ( *n == ACTIVE )  {zaehler_1++ ; }
if ( *no == ACTIVE ) {zaehler_1++ ; }
if ( *w == ACTIVE )  {zaehler_1++ ; }
if ( *o == ACTIVE )  {zaehler_1++ ; }
if ( *sw == ACTIVE ) {zaehler_1++ ; }
if ( *s == ACTIVE )  {zaehler_1++ ; }
if ( *so == ACTIVE ) {zaehler_1++ ; }



if ( zaehler_1 == 2 || zaehler_1 == 3 ) {

        fprintf(fp ,"%d,%d\n", i, j );
    }

zaehler_1=0;

            }
        }
    }


/*************************************************************************************************************/
/***********************  INACTIVE NACHBARN DER ACTIVEN AUF DEREN ACTIVE UNTERSUCHEN  ************************/
/*************************************************************************************************************/



for (i = 0; i < zeile; i++) {
      for (j = 0, i_3 = 0; j < spalte; j++, i_3++)

        if ( matrix[i][j] == ACTIVE ) {


     ggg  = i-2;  // minus 2 Zeilen
     gg   = i-1;  // minus 1 Zeile
     g    = i;    // gleiche Zeile
     pggg = i+2;  // plus 2  Zeilen
     pgg  = i+1;  // plus 1  Zeile

     hhh  = j-2;  // minus 2 Spalten
     hh   = j-1;  // minus 1 Spalte
     h    = j;    // gleiche Spalte
     phhh = j+2;  // plus 2  Spalten
     phh  = j+1;  // plus 1  Spalte

//

int i_Array[]={gg,gg,gg,g,g,pgg,pgg,pgg};
int j_Array[]={hh,h,phh,hh,phh,hh,h,phh};


for (i_3 = 0; i_3 < 8; i_3++ ) {

int ppi;
int ppj;

ppi=i_Array[i_3];
ppj=j_Array[i_3];

i=i_Array[i_3];
j=j_Array[i_3];


     int xy = i;   // gleiche Zeile
     int yy = i+1; // plus eine Zeile
     int y  = i-1; // minus 1 Zeile ...

     int yx = j;   // gleiche Spalte
     int xx = j+1; // plus eine Spalte ...
     int x  = j-1; // minus eine Spalte ...


    nw=&matrix[y][x];
    n =&matrix[y][yx];
    no=&matrix[y][xx];
    w =&matrix[xy][x];
    o =&matrix[xy][xx];
    sw=&matrix[yy][x];
    s =&matrix[yy][yx];
    so=&matrix[yy][xx];



    if ( *nw == ACTIVE ) {zaehler_1++ ; }
    if ( *n  == ACTIVE ) {zaehler_1++ ; }
    if ( *no == ACTIVE ) {zaehler_1++ ; }
    if ( *w  == ACTIVE ) {zaehler_1++ ; }
    if ( *o  == ACTIVE ) {zaehler_1++ ; }
    if ( *sw == ACTIVE ) {zaehler_1++ ; }
    if ( *s  == ACTIVE ) {zaehler_1++ ; }
    if ( *so == ACTIVE ) {zaehler_1++ ; }


if ( zaehler_1 == 3 ) {

        fprintf(fp ,"%d,%d\n", i, j );
    }

zaehler_1=0;

}


        }
    }
}

    	//printf("Adressen wurden geschrieben.\n");

          fclose(fp);


/****************************  MATRIX LEEREN  ************************************/

    for (i = 0; i < zeile; i++) {

        for (j = 0 ; j < spalte; j++) {

                matrix[i][j] = INACTIVE + INACTIVE;
        }
    }

/*********************************************************************************/

}



/**************************************************************************************************************/
/*****************************************  SPEICHER FREIGEBEN  ***********************************************/
/**************************************************************************************************************/

   /* Spalten freigeben */

   for(i = 0; i < zeile; i++)
      free(matrix[i]);

   /* Zeilen freigeben. */

   free(matrix);


return 0;
}
