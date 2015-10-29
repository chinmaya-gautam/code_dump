#!/usr/bin/perl
#quessnum.plx

use warnings;
use strict;

my $target = 12;

print "guess my num?\n";
print "enter your guess: ";
my $guess = <STDIN>;

if($target == $guess){
  print "thats it you guessed it correctly!\n";
}

if($target < $guess){
  print "your guess is higher\n";
}

if($target > $guess){
  print "your guess is lower\n";
}