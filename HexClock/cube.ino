const static int top_side[32] =  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,21,22,23,24,25,26,30,31,32,33,39,40};
const static int left_side[32] = {27,28,29,41,42,43,44,45,46,47,56,57,58,59,60,61,62,63,72,73,74,75,76,77,78,79,87,88,89,90,91,95};
const static int right_side[32]= {20,34,35,36,37,38,48,49,50,51,52,53,54,55,64,65,66,67,68,69,70,71,80,81,82,83,84,85,86,92,93,94};
int cube_anim_step;
static uint32_t lastms;
void cube ()
{
  for (int i = 0; i < 32; i++)
  {
    leds[top_side[i]] = CRGB(255,0,0);
    leds[left_side[i]] = CRGB(0,255,0);
    leds[right_side[i]] = CRGB(0,0,255);
  }

  /*
  leds[top_side[cube_anim_step]] = CRGB(255,0,0);
  leds[left_side[cube_anim_step]] = CRGB(0,255,0);
  leds[right_side[cube_anim_step]] = CRGB(0,0,255);
  uint32_t ms = millis();
  if (lastms + 150 < ms)
  {
    lastms = ms;
    cube_anim_step++;
    if (cube_anim_step >= 32)
      cube_anim_step = 0;
  }
*/

/*
  leds[10] = CRGB(255,255,255);
  leds[11] = CRGB(0,255,255);
  leds[20] = CRGB(255,255,255);
  leds[21] = CRGB(0,255,255);
  leds[30] = CRGB(255,255,255);
  leds[31] = CRGB(0,255,255);
  leds[40] = CRGB(255,255,255);
  leds[41] = CRGB(0,255,255);
  leds[50] = CRGB(255,255,255);
  leds[51] = CRGB(0,255,255);
  leds[60] = CRGB(255,255,255);
  leds[61] = CRGB(0,255,255);
  leds[70] = CRGB(255,255,255);
  leds[71] = CRGB(0,255,255);
  leds[80] = CRGB(255,255,255);
  leds[81] = CRGB(0,255,255);
  leds[90] = CRGB(255,255,255);
  leds[91] = CRGB(0,255,255);
  */
}