#!/usr/bin/perl
#ranges.plx

use warnings;
use strict;

print "Counting up : ",(0 .. 5),"\n";
print "Counting down : ",(5 .. 0),"\n";
print "Countig down (properly) : ",reverse(0 .. 5),"\n";

print "half the alphabet: ",('a'.. 'm'), "\n";
print "the other half (backwards): ", reverse('m'..'z'), "\n";

print "going from 3 to z: ",(3 .. 'z'),"\n";
print "going from z to 3: ",('z' .. 3),"\n";
