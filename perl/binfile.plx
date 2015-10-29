#!/usr/bin/perl
#binfile.plx

use warnings;
use strict;

open FILE,">binfile.bin" or die $!;
binmode FILE;
print FILE "this is a binary file!";
print "\n";