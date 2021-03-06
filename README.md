# Scape Room Bomb 馃挘
Proyecto 1, Sistemas F铆sicos Interactivos, UPB

## ToDo
- [x] Inicia en modo de configuraci贸n, es decir, sin hacer cuenta regresiva a煤n, la bomba est谩 desarmada. El valor inicial del conteo regresivo es de 20 segundos.
- [x]  En el modo de configuraci贸n, los pulsadores UP y DOWN permiten aumentar o disminuir el tiempo inicial de la bomba.
- [x]  El tiempo se puede programar entre 10 y 60 segundos con cambios de 1 segundo.
- [x]  El tiempo de configuraci贸n se debe visualizar en el LCD (enviamos el valor al PC).
- [x]  El pulsador ARM arma la bomba.
- [x]  Una vez armada la bomba, comienza la cuenta regresiva que ser谩 visualizada en el LCD en por medio de una cuenta regresiva en segundos.
- [x]  La bomba explotar谩 (se activa la salida de activaci贸n de la bomba) cuando el tiempo llegue a cero. En este punto el control regresar谩 al modo de configuraci贸n.
- [x]  Una vez la bomba est茅 armada es posible desactivarla ingresando un c贸digo de seguridad. El c贸digo ser谩 la siguiente secuencia de pulsadores presionados uno despu茅s de otro: DOWN, UP, DOWN, DOWN, UP, ARM.
- [x]  Si la secuencia se ingresa correctamente el controlador pasar谩 de nuevo al modo de configuraci贸n de lo contrario continuar谩 la fatal cuenta regresiva.

## Requisitos
- [ ] R01: la soluci贸n debe tener dos tareas concurrentes. La Tarea 1 se debe encargar del control de la bomba. La Tarea 2 debe generar una se帽al digital peri贸dica con una frecuencia de 1 Hz. La se帽al debe permanecer en alto 500 ms y en bajo 500 ms.
- [x] R02: debes almacenar la clave de desarmado de la bomba en una arreglo.
- [x] R03: debes definir una funci贸n a la cual le pasar谩s la direcci贸n en memoria de dos arreglos: uno con la clave recibida y otro con la clave correcta. La funci贸n deber谩 devolver un bool as铆: true si la clave recibida es igual a la clave almacenada o false si las claves no coinciden.
- [ ] R04: realiza un diagrama con el modelo en m谩quina de estados para tu soluci贸n.
- [ ] R05: define varios escenarios de prueba que permitan recoger la funcionalidad descrita del controlador.
- [ ] R06: implementa el modelo de m谩quina de estados considerando todas las tareas solicitadas.
- [ ] R07: verifica todos los escenarios de prueba definidos.

## References
- https://www.programmingelectronics.com/debouncing-a-button-with-arduino/
