#!/usr/bin/perl
#tail.plx

use warnings;
use strict;

open FILE,'sample_file.txt' or die $!;

my @last5;

while(<FILE>){
	push @last5,$_;
	shift @last5 if @last5>5;
}

print "\nlast 5 lines:\n @last5\n";