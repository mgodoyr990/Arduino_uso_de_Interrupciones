# Arduino_uso_de_Interrupciones
El enfoque principal es el uso y la implementación de interrupciones en microcontroladores, utilizando como base la arquitectura ESP32 y el ecosistema Arduino.

# Introducción: ¿Qué es una Interrupción?
En el desarrollo con microcontroladores, una interrupción se entiende como la suspensión temporal de una fracción de código para ejecutar una subrutina específica denominada ISR (Interrupt Service Routine).

- Flujo de Ejecución: Una vez ejecutada la subrutina, el programa continúa exactamente desde donde se detuvo.
- Origen: Estas pueden ser parte del sistema operativo, de la BIOS de la placa o programadas por el usuario.

### ¿Por qué son necesarias?
Los microcontroladores operan bajo un ciclo infinito llamado void loop(). Depender exclusivamente de este ciclo para detectar eventos se conoce como Método Polling, el cual es ineficiente porque consume recursos procesando instrucciones que "distraen" al microcontrolador del monitoreo de eventos críticos.
