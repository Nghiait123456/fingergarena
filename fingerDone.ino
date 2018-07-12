/*
 * readAndCompareFinger.cpp
 *
 *  Created on: Apr 12, 2018
 *      Author: user
 */
#include "Arduino.h"
#include "global1.h"
#include "fingerprint_data.h"
#include "SoftwareSerial.h"
#include "readAndCompareFinger.h"
#include "changeIdFInger.h"
#include "gpsDataNew.h"
#include <SoftwareSerial.h>
#include "ClearID.h"
#include "ListIdUsed.h"
#include "AddNewId.h"
#include  "userconfig.h"
#include "delayNoLoop.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned long timeProvince;
char datasend_encoder[6];
char input_uart[50];

unsigned long x = 0;
unsigned long y = 0;

unsigned char addnewId = 0;
unsigned char changeId = 0;
unsigned char getId = 0;

unsigned char callAddIdFromApp = 0;
unsigned char callChangeIdFromApp = 0;
unsigned char callGetIdFromApp = 0;

unsigned char secondScan = 0;
unsigned char beep = 0;

volatile unsigned char numberIdChange = 0;
volatile unsigned char sttGetGps = 0;
volatile unsigned char sumIdUsed = 0;
unsigned long delayTest = 0;

volatile unsigned char timeGps = 0;
#define Newproduct  200

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if NEW_BEEP==0
void putHandOnFg (void)
{
  uint8_t i;
  i = 2;
  while (i--)
  {
    sysbeep (8, 1000, 400);
    delay (400);
    sysbeep (8, 1000, 1);
    delay (400);
  }
}

void putHandOutFg (void)
{
  uint8_t i;
  i = 8;
  while (i--)
  {
    sysbeep (8, 1000, 20);
    delay (20);
    sysbeep (8, 1000, 1);
    delay (20);
  }
}

void timeOut (void)
{
  uint8_t i;
  i = 6;
  while (i--)
  {
    sysbeep (8, 1000, 200);
    delay (200);
    sysbeep (8, 1000, 1);
    delay (200);
  }
}

void OK (void)
{
  sysbeep (8, 1000, 3000);
  delay (3000);
}
#else

void beepMutil (uint32_t freq, uint32_t duration, uint32_t space, uint16_t times)
{
  while (times--)
  {
    sysbeep (8, freq, duration);
    delay (duration + space);
  }
}

void putHandOnFg ()
{
  beepMutil (1000, 400, 400, 2);
}
void putHandOutFg()
{
   beepMutil(1000,20,20,8);
}
void OK ()
{
  beepMutil (1000, 3000, 0, 1);
}
void timeOut ()
{
  beepMutil (1000, 200, 200, 6);
}
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////////
ucsstype getGpsFromEeprom (void)
{

  if (getarg (0) > 0)
  {
# if( DEBUG ==1)
    spln (" truyen sai so tham so ");
# endif
    return 0;
  }

  if (eeread (longGpsData) != 0)
  {

    //check data
    unsigned char x = 0;

    /*    for (uint16_t j = 0; j < sizeof(input_uart); j++)
     {
     input_uart[j] = '\0';
     }*/
    memset (input_uart, 0, sizeof(input_uart));
    strcat (input_uart, "getgps(\"ok\",");
    x = strlen (input_uart);

    for (int i = locationStartSaveGpsData;
        i < (int) (locationStartSaveGpsData + (unsigned char) eeread (longGpsData) - 25); i++)
    {
      input_uart[x] = eeread (i);
      x++;
    }
    input_uart[x] = 0;
    sp (input_uart);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (uint16_t j = 0; j < sizeof(input_uart); j++)
    {
      input_uart[j] = '\0';
    }
    x = 0;
    for (int i = (int) (locationStartSaveGpsData + (unsigned char) eeread (longGpsData) - 25);
        i < (int) (locationStartSaveGpsData + (unsigned char) eeread (longGpsData)); i++)
    {
      input_uart[x] = eeread (i);
      x++;
    }
    strcat (input_uart, ");");
    spln (input_uart);
    return 1;
  }
  else
  {
    spln ("loi data gps ");
  }
  return 0;
}
ucsstype changeID (void)
{
  if (addnewId != 0 || getId != 0)
    return 0;
  if (!getarg (0))
  {
#if( DEBUG ==1 )
    spln ("khong co tham so dc truyen ");
#endif
    return 0;
  }
  if (getarg (0) > 1)
  {
#if( DEBUG ==1 )
    spln ("truyen sai so tham so ");
#endif
    return 0;
  }
  if (isstringarg (1))
  {
#if( DEBUG ==1 )
    spln ("tham so khong phai dang so ");
#endif
    return 2;
  }

  finger_Config (57600);
  callChangeIdFromApp = 1;
  numberIdChange = getarg (1);
  if (0 >= getarg (1) || getarg (1) > 127)
    return 2;
  uint8_t x = changeIdFinger (getarg (1), locationStartEeprom);
  if (x == 2)
    return 1;
  return 0;
}

