#!/usr/bin/perl
#deref2.plx

use warnings;
use strict;

my @bands = qw(Crosby Stills Nash Young);
my $ref = \@bands;

for (0..3){
	print "Array:       ",$bands[$_];
	print "\nrefference:  ",${$ref}[$_],"\n";
}