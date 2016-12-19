//藍牙模組 HC-05 測試 
//2016.08.09
#include <SoftwareSerial.h> // 引用程式庫

// 藍牙模組腳位 
SoftwareSerial BT(3, 4); // Rx, Tx

char val; // 儲存接收資料的變數 
String val2;

void setup() { 
    Serial.begin(9600); // 與電腦序列埠連線 
    Serial.println("BT ready"); 
    BT.begin(9600); 
} 

void loop() { 
    
    // 收到藍牙模組的資料，送到「序列埠監控視窗」(與模組連線的裝置傳到模組)
    // Receive
    if (BT.available()) { 
        val2 = BT.readString();
        Serial.print(val2);
        Serial.print("\n");
    } 

    // 若收到「序列埠監控視窗」的資料(電腦端經由Arduino發送)，送到藍牙模組 
    // Send
    if (Serial.available()) {
      val = Serial.read();
       Serial.print(val);
       delay(5);
       BT.write(val);
    }
}
