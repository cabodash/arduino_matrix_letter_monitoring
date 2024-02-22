#include "LedControl.h"

LedControl lc0 = LedControl(11, 13, 10, 1);
LedControl lc1 = LedControl(11, 13, 10, 2);
LedControl lc2 = LedControl(11, 13, 10, 3);
LedControl lc3 = LedControl(11, 13, 10, 4);

struct Character {
  String letter;
  byte data[8];
};
Character characters[] = {
  { "A", { B00111110, B01111110, B11001000, B11001000, B01111110, B00111110, B00000000, B00000000 } },
  { "B", { B10000010, B11111110, B11111110, B10010010, B10010010, B11111110, B01101100, B00000000 } },
  { "C", { B00111000, B01111100, B11000110, B10000010, B10000010, B11000110, B01000100, B00000000 } },
  { "D", { B10000010, B11111110, B11111110, B10000010, B11000110, B01111100, B00111000, B00000000 } },
  { "E", { B10000010, B11111110, B11111110, B10010010, B10111010, B10000010, B11000110, B00000000 } },
  { "F", { B10000010, B11111110, B11111110, B10010010, B10111000, B10000000, B11000000, B00000000 } },
  { "G", { B00111000, B01111100, B11000110, B10000010, B10001010, B11001110, B01001110, B00000000 } },
  { "H", { B11111110, B11111110, B00010000, B00010000, B11111110, B11111110, B00000000, B00000000 } },
  { "I", { B00000000, B10000010, B11111110, B11111110, B10000010, B00000000, B00000000, B00000000 } },
  { "J", { B00001100, B00001110, B00000010, B10000010, B11111110, B11111100, B10000000, B00000000 } },
  { "K", { B10000010, B11111110, B11111110, B00010000, B00111000, B11101110, B11000110, B00000000 } },
  { "L", { B10000010, B11111110, B11111110, B10000010, B00000010, B00000110, B00001110, B00000000 } },
  { "M", { B11111110, B11111110, B01110000, B00111000, B01110000, B11111110, B11111110, B00000000 } },
  { "N", { B11111110, B11111110, B01100000, B00110000, B00011000, B11111110, B11111110, B00000000 } },
  { "O", { B00111000, B01111100, B11000110, B10000010, B11000110, B01111100, B00111000, B00000000 } },
  { "P", { B10000010, B11111110, B11111110, B10010010, B10010000, B11110000, B01100000, B00000000 } },
  { "Q", { B01111000, B11111100, B10000100, B10001110, B11111110, B01111010, B00000000, B00000000 } },
  { "R", { B10000010, B11111110, B11111110, B10010000, B10011000, B11111110, B01100110, B00000000 } },
  { "S", { B01100100, B11110110, B10110010, B10011010, B11001110, B01001100, B00000000, B00000000 } },
  { "T", { B11000000, B10000010, B11111110, B11111110, B10000010, B11000000, B00000000, B00000000 } },
  { "U", { B11111110, B11111110, B00000010, B00000010, B11111110, B11111110, B00000000, B00000000 } },
  { "V", { B11111000, B11111100, B00000110, B00000110, B11111100, B11111000, B00000000, B00000000 } },
  { "W", { B11111110, B11111110, B00001100, B00011000, B00001100, B11111110, B11111110, B00000000 } },
  { "X", { B11000010, B11100110, B00111100, B00011000, B00111100, B11100110, B11000010, B00000000 } },
  { "Y", { B11100000, B11110010, B00011110, B00011110, B11110010, B11100000, B00000000, B00000000 } },
  { "Z", { B11100010, B11000110, B10001110, B10011010, B10110010, B11100110, B11001110, B00000000 } },
  { "a", { B00000100, B00101110, B00101010, B00101010, B00111100, B00011110, B00000010, B00000000 } },
  { "b", { B10000010, B11111110, B11111100, B00010010, B00010010, B00011110, B00001100, B00000000 } },
  { "c", { B00011100, B00111110, B00100010, B00100010, B00110110, B00010100, B00000000, B00000000 } },
  { "d", { B00001100, B00011110, B00010010, B10010010, B11111100, B11111110, B00000010, B00000000 } },
  { "e", { B00011100, B00111110, B00101010, B00101010, B00111010, B00011000, B00000000, B00000000 } },
  { "f", { B00010010, B01111110, B11111110, B10010010, B11000000, B01000000, B00000000, B00000000 } },
  { "g", { B00011001, B00111101, B00100101, B00100101, B00011111, B00111110, B00100000, B00000000 } },
  { "h", { B10000010, B11111110, B11111110, B00010000, B00100000, B00111110, B00011110, B00000000 } },
  { "i", { B00000000, B00100010, B10111110, B10111110, B00000010, B00000000, B00000000, B00000000 } },
  { "j", { B00000110, B00000111, B00000001, B00000001, B10111111, B10111110, B00000000, B00000000 } },
  { "k", { B10000010, B11111110, B11111110, B00001000, B00011100, B00110110, B00100010, B00000000 } },
  { "l", { B00000000, B10000010, B11111110, B11111110, B00000010, B00000000, B00000000, B00000000 } },
  { "m", { B00111110, B00111110, B00011000, B00011100, B00111000, B00111110, B00011110, B00000000 } },
  { "n", { B00111110, B00111110, B00100000, B00100000, B00111110, B00011110, B00000000, B00000000 } },
  { "o", { B00011100, B00111110, B00100010, B00100010, B00111110, B00011100, B00000000, B00000000 } },
  { "p", { B00100001, B00111111, B00011111, B00100101, B00100100, B00111100, B00011000, B00000000 } },
  { "q", { B00011000, B00111100, B00100100, B00100101, B00011111, B00111111, B00100001, B00000000 } },
  { "r", { B00100010, B00111110, B00011110, B00110010, B00100000, B00111000, B00011000, B00000000 } },
  { "s", { B00010010, B00111010, B00101010, B00101010, B00101110, B00100100, B00000000, B00000000 } },
  { "t", { B00000000, B00100000, B01111100, B11111110, B00100010, B00100100, B00000000, B00000000 } },
  { "u", { B00111100, B00111110, B00000010, B00000010, B00111100, B00111110, B00000010, B00000000 } },
  { "v", { B00111000, B00111100, B00000110, B00000110, B00111100, B00111000, B00000000, B00000000 } },
  { "w", { B00111100, B00111110, B00001110, B00011100, B00001110, B00111110, B00111100, B00000000 } },
  { "x", { B00100010, B00110110, B00011100, B00001000, B00011100, B00110110, B00100010, B00000000 } },
  { "y", { B00111001, B00111101, B00000101, B00000101, B00111111, B00111110, B00000000, B00000000 } },
  { "z", { B00110010, B00100110, B00101110, B00111010, B00110010, B00100110, B00000000, B00000000 } }
};

