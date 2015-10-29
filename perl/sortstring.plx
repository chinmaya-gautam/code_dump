#!/usr/bin/perl
#sortstring.plx

use warnings;
use strict;

my @array = qw(pen pencil paper book copy notepad ruler);

print "unsorted array : @array\n";
my @sorted = sort(@array);
print "sorted array : @sorted\n";
