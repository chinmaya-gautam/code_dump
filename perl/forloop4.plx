#!/usr/bin/perl
#forloop4.plx

use warnings;
use strict;

my @array = (1,2,3,5,7,9,0);

my $i = "hello there!";

foreach $i (@array){
print "$i .. \n";
sleep (3);
}
print "all done,$i \n";