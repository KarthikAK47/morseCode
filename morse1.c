#include <stdio.h>
#include <ctype.h>
#include <windows.h>

const char *morseCodeDict[] = {
    ".-",   "-...", "-.-.", "-..",   ".",    "..-.", "--.",   "....",  "..",    ".---", 
    "-.-",  ".-..", "--",   "-.",    "---",  ".--.", "--.-",  ".-.",  "...",   "-", 
    "..-",  "...-", ".--",  "-..-",  "-.--", "--..", 
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

void playSound(const char *morseCode) {
    for (int i = 0; morseCode[i] != '\0'; i++) {
        if (morseCode[i] == '.') {
            Beep(800, 200);
        } else if (morseCode[i] == '-') {
            Beep(800, 600);
        } else if (morseCode[i] == ' ') {
            Sleep(300);
        }
        Sleep(200);
    }
}

void textToMorse(const char *inputText) {
    for (int i = 0; inputText[i] != '\0'; i++) {
        char ch = toupper(inputText[i]);
        if (ch >= 'A' && ch <= 'Z') {
            printf("%s ", morseCodeDict[ch - 'A']);
            playSound(morseCodeDict[ch - 'A']);
        } else if (ch >= '0' && ch <= '9') {
            printf("%s ", morseCodeDict[ch - '0' + 26]);
            playSound(morseCodeDict[ch - '0' + 26]);
        } else if (ch == ' ') {
            printf("/ ");
            Sleep(500);
        }
    }
    printf("\n");
}

int main() {
    char inputText[100];

    printf("enter text to convert to Morse code: ");
    fgets(inputText, sizeof(inputText), stdin);

    textToMorse(inputText);

    return 0;
}
