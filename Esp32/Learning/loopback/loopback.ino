#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(5);  // Change to your actual CS pin (e.g., 5)

void setup() {
  Serial.begin(115200);
  SPI.begin();  // Default: SCK=18, MISO=19, MOSI=23 for ESP32
  delay(1000);  // Let Serial start

  Serial.println("Initializing MCP2515 in Loopback Mode...");

  mcp2515.reset();

  // Set bitrate and clock speed of MCP2515 module (usually 8 MHz crystal)
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);

  // Enable loopback mode
  mcp2515.setLoopbackMode();

  Serial.println("MCP2515 is in loopback mode.");
}

void loop() {
  // Construct message
  canMsg.can_id  = 0x123;
  canMsg.can_dlc = 3;
  canMsg.data[0] = 0xAB;
  canMsg.data[1] = 0xCD;
  canMsg.data[2] = 0xCC;

  Serial.println("Sending test CAN message...");
  if (mcp2515.sendMessage(&canMsg) == MCP2515::ERROR_OK) {
    Serial.println("Message sent!");
  } else {
    Serial.println("Message failed to send.");
  }

  delay(10);  // Allow time for internal loopback

  // Try to read the same message
  struct can_frame recvMsg;
  if (mcp2515.readMessage(&recvMsg) == MCP2515::ERROR_OK) {
    Serial.print("Message received: ID=0x");
    Serial.print(recvMsg.can_id, HEX);
    Serial.print(" Data: ");
    for (int i = 0; i < recvMsg.can_dlc; i++) {
      Serial.print("0x");
      Serial.print(recvMsg.data[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  } else {
    Serial.println("No message received.");
  }

  Serial.println("-------------");
  delay(1000);
}