ucsstype clearID123 (void)
{
  if (addnewId != 0 || getId != 0 || changeId != 0)
    return 0;
  if (!getarg (0))
  {
#if( DEBUG ==1 )
    spln ("khong co tham so dc truyen ");
#endif
    return 1;
  }
  if (getarg (0) > 1)
  {
#if( DEBUG ==1 )
    spln ("truyen sai so tham so ");
#endif
    return 1;
  }
  if (isstringarg (1))
  {
#if( DEBUG ==1 )
    spln ("tham so khong phai dang so ");
#endif
    return 2;
  }

  finger_Config (57600);
  if (0 > getarg (1) || getarg (1) > 127)
    return 1;
  uint8_t x = ClearId (getarg (1), locationStartEeprom);
  if (x == 2)
    return 3;
  return 0;
}
ucsstype listID (void)
{
  if (getarg (0) > 0)
  {
#if( DEBUG ==1 )
    spln ("truyen sai so tham so ");
#endif
    return 1;
  }

  finger_Config (57600);
  ListIdUsed (1, 127, locationStartEeprom);
  return 0;
}

ucsstype addID (void)
{
  if (getarg (0) > 0)
  {
#if( DEBUG ==1 )
    spln ("truyen sai so tham so ");
#endif
    return 0;
  }

  if (changeId != 0 || getId != 0)
    return 0;
  callAddIdFromApp = 1;
  finger_Config (57600);
  uint8_t x = AddNewId (1, 127, locationStartEeprom);
  if (x == 2)
    return 1;
  return 0;
}

ucsstype getFG (void)
{
  putHandOnFg ();
  if (getarg (0) > 0)
  {
#if (DEBUG ==1 )
    spln ("truyen sai so tham so ");
#endif
    return 0;
  }
  if (addnewId != 0 || changeId != 0)
    return 0;
  callGetIdFromApp = 1;
  finger_Config (57600);
  uint8_t x = readAndCompaeFinger ();
  if (x == 2)
    return 1;
  return 0;
}

ucsstype getScr (void)
{
  uint8_t security;
  finger_Config (57600);
  if (fingerReadSystemParameter ((uint8_t *) input_uart, 150, security) == 0)
  {
    for (uint16_t j = 0; j < sizeof(input_uart); j++)
    {
      input_uart[j] = '\0';
    }
    strcat (input_uart, "fgreadscr(\"ok\",");
    datasend_encoder[0] = 0;
    sprintf (datasend_encoder, "%d", security);
    strcat (input_uart, datasend_encoder);
    strcat (input_uart, ");");
    spln (input_uart);
  }
  else
  {
    spln ("fgreadscr(fail);");
  }
  return 0;
}

ucsstype setScr (void)
{
  if (!getarg (0))
  {
    return 1;
  }
  if (getarg (0) > 1)
  {
    return 2;
  }
  if (isstringarg (1))
  {
    return 3;
  }
  finger_Config (57600);
  if ((uint8_t) getarg (1) > 5 || (uint8_t) getarg (1) < 1)
    return 4;
  if (fingerSetsyspara (5, (uint8_t) getarg (1), (uint8_t *) input_uart, 150) == 0)
  {
    spln ("fgsetscr(ok);");
  }
  else
  {
    spln ("fgsetscr(fail);");
  }
  return 0;
}

