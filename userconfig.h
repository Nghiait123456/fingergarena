/*
 * userconfig.h
 *
 *  Created on: Jul 3, 2018
 *      Author: user
 */

#ifndef USERCONFIG_H_
#define USERCONFIG_H_

#define DEBUG   0
#define usePassWordFg 0
#include </home/user/workspace/NoPCShare/IotTeam/IoTHeartLibs/Arduino/avr/csshockpro.h>
#define locationStartEeprom 768
#define locationEndEeprom 1023
#define locationStartSaveGpsData  (768+127)
#define longGpsData  (768+127+60)


#define debug   while(1)  { runSBash(); }




/*
#define putHandOnFg()     for( int i=0; i< 3; i++ )     doCLIPM("beep(8,1000,400);snooze(400);beep(8,1000,1);snooze(400);")
#define putHandOutFg()   for( int i =0; i < 8; i ++ )    doCLIPM("beep(8,1000,20);snooze(20);beep(8,1000,1);snooze(20);")
#define OK()                                              doCLIPM("beep(8,1000,2000);")
#define timeOut()        for( int i =0; i < 3; i++ )        doCLIPM("beep(8,1000,4000); ")
*/



// vij tri luu id trong eeprom la id + locationStartEepromID

#define button 7
extern unsigned char addnewId;
extern unsigned char changeId;
extern unsigned char getId;

extern unsigned char callAddIdFromApp;
extern unsigned char callChangeIdFromApp;
extern unsigned char callGetIdFromApp;
extern unsigned char callClearIdFromApp;

extern unsigned long delayTest;
extern char datasend_encoder[6];

extern char input_uart[50];

extern unsigned long x;
extern unsigned long y;

extern volatile unsigned char timeGps;

extern volatile unsigned char numberIdChange;
extern volatile unsigned char sttGetGps;

extern unsigned char secondScan ;
extern unsigned char beep ;


#define NEW_BEEP 1
#if NEW_BEEP==0
extern  void putHandOnFg(void);
extern  void putHandOutFg(void);
extern  void OK(void);
extern  void timeOut(void);
#else
extern void beepMutil (uint32_t freq, uint32_t duration, uint32_t space, uint16_t times);
extern  void putHandOnFg(void);
extern  void putHandOutFg(void);
extern  void OK(void);
extern  void timeOut(void);

/*
#define putHandOnFg()      beepMutil(1000,400,400,2)
#define   putHandOutFg()   beepMutil(1000,20,20,8)
#define   OK()             beepMutil(1000,3000,0,1)
#define    timeOut()        beepMutil(1000,200,200,6)
*/
#endif

#endif /* USERCONFIG_H_ */
