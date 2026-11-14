// Librerias
#include <Wire.h>
#include <VL53L1X.h>

// Crear objeto de sensor ToF
VL53L1X sensorToF;

// Definición de constantes
const int SDA_PIN = ?XD; // creo que 8
const int SCL_PIN = ?XD; // creo que 9


// Configuración
void setup() 
{
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  
  // Inicialización de la librería del sensor
  sensorToF.init();

  // Y algunos "settings"
  sensorToF.setDistanceMode(VL53L1X::Short); // distance mode (kinda obvious)
  sensorToF.startContinuous(50); // iniciar mediciones con un intervalo de 50 ms

}

// Ejecutación
void loop() 
{
  // Llamar la función de lectura
  int distance = sensorToF.read(); 

  // Print datos recibidos ᓚᘏ𑄝
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" mm");
  delay(1000);
}