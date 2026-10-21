# Ultrasonic Theremin using Arduino Nano and LabVIEW
The purpose of this project is to implement a Theremin, an electronic musical instrument, using ultrasonic sensors and a simple Arduino-family microcontroller. We use serial connection between the microcontroller and a computer, so as to have a visual representation of the sensor measurements using the National Instruments LabVIEW software. 

This project is a practical experiment in the usage of LabVIEW software and the VISA library plugin (Virtual Instrument Software Architecture).


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
To design the circuit of the project, we use [fritzing](https://fritzing.org/), an open source cross-platform designer program which is quite easy to use and allows graphic view for simple Arduino projects. The only downside is that it has a limited amount of components. The circuit is the one in the image below
<p align = "center">
  <img width="2520" height="1515" alt="Theremino Sketch_bb" src="https://github.com/user-attachments/assets/879130b9-3298-4c28-9a34-d044fd9a7d7c" />
</p>

### Parts Used for project
- 1x Arduino Nano
- 2x HC-SR04 Ultrasonic Sensors
- 1x LM386 Audio Amplifier
- 1x MCP41010 Digital 10kΩ Potentiometer
- 1x 470kΩ Rotary Potentiometer
- 1x 10μF Electrolytic Capacitor
- 1x 100nF Ceramic Capacitor
- 1x 220μF Εlectrolytic Capacitor
- 1x 50nF Electrolytic Capacitor
- 1x 100Ω Resistor
- 1x Speaker 4Ω, 3V

