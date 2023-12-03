#include <stdio.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS << 3

#define EF 0xEF
#define BE 0xBE
#define AD 0xAD
#define DE 0xDE
#define BEEF 0xBEEF
#define ADBE 0xADBE
#define DEAD 0xDEAD
#define EFDE 0xEFDE
#define DEADBEEF 0xDEADBEEF
#define F00DC0DE 0xF00DC0DE

typedef struct {
    unsigned long long double_word[NO_WORDS];
} arr_t;


arr_t store_byte_data[8] =
    {
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000}};

arr_t store_byte_expected_data[8] =
    {
        // double_word0         double_word1
        {0x00000000000000EF, 0x0000000000000000},
        {0x000000000000BE00, 0x0000000000000000},
        {0x0000000000AD0000, 0x0000000000000000},
        {0x00000000DE000000, 0x0000000000000000},
        {0x000000EF00000000, 0x0000000000000000},
        {0x0000BE0000000000, 0x0000000000000000},
        {0x00AD000000000000, 0x0000000000000000},
        {0xDE00000000000000, 0x0000000000000000}};


arr_t store_half_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_expected_data[8] =
       {
          { 0x000000000000BEEF, 0x0000000000000000 },
          { 0x0000000000ADBE00, 0x0000000000000000 },
          { 0x00000000DEAD0000, 0x0000000000000000 },
          { 0x000000EFDE000000, 0x0000000000000000 },
          { 0x0000BEEF00000000, 0x0000000000000000 },
          { 0x00ADBE0000000000, 0x0000000000000000 },
          { 0xDEAD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x00000000000000EF }
       };


arr_t store_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_word_expected_data[8] =
       {
          { 0x00000000DEADBEEF, 0x0000000000000000 },
          { 0x000000DEADBEEF00, 0x0000000000000000 },
          { 0x0000DEADBEEF0000, 0x0000000000000000 },
          { 0x00DEADBEEF000000, 0x0000000000000000 },
          { 0xF00DC0DE00000000, 0x0000000000000000 },
          { 0x0DC0DE0000000000, 0x00000000000000F0 },
          { 0xC0DE000000000000, 0x000000000000F00D },
          { 0xDE00000000000000, 0x0000000000F00DC0 }
       };


arr_t store_double_word_data[8] =
    {
        {DEADBEEF, F00DC0DE},
        {DEADBEEF, F00DC0DE},
        {DEADBEEF, F00DC0DE},
        {DEADBEEF, F00DC0DE},
        {DEADBEEF, F00DC0DE},
        {DEADBEEF, F00DC0DE},
        {DEADBEEF, F00DC0DE},
        {DEADBEEF, F00DC0DE}};


arr_t store_double_word_expected_data[8] =
       {
          { 0xDEADBEEFF00DC0DE, 0x0000000000000000 },
          { 0xADBEEFF00DC0DE00, 0x00000000000000DE },
          { 0xBEEFF00DC0DE0000, 0x000000000000DEAD },
          { 0xEFF00DC0DE000000, 0x0000000000DEADBE },
          { 0xF00DC0DE00000000, 0x00000000DEADBEEF },
          { 0x0DC0DE0000000000, 0x000000DEADBEEFF0 },
          { 0xC0DE000000000000, 0x0000DEADBEEFF00D },
          { 0xDE00000000000000, 0x00DEADBEEFF00DC0 }
       };



int store_byte_test() {
  for (int i = 0; i < 8; i++) {
    store_byte_data[i].double_word[0] |= (EF << (8 * i));
    store_byte_data[i].double_word[1] |= (BE << (8 * i));
    store_byte_data[i].double_word[0] |= (AD << (8 * (i + 4)));
    store_byte_data[i].double_word[1] |= (DE << (8 * (i + 4)));
  }

  for (int i = 0; i < 8; i++) {
    if (store_byte_data[i].double_word[0] != store_byte_expected_data[i].double_word[0] ||
        store_byte_data[i].double_word[1] != store_byte_expected_data[i].double_word[1]) {
      printf("Mismatch at index %d\n", i);
      return 1;
    }
  }

  return 0;
}

int store_half_word_test() {
  for (int i = 0; i < 8; i++) {
    store_half_word_data[i].double_word[0] |= (BEEF << (16 * i));
    store_half_word_data[i].double_word[1] |= (ADBE << (16 * i));
    store_half_word_data[i].double_word[0] |= (DEAD << (16 * (i + 4)));
    store_half_word_data[i].double_word[1] |= (EFDE << (16 * (i + 4)));
  }

  for (int i = 0; i < 8; i++) {
    if (store_half_word_data[i].double_word[0] != store_half_word_expected_data[i].double_word[0] ||
        store_half_word_data[i].double_word[1] != store_half_word_expected_data[i].double_word[1]) {
      printf("Mismatch at index %d\n", i);
      return 1;
    }
  }

  return 0;
}

int store_word_test() {
  for (int i = 0; i < 8; i++) {
    store_word_data[i].double_word[0] |= (DEADBEEF << (32 * i));
    store_word_data[i].double_word[1] |= (F00DC0DE << (32 * i));
  }

  for (int i = 0; i < 8; i++) {
    if (store_word_data[i].double_word[0] != store_word_expected_data[i].double_word[0] ||
        store_word_data[i].double_word[1] != store_word_expected_data[i].double_word[1]) {
      printf("Mismatch at index %d\n", i);
      return 1;
    }
  }

  return 0;
}

int store_double_word_test() {
  for (int i = 0; i < 8; i++) {
    store_double_word_data[i].double_word[0] = DEADBEEF;
    store_double_word_data[i].double_word[1] = F00DC0DE;
  }

  for (int i = 0; i < 8; i++) {
    if (store_double_word_data[i].double_word[0] !=
        store_double_word_expected_data[i].double_word[0]) {
      printf("Mismatch at index %d\n", i);
      return 1;
    }
  }

  return 0;
}
int main() {
    int result;

    result = store_byte_test();
    printf("store_byte_test: %s\n", result == 0 ? "Passed" : "Failed");

    result = store_half_word_test();
    printf("store_half_word_test: %s\n", result == 0 ? "Passed" : "Failed");

    result = store_word_test();
    printf("store_word_test: %s\n", result == 0 ? "Passed" : "Failed");

    result = store_double_word_test();
    printf("store_double_word_test: %s\n", result == 0 ? "Passed" : "Failed");

    return 0;
}

