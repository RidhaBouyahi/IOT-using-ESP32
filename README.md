# IOT using ESP32
There is always a serious problem related to scheduling and stocks managing.
Workers used to get income product and register it on papers then redo the registration using office computers.
Some producted are lost as some others are unregistered.
I suggested a solution based on ESP32, barcode scanner module to solve this problem.

By using barcodes that contains shipment details(Provider,delivery, date , status) sticked on the incomming products, workers 
could scan it using the scanner i developed.
This gadget can detect barcode,decode it and send its data to the firebase server in realtime.
from there the manager could access the DB and configure priority and previlege.
In this project, you will find a 3D model of the gadget using CATIA VR5, CUSTOM ESP32 designed for our purpose, C script.

In the script, the esp32 will check if wifi is available, connect to it link esp32 to firebase, read data then send it in real-time.
