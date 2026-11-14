// Definicion de constantes
const int pines_sensor[8] = {?XD, ?XD, ?XD, ?XD, ?XD, ?XD, ?XD, ?XD}; // хрен його знає at this point
const int ir_pin = ?XD; // alimentacio 3.3V

// Preparación para guardar los valores de cada uno de los sensores
int valores_sensor[8];
int val_blanco = 0;
int val_negro = 4095; 
int umbral = valor_negro + ((valor_blanco - valor_negro) / 2);

// Configuración
void setup() 
{
  Serial.begin(115200);
  
  // Siempre funcionando
  pinMode(ir_pin, INPUT_PULLUP);

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
    
    if (valores_sensor[i] > umbral) 
    {
      Serial.print("-- I guess this channel found the Adventure Line™ --"); // alguien aquí sabe de Stanley Parable?
    }
    
    Serial.println();
  }
  
  Serial.println("--- . ݁₊ ⊹ . ݁ ⟡ ݁ . ⊹ ₊ ݁. ---");
  delay(1000);
}