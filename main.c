/* 2D_dyn_array.c */
#include <stdio.h>
#include <stdlib.h>
#define BUF 1024
#define ZEILENLAENGE
#define NUMLETTERS 100
#define ACTIVE 1
#define INACTIVE 0


int main(void) {


   int i, i_2, i_3, i_4, j, zeile, spalte, a, b;
   a=0;
   b=0;
   int y, yy, x, xx; // zur Definition rund um den aktuellen Point
   int *nw, *n, *no, *w, *c, *o, *so, *s, *sw;
   int zaehler_1;
   zaehler_1=0;

   /* Matrix ist Zeiger auf int-Zeiger. */
   int ** matrix;
   int ZEILENLAENGE;

    int count_generation;
        count_generation=0;

    int generation;
        generation=0;


    int ggg, gg, g, pggg, pgg, hhh, hh, h, phhh, phh ;
    int *nwnw, *nwn, *nwno, *nww, *ccnw, *nwo, *nwsw, *nws, *nwso, *nnw, *nn, *nno, *nnnw, *ccn, *nnno, *nsw, *ns, *nso, *nonw, *non;
    int *nono, *now, *ccno, *nooo, *nosw, *nos, *noso, *wnw, *wn, *wno, *ww, *ccw, *wo, *wsw, *ws, *wso, *onw, *on, *ono, *ow;
    int *cco, *oo, *osw, *os, *oso, *swnw, *swn, *swno, *sww, *swww, *ccsw, *swo, *swsw, *sws, *swso, *snw, *sn, *sno, *ssww, *ccs;
    int *soo, *ssw, *ss, *sso, *sonw, *son, *sono, *sow, *ccso, *sooo, *sosw, *sos, *soso, *nonoo;


    int temp;
        temp=0;


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

// if ( count_generation == generation-1 ) {

        printf("\n\n");

   // Inhalt der Matrix entsprechend ausgeben
   for (i = 0; i < zeile; i++) {
      for (j = 0; j < spalte; j++)
          printf("%d ", matrix[i][j]);
          printf("\n");

   }

// }


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
        // spielfeld_3[i_2] = &matrix[i][j];
        // i_2++;
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

// NW
     nwnw   = &matrix[ggg][hhh];   // NW
     nwn    = &matrix[ggg][hh];    // N
     nwno   = &matrix[ggg][h];     // NO
     nww    = &matrix[gg][hhh];    // W
     ccnw   = &matrix[gg][hh];     // Orig-Zelle
     nwo    = &matrix[gg][h];      // O
     nwsw   = &matrix[g][hhh];     // NWSW
     nws    = &matrix[g][hh];      // NWS
     nwso   = &matrix[g][h];       // NWSO

// N
     nnw    = &matrix[ggg][hh];    // NW
     nn     = &matrix[ggg][h];     // N
     nno    = &matrix[ggg][phh];   // NO
     nnnw   = &matrix[gg][hh];     // W
     ccn    = &matrix[gg][h];      // Orig-Zelle
     nnno   = &matrix[gg][phh];    // O
     nsw    = &matrix[g][hh];      // NWSW
     ns     = &matrix[g][h];       // NWS
     nso    = &matrix[g][phh];     // NWSO

// NO
     nonw   = &matrix[ggg][h];     // NW
     non    = &matrix[ggg][phh];   // N
     nono   = &matrix[ggg][phhh];  // NO
     now    = &matrix[gg][h];      // W
     ccno   = &matrix[gg][phh];    // Orig-Zelle
     nonoo  = &matrix[gg][phhh];   // O
     nosw   = &matrix[g][h];       // NWSW
     nos    = &matrix[g][phh];     // NWS
     noso   = &matrix[g][phhh];    // NWSO

 // W
     wnw    = &matrix[gg][hhh];    // WNW
     wn     = &matrix[gg][hh];     // WN
     wno    = &matrix[gg][h];      // WNO
     ww     = &matrix[g][hhh];     // WW
     ccw    = &matrix[g][hh];      // Orig-Zelle
     wo     = &matrix[g][h];       // WO
     wsw    = &matrix[pgg][hhh];   // WSW
     ws     = &matrix[pgg][hh];    // WS
     wso    = &matrix[pgg][h];     // WSO

 // O
     onw    = &matrix[gg][h];       // ONW
     on     = &matrix[gg][phh];     // ON
     ono    = &matrix[gg][phhh];    // ONO
     ow     = &matrix[g][h];        // OW
     cco    = &matrix[g][phh];      // Orig-Zelle
     oo     = &matrix[g][phhh];     // OO
     osw    = &matrix[pgg][h];      // OSW
     os     = &matrix[pgg][phh];    // OS
     oso    = &matrix[pgg][phhh];   // OSO

 // SW
     swnw   = &matrix[g][hhh];      // SWNW
     swn    = &matrix[g][hh];       // SWN
     swno   = &matrix[g][h];        // SWNO
     sww    = &matrix[pgg][hhh];    // SWW
     ccsw   = &matrix[pgg][hh];     // Orig-Zelle
     swo    = &matrix[pgg][h];      // SWO
     swsw   = &matrix[pggg][hhh];   // SWSW
     sws    = &matrix[pggg][hh];    // SWS
     swso   = &matrix[pggg][h];     // SWSO
// S
     snw    = &matrix[g][hh];       // SNW
     sn     = &matrix[g][h];        // SN
     sno    = &matrix[g][phh];      // SNO
     swww   = &matrix[pgg][hh];     // SW
     ccs    = &matrix[pgg][h];      // Orig-Zelle
     soo    = &matrix[pgg][phh];    // SOO
     ssw    = &matrix[pggg][hh];    // SSW
     ss     = &matrix[pggg][h];     // SS
     sso    = &matrix[pggg][phh];   // SSO
// SO
     sonw   = &matrix[g][h];        // SONW
     son    = &matrix[g][phh];      // SON
     sono   = &matrix[g][phhh];     // SONO
     sow    = &matrix[pgg][h];      // SOW
     ccso   = &matrix[pgg][phh];    // Orig-Zelle
     sooo   = &matrix[pgg][phhh];   // SOOO
     sosw   = &matrix[pggg][h];     // SOSW
     sos    = &matrix[pggg][phh];   // SOS
     soso   = &matrix[pggg][phhh];  // SOSO


int ccnw_counter=0;
if ( *nwnw == ACTIVE ){ccnw_counter++;}
if ( *nwn  == ACTIVE ){ccnw_counter++;}
if ( *nwno == ACTIVE ){ccnw_counter++;}
if ( *nww  == ACTIVE ){ccnw_counter++;}
if ( *nwo  == ACTIVE ){ccnw_counter++;}
if ( *nwsw == ACTIVE ){ccnw_counter++;}
if ( *nws  == ACTIVE ){ccnw_counter++;}
if ( *nwso == ACTIVE ){ccnw_counter++;}
if ( ccnw_counter == 3 ) { fprintf(fp ,"%d,%d\n", gg, hh ); }


int ccn_counter=0;
if ( *nnw  == ACTIVE ){ccn_counter++;}
if ( *nn   == ACTIVE ){ccn_counter++;}
if ( *nno  == ACTIVE ){ccn_counter++;}
if ( *nnnw == ACTIVE ){ccn_counter++;}
if ( *nnno == ACTIVE ){ccn_counter++;}
if ( *nsw  == ACTIVE ){ccn_counter++;}
if ( *ns   == ACTIVE ){ccn_counter++;}
if ( *nso  == ACTIVE ){ccn_counter++;}
if ( ccn_counter == 3 ) { fprintf(fp ,"%d,%d\n", gg, h ); }


int ccno_counter=0;
if ( *nonw == ACTIVE ){++ccno_counter;}
if ( *non  == ACTIVE ){++ccno_counter;}
if ( *nono == ACTIVE ){++ccno_counter;}
if ( *now  == ACTIVE ){++ccno_counter;}
if ( *nonoo== ACTIVE ){++ccno_counter;}
if ( *nosw == ACTIVE ){++ccno_counter;}
if ( *nos  == ACTIVE ){++ccno_counter;}
if ( *noso == ACTIVE ){++ccno_counter;}
if ( ccno_counter == 3 ) { fprintf(fp ,"%d,%d\n", gg, phh ); }



int ccw_counter=0;
if ( *wnw  == ACTIVE ){ccw_counter++;}
if ( *wn   == ACTIVE ){ccw_counter++;}
if ( *wno  == ACTIVE ){ccw_counter++;}
if ( *ww   == ACTIVE ){ccw_counter++;}
if ( *wo   == ACTIVE ){ccw_counter++;}
if ( *wsw  == ACTIVE ){ccw_counter++;}
if ( *ws   == ACTIVE ){ccw_counter++;}
if ( *wso  == ACTIVE ){ccw_counter++;}
if ( ccw_counter == 3 ) { fprintf(fp ,"%d,%d\n", g, hh ); }



int cco_counter=0;
if ( *onw  == ACTIVE ){cco_counter++;}
if ( *on   == ACTIVE ){cco_counter++;}
if ( *ono  == ACTIVE ){cco_counter++;}
if ( *ow   == ACTIVE ){cco_counter++;}
if ( *oo   == ACTIVE ){cco_counter++;}
if ( *osw  == ACTIVE ){cco_counter++;}
if ( *os   == ACTIVE ){cco_counter++;}
if ( *oso  == ACTIVE ){cco_counter++;}
if ( cco_counter == 3 ) { fprintf(fp ,"%d,%d\n", g, phh ); }


int ccsw_counter=0;
if ( *swnw == ACTIVE ){ccsw_counter++;}
if ( *swn  == ACTIVE ){ccsw_counter++;}
if ( *swno == ACTIVE ){ccsw_counter++;}
if ( *sww  == ACTIVE ){ccsw_counter++;}
if ( *swo  == ACTIVE ){ccsw_counter++;}
if ( *swsw == ACTIVE ){ccsw_counter++;}
if ( *sws  == ACTIVE ){ccsw_counter++;}
if ( *swso == ACTIVE ){ccsw_counter++;}
if ( ccsw_counter == 3 ) { fprintf(fp ,"%d,%d\n", pgg, hh ); }



int ccs_counter=0;
if ( *snw  == ACTIVE ){ccs_counter++;}
if ( *sn   == ACTIVE ){ccs_counter++;}
if ( *sno  == ACTIVE ){ccs_counter++;}
if ( *swww == ACTIVE ){ccs_counter++;}
if ( *soo  == ACTIVE ){ccs_counter++;}
if ( *ssw  == ACTIVE ){ccs_counter++;}
if ( *ss   == ACTIVE ){ccs_counter++;}
if ( *sso  == ACTIVE ){ccs_counter++;}
if ( ccs_counter == 3 ) { fprintf(fp ,"%d,%d\n", pgg, h ); }


int ccso_counter=0;
if ( *sonw == ACTIVE ){ccso_counter++;}
if ( *son  == ACTIVE ){ccso_counter++;}
if ( *sono == ACTIVE ){ccso_counter++;}
if ( *sow  == ACTIVE ){ccso_counter++;}
if ( *sooo == ACTIVE ){ccso_counter++;}
if ( *sosw == ACTIVE ){ccso_counter++;}
if ( *sos  == ACTIVE ){ccso_counter++;}
if ( *soso == ACTIVE ){ccso_counter++;}
if ( ccso_counter == 3 ) { fprintf(fp ,"%d,%d\n", pgg, phh ); }

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
