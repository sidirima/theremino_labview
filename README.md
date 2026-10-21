# Ultrasonic Theremin using Arduino Nano and LabVIEW
The purpose of this project is to implement a Theremin, an electronic musical instrument, using ultrasonic sensors. We use an Arduino-family microcontroller and also we have a visual representation on National Instruments LabVIEW software.
<p align = "center">
  <img width="1684" height="1365" alt="image" src="https://github.com/user-attachments/assets/070f85a3-e65c-4b08-9051-8cfcb53011cb" />
</p>

## What is a Theremin?
The Theremin was invented by Leon Theremin, a Soviet engineer in the 1920s. It is a wooden or plastic box with two metal antennas, one vertical and one horizontal. The circuitry inside the box 
is responsible for sound generation. There is a speaker and some simple oscillators, as we see on the block diagram in the picture below.
<p align = "center">
  <img src="https://hackaday.com/wp-content/uploads/2020/10/Theremin-block-diagram.png">
</p>

The vertical antenna is used for pitch variation and the horizontal one for volume variation. By the movement of the hands of the thereminist, the oscillators vary their output frequency thus altering the sound generated.
The antennas are essentially the "electrode" of a capacitor, with the hand of the thereminist being the other electrode. Thus, by the hand movements there is a variation in the capacitive load of the oscillators. The electronics are pure analog.



