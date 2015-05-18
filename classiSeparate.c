#include <stdio.h>
#include <stdlib.h>

#include "classiSeparate.h"

/**
 * Ordina l'elenco degli studenti in base al cognome.
 * @param elenco
 * @param dimensione
 */
void ordina(studente elenco[], int dimensione) {
    studente temp;
    int indiceMinore;
    int i, j;
    
    indiceMinore = 0;
    for(i=0; i<(dimensione-1); i++) {
        indiceMinore = i;
        for(j=i+1; j<dimensione; j++) {
            if(strcmp(elenco[j].cognome, elenco[indiceMinore].cognome) < 0) {
                indiceMinore = j;
            }
        }
        if(indiceMinore != i) {
            temp = elenco[indiceMinore];
            elenco[indiceMinore] = elenco[i];
            elenco[i] = temp;
        }
    }
    return;
}

studente *rialloca(studente *elencoCorrente, int dimensioneCorrente) {
    studente *elencoNuovo = NULL;
    int i;
    
    elencoNuovo = (studente *)malloc(2*dimensioneCorrente*sizeof(studente));
    if(elencoNuovo != NULL) {
        for(i=0; i<dimensioneCorrente; i++) {
            elencoNuovo[i] = elencoCorrente[i];
        }
        free(elencoCorrente);
    }
    
    return elencoNuovo;
}

int scriviCSV(studente elenco[], int dimensione, char nomeFileMaschi[], char nomeFileFemmine[]) {
    FILE *maschi;
    FILE *femmine;
    
    int returnCode = 0;
    
    maschi = fopen(nomeFileMaschi, "w");
    femmine = fopen(nomeFileFemmine, "w");
    
    if(maschi != NULL && femmine != NULL) {
        scriviIntestazioneCSV(maschi);
        scriviIntestazioneCSV(femmine);

        scriviSessoCSV(maschi, "m", elenco, dimensione);
        scriviSessoCSV(femmine, "f", elenco, dimensione);

        fclose(maschi);
        fclose(femmine);
    }
    else {
        returnCode = -1;
        if(maschi == NULL)
            fprintf(stderr, "Impossibile aprire il file \"%s\"\n", nomeFileMaschi);
        if(femmine == NULL)
            fprintf(stderr, "Impossibile aprire il file \"%s\"\n", nomeFileFemmine);
    }
    
    return returnCode;
}

/**
 * Scrive l'intestazione (prima riga) del file CSV
 * @param f
 */
void scriviIntestazioneCSV(FILE *f) {
    fprintf(f, "nome;cognome;classe;sesso;eta\n");
}

/**
 * Scrive tutti gli studenti di uno specifico sesso nel file.
 * @param f
 * @param sesso
 * @param elenco
 * @param dimensione
 * @return Il numero di studenti scritti nel file.
 */
int scriviSessoCSV(FILE *f, char sesso[], studente elenco[], int dimensione) {
    int i;
    
    for(i=0; i<dimensione; i++) {
        if(!strcmp(elenco[i].sesso, sesso)) {
            scriviStudenteCSV(f, elenco[i]);
        }
    }
    return i;
}

/**
 * Scrive tutti gli studenti di uno specifico sesso nel file.
 * @param f
 * @param sesso
 * @param elenco
 * @param dimensione
 * @return Il numero di studenti scritti nel file.
 */
void scriviStudenteCSV(FILE *f, studente s) {
    fprintf(f, "%s;%s;%s;%s;%d\n", s.nome, s.cognome, s.classe, s.sesso, s.eta);
}