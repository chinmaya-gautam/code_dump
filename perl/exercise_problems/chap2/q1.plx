#!/usr/bin/perl
#currency_converter2.plx

use warnings;
use strict;

print "please enter an exchange rate INR -> GBP: ";
my $RATE = <STDIN>;
print "please enter 1st value to convert: ";
my $value1 = <STDIN>;

print "please enter 2nd value to convert: ";
my $value2 = <STDIN>;

print "please enter 3rd value to convert: ";
my $value3 = <STDIN>;

chomp($value1,$value2,$value3);

print "\nconversions:\n";
print "INR\t\t| GBP\n";
print "___________________________________________\n";
print "$value1\t\t| ",$value1/$RATE,"\n";
print "$value2\t\t| ",$value2/$RATE,"\n";
print "$value3\t\t| ",$value3/$RATE,"\n";

