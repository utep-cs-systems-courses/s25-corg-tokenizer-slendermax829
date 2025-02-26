#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main() 
{
    List *history = init_history();
    char word[100];
    
    while(1){
        fputs("$ ", stdout);
        fflush(stdout);

        fgets(word, sizeof(word), stdin);
        word[strlen(word) - 1] = '\0';

        if (strcmp(word, "q") == 0){
            goto end; // exits the program
        }
        else if(strcmp(word, "h") == 0){
            print_history(history);
            free_history(history);
            //prints the history of tokens
        }
        else if(strcmp(word, "!h") == 0){
            printf("Please type in a number to get the history of the token\n!");
            int id;

            scanf("%d", &id);
            char *str = get_history(history, id);
            printf("%s\n", str);
            free_history(history);
            //prints the history of the token of the number typed
        }
        
        else{
            char **tokens = tokenize(word);
            print_tokens(tokens);
            free_tokens(tokens);
            //prints the tokens just typed
        }
    }
    end:
    return 0;
}
