#!/usr/bin/perl
#elems.plx

use warnings;
use strict;

my @array = qw(alpha bravo charlie delta);

print "scalar value: ",scalar @array,"\n";
print "highest element: ",$#array,"\n";
