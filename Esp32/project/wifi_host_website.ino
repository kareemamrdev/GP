// #include <WiFi.h>
// #include <WebServer.h>

// const char* ssid = "Handaseta_Private1";     // your Wi-Fi name
// const char* password = "H.20002000";         // your Wi-Fi password

// WebServer server(80);

// // Replace with your real-time data variable
// String sensorValue = "naggar";  // later this will come from MCU or sensor

// void handleDataRequest() {
//   server.send(200, "text/plain", sensorValue);
// }

// void setup() {
//   Serial.begin(115200);
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("\n✅ Connected!");
//   Serial.print("ESP IP: ");
//   Serial.println(WiFi.localIP());

//   server.on("/data", handleDataRequest);
//   server.begin();
//   Serial.println("📡 Web server started");
// }

// void loop() {
//   server.handleClient();

//   // Simulate changing data (you'll replace this later with actual input)
//   static unsigned long lastUpdate = 0;
//   if (millis() - lastUpdate > 1000) {
//     lastUpdate = millis();
//     sensorValue = "naggar " + String(random(100));  // example update
//     Serial.println("New data: " + sensorValue);
//   }
// }

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "3mk";
const char* password = "3mk_124578";

IPAddress local_IP(192, 168, 1, 15);  // pick an unused IP outside DHCP range
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);



WebServer server(80);

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Must be called before WiFi.begin()!
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("❌ Failed to configure static IP");
  }

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ Connected!");
  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.localIP());

  server.on("/data", []() {
    server.send(200, "text/plain", "naggar");  // simplified for now
  });

  server.begin();
  Serial.println("📡 Web server started");
}

void loop() {
  server.handleClient();
}
