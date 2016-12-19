//計時器範例
#include <Timer.h>

Timer t2;

void setup() {
  
  pinMode(2, OUTPUT); // Pin: Output Mode
  
  // 以oscillate設定每幾毫秒切換一次狀態(方波) 參數:第幾腳/週期幾毫秒/初始狀態
  t2.oscillate(2, 1000, HIGH); 
  
}

void loop() {
  
  // 呼叫timer的update，運作更新狀態 
  t2.update();
 
}
