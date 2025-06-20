#include <SPI.h>
#include <mcp2515.h>

MCP2515 mcp2515(5); // Assuming CS pin is connected to ESP32 GPIO 5
unsigned long previousMillis = 0;
const long interval = 500;  // 500 milliseconds
unsigned long previousMillis2 = 0;
const long interval2 = 200;  // 500 milliseconds
 struct can_frame sendMsg;
void setup() {
  Serial.begin(115200);
  SPI.begin();
  delay(100);

  Serial.println("CAN Transceiver Example");
  mcp2515.reset();
  mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ); // Ensure this matches your C2000's configuration
  mcp2515.setNormalMode();
 
    sendMsg.data[0] = 0xFA;
}

void loop() {
  // --- Sending Part ---
  // Create a CAN message to send
  
  sendMsg.can_id = 0x123; // Example CAN Identifier (11-bit standard frame)
  sendMsg.can_dlc = 8;     // Data Length Code (number of data bytes)
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Toggle between 0xFA and 0
    if (sendMsg.data[0] == 0xFA) {
      sendMsg.data[0] = 0x00;
      Serial.println(sendMsg.data[0]);
    } else {
      sendMsg.data[0] = 0xFA;
      Serial.println(sendMsg.data[0]);
    }
  }
  sendMsg.data[1] = 0x00;
  sendMsg.data[2] = 0x00;
  sendMsg.data[3] = 0x00;
  sendMsg.data[4] = 0x00;
  sendMsg.data[5] = 0x00;
  sendMsg.data[6] = 0x00;
  sendMsg.data[7] = 0x00;

  // Send the CAN message
  unsigned long currentMillis2 = millis();

  if (currentMillis2 - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis2;

    // Toggle between 0xFA and 0
     byte error = mcp2515.sendMessage(&sendMsg);

  if (error == MCP2515::ERROR_OK) {
    Serial.println("Message sent successfully!");
  } else {
    Serial.print("Error sending message: ");
    Serial.println(error);
  }
  }


  // --- Receiving Part ---
  struct can_frame receivedMsg;
  if (mcp2515.readMessage(&receivedMsg) == MCP2515::ERROR_OK) {
    Serial.print("Message received: ID=0x");
    Serial.print(receivedMsg.can_id, HEX);
    Serial.print(" Data: ");
    for (int i = 0; i < receivedMsg.can_dlc; i++) {
      Serial.print("0x");
      Serial.print(receivedMsg.data[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  } else {
    Serial.println("No message received.");
  }

  delay(100); // Adjust delay as needed for your testing
}