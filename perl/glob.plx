#!/usr/bin/perl
#glob.plx

use warnings;
use strict;

my @files = glob("sort*");
print "Matched 'sort*' @files\n";
