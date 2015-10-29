#!/usr/bin/perl
#match3.plx

use warnings;
use strict;

my $test1 = "The dog is in the kernel";
my $test2 = "The sheepdog is in the feild";

print "this dog is at home\n" if ($test1 =~ / dog/);
print "this dog is at work\n" if ($test2 =~ / dog/);