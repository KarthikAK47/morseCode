#include <stdio.h>
#include <ctype.h>
#include <windows.h>

typedef struct {
    char character;
    const char *morseCode;
} MorseCodeMap;

MorseCodeMap morseCodeDict[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, 
    {'8', "---.."}, {'9', "----."}, {'0', "-----"},
    {' ', "/"}
};

void playSound(char morseChar) {
    if (morseChar == '.') {
        Beep(1000, 200); 
    } else if (morseChar == '-') {
        Beep(1000, 600); 
    } else if (morseChar == ' ') {
        Sleep(200);
    }
}

const char* charToMorse(char ch) {
    for (int i = 0; i < sizeof(morseCodeDict) / sizeof(morseCodeDict[0]); i++) {
        if (toupper(ch) == morseCodeDict[i].character) {
            return morseCodeDict[i].morseCode;
        }
    }
    return ""; 
}

void textToMorse(const char *inputText) {
    for (int i = 0; inputText[i] != '\0'; i++) {
        const char* morse = charToMorse(inputText[i]);
        if (morse[0] != '\0') {
            printf("%s ", morse); 
            for (int j = 0; morse[j] != '\0'; j++) {
                playSound(morse[j]); 
            }
            Sleep(400); 
        } else {
            printf("! ");
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
