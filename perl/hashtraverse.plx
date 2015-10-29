#!/usr/bin/perl
#hashtraverse.plx

use warnings;
use strict;

my %db = (
	"chinmaya gautam" => "109cs0322",
	"shreeram kushwaha" => "109cs0157",
	"anurag das" => "109cs0136",
	"shariq islam" => "109cs0324"
);

for (keys %db) {
print "$_ has roll no $db{$_}\n";
}

print "\n";
