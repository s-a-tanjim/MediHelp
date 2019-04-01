#include<stdio.h>
#include<windows.h>
main()
{
    char word2[30];
    FILE *word_file2;
    word_file2=fopen("Symptoms2.txt","r");
    fscanf(word_file2,"%s",word2);

    //fscanf(word_file2,"%[^\n]", word2);
    //fscanf(word_file2,word2);
        printf("%s \n",word2);
    //fgets(word2,1000,word_file2);
    //fscanf(word_file2,"%[^\n]", word2);
    //printf("%s ",word2);
    //fscanf(word_file2,"%[^\n]", word2);
    //fgets(word2,1000,word_file2);
    //printf("%s ",word2);




}


