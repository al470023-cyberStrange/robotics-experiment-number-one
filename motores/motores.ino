// Definicion de constantes
const int IN1_MOTOR_A = ?XD;
const int IN2_MOTOR_A = ?XD; 

// Configuración
void setup_motores() 
{
  pinMode(IN1_MOTOR_A, OUTPUT);
  pinMode(IN2_MOTOR_A, OUTPUT);
}

// Ejecutación
void loop_motores() 
{
  digitalWrite(IN1_MOTOR_A, HIGH);
  digitalWrite(IN2_MOTOR_A, LOW);
  delay(1000);

  /* En otro sentido ¯\_(ツ)_/¯
  digitalWrite(IN1_MOTOR_A, LOW);
  digitalWrite(IN2_MOTOR_A, HIGH);
  delay(1000);*/
}