void gpsRead ()
{
  if (eeread (longGpsData) == 0)
  {
#if( DEBUG ==1 )
    spln ("van chua doc dc gps ");
#endif
    uint8_t l = getGpsData_softWareSerial (sttGetGps, locationStartSaveGpsData);
    if (l >= 2)
    {
      sttGetGps = 0;
    }
  }
  else
  {
    // spln("da doc duoc gps ");
    static unsigned long gps2 = millis ();
    if (timeGps == 0)
    {
#if(DEBUG == 1)
      spln ("da dat lai bo dem time ----------- ");
#endif
      gps2 = millis ();
      timeGps = 1;
    }
    if ((millis () - gps2) < 2000)
    {
      // spln("nho hon 2000");
      uint8_t l = getGpsData_softWareSerial (sttGetGps, locationStartSaveGpsData);
      //  printlnUint32 (l, 5, 'l');
      if (l >= 2)
      {
        sttGetGps = 0;
      }
    }
    else if ((millis () - gps2) > 20000)
    {
      timeGps = 0;
      gps2 = millis ();
#if(DEBUG ==1)
      spln ("da reset bo dem time --------- ");
#endif
    }
  }
}
#if(DEBUG ==1)
void printHex (int num, int precision)
{
  char tmp[16];
  char format[30];

  sprintf (format, "%%.%dX", precision);

  sprintf (tmp, format, num);
  sp (tmp);
}
#endif
void setup ()
{

  initCSShock (115200);
  config_GPSneo (28800);
  finger_Config (57600);
  eewrite (longGpsData, 0);

  addCSShockFunction ("gpsget", (csshock_func) getGpsFromEeprom);
  addCSShockFunction ("fgchange", (csshock_func) changeID);
  addCSShockFunction ("fgclear", (csshock_func) clearID123);
  addCSShockFunction ("fglist", (csshock_func) listID);
  addCSShockFunction ("fgaddnew", (csshock_func) addID);
  addCSShockFunction ("fgget", (csshock_func) getFG);
  addCSShockFunction ("fgscrget", (csshock_func) getScr);
  addCSShockFunction ("fgscrset", (csshock_func) setScr);

}
// The loop function is called in an endless loop
void loop ()
{

  static unsigned long addidTimeout = millis ();
  static unsigned long changeidTimeout = millis ();
  static unsigned long getIdFgTimeout = millis ();

///////////////////////////////////////////////////////////////////////////////////////

//  p012 = micros ();

  if (changeId == 0 && getId == 0)
  {
    // co callAddIDFromApp : de update time out 1 lan duy nhat
    if (callAddIdFromApp == 1)
    {
      addidTimeout = millis () + 35000;
      callAddIdFromApp = 0;
    }
    if (millis () < addidTimeout && addnewId == 1)
    {

      finger_Config (57600);
      AddNewId (1, 127, locationStartEeprom);
    }
    else if (addnewId == 2)
    {
      addnewId = 0;
      beep = 0;
      secondScan = 0;
    }
    else if (millis () > addidTimeout)
    {
      beep = 0;
      secondScan = 0;
      if (addnewId == 1)
      {
        for (uint16_t j = 0; j < sizeof(input_uart); j++)
        {
          input_uart[j] = '\0';
        }
        strcat (input_uart, "addnewid(\"fail\");");
        spln (input_uart);
        addnewId = 0;
        timeOut ();
      }

    }
  }
//////////////////////////////////////////////////////////////////////////////////////
  if (addnewId == 0 && getId == 0)
  {
    if (callChangeIdFromApp == 1)
    {
      changeidTimeout = millis () + 35000;
      callChangeIdFromApp = 0;
    }
    if (millis () < changeidTimeout && changeId == 1)
    {
      finger_Config (57600);
      changeIdFinger (numberIdChange, locationStartEeprom);
    }
    else if (changeId == 2)
    {
      changeId = 0;
      beep = 0;
      secondScan = 0;
    }
    else if (millis () > changeidTimeout)
    {

      beep = 0;
      secondScan = 0;
      if (changeId == 1)
      {
        for (uint16_t j = 0; j < sizeof(input_uart); j++)
        {
          input_uart[j] = '\0';
        }
        strcat (input_uart, "changeid(\"fail\");");
        spln (input_uart);
        changeId = 0;
        timeOut ();
      }
    }
  }
//////////////////////////////////////////////////////////////////////////////////////////
  if (changeId == 0 && addnewId == 0)
  {
    if (callGetIdFromApp == 1)
    {
      getIdFgTimeout = millis () + 10000;
      callGetIdFromApp = 0;
    }
    if (millis () < getIdFgTimeout && getId == 1)
    {
      finger_Config (57600);
      readAndCompaeFinger ();
    }
    else if (getId == 2)
    {
      getId = 0;
      getIdFgTimeout = millis ();
    }
    else if (millis () > getIdFgTimeout)
    {
      if (getId == 1)
      {
        for (uint16_t j = 0; j < sizeof(input_uart); j++)
        {
          input_uart[j] = '\0';
        }
        strcat (input_uart, "getid(\"fail\");");
        spln (input_uart);
        getId = 0;
        timeOut ();
      }
    }
  }
//////////////////////////////////////////////////////////////////////////////////////////////

  /*  if (eeread (longGpsData) == 0)
   {
   uint8_t l = getGpsData_softWareSerial (sttGetGps, locationStartSaveGpsData);
   if (l >= 2)
   {
   sttGetGps = 0;
   }
   }
   else if (eeread (longGpsData) != 0)
   {
   gps1 = millis ();

   if (millis () > p2 + 8000)
   {
   static unsigned long gps2 = millis ()
   uint8_t l = getGpsData_softWareSerial (sttGetGps, locationStartSaveGpsData);
   //  printlnUint32 (l, 5, 'l');
   if (l >= 2)
   {
   sttGetGps = 0;
   }
   }
   }*/
  gpsRead ();

  runCSShock ();

}

