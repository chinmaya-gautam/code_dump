#!/usr/bin/perl
#shift.plx

use warnings;
use strict;

my @array = qw(pen pencil book copy notepad eraser);
print "array is : @array\n";
my $elem=shift @array;
print "array is now : @array \nelement shifted : $elem\n";
unshift(@array, "ruler");
print "array is now : @array\n";
