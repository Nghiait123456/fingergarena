/*
 * ClearID.cpp
 *
 *  Created on: Jun 4, 2018
 *      Author: user
 */

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

uint8_t ClearId (uint8_t id, uint16_t eepromLocationStartSaveId)
{

  uint8_t p = delete_Template (id);

  if (p == 0)
  {

    for (uint16_t j = 0; j < sizeof(input_uart); j++)
    {
      input_uart[j] = '\0';
    }
    strcat (input_uart, "clearid(\"ok\");");

    eewrite ((id + eepromLocationStartSaveId), 0);
    spln (input_uart);
    // in ra
    return 0; // clear ID ok
  }
  else
  {
    for (uint16_t j = 0; j < sizeof(input_uart); j++)
    {
      input_uart[j] = '\0';
    }
    strcat (input_uart, "clearid(\"fail\");");
    spln (input_uart);
  }

  return 5;
}

