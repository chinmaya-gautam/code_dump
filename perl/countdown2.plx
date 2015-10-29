#!/usr/bin/perl
#countdown2.plx

use warnings;
use strict;

my $value = 5;

print "$value\n" while ($value-- > 0); #this shows that the condition is always evaluated before the execution of code...
