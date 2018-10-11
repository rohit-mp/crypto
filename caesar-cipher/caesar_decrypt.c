#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

void main(){
    FILE *input = fopen("caesar_cipher_text", "r");
    int size;
    fseek(input, 0, SEEK_END);
    size = ftell(input);
    fseek(input, 0, SEEK_SET);

    //calculating the frequency of all the letters
    int i;
    int *freq = calloc(26, sizeof(int));
    for(i=0; i<size; i++){
        char ch;
        fscanf(input, "%c", &ch);
        if(isalpha(ch)){
            freq[ch-97]++;
        }
    }
    fseek(input, 0, SEEK_SET);
    
    //finding character with highest frequency
    int max = freq[0];
    int maxIdx = 0;
    for(i=1;i<26;i++){
        if(freq[i]>=max){
            max=freq[i];
            maxIdx=i;
        }
    }

    int shift = maxIdx+97 - 'e';
    
    //shifting back
    FILE *output = fopen("caesar_decrypted_text","w");
    for(i=0; i<size; i++){
        char ch;
        fscanf(input, "%c", &ch);
        if(isalpha(ch)){
            ch-=shift;
            if(ch<97)
                ch+=26;
        }
        fprintf(output, "%c", ch);
    }
}

