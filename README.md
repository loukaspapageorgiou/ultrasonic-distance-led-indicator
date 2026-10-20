# ultrasonic-distance-led-indicator

An Arduino-based ultrasonic parking sensor system that measures distance in cm and provides visual proximity alerts using Green, Yellow, and Red LEDs, along with real-time Serial Monitor output.


# Arduino Ultrasonic Parking Sensor 🚗🚦

An Arduino-based proximity and parking sensor system that measures the distance to nearby obstacles in centimeters using an ultrasonic sensor and provides visual feedback through three traffic-light style LEDs (Green, Yellow, Red)[cite: 19].

## Features

* **Real-Time Distance Measurement:** Sends a 10-microsecond ultrasonic pulse and calculates the distance in centimeters based on the speed of sound (343 m/s)[cite: 19].
* **Visual Proximity Alerts:** Uses three LEDs (Green, Yellow, Red) to indicate safe, caution, and danger zones based on distance thresholds[cite: 19].
* **Serial Monitor Output:** Continuously prints the measured distance in centimeters (`cm`) at a 9600 baud rate with a 100ms refresh delay[cite: 19].

## Pinout Configuration

| Component | Pin Variable | Arduino Pin | Mode |
| :--- | :--- | :--- | :--- |
| **Ultrasonic Sensor (TRIG)** | `trigPin` | Pin `9` | `OUTPUT`[cite: 19] |
| **Ultrasonic Sensor (ECHO)** | `echoPin` | Pin `10` | `INPUT`[cite: 19] |
| **Green LED** | `ledGreen` | Pin `2` | `OUTPUT`[cite: 19] |
| **Yellow LED** | `ledYellow` | Pin `3` | `OUTPUT`[cite: 19] |
| **Red LED** | `ledRed` | Pin `4` | `OUTPUT`[cite: 19] |

## Parking Sensor Logic (Distance Thresholds)

The system evaluates the calculated `distance` every 100 milliseconds and triggers the corresponding LED[cite: 19]:

* **Safe Zone (`distance > 20 cm`):** Only the **Green LED** turns ON (`HIGH`), while Yellow and Red remain OFF (`LOW`)[cite: 19].
* **Caution Zone (`10 cm < distance <= 20 cm`):** Only the **Yellow LED** turns ON (`HIGH`), while Green and Red remain OFF (`LOW`)[cite: 19].
* **Danger Zone (`0 cm < distance <= 10 cm`):** Only the **Red LED** turns ON (`HIGH`), while Green and Yellow remain OFF (`LOW`)[cite: 19].

## How It Works

1. The `trigPin` is cleared (`LOW`) for 2 microseconds and then set `HIGH` for 10 microseconds to emit an ultrasonic pulse[cite: 19].
2. The `pulseIn(echoPin, HIGH)` function measures the duration (in microseconds) it takes for the sound wave to bounce back[cite: 19].
3. The distance in centimeters is calculated using the formula: `distance = duration * 0.034 / 2`[cite: 19].
4. The distance is printed to the Serial Monitor and evaluated against the parking threshold logic[cite: 19].

## Setup & Usage

1. Connect the ultrasonic sensor and the three LEDs to your Arduino board according to the **Pinout Configuration** table above[cite: 19].
2. Open the `.ino` sketch in the **Arduino IDE**.
3. Select your Arduino board and port, then click **Upload**.
4. Open the **Serial Monitor** (set to `9600` baud) to view the real-time distance readings.


https://github.com/user-attachments/assets/2844e0e8-1e67-446d-b318-1420b55883fe

