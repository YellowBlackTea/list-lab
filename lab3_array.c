#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main(){
    // file pointer
    FILE *file_ptr;

    /* 2D string to print + to store, 
        can store a maximum of 100 words and 
        each word can have a maximum of 20 characters. */
    char s[100][20]; 
    
    int pos = 0;            // position index
    int end_counter = 0;    // counter to know when it reachs the end of the file 
    int frequency = 1;      // counter for the frequency, set to 1
    
    /* read the content of the input file
        and print it to visualize it. */ 
    // open the input text in read mode
    file_ptr = fopen("input_text.txt", "r");
    if(file_ptr == NULL){
        printf("Error: file not found.\n");
        EXIT_FAILURE;
    }

    printf("---------------------------------------\n");
    // print the input file
    printf("The content of the input file is:\n");
    while(1){
        // if end of file, break and get out the loop
        if(feof(file_ptr)){
            break;
        }

        // store content of each string    
        fscanf(file_ptr,"%s", s[pos]);
        printf("%s ", s[pos]);
        end_counter++;
        pos++;

    }
    printf("\n");
    printf("---------------------------------------\n");

    // close the input file 
    fclose(file_ptr);
    
    /* write the output in the output text file 
        with each frequency. */
    // open the output txt file in write mode
    file_ptr = fopen("output_dictionnary.txt", "w");
    if(file_ptr == NULL){
        printf("Error: file not found.\n");
        EXIT_FAILURE;
    }

    // comparing
    for(int i = 0; i<end_counter; i++){
        for(int j = i+1; j<end_counter; j++){
            // if s[i] == s[j], then frequency++
            if(!(strcmp(s[i], s[j]))){
                if(i!=j){
                    frequency++;
                }

                // to remove the repeated string
                for(int k = j; k<end_counter; k++){
                    strcpy(s[k],s[k+1]);    // copy the next string to the previous one
                }
                end_counter--;
            }
        }

        // write each string and its frequency
        fprintf(file_ptr, "%s\t%d\n", s[i],frequency);
        frequency = 1;
    }

    // close the output file
    fclose(file_ptr);

    /* visualizing the output file */
    pos = 0;
    file_ptr = fopen("output_dictionnary.txt", "r");
    if(file_ptr == NULL){
        printf("Error: file not found.\n");
        EXIT_FAILURE;
    }
    printf("\n");
    printf("The new output text file has been created.\n");
    printf("---------------------------------------\n");
    printf("The content of the output file is:\n");
    while(1){
        // if end of file, break and get out the loop
        if(feof(file_ptr)){
            break;
        }

        // store content of each string    
        fscanf(file_ptr,"%s", s[pos]);
        if(pos%2==0){
            printf("%s\t", s[pos]);
        }
        else{
            printf("%s\n", s[pos]);
        }
            
        end_counter++;
        pos++;  

    }
    printf("\n");
    printf("---------------------------------------\n");

    fclose(file_ptr);

    return 0;
}