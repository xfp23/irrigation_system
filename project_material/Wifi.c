#include <WiFi.h>
WiFi.mode(mode)：//设置 WiFi 模式，其中 mode 可以是以下之一：
WIFI_OFF//关闭 WiFi
WIFI_STA//将设备配置为 Station（客户端）模式
WIFI_AP//将设备配置为 Access Point（AP，热点）模式
WIFI_AP_STA//同时配置为 AP 和 Station 模式
WIFI_MODE_MAX//WiFi模式的数量

WiFi.begin(ssid, password);//初始化wifi
WiFi.disconnect()//断开当前的 WiFi 连接。
WiFi.status()//获取当前 WiFi 连接的状态，返回值为以下常量之一：

WL_IDLE_STATUS//WiFi 处于空闲状态
WL_NO_SSID_AVAIL//未找到指定的 SSID
WL_CONNECTED//已成功连接到 WiFi 网络
WL_CONNECT_FAILED//连接失败
WL_CONNECTION_LOST//连接丢失
WL_DISCONNECTED//已断开连接

WiFi.localIP()//获取设备分配的本地 IP 地址。

WiFi.softAP(ssid, password)//在设备上创建一个热点，其中 ssid 是热点的 SSID，password 是连接到热点所需的密码。

WiFi.softAPmacAddress(mac)//获取当前设备的 Soft AP 模式下的 MAC 地址。

WiFi.beginAP(ssid, password, channel, hidden, max_connection)//配置设备作为 AP 模式并启动它。

WiFi.scanNetworks()//扫描附近的 WiFi 网络并返回扫描到的网络数量。

WiFi.RSSI()//返回一个整数值，表示当前连接的 WiFi 网络的信号强度。单位通常是 dBm（分贝毫瓦），负值表示信号强度越强-30 dBm 表示比 -50 dBm 的信号更强

WiFi.isConnected()//检查设备是否已连接到 WiFi 网络。

WiFi.softAPdisconnect()//断开设备的 Soft AP 连接。

WiFi.getHostname()//获取设备的主机名。

WiFi.setHostname(hostname)//设置设备的主机名。

WiFi.printDiag(Serial)//打印 WiFi 诊断信息到串口。

WiFi.mode(WIFI_MODE_APSTA)//配置设备同时作为 AP 和 Station。
