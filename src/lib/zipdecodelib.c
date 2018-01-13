#include "zipdecodelib.h"
#include <stdio.h>
#include <string.h>

ZipStruct *zipstruct_create(int zipcode_low, int zipcode_high, 
       bstring state, int zipcode_second_low, int zipcode_second_high)
{
   ZipStruct *zip = malloc(sizeof(ZipStruct)); 
   check_mem(zip);
   zip->zipcode_low = zipcode_low;
   zip->zipcode_high = zipcode_high;
   zip->count = 0;
   zip->state = state;
   zip->zipcode_second_low = zipcode_second_low;
   zip->zipcode_second_high = zipcode_second_high;

   return zip;

 error:
   if(zip)
       free(zip);
   return NULL;
}

void USCode_clear()
{
    for(int i = 0; i < 51; i++) {
        if(USCode[i] != NULL) {
            free(USCode[i]);
        }
    }
}

int get_state(int zip_code) 
{
    // we first handle a number of edge cases
    if(zip_code == 501 || zip_code == 544) {
        return 7;
    }
    if(zip_code == 5501 || zip_code == 5544) {
        return 0;
    }
    if(zip_code == 6390) {
        return 7;
    }
    if(zip_code == 73960) {
        return 38;
    }
    if(zip_code == 83414) {
        return 40;
    } // then we handle the bulk of cases
    for(int i = 0; i < 51; i++) {
        if(zip_code >= USCode[i]->zipcode_low && \
                zip_code <= USCode[i]->zipcode_high) {
                return  i;
        }
        
        if(USCode[i]->zipcode_second_low) {
           if(zip_code >= USCode[i]->zipcode_second_low &&
                    zip_code <= USCode[i]->zipcode_second_high){
                return i;
            }
        } 
    }

    if(zip_code >= 56901 && zip_code <= 56972) {
        return 10;
    }
    if(zip_code >= 88510 && zip_code <= 88595) {
        return 38;
    }

    return -1;
}

int USCode_create()
{   
    USCode[0] = zipstruct_create(1001, 2791, (bstring)"Massachusetts", 0, 0);
    USCode[1] = zipstruct_create(2801, 2940, (bstring)"Rhode Island", 0, 0);
    USCode[2] = zipstruct_create(3031, 3897, (bstring)"New Hampshire", 0, 0);
    USCode[3] = zipstruct_create(3901, 4992, (bstring)"Maine", 0, 0);
    USCode[4] = zipstruct_create(5001, 5907, (bstring)"Vermont", 0, 0);
    USCode[5] = zipstruct_create(6001, 6927, (bstring)"Connecticut", 0, 0);
    USCode[6] = zipstruct_create(7001, 8989, (bstring)"New Jersey", 0, 0);
    USCode[7] = zipstruct_create(10001, 14905, (bstring)"New York", 0, 0);
    USCode[8] = zipstruct_create(15001, 19612, (bstring)"Pennsylvania", 0, 0);
    USCode[9] = zipstruct_create(19701, 19980, (bstring)"Delaware", 0, 0);
    USCode[10] = zipstruct_create(20001, 20091, 
            (bstring)"District of Columbia", 20201, 20599);
    USCode[11] = zipstruct_create(20101, 20198, (bstring)"Virginia", 22003, 24658);
    USCode[12] = zipstruct_create(20601, 21930, (bstring)"Maryland", 0, 0);
    USCode[13] = zipstruct_create(24701, 26886, (bstring)"West Virginia", 0, 0);
    USCode[14] = zipstruct_create(27006, 28909, (bstring)"North Carolina", 0, 0);
    USCode[15] = zipstruct_create(29001, 29945, (bstring)"South Carolina", 0, 0);
    USCode[16] = zipstruct_create(30002, 31999, (bstring)"Georgia", 39813, 39901);
    USCode[17] = zipstruct_create(32003, 34997, (bstring)"Florida", 0, 0);
    USCode[18] = zipstruct_create(35004, 36925, (bstring)"Alabama", 0, 0);
    USCode[19] = zipstruct_create(37010, 38589, (bstring)"Tennessee", 0, 0);
    USCode[20] = zipstruct_create(38601, 39776, (bstring)"Mississippi", 0, 0);
    USCode[21] = zipstruct_create(40003, 42788, (bstring)"Kentucky", 0, 0);
    USCode[22] = zipstruct_create(43001, 45999, (bstring)"Ohio", 0, 0);
    USCode[23] = zipstruct_create(46001, 47997, (bstring)"Indiana", 0, 0);
    USCode[24] = zipstruct_create(48001, 49971, (bstring)"Michigan", 0, 0);
    USCode[25] = zipstruct_create(50001, 52809, (bstring)"Iowa", 0, 0);
    USCode[26] = zipstruct_create(53001, 54990, (bstring)"Wisconsin", 0, 0);
    USCode[27] = zipstruct_create(55001, 56763, (bstring)"Minnesota", 0, 0);
    USCode[28] = zipstruct_create(57001, 57799, (bstring)"South Dakota", 0, 0);
    USCode[29] = zipstruct_create(58001, 58856, (bstring)"North Dakota", 0, 0);
    USCode[30] = zipstruct_create(59001, 59937, (bstring)"Montana", 0, 0);
    USCode[31] = zipstruct_create(60001, 62999, (bstring)"Illinois", 0, 0);
    USCode[32] = zipstruct_create(63005, 65899, (bstring)"Missouri", 0, 0);
    USCode[33] = zipstruct_create(66002, 67594, (bstring)"Kansas", 0, 0);
    USCode[34] = zipstruct_create(68001, 69367, (bstring)"Nebraska", 0, 0);
    USCode[35] = zipstruct_create(70001, 71497, (bstring)"Louisiana", 0, 0);
    USCode[36] = zipstruct_create(71601, 72959, (bstring)"Arkansas", 0, 0);
    USCode[37] = zipstruct_create(73001, 73196, (bstring)"Oklahoma", 73401, 74966);
    USCode[38] = zipstruct_create(73301, 73344, (bstring)"Texas", 75001, 79999);
    USCode[39] = zipstruct_create(80001, 81658, (bstring)"Colorado", 0, 0);
    USCode[40] = zipstruct_create(82001, 83128, (bstring)"Wyoming", 0, 0);
    USCode[41] = zipstruct_create(83201, 83877, (bstring)"Idaho", 0, 0);
    USCode[42] = zipstruct_create(84001, 84791, (bstring)"Utah", 0, 0);
    USCode[43] = zipstruct_create(85001, 86556, (bstring)"Arizona", 0, 0);
    USCode[44] = zipstruct_create(87001, 88439, (bstring)"New Mexico", 0, 0);
    USCode[45] = zipstruct_create(88901, 89883, (bstring)"Nevada", 0, 0);
    USCode[46] = zipstruct_create(90001, 96162, (bstring)"California", 0, 0);
    USCode[47] = zipstruct_create(96701, 96898, (bstring)"Hawaii", 0, 0);
    USCode[48] = zipstruct_create(97001, 97920, (bstring)"Oregon", 0, 0);
    USCode[49] = zipstruct_create(98001, 99403, (bstring)"Washington", 0, 0);
    USCode[50] = zipstruct_create(99501, 99950, (bstring)"Alaska", 0, 0);

    for(int i = 0; i < 51; i++) {
        check(USCode[i], "Failed to create zip decoder");
    }

    return 0;

  error:
    return -1;
}

