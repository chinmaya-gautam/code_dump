#!/usr/bin/perl
#matchtest.plx

use warnings;
use strict;

$_ =  q("I wonder what the english is for 'yes' and 'no'," he thought.);
#Tolkein, Lord of the Rings.

print "Enter some text to find: ";
my $pattern = <STDIN>;

chomp $pattern;

if (/$pattern/){
print "text matches the pattern '$pattern'\n";
}
else {
print "'pattern' was not found\n";
}
