#!/usr/bin/perl
#hash.plx

use warnings;
use strict;

my %rolls = (
	'chinmaya gautam' => "109cs0322",
	'shreeram kushwaha'=> "109cs0157",
	prateek => "109cs0130",
	shariq => "109cs0324"
);

my %names = reverse %rolls;

print "what is the roll no. of chinmaya gautam?\n"; 
print "it is ",$rolls{'chinmaya gautam'},"\n";
print "what is the roll no. of shreeram kushwaha?\n"; 
print "it is $rolls{'shreeram kushwaha'}\n";
print "what is the name of 109cs0130?\n"; 
print "it is $names{'109cs0130'}\n";
print "what is the name of 109cs0324?\n"; 
print "it is $names{'109cs0324'}\n";

