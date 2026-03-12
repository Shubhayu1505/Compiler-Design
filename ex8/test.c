#include<stdio.h>
#include<string.h>

int isNT(char c){return c>='A'&&c<='Z';}

int main(){
char p[10][20],first[10][20]={0},follow[10][20]={0},prod[20][20];
int n,i,j,k,l,m,s=0,t,a,b,e=0;

printf("Enter the no. of nonterminals\n");
scanf("%d",&n);

printf("Enter the productions in a grammar\n");
for(i=0;i<n;i++)scanf("%s",p[i]);

for(k=0;k<n;k++)
for(i=0;i<n;i++){
for(j=3,l=0;p[i][j];j++){
if(p[i][j]=='|')continue;

if(!isNT(p[i][j])){
for(m=0;m<l;m++)if(first[i][m]==p[i][j])goto skip;
first[i][l++]=p[i][j];
skip: break;
}

else if(k){
for(a=0;a<n;a++)if(p[a][0]==p[i][j])break;
for(b=0;first[a][b];b++){
for(m=0;m<l;m++)if(first[i][m]==first[a][b])goto s2;
first[i][l++]=first[a][b];
s2:;
}
break;
}
}
first[i][l]=0;
}

printf("First\n");
for(i=0;i<n;i++)printf("FIRS[%c]=%s\n",p[i][0],first[i]);

follow[0][0]='$';
follow[0][1]='\0';

for(i=0;i<n;i++){
for(j=0;j<n;j++){
for(k=3;p[j][k];k++){

if(p[j][k]==p[i][0]){

if(!p[j][k+1]||p[j][k+1]=='|'){
for(a=0;p[j][0]!=p[a][0];a++);
for(b=0;follow[a][b];b++){
for(m=0;follow[i][m];m++)if(follow[i][m]==follow[a][b])goto f1;
follow[i][m]=follow[a][b];
follow[i][m+1]=0;
f1:;
}
}

else if(!isNT(p[j][k+1])){
for(m=0;follow[i][m];m++)if(follow[i][m]==p[j][k+1])goto f2;
follow[i][m]=p[j][k+1];
follow[i][m+1]=0;
f2:;
}

else{
for(a=0;p[a][0]!=p[j][k+1];a++);
for(b=0;first[a][b];b++){
if(first[a][b]=='@')continue;
for(m=0;follow[i][m];m++)if(follow[i][m]==first[a][b])goto f3;
follow[i][m]=first[a][b];
follow[i][m+1]=0;
f3:;
}
}

}
}
}
}

printf("Follow\n");
for(i=0;i<n;i++)printf("FOLLOW[%c]=%s\n",p[i][0],follow[i]);

printf("\n");

for(i=0;i<n;i++){
j=3;
while(p[i][j]){

if(j==3||p[i][j-1]=='|'){

for(k=0;k<3;k++)prod[s][k]=p[i][k];
t=j;

for(k=3;p[i][j]&&p[i][j]!='|';k++)
prod[s][k]=p[i][j++];

prod[s][k]=0;

if(!isNT(p[i][t]))
printf("M[%c,%c]=%s\n",p[i][0],p[i][t],prod[s]);

else{
for(a=0;p[a][0]!=p[i][t];a++);
for(b=0;first[a][b];b++)
printf("M[%c,%c]=%s\n",p[i][0],first[a][b],prod[s]);
}

s++;
}

if(p[i][j]=='|')j++;

}
}

return 0;
}
