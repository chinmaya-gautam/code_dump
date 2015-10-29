#!/usr/bin/perl
#nl.plx

use warnings;
use strict;

open FH,'sample_file.txt' or die $!;

my $lineno=1;

while(<FH>){
print $lineno++;
print " ",$_;
}
print "\n";