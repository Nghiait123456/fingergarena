/*
 * changeIDFinger.cpp
 *
 *  Created on: Apr 12, 2018
 *      Author: user
 */
#include "Arduino.h"
#include "global1.h"
#include "fingerprint_data.h"
#include "SoftwareSerial.h"
#include "userconfig.h"

uint8_t changeIdFinger (uint8_t id, uint16_t eepromLocationStatSave)
{
  deviceRunTime.changeId = 1;
#if( DEBUG12 ==1 )
  uint8_t p11=1;
    if( p11==1 )
      {
      spln("in ra stack");
      usr_free(2);
      }
#endif
  // get and compare  finger print
  uint8_t p = create_Template (id, NULL); // them 1 id moi thanh cong tra ve 0 va 512bye id
  if (p == 9)
  {
    eewrite (id + eepromLocationStatSave, 1);
    deviceRunTime.changeId = 2;
    splnPM( "changefg(ok);" );
    // in ra va update vao bo nho
    return 2; // id doi thanh cong
  }

  return 5;
}
// send MKP continue