byte matrix[32] = { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
                    B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
                    B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
                    B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000 };



//Calcula el ancho de una letra
int widthLetter(byte letter[8]) {
  int width = 0;
  for (int i = 0; i < 8; i++) {
    if (letter[i] != B00000000) {
      width++;
    }
  }
  return width;
}

//transforma una letra quitando los espacios
// byte removeEmptyColumns(byte letter[8]) {
//   int width = widthLetter(letter);
//   byte newLetter[width];
//   int index = 0;
//   for (int i = 0; i < 8; i++) {
//     if (letter[i] != B00000000) {
//       newLetter[index] = letter[i];
//       index++;
//     }
//   }
//   return newLetter;
// }

//Hace espacio para la letra recibida (La letra recibida debe ser sin formatear)
void spaceToNewLetter(byte letter[8]) {
  int width = widthLetter(letter) +1;
  for (int i = width; i < sizeof(matrix); i++) {
    matrix[i-width] = matrix[i];
  }
  matrix[31 - widthLetter(letter)] = B00000000;
}

//añade la letra a la lista de la matriz
void addLetterToMatrix(byte letter[8]){
  int width = widthLetter(letter);
  Serial.print("width: ");
  Serial.print(width);
  Serial.println();


  int indexMatrix = sizeof(matrix)-1;
  for(int i = 7; i >=0; i--){
    Serial.print(letter[i], BIN);
    Serial.print(" ");
    if(letter[i] != B00000000){
      matrix[indexMatrix] = letter[i];
      indexMatrix --;
    }
  }
  Serial.println();
}

//Añade el espacio a la lista de la matriz
void addSpace(){
  for (int i = 3; i < sizeof(matrix); i++) {
    matrix[i-3] = matrix[i];
  }
  matrix[31] = B00000000;
  matrix[30] = B00000000;
  matrix[29] = B00000000;
}

// Añade la letra recibida a la variable de la matrix
void addLetter(char receivedChar) {
  for (int i = sizeof(characters) / sizeof(Character) - 1; i >= 0; i--) {
    if (characters[i].letter == String(receivedChar)) {
      spaceToNewLetter(characters[i].data);
      addLetterToMatrix(characters[i].data);
      break;
    }
  }
}

