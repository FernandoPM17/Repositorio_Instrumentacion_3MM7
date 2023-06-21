double Valor;
double Distancia;
int dist;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int Voltaje;
  Voltaje=analogRead(A0);
  Valor=Voltaje/2848.4;
  Distancia=pow(Valor,1/(-0.776));
  Distancia=33.7-Distancia;
  Serial.println(Distancia);
  delay(1000);
}
