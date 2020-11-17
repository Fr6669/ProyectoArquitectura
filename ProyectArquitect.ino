/*Se dejaron valores predeterminados ya que no es posible
  simular un sensor de ultrasonido por ende no podemos calcular
  una distancia. Sonará el buzzer cada que esta variable
  sea multiplo de 10*/
const int trigPin=8;
const int echoPin=9;
const int buzzer=7;
//variables

long duracion;
int distancia;
int distanciaSegura;

//Variable auxiliar 
int aux=0;

void setup() {
  
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //Tiempo de respuesta en microsegundos
  duracion= pulseIn(echoPin, HIGH);
  //Distancia en cm
  distancia= (duracion * 0.000001) * (34300.0 / 2.0); 
  distanciaSegura=distancia;
  //Si es multiplo de 0
  //Se podría decir que sonará cada 10 cm
  if(aux%10==0){
    digitalWrite(buzzer, HIGH);
  }else{
    digitalWrite(buzzer, LOW);
  }
  Serial.print("Distancia= ");
  Serial.println(aux);
  aux++;
}
