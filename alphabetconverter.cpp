#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int t = 0;
    int visited[26] = {0};
    char X[101];
    int n;
  
    FILE *infile = fopen("testdata.in", "r"); //open file//
        fscanf(infile, "%d", &t);
        for(int i = 0; i < t; i++){
            fscanf(infile, "%s", X); //scanning the string//
            fgetc(infile);
            fscanf(infile, "%d", &n); //getting no of process//
            for(int j = 0; j < n; j++){
                char from[2];
                char to[2];
                fscanf(infile, "%s %s", from, to); //getting from char  //getting to char//
                fgetc(infile);
                char fromch = from[0]; //char from//
                char toch = to[0]; //char to//
                if (!visited[fromch - 'A']){ //if block//
                    visited[fromch - 'A'] = 1; //set visited to 1//
                    for (int j = 0; j < strlen(X); j++){
                        if (X[j] == fromch){ //if value is equal to from char//
                            X[j] = toch; //set value to to char//
                        }
                    } 
                }
            }
            int frequency[26] = {0}; //frequency
            for (int k = 0; k < strlen(X); k++){
              frequency[X[k] - 'A']++; //increase frequency//
            }
            for (int k = 0; k < 26; k++){
                if (frequency[k]){ //if frequency is non zero//
                  printf("%c %d\n", 'A' + k, frequency[k]); //print char along with frequency//
                }
            }
        }
    fclose(infile); //close file//
    return 0;
}
