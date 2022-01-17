#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

/* List has a data (a word of max 20 characters),
    and its frequency. */
struct list{
    char word[20];
    int frequency;
};


int main(){
    // file pointer
    FILE *file_ptr;
    
    // creating a string array of structures
    struct list s[100];     // it can store a maximum of 100 words

    int pos = 0;            // position index
    int end_counter = 0;    // counter to know when it reaches the end of the text
    
    /* read the content of the input file
        and print it to visualize it. */ 
    
    // open the input text in read mode
    file_ptr = fopen("input_text.txt", "r");
    if(file_ptr == NULL){
        printf("Error: file not found.\n");
        EXIT_FAILURE;
    }

    printf("---------------------------------------\n");
    // print the input file, not required but will help visualizing
    printf("The content of the input file is:\n");
    while(1){
        // if end of file, break and get out the loop
        if(feof(file_ptr)){
            break;
        }

        // read and store content of each string
        fscanf(file_ptr,"%s", s[pos].word);
        printf("%s ", s[pos].word);
        pos++;
        end_counter++;

    }
    printf("\n\n");
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
        s[i].frequency = 1;                         // the word appears at least once
        for(int j = i+1; j<end_counter; j++){
            // if s[i] == s[j], then frequency++
            if(!(strcmp(s[i].word, s[j].word))){
                if(i!=j){
                    s[i].frequency++;
                }

                // to remove the repeated string
                for(int k = j; k<end_counter; k++){
                    strcpy(s[k].word,s[k+1].word);    // copy the next string to the previous one
                }
                end_counter--;
            }
        }

        // write each string and its frequency
        fprintf(file_ptr, "%s\t%d\n", s[i].word,s[i].frequency);
    }

    // close the output file
    fclose(file_ptr);
    printf("The new output text file has been created.\n");


    /*  *********************************************
        ****** Everything below can be deleted. *****
        Only here to help visualizing the ouput file.
        ********************************************* */

    /* visualizing the output file */
    pos = 0;

    file_ptr = fopen("output_dictionnary.txt", "r");
    if(file_ptr == NULL){
        printf("Error: file not found.\n");
        EXIT_FAILURE;
    }
    printf("The content of the output file is:\n");
    while(1){
        // if end of file, break and get out the loop
        if(feof(file_ptr)){
            break;
        }

        // read and store content of each string    
        fscanf(file_ptr,"%s", s[pos].word);
        if(pos%2==0){
            printf("%s\t", s[pos].word);
        }
        else{
            printf("%s\n", s[pos].word);
        }
        
        pos++;  

    }
    printf("\n");
    printf("---------------------------------------\n");
    fclose(file_ptr);

    return 0;
}