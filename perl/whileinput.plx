#!/usr/bin/perl
#whileinput.plx

use warnings;
use strict;

my @input;
while(<STDIN>){
chomp;
last unless $_;
push @input,$_;
}
for (@input){
print $_,"\n";
}