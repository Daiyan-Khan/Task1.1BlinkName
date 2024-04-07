void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

//a dash keeps light on for longer time
void dash() {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);                      // wait for one second
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}

//dot quickly turns on and off for short interval
void dot() {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for half a second
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}

// Dictionary for Morse Code
const char* MORSE_CODE_DICT[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

// Encode a given string into Morse Code
String EncodeMorse(String message) {
    String cipher = "";
    for (int i = 0; i < message.length(); i++) {
        char letter = toupper(message[i]);
        if (letter != ' ') {
            cipher += MORSE_CODE_DICT[letter - 'A'];
            cipher += " ";
        } else {
            // 1 space indicates different characters
            // and 2 indicates different words
            cipher += " ";
        }
    }
    return cipher;
}

// Blink the given dots and dashes
void BlinkMorse(String cipher) {
    for (int i = 0; i < cipher.length(); i++) {
        char symbol = cipher[i];
        if (symbol == '.') {
            dot();
        } else if (symbol == '-') {
            dash();
        } else if (symbol == ' ') {
            digitalWrite(LED_BUILTIN, LOW);
            delay(1500);
        }
    }
}

void loop() {
    // Example usage:
    String morseCode = EncodeMorse("Daiyan");
    BlinkMorse(morseCode);
    delay(2000); // Delay between words
}
