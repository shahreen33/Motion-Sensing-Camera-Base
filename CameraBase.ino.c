void loop()
{



    for (int PIR = 0; PIR < 5; PIR++)   // start this loop for each PIR sensor
    {

        currentPIRpin = PIRpin[PIR]; // set current PIR pin to current number in 'for'loop

        currentLEDpin=LEDpin[PIR]; // set current LED pin to current number in 'for' loop

        PIRstatus = digitalRead(currentPIRpin);



        if (PIRstatus == HIGH)   // if motion is detected on current PIR sensor
        {

            digitalWrite(currentLEDpin, HIGH); // turn corresponding LED on

            if(PIRprevState[PIR] == 0)   // if PIR sensor's previous state is LOW
            {

                if (currentPIRposition != currentPIRpin && PIRprevState[PIR] == 0)   // if high PIR is different than current position PIR then move to new position

                    camServo.write(PIRposition[PIR]);

                    Serial.print("Current angle : ");

                    Serial.println(PIRposition[PIR]);

                    delay(50);

                    currentPIRposition = currentPIRpin; // reset current PIR position to active

                    [PIR] pin

                    PIRprevState[PIR] = 1; // set previous PIR state to HIGH

                }

                PIRprevState[PIR] = 1; // set previous PIR state to HIGH if the current position is the same as the current PIR pin

            } // end PIRprevState if

        } // end PIRstatus if



        else   //
        {

            digitalWrite(currentLEDpin, LOW); //the led visualizes the sensors output pin

            state

            PIRprevState[PIR] = 0; // set previous PIR state to LOW

        } // end else



    } // end [PIR] for loop

} // end main loop
