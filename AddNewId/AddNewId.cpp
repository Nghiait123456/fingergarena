/*
 * AddNewId.cpp
 *
 *  Created on: Jun 7, 2018
 *      Author: user
 */
#include "Arduino.h"
#include "global1.h"
#include "fingerprint_data.h"
#include "SoftwareSerial.h"
#include  "userconfig.h"

uint8_t AddNewId (uint16_t ID_firstly, uint16_t Max_size_id, uint16_t eepromLocationStatSave)
{

  addnewId = 1;
  int id = -1;
  // find id add
  for (int i = ID_firstly; i < ID_firstly + Max_size_id; i++)
  {
    if (eeread (i + eepromLocationStatSave) == 0)
    {
      id = i;
      break;
    }
  }

  //  flash full
  if (id == -1)
  {
    for (uint16_t j = 0; j < sizeof(input_uart); j++)
    {
      input_uart[j] = '\0';
    }
    strcat (input_uart, "addnewid(\"fail\");");
    spln (input_uart);
    // in ra
    return 3;
  }
  else
  {

    uint8_t p = create_Template (id, NULL, 8000); // them 1 id moi thanh cong tra ve 0 va 512bye id
  # if(DEBUG==1)
    printlnUint32(p,5,'p');
  #endif
    if (p == 9)
    {
      beep = 0;
      secondScan = 0;
      addnewId = 2;
      eewrite (id + eepromLocationStatSave, 1);
      //update tong id
      for (uint16_t j = 0; j < sizeof(input_uart); j++)
      {
        input_uart[j] = '\0';
      }
      strcat (input_uart, "addnewid(\"ok\",");
      datasend_encoder[0] = 0;
      sprintf (datasend_encoder, "%d", id);
      strcat (input_uart, datasend_encoder);
      strcat (input_uart, ");");
      spln (input_uart);

      return 2; // id doi thanh cong
    }

  }
  return 4;
}

