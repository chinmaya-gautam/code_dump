#!/usr/bin/perl
#noref.plx

use warnings;
use strict;

my $ref = [1,2,3];
print "brefore \$ref: $ref\n";
print "@{$ref}\n";
$ref++;
print "after \$ref: $ref\n";
print "@{$ref}\n";
