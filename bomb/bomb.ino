void setup() {
  Serial.begin(9600);
}

void bomb() {

  static const uint8_t upPin = 2;
  static const uint8_t downPin = 3;
  static const uint8_t armPin = 4;

  static uint8_t estadoBomba = 0; // 0: desarmada, 1: armada

  static const uint32_t interval = 1000;
  static const uint32_t interval2 = 100;
  static uint32_t previousMillis = 0;
  static uint32_t previousMillis2 = 0;
  static uint8_t cuentaBomba = 20;
  static uint8_t cuentaTeclado = 0;
  static uint8_t contraTeclado[6];
  static const uint8_t contraSegura[] = {2, 1, 2, 2, 1, 3};

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
    uint32_t currentMillis = millis();

    if ( (currentMillis - previousMillis) >= interval ) {
      
      previousMillis = currentMillis;
      cuentaBomba--;
      Serial.print("Quedan: ");
      Serial.println(cuentaBomba);
    }
    else if ((currentMillis - previousMillis2) >= interval2) {
      
      previousMillis2 = currentMillis;
      
      // verificar codigo de seguridad
      if (digitalRead(upPin) == HIGH) {
        Serial.println("estoy aqui");
        //contraTeclado[cuentaTeclado] = 1;
        //cuentaTeclado++;
      }
      if (digitalRead(downPin) == HIGH) {
        contraTeclado[cuentaTeclado] = 2;
        cuentaTeclado++;
      }
      if (digitalRead(armPin) == HIGH) {
        contraTeclado[cuentaTeclado] = 3;
        cuentaTeclado++;

        if (cuentaTeclado == 6) {
          if (contraTeclado == contraSegura) {
            Serial.println("Bomba desarmada");
            estadoBomba = 0;
            memset(contraTeclado, 0, sizeof(contraTeclado));
          }
        }
      }
    }

    if (cuentaBomba == 0) {
      Serial.println("BOMBA EXPLOTO");
      cuentaBomba = 20;
      estadoBomba = 0;
    }
  }
}

void senal() {
}

void loop() {
  bomb();
  senal();
}
