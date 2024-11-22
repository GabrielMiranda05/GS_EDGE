#include <WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "23.22.163.175";

//Recebe dados
String my_payload;
String my_topic;

WiFiClient WOKWI_Client;
PubSubClient client(WOKWI_Client);

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
 String conc_payload;
 for (int i = 0; i < length; i++) {
    conc_payload += ((char)payload[i]);
  }
  my_payload = conc_payload;
  my_topic = topic;
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("WOKWI_Client")) {
      Serial.println("connected");
      client.subscribe("ESP32_RECEBE");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(2, OUTPUT); 
  pinMode(15, OUTPUT); 
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void Conexao_WIFI(){
  if(WiFi.status())
  digitalWrite(2, HIGH);
  else
  digitalWrite(2, LOW);
}

void Conexao_MQTT(){
  if(client.connected())
  digitalWrite(15, HIGH);
  else
  digitalWrite(15, LOW);
}

void Publica_Dados_Potencia(){
  int Valor_POT;
  Valor_POT = analogRead(34);
  client.publish("TOPICO_POT",String(Valor_POT).c_str());
  delay(1000);
}

void Publica_Dados_Corrente(){
  int Valor_CORRENTE;
  Valor_CORRENTE = analogRead(35);
  client.publish("TOPICO_CORRENTE",String(Valor_CORRENTE).c_str());
  delay(1000);
}

void loop() {
  reconnect();
  client.loop();
  Conexao_WIFI();
  Conexao_MQTT();
  Publica_Dados_Corrente();
  Publica_Dados_Potencia();
}