#include "S3B.h"

S3B module;

void s3BReceiver(uint8_t* data, size_t len, uint8_t* transmitterAddress);
void s3BTransmitStatus(uint8_t status);
void softwareS3BCommand();
void softwareATCommandResponse(uint8_t* data, size_t len);
void moduleSettingsLoaded();
void s3BRSSI(int rssi, uint8_t* transmitterAddress);

void setup(){
    module.init();
	module.receiveDataCallback(s3BReceiver);
	module.rssiUpdateCallback(s3BRSSI);
	module.transmissionStatusCallback(s3BTransmitStatus);
	module.softwareATCallback(softwareATCommandResponse);
	module.settingsLoadedCallback(moduleSettingsLoaded);
}

void loop(){
    module.loop();
}

void s3BReceiver(uint8_t* data, size_t len, uint8_t* transmitterAddress){

}

void s3BTransmitStatus(uint8_t status){

}

void softwareS3BCommand(){

}

void softwareATCommandResponse(uint8_t* data, size_t len){

}

void moduleSettingsLoaded(){

}

void s3BRSSI(int rssi, uint8_t* transmitterAddress){
	int currentSignalStrength;
	moduleErrorNotified = false;
	if(rssi == 40){
		rssi = 100;
	}else{
		rssi = rssi * -1;
		rssi = rssi + 92;
		rssi = rssi*1.923076923076923;
	}
	if(rssi < 20){
		currentSignalStrength = 1;
	}
	if(rssi >= 20 && rssi < 40){
		currentSignalStrength = 2;
	}
	if(rssi >= 40 && rssi < 60){
		currentSignalStrength = 3;
	}
	if(rssi >= 60 && rssi < 80){
		currentSignalStrength = 4;
	}
	if(rssi > 80){
		currentSignalStrength = 5;
	}
}
