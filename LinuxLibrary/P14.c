#include <stdio.h>

int asciiBinaryToInt(char *s){
    int result = 0;
    while(*s){
        result*=2;
        if(*s == '1') result+=1;
        else if(!(*s == '0' || *s == '1')){
            printf("An invalid character was found\n");
            return result;
        }
        s++;
    }
    return result;
}

int asciiHEXToInt(char *s){
    int size = 0;
    char *t = s;
    while(*t){
        size++;
        t++;
    }
    int result = 0;
    int factor = 1;
    for(; s < s+size; size--){
        int num = *(s + size-1);
        if(num >= '0' && num <= '9') result+= (num -'0') * factor;
        else if(num >='a' && num <='f') result+= (num -'a' + 10) * factor;
        else if(num >='A' && num <='F') result+= (num -'A' + 10) * factor;
        else{
            printf("An invalid character was found\n");
            return result;
        }
        factor*=16;
    }
    return result;

}


