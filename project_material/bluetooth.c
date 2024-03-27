typedef char * String;
/*库：Bluetoothserial.h
建立蓝牙对象： Bluetoothserial myBT(自定义名称);
检查蓝牙缓冲区是否有外部送来的资料：myBT.available();
读取缓冲区的资料：myBT.read();
透过蓝牙发送讯息：myBT.println();
*/

/*available()方法返回的是整数类型（int）。
该方法用于检查接收缓冲区中是否有可用的数据。如果有可用的数据，则返回缓冲区中可用字节的数量；如果没有可用的数据，则返回0。
*/

//读取蓝牙发送的信息
setupBluetooth();//：初始化蓝牙设置。
connectToBluetooth();//：连接到蓝牙设备。
sendBluetoothData(String data);//：发送数据到已连接的蓝牙设备，参数 data 是要发送的字符串数据。
receiveBluetoothData();//：接收从蓝牙设备发送过来的数据，并返回接收到的字符串。
isBluetoothConnected();//：检查是否已连接到蓝牙设备，返回布尔值表示连接状态。