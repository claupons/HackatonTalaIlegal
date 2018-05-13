int redLed = 12;
int greenLed = 11;
int smokeA0 = A0;
// Your threshold value
int sensorThres = 400;
const int sensorPIN = A2;
const int sampleWindow = 50; // Ancho ventana en mS (50 mS = 20Hz)
 const int sensorMin = 4;     // lectura mínima
const int sensorMax = 1024;  // lectura máxima

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

 
  
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    Serial.println ("Hay fuego");
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    Serial.println (" "); 
    unsigned long startMillis= millis();
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // Recopilar durante la ventana
   unsigned int sample;
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(sensorPIN);
      if (sample < 1024)
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // Actualizar máximo
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // Actualizar mínimo
         }
      }
   }
   unsigned int peakToPeak = signalMax - signalMin;  // Amplitud del sonido
   double volts = (peakToPeak * 5.0) / 1024;  // Convertir a tensión
   
   if (volts>0.1)
{ 
  Serial.println ("Estan talando un árbol");
   digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
}
else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    Serial.println (" ");
  // Leer el sensor en el pin A0:
  int sensorReading = analogRead(A4);
  // Mapeamos el rango del sensor (4 opciones):
  // f¿Función: 'long int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // Valores del rango:
  switch (range) {
  case 1:    // Fuego cercano, a una distancia de aproximadamente 1.5 pies.
    Serial.println("** HAY FUEGO **");
     digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    break;
  case 0:    // Se detecta fuego entre 1-3 pies de distancia.
    Serial.println("** HAY FUEGO **");
     digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    break;
  case 2:    // No se ha detectado fuego.
    Serial.println("");
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    break;
     }
  }
  delay(100);
 }
 }
