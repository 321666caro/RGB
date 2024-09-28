#define SWITCH_PIN 13

// Define  los pines de los LEDs
const int ledPins[3][3] = {
  {2, 3, 4},  // LED1 (Rojo, Azul, Verde)
  {5, 6, 7},  // LED2 (Rojo, Azul, Verde)
  {8, 9, 10}  // LED3 (Rojo, Azul, Verde)
};

void setup() {
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      pinMode(ledPins[i][j], OUTPUT);
    }
  }

  //  interruptor
  pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void setLedColors(int ledIndex, int r, int g, int b) {
  analogWrite(ledPins[ledIndex][0], r); // Rojo
  analogWrite(ledPins[ledIndex][1], g); // Azul
  analogWrite(ledPins[ledIndex][2], b); // Verde
}

void loop() {
  if (digitalRead(SWITCH_PIN) == LOW) { 
    setLedColors(0, 0, 0, 255); // Verde
    setLedColors(1, 255, 0, 0); // Rojo
    setLedColors(2, 255, 0, 0); // Rojo
    delay(1000);

    // Semáforo 2 en verde
    setLedColors(0, 255, 0, 0); // Rojo
    setLedColors(1, 0, 0, 255); // Verde
    setLedColors(2, 255, 0, 0); // Rojo
    delay(1000);

    // Semáforo 3 en verde
    setLedColors(0, 255, 0, 0); // Rojo
    setLedColors(1, 255, 0, 0); // Rojo
    setLedColors(2, 0, 0, 255); // Verde
    delay(1000);
  } else { // Si el interruptor está apagado
    for (int i = 0; i < 3; i++) {
      setLedColors(i, 255, 0, 255); // Amarillo
    }
    delay(500); // Encendido
    for (int i = 0; i < 3; i++) {
      setLedColors(i, 0, 0, 0); // Apagar
    }
    delay(500); // Apagado
  }
}

  
  