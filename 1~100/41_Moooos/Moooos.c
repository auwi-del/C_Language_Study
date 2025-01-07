#include <stdio.h>

#define LED_BUILTIN 13
#define LOW 0
#define HIGH 1

char *CharToMos( char c );

int main()
{
    printf( "%s", CharToMos( 's' ) );
    system( "pause" );
}



// 传入一个字符, 传回一个 [关于点和划的字符串]
char* CharToMos( char c )
{ 
  switch( c )
  {
    case 'a': return ".--"; break;
    case 'b': return "-..."; break;
    case 'c': return "-.-."; break;
    case 'd': return "-.."; break;
    case 'e': return "."; break;
    case 'f': return "..-."; break;
    case 'g': return "--."; break;
    case 'h': return "...."; break;
    case 'i': return ".."; break;
    case 'j': return ".---"; break;
    case 'k': return "-.-"; break;
    case 'l': return ".-.."; break;
    case 'm': return "--"; break;
    case 'n': return "-."; break;
    case 'o': return "---"; break;
    case 'p': return ".--."; break;
    case 'q': return "--.-"; break;
    case 'r': return ".-."; break;
    case 's': return "..."; break;
    case 't': return "-"; break;
    case 'u': return "..-"; break;
    case 'v': return "...-"; break;
    case 'w': return ".--"; break;
    case 'x': return "-..-"; break;
    case 'y': return "-.--"; break;
    case 'z': return "--.."; break;
  }
}