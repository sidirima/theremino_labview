# Ultrasonic Theremin using Arduino Nano and LabVIEW
The purpose of this project is to implement a **Theremin**, an electronic musical instrument, using ultrasonic sensors and a simple Arduino-family microcontroller. We use serial connection between the microcontroller and a computer, so as to have a **visual representation of the sensor measurements** using the National Instruments LabVIEW software. 

This project is a practical experiment in the usage of **LabVIEW** software and the **VISA library plugin** (Virtual Instrument Software Architecture).

## Project Index

#### 1. Arduino Code 

#### 2. LabVIEW visualization file

#### 3. Schematics / Designs

#### 4. Pictures / Videos

## What is a Theremin?
The Theremin was invented by Leon Theremin, a Soviet engineer in the 1920s. It is a wooden or plastic box with two metal antennas, one vertical and one horizontal. The vertical antenna is used for pitch variation and the horizontal one for volume variation. The circuitry inside the box is responsible for sound generation. The thereminist is using their hands movements to alter the sound of the instrument.

<p align = "center">
  <img width="842" height="682.5" alt="image" src="https://github.com/user-attachments/assets/070f85a3-e65c-4b08-9051-8cfcb53011cb" />
</p>

## How does a Theremin work?
As we see in the block diagram of the instrument below, the two antennas are connected to two oscillators. The first oscillator is responsible for the volume of the generated sound. Using a **bandpass filter**, we set the maximum and minimum value accordingly.
The second oscillator is responsible for the pitch variation. The instrument uses a mixer to correspond the signal created via the pitch oscillator with a reference signal. The two signals are then combined and amplified in order for a sound to be heard via the speaker.

<p align = "center">
  <img src="https://hackaday.com/wp-content/uploads/2020/10/Theremin-block-diagram.png">
</p>

The antennas are essentially one electrode of a capacitor, with the hand of the thereminist being the other electrode. Thus, by the hand movements there is a variation in the capacitive load of the oscillators. For instance, if the thereminist holds their one hand position over the volume antenna and moves their other hand, there is only a pitch variation with a stable volume.

## Our project circuitry
To design the circuit of the project, we use [fritzing](https://fritzing.org/), an open source cross-platform designer program which is quite easy to use and allows sketch design for simple Arduino projects. The only downside is that it has a limited amount of components. The circuit is the one in the image below.
<p align = "center">
  <img width="2520" height="1515" alt="Theremino Sketch_bb" src="https://github.com/user-attachments/assets/879130b9-3298-4c28-9a34-d044fd9a7d7c" />
</p>

### Parts Used for project
- 1x Arduino Nano
- 2x HC-SR04 Ultrasonic Sensors
- 1x LM386 Audio Amplifier
- 1x MCP41010  10kΩ Digital Potentiometer
- 1x 470kΩ Rotary Potentiometer
- 1x 10μF Electrolytic Capacitor
- 1x 100nF Electrolytic Capacitor
- 1x 220μF Εlectrolytic Capacitor
- 1x 50nF Ceramic Capacitor
- 1x 100Ω Resistor
- 1x Speaker 4Ω, 3V

## Ultrasonic Sensor Working Principle
Instead of using our hands to vary the capacitance used in the oscillators, we use two ultrasonic sensor modules, one for varying the pitch and the other for varying the volume of the generated signal. These sensors are based on the principle of sound wave reflection, in this particular case an ultrasonic one (>20kHz). As we can see in the picture below, the sensor module has two metal barrels, one containing the sound transmitter and the other the receiver. This wave will bounce in every obstacle in its way, in our case it would be the hand of the thereminist and return to the receiver. The distance calculation is performed by using the time difference between transmission and reception of the signal.
<p align = "center">
  <img width="512" height="262.5" alt="image" src="https://github.com/user-attachments/assets/b5a35b19-1932-4a1d-9de1-c4435061307f" />
</p>

The generated sound is nothing but a square wave signal with variable frequency and amplitude. The frequency parameter is defined by the "Pitch" ultrasonic sensor value, whereas the amplitude parameter is defined by the "Volume" sensor value.

## Is the Digital Potentiometer necessary?
The digital potentiometer used is manufactured by Microchip, and it is a non-volatile 10kΩ variable resistance. The IC we selected uses the SPI serial protocol for communication with the microcontroller. The reason for selecting it is the packaging, which is a standard DIP-8, making it easy to test on a breadboard or solder to a PCB. 

In our case, we use this potentiometer to translate the digital output signals of the Arduino microcontroller to voltage. The use of this potentiometer is a necessity if we want to keep the "handsfree" principle of the original theremin instrument. With the use of the digital potentiometer, volume and pitch are only controlled by the parameters of the ultrasonic sensors.

Although, in the end we end up using a simple 470kΩ rotary potentiometer as well, acting as a "Master Volume" knob for the instrument.

## Audio Amplification
The signals generated via the Arduino microcontroller are not "speaker level" signals in order to be heard properly. Thus, we need to amplify and normalize the generated sound signals.
In order to achieve this, we need to use a specified Audio Amplifier IC, such as the LM386. This IC can safely drive a 4Ω or 8Ω speaker using a low voltage power source, in our case a +9V DC power supply or a 9V battery. 

The difference between the LM386 and other more common operational amplifier ICs (such as the LM741) is that those ICs have a max output current of 20mA, thus we need a load of very high resistance in order for them to function properly. Using a non-audio specific amplifier IC would require the use of external Push-Pull stages, making the circuit rather complex and ineffective due to high pricing of the components.
<p align = "center">
  <img width="1353" height="555" alt="Schematic_LM386-Amplifier_2026-10-22" src="https://github.com/user-attachments/assets/08b3692e-a99a-4ced-8c0c-fbf86d99e243" />
</p>
As we can see in the schematic diagram above, the audio amplifier section of the project is a non-inverting amplifier with a standard voltage gain of 20, due to the fact that the gain pins of the IC are not connected. Capacitors C1 and C2 are bypass capacitors, one connected to the IC and the other for voltage filtering. C3 and R1 form a **asfasf** filter that is used for impedance linearization of the drive speaker. It is used to cutoff the voice coil inductance in high frequencies. These components values are suggested in the datasheet for LM386.



