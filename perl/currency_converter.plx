#!/usr/bin/perl
#currency_converter.plx

use warnings;
use strict;

my $USD=45;
my $GBP=78;
my $YEN=1.5;
my $INR=1;

print "please enter an amount : ";
my $value=<STDIN>;

print "value in INR = ",$value/$INR,"\n";
print "value in USD = ",$value/$USD,"\n";
print "value in GBP = ",$value/$GBP,"\n";
print "value in YEN = ",$value/$YEN,"\n";

