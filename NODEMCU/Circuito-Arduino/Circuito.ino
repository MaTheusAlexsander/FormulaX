#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Quadrante.h>

const char* SSID = "Tely 203";
const char* PASS = "pai_011028";

HTTPClient http;

const String LOCATION = "http://formulax.herokuapp.com/";

const String UPLOAD = "upload";
const String DOWNLOAD = "download";

Quadrante q1(D7, D2, 3), q2(D8, D3, 3);

const int d_p_t_i_1 = q1.getIr();
const int d_p_t_i_2 = q2.getIr();

const String Q1 = "\"Q1\":";
const String Q2 = "\"Q2\":";
const String T1 = "\"T1\":";
const String T2 = "\"T2\":";
const String TQ1 = "\"TQ1\":";
const String TQ2 = "\"TQ2\":";


volatile int count1 = 0;
volatile int count2 = 0;

unsigned long tempInterrupt1;
unsigned long tempInterrupt2;
unsigned long tempAtual1;
unsigned long tempAtual2;

void ICACHE_RAM_ATTR interrupt1() {
  count1++;
  tempInterrupt1 = millis();
  Serial.print(JSON_TQ1(tempInterrupt1));
}

void ICACHE_RAM_ATTR interrupt2() {
  count2++;
  tempInterrupt2 = millis();
  Serial.print(JSON_TQ2(tempInterrupt2));
}

void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(d_p_t_i_1), interrupt1, RISING);
  attachInterrupt(digitalPinToInterrupt(d_p_t_i_2), interrupt2, RISING);

  WiFi.begin(SSID, PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(" Aguardando conexão");
  }
}

void loop() {
  //INTERRUPÇÃO DOS IRs
  if (count1 > 0) {
    q1.acenderQuadrante();
    tempAtual1 = millis();
    if (tempAtual1 - tempInterrupt1 > q1.getTempo()) {
      q1.apagarQuadrante();
      count1 = 0;
    }
  }
  if (count2 > 0) {
    q2.acenderQuadrante();
    tempAtual2 = millis();
    if (tempAtual2 - tempInterrupt2 > q2.getTempo()) {
      q2.apagarQuadrante();
      count2 = 0;
    }
  }
  //COMUNICAÇÃO SERIAL EM JSON
  if (Serial.available() > 0) {
    String comando = Serial.readString();
    atualizarQuadrantes(comando);
  }
  atualizarQuadrantes(downloadWEB());
  uploadQs();
  delay(10);
  uploadTs();
  Serial.print(JSON_Q());
  delay(10);
  Serial.print(JSON_T());
  delay(1000);
}

//FUNCOES PARA JSON
void atualizarQuadrantes(String comando) {
  if (comando.startsWith("{") && comando.endsWith("}")) {
    if (comando.indexOf(Q1 + "1") > 0) {
      q1.acenderQuadrante();
    } else if (comando.indexOf(Q1 + "0") > 0) {
      q1.apagarQuadrante();
    }
    if (comando.indexOf(Q2 + "1") > 0) {
      q2.acenderQuadrante();
    } else if (comando.indexOf(Q2 + "0") > 0) {
      q2.apagarQuadrante();
    }
    if (comando.indexOf(T1) > 0) {
      int i = comando.indexOf(":");
      int j = comando.indexOf("}");
      String s;
      while ((i + 1) < j) {
        s += comando[i + 1];
        i++;
      }
      int w = s.toInt();
      q1.setTempo(w);
    }
    if (comando.indexOf(T2) > 0) {
      int i = comando.indexOf(":");
      int j = comando.indexOf("}");
      String s;
      while ((i + 1) < j) {
        s += comando[i + 1];
        i++;
      }
      int w = s.toInt();
      q2.setTempo(w);
    }
  }
}

String JSON_Q() {
  return "{" +
         Q1 + String(q1.status()) + "," +
         Q2 + String(q2.status()) +
         "}";
}
String JSON_T() {
  return "{" +
         T1 + String(q1.getTempo()) + "," +
         T2 + String(q2.getTempo()) +
         "}";
}
String JSON_TQ1(unsigned long t) {
  return "{" +
         TQ1 + String(t) +
         "}";
}
String JSON_TQ2(unsigned long t) {
  return "{" +
         TQ2 + String(t) +
         "}";
}
//FUNÇÕES WEB
String downloadWEB() {
  http.begin(LOCATION + DOWNLOAD);
  http.GET();
  String payload = http.getString();
  http.end();
  return payload;
}
void uploadQs() {
  http.begin(LOCATION + UPLOAD);
  http.addHeader("Content-Type", "application/json");
  http.POST(JSON_Q());
  http.end();
}
void uploadTs() {
  http.begin(LOCATION + UPLOAD);
  http.addHeader("Content-Type", "application/json");
  http.POST(JSON_T());
  http.end();
}
