#include <stdio.h>

#define NO_WORDS 2 
#define SIZE_WORDS NO_WORDS<<3 

typedef struct {
   unsigned long long double_word[NO_WORDS];
} arr_t __attribute__ ((aligned (SIZE_WORDS) ));


arr_t store_byte_data[8] =
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


arr_t store_byte_expected_data[8] =
       {    // double_word0         double_word1
          { 0x00000000000000EF, 0x0000000000000000 },
          { 0x000000000000BE00, 0x0000000000000000 },
          { 0x0000000000AD0000, 0x0000000000000000 },
          { 0x00000000DE000000, 0x0000000000000000 },
          { 0x000000EF00000000, 0x0000000000000000 },
          { 0x0000BE0000000000, 0x0000000000000000 },
          { 0x00AD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x0000000000000000 }
       };


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
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


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



int store_byte_test ( ) {
//arrt_t store_byte_data[8]={EF,BE,AD,DE,EF,BE,AD,DE};
arr_t store_byte_data[8] = {    // double_word0         double_word1
          { 0x00000000000000EF, 0x0000000000000000 },
          { 0x000000000000BE00, 0x0000000000000000 },
          { 0x0000000000AD0000, 0x0000000000000000 },
          { 0x00000000DE000000, 0x0000000000000000 },
          { 0x000000EF00000000, 0x0000000000000000 },
          { 0x0000BE0000000000, 0x0000000000000000 },
          { 0x00AD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x0000000000000000 }
       };	
	
	for(int i=0; i<8; i++)
{ int pass =1;
	if(store_byte_data[i].double_word[0] != store_byte_expected_data[i].double_word[0]){
		printf("\nmismatch in byte data");
	pass= 0;}
	else{
	printf("\nbyte data is matched");}
	return pass;}
	// EF, BE, AD, DE, EF, BE, AD, DE
} // store_byte_test


int store_half_word_test ( ) {
arr_t store_half_word_data[8] =
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
 for(int i=0; i<8; i++)
{ int p =1;
        if(store_half_word_data[i].double_word[0] != store_half_word_expected_data[i].double_word[0]){
                printf("\nmismatch in half word data");
        p= 0;}
        else{
        printf("\nhalf word data is match");}
        return p;}

// BEEF, ADBE, DEAD, EFDE, BEEF, ADBE, DEAD, EFDE

} 
//store_half_word_test


int store_word_test ( ) {
arr_t store_word_data[8] =
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


 for(int i=0; i<8; i++)
{ int pa =1;
        if(store_word_data[i].double_word[0] != store_word_expected_data[i].double_word[0]){
                printf("\nmismatch in store word data");
        pa= 0;}
        else{
        printf("\nstore word data is matched");}
        return pa;}

// DEADBEEF, F00DC0DE

} // store_word_test


int store_double_word_test ( ) {
arr_t store_double_word_data[8] =
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

	 for(int i=0; i<8; i++)
{ int pas =1;
        if(store_double_word_data[i].double_word[0] != store_double_word_expected_data[i].double_word[0]){
                printf("\nmismatch in double word data");
        pas= 0;}
        else{
        printf("\ndouble word data IS matched\n");}
        return pas;}

// DEADBEEFF00DC0DE

} // store_double_word_test



int main() {
int result = store_byte_test();
int result1 = store_half_word_test ();
int result2 = store_word_test();
int result3 = store_double_word_test();

} 
// main
