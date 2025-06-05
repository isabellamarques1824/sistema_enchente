#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pinos do sensor ultrassônico
const int trigPin =  13;
const int echoPin = 12;

// LEDs
const int ledVerde = 8;
const int ledAmarelo =  9;
const int ledVermelho =  10;

// Buzzer
const int buzzer = 11;

// Variáveis para distância
long duracao;
float distancia;

void setup() {
  // Inicializa LCD
  lcd.init();
  lcd.backlight();
  
  // Pinos do sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Pinos dos LEDs
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  // Buzzer
  pinMode(buzzer, OUTPUT);

  // Mensagem inicial
  lcd.setCursor(0, 0);
  lcd.print(" HydroSafe Tech ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Mede a distância (altura da água)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duracao = pulseIn(echoPin, HIGH);
  distancia = duracao * 0.034 / 2; // cm

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Altura: ");
  lcd.print(distancia);
  lcd.print("cm");

  // Lógica de risco
  if (distancia > 100) {
    // Risco Baixo
    lcd.setCursor(0, 1);
    lcd.print("Risco: Baixo   ");
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else if (distancia > 50 && distancia <= 100) {
    // Risco Moderado
    lcd.setCursor(0, 1);
    lcd.print("Risco: Moderado");
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else {
    // Risco Crítico
    lcd.setCursor(0, 1);
    lcd.print("Risco: CRITICO!");
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 1000); // Liga buzzer com som
  }

  delay(2000);
  noTone(buzzer); // Desliga buzzer entre ciclos
}
