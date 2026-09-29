#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXP 100
#define BUFLEN 101
char *gems[]={"NONE","Garnet","Amethyst","Aquamarine","Diamond","Emerald","Pearl","Ruby","Peridot","Sapphire","Tourmaline","Topaz","Lapis",0};
char ponies[MAXP][BUFLEN];

int gemPriority(char *name){
    int i,j,k;
    char word[BUFLEN];
    for(i=0;name[i];i++)
        word[i]=tolower(name[i]);
    word[i]='\0';
    for(i=0;gems[i]!=0;i++){
        int len=strlen(gems[i]);
        for(j=0;word[j];j++)
        {
            k=0;
            while(word[j+k] && k<len && tolower(word[j+k])==tolower(gems[i][k]))
                k++;
            if(k==len&&(j==0||!isalpha(word[j-1]))&&(!word[j+k]||!isalpha(word[j+k])))
                return i;
        }
    }
    return 0;
}
int compare(char *a,char *b){
    int i=0;
    while(a[i]&&b[i]){
        char x=tolower(a[i]);
        char y=tolower(b[i]);
        if(x!=y)
            return x-y;
        i++;
    }
    return tolower(a[i])-tolower(b[i]);
}
int cmp(const void *a,const void *b){
    char *p1=(char *)a;
    char *p2=(char *)b;
    int g1=gemPriority(p1);
    int g2=gemPriority(p2);
    if(g1!=0&&g2==0)
        return -1;
    if(g1==0&&g2!=0)
        return 1;
    if(g1!=g2)
        return g2-g1;
    return compare(p1,p2);
}
int main(){
    int n=0;
    while(n<MAXP&&fgets(ponies[n],BUFLEN,stdin)){
        ponies[n][strcspn(ponies[n],"\n")]='\0';
        if(strcmp(ponies[n],"END")==0)
            break;
        n++;
    }
    qsort(ponies,n,sizeof(ponies[0]),cmp);
    for(int i=0;i<n;i++)
        printf("%s\n",ponies[i]);
    return 0;
}