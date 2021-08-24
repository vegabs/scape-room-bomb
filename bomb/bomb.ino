void setup() {

}

void bomb() {

  static const uint8_t upPin = 2;
  static const uint8_t downPin = 3;
  static const uint8_t armPin = 4;

  static uint8_t estadoBomba = 0; // 0: desarmada, 1: armada

  static const uint8_t intervalo = 1000;
  static uint8_t previousMillis = 0;
  static uint8_t cuentaBomba = 20;

  if (estadoBomba == 0) {

    if (digitalRead(upPin) == HIGH) {
      cuentaBomba++;
    }

    if (digitalRead(downPin) == HIGH) {
      cuentaBomba--;
    }

    Serial.print(cuentaBomba);
    Serial.println(" segundos");
    
    if (digitalRead(armPin) == HIGH) {
      estadoBomba = 1;
      Serial.println("BOMBA ARMADA");
    }

  }


}

void loop() {
  bomb();
}
