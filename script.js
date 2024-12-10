const morseCodeDict = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 'I': '..',
    'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.',
    'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..',
    '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....', '7': '--...', '8': '---..',
    '9': '----.', '0': '-----', ' ': '/'
};


let enableVibration = false;
let enableSound = false;

function textToMorse(inputText) {
    return inputText.toUpperCase().split('').map(char => morseCodeDict[char] || '').join(' ');
}

function vibrateMorseCode(morseCode) {
    for (let i = 0; i < morseCode.length; i++) {
        if (morseCode[i] === '.') {
            navigator.vibrate(150);  
        } else if (morseCode[i] === '-') {
            navigator.vibrate(300);  
        } else if (morseCode[i] === ' ') {
            navigator.vibrate(500);  
        }
    }
}

function playMorseCodeSound(morseCode) {
    const dotSound = new Audio('sound/dot.mp3'); 
    const dashSound = new Audio('sound/dash.mp3');

    let currentTime = 0;

    for (let i = 0; i < morseCode.length; i++) {
        setTimeout(() => {
            if (morseCode[i] === '.') {
                dotSound.play(); 
            } else if (morseCode[i] === '-') {
                dashSound.play(); 
            }
        }, currentTime);
        
        
        if (morseCode[i] === '.') {
            currentTime += 500; 
        } else if (morseCode[i] === '-') {
            currentTime += 1000; 
        } else if (morseCode[i] === ' ') {
            currentTime += 1500; 
        }
    }
}
    

document.getElementById('convertButton').addEventListener('click', function() {
    const inputText = document.getElementById('textInput').value;
    const morseCode = textToMorse(inputText);
    
    document.getElementById('output').innerText = morseCode;
    
    if (enableVibration) {
        vibrateMorseCode(morseCode);
    }

    if (enableSound) {
        playMorseCodeSound(morseCode);
    }
});

document.getElementById('clearButton').addEventListener('click', function() {
    document.getElementById('textInput').value = '';
    document.getElementById('output').innerText = '';
});

document.getElementById('enableVibration').addEventListener('change', function(event) {
    enableVibration = event.target.checked;
});

document.getElementById('enableSound').addEventListener('change', function(event) {
    enableSound = event.target.checked;
});

document.addEventListener('keydown', function(event) {
    if (event.key === 'ArrowUp') {
        document.getElementById('textInput').value += '.';
    } else if (event.key === 'ArrowDown') {
        document.getElementById('textInput').value += '-';
    }
});
