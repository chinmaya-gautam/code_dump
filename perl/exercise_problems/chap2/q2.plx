#!/usr/bin/perl
#ibconverter (interactive base converter)

use warnings;
use strict;

print "enter a hexadecimal number: ";
my $input = <STDIN>;
chomp($input);
print "\n $input in decimal : ",hex($input),"\n";

print "enter an octal number: ";
$input = <STDIN>;
chomp($input);
print "\n $input in decimal : ",oct($input),"\n";
 
