#include <IRremote.h> 
int IN1 = 3;    // Sürücü kartın IN1 bağlantısı
int IN2 = 2;    // Sürücü kartın IN2 bağlantısı
int ENA = 9;    // Motorun çalışma ve hız kontrol pini

int IN3 = 4;    // Sürücü kartın IN1 bağlantısı
int IN4 = 5;    // Sürücü kartın IN2 bağlantısı
int ENB = 10;    // Motorun çalışma ve hız kontrol pini


IRrecv irrecv(12); 
decode_results results;
void setup() {
  pinMode(IN1, OUTPUT);     // Pinler çıkış olarak ayarlanıyor
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);     // Pinler çıkış olarak ayarlanıyor
  pinMode(IN4, OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600); 
}
void ileri(){
  Serial.println("ileri girdi");
  analogWrite(ENA, 100);     // Hız ayarı yapılıyor (0-255 arası yazılabilir)
  digitalWrite(IN1, HIGH);  // Dönüş yönü IN1-IN2 pinlerinin hangisinin HIGH
  digitalWrite(IN2, LOW);   // hangisinin LOW yapıldığıyla ayarlanıyor
  analogWrite(ENB, 100);     // Hız ayarı yapılıyor (0-255 arası yazılabilir)
  digitalWrite(IN3, HIGH);  // Dönüş yönü IN1-IN2 pinlerinin hangisinin HIGH
  digitalWrite(IN4, LOW);
  delay(100);    
            // Motorun dönüş süresini ayarlıyoruz
}
void dur(){
  analogWrite(ENA, 100);     // Hız ayarı yapılıyor (0-255 arası yazılabilir)
  digitalWrite(IN1, LOW);  // Dönüş yönü IN1-IN2 pinlerinin hangisinin HIGH
  digitalWrite(IN2, LOW);   // hangisinin LOW yapıldığıyla ayarlanıyor
  analogWrite(ENB, 100);     // Hız ayarı yapılıyor (0-255 arası yazılabilir)
  digitalWrite(IN3, LOW);  // Dönüş yönü IN1-IN2 pinlerinin hangisinin HIGH
  digitalWrite(IN4, LOW);
  delay(100);    
            // Motorun dönüş süresini ayarlıyoruz
}
void sag(){
  analogWrite(ENA, 100);     // Hız ayarı yapılıyor (0-255 arası yazılabilir)
  digitalWrite(IN1, HIGH);  // Dönüş yönü IN1-IN2 pinlerinin hangisinin HIGH
  digitalWrite(IN2, LOW);   // hangisinin LOW yapıldığıyla ayarlanıyor
  analogWrite(ENB, 100);     // Hız ayarı yapılıyor (0-255 arası yazılabilir)
  digitalWrite(IN3, LOW);  // Dönüş yönü IN1-IN2 pinlerinin hangisinin HIGH
  digitalWrite(IN4, LOW);
  delay(100);    
            // Motorun dönüş süresini ayarlıyoruz
}
void sol(){
  analogWrite(ENA, 100);     // Hız ayarı yapılıyor (0-255 arası yazılabilir)
  digitalWrite(IN1, LOW);  // Dönüş yönü IN1-IN2 pinlerinin hangisinin HIGH
  digitalWrite(IN2, LOW);   // hangisinin LOW yapıldığıyla ayarlanıyor
  analogWrite(ENB, 100);     // Hız ayarı yapılıyor (0-255 arası yazılabilir)
  digitalWrite(IN3, HIGH);  // Dönüş yönü IN1-IN2 pinlerinin hangisinin HIGH
  digitalWrite(IN4, LOW);
  delay(100);    
            // Motorun dönüş süresini ayarlıyoruz
}

void geri(){
  analogWrite(ENA, 100);     // Hız ayarı yapılıyor (0-255 arası yazılabilir)
  digitalWrite(IN1, LOW);  // Dönüş yönü IN1-IN2 pinlerinin hangisinin HIGH
  digitalWrite(IN2, HIGH);   // hangisinin LOW yapıldığıyla ayarlanıyor
  analogWrite(ENB, 100);     // Hız ayarı yapılıyor (0-255 arası yazılabilir)
  digitalWrite(IN3, LOW);  // Dönüş yönü IN1-IN2 pinlerinin hangisinin HIGH
  digitalWrite(IN4, HIGH);
  delay(100);    
            // Motorun dönüş süresini ayarlıyoruz
}
void loop() {
  if (irrecv.decode(&results)){ 
    Serial.println(results.value);
    if (results.value==16738455){
      ileri();
    } 
    else if(results.value==16716015) {
      sol();
    }
    else if (results.value==16734885) {
      sag();
    }
    else if (results.value==16730805) {
      geri();
    }
    else {
      dur();
    }
    irrecv.resume();
  } 
}