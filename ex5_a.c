#include <stdio.h>
#include <string.h>
#define MAX 10
void elim(char N,char p[][10],int c){
    char a[MAX][10],b[MAX][10];
    int ac=0,bc=0;
    printf("%c -> ",N);
    for(int i=0;i<c;i++)printf("%s%s",p[i],i<c-1?" | ":"");
    for(int i=0;i<c;i++){
        if(p[i][0]==N)strcpy(a[ac++],p[i]+1);
        else strcpy(b[bc++],p[i]);
    }
    if(ac==0){printf("\nNo left recursion.\n");return;}
    printf("\n\nAfter elimination:\n");
    printf("%c -> ",N);
    for(int i=0;i<bc;i++)printf("%s%c%s",strcmp(b[i],"ε")?b[i]:"","T'",i<bc-1?" | ":"");
    printf("\nT' -> ");
    for(int i=0;i<ac;i++)printf("%s%c%s",a[i],"T'",i<ac-1?" | ":"");
    printf(" | ε\n");
}
int main(){
    printf("=== Left Recursion Elimination ===\nGrammar:\nS -> Sa | bB | bD | ε\nB -> b\nD -> d\n\n");
    char S[][10]={"Sa","bB","bD","ε"};elim('S',S,4);
    printf("\nB -> b\nD -> d\n");
}
