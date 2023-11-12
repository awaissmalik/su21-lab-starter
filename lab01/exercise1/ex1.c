#include <string.h>
#include "ex1.h"

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: all strings end in a null terminator */
int num_occurrences(char *str, char letter) {
    int count = 0;

    // Iterate through the string
    while (*str != '\0') {
        if (*str == letter) {
            count++;
        }
        str++;
    }

    return count;
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20 nucleotides.
All letters will be upper case. */
void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
    // Assuming DNA_sequence has a member 'sequence' to store the DNA sequence.

    // Initialize counts for each nucleotide to 0
    int count_A = 0, count_C = 0, count_G = 0, count_T = 0;

    // Iterate through the DNA sequence
    for (int i = 0; i < strlen(dna_seq->sequence); i++) {
        char nucleotide = dna_seq->sequence[i];

        // Update counts based on the nucleotide
        switch (nucleotide) {
            case 'A':
                count_A++;
                break;
            case 'C':
                count_C++;
                break;
            case 'G':
                count_G++;
                break;
            case 'T':
                count_T++;
                break;
            // You may want to handle other cases (e.g., invalid characters) as needed
        }
    }

    // Assign the counts to the DNA_sequence
    dna_seq->count_A = count_A;
    dna_seq->count_C = count_C;
    dna_seq->count_G = count_G;
    dna_seq->count_T = count_T;

    // Make sure to add a NULL terminator to the sequence
    dna_seq->sequence[strlen(dna_seq->sequence)] = '\0';
}
