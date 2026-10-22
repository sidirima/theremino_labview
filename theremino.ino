
#include <SPI.h>  // include the SPI library

 
#define ECHOPIN_volume 2          // Pin to receive echo pulse
#define TRIGPIN_volume 3          // Pin to send trigger pulse
#define ECHOPIN_pitch 4           // Pin to receive echo pulse
#define TRIGPIN_pitch 5           // Pin to send trigger pulse
 
#define SPEAKER_Pin 6             // Pin for Speaker
 
float frequency;                  // put out frequency
float volume;                     // put out volume
float distance_pitch;             // distance for pitch-control
float distance_volume;            // distance for volume-control
 
 
// ===================
// ====== SETUP ======
// ===================
 
void setup()
   {
    Serial.begin(9600);
    
    pinMode(ECHOPIN_volume, INPUT);
    pinMode(TRIGPIN_volume, OUTPUT);
    pinMode(ECHOPIN_pitch, INPUT);
    pinMode(TRIGPIN_pitch, OUTPUT);
    
    pinMode(SPEAKER_Pin, OUTPUT);
    
    SPI.begin();    // initialize SPI: 
   }
 
 
// ===========================
// ========== LOOP ===========
// ===========================
 
void loop()
   {
    // ==============================
    // ultra sonic distance for pitch
    // ==============================
    
    digitalWrite(TRIGPIN_pitch, LOW);             // Set the trigger pin to low for 2uS
    delayMicroseconds(2);
    
    digitalWrite(TRIGPIN_pitch, HIGH);            // Send a 10uS high to trigger ranging
    delayMicroseconds(10);
    digitalWrite(TRIGPIN_pitch, LOW);                         // Send pin low again
    
    distance_pitch = pulseIn(ECHOPIN_pitch, HIGH) / 58.0;     // Read in times pulse
    
    frequency = 4000.0 / (distance_pitch + 1.0);
    
    
    //frequency = (1500.0 / 23.0) * (25.0 - distance_pitch);   // points (2/1500) and (25/0)
    
    if (frequency < 30)
       {
        frequency = 0.0;        
       }
      
    if (frequency > 1000)
       {
        frequency = 1000.0;        
       }
  
 
    // ===============================
    // ultra sonic distance for volume
    // ===============================
 
    digitalWrite(TRIGPIN_volume, LOW);             // Set the trigger pin to low for 2uS
    delayMicroseconds(2);
    
    digitalWrite(TRIGPIN_volume, HIGH);            // Send a 10uS high to trigger ranging
    delayMicroseconds(10);
    digitalWrite(TRIGPIN_volume, LOW);                         // Send pin low again
    
    distance_volume = pulseIn(ECHOPIN_volume, HIGH) / 58.0;    // Read in times pulse
   
    volume = (255.0 / 23.0) * (25.0 - distance_volume);    // points (2/255) and (25/0)
    
    if (volume > 255.0)
       {
        volume = 255.0; 
       }    
    
    if (volume < 0)
       {
        volume = 0.0; 
       }
      

    Serial.print(frequency,0);
    Serial.print("\t");
    Serial.println(volume,0);
              
    tone(SPEAKER_Pin,(int)frequency);   // sending the pitch to the speaker-pin
    
    digitalPotWrite((int)volume);       // sending the volume to the digital poti
       
    delay(50);                                    // Wait 50mS before next ranging
    
}
 
 
// ============================
// ======== SUBROUTINE ========
// ============================
 
void digitalPotWrite(byte value) 
	{
    // take the SS pin low to select the chip:
	digitalWrite(CS_Pin,LOW);
    
	SPI.transfer(B00010001); // The command byte
	SPI.transfer(value);     // The data byte
    
    // take the SS pin high to de-select the chip
	digitalWrite(CS_Pin,HIGH);
	}


