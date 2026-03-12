#include<stdio.h>
#include<string.h>
int main(){
char f[10][20],p[10][20],fi[20][20],fo[20][20];
int a=0,e,i,t,b,c,n,k,l=0,j,s,m,x;

printf("Enter the no. of nonterminals\n");
scanf("%d",&n);
printf("Enter the productions in a grammar\n");
for(i=0;i<n;i++)scanf("%s",p[i]);
for(i=0;i<n;i++)fo[i][0]='\0';

for(s=0;s<n;s++){
for(i=0;i<n;i++){
j=3;l=0;a=0;
L:
if(!((p[i][j]>64)&&(p[i][j]<91))){
for(m=0;m<l;m++)if(fi[i][m]==p[i][j])goto S1;
fi[i][l]=p[i][j];l++;
S1:j++;
}else{
if(s>0){
while(p[i][j]!=p[a][0])a++;
b=0;
while(fi[a][b]!='\0'){
for(m=0;m<l;m++)if(fi[i][m]==fi[a][b])goto S2;
fi[i][l]=fi[a][b];l++;
S2:b++;
}}}
while(p[i][j]!='\0'){
if(p[i][j]=='|'){j++;goto L;}
j++;
}
fi[i][l]='\0';
}}

printf("First\n");
for(i=0;i<n;i++)printf("FIRS[%c]=%s\n",p[i][0],fi[i]);

fo[0][0]='$';
for(i=0;i<n;i++){
k=0;j=3;
if(i==0)l=1;else l=0;
K1:
while((p[i][0]!=p[k][j])&&(k<n)){
if(p[k][j]=='\0'){k++;j=2;}
j++;
}
j++;
if(p[i][0]==p[k][j-1]){
if((p[k][j]!='|')&&(p[k][j]!='\0')){
a=0;
if(!((p[k][j]>64)&&(p[k][j]<91))){
for(m=0;m<l;m++)if(fo[i][m]==p[k][j])goto Q3;
fo[i][l]=p[k][j];l++;
Q3:;
}else{
while(p[k][j]!=p[a][0])a++;
x=0;
while(fi[a][x]!='\0'){
if(fi[a][x]!='@'){
for(m=0;m<l;m++)if(fo[i][m]==fi[a][x])goto Q2;
fo[i][l]=fi[a][x];l++;
}else e=1;
Q2:x++;
}
if(e==1){e=0;goto A1;}
}}
else{
A1:c=0;a=0;
while(p[k][0]!=p[a][0])a++;
while((fo[a][c]!='\0')&&(p[a][0]!=p[i][0])){
for(m=0;m<l;m++)if(fo[i][m]==fo[a][c])goto Q1;
fo[i][l]=fo[a][c];l++;
Q1:c++;
}}
goto K1;
}
fo[i][l]='\0';
}

printf("Follow\n");
for(i=0;i<n;i++)printf("FOLLOW[%c]=%s\n",p[i][0],fo[i]);

printf("\n");
s=0;
for(i=0;i<n;i++){
j=3;
while(p[i][j]!='\0'){
if((p[i][j-1]=='|')||(j==3)){
for(x=0;x<=2;x++)f[s][x]=p[i][x];
t=j;
for(x=3;((p[i][j]!='|')&&(p[i][j]!='\0'));x++){f[s][x]=p[i][j];j++;}
f[s][x]='\0';

if(p[i][t]=='@'){
b=0;a=0;
while(p[a][0]!=p[i][0])a++;
while(fo[a][b]!='\0'){
printf("M[%c,%c]=%s\n",p[i][0],fo[a][b],f[s]);
b++;
}}
else if(!((p[i][t]>64)&&(p[i][t]<91)))
printf("M[%c,%c]=%s\n",p[i][0],p[i][t],f[s]);
else{
b=0;a=0;
while(p[a][0]!=p[i][3])a++;
while(fi[a][b]!='\0'){
printf("M[%c,%c]=%s\n",p[i][0],fi[a][b],f[s]);
b++;
}}
s++;
}
if(p[i][j]=='|')j++;
}}
}
