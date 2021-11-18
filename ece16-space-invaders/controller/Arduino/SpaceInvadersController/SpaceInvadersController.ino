/*
 * Global variables
 */
// Acceleration values recorded from the readAccelSensor() function
int ax = 0; int ay = 0; int az = 0;
int ppg = 0;        // PPG from readPhotoSensor() (in Photodetector tab)
int sampleTime = 0; // Time of last sample (in Sampling tab)
bool sending;


int lives = 3; // lives remaining
int score = 0; // current score
int top1 = 0;  // top score
int top2 = 0;  // second top score
int top3 = 0;  // third top score
unsigned long time_changed = millis(); // tracks time of last top score change
bool show_ts1 = true; // bool to track if top1 to print
bool show_ts2 = false; // bool to track if top2 to print
bool show_ts3 = false; // bool to track if top3 to print

/*
 * Initialize the various components of the wearable
 */
void setup() {
  setupCommunication();
  setupDisplay();
  setupPhotoSensor();
  setupAccelSensor();
  sending = false;

  writeDisplay("Ready...", 1, true);
  writeDisplay("Set...", 2, true);
  writeDisplay("Play!", 3, true);
  
}

/*
 * The main processing loop
 */
void loop() {
  // displays the score, lives, and tops scores
  writeDisplay(score.c_str(), 1, true); 
  writeDisplay(lives.c_str(), 2, true);
  if (millis() - time_changed > 3000) { // cycles top scores every 3 seconds.
     if (show_ts1) {
      writeDisplay(top1.c_str(), 3, true); 
      show_ts1 = false;
      show_ts2 = true;
      timed_changed = millis());
     }
     else if (show_ts2) {
      writeDisplay(top2.c_str(), 3, true); 
      show_ts2 = false;
      show_ts3 = true;
      timed_changed = millis();
     }
     if (show_ts3) {
      writeDisplay(top3.c_str(), 3, true); 
      show_ts3 = false;
      show_ts1 = true;
      timed_changed = millis();
     }
  }
  // Parse command coming from Python (either "stop" or "start")
  String command = receiveMessage();
  if(command == "stop") {
    sending = false;
    writeDisplay("Controller: Off", 0, true); 
  }
  else if(command == "start") {
    sending = true;
    writeDisplay("Controller: On", 0, true);
  }
  else if(command.substring(0,5) == "score") {
    score = 
  }

  
  

  // Send the orientation of the board
  if(sending && sampleSensors()) {
    sendMessage(String(getOrientation()));
  }
}
