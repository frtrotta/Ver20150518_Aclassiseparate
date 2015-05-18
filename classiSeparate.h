#ifndef CLASSISEPARATE_H
#define	CLASSISEPARATE_H

#include <stdlib.h>

#define NOME_MAXLEN 25
#define COGNOME_MAXLEN 25
#define CLASSE_MAXLEN 5

struct s_studente {
    char nome[NOME_MAXLEN+1];
    char cognome[COGNOME_MAXLEN+1];
    char classe[CLASSE_MAXLEN+1];
    char sesso[2];
    int eta;
};

typedef struct s_studente studente;

/**
 * Ordina l'elenco degli studenti in base al cognome.
 * @param elenco
 * @param dimensione
 */
void ordina(studente elenco[], int dimensione);

studente *rialloca(studente *elencoCorrente, int dimensioneCorrente);

int scriviCSV(studente *elenco, int dimensione, char nomeFileMaschi[], char nomeFileFemmine[]);

/**
 * Scrive l'intestazione (prima riga) del file CSV
 * @param f
 */
void scriviIntestazioneCSV(FILE *f);

/**
 * Scrive tutti gli studenti di uno specifico sesso nel file.
 * @param f
 * @param sesso
 * @param elenco
 * @param dimensione
 * @return Il numero di studenti scritti nel file.
 */
int scriviSessoCSV(FILE *f, char sesso[], studente elenco[], int dimensione);

/**
 * Scrive un singolo studente nel file in formato CSV
 * @param f
 * @param s
 */
void scriviStudenteCSV(FILE *f, studente s);

#endif	/* CLASSISEPARATE_H */

