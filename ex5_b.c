#include <stdio.h>
#include <string.h>
#define MAX 10

int pre(char s1[],char s2[]){
    int i=0;
    while(s1[i]&&s2[i]&&s1[i]==s2[i])i++;
    return i;
}

void fact(char N,char p[][10],int c){
    printf("%c -> ",N);
    for(int i=0;i<c;i++)printf("%s%s",p[i],i<c-1?" | ":"");
    char com[10]="";int len=0;
    if(c){
        strcpy(com,p[0]);len=strlen(com);
        for(int i=1;i<c&&len;i++){
            int t=pre(com,p[i]);
            if(t<len){len=t;com[len]=0;}
        }
    }
    if(!len){printf("\nNo left factoring possible.\n");return;}
    printf("\n\nAfter factoring:\n%c -> %sT'\nT' -> ",N,com);
    int f=1;
    for(int i=0;i<c;i++){
        if(strncmp(p[i],com,len)==0){
            char r[10];strcpy(r,p[i]+len);
            printf("%s%s",strlen(r)?r:"ε",f?f=0,"":" | ");
        }
    }
    printf("\n");
}

int main(){
    printf("=== Left Factoring ===\nGrammar:\nS -> a | ab | abc | abcd\n\n");
    char p[][10]={"a","ab","abc","abcd"};fact('S',p,4);
}
