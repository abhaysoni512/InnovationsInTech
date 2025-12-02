#include <string.h>
#include <stdio.h>

char *mystrtok(char *str, const char* delimiters){
    // declare next_token and assign str if not null
    static char *next_tokens = NULL;
    if(str!=NULL){
        next_tokens = str;
    }

    // check we have next_token or not
    if(next_tokens=NULL){
        return NULL;   //means no token left
    }

    // escape leading tokens
    char *token_start = next_tokens;
    while(*next_tokens && strchr(delimiters,*token_start)){
        token_start++;
    }

    // check by skipping we may reach till end
    if (*token_start == '\0') {
        next_tokens = NULL;
        return NULL;
    }

    // move token to end of string
    char *token_end = token_start;
    while(*token_end && strchr(delimiters,*token_end)){
        token_end++;
    }


    // now if we got next delimiter
    if (*token_end) {
        *token_end = '\0';
        next_tokens = token_end + 1;
    } else {
        next_tokens = NULL;
}


}
int main(){
    char str[] = "...why?I;am?feeling;exicited";
    char tokens[] = ".?;";
    char *t;
    t = strtok(str,tokens);
    
    while (t!=NULL)
    {
        printf("%s ",t);
        t = strtok(NULL,tokens);
    }
    
    printf("\n------%s",str);

    char str[] = "...why?I;am?feeling;exicited";

    mystrtok(str);
    return 0;
}