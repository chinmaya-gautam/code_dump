#!/usr/bin/perl
#nl2.plx

use warnings;
use strict;

my $lineno=1;
while(<>){
print $lineno++,": $_";
}