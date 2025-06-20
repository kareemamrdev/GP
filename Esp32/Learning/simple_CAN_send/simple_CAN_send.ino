#include <SPI.h>
#include <mcp2515.h>

MCP2515 mcp2515(5); // Assuming CS pin is connected to ESP32 GPIO 5

void setup() {
  Serial.begin(115200);
  SPI.begin();
  delay(1000);

  Serial.println("CAN Sender Example");
  mcp2515.reset();
  mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ); // Make sure this matches your C2000's receiving configuration
  mcp2515.setNormalMode();
}

void loop() {
  // Create a CAN message
  struct can_frame canMsg;
  canMsg.can_id = 0x123; // Example CAN Identifier (11-bit standard frame)
  canMsg.can_dlc = 8;     // Data Length Code (number of data bytes)
  canMsg.data[0] = 0xFF;  // Example data byte 1
  canMsg.data[1] = 0x00;  // Example data byte 2
  canMsg.data[2] = 0x00;  // Example data byte 3
  canMsg.data[3] = 0x00;  // Example data byte 4
  canMsg.data[4] = 0x00;  // Example data byte 4
  canMsg.data[5] = 0x00;  // Example data byte 4
  canMsg.data[6] = 0x00;  // Example data byte 4
  canMsg.data[7] = 0x00;  // Example data byte 4

  // Send the CAN message
  byte error = mcp2515.sendMessage(&canMsg);

  if (error == MCP2515::ERROR_OK) {
    Serial.println("Message sent successfully!");
  } else {
    Serial.print("Error sending message: ");
    Serial.println(error);
  }

  delay(1000); // Send a message every 1 second (adjust as needed)
}
