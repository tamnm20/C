# Cài đặt
## Cài đặt thư viện 
~~~
sudo apt-get install build-essential gcc make cmake cmake-gui cmake-curses-gui
cd github/
git clone https://github.com/eclipse/paho.mqtt.c.git
cd paho.mqtt.c
sudo apt-get update
sudo apt-get install libssl-dev
make
sudo make install
~~~
## Cài đặt mosquitto
~~~
sudo apt-get update
sudo apt-get install mosquitto
sudo systemctl status mosquitto
sudo apt-get install mosquitto-clients
mosquitto_sub -h localhost -t test
mosquitto_pub -h localhost -t test -m "Hello, MQTT!"
~~~
## Build chương trình với thư viện
~~~
touch mqtt_example.c
nano mqtt_example.c 
gcc -o mqtt_example mqtt_example.c -lpaho-mqtt3c
./mqtt_example
~~~


