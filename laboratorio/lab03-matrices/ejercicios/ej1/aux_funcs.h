#ifndef _AUX_FUNCS_
#define _AUX_FUNCS_

char *parse_filepath(int argc, char *argv[]);

unsigned int data_from_file(const char *path,
                             unsigned int indexes[],
                             char letters[],
                             unsigned int max_size);
                    
void sort(char letters[], unsigned int indexes[], char sorted[], unsigned int lenght);

#endif