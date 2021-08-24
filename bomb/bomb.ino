void setup() {
  Serial.begin(9600);
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

    if (cuentaBomba >= 10 && cuentaBomba <= 60) {
      if (digitalRead(upPin) == HIGH) {
        cuentaBomba++;
      }
      if (digitalRead(downPin) == HIGH) {
        cuentaBomba--;
      }

      if (cuentaBomba == 9) {
        cuentaBomba = 10;
      };
      if (cuentaBomba == 61) {
        cuentaBomba = 60;
      };
    }

    Serial.print(cuentaBomba);
    Serial.println(" segundos");

    if (digitalRead(armPin) == HIGH) {
      estadoBomba = 1;
      Serial.println("BOMBA ARMADA");
    }
  }

  if (estadoBomba == 1) {
    cuentaBomba--;
    Serial.print("Quedan: ");
    Serial.println(cuentaBomba);

    if (cuentaBomba == 0) {
      Serial.println("BOMBA EXPLOTO");
      cuentaBomba = 20;
      estadoBomba = 0;
    }
  }

}

void loop() {
  bomb();
}
