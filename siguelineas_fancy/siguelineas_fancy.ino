// Definicion de constantes
const int pines_sensor[8] = {?XD, ?XD, ?XD, ?XD, ?XD, ?XD, ?XD, ?XD}; // хрен його знає at this point
const int ir_pin = ?XD; // alimentacio 3.3V

// Preparación para guardar info de cada uno de los sensores
int valores_sensor[8];
int sensor_min[8];
int sensor_max[8];
int umbral[8];

// Configuración
void setup() 
{
  Serial.begin(115200);
  
  pinMode(ir_pin, OUTPUT);
  digitalWrite(ir_pin, HIGH);

  /*
  Pregunta, se puede usar:

  pinMode(ir_pin, INPUT_PULLUP);
  */

  // Revisar que todos sensores estan funcionando (I'll be honest, Roma came up with idea of checking this)
  revisarSensores();

  // Calibrar sensores
  for (int i = 0; i < 8; i++) 
  {
    sensor_min[i] = 4095; // máximo posible --> vamos a bajar
    sensor_max[i] = 0;    // mínimo posible --> vamos a subir
  }

  Serial.println("Sensorea estan calibrando... puedes ensenar la linéa, porfa?");
  calibracionSensores();
}

// Ejecutación
void loop() 
{
  for (int i = 0; i < 8; i++) 
  {
    valores_sensor[i] = analogRead(pines_sensor[i]);
    
    // Print lo todo ᓚᘏ𑄝
    Serial.print("Canal ");
    Serial.print(i);
    Serial.print(" (Pin ");
    Serial.print(pines_sensor[i]);
    Serial.print("): ");
    Serial.print(valores_sensor[i]);
    
    if (valores_sensor[i] > umbral[i]) 
    {
      Serial.print("-- I guess this channel found the Adventure Line™ --"); // alguien aquí sabe de Stanley Parable?
    }
    
    Serial.println();
  }
  
  Serial.println("--- . ݁ ⟡ ݁ . ---");
  delay(1000);
}


// Todas las funciones necesarias
void revisarSensores() 
{
  Serial.println("Sensorea estan despertando, espera un momento...ᶻ z 𐰁");

  bool todos_funcionando = false;
  while (!todos_funcionando) 
  {
    todos_funcionando = true; 

    for (int i = 0; i < 8; i++) 
    {
      int lectura = analogRead(pines_sensor[i]);
      
      if (lectura <= 1) // IMPORTANTE! Solo va a funcionar si lo encendemos en una superficie que NO sea blanca
      {
        todos_funcionando = false;
        break;
      }
    }

    if (!todos_funcionando) 
    {
      Serial.println("Un sensor no quiere despertar -_- ... Revisa las conexiones ¯\_(ツ)_/¯");
      delay(500); // Esperar 0.5s y volver a comprobar
    }
  }

  Serial.println("El sol brilla! Todos sensores estan listos para trabajar!");
  Serial.println("--- . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁. ---");
}

void calibracionSensores() 
{
  unsigned long tiempo_inicio = millis();
  
  // Damos 5 segundos para calibrar
  while (millis() - tiempo_inicio < 5000) 
  {
    encontrarExtremosSensores();
    delay(20);
  }

  // Calculamos umbrales
  calcularUmbralesSensores();

  Serial.println("Sensorea están calibrados ദ്ദി(ᵔᗜᵔ)");
  Serial.println("--- . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁. ---");
  Serial.println();
  Serial.println("Todo está listo, lets get to work ᕙ(  •̀ ᗜ •́  )ᕗ");
}

void encontrarExtremosSensores() 
{
  for (int i = 0; i < 8; i++) 
  {
    int valor_actual = analogRead(pines_sensor[i]);
        
    if (valor_actual < sensor_min[i]) 
    {
      sensor_min[i] = valor_actual;
    }
    if (valor_actual > sensor_max[i]) 
    {
      sensor_max[i] = valor_actual;
    }
  }
}

void calcularUmbralesSensores() 
{
  for (int i = 0; i < 8; i++) 
  {
    umbral[i] = sensor_min[i] + ((sensor_max[i] - sensor_min[i]) / 2);
    
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(" --> Mín: ");
    Serial.print(sensor_min[i]);
    Serial.print(" --> Máx: ");
    Serial.print(sensor_max[i]);
    Serial.print(" --> Umbral: ");
    Serial.println(umbral[i]);
  }
}