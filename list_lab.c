#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

/* List has a data (a word of max 20 characters),
    its frequency and a pointer to the next node. */
struct list{
    char data[20];
    int frequency;
    struct list *next;
};


// get the adress of the new word with its frequency
struct list *getNewWord(char *word){
    // creating a new list by allocating memory
    struct list *newWord = NULL;
    newWord = (struct list *) malloc(sizeof(struct list));

    // copy the word into the list
    strcpy(newWord->data, word);
    // add its frequency set to 0
    newWord->frequency = 0;
    newWord->next = NULL;

    // return the address of the new word
    return newWord;
}

// comparing each word of the list
// get the address of the word getting duplicate (return NULL if not found any duplicate words)
struct list *comparing(struct list *list, char *word){
    struct list *current = list;

    // if list is empty
    if(list == NULL){
        return NULL;
    }

    // if both words are not equal, check the next one (until reaching the last one)
    while(strcmp(current->data,word)){
        if(current->next == NULL){
            return NULL;
        }
        else{
            current = current->next;
        }
    }

    // return the address of the duplicate word
    return current;
}

// deleteting a word which is already in the list
void deleteWord(struct list *list){
    struct list *head = list;
    struct list *tail = NULL;
    struct list *tmp = NULL;

    tmp = head;

    // duplicate words found (i.e frequency = 0)
    while((tmp != NULL) && (tmp->frequency == 0)){
        head = head->next;
        free(tmp);
        return;
    }

    // searching for duplicate words
    while((tmp != NULL) && (tmp->frequency != 0)){
        tail = tmp;
        tmp = tmp->next;
    } 

    // if no duplicate words were found
    if(tmp == NULL){
        return;
    }

    // remove the link of the tmp node
    tail->next = tmp->next;

    // free the memory
    free(tmp);
}

// printing each word with its frequency to help visualizing the list
void printList(struct list *list){
    struct list *traversing = list;
    if(traversing == NULL){
        printf("list is empty\n");
    }
    // if list is not empty, loop printf
    while(traversing != NULL){
        printf("%s\t%d\n",traversing->data, traversing->frequency);
        traversing = traversing->next;
    }
}

// writing the output in the output file
void writeFile(FILE *file_ptr, struct list *list){
    // same code as the printList, only changing the printf to fprintf

    struct list *output = list;
    if(output == NULL){
        printf("Cannot write an empty list\n");
    }
    // if list is not empty, loop printf
    while(output != NULL){
        fprintf(file_ptr, "%s\t%d\n", output->data,output->frequency);
        output = output->next;
    }
}

int main(){
    // file pointers
    FILE *file_ptr;
    FILE *file_output_ptr;
    
    char s[100];            // array to read/save the input text file
    int end_counter = 1;    // counter to know when it reaches the end of the text

    // define 3 nodes 
    struct list *head = NULL;           // head = start pointer of the list
    struct list *added = NULL;          // added = current pointer of the list
    struct list *compare = NULL;        // compare = pointer to incremente the frequency

    // open the input text in read mode
    file_ptr = fopen("input_text.txt", "r");
    if(file_ptr == NULL){
        printf("Error: file not found.\n");
        EXIT_FAILURE;
    }
    
    // open the output txt file in write mode
    file_output_ptr = fopen("output_dictionnary.txt", "w");
    if(file_output_ptr == NULL){
        printf("Error: file not found.\n");
        EXIT_FAILURE;
    }

    printf("The content of the input file is:\n");
    while(1){
        if(feof(file_ptr)){
            break;
        }
        // read and store content of each word
        fscanf(file_ptr,"%s", s);
        printf("word %d: %s\n", end_counter, s);
        end_counter++;

        // add each word into a list
        if(head == NULL){
            head = getNewWord(s);
            if(head != NULL){
                added = head;
            }
        }
        else{
            added->next = getNewWord(s);
            if(added->next != NULL){
                added = added->next;
            }
        }

        // compare words of the list
        compare = comparing(head, s);
        if(compare != NULL){
            compare->frequency++;
        }
        else{
            compare = getNewWord(s);
        }
        

    }
    printf("\n");
    
    // deletes all the duplicate words (i.e frequency = 0)
    for(int i=0; i<end_counter;i++){
        deleteWord(head);
    }

    printf("---------------------------------------\n");
    writeFile(file_output_ptr,head);

    printf("The content of the output file is:\n");
    printList(head);
    printf("\n");

    fclose(file_ptr);
    fclose(file_output_ptr);


    free(head);
    return 0;
}