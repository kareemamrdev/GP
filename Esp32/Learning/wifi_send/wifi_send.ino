#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// WiFi AP credentials
const char* ap_ssid = "ESP32_AP";
const char* ap_password = "12345678";

// WebSocket server
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_CONNECT) {
    Serial.println("WebSocket client connected");
  } else if (type == WS_EVT_DISCONNECT) {
    Serial.println("WebSocket client disconnected");
  }
}

void setup() {
  // Initialize Serial
  Serial.begin(115200);

  // Set up WiFi Access Point
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ap_ssid, ap_password);
  delay(1000); // Wait for AP to stabilize
  Serial.print("AP Started, IP: ");
  Serial.println(WiFi.softAPIP()); // Default: 192.168.4.1

  // Initialize WebSocket
  ws.onEvent(onWebSocketEvent);
  server.addHandler(&ws);
  server.begin();
  Serial.println("WebSocket server started");
}

void loop() {
  // Simulate data (mimicking CAN message)
  static unsigned long lastSend = 0;
  if (millis() - lastSend >= 1000) { // Send every 1 second
    // Dummy data
    uint32_t id = 0x123;
    uint8_t data[8] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x00, 0x11};
    
    // Format message as JSON
    char buffer[128];
    snprintf(buffer, sizeof(buffer), 
             "{\"id\":\"0x%X\",\"data\":[\"0x%02X\",\"0x%02X\",\"0x%02X\",\"0x%02X\",\"0x%02X\",\"0x%02X\",\"0x%02X\",\"0x%02X\"]}",
             id, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
    
    // Send to all WebSocket clients
    ws.textAll(buffer);
    Serial.println("Sent: " + String(buffer));
    
    lastSend = millis();
  }
  
  // Clean up disconnected clients
  ws.cleanupClients();
}