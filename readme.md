# Lab 3 - Linked lists
By Estelle Zheng
## Objective

The task is to create a new file, named `output_dictionary.txt` which contains the frequencies of each word met in the input text file. The `input_text.txt` is a non-empty text file, it is also assumed that each word is separated via whitespaces. So words like "isn't" is count as 1 word.

Let us assume that each word has a length at most of 20 characters.

## ZIP File
The .zip file should contain:
- `list_lab.c` file where the code is implemented,
- `readme.md` file,
- `input_text.txt` file where the input text is. It can be manually changed to test other words.

## Explanation on some parts

- Some printf were added to help visualizing the input text file and the output text file. They can be removed since it was not required.
- I assumed that the input text could only have 100 words, this can be increased if needed. ~~A 2D array was used to be able to both print and store its element.~~ **String array of struct is used instead.**
- The interesting part on the code is the comparing part. I implemented it with two loops and I added another one to remove each duplicated word. It might have a better implementation, but for the moment I did not find anything.

## Running the code 

Open the terminal and run this code normally:

```bash
gcc -o list_lab list_lab.c
./list_lab
```
