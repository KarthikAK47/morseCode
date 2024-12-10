#include <stdio.h>
#include <ctype.h>

const char *morseCode[] = {
        /*A*/".-",      /*B*/"-...",    /*C*/"-.-.",   /*D*/"-..",   /*E*/".",  
       /*F*/"..-.",    /*G*/"--.",     /*H*/ "....",  /*I*/"..",    /*J*/ ".---",
      /*K*/"-.-",     /*L*/".-.."     /*M*/, "--",   /*N*/"-.",    /*O*/"---",
     /*P*/".--.",    /*Q*/"--.-",    /*R*/".-.",    /*S*/"...",   /*T*/"-", 
    /*U*/"..-",     /*V*/"...-",    /*W*/".--",    /*X*/"-..-",  /*Y*/"-.--",   /*Z*/"--..", 

     /*0*/".----",   /*1*/"..---",  /*2*/"...--",  /*3*/"....-",  /*4*/".....", 
    /*5*/"-....",   /*6*/"--...",  /*7*/"---..",  /*8*/"----.",  /*8*/"-----"
};

void textToMorse(const char *inputText) {
    for (int i = 0; inputText[i] != '\0'; i++) 
    {
        char ch = toupper(inputText[i]); 

        if (ch >= 'A' && ch <= 'Z') 
            {
            printf("%s ", morseCode[ch - 'A']);
            } 
        else if (ch >= '0' && ch <= '9') 
            {
            printf("%s ", morseCode[ch - '0' + 26]);
            } 
        else if (ch == ' ') 
            {
            printf("/ ");
            }
    }
    printf("\n");
}

int main() {
    char inputText[100];

    printf("Enter text to convert to Morse code: ");
    fgets(inputText, sizeof(inputText), stdin);

    textToMorse(inputText);

    return 0;
}
