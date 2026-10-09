# Is Fall falling?
This project is a generative art installation centered around the themes of "transitions" and "randomness". It captures the idiosyncrasies of NYC weather conditions on a LilyGo TTGO T-display ESP32. The display randomizes weather elements and adds a falling effect to animate the chaotic sky. 

## Project GIF
<img width="800" height="586" alt="installation-gif" src="https://github.com/user-attachments/assets/e4ce1eb5-fd81-4a10-ab98-5fdbcfd53080" />

## Recreation
To recreate this project, you need a LilyGo TTGO T-display ESP32 and a USB-C to USB-C cable to connect the ESP32 to your computer. 

### Setup
## Setup
1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Follow the [Arduino-ESP32 installation guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html) to add ESP32 board support.
3. Install **TFT_eSPI by Bodmer** through the Arduino Library Manager.
4. Open `TFT_eSPI/User_Setup_Select.h`:
   - Comment out `#include <User_Setup.h>`.
   - Uncomment `#include <User_Setups/Setup25_TTGO_T_Display.h>`.
5. Clone this repository and open the project’s `.ino` file.
6. Connect the TTGO T-Display and select:
   - **Board:** ESP32 Dev Module
   - **Upload Speed:** 115200
   - **Flash Size:** 4 MB
   - **PSRAM:** Disabled
   - **Port:** The port connected to the board
7. Compile and upload the sketch.

> **Note:** If the board does not appear under **Tools → Port**, install the appropriate USB driver linked in the [TTGO T-Display repository](https://github.com/Xinyuan-LilyGO/TTGO-T-Display).

### Presentation
To exhibit this project as a hanging installation, you will need a LiPo battery, a string, a popsicle stick, and an envelope. The envelope should have two small holes near the top to thread the string through and one hole near the center for the display. The string used in my installation was ~4', but it varies depending on your preferred height for the hanging installation. You may follow the detailed instructions for the installation setup [here]([url](https://coms3930.notion.site/Module-1-Install-10a350cc6f058045b899e7d3c2a3c8f5)). 
