#include "Arduino.h"
#include "Streaming.h"
#include "MemoryFree.h"
#include "Flash.h"
#include "ConstantVariable.h"


const int BAUDRATE = 9600;
CONSTANT_STRING(big_string,
                "Stately, plump Buck Mulligan came from the stairhead, bearing a bowl of\n"
                "lather on which a mirror and a razor lay crossed. A yellow dressinggown,\n"
                "ungirdled, was sustained gently behind him on the mild morning air. He\n"
                "held the bowl aloft and intoned:\n"
                "--_Introibo ad altare Dei_.\n"
                "Halted, he peered down the dark winding stairs and called out coarsely:\n"
                "--Come up, Kinch! Come up, you fearful jesuit!\n"
                "Solemnly he came forward and mounted the round gunrest. He faced about\n"
                "and blessed gravely thrice the tower, the surrounding land and the\n"
                "awaking mountains. Then, catching sight of Stephen Dedalus, he bent\n"
                "towards him and made rapid crosses in the air, gurgling in his throat\n"
                "and shaking his head. Stephen Dedalus, displeased and sleepy, leaned\n"
                "his arms on the top of the staircase and looked coldly at the shaking\n"
                "gurgling face that blessed him, equine in its length, and at the light\n"
                "untonsured hair, grained and hued like pale oak.\n");
CONSTANT_STRING(little_string,"12345");
CONSTANT_STRING(empty_string,"");

void setup()
{
  Serial.begin(BAUDRATE);
  Serial.flush();
  delay(1000);

#ifdef __AVR__
  Serial << "free_memory = " << freeMemory() << endl;
#endif
}


void loop()
{
  Serial << endl;
  delay(1000);
#ifdef __AVR__
  Serial << "free_memory = " << freeMemory() << endl;
#endif
  Serial << endl;
  Serial << "big_string.length() = " << big_string.length() << endl;
  char big_char_array[big_string.length() + 1];
  big_string.copy(big_char_array);
  Serial << big_char_array << endl;
  Serial << "big_string[6] = " << big_string[6] << endl;

  Serial << endl;
  Serial << "little_string.length() = " << little_string.length() << endl;
  char little_char_array[little_string.length() + 1];
  Serial << "little_char_array size = " << sizeof(little_char_array) << endl;
  little_string.copy(little_char_array,little_string.length() + 1);
  Serial << little_char_array << endl;
  char little_char_array2[little_string.length() + 1];
  little_string.copy(little_char_array2);
  Serial << little_char_array2 << endl;
  for (unsigned int offset=0;offset<=little_string.length();++offset)
  {
    little_string.copy(little_char_array2,little_string.length()+1,offset);
    Serial << little_char_array2 << endl;
  }
  Serial << "little_string[0] = " << little_string[0] << endl;

  Serial << endl;
  Serial << "empty_string.length() = " << empty_string.length() << endl;
  char empty_char_array[little_string.length() + 1];
  empty_string.copy(empty_char_array);
  Serial << empty_char_array << endl;
  if (strcmp(empty_char_array,"") == 0)
  {
    Serial << "empty_char_array == to \"\"" << endl;
  }
}
