# Aplicacion_COV_Check

Es un sistema dedicado a seguir los lineamientos estipulados por la Secretaria de Salud del país ante la pandemia del COVID-19. Este se compone por un 
sistema embebido y una aplicación móvil funcional.

## El sistema se divide en 5 diferentes partes:

**Detección de sana distancia**

El circuito se sitúa justo detrás de la primera persona de la fila; en caso de que haya una persona detrás se registrará la distancia a la que se encuentra 
y en caso de que esta sea menor a 1.5 metros, sonará una alarma para alertar sobre su cercanía.

**Detección de proximidad al sensor de temperatura**

El sensor lee la distancia al objeto más
cercano, y envía este dato al NodeMCU.
En caso de que la distancia del objeto sea
menor a 25 centímetros, se envía una señal
de HIGH al relevador, lo cual permite que la
corriente pase. En caso de ser menor, envía
una señal de LOW.
La corriente permite que el sensor de
temperatura (representado en esta imagen
como un LED), encienda únicamente cuando
sea necesario, lo que permite ahorrar energía.

**Toma de temperatura**

Una vez recibida la información de la placa anterior, esta nueva placa detectará la temperatura de las personas y la desplegará en una pantalla. El NODEMCU, en
un pin digital, recibe la temperatura registrada por el sensor. La pantalla LCD recibe los datos a través de uno de sus pines.

**Confirmación de uso de gel antibacterial**

El acelerómetro colocado en el
dispensador de gel, va a detectar la
aceleración que siente al ser presionado
el dispensador.
Como actuador está un LED RGB de
ánodo común que mientras no sienta
cambio en la aceleración, este va a tener
un color rojo prendido y cuando se
presione la tapa, el color del LED,
cambiará a verde.

**Detección de proximidad a la entrada**

El sensor de movimiento permite identificar
la presencia de un objeto frente a la puerta
para accionar un motor y que ésta se abra.
Si ya no se encuentra nadie, la puerta se
cierra.
La apertura y cerrado de la puerta se hace
mediante un motor.
