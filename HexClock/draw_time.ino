void draw_hours (void)
{
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  int hour=p_tm->tm_hour;
  if(hour==0)
    {
      hour0();
    }
    if(hour==1)
    {
      hour1();
    }
    if(hour==2)
    {
      hour2();
    }
    if(hour==3)
    {
      hour3();
    }
    if(hour==4)
    {
      hour4();
    }
    if(hour==5)
    {
      hour5();
    }
    if(hour==6)
    {
      hour6();
    }
    if(hour==7)
    {
      hour7();
    }
    if(hour==8)
    {
      hour8();
    }
    if(hour==9)
    {
      hour9();
    }
    if(hour==10)
    {
      hour10();
    }
    if(hour==11)
    {
      hour11();
    }
    if(hour==12)
    {
      hour12();
    }
    if(hour==13)
    {
      hour13();
    }
    if(hour==14)
    {
      hour14();
    }
    if(hour==15)
    {
      hour15();
    }
    if(hour==16)
    {
      hour16();
    }
    if(hour==17)
    {
      hour17();
    }
    if(hour==18)
    {
      hour18();
    }
    if(hour==19)
    {
      hour19();
    }
    if(hour==20)
    {
      hour20();
    }
    if(hour==21)
    {
      hour21();
    }
    if(hour==22)
    {
      hour22();
    }
    if(hour==23)
    {
      hour23();
    }
    if(hour==24)
    {
      hour24();
    }
}