// for the sort
int comparator(const void *v1, const void *v2)
{
    // cast void ptr to double ptr, then dereference; becomes a single ptr to ZipStruct
    const ZipStruct *p1 = *(ZipStruct **)v1; // qsort needs a void * to strt of array
    const ZipStruct *p2 = *(ZipStruct **)v2; // my array is an arr of ptrs
    // why using bstring? bstricmp threw a bus error; lib is unreliable
    return strcmp((char *)p1->state, (char *)p2->state); 
}

int decode_file(char *filename_read, char *filename_write)
{
    // initialize vars and files
    FILE *file = fopen(filename_read, "r"); 
    FILE *write_file = fopen(filename_write, "w");
    check(file, "Couldn't open zipcodes.txt.");
    check(write_file, "Couldn't open zipwrite.txt");

    check(USCode_create() > -1,"Couldn't create zip decoder. Bombing out.");
    char buff[20];
    char unknowns[100][20];
    int unknown_count = 0;

    // read zipcodes in txt file, cast to int, decode, record results
    while(1) {
        char *temp = fgets(buff, 20, (FILE *)file);
        if(temp == NULL) // means we're at EOF
            break;
        int zip = atoi(buff);
        int i = get_state(zip);
        if(i < 0) {
            snprintf(unknowns[unknown_count], 20, "%s", buff); // build not solved arr
            unknown_count++;
            continue;
        }
        USCode[i]->count++;
    }
    // sort results
    qsort(USCode, 51, sizeof(USCode[0]), comparator);

    // print and write results to disk
    rewind(write_file);
    char str[] = "\t   Visitor Stats\n"; // header
    printf("%s", str);
    int rc = fwrite(str, 1, sizeof(str), write_file);
    check(rc != 1, "Failed to write the header to zipwrite.");
    for(int i = 0; i < 51; i++) { // results
        if(USCode[i]->count > 0) {
            printf("%-20s\t\t%d\n", (char *)USCode[i]->state, USCode[i]->count);
            fprintf(write_file, "%-20s\t\t%d\n", 
                    (char *)USCode[i]->state, USCode[i]->count);
        }
    }
    fprintf(write_file, "\nUnknown         \t\t%d\n", unknown_count);
    printf("\nUnknown             \t\t%d\n", unknown_count);

    fprintf(write_file, "\n__________Unknown Zip Codes__________\n"); // footer
    for(int j = 0; j < unknown_count; j++) {
        fprintf(write_file, "%s", unknowns[j]); // zips not solved
    }

    // clean up
    fclose(file);
    fclose(write_file);
    USCode_clear();
    return 0;
  error:
    // TODO: check for memory and files to clean up
    return -1;
}

int decode_zip(int zipcount, char **zipcodes)
{
    check(USCode_create() > -1,"Couldn't create zip decoder. Bombing out.");
    for(int i = 0; i < zipcount; i++) {
        int zip = atoi(zipcodes[i]);
        int j = get_state(zip);
        if(j < 0) {
            printf("unknown\n");
        } else {
            printf("%s\n", (char *)USCode[j]->state);
        }
    } 
    USCode_clear();
    return 0;
  error:
    return -1;
}
