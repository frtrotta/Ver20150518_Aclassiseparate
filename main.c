#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "classiSeparate.h"

int main(int argc, char** argv) {
    char scelta[] = "s";
    studente letto; // record impiegato per la lettura dell'input
    studente *elencoStudenti; // elenco degli studenti letti
    int dimensioneCorrente = 2; // Spazio allocato
    int nElementi = 0; // Numero degli elementi effettivamente memorizzati
    int i=0;
    
    elencoStudenti = (studente *)malloc(dimensioneCorrente *sizeof(studente));
    if(elencoStudenti == NULL) {
        fprintf(stderr, "Impossibile allocare memoria per elenco (%d byte)\n", dimensioneCorrente *sizeof(studente));
        exit(1);
    }
    
    while(!strcmp(scelta, "s")) {
        printf("\nInserisci il nome (max %d caratteri): ", NOME_MAXLEN);
        scanf("%[^\n]", letto.nome);
        printf("Inserisci il cognome (max %d caratteri): ", COGNOME_MAXLEN);
        scanf("\n%[^\n]", letto.cognome);
        printf("Inserisci la classe (max %d caratteri): ", CLASSE_MAXLEN);
        scanf("%s", letto.classe);
        printf("Inserisci il sesso (m/f): ");
        scanf("%s", letto.sesso);
        printf("Inserisci eta': ");
        scanf("%d", &(letto.eta));

        if(i == dimensioneCorrente) {
            elencoStudenti = rialloca(elencoStudenti, dimensioneCorrente);
            dimensioneCorrente *= 2;
            if(elencoStudenti == NULL) {
                fprintf(stderr, "Impossibile allocare memoria per elenco (%d byte)\n", dimensioneCorrente *sizeof(studente));
                exit(2);
            }
        }
        
        elencoStudenti[i] = letto;
        i++;
        
        printf("\nVuoi aggiungere un altro studente? (s/n) ");
        scanf("%s", scelta);
        
    }
    
    nElementi = i;
    
    /*
     * E' possibile ordinare tutti gli elementi insieme, sebbene l'elenco contenga
     * sia maschi che femmine. Infatti, se l'insimee è ordinato, anche un suo
     * qualsiasi sottoinsieme è ordinato.
     */
    ordina(elencoStudenti, nElementi);
    
    scriviCSV(elencoStudenti, nElementi, "maschi.csv", "femmine.csv");
    
    return (EXIT_SUCCESS);
}