void draw_mins ()
{
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  int minute=p_tm->tm_min;
  r = 255;
  g = 255;
  b = 255;

  if(minute==0)
    {
      min0();
    }
    if(minute==1)
    {
      min1();
    }
    if(minute==2)
    {
      min2();
    }
    if(minute==3)
    {
      min3();
    }
    if(minute==4)
    {
      min4();
    }
    if(minute==5)
    {
      min5();
    }
    if(minute==6)
    {
      min6();
    }
    if(minute==7)
    {
      min7();
    }
    if(minute==8)
    {
      min8();
    }
    if(minute==9)
    {
      min9();
    }
    if(minute==10)
    {
      min10();
    }
    if(minute==11)
    {
      min11();
    }
    if(minute==12)
    {
      min12();
    }
    if(minute==13)
    {
      min13();
    }
    if(minute==14)
    {
      min14();
    }
    if(minute==15)
    {
      min15();
    }
    if(minute==16)
    {
      min16();
    }
    if(minute==17)
    {
      min17();
    }
    if(minute==18)
    {
      min18();
    }
    if(minute==19)
    {
      min19();
    }
    if(minute==20)
    {
      min20();
    }
    if(minute==21)
    {
      min21();
    }
    if(minute==22)
    {
      min22();
    }
    if(minute==23)
    {
      min23();
    }
    if(minute==24)
    {
      min24();
    }
    if(minute==25)
    {
      min25();
    }
    if(minute==26)
    {
      min26();
    }
    if(minute==27)
    {
      min27();
    }
    if(minute==28)
    {
      min28();
    }
    if(minute==29)
    {
      min29();
    }
    if(minute==30)
    {
      min30();
    }
    if(minute==31)
    {
      min31();
    }
    if(minute==32)
    {
      min32();
    }
    if(minute==33)
    {
      min33();
    }
    if(minute==34)
    {
      min34();
    }
    if(minute==35)
    {
      min35();
    }
    if(minute==36)
    {
      min36();
    }
    if(minute==37)
    {
      min37();
    }
    if(minute==38)
    {
      min38();
    }
    if(minute==39)
    {
      min39();
    }
    if(minute==40)
    {
      min40();
    }
    if(minute==41)
    {
      min41();
    }
    if(minute==42)
    {
      min42();
    }
    if(minute==43)
    {
      min43();
    }
    if(minute==44)
    {
      min44();
    }
    if(minute==45)
    {
      min45();
    }
    if(minute==46)
    {
      min46();
    }
    if(minute==47)
    {
      min47();
    }
    if(minute==48)
    {
      min48();
    }
    if(minute==49)
    {
      min49();
    }
    if(minute==50)
    {
      min50();
    }
    if(minute==51)
    {
      min51();
    }
    if(minute==52)
    {
      min52();
    }
    if(minute==53)
    {
      min53();
    }
    if(minute==54)
    {
      min54();
    }
    if(minute==55)
    {
      min55();
    }
    if(minute==56)
    {
      min56();
    }
    if(minute==57)
    {
      min57();
    }
    if(minute==58)
    {
      min58();
    }
    if(minute==59)
    {
      min59();
    }
    if(minute==60)
    {
      min60();
    }
}
/*------------------------------------Hour LEDs------------------------------------*/
void hour0()
{
    leds[3] = CRGB(255, 0, 0);
    leds[4] = CRGB(255, 0, 0);
    leds[15] = CRGB(255, 0, 0);
    leds[16] = CRGB(255, 0, 0);
    leds[23] = CRGB(255, 0, 0);
    leds[24] = CRGB(255, 0, 0);
}
void hour1()
{
    leds[3] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
}
void hour2()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour3()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour4()
{
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
}
void hour5()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour6()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour7()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
}
void hour8()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour9()
{
    leds[0] = CRGB(r,g,b);
    leds[1] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[24] = CRGB(r,g,b);
}
void hour10()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour11()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);  
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
}
void hour12()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour13()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour14()
{
    leds[2] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour15()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour16()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour17()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour18()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour19()
{
    leds[2] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[10] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour20()
{
    leds[2] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour21()
{
    leds[2] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour22()
{
    leds[2] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[23] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour23()
{
    leds[2] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[4] = CRGB(r,g,b);
    leds[5] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
    leds[32] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
void hour24()
{
    leds[2] = CRGB(r,g,b);
    leds[3] = CRGB(r,g,b);
    leds[7] = CRGB(r,g,b);
    leds[8] = CRGB(r,g,b);
    leds[9] = CRGB(r,g,b);
    leds[14] = CRGB(r,g,b);
    leds[15] = CRGB(r,g,b);
    leds[16] = CRGB(r,g,b);
    leds[17] = CRGB(r,g,b);
    leds[22] = CRGB(r,g,b);
    leds[25] = CRGB(r,g,b);
    leds[30] = CRGB(r,g,b);
    leds[31] = CRGB(r,g,b);
    leds[33] = CRGB(r,g,b);
}
/*----------------------------Minutes LEDs----------------------------*/
void min0()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min1()
{
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min2()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min3()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min4()
{
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
}
void min5()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min6()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min7()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
}
void min8()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min9()
{
    leds[55] = CRGB(r,g,b);
    leds[56] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
}
void min10()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min11()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
}
void min12()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min13()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min14()
{
    leds[62] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min15()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min16()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min17()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min18()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min19()
{
    leds[62] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min20()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min21()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min22()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min23()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min24()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min25()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min26()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min27()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min28()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min29()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min30()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min31()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min32()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min33()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min34()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min35()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min36()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min37()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min38()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min39()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min40()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min41()
{
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min42()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min43()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min44()
{
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min45()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min46()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min47()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min48()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min49()
{
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[72] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min50()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min51()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min52()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min53()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min54()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min55()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min56()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min57()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min58()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min59()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[80] = CRGB(r,g,b);
    leds[81] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
void min60()
{
    leds[62] = CRGB(r,g,b);
    leds[63] = CRGB(r,g,b);
    leds[64] = CRGB(r,g,b);
    leds[65] = CRGB(r,g,b);
    leds[70] = CRGB(r,g,b);
    leds[71] = CRGB(r,g,b);
    leds[73] = CRGB(r,g,b);
    leds[78] = CRGB(r,g,b);
    leds[79] = CRGB(r,g,b);
    leds[85] = CRGB(r,g,b);
    leds[86] = CRGB(r,g,b);
    leds[87] = CRGB(r,g,b);
    leds[88] = CRGB(r,g,b);
    leds[90] = CRGB(r,g,b);
    leds[91] = CRGB(r,g,b);
    leds[92] = CRGB(r,g,b);
    leds[93] = CRGB(r,g,b);
}
