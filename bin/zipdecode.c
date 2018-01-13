#include "../src/lib/zipdecodelib.h"


int main(int argc, char *argv[])
{
    char *msg_usage = "\nUSAGE: zipdecode [flag] [arguments]\nFLAGS: -f [read filename]; -z [read zipcodes from CLI]\nARGUMENTS: [file in] [file out]; [zip codes]\nEXAMPLE: zipdecode -r zipcodes.txt zipwrite.txt; zipdecode -z 80128 22042";
    check(argc > 2, "%s", msg_usage);

    if(argv[1][1] == 'f') {
        check(argc == 4, "Wrong number of arguments.\n%s", msg_usage);
        return decode_file(argv[2], argv[3]); 
    } else if(argv[1][1] == 'z') {
        char *zip_array[argc - 2];
        for(int i = 0; i < argc - 2; i++) {
            zip_array[i] = argv[i + 2];
        }
        return decode_zip(argc - 2, zip_array); 
    } else {
        printf("Invalid flag entered. Use z or f.\n%s", msg_usage);
        return -1;
    }
  error:
    return -1;
}
