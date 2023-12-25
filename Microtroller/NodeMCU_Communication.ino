#include <ESP8266WiFi.h>
#include <TridentTD_LineNotify.h>
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>


#define LINE_TOKEN "aoNKnLwD4zUNeajt8D4vqzGDiOZvvSscrjBJBOfeoTE"
const char* ssid = "Miss Shadopay";
const char* password = "krittscabello";
const char* mqtt_server = "192.168.152.211";
String incomingString;
double waterlavel = 0;

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (100)
char msg[MSG_BUFFER_SIZE];
int value = 0;
int lastlavel = 0;
int danger = 0;


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

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    //Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {

    } else {
      //Serial.print("failed, rc=");
      //Serial.print(client.state());
      //Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);
  setup_wifi();
  LINE.setToken(LINE_TOKEN);
  client.setServer(mqtt_server, 1883);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (Serial.available() > 0) {
    incomingString = Serial.readString();
    waterlavel = incomingString.toDouble();
    if (true) {
      if (waterlavel >= 181) {
        danger = 4;
      } else if (waterlavel >= 151) {
        danger = 3;
      } else if (waterlavel >= 131) {
        danger = 2;
      } else {
        danger = 1;
      }
      if (danger != lastlavel) {
        lastlavel = danger;
        if (lastlavel == 1) {
          LINE.notify("สภาวะระดับน้ำในขณะนี้ : สภาวะปกติ");
          LINE.notify("ระดับน้ำในเกณฑ์ : ไม่เกิน 1.30 เมตร");
        } else if (lastlavel == 2) {
          LINE.notify("สภาวะระดับน้ำในขณะนี้ : สภาวะธงเหลือง");
          LINE.notify("คำแนะนำ : ให้ติดตามข่าวสารอย่างใกล้ชิด");
          LINE.notify("ระดับน้ำในเกณฑ์ : 1.31-1.50 เมตร");
        } else if (lastlavel == 3) {
          LINE.notify("สภาวะระดับน้ำในขณะนี้ : สภาวะธงส้ม มีความเสี่ยงอันตราย");
          LINE.notify("คำแนะนำ : ให้อพยพเคลื่อนย้ายทรัพย์สินในที่สูง");
          LINE.notify("ติดต่อเทศบาล : 0-7552-2785");
          LINE.notify("ระดับน้ำในเกณฑ์ : 1.51-1.80 เมตร");
        } else if (lastlavel == 4) {
          LINE.notify("สภาวะระดับน้ำในขณะนี้ : สภาวะธงแดง มีความเสี่ยงอันตรายสูงสุด");
          LINE.notify("คำแนะนำ : ให้อาศัยอยู่ในสถานที่ปลอดภัย และปฏิบัติตามข้อสั่งการ");
          LINE.notify("ติดต่อเทศบาล : 0-7552-2785");
          LINE.notify("ระดับน้ำในเกณฑ์ : ตั้งแต่ 1.81 เมตร");
        }
        //LINE.notify("ระดับปัจจุบัน : ");
      }
    }
  }
  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;

    snprintf(msg, MSG_BUFFER_SIZE, "{\"waterlavel\":%f}", waterlavel);
    //Serial.print("Publish message: ");
    //Serial.println(msg);
    client.publish("Data", msg);
  }
  delay(5000);
}
