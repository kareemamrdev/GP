#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Handaseta_Private1";    // your Wi-Fi SSID
const char* password = "H.20002000";        // your Wi-Fi password

WebServer server(80);
int counter = 0;
unsigned long lastUpdate = 0;

String generateHTML() {
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <title>ESP32 Dashboard</title>
      <meta charset="UTF-8">
      <style>
        body {
          font-family: sans-serif;
          background: #f2f2f2;
          text-align: center;
          padding-top: 50px;
        }
        .box {
          background: white;
          padding: 30px;
          margin: auto;
          display: inline-block;
          border-radius: 10px;
          box-shadow: 0px 4px 8px rgba(0,0,0,0.1);
        }
        .value {
          font-size: 48px;
          color: #2c7be5;
        }
      </style>
      <script>
        function updateValue() {
          fetch("/value")
            .then(res => res.text())
            .then(data => {
              document.getElementById("value").innerText = data;
            });
        }
        setInterval(updateValue, 1000);
        window.onload = updateValue;
      </script>
    </head>
    <body>
      <div class="box">
        <h1>ESP32 Live Counter</h1>
        <div class="value" id="value">0</div>
      </div>
    </body>
    </html>
  )rawliteral";

  return html;
}

void handleRoot() {
  server.send(200, "text/html", generateHTML());
}

void handleValue() {
  server.send(200, "text/plain", String(counter));
}

void setup() {
  Serial.begin(115200);
  delay(1000);

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

  server.on("/", handleRoot);
  server.on("/value", handleValue);
  server.begin();
  Serial.println("📡 Web server started");
}

void loop() {
  server.handleClient();

  if (millis() - lastUpdate > 1000) {
    counter++;
    lastUpdate = millis();
    Serial.println(counter);
  }
}
