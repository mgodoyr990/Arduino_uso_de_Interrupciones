# Arduino_uso_de_Interrupciones
El enfoque principal es el uso y la implementación de interrupciones en microcontroladores, utilizando como base la arquitectura ESP32 y el ecosistema Arduino.

## Introducción: ¿Qué es una Interrupción?
En el desarrollo con microcontroladores, una interrupción se entiende como la suspensión temporal de una fracción de código para ejecutar una subrutina específica denominada ISR (Interrupt Service Routine).

- Flujo de Ejecución: Una vez ejecutada la subrutina, el programa continúa exactamente desde donde se detuvo.
- Origen: Estas pueden ser parte del sistema operativo, de la BIOS de la placa o programadas por el usuario.

### ¿Por qué son necesarias?
Los microcontroladores operan bajo un ciclo infinito llamado void loop(). Depender exclusivamente de este ciclo para detectar eventos se conoce como Método Polling, el cual es ineficiente porque consume recursos procesando instrucciones que "distraen" al microcontrolador del monitoreo de eventos críticos.

## Interrupciones en ESP32
A diferencia de otras placas, en la ESP32, todos los pines GPIO se pueden configurar como pines de interrupción.

### Clasificación

- Externas: Provocadas por eventos físicos como el accionamiento de un pulsador o la señal de un sensor.
- Internas: Generadas por eventos del propio software, como el término de un temporizador (timer) o un error en la ejecución

### Modos de Disparo (Triggering)
Para que la interrupción ocurra, debemos definir el cambio de estado en el GPIO mediante la función attachInterrupt(GPIO, ISR, MODO):

<img width="654" height="380" alt="image" src="https://github.com/user-attachments/assets/1dd995f6-6334-4a3c-9466-cfc4a0fb8762" />

## Consideraciones y Buenas Prácticas (Checklist)

Para asegurar la estabilidad del sistema, se deben seguir estas reglas críticas:

- Brevedad: La ISR debe tener un tiempo de ejecución lo más corto posible.
- Atributo IRAM_ATTR: Obligatorio para direccionar la función a la RAM interna y mejorar la velocidad de respuesta.
- Variables Volátiles: La comunicación entre la ISR y el programa principal debe hacerse exclusivamente mediante variables declaradas como volatile (ej: volatile int state = LOW;).
- Sin Retornos: Las funciones ISR no reciben parámetros ni devuelven valores.
