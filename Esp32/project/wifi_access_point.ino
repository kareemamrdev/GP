#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ESP32-HMI";
const char* password = "12345678";

WebServer server(80);

String generateHTML() {
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <title>ESP32 HMI Dashboard</title>
      <meta charset="UTF-8">
      <style>
        body {
          font-family: Arial, sans-serif;
          background-color: #f0f4f8;
          text-align: center;
          padding: 50px;
        }
        .box {
          background-color: white;
          padding: 30px;
          border-radius: 10px;
          box-shadow: 0 0 10px rgba(0,0,0,0.1);
          display: inline-block;
        }
        h1 {
          color: #333;
        }
        .word {
          font-size: 48px;
          color: #28a745;
        }
      </style>
      <script>
        function updateWord() {
          fetch("/word")
            .then(response => response.text())
            .then(data => {
              document.getElementById("word").innerText = data;
            })
            .catch(err => {
              console.error("Fetch error:", err);
            });
        }
        setInterval(updateWord, 1000);
        window.onload = updateWord;
      </script>
    </head>
    <body>
      <div class="box">
        <h1>ESP32 Live Display</h1>
        <div class="word" id="word">...</div>
      </div>
    </body>
    </html>
  )rawliteral";

  return html;
}

void handleRoot() {
  Serial.println("Serving root page");
  server.send(200, "text/html", generateHTML());
}

void handleWord() {
  Serial.println("Sending word: naggar");
  server.send(200, "text/plain", "naggar");
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.print("Access Point IP: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/word", handleWord);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();
  delay(1);  // Keep things running smoothly
}
