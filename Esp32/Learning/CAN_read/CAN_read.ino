#include <SPI.h>
#include <mcp2515.h>
bool  firstLoop =true ;
struct can_frame canMsg;
struct MCP2515 mcp2515(5); // CS pin is GPIO 5
 
#define CAN_ACK_ID 0x135  // CAN ID for acknowledgment
 
void setup()
{
  Serial.begin(115200);
  
  SPI.begin();
  // Wait until Serial is ready (on some boards)
  delay(1000); 
 Serial.println("start ");
  mcp2515.reset();
  mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
   Serial.println("Can_ok ");
}
 
 
void loop()
{
   if (firstLoop) {
    Serial.println("This is from setup (delayed)");
  
    firstLoop = false;
  }
  Serial.println("loop2 ");
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK)
  {
    Serial.println("recieved message ");
      int tempInt = (canMsg.data[0] << 8) | canMsg.data[1]; // Combine MSB and LSB
      float temperatureC = tempInt / 100.0; // Convert back to float
 
      Serial.print("Temperature received: ");
      Serial.print(temperatureC);
      Serial.println(" °C");
 
      // Send acknowledgment
      canMsg.can_id  = CAN_ACK_ID;  // Use ACK ID
      canMsg.can_dlc = 0;           // No data needed for ACK
      mcp2515.sendMessage(&canMsg);
      Serial.println("ACK sent");
    
  }else{
    Serial.println("no message is recieved");
  }
  delay(500);
}