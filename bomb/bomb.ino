void setup() {
  Serial.begin(9600);
}

bool verificaClave(uint8_t *pclaveUser, uint8_t *pclaveCorrecta, uint8_t sizeContra) {

  bool resu = 0;
  uint8_t correctas = 0;
  for (int i = 0; i < sizeContra; i++) {
    if (*(pclaveUser + i) == *(pclaveCorrecta + i)) correctas++;
  }

  (correctas == 6) ? Serial.println("BOMBA DESARMADA") : Serial.println("INCORRECTO");
  (correctas == 6) ? resu = 1 : resu = 0;
  return resu;
}

void bomb() {
  static const uint8_t upPin = 2;
  static const uint8_t downPin = 3;
  static const uint8_t armPin = 4;

  static uint8_t cuentaUpdate = 0;
  static uint8_t estadoBomba = 0; // 0: desarmada, 1: armada
  static const uint32_t interval = 1000;
  static const uint32_t interval2 = 50;
  static uint32_t previousMillis = 0;
  static uint32_t previousMillis2 = 0;
  static uint8_t cuentaBomba = 20;
  static uint8_t cuentaTeclado = 0;
  static uint8_t contraTeclado[6];
  static uint8_t contraSegura[6] = {2, 1, 2, 2, 1, 3};

  // estado de configuracion
  if (estadoBomba == 0) {

    if (cuentaBomba >= 10 && cuentaBomba <= 60) {

      if (digitalRead(upPin) == HIGH) cuentaBomba++;
      if (digitalRead(downPin) == HIGH) cuentaBomba--;

      if (cuentaBomba == 9) cuentaBomba = 10;
      if (cuentaBomba == 61) cuentaBomba = 60;
    }

    Serial.println("SET: 00:" + (String)cuentaBomba);

    if (digitalRead(armPin) == HIGH) {
      Serial.println("BOMBA ARMADA");
      estadoBomba = 1;
    }

  }

  // estado conteo
  if (estadoBomba == 1) {

    uint32_t currentMillis = millis();

    if ((currentMillis - previousMillis) >= interval ) {
      previousMillis = currentMillis;
      Serial.println("TIMER: 00:" + (String)cuentaBomba);
      cuentaBomba--;
    }

    else if ((currentMillis - previousMillis2) >= interval2) {
      previousMillis2 = currentMillis;

      // verificar codigo de seguridad
      if (digitalRead(upPin) == HIGH) {
        Serial.println("UP");
        contraTeclado[cuentaTeclado] = 1;
        cuentaTeclado++;
      }
      if (digitalRead(downPin) == HIGH) {
        Serial.println("DOWN");
        contraTeclado[cuentaTeclado] = 2;
        cuentaTeclado++;
      }
      if (digitalRead(armPin) == HIGH && cuentaUpdate > 0) {
        Serial.println("ARM");
        contraTeclado[cuentaTeclado] = 3;
        cuentaTeclado++;
      }

      if (cuentaTeclado == 6) {
        bool esClave = verificaClave(contraTeclado, contraSegura, cuentaTeclado);
        if (esClave == true) {
          cuentaBomba = 20;
          estadoBomba = 0;
          cuentaUpdate = 0;
          delay(100);
        }
        cuentaTeclado = 0;
      }

      cuentaUpdate++;
    }

    if (cuentaBomba == 0) {
      Serial.println("BOMBA EXPLOTO");
      cuentaBomba = 20;
      cuentaUpdate = 0;
      estadoBomba = 0;
    }
  }
}

void senal() {
  uint32_t currentMillisPWM = millis();
  static uint32_t previousMillisPWM = 0;
  const uint32_t intervalPWM = 500;
  static uint8_t PWMState = LOW;

  if (currentMillisPWM - previousMillisPWM >= intervalPWM) {
    previousMillisPWM = currentMillisPWM;
 
    if (PWMState == LOW) {
      PWMState = HIGH;
      digitalWrite(8, 1);
      
    } else {
      PWMState = LOW;
      digitalWrite(8, 0);
    }
  }
}

  void loop() {
    bomb();
    senal();
  }
