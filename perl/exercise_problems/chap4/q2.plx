#!/usr/bin/perl
#number guessing

use warnings;
use strict;

my $answer = 37;

while(<STDIN>){
chomp;
last if $answer == $_ && print "you got it\n";
print "you geussed lower\n" if $answer > $_;
print "you geussed higher\n" if $answer < $_;
}