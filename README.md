# Scape Room Bomb 💣
Proyecto 1, Sistemas Físicos Interactivos, UPB

## ToDo
- [x] Inicia en modo de configuración, es decir, sin hacer cuenta regresiva aún, la bomba está desarmada. El valor inicial del conteo regresivo es de 20 segundos.
- [x]  En el modo de configuración, los pulsadores UP y DOWN permiten aumentar o disminuir el tiempo inicial de la bomba.
- [x]  El tiempo se puede programar entre 10 y 60 segundos con cambios de 1 segundo.
- [x]  El tiempo de configuración se debe visualizar en el LCD (enviamos el valor al PC).
- [x]  El pulsador ARM arma la bomba.
- [x]  Una vez armada la bomba, comienza la cuenta regresiva que será visualizada en el LCD en por medio de una cuenta regresiva en segundos.
- [x]  La bomba explotará (se activa la salida de activación de la bomba) cuando el tiempo llegue a cero. En este punto el control regresará al modo de configuración.
- [x]  Una vez la bomba esté armada es posible desactivarla ingresando un código de seguridad. El código será la siguiente secuencia de pulsadores presionados uno después de otro: DOWN, UP, DOWN, DOWN, UP, ARM.
- [x]  Si la secuencia se ingresa correctamente el controlador pasará de nuevo al modo de configuración de lo contrario continuará la fatal cuenta regresiva.

## Requisitos
- [ ] R01: la solución debe tener dos tareas concurrentes. La Tarea 1 se debe encargar del control de la bomba. La Tarea 2 debe generar una señal digital periódica con una frecuencia de 1 Hz. La señal debe permanecer en alto 500 ms y en bajo 500 ms.
- [x] R02: debes almacenar la clave de desarmado de la bomba en una arreglo.
- [x] R03: debes definir una función a la cual le pasarás la dirección en memoria de dos arreglos: uno con la clave recibida y otro con la clave correcta. La función deberá devolver un bool así: true si la clave recibida es igual a la clave almacenada o false si las claves no coinciden.
- [ ] R04: realiza un diagrama con el modelo en máquina de estados para tu solución.
- [ ] R05: define varios escenarios de prueba que permitan recoger la funcionalidad descrita del controlador.
- [ ] R06: implementa el modelo de máquina de estados considerando todas las tareas solicitadas.
- [ ] R07: verifica todos los escenarios de prueba definidos.
