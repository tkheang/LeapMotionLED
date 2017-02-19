// Timothy Kheang and Saarthak Ahlawat
// Created for Hackpoly 2017
import de.voidplus.leapmotion.*;
import processing.serial.*; 

Serial port;
LeapMotion leap;
int previousPosition = 0;
int currentPosition = 0;

void setup() 
{
  size(800, 800, P3D);
  background(255);
  leap = new LeapMotion(this);
  port = new Serial(this, Serial.list()[0], 9600);
}

void draw() 
{
  background(255);
  
  for (Hand hand : leap.getHands()) 
  {
    hand.draw();
    
    if (hand.getThumb().isExtended() && hand.getIndexFinger().isExtended() && hand.getMiddleFinger().isExtended() && hand.getRingFinger().isExtended() && hand.getPinkyFinger().isExtended()) // open hand
    {
      currentPosition = (int) map(hand.getPosition().x, 0, 1000, 2, 13);
      if (previousPosition != currentPosition) 
      {
        previousPosition = currentPosition;
        port.write(previousPosition);
      }
    }
    else if (!hand.getThumb().isExtended() && hand.getIndexFinger().isExtended() && !hand.getMiddleFinger().isExtended() && !hand.getRingFinger().isExtended() && !hand.getPinkyFinger().isExtended()) // 1 finger
        port.write('A');
    else if (!hand.getThumb().isExtended() && hand.getIndexFinger().isExtended() && hand.getMiddleFinger().isExtended() && !hand.getRingFinger().isExtended() && !hand.getPinkyFinger().isExtended()) // 2 fingers
        port.write('B');
    else if (!hand.getThumb().isExtended() && hand.getIndexFinger().isExtended() && hand.getMiddleFinger().isExtended() && hand.getRingFinger().isExtended() && !hand.getPinkyFinger().isExtended()) // 3 fingers
        port.write('C');
    else if (!hand.getThumb().isExtended() && hand.getIndexFinger().isExtended() && hand.getMiddleFinger().isExtended() && hand.getRingFinger().isExtended() && hand.getPinkyFinger().isExtended()) // 4 fingers
        port.write('D');
    else
      port.write('0');
    }
}