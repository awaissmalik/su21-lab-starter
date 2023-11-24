#ifndef EX_1_H
#define EX_1_H

typedef struct DNA_sequence {
     char sequence[21];
     int count_A;
     int count_C;
     int count_G;
     int count_T;
} DNA_sequence;

int num_occurrences(char *str, char letter);
void compute_nucleotide_occurrences(DNA_sequence *dna_seq);

#endif //EX_1_H
