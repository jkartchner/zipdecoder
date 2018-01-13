#include "dbg.h"
#include "bstrlib.h"
#include <stdlib.h>

typedef struct ZipStruct {
    int zipcode_low;
    int zipcode_high;
    int count;
    bstring state;
    int zipcode_second_low;
    int zipcode_second_high;
} ZipStruct;

ZipStruct *USCode[51];

ZipStruct *zipstruct_create(int zipcode_low, int zipcode_high, bstring state, 
        int zipcode_second_low, int zipcode_second_high);
int get_state(int zip_code);
void USCode_clear(); 
int USCode_create(); 
int decode_file(char *filename_read, char *filename_write);
int decode_zip(int zipcount, char **zipcodes);
