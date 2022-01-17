# Lab 3 - Linked List
By Estelle Zheng
## Objective

The task is to create a new file, named `output_dictionary.txt` which contains the frequencies of each word met in the input text file. The `input_text.txt` is a non-empty text file, it is also assumed that each word is separated via whitespaces. So words like "isn't" is count as only 1 word.

Let us assume that each word has a length at most of 20 characters.

## ZIP File
The .zip file should contain 5 files:
- `list_lab.c` file where the code is implemented using Linked Lists,
- `lab3_array.c` file where the code is implemented using only arrays,
- `lab3_onlyStruct.c` file where the code is implemented using only data struct, but not linked lists.
- `readme.md` file,
- `input_text.txt` file where the input text is. It can be manually changed to test other words.

## Explanation on some parts (only list_lab.c)

- The `printFile` function helps the visualization.
- I assumed that the input text could only have 100 words, this can be increased if needed. ~~A 2D array was used to be able to both print and store its element.~~ **A linked list is used instead.**
- This implementation is not the most efficient, because creating 5 different functions to do this task is too much. The `comparing` function could be improved, but for the moment nothing better was found.

## Running the code 

Open the terminal and run this code normally:

```bash
gcc -o list_lab list_lab.c
./list_lab
```
