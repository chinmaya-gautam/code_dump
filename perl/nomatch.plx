#!/usr/bin/perl
#nomatch.plx

use warnings;
use strict;

my $sentence = "this sentence does not contain the word beign searched for";

print "\nthe sentence does not contain fish\n" if($sentence !~ /fish/);