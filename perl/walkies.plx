#!/usr/bin/perl
#walkies.plx

use warnings;
use strict;

print "what's the weather like outside? ";
my $weather = <STDIN>;
print "how hot is it,in degrees? ";
my $temperature = <STDIN>;
print "and how many emails left to reply to? ";
my $work = <STDIN>;

chomp ($weather, $temperature, $work);

if($weather eq "snowing"){
  print "OK, lets go!\n";
}elsif($weather eq "raining"){
  print "no way! i am staying in\n";
}elsif ($temperature < 18){
  print "its too cold for me, i am staying in\n";
}elsif ($work > 30){
  print "i have too much work, sorry\n";
}else{
  print "why not?\n";
}