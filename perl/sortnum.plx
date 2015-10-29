#!/usr/bin/perl
#sortnum.plx

use warnings;
use strict;

my @array = qw(1 6 2 5 62 132 56 76 43 23);

print "unsorted array: @array\n";
my @sorted= sort {$a <=> $b} (@array);
print "sorted array: @sorted\n";
