# Autism-Buddy
This is the repository containing the Arduino code used in the Autism Buddy project. Group 90, Engineering Design Course 2021, Eindhoven University of Technology.

This code contains instruction that run the circuit. The circuit contains 6 buttons related to an emotion. Every button lights up an RGB LED strip in a different color. 
The colors were researched in order to be liked by children with autism. There is a 10 second delay implemented that prevents from activating any two buttons in a row.

This code also implements Blynk. Blynk connects the Arduino circuit to the internet and send notifications related to what button has been pressed. 
The notifications are received in the Android/IOS Blynk app. Within this app, the user can press a button that will color the LED strip used in the circuit in cyan.
This is used as a form of acknowledgement. Also, the built in LED of the Arduino can be turned on or off within the smartphone app.
