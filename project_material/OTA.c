#include <WiFi.h> // 包含ESP32的WiFi库
#include <ESPmDNS.h> // 包含ESP32的mDNS库
#include <v .h> // 包含ESP32的UDP库
#include <ArduinoOTA.h> // 包含ESP32的OTA库

const char* ssid = ".........."; // WiFi网络的SSID
const char* password = ".........."; // WiFi网络的密码

void setup() {
  Serial.begin(115200); // 初始化串口通信，波特率为115200
  Serial.println("Booting"); // 打印启动信息

  WiFi.mode(WIFI_STA); // 设置WiFi模式为Station（即连接到现有WiFi网络）
  WiFi.begin(ssid, password); // 开始连接WiFi网络

  // 等待连接成功
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting..."); // 连接失败时打印提示信息
    delay(5000); // 延迟5秒后重启ESP32
    ESP.restart(); // 重启ESP32
  }

  // 初始化OTA功能
  ArduinoOTA
    .onStart([]() { // OTA开始时的回调函数
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch"; // 更新固件
      else // U_SPIFFS
        type = "filesystem"; // 更新文件系统

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type); // 开始OTA更新时打印提示信息
    })
    .onEnd([]() { // OTA结束时的回调函数
      Serial.println("\nEnd"); // OTA更新结束时打印提示信息
    })
    .onProgress([](unsigned int progress, unsigned int total) { // OTA更新进度回调函数
      Serial.printf("Progress: %u%%\r", (progress / (total / 100))); // 打印OTA更新进度
    })
    .onError([](ota_error_t error) { // OTA更新错误回调函数
      Serial.printf("Error[%u]: ", error); // 打印OTA更新错误信息
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed"); // 鉴权失败
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed"); // OTA开始失败
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed"); // 连接失败
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed"); // 接收失败
      else if (error == OTA_END_ERROR) Serial.println("End Failed"); // OTA结束失败
    });

  ArduinoOTA.begin(); // 启动OTA功能

  Serial.println("Ready"); // 提示OTA已准备就绪
  Serial.print("IP address: "); // 打印ESP32的IP地址
  Serial.println(WiFi.localIP());
}

void loop() {
  ArduinoOTA.handle(); // 处理OTA事件
}
