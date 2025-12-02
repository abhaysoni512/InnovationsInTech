#include <stdio.h>
#include <string.h>
size_t myStrlen(const char *s){
    int i = 0;
    size_t cnt =0;
    while (s[i]!='\0')
    {
        cnt++;
        i++;
    }
    return cnt;


}
char * my_Strncpy(char *dest,const char *src,size_t n){
    size_t i = 0;
    for(;i<n && src[i]!='\0';i++){
        dest[i]= src[i];
    }
    // if n is greater than strlen of src
    for(;i<n;i++){
        dest[i]='\0';
    }   

    return dest;
}

int myStrcmp(const char *s1,const char *s2){
    while (*s1==*s2)
    {
       if(*s1 == '\0') return 0;
       s1++;
       s2++;
    }
    return (*s1-*s2);
    
}

char * mystrcat(char *dest, const char *src) {
    int i= 0,j=0;
    while (dest[i]!='\0')
    {
        i++;
    }
    while(src[j]!='\0'){
        dest[i++] = src[j++];
    }
    return dest;
    
}

char * mystrncat(char *dest, const char *src, size_t n){
    int i=0,j=0;
    while (dest[i]!='\0')
    {
        i++;
    }
    while (src[j]!=0 && j<n)
    {
        dest[i++] = src[j++];
    }
    dest[i] = '\0';
    return dest;
    
}

int main(){
    char str[]="Abhay";
    printf("%lu \n",myStrlen(str));

    // char str1[10];
    // char str2[10];
    // printf("Enter str1 : ");
    // scanf("%s",str1);
    // printf("Enter str2 : ");
    // scanf("%s",str2);
    // printf("Lexicographical comparison between str1: %s and str2: %s = %d",str1,str2,myStrcmp(str1,str2));

    char str1[30]= "Abhay";
    char str2[5]= "Soni";

    getchar();
    printf("%s",mystrcat(str1,str2));

    getchar();
    printf("%s",mystrncat(str1,str2,3));


}