// Actualiza las cuatro matrices en serie
void updateMatrix() {
  int nMatrix = 0;
  lc3.setColumn(0, 7, matrix[31]);
  lc3.setColumn(0, 6, matrix[30]);
  lc3.setColumn(0, 5, matrix[29]);
  lc3.setColumn(0, 4, matrix[28]);
  lc3.setColumn(0, 3, matrix[27]);
  lc3.setColumn(0, 2, matrix[26]);
  lc3.setColumn(0, 1, matrix[25]);
  lc3.setColumn(0, 0, matrix[24]);

  lc3.setColumn(1, 7, matrix[23]);
  lc3.setColumn(1, 6, matrix[22]);
  lc3.setColumn(1, 5, matrix[21]);
  lc3.setColumn(1, 4, matrix[20]);
  lc3.setColumn(1, 3, matrix[19]);
  lc3.setColumn(1, 2, matrix[18]);
  lc3.setColumn(1, 1, matrix[17]);
  lc3.setColumn(1, 0, matrix[16]);

  lc3.setColumn(2, 7, matrix[15]);
  lc3.setColumn(2, 6, matrix[14]);
  lc3.setColumn(2, 5, matrix[13]);
  lc3.setColumn(2, 4, matrix[12]);
  lc3.setColumn(2, 3, matrix[11]);
  lc3.setColumn(2, 2, matrix[10]);
  lc3.setColumn(2, 1, matrix[9]);
  lc3.setColumn(2, 0, matrix[8]);

  lc3.setColumn(3, 7, matrix[7]);
  lc3.setColumn(3, 6, matrix[6]);
  lc3.setColumn(3, 5, matrix[5]);
  lc3.setColumn(3, 4, matrix[4]);
  lc3.setColumn(3, 3, matrix[3]);
  lc3.setColumn(3, 2, matrix[2]);
  lc3.setColumn(3, 1, matrix[1]);
  lc3.setColumn(3, 0, matrix[0]);
  // for (int i = 0; i < 32; i++) {
  //   Serial.print(matrix[i], BIN);
  //   Serial.print(" ");
  // }
  // Serial.println();
}

// Mueve las columnas a la izquierda
unsigned long lastUpdateTime = 0;  // Variable para realizar un seguimiento del tiempo

void scroll() {
  // Verifica si ha pasado medio segundo desde la última actualización
  if (millis() - lastUpdateTime >= 200) {
    // Verifica si la columna 0 no es igual a B00000000
    if (matrix[0] == B00000000) {
      // Mueve todas las columnas una posición hacia la izquierda
      for (int i = 0; i < 31; i++) {
        matrix[i] = matrix[i + 1];
      }
      // Establece la última columna en B00000000
      matrix[31] = B00000000;
      updateMatrix();
    }
    // Actualiza la última vez que se actualizó la matrix
    lastUpdateTime = millis();
  }
}

// Mueve hacia la izquierda la letra actual y pinta la nueva
void moveToLeft(char receivedChar) {
  int letterWidth = 0;
  for (int i = sizeof(characters) / sizeof(Character) - 1; i > 0; i--) {
    if (String(receivedChar) == characters[0].letter) {
      // Mueve el array de matrix una posición a la izquierda y añade en la última posición (31) un B00000000
      letterWidth++;
    } else if (characters[i].letter == String(receivedChar)) {
      // Añade las últimas 8 columnas de la letra a la variable matrix
      for (int j = 0; j < 8; j++) {
        if (characters[i].data[j] != B00000000) {
          letterWidth++;
        }
      }
      letterWidth++;
      break;
    }
  }

  Serial.print("Ancho de la letra: ");
  Serial.println(letterWidth);
  // Hace espacio para la nueva letra
  for (int i = 0; i < (31 - letterWidth); i++) {
    matrix[i] = matrix[i + letterWidth];
  }
  matrix[31] = B00000000;
  // Deja una columna de B00000000 entre letra y letra
  //   for (int i = letterWidth - 1; i >= 0; i--) {
  //     matrix[i] = B00000000;
  //   }
  // Pinta la nueva letra
  addLetter(receivedChar);
}






void setup() {
  Serial.begin(2000000);
  lc0.shutdown(0, false);
  lc0.setIntensity(0, 8);
  lc0.clearDisplay(0);
}

void loop() {
  if (Serial.available()) {
    char receivedChar = Serial.read();
    if (isprint(receivedChar)) {
      Serial.print("comm: ");
      Serial.print(receivedChar);
      Serial.println();
      if(receivedChar == 32){
        Serial.print("- Espacio");
        Serial.println();
        addSpace();
      }else{
       addLetter(receivedChar);
       Serial.print("- No espacio");
        Serial.println();
      }
      updateMatrix();
    }
  }
  // scroll();
}