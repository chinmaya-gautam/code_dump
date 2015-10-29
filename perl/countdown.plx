#!/usr/bin/perl
#countdown.plx

use warnings;
use strict;

for (reverse(1..5)){
print "$_..\n";
sleep(1);
}
print"blast off!\n";
