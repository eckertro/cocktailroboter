    // (c) Michael Schoeffler 2017, http://www.mschoeffler.de
    #include <HX711_ADC.h> // https://github.com/olkal/HX711_ADC
    #include <Wire.h>

    HX711_ADC LoadCell(0, 1); // parameters: dt pin, sck pin<span data-mce-type="bookmark" style="display: inline-block; width: 0px; overflow: hidden; line-height: 0;" class="mce_SELRES_start"></span>

    void setup() {
      LoadCell.begin(); // start connection to HX711
      LoadCell.start(2000); // load cells gets 2000ms of time to stabilize
      LoadCell.setCalFactor(999.0); // calibration factor for load cell => strongly dependent on your individual setup
    }
    void loop() {
      LoadCell.update(); // retrieves data from the load cell
      float g = LoadCell.getData(); // get output value   
      Serial.println(g);
    }
