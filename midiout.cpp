// midiout.cpp
 
#include <iostream>
#include <cstdlib>
#include "RtMidi.h"
#include <windows.h>
 
int main()
{
  RtMidiOut *midiout = new RtMidiOut();
  std::vector<unsigned char> message;
 
  // Check available ports.
  unsigned int nPorts = midiout->getPortCount();
  if ( nPorts == 0 ) {
    std::cout << "No ports available!\n";
    goto cleanup;
  }
 
  // Open first available port.
  midiout->openPort( 1 );
 
  // Send out a series of MIDI messages.
 
  // Program change: 192, 5
  message.push_back( 192 );
  message.push_back( 5 );
  midiout->sendMessage( &message );
 
  // Control Change: 176, 7, 100 (volume)
  message[0] = 176;
  message[1] = 7;
  message.push_back( 100 );
  midiout->sendMessage( &message );
 
  // Note On: 144, 64, 90
  message[0] = 144;
  message[1] = 64;
  message[2] = 90;
  midiout->sendMessage( &message );
 
  Sleep( 500 ); // Platform-dependent ... see example in tests directory.
 
  // Note Off: 128, 64, 40
  message[0] = 128;
  message[1] = 64;
  message[2] = 40;
  midiout->sendMessage( &message );
 
  // Clean up
 cleanup:
  delete midiout;
 
  return 0;
}